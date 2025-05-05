#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include <stdbool.h>

#include "interface.h"
#include "mouvements.h"
#include "pieces.h"
#include "IA.h"

int nombre_random(int max)
{
    static int rand_is_seeded = 0;
    if(!rand_is_seeded)
    {
        srand(time(NULL));
        rand_is_seeded = 1;
    }
    return rand()%(max);
}

int **IA_blanc(int **plateau)
{
    int num_hasard;
    int ligne;
    int colonne;
    int valeur;
    int deja_bouge;

    int *depart_IA;
    depart_IA = malloc(sizeof(int) * 4);

    int *tableau_pieces_valeurs = NULL;
    tableau_pieces_valeurs = malloc(sizeof(int) * 16);

    int *tableau_pieces_lignes = NULL;
    tableau_pieces_lignes = malloc(sizeof(int) * 8);

    int *tableau_pieces_colonnes = NULL;
    tableau_pieces_colonnes = malloc(sizeof(int) * 2);

    int taille_tableau_pieces = 0;

    int **tableau;
    tableau = malloc(sizeof(int *) *8);
    for(int i=0; i<8; i++)
    {
        tableau[i] = malloc(sizeof(int)*8);
    }

    for(int o=0; o < 16; o++)
    {
        for(int i=0; i < 8; i++)
        {
            for(int j=0; j < 8; j++)
            {
                if(plateau[i][j]>0)
                {
                    taille_tableau_pieces++;
                    tableau_pieces_lignes[o] = i;
                    tableau_pieces_colonnes[o] = j;
                    tableau_pieces_valeurs[o] = plateau[i][j];
                }
            }
        }
    }

    num_hasard = (rand() % (taille_tableau_pieces));

    ligne = tableau_pieces_lignes[num_hasard];
    colonne = tableau_pieces_colonnes[num_hasard];
    valeur = tableau_pieces_valeurs[num_hasard];

    depart_IA[0]=valeur;
    depart_IA[1]=ligne;
    depart_IA[2]=colonne;

    if (valeur==1)
    {
        deja_bouge = pion_deja_bouge(plateau, ligne, 'B', 'N');
        tableau = Mouvements_Pion(plateau, ligne, colonne, 'B', 'N', deja_bouge);
    }
    if (valeur==2)
    {
        tableau = Mouvements_Fou(plateau, ligne, colonne, 'B');
    }
    if (valeur==3)
    {
        tableau = Mouvements_Cavalier(plateau, ligne, colonne, 'B');
    }
    if (valeur==4)
    {
        tableau = Mouvements_Tour(plateau, ligne, colonne, 'B');
    }
    if (valeur==5)
    {
        tableau = Mouvements_Reine(plateau, ligne, colonne, 'B');
    }
    if (valeur==6)
    {
        tableau = Mouvements_Roi(plateau, ligne, colonne, 'B');
    }
    depart_IA[3]=tableau;
    return depart_IA;
}


int **IA_noir(int **plateau)
{
    int num_hasard;
    int ligne;
    int colonne;
    int valeur;
    int deja_bouge;

    int *depart_IA;
    depart_IA = malloc(sizeof(int) * 4);


    int *tableau_pieces_valeurs;
    tableau_pieces_valeurs = malloc(sizeof(int) * 16);
    for (int i=0;i<16;i++)
    {
        tableau_pieces_valeurs[i] = 0;
    }

    int *tableau_pieces_lignes;
    tableau_pieces_lignes = malloc(sizeof(int) * 8);
    for (int i=0;i<8;i++)
    {
        tableau_pieces_lignes[i] = 0;
    }

    int *tableau_pieces_colonnes;
    tableau_pieces_colonnes = malloc(sizeof(int) * 8);
    for (int i=0;i<8;i++)
    {
        tableau_pieces_colonnes[i] = 0;
    }

    int **tableau;
    tableau = malloc(sizeof(int *) *8);
    for(int i=0; i<8; i++)
    {
        tableau[i] = malloc(sizeof(int)*8);
    }

    int taille_tableau_pieces = 0;


    for(int i=0; i < 8; i++)
    {
        for(int j=0; j < 8; j++)
        {
            if(plateau[i][j] < 0)
            {
                //printf("%d\n", o);
                taille_tableau_pieces++;
                tableau_pieces_lignes[taille_tableau_pieces] = i;
                //printf("%d\n",tableau_pieces_lignes[o]);
                tableau_pieces_colonnes[taille_tableau_pieces] = j;
                //printf("%d\n",tableau_pieces_colonnes[o]);
                tableau_pieces_valeurs[taille_tableau_pieces] = plateau[i][j];
                //printf("%d\n",tableau_pieces_valeurs[o]);
            }
        }
    }

    //printf("%i\n",taille_tableau_pieces);
    num_hasard = nombre_random(taille_tableau_pieces);
    //printf("%i\n", num_hasard);

    ligne = tableau_pieces_lignes[num_hasard];
    colonne = tableau_pieces_colonnes[num_hasard];
    valeur = tableau_pieces_valeurs[num_hasard];

    depart_IA[0] = valeur;
    depart_IA[1] = ligne;
    depart_IA[2] = colonne;


    if (valeur==-1)
    {
        deja_bouge = pion_deja_bouge(plateau, ligne, 'N', 'B');
        tableau = Mouvements_Pion(plateau, ligne, colonne, 'N', 'B', deja_bouge);
    }
    if (valeur==-2)
    {
        tableau = Mouvements_Fou(plateau, ligne, colonne, 'N');
    }
    if (valeur==-3)
    {
        tableau = Mouvements_Cavalier(plateau, ligne, colonne, 'N');
    }
    if (valeur==-4)
    {
        tableau = Mouvements_Tour(plateau, ligne, colonne, 'N');
    }
    if (valeur==-5)
    {
        tableau = Mouvements_Reine(plateau, ligne, colonne, 'N');
    }
    if (valeur==-6)
    {
        tableau = Mouvements_Roi(plateau, ligne, colonne, 'N');
    }
    depart_IA[3] = tableau;
    return depart_IA;
}

