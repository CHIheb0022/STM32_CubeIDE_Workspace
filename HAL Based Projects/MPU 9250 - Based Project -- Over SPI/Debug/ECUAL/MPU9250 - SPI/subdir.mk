################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/MPU9250\ -\ SPI/MPU9250.c 

OBJS += \
./ECUAL/MPU9250\ -\ SPI/MPU9250.o 

C_DEPS += \
./ECUAL/MPU9250\ -\ SPI/MPU9250.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/MPU9250\ -\ SPI/MPU9250.o: ../ECUAL/MPU9250\ -\ SPI/MPU9250.c ECUAL/MPU9250\ -\ SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"ECUAL/MPU9250 - SPI/MPU9250.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ECUAL-2f-MPU9250-20--2d--20-SPI

clean-ECUAL-2f-MPU9250-20--2d--20-SPI:
	-$(RM) ./ECUAL/MPU9250\ -\ SPI/MPU9250.cyclo ./ECUAL/MPU9250\ -\ SPI/MPU9250.d ./ECUAL/MPU9250\ -\ SPI/MPU9250.o ./ECUAL/MPU9250\ -\ SPI/MPU9250.su

.PHONY: clean-ECUAL-2f-MPU9250-20--2d--20-SPI

