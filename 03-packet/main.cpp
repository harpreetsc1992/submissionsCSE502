#include <iostream>
#include <string.h>
#include "Vtop.h"
#include "verilated.h"
#if VM_TRACE
# include <verilated_vcd_c.h>
#endif

// Current simulation time (64-bit unsigned)
uint64_t main_time = 0;
uint64_t ps_per_clock = 10000;

int main(int argc, char* argv[]) {

  //////////////////////////////////////////////////////////////////////
  // initialize
  //////////////////////////////////////////////////////////////////////
	// initialize verilator
	Verilated::commandArgs(argc, argv);
	Vtop top;
	
	// to ensure repeatability of the generated random numbers
	srand(0);
	
  // waveform generation
	VerilatedVcdC* tfp = NULL;
#if VM_TRACE
	// If verilator was invoked with --trace
	Verilated::traceEverOn(true);
	VL_PRINTF("Enabling waves...\n");
	tfp = new VerilatedVcdC;
	assert(tfp);
	// Trace 99 levels of hierarchy
	top.trace (tfp, 99);
	tfp->spTrace()->set_time_resolution("1 ns");
	// Open the dump file
	tfp->open ("../trace.vcd");
#endif

   // macro to generate clock ticks
#define TICK() do {                    \
    top.clk = !top.clk;                \
    top.eval();                        \
    if (tfp) tfp->dump(main_time/1000);\
    main_time += ps_per_clock / 2;     \
} while(0)

 //////////////////////////////////////////////////////////////////////
  // write your test sequence here
  // remember to advance the time properly after each new input set
  //////////////////////////////////////////////////////////////////////

  // make sure clk is 0 at the beginning
    top.clk = 0;
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
	
  // initialize your top module here (if needed) using
  // the reset signal
    top.reset = 1;
	VL_PRINTF("Reset: %d\n", top.reset);

    TICK(); // 1
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
    TICK(); // 0
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
    top.reset = 0;
	VL_PRINTF("Reset: %d\n", top.reset);
  TICK(); // 1
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
      top.data = 0xBE;
	VL_PRINTF("Data byte 0: %d\n", top.data);
	VL_PRINTF("Error byte 0: %d\n", top.error);
        TICK(); // 0
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
        TICK(); // 1    
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
	  top.data = 0xEF;
	VL_PRINTF("Data byte 1: %d\n", top.data);
	VL_PRINTF("Error byte 1: %d\n", top.error);
        TICK(); // 0
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
        TICK(); // 1    
	VL_PRINTF("Clock Pulse: %d\n", top.clk);

	int j = 2;

	for (unsigned i = 140; i < 148; i++)
	{
		top.data = i;
	VL_PRINTF("Data byte %d: %d\n", j, top.data);
	VL_PRINTF("Error byte %d: %d\n", j, top.error);
		TICK(); // 0
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		TICK(); // 1
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		j++;
	}
	top.data = 124;
	VL_PRINTF("Data byte %d: %d\n", j, top.data);
	VL_PRINTF("Error byte %d: %d\n", j, top.error);
		TICK(); // 0
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		TICK(); // 1

	for (unsigned i = 140; i < 145; i++)
	{
		top.data = i;
	VL_PRINTF("Data byte %d: %d\n", j, top.data);
	VL_PRINTF("Error byte %d: %d\n", j, top.error);
		TICK(); // 0
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		TICK(); // 1
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		j++;
	}	
	top.data = 0xBE;
		TICK(); // 0
		TICK(); // 1
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		j++;

	for (unsigned i = 140; i < 148; i++)
	{
		top.data = i;
	VL_PRINTF("Data byte %d: %d\n", j, top.data);
	VL_PRINTF("Error byte %d: %d\n", j, top.error);
		TICK(); // 0
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		TICK(); // 1
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		j++;
	}		
	top.data = 0xBE;
		TICK(); // 0
		TICK(); // 1
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		j++;
	top.data = 0xEF;
		TICK(); // 0
		TICK(); // 1

	for (unsigned i = 140; i < 148; i++)
	{
		top.data = i;
	VL_PRINTF("Data byte %d: %d\n", j, top.data);
	VL_PRINTF("Error byte %d: %d\n", j, top.error);
		TICK(); // 0
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		TICK(); // 1
	VL_PRINTF("Clock Pulse: %d\n", top.clk);
		j++;
	}	
		top.data = 67;
		TICK(); // 0
		TICK(); // 1
		top.data = 0xEF;	
		TICK(); // 0
		TICK(); // 1
		top.reset = 1;
		TICK(); // 0
		TICK(); // 1
		TICK(); // 0
		TICK(); // 1
		TICK(); // 0
		TICK(); // 1
  //////////////////////////////////////////////////////////////////////
  // finalize
  //////////////////////////////////////////////////////////////////////

  // execute the final blocks (if any)
	top.final();

  // finalize the trace
#if VM_TRACE
	if (tfp) tfp->close();
	delete tfp;
#endif

	return 0;
}
