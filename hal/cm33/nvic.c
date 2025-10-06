#include <uos/hal/cm33/nvic.h>

static uint8_t _group_bits;

static inline uint8_t _make_prio(uint8_t g_priority, uint8_t s_priority);

void nvic_set_prio_group(uint8_t group_bits)
{
	// Set the grouping within the nvic
	SCB->AIRCR = (SCB->AIRCR & ~(SCB_AIRCR_PRIGOUP_MASK)) |
		(NVIC_GROUP_BITS_MAX - group_bits) | SCB_AIRCR_VECTKEY;
	
	_group_bits = group_bits;
}

void nvic_interrupt_config(int16_t irqn, interrupt_handler handler,
	uint8_t g_priority, uint8_t s_priority)
{
	// Set the handler within the vector table
	ivect_table[SYS_IVECT_TAB_ENTS + irqn] = handler;
	
	// Construct the priority
	uint8_t priority = _make_prio(g_priority, s_priority);
	
	if (irqn < 0)
	{
		// Set system vector priority
		SCB->SHPR[SYS_CONFIG_PRI_INTS + irqn] = priority;
	}
	else
	{
		// Set peripheral vector priority
		NVIC->IPR[irqn] = priority;
	}
}

void nvic_interrupt_on(int16_t irqn)
{
	NVIC->ISER[irqn >> 5] = 1 << (irqn & 0x1F);
}

void nvic_interrupt_off(int16_t irqn)
{
	NVIC->ICER[irqn >> 5] = 1 << (irqn & 0x1F);
}

void nvic_interrupt_clear(int16_t irqn)
{
	NVIC->ICPR[irqn >> 5] = 1 << (irqn & 0x1F);
}

void nvic_interrupt_pend(int16_t irqn)
{
	NVIC->ISPR[irqn >> 5] = 1 << (irqn & 0x1F);
}

uint8_t nvic_get_prio_group(void)
{
	return _group_bits;	
}

static inline uint8_t _make_prio(uint8_t g_priority, uint8_t s_priority)
{
	uint8_t bits    = nvic_get_prio_bits();
	uint8_t g_shift = NVIC_PRIO_BITS_MAX - bits + _group_bits;
	uint8_t s_shift = NVIC_PRIO_BITS_MAX - bits;
	
	return (g_priority << g_shift) | (s_priority << s_shift);
}