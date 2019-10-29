################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../hello.cpp \
../main.cpp \
../output_formatting.cpp \
../size_of_variables.cpp \
../string_stream.cpp 

OBJS += \
./hello.o \
./main.o \
./output_formatting.o \
./size_of_variables.o \
./string_stream.o 

CPP_DEPS += \
./hello.d \
./main.d \
./output_formatting.d \
./size_of_variables.d \
./string_stream.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


