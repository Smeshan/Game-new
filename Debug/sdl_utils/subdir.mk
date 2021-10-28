################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sdl_utils/SDLLoader.cpp 

OBJS += \
./sdl_utils/SDLLoader.o 

CPP_DEPS += \
./sdl_utils/SDLLoader.d 


# Each subdirectory must supply rules for building sources it contributes
sdl_utils/%.o: ../sdl_utils/%.cpp sdl_utils/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


