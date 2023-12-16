################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MPU9250-DMP.c \
../Core/Src/MPU9250.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/inv_mpu.c \
../Core/Src/inv_mpu_dmp_motion_driver.c \
../Core/Src/main.c \
../Core/Src/stm32_mpu9250_clk.c \
../Core/Src/stm32_mpu9250_i2c.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c 

OBJS += \
./Core/Src/MPU9250-DMP.o \
./Core/Src/MPU9250.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/inv_mpu.o \
./Core/Src/inv_mpu_dmp_motion_driver.o \
./Core/Src/main.o \
./Core/Src/stm32_mpu9250_clk.o \
./Core/Src/stm32_mpu9250_i2c.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o 

C_DEPS += \
./Core/Src/MPU9250-DMP.d \
./Core/Src/MPU9250.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/inv_mpu.d \
./Core/Src/inv_mpu_dmp_motion_driver.d \
./Core/Src/main.d \
./Core/Src/stm32_mpu9250_clk.d \
./Core/Src/stm32_mpu9250_i2c.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -IC:/Users/User/STM32Cube/Repository/STM32Cube_FW_L4_V1.17.2/Drivers/STM32L4xx_HAL_Driver/Inc -IC:/Users/User/STM32Cube/Repository/STM32Cube_FW_L4_V1.17.2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -IC:/Users/User/STM32Cube/Repository/STM32Cube_FW_L4_V1.17.2/Drivers/CMSIS/Device/ST/STM32L4xx/Include -IC:/Users/User/STM32Cube/Repository/STM32Cube_FW_L4_V1.17.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/MPU9250-DMP.cyclo ./Core/Src/MPU9250-DMP.d ./Core/Src/MPU9250-DMP.o ./Core/Src/MPU9250-DMP.su ./Core/Src/MPU9250.cyclo ./Core/Src/MPU9250.d ./Core/Src/MPU9250.o ./Core/Src/MPU9250.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/inv_mpu.cyclo ./Core/Src/inv_mpu.d ./Core/Src/inv_mpu.o ./Core/Src/inv_mpu.su ./Core/Src/inv_mpu_dmp_motion_driver.cyclo ./Core/Src/inv_mpu_dmp_motion_driver.d ./Core/Src/inv_mpu_dmp_motion_driver.o ./Core/Src/inv_mpu_dmp_motion_driver.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32_mpu9250_clk.cyclo ./Core/Src/stm32_mpu9250_clk.d ./Core/Src/stm32_mpu9250_clk.o ./Core/Src/stm32_mpu9250_clk.su ./Core/Src/stm32_mpu9250_i2c.cyclo ./Core/Src/stm32_mpu9250_i2c.d ./Core/Src/stm32_mpu9250_i2c.o ./Core/Src/stm32_mpu9250_i2c.su ./Core/Src/stm32l4xx_hal_msp.cyclo ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_it.cyclo ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.cyclo ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su

.PHONY: clean-Core-2f-Src

