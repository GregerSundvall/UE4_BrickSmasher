

#include "GProjectile.h"

#include "BrickSmasher/Bricks/GBrick.h"
#include "BrickSmasher/Player/GPlayer.h"


AGProjectile::AGProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
	
}

void AGProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileVelocity = GetActorForwardVector() * 300.f;
	
}

void AGProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult Hit;
	AddActorWorldOffset(ProjectileVelocity * DeltaTime, true, &Hit);
	if (Hit.bBlockingHit)
	{
		ProjectileVelocity = ProjectileVelocity.MirrorByVector(Hit.Normal);
		if (AGPlayer* Other = Cast<AGPlayer, AActor>(Hit.GetActor()))
		{
			ProjectileVelocity.Y += Other->MoveComponent->PaddleVelocity.Y * 0.5f;
			// if (ProjectileVelocity.Y > ProjectileVelocity.X)
			// {
			// 	ProjectileVelocity.Y = ProjectileVelocity.X;
			// }
			// if (ProjectileVelocity.Y < ProjectileVelocity.X)
			// {
			// 	ProjectileVelocity.Y = ProjectileVelocity.X
			// }
		}
		
		if (AGBrick* Other = Cast<AGBrick, AActor>(Hit.GetActor()))
		{
			Other->Health --;
		}
	}

	
}

