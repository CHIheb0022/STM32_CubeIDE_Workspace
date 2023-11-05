################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LM35/LM35.c \
../LM35/LM35_cfg.c 

OBJS += \
./LM35/LM35.o \
./LM35/LM35_cfg.o 

C_DEPS += \
./LM35/LM35.d \
./LM35/LM35_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
LM35/%.o LM35/%.su LM35/%.cyclo: ../LM35/%.c LM35/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LM35

clean-LM35:
	-$(RM) ./LM35/LM35.cyclo ./LM35/LM35.d ./LM35/LM35.o ./LM35/LM35.su ./LM35/LM35_cfg.cyclo ./LM35/LM35_cfg.d ./LM35/LM35_cfg.o ./LM35/LM35_cfg.su

.PHONY: clean-LM35

