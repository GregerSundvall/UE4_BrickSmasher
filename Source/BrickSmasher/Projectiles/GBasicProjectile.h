
#pragma once

#include "CoreMinimal.h"
#include "GProjectile.h"
#include "Components/SphereComponent.h"
#include "GBasicProjectile.generated.h"

UCLASS(Abstract)
class BRICKSMASHER_API AGBasicProjectile : public AGProjectile
{
	GENERATED_BODY()

public:
	AGBasicProjectile();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void OnShoot_Implementation() override;
	
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* Collision;

	UPROPERTY(EditDefaultsOnly)
	FVector ProjectileVelocity;

	UPROPERTY(EditDefaultsOnly)
	FVector SpawnOffset = FVector(0,0,25);

	

	
};
