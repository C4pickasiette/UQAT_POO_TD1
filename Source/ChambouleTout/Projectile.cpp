// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Création et configuration du Mesh Component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	// Appel de la fonction parent de BeginPlay
	Super::BeginPlay();

	// Appel de la fonction Impulse
	Impulse();
}

void AProjectile::Impulse()
{
	// Initalisation du vecteur d'impulsion
	FVector impulse = GetActorForwardVector() * 1000000;
	// Appel de la fonction AddImpulse du MeshComponent
	MeshComponent->AddImpulse(impulse);
}

void AProjectile::Tick(float DeltaTime)
{
	// Appel de la fonction parent de BeginPlay
	Super::Tick(DeltaTime);
}

