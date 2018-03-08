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

always_comb begin
    case (op)
        3'h0: out = in << cnt;
        3'h1: out = in >> cnt;
        3'h2: out = $signed(in) <<< cnt;
        3'h3: out = $signed(in) >>> cnt;
        3'h4: out = (in << cnt) | (in >> ~cnt);
        3'h5: out = (in >> cnt) | (in << ~cnt);
        default: out = 32'hxxxxxxxx;
    endcase
end

endmodule // top
