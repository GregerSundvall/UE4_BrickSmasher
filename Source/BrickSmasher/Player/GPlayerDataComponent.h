
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GPlayerDataComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BRICKSMASHER_API UGPlayerDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGPlayerDataComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Score;


	
	
};
