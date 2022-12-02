################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/logic/Tasks.cpp \
../Core/Src/logic/ap.cpp 

OBJS += \
./Core/Src/logic/Tasks.o \
./Core/Src/logic/ap.o 

CPP_DEPS += \
./Core/Src/logic/Tasks.d \
./Core/Src/logic/ap.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/logic/%.o Core/Src/logic/%.su: ../Core/Src/logic/%.cpp Core/Src/logic/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DUSE_UART_IT -DSTM32H743xx -DDEBUG -c -I"C:/Users/taeka/STM32CubeIDE/workspace_1.5.0/STM32H743ZG_fw/Core/Src/common" -I"C:/Users/taeka/STM32CubeIDE/workspace_1.5.0/STM32H743ZG_fw/Core/Src/hw" -I"C:/Users/taeka/STM32CubeIDE/workspace_1.5.0/STM32H743ZG_fw/Core/Src/bsp" -I"C:/Users/taeka/STM32CubeIDE/workspace_1.5.0/STM32H743ZG_fw/Core/Src/logic" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-logic

clean-Core-2f-Src-2f-logic:
	-$(RM) ./Core/Src/logic/Tasks.d ./Core/Src/logic/Tasks.o ./Core/Src/logic/Tasks.su ./Core/Src/logic/ap.d ./Core/Src/logic/ap.o ./Core/Src/logic/ap.su

.PHONY: clean-Core-2f-Src-2f-logic

