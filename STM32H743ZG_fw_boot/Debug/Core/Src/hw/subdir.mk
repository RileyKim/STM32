################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/hw/hw.cpp 

OBJS += \
./Core/Src/hw/hw.o 

CPP_DEPS += \
./Core/Src/hw/hw.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/hw/%.o Core/Src/hw/%.su: ../Core/Src/hw/%.cpp Core/Src/hw/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DUSE_UART_IT -DSTM32H743xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/taeka/STM32CubeIDE/workspace_1.5.0/STM32H743ZG_fw_boot/Core/Src/common" -I"C:/Users/taeka/STM32CubeIDE/workspace_1.5.0/STM32H743ZG_fw_boot/Core/Src/hw" -I"C:/Users/taeka/STM32CubeIDE/workspace_1.5.0/STM32H743ZG_fw_boot/Core/Src/bsp" -I"C:/Users/taeka/STM32CubeIDE/workspace_1.5.0/STM32H743ZG_fw_boot/Core/Src/logic" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-hw

clean-Core-2f-Src-2f-hw:
	-$(RM) ./Core/Src/hw/hw.d ./Core/Src/hw/hw.o ./Core/Src/hw/hw.su

.PHONY: clean-Core-2f-Src-2f-hw

