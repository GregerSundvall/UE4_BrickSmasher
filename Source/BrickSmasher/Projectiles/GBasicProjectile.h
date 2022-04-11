﻿
#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GProjectile.generated.h"

UCLASS()
class BRICKSMASHER_API AGBasicProjectile : public AActor
{
	GENERATED_BODY()

public:
	AGBasicProjectile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Collision;

	FVector ProjectileVelocity;

	// TSubclassOf<AActor>* Other;
	
};