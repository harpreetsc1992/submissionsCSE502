///////////////////////////////////////////////////////////////////////
// Write the code for a packet error detector
// 
// A correct packet will have the following format:
//   Bytes 0-1 : 0xBE 0xEF
//               This 16-bit sequence indicates a new packet.  Neither
//               of these two byes (0xBE and 0xEF) ever happen in 
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

    
endmodule // top


