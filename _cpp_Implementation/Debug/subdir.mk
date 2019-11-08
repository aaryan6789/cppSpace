################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp \
../relational_operators.cpp \
../variable_assignment.cpp \
../volume.cpp 

OBJS += \
./main.o \
./relational_operators.o \
./variable_assignment.o \
./volume.o 

CPP_DEPS += \
./main.d \
./relational_operators.d \
./variable_assignment.d \
./volume.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


