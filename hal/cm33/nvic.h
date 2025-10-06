#pragma once

#include <uos/hal/cm33/cm33.h>

/*!
 * @brief Function executed for handling an interrupt
 */
typedef void (*interrupt_handler)(void);

/*!
 * @brief Interrupt vector table used to set the handlers executed in response to an interrupt
 *
 * @note The mcu hal implementation must allocate the vector table for this module to use
 */
extern interrupt_handler ivect_table[];

/*!
 * @brief Sets the number of priority bits used for the main priority of interrupts
 *
 * @note All the bits not assigned to the main priority will be assigned to the sub priority
 *
 * @param bits
 *        The number of priority bits used for the main priority of interrupts
 */
void nvic_set_prio_group(uint8_t bits);

/*!
 * @brief Configures an interrupt
 *
 * @param irqn
 *        The interrupt number
 *
 * @param handler
 *        The function to execute in response to an interrupt
 *
 * @param g_priority
 *        The group priority for the interrupt
 *
 * @param s_priority
 *        The sub priority for the interrupt
 */
void nvic_interrupt_config(int16_t irqn, interrupt_handler handler,
	uint8_t g_priority, uint8_t s_priority);

/*!
 * @brief Enables an interrupt
 *
 * @note This function cannot be used for system interrupts
 *
 * @param irqn
 *        The interrupt number
 */
void nvic_interrupt_on(int16_t irqn);

/*!
 * @brief Disables an interrupt
 *
 * @note This function cannot be used for system interrupts
 *
 * @param irqn
 *        The interrupt number 
 */
void nvic_interrupt_off(int16_t irqn);

/*!
 * @brief Clears the interrupt flag associated with the interrupt
 *
 * @note This function cannot be used for system interrupts
 *
 * @param irqn
 *        The interrupt number
 */
void nvic_interrupt_clear(int16_t irqn);

/*!
 * @brief Pends the interrupt flag associated with the interrupt
 *
 * @note This function cannot be used for system interrupts
 *
 * @param irqn
 *        The interrupt number
 */
void nvic_interrupt_pend(int16_t irqn);

/*!
 * @brief Gets the number of priority bits supported by the nvic within the target mcu
 *
 * @note This function must be implemented by the hal layer for the target mcu
 *
 * @return bits
 *         The number of priority bits supported by the nvic within the target mcu
 */
uint8_t nvic_get_prio_bits(void);

/*!
 * @brief Gets the number of priority bits currently assigned to the main priority of the nvic
 *        within the target mcu
 *
 * @param bits
 *        The number of priority bits assigned to the main priority of the nvic within the target
 *        mcu
 */

uint8_t nvic_get_prio_group(void);