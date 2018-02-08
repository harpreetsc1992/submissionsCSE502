///////////////////////////////////////////////////////////////////////
// Write the code for the shifter module below.
//
// The "op" input determines the function of the module as follows:
//   3'x0: Logical left shift
//   3'x1: Logical right shift
//   3'x2: Signed left shift
//   3'x3: Signed right shift
//   3'x4: Left rotate
//   3'x5: Right rotate
//   Otherwise: don’t-care
///////////////////////////////////////////////////////////////////////

module top(
    input  [31:0] in,
    input  [2:0] op,
    input  [4:0] cnt,
    output [31:0] out
);


endmodule // top


