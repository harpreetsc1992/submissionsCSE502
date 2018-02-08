///////////////////////////////////////////////////////////////////////
// Write a 4-input 4-bit mux
///////////////////////////////////////////////////////////////////////

module top(
    input  [3:0] a, b, c, d,  // mux inputs
    input  [1:0] sel,         // mux select
    output [3:0] f            // mux output
);

    always_comb begin
        if (0 == sel)
            f = a;
        else if (1 == sel)
            f = b;
        else if (2 == sel)
            f = c;
        else
            f = d;            
    end
    
endmodule // top


