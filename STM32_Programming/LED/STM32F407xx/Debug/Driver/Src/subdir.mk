################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/STM32F407xx_gpiodriver.c 

OBJS += \
./Driver/Src/STM32F407xx_gpiodriver.o 

C_DEPS += \
./Driver/Src/STM32F407xx_gpiodriver.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o Driver/Src/%.su Driver/Src/%.cyclo: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/Embedded Programming/STM32_Programming/LED/STM32F407xx/Driver/Inc" -I"D:/Embedded Programming/STM32_Programming/LED/STM32F407xx/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/STM32F407xx_gpiodriver.cyclo ./Driver/Src/STM32F407xx_gpiodriver.d ./Driver/Src/STM32F407xx_gpiodriver.o ./Driver/Src/STM32F407xx_gpiodriver.su

.PHONY: clean-Driver-2f-Src

