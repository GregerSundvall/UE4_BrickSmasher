

#include "GLevel.h"

AGLevel::AGLevel()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
}

void AGLevel::BeginPlay()
{
	Super::BeginPlay();
}

void AGLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
