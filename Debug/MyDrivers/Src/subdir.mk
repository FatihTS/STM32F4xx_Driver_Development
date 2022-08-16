################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyDrivers/Src/GPIO.c \
../MyDrivers/Src/RCC.c 

OBJS += \
./MyDrivers/Src/GPIO.o \
./MyDrivers/Src/RCC.o 

C_DEPS += \
./MyDrivers/Src/GPIO.d \
./MyDrivers/Src/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
MyDrivers/Src/%.o: ../MyDrivers/Src/%.c MyDrivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/EmbededDrivers/DriverDevelopment/MyDrivers/Inc" -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

