#pragma once

#include <uos/base.h>

/*!
 * @brief Gets the current system clock frequency
 *
 * @return frequency
 *         The system clock frequency in hertz
 */
uint32_t get_sysclk_freq(void);