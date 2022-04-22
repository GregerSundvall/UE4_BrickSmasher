

#include "GBrick.h"


AGBrick::AGBrick()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGBrick::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGBrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	
	if (Health == 0)
	{
		IAmDead();
		// Destroy();
	}
}

void AGBrick::SetOwnerArray(const TArray<AGBrick*> OwningArray)
{
	OwnerArray = OwningArray;
}

void AGBrick::RemoveFromOwnerArray()
{
	OwnerArray.Remove(this);
	
}

void AGBrick::SetParentLevel(AGLevel* Level)
{
	ParentLevel = Level;
}

void AGBrick::IAmDead_Implementation()
{
	
}

