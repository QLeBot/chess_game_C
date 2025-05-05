#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "initialisation.h"


void initialisation_blanc(int **plateau)
{
    int a, b;
    /*
    int **plateau;
    plateau = malloc(sizeof(int *) *8);
    for(int i=0; i<8; i++)
    {
        plateau[i] = malloc(sizeof(int)*8);
    }
    */
    for (a=0;a<8;a++)
    {
        for (b=0;b<8;b++)
        {
            plateau[a][b]=0;//Remise à zero de l'echiquier
            //printf(plateau[a][b]);
        }
    }

        for (b=0;b<8;b++)
        {
            plateau[1][b]=-1;//Pions noirs
            plateau[6][b]=1;//Pions blancs
        }

        plateau[0][0]=-4;//Tour noir
        plateau[0][7]=-4;//Tour noir
        plateau[0][1]=-3;//Cavalier noir
        plateau[0][6]=-3;//Cavalier noir
        plateau[0][2]=-2;//Fou noir
        plateau[0][5]=-2;//Fou noir
        plateau[0][3]=-5;//Dame noir
        plateau[0][4]=-6;//Roi noir
        plateau[7][0]=4;//Tour blanche
        plateau[7][7]=4;//Tour blanche
        plateau[7][1]=3;//Cavalier blanc
        plateau[7][6]=3;//Cavalier blanc
        plateau[7][2]=2;//Fou blanc
        plateau[7][5]=2;//Fou blanc
        plateau[7][3]=5;//Dame blanc
        plateau[7][4]=6;//Roi blanc

        //plateau[4][4]=4; //test

        //return(plateau);
        //printf(plateau[0][0]);
}

void initialisation_noir(int **plateau)
{
    int a, b;
        for (a=0;a<8;a++)
        {
            for (b=0;b<8;b++)
            {
                plateau[a][b]=0;//Remise à zero de l'echiquier
            }
        }

        for (b=0;b<8;b++)
        {
            plateau[1][b]=1;//Pions blancs
            plateau[6][b]=-1;//Pions noirs
        }

        plateau[0][0]=4;//Tour blanche
        plateau[0][7]=4;//Tour blanche
        plateau[0][1]=3;//Cavalier blanc
        plateau[0][6]=3;//Cavalier blanc
        plateau[0][2]=2;//Fou blanc
        plateau[0][5]=2;//Fou blanc
        plateau[0][3]=5;//Dame blanc
        plateau[0][4]=6;//Roi blanc
        plateau[7][0]=-4;//Tour noir
        plateau[7][7]=-4;//Tour noir
        plateau[7][1]=-3;//Cavalier noir
        plateau[7][6]=-3;//Cavalier noir
        plateau[7][2]=-2;//Fou noir
        plateau[7][5]=-2;//Fou noir
        plateau[7][3]=-5;//Dame noir
        plateau[7][4]=-6;//Roi noir
}

