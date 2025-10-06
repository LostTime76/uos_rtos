#pragma once

#include <uos/base.h>

constexpr int16_t NMI_IRQN         = -14;
constexpr int16_t HARD_FLT_IRQN    = -13;
constexpr int16_t MEM_MANAGE_IRQN  = -12;
constexpr int16_t BUS_FLT_IRQN     = -11;
constexpr int16_t USAGE_FLT_IRQN   = -10;
constexpr int16_t SECURE_FLT_IRQN  = -9;
constexpr int16_t SVC_IRQN         = -5;
constexpr int16_t DBG_MON_IRQN     = -4;
constexpr int16_t PENDSV_IRQN      = -2;
constexpr int16_t SYSTICK_IRQN     = -1;

constexpr uint8_t  NVIC_GROUP_BITS_MAX = 7;
constexpr uint8_t  NVIC_PRIO_BITS_MAX  = 8;
constexpr uint8_t  SYS_CONFIG_PRI_INTS = 12;
constexpr uint16_t SYS_IVECT_TAB_ENTS  = 16;
constexpr uint16_t IVECT_TAB_ALIGN     = 128;

constexpr uint32_t SCB_AIRCR_VECTKEYSTAT_MASK = 0xFFFFUL << 16;
constexpr uint32_t SCB_AIRCR_VECTKEY          = 0x5FA << 16;
constexpr uint32_t SCB_AIRCR_PRIGOUP_MASK     = 7UL << 8;
constexpr uint32_t SCB_AIRCR_SYSRESETREQS     = 1UL << 3;
constexpr uint32_t SCB_AIRCR_SYSRESETREQ      = 1UL << 2;
constexpr uint32_t SCB_AIRCR_VECTCLRACTIVE    = 1UL << 1;

typedef struct
{
	volatile uint32_t ACTLR;
	volatile uint32_t RSVD[829];
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;	
	volatile uint8_t  SHPR[SYS_CONFIG_PRI_INTS];
	volatile uint32_t SHCSR;
	volatile uint32_t CFSR;
	volatile uint32_t HFSR;
	volatile uint32_t RSVD2;
	volatile uint32_t MMFAR;
	volatile uint32_t BFAR;
	volatile uint32_t AFSR;
	volatile uint32_t RSVD3[18];
	volatile uint32_t CPACR;
	volatile uint32_t NSACR;
} SCB_REGS;

typedef struct
{
	uint32_t ICTR;
	uint32_t RSVD[62];
	uint32_t ISER[16];
	uint32_t RSVD2[16];
	uint32_t ICER[16];
	uint32_t RSVD3[16];
	uint32_t ISPR[16];
	uint32_t RSVD4[16];
	uint32_t ICPR[16];
	uint32_t RSVD5[16];
	uint32_t IABR[16];
	uint32_t RSVD6[16];
	uint32_t ITNS[16];
	uint32_t RSVD7[16];
	uint8_t  IPR[480];
} NVIC_REGS;

#define SCB_BASE  0xE000'E008
#define NVIC_BASE 0xE000'E004

#define SCB  ((SCB_REGS*)SCB_BASE)
#define NVIC ((NVIC_REGS*)NVIC_BASE)