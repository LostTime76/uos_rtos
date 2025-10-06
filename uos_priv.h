#pragma once

#include <uos/uos.h>
#include <uos/uos_mcu.h>

/*!
 * @brief Adds a task to be scheduled within the rtos
 *
 * @note Do not use within user code
 */
void uos_schedule_task(Uos_Task* task);

/*!
 * @brief Runs the next elligible highest priority task.
 *
 * @note Do not use within user code
 */
void uos_schedule(void);