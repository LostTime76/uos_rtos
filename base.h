#pragma once

#include <stdint.h>

/*!
 * @brief Enters a critical section of code
 */
void enter_crticial(void);

/*!
 * @brief Exits a critical section of code
 */
void exit_critical(void);

/*!
 * @brief Delays (spins) for a number of microseconds.
 *
 * @note The delay will be at least the specified number of microseconds, but usually more.
 *       Implementations will generally use a tight loop based on the system clock frequency. Thus
 *       the delay is highly inaccurate and the function should be used sparingly.
 *
 * @param nanoseconds
 *        The approximate delay in nanoseconds
 */
void delay_us(uint32_t microseconds);