

#include "GPlayer.h"

#include "GPlayerDataComponent.h"
#include "BrickSmasher/Projectiles/GProjectile.h"


AGPlayer::AGPlayer()
{
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = Root;

	PlayerDataComponent = CreateDefaultSubobject<UGPlayerDataComponent>(TEXT("Data"));

	MoveComponent = CreateDefaultSubobject<UGPaddleMovementComponent>(TEXT("Movement Component"));
	
	
}

void AGPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AGPlayer::HandleMovePaddleInput);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &AGPlayer::HandleShootInput);
	
}

void AGPlayer::HandleMovePaddleInput(float Value)
{
	MoveComponent->GoRightInput = Value;
}

void AGPlayer::HandleShootInput()
{
	if (!bProjectileIsStillAlive && ProjectilesLeft > 0)
	{
		FTransform SpawnTransform = GetActorTransform();
		auto Projectile = GetWorld()->SpawnActor(ProjectileClass, &SpawnTransform);
		auto Casted = Cast<AGProjectile>(Projectile);
		Casted->Init(this);

		ProjectilesLeft--;
		bProjectileIsStillAlive = true;

	}
}

void AGPlayer::OnProjectileDead()
{
	bProjectileIsStillAlive = false;

	if (ProjectilesLeft == 0)
	{
		GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
		2.0f,
		FColor::Emerald,
		TEXT("GAME OVER"),
		true,
		FVector2D(4.f)
		);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
		2.0f,
		FColor::Emerald,
		FString::Printf(TEXT("%i Projectiles Left"), ProjectilesLeft),
		true,
		FVector2D(4.f)
		);
	}
}


void AGPlayer::EquipProjectile(AGProjectile* NewProjectile)
{
	
}


