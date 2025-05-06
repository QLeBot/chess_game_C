#include <stdio.h>
#include <stdlib.h>
#include "mouvements.h"
#include "pieces.h"

int **Mouvements(int **plateau, int ligne, int colonne, char Couleur, char Couleur_Joueur, int valeur)
{
    int deja_bouge;
    if (valeur<0)
    {
        if (valeur==-1)
        {
            deja_bouge = pion_deja_bouge(plateau, ligne, Couleur, Couleur_Joueur);
            Mouvements_Pion(plateau, ligne, colonne, Couleur, Couleur_Joueur, deja_bouge);
        }
        if (valeur==-2)
        {
            Mouvements_Fou(plateau, ligne, colonne, Couleur);
        }
        if (valeur==-3)
        {
            Mouvements_Cavalier(plateau, ligne, colonne, Couleur);
        }
        if (valeur==-4)
        {
            Mouvements_Tour(plateau, ligne, colonne, Couleur);
        }
        if (valeur==-5)
        {
            Mouvements_Reine(plateau, ligne, colonne, Couleur);
        }
        if (valeur==-6)
        {
            Mouvements_Roi(plateau, ligne, colonne, Couleur);
        }
    }
    if (valeur>0)
    {
        if (valeur==1)
        {
            deja_bouge = pion_deja_bouge(plateau, ligne, Couleur, Couleur_Joueur);
            Mouvements_Pion(plateau, ligne, colonne, Couleur, Couleur_Joueur, deja_bouge);
        }
        if (valeur==2)
        {
            Mouvements_Fou(plateau, ligne, colonne, Couleur);
        }
        if (valeur==3)
        {
            Mouvements_Cavalier(plateau, ligne, colonne, Couleur);
        }
        if (valeur==4)
        {
            Mouvements_Tour(plateau, ligne, colonne, Couleur);
        }
        if (valeur==5)
        {
            Mouvements_Reine(plateau, ligne, colonne, Couleur);
        }
        if (valeur==6)
        {
            Mouvements_Roi(plateau, ligne, colonne, Couleur);
        }
    }
}


//ROI
int **Mouvements_Roi(int **plateau, int ligne, int colonne, char Couleur)
{
    int i,j,k;
    int **tableau_highlighting;
    tableau_highlighting = malloc(sizeof(int *) *8);
    for(i=0;i<8;i++)
    {
        tableau_highlighting[i] = malloc(sizeof(int)*8);
    }
    for(j=0;j<8;j++)
    {
        for (k=0;k<8;k++)
        {
            tableau_highlighting[j][k]=0;
        }
    }
    if (Couleur=='B')
    {
        if ((ligne-1>=0) && (colonne-1>=0))
        {
            if (plateau[ligne-1][colonne-1]<=0)
            {
                tableau_highlighting[ligne-1][colonne-1]=1;
            }
        }
        if ((ligne-1>=0))
        {
            if (plateau[ligne-1][colonne]<=0)
            {
                tableau_highlighting[ligne-1][colonne]=1;
            }
        }
        if ((ligne-1>=0) && (colonne+1<=7))
        {
            if (plateau[ligne-1][colonne+1]<=0)
            {
                tableau_highlighting[ligne-1][colonne+1]=1;
            }
        }
        if ((colonne-1>=0))
        {
            if (plateau[ligne][colonne-1]<=0 )
            {
                tableau_highlighting[ligne][colonne-1]=1;
            }
        }
        if ((colonne+1<=7))
        {
            if (plateau[ligne][colonne+1]<=0)
            {
                tableau_highlighting[ligne][colonne+1]=1;
            }
        }
        if ((ligne+1<=7) && (colonne-1>=0))
        {
            if (plateau[ligne+1][colonne-1]<=0 )
            {
                tableau_highlighting[ligne+1][colonne-1]=1;
            }
        }
        if ((ligne+1<=7))
        {
            if (plateau[ligne+1][colonne]<=0)
            {
                tableau_highlighting[ligne+1][colonne]=1;
            }
        }
        if ((ligne+1<=7) && (colonne+1<=7))
        {
            if (plateau[ligne+1][colonne+1]<=0)
            {
                tableau_highlighting[ligne+1][colonne+1]=1;
            }
        }
    }
    if (Couleur=='N')
    {
        if ((ligne-1>=0) && (colonne-1>=0))
        {
            if (plateau[ligne-1][colonne-1]>=0 )
            {
                tableau_highlighting[ligne-1][colonne-1]=1;
            }
        }
        if ((ligne-1>=0))
        {
            if (plateau[ligne-1][colonne]>=0)
            {
                tableau_highlighting[ligne-1][colonne]=1;
            }
        }
        if ((ligne-1>=0) && (colonne+1<=7))
        {
            if (plateau[ligne-1][colonne+1]>=0)
            {
                tableau_highlighting[ligne-1][colonne+1]=1;
            }
        }
        if ((colonne-1>=0))
        {
            if (plateau[ligne][colonne-1]>=0 )
            {
                tableau_highlighting[ligne][colonne-1]=1;
            }
        }
        if ((colonne+1<=7))
        {
            if (plateau[ligne][colonne+1]>=0)
            {
                tableau_highlighting[ligne][colonne+1]=1;
            }
        }
        if ((ligne+1<=7) && (colonne-1>=0))
        {
            if (plateau[ligne+1][colonne-1]>=0 )
            {
                tableau_highlighting[ligne+1][colonne-1]=1;
            }
        }
        if ((ligne+1<=7))
        {
            if (plateau[ligne+1][colonne]>=0)
            {
                tableau_highlighting[ligne+1][colonne]=1;
            }
        }
        if ((ligne+1<=7) && (colonne+1<=7))
        {
            if (plateau[ligne+1][colonne+1]>=0)
            {
                tableau_highlighting[ligne+1][colonne+1]=1;
            }
        }
    }
    return(tableau_highlighting);
}


//REINE
int **Mouvements_Reine(int **plateau, int ligne, int colonne, char Couleur)
{
    int a;
    int i,j,k,l;

    int **tableau_highlighting;
    tableau_highlighting = malloc(sizeof(int *) *8);
    for (i=0;i<8;i++)
    {
        tableau_highlighting[i] = malloc(sizeof(int)*8);
    }
    for (j=0;j<8;j++)
    {
        for (k=0;k<8;k++)
        {
            tableau_highlighting[j][k]=0;
        }
    }

    int *tab;
    tab = malloc(sizeof(int) *8);
    for (l=0;l<8;l++)
    {
      tab[l]=0;
    }

    if (Couleur=='B')
    {
        for (a=1;a<8;a++)
        {
            if ((ligne-a>=0) && (tab[0]!=1))
            {
                if (plateau[ligne-a][colonne]<0)//case avec un NOIR dessus
                {
                    tableau_highlighting[ligne-a][colonne]=1;
                    tab[0]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne]=1;
                }
                if (plateau[ligne-a][colonne]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[0]=1;//et ne peux pas aller plus loin
                }
            }
            if ((ligne-a<=0) || (tab[0]==1))
            {
                tab[0]=1;
            }
            if ((ligne+a<=7) && (tab[1]!=1))
            {
                if (plateau[ligne+a][colonne]<0)//case avec un NOIR dessus
                {
                    tableau_highlighting[ligne+a][colonne]=1;
                    tab[1]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne]=1;
                }
                if (plateau[ligne+a][colonne]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[1]=1;//et ne peux pas aller plus loin
                }
            }
            if ((ligne+a>=7) || (tab[1]==1))
            {
                tab[1]=1;
            }
            if ((colonne-a>=0) && (tab[2]!=1))
            {
                if (plateau[ligne][colonne-a]<0)//case avec un NOIR dessus
                {
                    tableau_highlighting[ligne][colonne-a]=1;
                    tab[2]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne][colonne-a]=1;
                }
                if (plateau[ligne][colonne-a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[2]=1;//et ne peux pas aller plus loin
                }
            }
            if ((colonne-a<=0) || (tab[2]==1))
            {
                tab[2]=1;
            }
            if ((colonne+a<=7) && (tab[3]!=1))
            {
                if (plateau[ligne][colonne+a]<0)//case avec un NOIR dessus
                {
                    tableau_highlighting[ligne][colonne+a]=1;
                    tab[3]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne][colonne+a]=1;
                }
                if (plateau[ligne][colonne+a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[3]=1;//et ne peux pas aller plus loin
                }
            }
            if ((colonne+a>=7) || (tab[3]==1))
            {
                tab[3]=1;
            }
        }
        for (a=1;a<8;a++)
        {
            if ((ligne-a>=0) && (colonne-a>=0) && (tab[4]!=1))
            {
                if (plateau[ligne-a][colonne-a]<0)//case avec un NOIR ennemis dessus
                {
                    tableau_highlighting[ligne-a][colonne-a]=1;
                    tab[4]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne-a]=1;
                }
                if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[4]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[4]=1;
            }
            if ((ligne-a>=0) && (colonne+a<=7) && (tab[5]!=1))
            {
                if (plateau[ligne-a][colonne+a]<0)//case avec un NOIR ennemis dessus
                {
                    tableau_highlighting[ligne-a][colonne+a]=1;
                    tab[5]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne+a]=1;
                }
                if (plateau[ligne-a][colonne+a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[5]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[5]=1;
            }
            if ((ligne+a<=7) && (colonne-a>=0) && (tab[6]!=1))
            {
                if (plateau[ligne+a][colonne-a]<0)//case avec un NOIR ennemis dessus
                {
                    tableau_highlighting[ligne+a][colonne-a]=1;
                    tab[6]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne-a]=1;
                }
                if (plateau[ligne+a][colonne-a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[6]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[6]=1;
            }
            if ((ligne+a<=7) && (colonne+a<=7) && (tab[7]!=1))
            {
                if (plateau[ligne+a][colonne+a]<0)//case avec un NOIR ennemis dessus
                {
                    tableau_highlighting[ligne+a][colonne+a]=1;
                    tab[7]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne+a]=1;
                }
                if (plateau[ligne+a][colonne+a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[7]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[7]=1;
            }
        }
    }
    if (Couleur=='N')
    {
        for (a=1;a<8;a++)
        {
            if ((ligne-a>=0) && (tab[0]!=1))
            {
                if (plateau[ligne-a][colonne]>0)//case avec un BLANC dessus
                {
                    tableau_highlighting[ligne-a][colonne]=1;
                    tab[0]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne]=1;
                }
                if (plateau[ligne-a][colonne]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[0]=1;//et ne peux pas aller plus loin
                }
            }
            if ((ligne-a<=0) || (tab[0]==1))
            {
                tab[0]=1;
            }
            if ((ligne+a<=7) && (tab[1]!=1))
            {
                if (plateau[ligne+a][colonne]>0)//case avec un BLANC dessus
                {
                    tableau_highlighting[ligne+a][colonne]=1;
                    tab[1]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne]=1;
                }
                if (plateau[ligne+a][colonne]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[1]=1;//et ne peux pas aller plus loin
                }
            }
            if ((ligne+a>=7) || (tab[1]==1))
            {
                tab[1]=1;
            }
            if ((colonne-a>=0) && (tab[2]!=1))
            {
                if (plateau[ligne][colonne-a]>0)//case avec un BLANC dessus
                {
                    tableau_highlighting[ligne][colonne-a]=1;
                    tab[2]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne][colonne-a]=1;
                }
                if (plateau[ligne][colonne-a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[2]=1;//et ne peux pas aller plus loin
                }
            }
            if ((colonne-a<=0) || (tab[2]==1))
            {
                tab[2]=1;
            }
            if ((colonne+a<=7) && (tab[3]!=1))
            {
                if (plateau[ligne][colonne+a]>0)//case avec un BLANC dessus
                {
                    tableau_highlighting[ligne][colonne+a]=1;
                    tab[3]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne][colonne+a]=1;
                }
                if (plateau[ligne][colonne+a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[3]=1;//et ne peux pas aller plus loin
                }
            }
            if ((colonne+a>=7) || (tab[3]==1))
            {
                tab[3]=1;
            }
        }
        for (a=1;a<8;a++)
        {
            if ((ligne-a>=0) && (colonne-a>=0) && (tab[4]!=1))
            {
                if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC ennemis dessus
                {
                    tableau_highlighting[ligne-a][colonne-a]=1;
                    tab[4]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne-a]=1;
                }
                if (plateau[ligne-a][colonne-a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[4]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[4]=1;
            }
            if ((ligne-a>=0) && (colonne+a<=7) && (tab[5]!=1))
            {
                if (plateau[ligne-a][colonne+a]>0)//case avec un BLANC ennemis dessus
                {
                    tableau_highlighting[ligne-a][colonne+a]=1;
                    tab[5]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne+a]=1;
                }
                if (plateau[ligne-a][colonne+a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[5]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[5]=1;
            }
            if ((ligne+a<=7) && (colonne-a>=0) && (tab[6]!=1))
            {
                if (plateau[ligne+a][colonne-a]>0)//case avec un BLANC ennemis dessus
                {
                    tableau_highlighting[ligne+a][colonne-a]=1;
                    tab[6]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne-a]=1;
                }
                if (plateau[ligne+a][colonne-a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[6]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[6]=1;
            }
            if ((ligne+a<=7) && (colonne+a<=7) && (tab[7]!=1))
            {
                if (plateau[ligne+a][colonne+a]>0)//case avec un BLANC ennemis dessus
                {
                    tableau_highlighting[ligne+a][colonne+a]=1;
                    tab[7]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne+a]=1;
                }
                if (plateau[ligne+a][colonne+a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[7]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[7]=1;
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%d", tableau_highlighting[i][j]);
        }
        printf("\n");
    }
    return(tableau_highlighting);
}


//TOUR
int **Mouvements_Tour(int **plateau, int ligne, int colonne, char Couleur)
{
    int a;
    int i,j,k,l;

    int **tableau_highlighting;
    tableau_highlighting = malloc(sizeof(int *) *8);
    for (i=0;i<8;i++)
    {
        tableau_highlighting[i] = malloc(sizeof(int)*8);
    }
    for (j=0;j<8;j++)
    {
        for (k=0;k<8;k++)
        {
            tableau_highlighting[j][k]=0;
        }
    }

    int *tab;
    tab = malloc(sizeof(int) *4);
    for (l=0;l<4;l++)
    {
      tab[l]=0;
    }

    if (Couleur=='B')
    {
        for (a=1;a<8;a++)
        {
            if ((ligne-a>=0) && (tab[0]!=1))
            {
                if (plateau[ligne-a][colonne]<0)//case avec un NOIR dessus
                {
                    tableau_highlighting[ligne-a][colonne]=1;
                    tab[0]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne]=1;
                }
                if (plateau[ligne-a][colonne]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[0]=1;//et ne peux pas aller plus loin
                }
            }
            if ((ligne-a<=0) || (tab[0]==1))
            {
                tab[0]=1;
            }
            if ((ligne+a<=7) && (tab[1]!=1))
            {
                if (plateau[ligne+a][colonne]<0)//case avec un NOIR dessus
                {
                    tableau_highlighting[ligne+a][colonne]=1;
                    tab[1]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne]=1;
                }
                if (plateau[ligne+a][colonne]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[1]=1;//et ne peux pas aller plus loin
                }
            }
            if ((ligne+a>=7) || (tab[1]==1))
            {
                tab[1]=1;
            }
            if ((colonne-a>=0) && (tab[2]!=1))
            {
                if (plateau[ligne][colonne-a]<0)//case avec un NOIR dessus
                {
                    tableau_highlighting[ligne][colonne-a]=1;
                    tab[2]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne][colonne-a]=1;
                }
                if (plateau[ligne][colonne-a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[2]=1;//et ne peux pas aller plus loin
                }
            }
            if ((colonne-a<=0) || (tab[2]==1))
            {
                tab[2]=1;
            }
            if ((colonne+a<=7) && (tab[3]!=1))
            {
                if (plateau[ligne][colonne+a]<0)//case avec un NOIR dessus
                {
                    tableau_highlighting[ligne][colonne+a]=1;
                    tab[3]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne][colonne+a]=1;
                }
                if (plateau[ligne][colonne+a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[3]=1;//et ne peux pas aller plus loin
                }
            }
            if ((colonne+a>=7) || (tab[3]==1))
            {
                tab[3]=1;
            }
        }
    }
    if (Couleur=='N')
    {
        for (a=1;a<8;a++)
        {
            if ((ligne-a>=0) && (tab[0]!=1))
            {
                if (plateau[ligne-a][colonne]>0)//case avec un BLANC dessus
                {
                    tableau_highlighting[ligne-a][colonne]=1;
                    tab[0]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne]=1;
                }
                if (plateau[ligne-a][colonne]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[0]=1;//et ne peux pas aller plus loin
                }
            }
            if ((ligne-a<=0) || (tab[0]==1))
            {
                tab[0]=1;
            }
            if ((ligne+a>=7) && (tab[1]!=1))
            {
                if (plateau[ligne+a][colonne]>0)//case avec un BLANC dessus
                {
                    tableau_highlighting[ligne+a][colonne]=1;
                    tab[1]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne]=1;
                }
                if (plateau[ligne+a][colonne]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[1]=1;//et ne peux pas aller plus loin
                }
            }
            if ((ligne+a>=7) || (tab[1]==1))
            {
                tab[1]=1;
            }
            if ((colonne-a>=0) && (tab[2]!=1))
            {
                if (plateau[ligne][colonne-a]>0)//case avec un BLANC dessus
                {
                    tableau_highlighting[ligne][colonne-a]=1;
                    tab[2]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne][colonne-a]=1;
                }
                if (plateau[ligne][colonne-a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[2]=1;//et ne peux pas aller plus loin
                }
            }
            if ((colonne-a<=0) || (tab[2]==1))
            {
                tab[2]=1;
            }
            if ((colonne+a<=7) && (tab[3]!=1))
            {
                if (plateau[ligne][colonne+a]>0)//case avec un BLANC dessus
                {
                    tableau_highlighting[ligne][colonne+a]=1;
                    tab[3]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne][colonne+a]=1;
                }
                if (plateau[ligne][colonne+a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[3]=1;//et ne peux pas aller plus loin
                }
            }
            if ((colonne+a>=7) || (tab[3]==1))
            {
                tab[3]=1;
            }
        }
    }
    return(tableau_highlighting);
}

//CAVALIER
int **Mouvements_Cavalier(int **plateau, int ligne, int colonne, char Couleur)
{
    int i,j,k;
    int **tableau_highlighting;
    tableau_highlighting = malloc(sizeof(int *) *8);
    for (i=0;i<8;i++)
    {
        tableau_highlighting[i] = malloc(sizeof(int)*8);
    }
    for (j=0;j<8;j++)
    {
        for (k=0;k<8;k++)
        {
            tableau_highlighting[j][k]=0;
        }
    }
    if (Couleur=='B')
    {
        if ((ligne-2>=0) && (colonne-1>=0))
        {
            if (plateau[ligne-2][colonne-1]<=0)
            {
                tableau_highlighting[ligne-2][colonne-1]=1;
            }
        }
        if ((ligne-2>=0) && (colonne+1<=7))
        {
            if (plateau[ligne-2][colonne+1]<=0)
            {
                tableau_highlighting[ligne-2][colonne+1]=1;
            }
        }
        if ((ligne-1>=0) && (colonne-2>=0))
        {
            if (plateau[ligne-1][colonne-2]<=0)
            {
                tableau_highlighting[ligne-1][colonne-2]=1;
            }
        }
        if ((ligne-1>=0) && (colonne+2<=7))
        {
            if (plateau[ligne-1][colonne+2]<=0)
            {
                tableau_highlighting[ligne-1][colonne+2]=1;
            }
        }
        if ((ligne+1<=7) && (colonne-2>=0))
        {
            if (plateau[ligne+1][colonne-2]<=0)
            {
                tableau_highlighting[ligne+1][colonne-2]=1;
            }
        }
        if ((ligne+1<=7) && (colonne+2<=7))
        {
            if (plateau[ligne+1][colonne+2]<=0)
            {
                tableau_highlighting[ligne+1][colonne+2]=1;
            }
        }
        if ((ligne+2<=7) && (colonne-1>=0))
        {
            if (plateau[ligne+2][colonne-1]>0)
            {
                tableau_highlighting[ligne+2][colonne-1]=1;
            }
        }
        if ((ligne+2<=7) && (colonne+1<=7))
        {
            if (plateau[ligne+2][colonne+1]<=0)
            {
                tableau_highlighting[ligne+2][colonne+1]=1;
            }
        }
    }
    if (Couleur=='N')
    {
        if ((ligne-2>=0) && (colonne-1>=0))
        {
            if (plateau[ligne-2][colonne-1]>=0)
            {
                tableau_highlighting[ligne-2][colonne-1]=1;
            }
        }
        if ((ligne-2>=0) && (colonne+1<=7))
        {
            if (plateau[ligne-2][colonne+1]>=0)
            {
                tableau_highlighting[ligne-2][colonne+1]=1;
            }
        }
        if ((ligne-1>=0) && (colonne-2>=0))
        {
            if (plateau[ligne-1][colonne-2]>=0)
            {
                tableau_highlighting[ligne-1][colonne-2]=1;
            }
        }
        if ((ligne-1>=0) && (colonne+2<=7))
        {
            if (plateau[ligne-1][colonne+2]>=0)
            {
                tableau_highlighting[ligne-1][colonne+2]=1;
            }
        }
        if ((ligne+1<=7) && (colonne-2>=0))
        {
            if (plateau[ligne+1][colonne-2]>=0)
            {
                tableau_highlighting[ligne+1][colonne-2]=1;
            }
        }
        if ((ligne+1<=7) && (colonne+2<=7))
        {
            if (plateau[ligne+1][colonne+2]>=0)
            {
                tableau_highlighting[ligne+1][colonne+2]=1;
            }
        }
        if ((ligne+2<=7) && (colonne-1>=0))
        {
            if (plateau[ligne+2][colonne-1]>=0)
            {
                tableau_highlighting[ligne+2][colonne-1]=1;
            }
        }
        if ((ligne+2<=7) && (colonne+1<=7))
        {
            if (plateau[ligne+2][colonne+1]>=0)
            {
                tableau_highlighting[ligne+2][colonne+1]=1;
            }
        }
    }
    return(tableau_highlighting);
}


//FOU
int **Mouvements_Fou(int **plateau, int ligne, int colonne, char Couleur)
{
    int a;
    int i,j,k,l;
    int **tableau_highlighting;
    tableau_highlighting = malloc(sizeof(int *) *8);
    for (i=0;i<8;i++)
    {
        tableau_highlighting[i] = malloc(sizeof(int)*8);
    }
    for (j=0;j<8;j++)
    {
        for (k=0;k<8;k++)
        {
            tableau_highlighting[j][k]=0;
        }
    }

    int *tab;
    tab = malloc(sizeof(int *) *4);
    for (l=0;l<4;l++)
    {
      tab[l]=0;
    }
    if (Couleur=='B')
    {
        for (a=1;a<8;a++)
        {
            if ((ligne-a>=0) && (colonne-a>=0) && (tab[0]!=1))
            {
                if (plateau[ligne-a][colonne-a]<0)//case avec un NOIR ennemis dessus
                {
                    tableau_highlighting[ligne-a][colonne-a]=1;
                    tab[0]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne-a]=1;
                }
                if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[0]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[0]=1;
            }
            if ((ligne-a>=0) && (colonne+a<=7) && (tab[1]!=1))
            {
                if (plateau[ligne-a][colonne+a]<0)//case avec un NOIR ennemis dessus
                {
                    tableau_highlighting[ligne-a][colonne+a]=1;
                    tab[1]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne+a]=1;
                }
                if (plateau[ligne-a][colonne+a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[1]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[1]=1;
            }
            if ((ligne+a<=7) && (colonne-a>=0) && (tab[2]!=1))
            {
                if (plateau[ligne+a][colonne-a]<0)//case avec un NOIR ennemis dessus
                {
                    tableau_highlighting[ligne+a][colonne-a]=1;
                    tab[2]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne-a]=1;
                }
                if (plateau[ligne+a][colonne-a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[2]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[2]=1;
            }
            if ((ligne+a<=7) && (colonne+a<=7) && (tab[3]!=1))
            {
                if (plateau[ligne+a][colonne+a]<0)//case avec un NOIR ennemis dessus
                {
                    tableau_highlighting[ligne+a][colonne+a]=1;
                    tab[3]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne+a]=1;
                }
                if (plateau[ligne+a][colonne+a]>0)//case avec un BLANC dessus = ne peux pas y aller
                {
                    tab[3]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[3]=1;
            }
        }
    }
    if (Couleur=='N')
    {
        for (a=1;a<8;a++)
        {
            if ((ligne-a>=0) && (colonne-a>=0) && (tab[0]!=1))
            {
                if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC ennemis dessus
                {
                    tableau_highlighting[ligne-a][colonne-a]=1;
                    tab[0]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne-a]=1;
                }
                if (plateau[ligne-a][colonne-a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[0]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[0]=1;
            }
            if ((ligne-a>=0) && (colonne+a<=7) && (tab[1]!=1))
            {
                if (plateau[ligne-a][colonne+a]>0)//case avec un BLANC ennemis dessus
                {
                    tableau_highlighting[ligne-a][colonne+a]=1;
                    tab[1]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne-a][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne-a][colonne+a]=1;
                }
                if (plateau[ligne-a][colonne+a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[1]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[1]=1;
            }
            if ((ligne+a<=7) && (colonne-a>=0) && (tab[2]!=1))
            {
                if (plateau[ligne+a][colonne-a]>0)//case avec un BLANC ennemis dessus
                {
                    tableau_highlighting[ligne+a][colonne-a]=1;
                    tab[2]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne-a]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne-a]=1;
                }
                if (plateau[ligne+a][colonne-a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[2]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[2]=1;
            }
            if ((ligne+a<=7) && (colonne+a<=7) && (tab[3]!=1))
            {
                if (plateau[ligne+a][colonne+a]>0)//case avec un BLANC ennemis dessus
                {
                    tableau_highlighting[ligne+a][colonne+a]=1;
                    tab[3]=1;//et donc ne peux pas aller plus loin
                }
                if (plateau[ligne+a][colonne+a]==0)//case vide
                {
                    tableau_highlighting[ligne+a][colonne+a]=1;
                }
                if (plateau[ligne+a][colonne+a]<0)//case avec un NOIR dessus = ne peux pas y aller
                {
                    tab[3]=1;//et ne peux pas aller plus loin
                }
            }
            else
            {
                tab[3]=1;
            }
        }
    }
    return(tableau_highlighting);
}


//PION
int **Mouvements_Pion(int **plateau, int ligne, int colonne, char Couleur, char Couleur_Joueur, int Deja_Bouge)
{
    int i,j,k;
    int **tableau_highlighting;
    tableau_highlighting = malloc(sizeof(int *) *8);
    for (i=0;i<8;i++)
    {
        tableau_highlighting[i] = malloc(sizeof(int)*8);
    }
    for (j=0;j<8;j++)
    {
        for (k=0;k<8;k++)
        {
            tableau_highlighting[j][k]=0;
        }
    }

    if (Couleur==Couleur_Joueur)
    {
        if (Couleur=='B')
        {
            if (Deja_Bouge==0)//le pion n'a pas bougé
            {
                if ((ligne-2>=0))
                {
                    if (plateau[ligne-2][colonne]==0)
                    {
                        tableau_highlighting[ligne-2][colonne]=1;
                    }
                }
                if ((ligne-1>=0))
                {
                    if (plateau[ligne-1][colonne]==0)
                    {
                        tableau_highlighting[ligne-1][colonne]=1;
                    }
                }
                if ((ligne-1>=0) && (colonne-1>=0))
                {
                    if (plateau[ligne-1][colonne-1]<0)
                    {
                        tableau_highlighting[ligne-1][colonne-1]=1;
                    }
                }
                if ((ligne-1>=0) && (colonne+1<=7))
                {
                    if (plateau[ligne-1][colonne+1]<0)
                    {
                        tableau_highlighting[ligne-1][colonne+1]=1;
                    }
                }
            }
            if (Deja_Bouge==1)//le pion A DEJA bougé
            {
                if ((ligne-1>=0))
                {
                    if (plateau[ligne-1][colonne]==0)
                    {
                        tableau_highlighting[ligne-1][colonne]=1;
                    }
                }
                if ((ligne-1>=0) && (colonne-1>=0))
                {
                    if (plateau[ligne-1][colonne-1]<0)
                    {
                        tableau_highlighting[ligne-1][colonne-1]=1;
                    }
                }
                if ((ligne-1>=0) && (colonne+1<=7))
                {
                    if (plateau[ligne-1][colonne+1]<0)
                    {
                        tableau_highlighting[ligne-1][colonne+1]=1;
                    }
                }
            }
        }
        if (Couleur=='N')
        {
            if (Deja_Bouge==0)//le pion n'a pas bougé
            {
                if ((ligne-2>=0))
                {
                    if (plateau[ligne-2][colonne]==0)
                    {
                        tableau_highlighting[ligne-2][colonne]=1;
                    }
                }
                if ((ligne-1>=0))
                {
                    if (plateau[ligne-1][colonne]==0)
                    {
                        tableau_highlighting[ligne-1][colonne]=1;
                    }
                }
                if ((ligne-1>=0) && (colonne-1>=0))
                {
                    if (plateau[ligne-1][colonne-1]>0)
                    {
                        tableau_highlighting[ligne-1][colonne-1]=1;
                    }
                }
                if ((ligne-1>=0) && (colonne+1<=7))
                {
                    if (plateau[ligne-1][colonne+1]>0)
                    {
                        tableau_highlighting[ligne-1][colonne+1]=1;
                    }
                }
            }
            if (Deja_Bouge==1)//le pion A DEJA bougé
            {
                if ((ligne-1>=0))
                {
                    if (plateau[ligne-1][colonne]==0)
                    {
                        tableau_highlighting[ligne-1][colonne]=1;
                    }
                }
                if ((ligne-1>=0) && (colonne-1>=0))
                {
                    if (plateau[ligne-1][colonne-1]>0)
                    {
                        tableau_highlighting[ligne-1][colonne-1]=1;
                    }
                }
                if ((ligne-1>=0) && (colonne+1<=7))
                {
                    if (plateau[ligne-1][colonne+1]>0)
                    {
                        tableau_highlighting[ligne-1][colonne+1]=1;
                    }
                }
            }
        }
    }
    if (Couleur!=Couleur_Joueur)
    {
        if (Couleur=='N')
        {
            if (Deja_Bouge==0)//le pion n'a pas bougé
            {
                if ((ligne+2<=7))
                {
                    if (plateau[ligne+2][colonne]==0)
                    {
                        tableau_highlighting[ligne+2][colonne]=1;
                    }
                }
                if ((ligne+1<=7))
                {
                    if (plateau[ligne+1][colonne]==0)
                    {
                        tableau_highlighting[ligne+1][colonne]=1;
                    }
                }
                if ((ligne+1<=7) && (colonne-1>=0))
                {
                    if (plateau[ligne+1][colonne-1]>0)
                    {
                        tableau_highlighting[ligne+1][colonne-1]=1;
                    }
                }
                if ((ligne+1<=7) && (colonne+1<=7))
                {
                    if (plateau[ligne+1][colonne+1]>0)
                    {
                        tableau_highlighting[ligne+1][colonne+1]=1;
                    }
                }
            }
            if (Deja_Bouge==1)//le pion A DEJA bougé
            {
                if ((ligne+1<=7))
                {
                    if (plateau[ligne+1][colonne]==0)
                    {
                        tableau_highlighting[ligne+1][colonne]=1;
                    }
                }
                if ((ligne+1<=7) && (colonne-1>=0))
                {
                    if (plateau[ligne+1][colonne-1]>0)
                    {
                        tableau_highlighting[ligne+1][colonne-1]=1;
                    }
                }
                if ((ligne+1<=7) && (colonne+1<=7))
                {
                    if (plateau[ligne+1][colonne+1]>0)
                    {
                        tableau_highlighting[ligne+1][colonne+1]=1;
                    }
                }
            }
        }
        if (Couleur=='B')
        {
            if (Deja_Bouge==0)//le pion n'a pas bougé
            {
                if ((ligne+2<=7))
                {
                    if (plateau[ligne+2][colonne]==0)
                    {
                        tableau_highlighting[ligne+2][colonne]=1;
                    }
                }
                if ((ligne+1<=7))
                {
                    if (plateau[ligne+1][colonne]==0)
                    {
                        tableau_highlighting[ligne+1][colonne]=1;
                    }
                }
                if ((ligne+1<=7) && (colonne-1>=0))
                {
                    if (plateau[ligne+1][colonne-1]<0)
                    {
                        tableau_highlighting[ligne+1][colonne-1]=1;
                    }
                }
                if ((ligne+1<=7) && (colonne+1<=7))
                {
                    if (plateau[ligne+1][colonne+1]<0)
                    {
                        tableau_highlighting[ligne+1][colonne+1]=1;
                    }
                }
            }
            if (Deja_Bouge==1)//le pion A DEJA bougé
            {
                if ((ligne+1<=7))
                {
                    if (plateau[ligne+1][colonne]==0)
                    {
                        tableau_highlighting[ligne+1][colonne]=1;
                    }
                }
                if ((ligne+1<=7) && (colonne-1>=0))
                {
                    if (plateau[ligne+1][colonne-1]<0)
                    {
                        tableau_highlighting[ligne+1][colonne-1]=1;
                    }
                }
                if ((ligne+1<=7) && (colonne+1<=7))
                {
                    if (plateau[ligne+1][colonne+1]<0)
                    {
                        tableau_highlighting[ligne+1][colonne+1]=1;
                    }
                }
            }
        }
    }
    return(tableau_highlighting);
}
