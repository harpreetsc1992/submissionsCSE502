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


	top.a = 10240;
	top.b = 1000;
	top.start = 1;
	TICK();
	TICK();
// Expected output 0x9C4000
	top.start = 0;
	TICK(); //1
	TICK();
	TICK(); //2
	TICK();
	TICK(); //3
	TICK();
	TICK(); //4
	TICK();
	TICK(); //5 
	TICK();
	TICK(); //6
	TICK();
	TICK(); //7
	TICK();
	TICK(); //8
	TICK();
	TICK(); //9
	TICK();
	TICK(); //10
	TICK();
	TICK(); //11
	TICK();
	TICK(); //12
	TICK();
	TICK(); //13
	TICK();
	TICK(); //14
	TICK();
	TICK(); //15
	TICK();
	TICK(); //16
	TICK();
	TICK(); //17
	TICK();
	TICK(); //18
	TICK();
	TICK(); //19
	TICK();
	TICK(); //20
	TICK();
	TICK(); //21
	TICK();
	TICK(); //22
	TICK();
	TICK(); //23
	TICK();
	TICK(); //24
	TICK();
	TICK(); //25
	TICK();
	TICK(); //26
	TICK();
	TICK(); //27
	TICK();
	TICK(); //28
	TICK();
	TICK(); //29
	TICK();
	TICK(); //30
	TICK();
	TICK(); //31
	TICK();

	TICK(); //32
	TICK();


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
