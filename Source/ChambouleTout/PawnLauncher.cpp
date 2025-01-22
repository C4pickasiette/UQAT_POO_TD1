// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnLauncher.h"
#include "Projectile.h"
#include "GameMode_ChambouleTout.h"

void APawnLauncher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Appel de la fonction parent de SetupPlayerInputComponent
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Association de l'input "SpawnProjectile" a la fonction APawnLauncher::SpawnProjectile
	PlayerInputComponent->BindAction("SpawnProjectile", IE_Pressed, this, &APawnLauncher::SpawnProjectile);
}

void APawnLauncher::BeginPlay()
{
	// Appel de la fonction parent de BeginPlay
	Super::BeginPlay();

	// Affichage du nombre de projectile
	LogProjectiles();
}

void APawnLauncher::SpawnProjectile()
{
	// Verification du nombre de projectile restant
	if (ProjectileCanSpawn())
	{
		// Initialisation de la position et de l'orientation du projectile
		FVector Location = GetActorLocation();
		FRotator Rotation = GetControlRotation();

		// Instantiation de l'actor
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
		
		// Decompte d'un projectile
		DecreaseRemainingProjectiles();

		// Verification du nombre de projectile restant
		if (ProjectileCanSpawn() == false)
		{
			// Affichage du message "Level reload in 5 seconds" a l'ecran
			GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, TEXT("Level reload in 5 seconds"));
			// Initialisation d'un timer, et appel de APawnLauncher::CallReloadLevel dans 5 secondes
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APawnLauncher::CallReloadLevel, 5.0f, true);

		}
	}
}

void APawnLauncher::CallReloadLevel()
{
	// Appel de la methode static AGameMode_ChambouleTout::reloadLevel
	AGameMode_ChambouleTout::reloadLevel(this);
}

void APawnLauncher::LogProjectiles()
{
	// Affichage du nombre de projectile dans le log
	UE_LOG(LogTemp, Log, TEXT("Spawn Projectile, remain : %d"), RemainingProjectiles)

	// Affichage du nombre de projectile sur l'ecran
	FString Message = FString::Printf(TEXT("Projectile : %d"), RemainingProjectiles);
	GEngine->AddOnScreenDebugMessage(1, 100.0f, FColor::Black, Message);
}

void APawnLauncher::DecreaseRemainingProjectiles()
{
	// Decrementation de la variable RemainingProjectiles
	RemainingProjectiles--;

	// Affichage du nombre de projectile
	LogProjectiles();
}

bool APawnLauncher::ProjectileCanSpawn()
{
	// Retourne true si RemainingProjectiles est superieur a 0
	return RemainingProjectiles > 0;
}

