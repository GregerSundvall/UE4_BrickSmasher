

#include "GCamera.h"


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
	
}

void AGCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActorToFollow == nullptr)
	{
		return;
	}
	FVector Location = GetActorLocation();
	Location = FMath::Lerp(Location, ActorToFollow->GetActorLocation(), FollowSpeed * DeltaTime);
	SetActorLocation(Location);
	
}

