# FreeRTOS: Queues

Today I delved into using Queues in FreeRTOS, and here's a rundown of what I learned:

## Introduction

I explored how to use Queues in FreeRTOS to facilitate communication between tasks.

### Simple Queue

- A simple Queue holds elements of the same data type.
- To begin, I created a Queue handler:
  ```c
  xQueueHandle SimpleQueue;
  ```
* Then, I created an integer Queue that can store 5 integers:
 
 ```c
SimpleQueue = xQueueCreate(5, sizeof(int));
 ```

* Tasks can send data to the Queue using xQueueSend and receive data using xQueueReceive.

# Structured Queue

* Unlike the simple Queue, a structured Queue can hold elements of different data types.
* I defined a structure my_struct to represent the data to be stored in the Queue.
* The Queue handler was created similarly to the simple Queue.
* Tasks can send structured data to the Queue, and receiving tasks must allocate memory to store the received data.
* Sending data from an ISR requires using interrupt-safe Queue functions like xQueueSendToFrontFromISR.

# Conclusion

I gained valuable insights into how tasks can effectively communicate through Queues, laying the groundwork for more complex interactions in future projects.