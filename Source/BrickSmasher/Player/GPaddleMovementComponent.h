
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GPaddleMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BRICKSMASHER_API UGPaddleMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGPaddleMovementComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void AddForce(const FVector& Force);
	void AddImpulse(const FVector& Impulse);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Acceleration = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Friction = 0.5f;

	UPROPERTY(VisibleAnywhere)
	FVector PaddleVelocity = FVector::ZeroVector;

	float GoRightInput = 0.0f;
};
