#include "GameMode_ChambouleTout.h"
#include "PawnLauncher.h"
#include "Target.h"
#include "Kismet/GameplayStatics.h"

int AGameMode_ChambouleTout::TotalCollisionCount = 0;

AGameMode_ChambouleTout::AGameMode_ChambouleTout()
{
}

void AGameMode_ChambouleTout::reloadLevel(UObject* WorldContextObject)
{
    // Obtention du nom du niveau actuel
    FString LevelName = UGameplayStatics::GetCurrentLevelName(WorldContextObject, true);

    // Rechargement du niveau
    UGameplayStatics::OpenLevel(WorldContextObject, FName(*LevelName));

    // Appel de la methode ResetScore() lorsque l'on recharge le niveau
    resetScore();
}

void AGameMode_ChambouleTout::resetScore()
{
    // Initialisation de la variable TotalCollisionCount a 0
    TotalCollisionCount = 0;
    // Affichage du score mis a jour
    logScore();
}

void AGameMode_ChambouleTout::increaseScore()
{
    // Incrementation de 1 de de la variable TotalCollisionCount
    TotalCollisionCount++;
    // Affichage du score mis a jour
    logScore();
}

void AGameMode_ChambouleTout::logScore()
{
    // Definition du message comprenant le score
    FString Message = FString::Printf(TEXT("SCORE : %d"), TotalCollisionCount);
    // Affichage du message sur l'ecran de jeux
    GEngine->AddOnScreenDebugMessage(2, 100.0f, FColor::Black, Message);
}