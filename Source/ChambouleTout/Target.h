#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Target.generated.h"

/**
* @brief Classe de gestion des cibles (Target).
* Gere la collision avec les autres objets et le score qui en decoule
*/
UCLASS()
class CHAMBOULETOUT_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// @brief Constructeur de la class ATarget
	ATarget();

	// @brief Initialisation de la Target
	// Desactive le comptage de collision et le reactive avec un delay de x temps
	void setupTarget();

	// @brief Active le comptage de collision
	void enableCollisionCount();

protected:
	// @brief Surcharge de la fonction d'Unreal Engine BeginPlay()
	virtual void BeginPlay() override;

	// @brief Surcharge de la fonction d'Unreal Engine Tick()
	virtual void Tick(float DeltaTime) override;

	// @brief Surcharge de la fonction d'Unreal Engine OnHit()
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	// @brief Mesh qui prend en charge les collisions
	UPROPERTY(EditAnywhere, Category = "Target")
	UStaticMeshComponent* MeshComponent;

	// @brief Variable qui autorise ou non le comptage de collision
	bool bCanCountCollision;
};
