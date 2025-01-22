// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.generated.h"


UCLASS()
class CHAMBOULETOUT_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// @brief Sets default values for this actor's properties
	AProjectile();
	// @brief Ajoute une impulsion physique au mesh
    void Impulse();

protected:
	// @brief Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// @brief Called every frame
	virtual void Tick(float DeltaTime) override;

public:	

	// @brief Variable du meshcomponent sur le quel agit la physique
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	UStaticMeshComponent* MeshComponent;
};
