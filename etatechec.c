#include <stdio.h>
#include <stdlib.h>
#include "mouvements.h"
#include "etatechec.h"


//ECHEC ?
int Etat_Echec(int **plateau, int ligne, int colonne, char Couleur, char Couleur_Joueur)
{
    int a;
    int *tab;
    tab = malloc(sizeof(int *) *8);
    for (int l=0;l<8;l++)
    {
        tab[l]=0;
    }

    if (Couleur='B')
    {
        for (a=1;a<7;a++)
        {
            if ((ligne-a>=0) && (tab[0]!=1))
            {
                if (plateau[ligne-a][colonne]==-5 || plateau[ligne-a][colonne]==-4)//case avec une reine NOIRE ou une tour NOIRE dessus
                {
                    return(1);
                    tab[0]=1;
                }
                if (plateau[ligne-a][colonne]==-3 || plateau[ligne-a][colonne]==-2 || plateau[ligne-a][colonne]==-1)//case avec une PIECE NOIRE autre que tour et reine
                {
                    tab[0]=1;
                }
                if (plateau[ligne-a][colonne]>0)//case avec un BLANC dessus = protégé
                {
                    tab[0]=1;
                }
            }
            if ((ligne+a>=7) && (tab[1]!=1))
            {
                if (plateau[ligne+a][colonne]==-5 || plateau[ligne+a][colonne]==-4)//case avec une reine NOIRE ou une tour NOIRE dessus
                {
                    return(1);
                    tab[1]=1;
                }
                if (plateau[ligne+a][colonne]==-3 || plateau[ligne+a][colonne]==-2 || plateau[ligne+a][colonne]==-1)//case avec une PIECE NOIRE autre que tour et reine
                {
                    tab[1]=1;
                }
                if (plateau[ligne+a][colonne]>0)//case avec un BLANC dessus = protégé
                {
                    tab[1]=1;
                }
            }
            if ((colonne-a>=0) && (tab[2]!=1))
            {
                if (plateau[ligne][colonne-a]==-5 || plateau[ligne][colonne-a]==-4)//case avec une reine NOIRE ou une tour NOIRE dessus
                {
                    return(1);
                    tab[2]=1;
                }
                if (plateau[ligne][colonne-a]==-3 || plateau[ligne][colonne-a]==-2 || plateau[ligne][colonne-a]==-1)//case avec une PIECE NOIRE autre que tour et reine
                {
                    tab[2]=1;
                }
                if (plateau[ligne][colonne-a]>0)//case avec un BLANC dessus = protégé
                {
                    tab[2]=1;
                }
            }
            if ((colonne+a<=7) && (tab[3]!=1))
            {
                if (plateau[ligne][colonne+a]==-5 || plateau[ligne][colonne+a]==-4)//case avec une reine NOIRE ou une tour NOIRE dessus
                {
                    return(1);
                    tab[3]=1;
                }
                if (plateau[ligne][colonne+a]==-3 || plateau[ligne][colonne+a]==-2 || plateau[ligne][colonne+a]==-1)//case avec une PIECE NOIRE autre que tour et reine
                {
                    tab[3]=1;
                }
                if (plateau[ligne][colonne+a]>0)//case avec un BLANC dessus = protégé
                {
                    tab[3]=1;
                }
            }
        }
        for (a=1;a<7;a++)
        {
            if (a==1)
            {
                if (Couleur_Joueur==Couleur)
                {
                    if ((ligne-a>=0) && (colonne-a>=0))
                    {
                        if (plateau[ligne-a][colonne-a]==-5 || plateau[ligne-a][colonne-a]==-2 || plateau[ligne-a][colonne-a]==-1)//case avec une reine NOIRE ou un fou NOIRE dessus
                        {
                            return(1);
                            tab[4]=1;
                        }
                        if (plateau[ligne-a][colonne-a]==-4 || plateau[ligne-a][colonne-a]==-3)//case avec une PIECE NOIRE autre que fou, pion et reine
                        {
                            tab[4]=1;
                        }
                        if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC dessus = protégé
                        {
                            tab[4]=1;
                        }
                    }
                    else
                    {
                        tab[4]=1;
                    }
                    if ((ligne-a>=0) && (colonne+a<=7))
                    {
                        if (plateau[ligne-a][colonne+a]==-5 || plateau[ligne-a][colonne+a]==-2 || plateau[ligne-a][colonne+a]==-1)//case avec une reine NOIRE ou un fou NOIRE dessus
                        {
                            return(1);
                            tab[5]=1;
                        }
                        if (plateau[ligne-a][colonne+a]==-4 || plateau[ligne-a][colonne+a]==-3)//case avec une PIECE NOIRE autre que fou, pion et reine
                        {
                            tab[5]=1;
                        }
                        if (plateau[ligne-a][colonne+a]>0)//case avec un BLANC dessus = protégé
                        {
                            tab[5]=1;
                        }
                    }
                    else
                    {
                        tab[5]=1;
                    }
                }
                if (Couleur_Joueur!=Couleur)
                {
                    if ((ligne-a>=0) && (colonne-a>=0))
                    {
                        if (plateau[ligne-a][colonne-a]==-5 || plateau[ligne-a][colonne-a]==-2)//case avec une reine NOIRE ou un fou NOIRE dessus
                        {
                            return(1);
                            tab[4]=1;
                        }
                        if (plateau[ligne-a][colonne-a]==-4 || plateau[ligne-a][colonne-a]==-3)//case avec une PIECE NOIRE autre que fou, pion et reine
                        {
                            tab[4]=1;
                        }
                        if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC dessus = protégé
                        {
                            tab[4]=1;
                        }
                    }
                    else
                    {
                        tab[4]=1;
                    }
                    if ((ligne-a>=0) && (colonne+a<=7))
                    {
                        if (plateau[ligne-a][colonne+a]==-5 || plateau[ligne-a][colonne+a]==-2)//case avec une reine NOIRE ou un fou NOIRE dessus
                        {
                            return(1);
                            tab[5]=1;
                        }
                        if (plateau[ligne-a][colonne+a]>0)//case avec un BLANC dessus = protégé
                        {
                            tab[5]=1;
                        }
                        if (plateau[ligne-a][colonne+a]==-4 || plateau[ligne-a][colonne+a]==-3)//case avec une PIECE NOIRE autre que fou, pion et reine
                        {
                            tab[5]=1;
                        }
                    }
                    else
                    {
                        tab[5]=1;
                    }
                    if ((ligne+a<=7) && (colonne-a>=0))
                    {
                        if (plateau[ligne+a][colonne-a]==-1)//case avec un pion NOIR
                        {
                            return(1);
                            tab[6]=1;
                        }
                    }
                    else
                    {
                        tab[6]=1;
                    }
                    if ((ligne+a<=7) && (colonne+a<=7))
                    {
                        if (plateau[ligne+a][colonne+a]==-1)//case avec un pion NOIR
                        {
                            return(1);
                            tab[7]=1;
                        }
                    }
                    else
                    {
                        tab[7]=1;
                    }
                }
            }
            if(a!=1)
            {
                if ((ligne-a>=0) && (colonne-a>=0) && (tab[4]!=1))
                {
                    if (plateau[ligne-a][colonne-a]==-5 || plateau[ligne-a][colonne-a]==-2)//case avec une reine NOIRE ou un fou NOIRE dessus
                    {
                        return(1);
                        tab[4]=1;
                    }
                    if (plateau[ligne-a][colonne-a]==-4 || plateau[ligne-a][colonne-a]==-3 || plateau[ligne-a][colonne-a]==-1)//case avec une PIECE NOIRE autre que fou et reine
                    {
                        tab[4]=1;
                    }
                    if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC dessus = protégé
                    {
                        tab[4]=1;
                    }
                }
                else
                {
                    tab[4]=1;
                }
                if ((ligne-a>=0) && (colonne+a<=7) && (tab[5]!=1))
                {
                    if (plateau[ligne-a][colonne+a]==-5 || plateau[ligne-a][colonne+a]==-2)//case avec une reine NOIRE ou un fou NOIRE dessus
                    {
                        return(1);
                        tab[5]=1;
                    }
                    if (plateau[ligne-a][colonne+a]==-4 || plateau[ligne-a][colonne+a]==-3 || plateau[ligne-a][colonne+a]==-1)//case avec une PIECE NOIRE autre que fou et reine
                    {
                        tab[5]=1;
                    }
                    if (plateau[ligne-a][colonne+a]>0)//case avec un BLANC dessus = protégé
                    {
                        tab[5]=1;
                    }
                }
                else
                {
                    tab[5]=1;
                }
                if ((ligne+a<=7) && (colonne-a>=0) && (tab[6]!=1))
                {
                    if (plateau[ligne+a][colonne-a]==-5 || plateau[ligne+a][colonne-a]==-2)//case avec une reine NOIRE ou un fou NOIRE dessus
                    {
                        return(1);
                        tab[6]=1;
                    }
                    if (plateau[ligne+a][colonne-a]==-4 || plateau[ligne+a][colonne-a]==-3 || plateau[ligne+a][colonne-a]==-1)//case avec une PIECE NOIRE autre que fou et reine
                    {
                        tab[6]=1;
                    }
                    if (plateau[ligne+a][colonne-a]>0)//case avec un BLANC dessus = protégé
                    {
                        tab[6]=1;
                    }
                }
                else
                {
                    tab[6]=1;
                }
                if ((ligne+a<=7) && (colonne+a<=7) && (tab[7]!=1))
                {
                    if (plateau[ligne+a][colonne+a]==-5 || plateau[ligne+a][colonne+a]==-2)//case avec une reine NOIRE ou un fou NOIRE dessus
                    {
                        return(1);
                        tab[7]=1;
                    }
                    if (plateau[ligne+a][colonne+a]==-4 || plateau[ligne+a][colonne+a]==-3 || plateau[ligne+a][colonne+a]==-1)//case avec une PIECE NOIRE autre que fou et reine
                    {
                        tab[7]=1;
                    }
                    if (plateau[ligne+a][colonne+a]>0)//case avec un BLANC dessus = protégé
                    {
                        tab[7]=1;
                    }
                }

                else
                {
                    tab[7]=1;
                }
            }
        }
        if ((ligne-2>=0) && (colonne-1>=0))
        {
            if (plateau[ligne-2][colonne-1]==-3)
            {
                return(1);
            }
        }
        if ((ligne-2>=0) && (colonne+1<=7))
        {
            if (plateau[ligne-2][colonne+1]==-3)
            {
                return(1);
            }
        }
        if ((ligne-1>=0) && (colonne-2>=0))
        {
            if (plateau[ligne-1][colonne-2]==-3)
            {
                return(1);
            }
        }
        if ((ligne-1>=0) && (colonne+2<=7))
        {
            if (plateau[ligne-1][colonne+2]==-3)
            {
                return(1);
            }
        }
        if ((ligne+1<=7) && (colonne-2>=0))
        {
            if (plateau[ligne+1][colonne-2]==-3)
            {
                return(1);
            }
        }
        if ((ligne+1<=7) && (colonne+2<=7))
        {
            if (plateau[ligne+1][colonne+2]==-3)
            {
                return(1);
            }
        }
        if ((ligne+2<=7) && (colonne-1>=0))
        {
            if (plateau[ligne+2][colonne-1]==-3)
            {
                return(1);
            }
        }
        if ((ligne+2<=7) && (colonne+1<=7))
        {
            if (plateau[ligne+2][colonne+1]==-3)
            {
                return(1);
            }
        }
    }

    if (Couleur='B')
    {
        for (a=1;a<7;a++)
        {
            if ((ligne-a>=0) && (tab[0]!=1))
            {
                if (plateau[ligne-a][colonne]==5 || plateau[ligne-a][colonne]==4)//case avec une reine BLANCHE ou une tour BLANCHE dessus
                {
                    return(1);
                    tab[0]=1;
                }
                if (plateau[ligne-a][colonne]==3 || plateau[ligne-a][colonne]==2 || plateau[ligne-a][colonne]==1)//case avec une PIECE NOIRE autre que tour et reine
                {
                    tab[0]=1;
                }
                if (plateau[ligne-a][colonne]<0)//case avec un NOIR dessus = protégé
                {
                    tab[0]=1;
                }
            }
            if ((ligne+a<=7) && (tab[1]!=1))
            {
                if (plateau[ligne+a][colonne]==5 || plateau[ligne+a][colonne]==4)//case avec une reine BLANCHE ou une tour BLANCHE dessus
                {
                    return(1);
                    tab[1]=1;
                }
                if (plateau[ligne+a][colonne]==3 || plateau[ligne+a][colonne]==2 || plateau[ligne+a][colonne]==1)//case avec une PIECE NOIRE autre que tour et reine
                {
                    tab[1]=1;
                }
                if (plateau[ligne+a][colonne]<0)//case avec un NOIR dessus = protégé
                {
                    tab[1]=1;
                }
            }
            if ((colonne-a>=0) && (tab[2]!=1))
            {
                if (plateau[ligne][colonne-a]==5 || plateau[ligne][colonne-a]==4)//case avec une reine BLANCHE ou une tour BLANCHE dessus
                {
                    return(1);
                    tab[2]=1;
                }
                if (plateau[ligne][colonne-a]==3 || plateau[ligne][colonne-a]==2 || plateau[ligne][colonne-a]==1)//case avec une PIECE NOIRE autre que tour et reine
                {
                    tab[2]=1;
                }
                if (plateau[ligne][colonne-a]<0)//case avec un NOIR dessus = protégé
                {
                    tab[2]=1;
                }
            }
            if ((colonne+a<=7) && (tab[3]!=1))
            {
                if (plateau[ligne][colonne+a]==5 || plateau[ligne][colonne+a]==4)//case avec une reine BLANCHE ou une tour BLANCHE dessus
                {
                    return(1);
                    tab[3]=1;
                }
                if (plateau[ligne][colonne+a]==3 || plateau[ligne][colonne+a]==2 || plateau[ligne][colonne+a]==1)//case avec une PIECE NOIRE autre que tour et reine
                {
                    tab[3]=1;
                }
                if (plateau[ligne][colonne+a]<0)//case avec un NOIR dessus = protégé
                {
                    tab[3]=1;
                }
            }
        }
        for (a=1;a<7;a++)
        {
            if (a==1)
            {
                if (Couleur_Joueur==Couleur)
                {
                    if ((ligne-a>=0) && (colonne-a>=0))
                    {
                        if (plateau[ligne-a][colonne-a]==5 || plateau[ligne-a][colonne-a]==2 || plateau[ligne-a][colonne-a]==1)//case avec une reine BLANCHE ou un fou BLANCHE dessus
                        {
                            return(1);
                            tab[4]=1;
                        }
                        if (plateau[ligne-a][colonne-a]==-4 || plateau[ligne-a][colonne-a]==-3)//case avec une PIECE BLANCHE autre que fou, pion et reine
                        {
                            tab[4]=1;
                        }
                        if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC dessus = protégé
                        {
                            tab[4]=1;
                        }
                    }
                    else
                    {
                        tab[4]=1;
                    }
                    if ((ligne-a>=0) && (colonne+a<=7))
                    {
                        if (plateau[ligne-a][colonne+a]==5 || plateau[ligne-a][colonne+a]==2 || plateau[ligne-a][colonne+a]==1)//case avec une reine BLANCHE ou un fou BLANCHE dessus
                        {
                            return(1);
                            tab[5]=1;
                        }
                        if (plateau[ligne-a][colonne+a]==-4 || plateau[ligne-a][colonne+a]==-3)//case avec une PIECE BLANCHE autre que fou, pion et reine
                        {
                            tab[5]=1;
                        }
                        if (plateau[ligne-a][colonne+a]>0)//case avec un NOIR dessus = protégé
                        {
                            tab[5]=1;
                        }
                    }
                    else
                    {
                        tab[5]=1;
                    }
                }
                if (Couleur_Joueur!=Couleur)
                {
                    if ((ligne-a>=0) && (colonne-a>=0))
                    {
                        if (plateau[ligne-a][colonne-a]==5 || plateau[ligne-a][colonne-a]==2)//case avec une reine BLANCHE ou un fou BLANCHE dessus
                        {
                            return(1);
                            tab[4]=1;
                        }
                        if (plateau[ligne-a][colonne-a]==-4 || plateau[ligne-a][colonne-a]==-3)//case avec une PIECE BLANCHE autre que fou, pion et reine
                        {
                            tab[4]=1;
                        }
                        if (plateau[ligne-a][colonne-a]>0)//case avec un BLANC dessus = protégé
                        {
                            tab[4]=1;
                        }
                    }
                    else
                    {
                        tab[4]=1;
                    }
                    if ((ligne-a>=0) && (colonne+a<=7))
                    {
                        if (plateau[ligne-a][colonne+a]==5 || plateau[ligne-a][colonne+a]==2)//case avec une reine BLANCHE ou un fou BLANCHE dessus
                        {
                            return(1);
                            tab[5]=1;
                        }
                        if (plateau[ligne-a][colonne+a]==-4 || plateau[ligne-a][colonne+a]==-3)//case avec une PIECE BLANCHE autre que fou, pion et reine
                        {
                            tab[5]=1;
                        }
                        if (plateau[ligne-a][colonne+a]>0)//case avec un NOIR dessus = protégé
                        {
                            tab[5]=1;
                        }
                    }
                    else
                    {
                        tab[5]=1;
                    }
                    if ((ligne+a<=7) && (colonne-a>=0))
                    {
                        if (plateau[ligne+a][colonne-a]==1)//case avec un pion BLANC
                        {
                            return(1);
                            tab[6]=1;
                        }
                    }
                    else
                    {
                        tab[6]=1;
                    }
                    if ((ligne+a<=7) && (colonne+a<=7))
                    {
                        if (plateau[ligne+a][colonne+a]==1)//case avec un pion BLANC
                        {
                            return(1);
                            tab[7]=1;
                        }
                    }
                    else
                    {
                        tab[7]=1;
                    }
                }
            }
            if (a!=1)
            {
                if ((ligne-a>=0) && (colonne-a>=0) && (tab[4]!=1))
                {
                    if (plateau[ligne-a][colonne-a]==5 || plateau[ligne-a][colonne-a]==2)//case avec une reine BLANCHE ou un fou BLANC dessus
                    {
                        return(1);
                        tab[4]=1;
                    }
                    if (plateau[ligne-a][colonne-a]==4 || plateau[ligne-a][colonne-a]==3 || plateau[ligne-a][colonne-a]==-1)//case avec une PIECE BLANCHE autre que fou et reine
                    {
                        tab[4]=1;
                    }
                    if (plateau[ligne-a][colonne-a]<0)//case avec un NOIR dessus = protégé
                    {
                        tab[4]=1;
                    }
                }
                else
                {
                    tab[4]=1;
                }
                if ((ligne-a>=0) && (colonne+a<=7) && (tab[5]!=1))
                {
                    if (plateau[ligne-a][colonne+a]==5 || plateau[ligne-a][colonne+a]==2)//case avec une reine BLANCHE ou un fou BLANC dessus
                    {
                        return(1);
                        tab[5]=1;
                    }
                    if (plateau[ligne-a][colonne+a]==4 || plateau[ligne-a][colonne+a]==3 || plateau[ligne-a][colonne+a]==1)//case avec une PIECE BLANCHE autre que fou et reine
                    {
                        tab[5]=1;
                    }
                    if (plateau[ligne-a][colonne+a]<0)//case avec un NOIR dessus = protégé
                    {
                        tab[5]=1;
                    }
                }
                else
                {
                    tab[5]=1;
                }
                if ((ligne+a<=7) && (colonne-a>=0) && (tab[6]!=1))
                {
                    if (plateau[ligne+a][colonne-a]==5 || plateau[ligne+a][colonne-a]==2)//case avec une reine BLANCHE ou un fou BLANC dessus
                    {
                        return(1);
                        tab[6]=1;
                    }
                    if (plateau[ligne+a][colonne-a]==4 || plateau[ligne+a][colonne-a]==3 || plateau[ligne+a][colonne-a]==1)//case avec une PIECE BLANCHE autre que fou et reine
                    {
                        tab[6]=1;
                    }
                    if (plateau[ligne+a][colonne-a]<0)//case avec un NOIR dessus = protégé
                    {
                        tab[6]=1;
                    }
                }
                else
                {
                    tab[6]=1;
                }
                if ((ligne+a<=7) && (colonne+a<=7) && (tab[7]!=1))
                {
                    if (plateau[ligne+a][colonne+a]==5 || plateau[ligne+a][colonne+a]==2)//case avec une reine BLANCHE ou un fou BLANC dessus
                    {
                        return(1);
                        tab[7]=1;
                    }
                    if (plateau[ligne+a][colonne+a]==4 || plateau[ligne+a][colonne+a]==3 || plateau[ligne+a][colonne+a]==1)//case avec une PIECE BLANCHE autre que fou et reine
                    {
                        tab[7]=1;
                    }
                    if (plateau[ligne+a][colonne+a]<0)//case avec un NOIR dessus = protégé
                    {
                        tab[7]=1;
                    }
                }
                else
                {
                    tab[7]=1;
                }
            }
        }
        if ((ligne-2>=0) && (colonne-1>=0))
        {
            if (plateau[ligne-2][colonne-1]==3)
            {
                return(1);
            }
        }
        if ((ligne-2>=0) && (colonne+1<=7))
        {
            if (plateau[ligne-2][colonne+1]==3)
            {
                return(1);
            }
        }
        if ((ligne-1>=0) && (colonne-2>=0))
        {
            if (plateau[ligne-1][colonne-2]==3)
            {
                return(1);
            }
        }
        if ((ligne-1>=0) && (colonne+2<=7))
        {
            if (plateau[ligne-1][colonne+2]==3)
            {
                return(1);
            }
        }
        if ((ligne+1<=7) && (colonne-2>=0))
        {
            if (plateau[ligne+1][colonne-2]==3)
            {
                return(1);
            }
        }
        if ((ligne+1<=7) && (colonne+2<=7))
        {
            if (plateau[ligne+1][colonne+2]==3)
            {
                return(1);
            }
        }
        if ((ligne+2<=7) && (colonne-1>=0))
        {
            if (plateau[ligne+2][colonne-1]==3)
            {
                return(1);
            }
        }
        if ((ligne+2<=7) && (colonne+1<=7))
        {
            if (plateau[ligne+2][colonne+1]==3)
            {
                return(1);
            }
        }
    }
    return(0);
}
