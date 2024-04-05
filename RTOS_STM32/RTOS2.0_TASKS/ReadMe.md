# Task Operations in FreeRTOS

In this example, I have explored some fundamental operations related to tasks in FreeRTOS. These operations include creating tasks, switching between tasks, suspending and resuming tasks, terminating tasks, and more. 

## Introduction

A basic introduction to tasks and priorities in FreeRTOS.

### Creating a Task

To create a task in FreeRTOS, follow these steps:

1. **Define a Task Handler:** This handler will store the ID of the created task.
    ```c
    osThreadId Task2Handler;
    ```

2. **Define the Thread:** Use `osThreadDef` to define the thread.
    ```c
    osThreadDef(Task2, task2_init, osPriorityNormal, 0, 128);
    ```

3. **Create the Task:** Create the thread and assign the ID to the task handler.
    ```c
    Task2Handler = osThreadCreate(osThread(Task2), NULL);
    ```

4. **Task Entry Function:** Write the code inside the entry function of the task.
    ```c
    void task2_init(void const * argument) {
        while (1) {
            printf("Task2 = %d\n", indx++);
            osDelay(2000);
        }
    }
    ```

### Switching Between Tasks

In FreeRTOS, tasks are switched based on their priorities. Higher priority tasks are executed before lower priority tasks.

### Suspend and Resume Tasks

Tasks can be suspended and resumed using `osThreadSuspend` and `osThreadResume` functions, respectively.

### Terminating the Task

Use `osThreadTerminate` function to terminate a task. Once terminated, a task cannot be resumed.

### Block the Task for Some Time

Tasks can be blocked for a specific duration using `osDelayUntil` function.

## Conclusion

This concludes our overview of basic task operations in FreeRTOS. 
