#pragma once

#include <uos/base.h>
#include <uos/timers/timer.h>
#include <uos/collections/linked_list.h>

/*! The number of task priorities supported by the rtos */
constexpr uint8_t UOS_TASK_PRIOS = 8;

/*! The minimum task priority supported by the rtos */
constexpr uint8_t UOS_TASK_PRIO_MIN = (UOS_TASK_PRIOS - 1);

/*! The maximum task priority supported by the rtos */
constexpr uint8_t UOS_TASK_PRIO_MAX = 0;

/*! The minimum task stack size */
constexpr uint32_t UOS_TASK_STACK_MIN = 128;

/*! Forward declaration for the task structure */
typedef struct Uos_Task Uos_Task;

/*!
 * @brief Function to execute for the task
 *
 * @param task
 *        The executing task
 *
 * @param arg
 *        Optional user argument
 */
typedef void (*uos_task_func)(Uos_Task* task, void* arg);

/*!
 * @brief Structure used to configure a task
 */
typedef struct
{
	/*! The priority of the task */
	uint8_t priority;
	
	/*! The task function to execute */
	uos_task_func function;
	
	/*! The buffer to use for the stack of the task */
	uint8_t* stack;
	
	/*! The size of the stack in bytes, must be a power of 2 */
	uint32_t stack_size;
} Uos_Task_Config;

/*!
 * @brief Structure representing a task within the rtos
 */
struct Uos_Task
{
	/*! The priority of the task */
	uint8_t priority;
	
	/*! The task function to execute */
	uos_task_func function;
	
	/*! The buffer used for the task stack */
	uint8_t* stack;
	
	/*! The size of the stack in bytes */
	uint32_t stack_size;
	
	/*! The node used to manage the state of the task */
	Linked_Node node;
	
	/*! Timer used for timing related functionality */
	Uos_Timer timer;
};

/*!
 * @brief Initializes the rtos
 */
void uos_init(void);

/*!
 * @brief Creates a task within the rtos and starts it
 *
 * @param task
 *        The task to create in a running state
 *
 * @param config
 *        The task configuration
 *
 * @param arg
 *        Optional argument to pass to the task function once the task starts executing.
 *        Set to null if unused.
 *
 * @return success
 *         True if task creation was successful, false otherwise
 */
bool uos_task_create(Uos_Task* task, const Uos_Task_Config* config, void* arg);

/*!
 * @brief Creates a task within the rtos but does not start it
 *
 * @param task
 *        The task to create in a suspended state
 *
 * @param arg
 *        Optional argument to pass to the task function once the task starts executing.
 *        Set to null if unused.
 *
 * @return success
 *         True if task creation was successful, false otherwise
 */
bool uos_task_create_suspended(Uos_Task* task, const Uos_Task_Config* config, void* arg);

/*!
 * @brief Resumes a suspended task
 *
 * @note Calling this function on an already running task has no effect
 *
 * @param task
 *        The task to resume. Passing null in this parameter accesses the current task.
 */
void uos_task_resume(Uos_Task* task);

/*!
 * @brief Suspsends a running task
 *
 * @note Calling this function on an already suspended task has no effect
 *
 * @param task
 *        The task to suspend. Passing null in this parameter accesses the current task
 */
void uos_task_suspend(Uos_Task* task);
