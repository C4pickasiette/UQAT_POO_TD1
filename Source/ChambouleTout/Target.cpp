#include "Target.h"
#include "GameMode_ChambouleTout.h"
#include "Engine/Engine.h"


ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Création et configuration du Mesh Component
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    // Activation de la simulation physique
    MeshComponent->SetSimulatePhysics(true);
    // Activation des collisions
    MeshComponent->SetNotifyRigidBodyCollision(true);

    // Attachement du gestionnaire de collision a la methode OnHit()
    MeshComponent->OnComponentHit.AddDynamic(this, &ATarget::OnHit);
}

void ATarget::BeginPlay()
{
    // Appel de la fonction parent de BeginPlay
	Super::BeginPlay();

    // Appel de setupTarget pour initialiser l'objet
    setupTarget();
}

// Method Appele a chaque frame
void ATarget::Tick(float DeltaTime)
{
    // Appel de la fonction parent de Tick
	Super::Tick(DeltaTime);

}

void ATarget::setupTarget()
{
    // Assignation de false a la variable bCanCountCollision
    bCanCountCollision = false;

    // Initialisation d'un timer, et appel de ATarget::enableCollisionCount dans 2 secondes
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATarget::enableCollisionCount, 2.0f, true);
}

void ATarget::enableCollisionCount()
{
    // Assignation de true a la variable bCanCountCollision
    bCanCountCollision = true;
}

void ATarget::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // Verification de la puissance d'impact et de la valeur de bCanCountCollision
    if (NormalImpulse.Length() > 2000 && bCanCountCollision)
    {
        // Appel de AGameMode_ChambouleTout::increaseScore pour augmenter le score
        AGameMode_ChambouleTout::increaseScore();
    }
}

