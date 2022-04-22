
#pragma once

#include "CoreMinimal.h"
#include "GPaddleMovementComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "GPlayer.generated.h"


class AGProjectile;
class UGPlayerDataComponent;

UCLASS(Blueprintable)
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
	void OnProjectileDead();
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UGPlayerDataComponent* PlayerDataComponent;

	UPROPERTY(VisibleAnywhere)
	UGPaddleMovementComponent* MoveComponent;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGProjectile> ProjectileClass;

	UPROPERTY()
	bool bProjectileIsStillAlive = false;

	UPROPERTY(EditAnywhere)
	int ProjectilesLeft = 3;
	
};
