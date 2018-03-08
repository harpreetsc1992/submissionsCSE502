///////////////////////////////////////////////////////////////////////
// Write a combinatorial 4-to-16 decoder
//
// This decoder has inputs "in[3:0]" and "enable". It drives 16
// active-high output lines "sel[15:0]".  If "enable" is 0, all "sel"
// bits are set to 0.  Otherwise, "sel" the bit whose index is given
// by "in" is asserted (i.e., set to 1) and others remain 0.
///////////////////////////////////////////////////////////////////////

module top(
  input enable,
  input [3:0] in,
  output [15:0] sel
);

assign sel = enable ? (1 << in): 4'h0;
endmodule // top


