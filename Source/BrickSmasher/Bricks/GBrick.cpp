// Fill out your copyright notice in the Description page of Project Settings.


#include "GBrick.h"


// Sets default values
AGBrick::AGBrick()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGBrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGBrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health == 0)
	{
		Destroy();
	}
}

