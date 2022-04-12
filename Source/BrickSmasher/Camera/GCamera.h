
#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "GCamera.generated.h"

UCLASS()
class BRICKSMASHER_API AGCamera : public AActor
{
	GENERATED_BODY()

public:
	AGCamera();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditAnywhere, Category = "Object to follow")
	AActor* ActorToFollow;
	
	UPROPERTY(EditAnywhere, Category ="Object to follow")
	float FollowSpeed = 5.0f;
	
	UPROPERTY(EditAnywhere, Category = "Object to follow")
	float ZOffset = -300.0f;

};
