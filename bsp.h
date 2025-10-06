#pragma once

#include <uos/base.h>

/*!
 * @brief Gets the current clock frequency that the code is operating at
 *
 * @note This function must be implemented within and managed by the project's bsp.
 *
 * @return frequency
 *         The clock frequency in hertz
 */
uint32_t bsp_get_sysclk_freq(void);