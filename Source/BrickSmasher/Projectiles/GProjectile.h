
#pragma once

#include "CoreMinimal.h"
#include "GProjectile.generated.h"


UCLASS(Blueprintable)
class BRICKSMASHER_API AGProjectile : public AActor
{
	GENERATED_BODY()


public:
	AGProjectile();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintNativeEvent)
	void OnShoot();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnHit();

	UPROPERTY()
	APawn* Player;
	
};
