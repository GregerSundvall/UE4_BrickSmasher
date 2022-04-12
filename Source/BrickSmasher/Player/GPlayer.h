
#pragma once

#include "CoreMinimal.h"
#include "GPaddleMovementComponent.h"
#include "BrickSmasher/Projectiles/GProjectile.h"
#include "GameFramework/Pawn.h"
#include "GPlayer.generated.h"

class UGPlayerDataComponent;

UCLASS()
class BRICKSMASHER_API AGPlayer : public APawn
{
	GENERATED_BODY()

public:
	AGPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void HandleMovePaddleInput(float Value);
	void HandleShootInput();
	void EquipProjectile(AGProjectile* NewProjectile);
	
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UGPlayerDataComponent* PlayerDataComponent;

	UPROPERTY(VisibleAnywhere)
	UGPaddleMovementComponent* MoveComponent;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGProjectile> ProjectileClass;

	UPROPERTY()
	bool bProjectileIsStillAlive = false;
	
};
