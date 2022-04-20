

#include "GPaddleMovementComponent.h"


UGPaddleMovementComponent::UGPaddleMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGPaddleMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UGPaddleMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Owner = GetOwner();

	// Apply acceleration
	PaddleVelocity += Owner->GetActorRightVector() * Acceleration * GoRightInput * DeltaTime;

	// Apply friction
	PaddleVelocity -= PaddleVelocity * Friction * DeltaTime;

	// Clamp to max velocity
	PaddleVelocity.Y = FMath::Clamp(PaddleVelocity.Y, -MaxVelocity, MaxVelocity);
	
	

	FHitResult HitResult;
	Owner->AddActorWorldOffset(PaddleVelocity * DeltaTime, true, &HitResult);

	if (HitResult.bBlockingHit == true)
	{
		PaddleVelocity.Y = -PaddleVelocity.Y / 2;
	}
}

void UGPaddleMovementComponent::AddForce(const FVector& Force)
{
	PaddleVelocity += Force * GetWorld()->GetDeltaSeconds();
}

void UGPaddleMovementComponent::AddImpulse(const FVector& Impulse)
{
	PaddleVelocity += Impulse;
}

