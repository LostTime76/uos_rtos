#pragma once

#include <uos/base.h>

/*!
 * @brief Sets the interrupt priority for the scheduler
 *
 * @param g_priority
 *        The preemption priority
 *
 * @param s_priority
 *        The sub priority
 */
void uos_mcu_set_interrupt_priority(uint8_t g_priority, uint8_t s_priority);