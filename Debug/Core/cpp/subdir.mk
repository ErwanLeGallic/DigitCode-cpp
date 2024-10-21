################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/cpp/Buzzer.cpp \
../Core/cpp/Peripherique.cpp \
../Core/cpp/main.cpp 

OBJS += \
./Core/cpp/Buzzer.o \
./Core/cpp/Peripherique.o \
./Core/cpp/main.o 

CPP_DEPS += \
./Core/cpp/Buzzer.d \
./Core/cpp/Peripherique.d \
./Core/cpp/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/cpp/%.o Core/cpp/%.su Core/cpp/%.cyclo: ../Core/cpp/%.cpp Core/cpp/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -D__cplusplus -DSTM32L152xE -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/sofia/STM32CubeIDE/workspace_1.16.1/DigitCode-cpp/Core/cpp" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-cpp

clean-Core-2f-cpp:
	-$(RM) ./Core/cpp/Buzzer.cyclo ./Core/cpp/Buzzer.d ./Core/cpp/Buzzer.o ./Core/cpp/Buzzer.su ./Core/cpp/Peripherique.cyclo ./Core/cpp/Peripherique.d ./Core/cpp/Peripherique.o ./Core/cpp/Peripherique.su ./Core/cpp/main.cyclo ./Core/cpp/main.d ./Core/cpp/main.o ./Core/cpp/main.su

.PHONY: clean-Core-2f-cpp

