#include <iostream>
#include <string.h>
#include "Vtop.h"
#include "verilated.h"
#if VM_TRACE
# include <verilated_vcd_c.h>
#endif


// Current simulation time (64-bit unsigned)
uint64_t main_time = 0;
const uint64_t ps_per_clock = 10000;


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
#define TICK() do {                  \
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

  // initialize your top module here (if needed) using
  // the reset signal
	top.reset = 1;
  
	TICK(); // 1
  
	TICK(); // 0
	top.reset = 0;
	
  TICK(); // 1

  for (unsigned i = 0; i < 100; i++) {    
    if (i % 13 == 1)
      top.hold = 1;
    else
      top.hold = 0;
		TICK(); // 0
		TICK(); // 1    
  }


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
