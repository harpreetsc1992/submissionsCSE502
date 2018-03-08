///////////////////////////////////////////////////////////////////////
// Write a 32-bit ripple-carry adder.
// 
// Implement your adder it by instantiating 32 1-bit full adders (fa1)
// and connecting them properly.  You can either instantiate them
// explicitely or as an array of modules or using generate statements.
//
// The signal names are self-explanatory.
///////////////////////////////////////////////////////////////////////

module FA32(a, b, cin, sum, cout);

  input  [31:0] a, b;
  input  cin;
  output [31:0] sum;
  output cout;
  
	logic c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c31;
	FA1 fa1(a[0], b[0], cin, sum[0], c1),
    fa2(a[1], b[1], c1, sum[1], c2),
    fa3(a[2], b[2], c2, sum[2], c3),
    fa4(a[3], b[3], c3, sum[3], c4),
    fa5(a[4], b[4], c4, sum[4], c5),
    fa6(a[5], b[5], c5, sum[5], c6),
    fa7(a[6], b[6], c6, sum[6], c7),
    fa8(a[7], b[7], c7, sum[7], c8),
    fa9(a[8], b[8], c8, sum[8], c9),
    fa10(a[9], b[9], c9, sum[9], c10),
    fa11(a[10], b[10], c10, sum[10], c11),
    fa12(a[11], b[11], c11, sum[11], c12),
    fa13(a[12], b[12], c12, sum[12], c13),
    fa14(a[13], b[13], c13, sum[13], c14),
    fa15(a[14], b[14], c14, sum[14], c15),
    fa16(a[15], b[15], c15, sum[15], c16),
	fa17(a[16], b[16], c16, sum[16], c17),
    fa18(a[17], b[17], c17, sum[17], c18),
    fa19(a[18], b[18], c18, sum[18], c19),
    fa20(a[19], b[19], c19, sum[19], c20),
    fa21(a[20], b[20], c20, sum[20], c21),
    fa22(a[21], b[21], c21, sum[21], c22),
    fa23(a[22], b[22], c22, sum[22], c23),
    fa24(a[23], b[23], c23, sum[23], c24),
    fa25(a[24], b[24], c24, sum[24], c25),
    fa26(a[25], b[25], c25, sum[25], c26),
    fa27(a[26], b[26], c26, sum[26], c27),
	fa28(a[27], b[27], c27, sum[27], c28),
    fa29(a[28], b[28], c28, sum[28], c29),
    fa30(a[29], b[29], c29, sum[29], c30),
    fa31(a[30], b[30], c30, sum[30], c31),
    fa32(a[31], b[31], c31, sum[31], cout);
  
endmodule // top


