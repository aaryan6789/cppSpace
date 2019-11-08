################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../cmake-build-debug/CMakeFiles/feature_tests.cxx 

C_SRCS += \
../cmake-build-debug/CMakeFiles/feature_tests.c 

OBJS += \
./cmake-build-debug/CMakeFiles/feature_tests.o 

CXX_DEPS += \
./cmake-build-debug/CMakeFiles/feature_tests.d 

C_DEPS += \
./cmake-build-debug/CMakeFiles/feature_tests.d 


# Each subdirectory must supply rules for building sources it contributes
cmake-build-debug/CMakeFiles/%.o: ../cmake-build-debug/CMakeFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cmake-build-debug/CMakeFiles/%.o: ../cmake-build-debug/CMakeFiles/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


