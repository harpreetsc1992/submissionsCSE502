#include <iostream>
#include <string.h>
#include "Vtop.h"
#include "verilated.h"
#if VM_TRACE
# include <verilated_vcd_c.h>
#endif


// Current simulation time (64-bit unsigned)
uint64_t main_time = 0;


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

#define ADVANCE(ns) do {               \
        top.eval();                        \
        if (tfp) tfp->dump(main_time);     \
        main_time += ns;                   \
    } while(0)
  
  //////////////////////////////////////////////////////////////////////
  // write your test sequence here
  // remember to advance the time properly after each new input set
  //////////////////////////////////////////////////////////////////////

  top.enable = 1;
  top.in = 0;

for (unsigned i = 0; i < 16; i++)
{
	top.in = i;
  ADVANCE(10);
  ADVANCE(10);
}
	top.enable = 0;
  ADVANCE(10);
  ADVANCE(10);
for (unsigned i = 0; i < 16; i++)
{
	top.in = i;
  ADVANCE(10);
  ADVANCE(10);
}
  ADVANCE(10);
  ADVANCE(10);
	
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
