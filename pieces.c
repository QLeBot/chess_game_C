#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include <stdbool.h>

int pion_deja_bouge(int **plateau, int ligne, char Couleur, char Couleur_Joueur)
{
    if (Couleur!=Couleur_Joueur)
    {
        if (ligne==1)
        {
            return(0);
        }
        return(1);
    }
    if (Couleur==Couleur_Joueur)
    {
        if (ligne==6)
        {
            return(0);
        }
        return(1);
    }
}
