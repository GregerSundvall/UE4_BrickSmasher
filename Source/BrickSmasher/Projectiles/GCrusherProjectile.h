
#pragma once

#include "CoreMinimal.h"
#include "GProjectile.h"
#include "GameFramework/Actor.h"
#include "GCrusherProjectile.generated.h"

UCLASS(Blueprintable)
class BRICKSMASHER_API AGCrusherProjectile : public AGProjectile
{
	GENERATED_BODY()

public:
	AGCrusherProjectile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
