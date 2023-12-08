/*
 * File: HCSR04_cfg.c
 * Driver Name: [[ HC-SR04 Ultrasonic Sensor ]]
 * SW Layer:   ECUAL
 * Created on: Jun 28, 2020
 * Author:     Khaled Magdy
 * -------------------------------------------
 * For More Information, Tutorials, etc.
 * Visit Website: www.DeepBlueMbedded.com
 *
 */

//CHIHEB:The modified lines of the following header file from the ECUAL Library will be commented.

#include "../HCSR04/HCSR04.h"

const HCSR04_CfgType HCSR04_CfgParam[HCSR04_UNITS] = // HCSR04_UNITS meaning that we can configure in the same table HCSR04_CfgParam two or more HCSR04 objects.
{
    // HC-SR04 Sensor Unit 1 Configurations
    {
	GPIOB,
	GPIO_PIN_12, // as the library suggest i will use the PB12 as an GPIO output for triggering the sensor (Since it's a free).
	TIM3,
	TIM_CHANNEL_1, // (TIM3,Channel_1) couple defines the GPIO pin used as a PWM input compare mode. Which is PA6 in this case.
	20 // Am using a 20Mhz clock frequency. and it will remain the same on the APB connected to Timer4 (Pres=1).
	  // Once configured the clock signal source must align on all used peripheral.
    }
};
