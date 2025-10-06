#include <uos/base.h>
#include <uos/hal/clock.h>
#include <uos/bsp.h>

uint8_t critical_nesting = 0;

void delay_us(uint32_t microseconds)
{
	// Calculate the number of loop iterations
	uint32_t iters = (microseconds * (bsp_get_sysclk_freq() / 1'000'000)) >> 1;
	
	__asm volatile(
		"loop:" 
		"	subs %[iters], %[iters], #1 \n"
		"	bne loop\n"
		: [iters] "+r" (iters) ::
	);
}

void enter_crticial(void)
{
	__asm volatile(
		"cpsid i\n"
		"dsb\n"
		"isb"
	);
	
	critical_nesting++;
}

void exit_critical(void)
{
	critical_nesting--;
	
	if (critical_nesting > 0)
	{
		return;
	}
	
	__asm volatile(
		"cpsie i\n"
		"dsb\n"
		"isb"
	);
}