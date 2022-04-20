
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
	



	

	
};
