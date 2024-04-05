# Getting Started with FreeRTOS in STM32

In this document, I'll outline the initial steps I took to understand tasks and priorities in FreeRTOS on an STM32 microcontroller. This serves as an introductory example to familiarize myself with these concepts.

## Setting up FreeRTOS using CubeMX

To begin, I set up FreeRTOS using CubeMX:
1. Selected the appropriate controller and opened CubeMX.
2. Chose FreeRTOS (version 1) as the operating system.
3. Navigated to the 'tasks and queues' tab where I found a default task already created.
4. Created another task named Task 2 with normal priority and specified its entry function as Task2_init.

## Understanding the Benefits of FreeRTOS

The primary advantage of FreeRTOS became apparent when I attempted to toggle two pins simultaneously with different delays. Without an operating system, this task is challenging due to the sequential execution of instructions. With FreeRTOS, I created two tasks, one for each pin, ensuring they toggle independently. This way, the scheduler ensures both tasks get enough time for execution.

## Creating a Task

To create a new task, I followed these steps:
1. Defined a ThreadID for the task to store its unique ID.
2. Defined the entry function for the task with an infinite loop inside which the program logic resides.
3. Inside the main function, I defined and created the task using `osThreadDef` and `osThreadCreate` respectively.

Here's a simplified example of creating a task:

```c
osThreadId Task3Handle;

void Task3_init(void const * argument)
{
    while (1)
    {
        // Task logic
        osDelay(1000); // 1 sec delay
    }
}

// Inside main function
osThreadDef(Task3, Task3_init, osPriorityBelowNormal, 0, 128);
Task3Handle = osThreadCreate(osThread(Task3), NULL);
```

# Managing Priorities in FreeRTOS
I learned that assigning priorities to tasks is crucial, especially when dealing with shared resources. Tasks with higher priorities get executed before those with lower priorities. By defining different priorities for different tasks, I ensured tasks executed in the desired order without waiting for each other.

Here's an example of defining task priorities:

```c
osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
osThreadDef(Task2, Task2_init, osPriorityAboveNormal, 0, 128);
osThreadDef(Task3, Task3_init, osPriorityBelowNormal, 0, 128);
```

# Conclusion

This example provided a foundational understanding of tasks and priorities in FreeRTOS on STM32. It serves as a stepping stone for further exploration into real-time operating systems for embedded systems development.