################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BruteForce.cpp \
../src/KMPMethod.cpp \
../src/StringMatchTest.cpp \
../src/main.cpp 

OBJS += \
./src/BruteForce.o \
./src/KMPMethod.o \
./src/StringMatchTest.o \
./src/main.o 

CPP_DEPS += \
./src/BruteForce.d \
./src/KMPMethod.d \
./src/StringMatchTest.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/zyin/Desktop/CodeProjects/C++/StringMatch/gtest/include" -I"/Users/zyin/Desktop/CodeProjects/C++/StringMatch/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


