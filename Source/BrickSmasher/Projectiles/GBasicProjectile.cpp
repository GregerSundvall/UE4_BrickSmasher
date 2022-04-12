

#include "GBasicProjectile.h"
#include "BrickSmasher/Bricks/GBrick.h"
#include "BrickSmasher/Player/GPlayer.h"


AGBasicProjectile::AGBasicProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
	AddActorWorldOffset(SpawnOffset);
	
}

void AGBasicProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileVelocity = GetActorUpVector() * 300.f;
	
}

void AGBasicProjectile::Tick(float DeltaTime)
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

		}
		
		if (AGBrick* Other = Cast<AGBrick, AActor>(Hit.GetActor()))
		{
			Other->Health --;
		}
	}

	if (GetActorLocation().Z < -200)
	{
		//Player.bProjectileIsStillAlive = false;
		Destroy();
	}
	
}

void AGBasicProjectile::OnShoot_Implementation()
{
	Super::OnShoot_Implementation();
}



