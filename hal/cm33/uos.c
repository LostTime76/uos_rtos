#include <uos/uos.h>
#include <uos/uos_mcu.h>
#include <uos/hal/cm33/uos.h>
#include <uos/hal/cm33/cm33.h>
#include <uos/hal/cm33/nvic.h>

static void _scheduler_handler(void);

void uos_mcu_set_interrupt_priority(uint8_t g_priority, uint8_t s_priority)
{
	nvic_interrupt_config(PENDSV_IRQN, _scheduler_handler, g_priority, s_priority);
}

void uos_mcu_scheduler_init(void)
{
	
}

void uos_mcu_invoke_scheduler(void)
{
	
}

static void _scheduler_handler(void)
{
	
}