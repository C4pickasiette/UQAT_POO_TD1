// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "PawnLauncher.generated.h"

/**
 * 
 */
UCLASS()
class CHAMBOULETOUT_API APawnLauncher : public ADefaultPawn
{
	GENERATED_BODY()

private:
	// @brief Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// @brief Instantiation d'un projectile
	void SpawnProjectile();

	// @brief Decrementation du nombre de projectile
	void DecreaseRemainingProjectiles();
	// @brief Verification du nombre de projectile restant
	bool ProjectileCanSpawn();

	// @brief Appel de la fonciton reloadLevel
	void CallReloadLevel();

	// @brief Affichage du nombre de projectile
	void LogProjectiles();

protected:
	// @brief Override BeginPlay
	virtual void BeginPlay() override;

public:
	// @brief Variable de definition du projectile
	UPROPERTY(EditAnywhere, Category = "Projectiles")
	TSubclassOf<AActor> ProjectileBlueprint;

	// @brief Variable du nombre maximum de projectile
	UPROPERTY(EditAnywhere, Category = "Projectiles")
	int RemainingProjectiles;
};
