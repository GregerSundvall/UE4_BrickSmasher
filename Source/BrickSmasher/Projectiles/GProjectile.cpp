
#include "GProjectile.h"
#include "BrickSmasher/Bricks/GBrick.h"
#include "Components/SphereComponent.h"


class AGBrick;

AGProjectile::AGProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
	AddActorWorldOffset(SpawnOffset);
}

void AGProjectile::Init(AGPlayer* Shooter)
{
	Player = Shooter;
	CurrentMaxVelocity = StartVelocity.Size();
	
	ProjectileVelocity = GetActorUpVector() * StartVelocity;
	
	// Fire a "curveball"
	// Take Y velocity from paddle and apply to projectile. Deduct Y velocity from Z velocity
	// to not get more total velocity by "curveballing". Clamp to half of projectile Z velocity
	// to limit angle to 45 degrees.
	ProjectileVelocity.Y = FMath::Clamp(Player->MoveComponent->PaddleVelocity.Y,
		-ProjectileVelocity.Z / 2, ProjectileVelocity.Z / 2);
	ProjectileVelocity.Z -= FMath::Abs(ProjectileVelocity.Y);
}

void AGProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AGProjectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CurrentMaxVelocity *= VelocityRampUp;
	
	FHitResult Hit;
	AddActorWorldOffset(ProjectileVelocity * DeltaSeconds, true, &Hit);
	if (Hit.bBlockingHit)
	{
		ProjectileVelocity = ProjectileVelocity.MirrorByVector(Hit.Normal);
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
			Other->Health --;
		}
	}

	if (GetActorLocation().Z < -30)
	{
		Player->OnProjectileDead();
		Destroy();
	}


}

void AGProjectile::OnShoot_Implementation()
{
}

void AGProjectile::OnHit_Implementation()
{
}

