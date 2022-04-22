
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GBrick.generated.h"


class AGLevel;
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

	UFUNCTION(BlueprintNativeEvent)
	void IAmDead();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AGBrick*> OwnerArray;

	UFUNCTION(BlueprintCallable)
	void SetOwnerArray(const TArray<AGBrick*> OwningArray);

	UFUNCTION(BlueprintCallable)
	void RemoveFromOwnerArray();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AGLevel* ParentLevel;
	
	UFUNCTION(BlueprintCallable)
	void SetParentLevel(AGLevel* Level);
	

};
