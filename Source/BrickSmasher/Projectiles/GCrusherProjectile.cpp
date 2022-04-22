

#include "GCrusherProjectile.h"


AGCrusherProjectile::AGCrusherProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGCrusherProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGCrusherProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

