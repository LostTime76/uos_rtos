#include <uos/uos_priv.h>

static uint8_t     _prio_flags = 0;
static Uos_Task*   _uos_current_task = nullptr;
static Linked_List _tasks[UOS_TASK_PRIOS];

static bool _task_create(Uos_Task* task, const Uos_Task_Config* config, bool suspended);

static inline uint8_t   _get_task_prio(uint8_t priority);
static inline uint32_t  _get_stack_size(uint32_t size);
static inline Uos_Task* _get_task(Uos_Task* task);

void uos_init(void)
{
	for (uint8_t count = 0; count < UOS_TASK_PRIOS; count++)
	{
		ll_init(&_tasks[count]);
	}
	
	uos_mcu_scheduler_init();
}

void uos_schedule(void)
{
	
}

bool uos_task_create(Uos_Task* task, const Uos_Task_Config* config, void* arg)
{
	return _task_create(task, config, false);
}

bool uos_task_create_suspended(Uos_Task* task, const Uos_Task_Config* config, void* arg)
{
	return _task_create(task, config, true);
}

static bool _task_create(Uos_Task* task, const Uos_Task_Config* config, bool suspended)
{
	if ((task == nullptr) || (config == nullptr))
	{
		return false;
	}
	else if ((config->stack == nullptr) || (config->stack_size < UOS_TASK_STACK_MIN))
	{
		return false;
	}
	
	task->priority   = _get_task_prio(config->priority);
	task->stack_size = _get_stack_size(config->stack_size);
	task->stack      = config->stack;
	task->function   = config->function;
	lln_init(&task->node, task);
	
	if (!suspended)
	{
		uos_task_resume(task);
	}
	
	return true;
}

void uos_task_resume(Uos_Task* task)
{
	task = _get_task(task);
	
	enter_crticial();
	
	uos_schedule_task(task);
	
	exit_critical();
}

void uos_task_suspend(Uos_Task* task)
{
	
}

void uos_schedule_task(Uos_Task* task)
{	
	// The task can already be scheduled for operations such as resume
	if (task->node.parent == nullptr)
	{
		return;
	}
	
	uint8_t priority = task->priority;
	
	// Add the task to the priority list
	ll_append(&_tasks[priority], &task->node);
	
	// Set the flag to indicate at least 1 task of a given priority within the scheduler
	_prio_flags |= 1 << priority;
	
	if ((_uos_current_task == nullptr) || (priority < _uos_current_task->priority))
	{
		uos_mcu_invoke_scheduler();
	}
}

static inline uint8_t _get_task_prio(uint8_t priority)
{
	return priority <= UOS_TASK_PRIO_MIN ? priority : UOS_TASK_PRIO_MIN;
}

static inline uint32_t _get_stack_size(uint32_t size)
{
	return 1 << __clz(size);
}

static inline Uos_Task* _get_task(Uos_Task* task)
{
	return task != nullptr ? task : _uos_current_task;
}