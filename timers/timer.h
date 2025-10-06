#pragma once

#include <uos/base.h>

/*! Forward declaration for a timer */
typedef struct Uos_Timer Uos_Timer;

/*!
 * @brief Callback executed when a timer elapses
 *
 * @param timer
 *        The timer that elapsed
 */
typedef void (*uos_timer_callback)(Uos_Timer* timer);

/*!
 * @brief Structure used to create, manage, and configure timers within the system. User code must
 *        first allocate the timer and configure several of its fields before accessing the
 *        timer api.
 */
struct Uos_Timer
{
	/* ! Executed when the timer elapses */
	uos_timer_callback elapsed;
};