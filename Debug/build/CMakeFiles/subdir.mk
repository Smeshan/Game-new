################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../build/CMakeFiles/feature_tests.cxx 

CXX_DEPS += \
./build/CMakeFiles/feature_tests.d 

OBJS += \
./build/CMakeFiles/feature_tests.o 


# Each subdirectory must supply rules for building sources it contributes
build/CMakeFiles/%.o: ../build/CMakeFiles/%.cxx build/CMakeFiles/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


