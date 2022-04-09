

#include "GPlayer.h"

#include "GPlayerDataComponent.h"
#include "BrickSmasher/Projectiles/GProjectile.h"


AGPlayer::AGPlayer()
{
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
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
	if (!bProjectileIsStillAlive)
	{
		AGProjectile->;
		bProjectileIsStillAlive = true;
	}
}

