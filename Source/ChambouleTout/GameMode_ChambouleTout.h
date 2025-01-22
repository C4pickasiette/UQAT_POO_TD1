#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode_ChambouleTout.generated.h"

/**
 * @brief Classe de mode de jeu pour gérer les états du jeu et suivre les scores dans le jeu ChambouleTout.
 * Gère la logique au niveau du jeu telle que le score et la gestion des niveaux.
 */
UCLASS()
class CHAMBOULETOUT_API AGameMode_ChambouleTout : public AGameModeBase
{
	GENERATED_BODY()

// Declaration des methodes public
public:
	// @brief Constructeur de la class AGameMode_ChambouleTout
	AGameMode_ChambouleTout();

	// @brief Recharge le niveau en cours
	// @param Precisez le contexte du niveau (this)
	static void reloadLevel(UObject* WorldContextObject);

	// @brief Augmente le score general de 1
	static void increaseScore();

	// @brief Reinitialise le score a 0
	static void resetScore();

	// @brief Affiche le score a l'ecran
	static void logScore();

	// @brief Compteur global pour toutes les collisions (Score)
	static int TotalCollisionCount;  
};