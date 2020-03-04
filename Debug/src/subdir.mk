################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/As3.cpp \
../src/Aspect.cpp \
../src/BaseApplication.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp 

OBJS += \
./src/As3.o \
./src/Aspect.o \
./src/BaseApplication.o \
./src/Entity381.o \
./src/EntityMgr.o 

CPP_DEPS += \
./src/As3.d \
./src/Aspect.d \
./src/BaseApplication.d \
./src/Entity381.d \
./src/EntityMgr.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/cmollise/workspace/As3/inc" -I/usr/include/ois -I/usr/local/include/OGRE/Overlay -I/usr/local/include/OGRE -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


