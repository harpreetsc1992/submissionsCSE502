///////////////////////////////////////////////////////////////////////
// Write a 4-bit counter which starts from 0 and counts up
///////////////////////////////////////////////////////////////////////

module top(
    reset,   // active-high reset signal
    clk,     // clock signal
    hold,    // pause counting
    cnt      // current value of the counter
);

    parameter WIDTH = 4;
    input reset, clk, hold;
    output logic [WIDTH-1:0] cnt;

    always_ff @(posedge clk) begin
        if (reset)
            cnt <= 0;
        else if (! hold)
            cnt <= cnt + 1;        
    end
    
    final begin
        $display("Final count is %d", cnt);
    end
endmodule // top


