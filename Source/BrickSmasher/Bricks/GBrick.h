
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GBrick.generated.h"

UCLASS()
class BRICKSMASHER_API AGBrick : public AActor
{
	GENERATED_BODY()

public:
	AGBrick();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Health = 1;

};
