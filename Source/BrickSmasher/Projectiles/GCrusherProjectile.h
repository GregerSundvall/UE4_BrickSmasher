
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GCrusherProjectile.generated.h"

UCLASS()
class BRICKSMASHER_API AGCrusherProjectile : public AActor
{
	GENERATED_BODY()

public:
	AGCrusherProjectile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
