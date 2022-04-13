

#include "GCamera.h"

#include "Kismet/KismetMathLibrary.h"


AGCamera::AGCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	
}

void AGCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	Controller->SetViewTarget(this);
	SetActorLocation(Offset);
}

void AGCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActorToFollow == nullptr)
	{
		return;
	}
	FVector Location = GetActorLocation();
	Location.Y = FMath::Lerp(Location.Y, ActorToFollow->GetActorLocation().Y, FollowSpeed * DeltaTime);
	// Location = FMath::Lerp(Location, ActorToFollow->GetActorLocation(), FollowSpeed * DeltaTime);
	SetActorLocation(Location);

	FVector DirectionTowardsYawPoint = YawCenterPoint - GetActorLocation();
	DirectionTowardsYawPoint.Normalize();
	auto RotatorTowardsCenter = UKismetMathLibrary::MakeRotFromX(DirectionTowardsYawPoint);
	RotatorTowardsCenter.Pitch = 0;
	RotatorTowardsCenter.Roll = 0;
	SetActorRotation(RotatorTowardsCenter);
	
	
}

