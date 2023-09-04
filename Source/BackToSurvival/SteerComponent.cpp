// Fill out your copyright notice in the Description page of Project Settings.


#include "SteerComponent.h"

// Sets default values for this component's properties
USteerComponent::USteerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	velocity = FVector::ZeroVector;

	// ...
}


// Called when the game starts
void USteerComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void USteerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

FVector USteerComponent::Truncate(FVector v, float m) {
	if (v.Length() == 0.0 || v.Length() < m) {
		return v;
	}
	return (m * v) / v.Length();
}

// compute the new position
FVector USteerComponent::Compute(FVector pos, FVector steering) {
	FVector acceleration = Truncate(steering, max_force) / mass;
	velocity = Truncate(velocity + acceleration, max_speed);

	return pos + velocity;
}

FVector USteerComponent::Seek(const FVector& position, const FVector& target) {
	if (mass == 0.0) {
		return target;
	}

	FVector res = target - position;
	res.Normalize();
	res = res * max_speed - velocity; // steering = desired_velocity - velocity

	return Compute(position, res);
}

FVector USteerComponent::Flee(const FVector& position, const FVector& target) {
	if (mass == 0.0) {
		return target;
	}

	FVector res = position - target;
	res.Normalize();
	res = res * max_speed - velocity; // steering = desired_velocity - velocity

	return Compute(position, res);
}


FVector USteerComponent::Pursuit(const FVector& position, const FVector& target, const FVector& velocity_target) {
	FVector d = target - position;
	FVector unit_forward = velocity;
	unit_forward.Normalize();
	FVector unit_forward_target = velocity_target;
	unit_forward_target.Normalize();
	double t = FVector::DotProduct(unit_forward, unit_forward_target) * FVector::DotProduct(velocity_target, d); // d*c

	return Seek(position, target + velocity_target * t);
}

FVector USteerComponent::Evasion(const FVector& position, const FVector& target, const FVector& velocity_target) {
	FVector d = target - position;
	FVector unit_forward = velocity;
	unit_forward.Normalize();
	FVector unit_forward_target = velocity_target;
	unit_forward_target.Normalize();
	double t = FVector::DotProduct(unit_forward, unit_forward_target) * FVector::DotProduct(velocity_target, d); // d*c

	return Flee(position, target + velocity_target * t);
}

FVector USteerComponent::Arrival(const FVector& position, const double slowing_d, const FVector& target) {
	if (mass == 0.0) {
		return target;
	}

	FVector res = target - position; // target_offset
	double d = res.Length();
	if (d == 0.0) {
		velocity = FVector::ZeroVector;
		return position;
	}

	double ramped_speed = max_speed * (d / slowing_d);
	res *= FMath::Min(ramped_speed, max_speed) / d; // desired_velocity = (clamped_speed / distance) * target_offset
	res -= velocity; // steering = desired_velocity - velocity

	return Compute(position, res);
}

inline FVector USteerComponent::GetVelocity() const{
	return velocity;
}