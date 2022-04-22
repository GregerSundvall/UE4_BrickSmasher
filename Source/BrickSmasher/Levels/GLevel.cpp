

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

void AGLevel::AddBrick(AGBrick* Brick)
{
	Bricks.Add(Brick);
}

void AGLevel::RemoveBrick(AGBrick* Brick)
{
	Bricks.Remove(Brick);
	
}









