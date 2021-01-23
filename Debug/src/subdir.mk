################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BlobMovement.cpp \
../src/CollidableObject.cpp \
../src/Consumable.cpp \
../src/ConsumableHeart.cpp \
../src/ConsumableMoney.cpp \
../src/Enemy.cpp \
../src/EntityManager.cpp \
../src/Game.cpp \
../src/Map.cpp \
../src/MovementAI.cpp \
../src/Player.cpp \
../src/Projectile.cpp \
../src/TextureManager.cpp \
../src/main.cpp 

OBJS += \
./src/BlobMovement.o \
./src/CollidableObject.o \
./src/Consumable.o \
./src/ConsumableHeart.o \
./src/ConsumableMoney.o \
./src/Enemy.o \
./src/EntityManager.o \
./src/Game.o \
./src/Map.o \
./src/MovementAI.o \
./src/Player.o \
./src/Projectile.o \
./src/TextureManager.o \
./src/main.o 

CPP_DEPS += \
./src/BlobMovement.d \
./src/CollidableObject.d \
./src/Consumable.d \
./src/ConsumableHeart.d \
./src/ConsumableMoney.d \
./src/Enemy.d \
./src/EntityManager.d \
./src/Game.d \
./src/Map.d \
./src/MovementAI.d \
./src/Player.d \
./src/Projectile.d \
./src/TextureManager.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


