# STM32 Workspace

The projects presented here offer a glimpse into my STM32 Boards learning journey, illustrating the progression of my skills. This repository serves multiple purposes:

* A beginner's guide, facilitating a seamless learning journey with a smooth escalation.
* A personal portfolio showcasing my proficiency in the C programming language and embedded environments (STM32).
* A foundational library intended to support more advanced projects.

This repository contains a collection of my personal projects developed for STM32 . The projects are organized into two main categories: HAL-based projects and LL-based projects.

## HAL-Based Projects

The Hardware Abstraction Layer (HAL) is a high-level library provided by STMicroelectronics to abstract the hardware details and simplify the development process.

### Projects List

* **LED Toggle:** Simple project to toggle an LED [Project No. 1].
   - GPIO in output mode.
   - `HAL_GPIO_Toggle(GPIO_PORTX, GPIO_PIN_X)`
   - How to use `Delay(t ms)` function.
* **LED control using user Button:** Controlling an LED with an external control source [Project No. 2].
   - GPIO in input push-pull mode.
   - Reading GPIO pin state using `HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)`.
   - Set and reset GPIO pins.
* **Button Interrupt:** Handling button press using interrupts [No. 3].
   - Enabling EXTI channel using interrupt view in CubeMX.
   - Callback function and ISR implementation.
   - External variables.
* **Debug session:** Breakpoints and watchpoints using SWD [No. 4].
   - How to enable SWD using CubeMX and CubeIDE on debug session.
   - Select a breakpoint/watchpoint.
   - Use `printf` for console debugging.
   - Live expression view to monitor data.
   - How to use SWV: ITM data console trace window & data trace timeline Graph window.
* **UART Communication:** PC/STM32 <--> STM32 greeting: "Hello world" [No. 10 --> N° 12].
   - Configure UART1 to establish Board to board communication.
   - Use UART2 bridging STM32 with your PC through ST_link debugger.
   - Monitor exchanged messages using 3 different tools (SWD & printf, Real term, Pyserial library).
   - Polling, Interrupt and DMA mode.
   - Sprintf() function. 
   ...

These projects draw inspiration from the [DeepBlue course](https://deepbluembedded.com/stm32-arm-programming-tutorials/) on STM32 boards.

## LL-Based Projects

The Low-Level (LL) library provides a lower-level interface compared to the HAL and gives more direct access to the hardware.

### Projects List

* **LL LED Toggle:** LED toggle using LL programming.
* **LL Timer Configuration:** Configuring timers using LL.
* **LL SPI Communication:** SPI communication with LL.
   ...

These projects showcase my practice and exercises through the Udemy course on [Bare metal programming](https://www.udemy.com/course/embedded-systems-bare-metal-programming//) using STM32 MCUs.

### Advanced HAL-based Projects:

* **Capture and plot data stream sent through UART:**
* **Remote controlled ROBOT:**
* **Interfacing and gather MPU9250 data:**

## Usage

These projects are configured using CubeMX and are designed for the **STM32L476RG** board.

You can navigate to each project's folder for detailed instructions and source code and adapt to the board you are working on.

Feel free to explore and use these projects as a reference for STM32 development. If you have any questions or improvements, don't hesitate to open an issue or contribute.

Happy coding!


**Note:** This README provides an overview of the repository structure. The repository contains many more projects that are not yet described here. I will be working on updating the README to include more detailed information about additional projects. Stay tuned for more exciting content!
