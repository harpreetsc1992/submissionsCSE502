///////////////////////////////////////////////////////////////////////
// Write a 1-bit full adder.
//
// The signal names are self-explanatory.
///////////////////////////////////////////////////////////////////////

module FA1(a, b, cin, sum, cout);

  input  a, b, cin;
  output sum, cout;

  assign sum  = ((~cin) & a & (~b)) | ((~cin) & (~a) & b ) | (cin & (~a) & (~b)) | (cin & a & b); 
  assign cout = ((~cin) & a & b) | ((cin) & (~a) & b ) | (cin & (a) & (~b)) | (cin & a & b);
endmodule // top


