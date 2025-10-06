#pragma once

/*!
 * @brief Initializes the scheduler for a given mcu port
 */
void uos_mcu_scheduler_init(void);

/*!
 * @brief Invokes the interrupt handler that is used to schedule tasks within the rtos
 *
 * @note Do not used within user code
 */
void uos_mcu_invoke_scheduler(void);