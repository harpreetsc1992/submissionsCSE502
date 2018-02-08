/////////////////////////////////////////////////////////////////////////
// Write a sequential multiplier using your 32-bit full adder (FA32).
//
// A multiplication operation begins by setting the inputs "a" and "b"
// to the desired operands and asserting the "start" signal.  "start"
// signal is synchronous, i.e., if it is equal to "1" on a clock
// posedge, it will force the multiplier to start a new
// multiplication, even if the previous one is not yet complete.
// 
// Upon detecting "start" on a clock posedge, the computation begins.
// During the computation, in each cycle, the multiplier computes a
// partial product (see below) and adds it to the running partial sum.
// The "ready" output should be "0" during the computation.  Once the
// final result is generated, the "ready" signal should be set to "1"
// to signal the completion.  In the same cycle that "ready" is set to
// "1", the "result" output should be set to the multiplication
// result.  Both "ready" and "result" should maintain their values
// until the "start" signal is detected again on a clock posedge.
// 
// The partial product is the product of "reg_a" and "reg_b[0]".
// "reg_a" and "reg_b" are initialized using the values of "a" and
// "b".  To account for the positional significance of the operand
// bits, in each cycle, "reg_a" is shifted by one bit to the left and
// "reg_b" is shifted to the right. The partial product is either "0"
// (if "reg_b[0]" is "0") or "reg_a" (if "reg_b[0]" is "1").
//
// Once you have implemented FA1 and FA32, fill in the blanks, "...",
// in this file to complete your multiplier implementation.
//
// "a", "b" and "result" are all unsigned numbers.
/////////////////////////////////////////////////////////////////////////

module top(clk, start, a, b, ready, result);

  input  start, clk;
  input  [15:0] a, b;
  output wire ready;
  output wire [31:0] result;

  logic [31:0] partial_sum;

  logic [31:0] reg_a;
  wire  [31:0] reg_a_inp;

  logic [15:0] reg_b;
  wire  [15:0]  reg_b_inp;
  
  wire  [31:0] fa32_in_a, fa32_in_b, fa32_out;
  
  assign reg_a_inp = ...
  assign reg_b_inp = start ? b : (reg_b >> 1);
  
  // the full adder
  assign fa32_in_a = ...
  assign fa32_in_b = ...
  
  FA32 adder(
    .a(fa32_in_a),
    .b(fa32_in_b),
    .cin(...),
    .sum(fa32_out));

  // the registers
  always_ff @(posedge clk) begin
    // make proper assignments to partial_sum, reg_a and reg_b
    // ...
  end
  
  // assign the proper output
  assign result = ...
  assign ready = ...
endmodule // top


