///////////////////////////////////////////////////////////////////////
// Write the code for a packet error detector
// 
// A correct packet will have the following format:
//   Bytes 0-1 : 0xBE 0xEF
//               This 16-bit sequence indicates a new packet.  Neither
//               of these two bytes (0xBE and 0xEF) ever happen in 
//               a packet body or checksum.
//   Bytes 2-9 : packet body --- may contain anything other than the
//               above sequence
//   Byte 10   : packet checksum --- sum of Bytes 2-9 modulo 256
//
// Write a module that detects an erroneous packet. A packet is
// errorneous if
//   - it is shorter or longer than 11 bytes (see above), or
//   - it has the wrong checksum.
//
// The "error" output is reset by the "reset" signal and remains low
// until an error is detected.  Upon detecting an error, "error" is
// set and remains set until the cycle in which the Byte 2 of the next
// packet is received.
///////////////////////////////////////////////////////////////////////

module top(
    input  reset,   // active-high reset signal
    input  clk,     
    input  [7:0] data,
    output error
);
	logic [7:0] mod, mod_tmp;
	logic [3:0] byte_read, counter;
	logic tmp_err;

	always_comb begin
		if (data == 8'hBE) begin	// If a packet is BE, reset mod and counter to 0
			mod_tmp = 0;
			counter = 0;
		end
		else if (data == 8'hEF && counter == 0) begin	// If a packet is EF and counter is 0, set mod to 0 and counter to 1
			mod_tmp = 0;
			counter = 1;
		end
		else if (data != 8'hEF && (counter >= 1 && counter < 10)) begin	// If a packet is not EF, but counter is between 2 and 9, that means legit packet. Perform Modulo and increment counter
			mod_tmp = (mod + data) % 256;
			counter = byte_read + 1;
		end

		else if (data == 8'hEF && counter > 1 && clk == 0) begin
			mod_tmp = 0;
			counter = 0;
		end

	end

	always_ff @(posedge clk) begin
		mod <= mod_tmp;
		byte_read <= counter;
	end
	
	always_comb begin
		if (reset == 1)
			error = 0;
		else if (mod == data && byte_read == 9 && clk == 0)
			error = 0;
		else if (mod != data && byte_read == 9 && clk == 0)
			error = 1;
	end

endmodule // top


