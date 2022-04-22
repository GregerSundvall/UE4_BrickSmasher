

#include "GCrusherProjectile.h"

#include "BrickSmasher/Bricks/GBrick.h"


class AGBrick;

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

	FHitResult Hit;
	AddActorWorldOffset(ProjectileVelocity * DeltaTime, true, &Hit);
	if (Hit.bBlockingHit)
	{
		if (const AGPlayer* Other = Cast<AGPlayer, AActor>(Hit.GetActor()))
		{
			
			ProjectileVelocity.Y += Other->MoveComponent->PaddleVelocity.Y * 0.5f;
			// ProjectileVelocity.Y = FMath::Clamp(ProjectileVelocity.Y, -200.f, 200.f);
			while (ProjectileVelocity.Size() > CurrentMaxVelocity)
			{
				ProjectileVelocity *= 0.999;
			}
		}
		
		if (AGBrick* Other = Cast<AGBrick, AActor>(Hit.GetActor()))
		{
			Other->Health = 0;
		}
		else
		{
			ProjectileVelocity = ProjectileVelocity.MirrorByVector(Hit.Normal);
		}
	}

	if (GetActorLocation().Z < -30)
	{
		Player->OnProjectileDead();
		Destroy();
	}
}

