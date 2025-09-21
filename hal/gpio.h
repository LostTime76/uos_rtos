#pragma once

#include <uos/base.h>

/*!
 * @brief Sets a gpio pin to a high value
 *
 * @param port
 *        The gpio port containing the pin to set
 *
 * @param pin
 *        The number of the pin within the port to set
 */
void gpio_set(void* port, uint16_t pin);

/*!
 * @brief Sets a gpio pin to a low value
 *
 * @param port
 *        The gpio port containing the pin to clear
 *
 * @param pin
 *        The number of the pin within the port to clear
 */
void gpio_clear(void* port, uint16_t pin);

/*!
 * @brief Writes a value to a gpio pin
 *
 * @param port
 *        The gpio port containing the pin to write to
 *
 * @param pin
 *        The number of the pin within the port to write to
 *
 * @param value
 *        True to set the pin high, false to set the pin low
 */
void gpio_write(void* port, uint16_t pin, bool value);

/*!
 * @brief Toggles the state of a gpio pin
 *
 * @param port
 *        The gpio port containing the pin to toggle
 *
 * @param pin
 *        The number of the pin within the port to toggle
 */
void gpio_toggle(void* port, uint16_t pin);

/*!
 * @brief Reads the value of a gpio pin
 *
 * @param port
 *        The gpio port containing the pin to read from
 *
 * @param pin
 *        The number of the pin within the port to read
 *
 * @return value
 *         True if the pin is high, false if the pin is low
 */
bool gpio_read(void* port, uint16_t pin);