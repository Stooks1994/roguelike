################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CollidableObject.cpp \
../src/CollisionManager.cpp \
../src/FrameTimer.cpp \
../src/Game.cpp \
../src/GameObject.cpp \
../src/Map.cpp \
../src/Player.cpp \
../src/Projectile.cpp \
../src/ProjectileManager.cpp \
../src/TextureManager.cpp \
../src/main.cpp 

OBJS += \
./src/CollidableObject.o \
./src/CollisionManager.o \
./src/FrameTimer.o \
./src/Game.o \
./src/GameObject.o \
./src/Map.o \
./src/Player.o \
./src/Projectile.o \
./src/ProjectileManager.o \
./src/TextureManager.o \
./src/main.o 

CPP_DEPS += \
./src/CollidableObject.d \
./src/CollisionManager.d \
./src/FrameTimer.d \
./src/Game.d \
./src/GameObject.d \
./src/Map.d \
./src/Player.d \
./src/Projectile.d \
./src/ProjectileManager.d \
./src/TextureManager.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


