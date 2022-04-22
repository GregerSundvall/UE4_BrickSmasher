
#pragma once

#include "CoreMinimal.h"
#include "BrickSmasher/Player/GPlayer.h"
#include "GProjectile.generated.h"


class USphereComponent;
UCLASS(Abstract)
class BRICKSMASHER_API AGProjectile : public AActor
{
	GENERATED_BODY()


public:
	AGProjectile();
	void Init(AGPlayer* Shooter);
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintNativeEvent)
	void OnShoot();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnHit();


	UPROPERTY(EditAnywhere)
	FVector StartVelocity = FVector(0,0,300.f);

	UPROPERTY(EditAnywhere)
	float CurrentMaxVelocity;
	
	UPROPERTY(EditDefaultsOnly)
	FVector ProjectileVelocity;

	UPROPERTY(EditDefaultsOnly)
	float VelocityRampUp = 1.0001f;
	
	UPROPERTY(VisibleAnywhere)
	AGPlayer* Player;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* Collision;
	
	UPROPERTY(EditDefaultsOnly)
	FVector SpawnOffset = FVector(0,0,25);
	
};
