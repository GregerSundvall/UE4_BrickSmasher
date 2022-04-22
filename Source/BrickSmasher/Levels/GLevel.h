
#pragma once

#include "CoreMinimal.h"
#include "BrickSmasher/Bricks/GBrick.h"
#include "GLevel.generated.h"


UCLASS()
class BRICKSMASHER_API AGLevel : public AActor
{
	GENERATED_BODY()

public:
	AGLevel();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AGBrick> BrickClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AGBrick*> Bricks;

	UFUNCTION(BlueprintCallable)
	void AddBrick(AGBrick* Brick);

	UFUNCTION(BlueprintCallable)
	void RemoveBrick(AGBrick* Brick);
	
};
