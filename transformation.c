#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include <stdbool.h>
#include "transformation.h"
#include "pieces.h"


int transfo_blanc(int **plateau, int ligne, int colonne)
{
    SDL_Window *window_transfo_blanc = NULL;
    SDL_Renderer *renderer_transfo_blanc = NULL;

    SDL_Surface *image_reine_blanche = NULL;
    SDL_Surface *image_tour_blanche = NULL;
    SDL_Surface *image_cavalier_blanc = NULL;
    SDL_Surface *image_fou_blanc = NULL;
    image_reine_blanche = SDL_LoadBMP("W_Queen.bmp");
    image_tour_blanche = SDL_LoadBMP("W_Rook.bmp");
    image_cavalier_blanc = SDL_LoadBMP("W_Knight.bmp");
    image_fou_blanc = SDL_LoadBMP("W_Bishop.bmp");

    SDL_Color noir = {0, 0, 0, 255};
    SDL_Color blanc = {255,255,255,255};

    window_transfo_blanc = SDL_CreateWindow("Choisissez la transformation de votre pion :", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 440, 140, SDL_WINDOW_SHOWN);
    renderer_transfo_blanc = SDL_CreateRenderer(window_transfo_blanc, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //REINE BLANCHE
    SDL_Rect rect_QBlanc = {20, 20, 100, 100};
    SDL_SetRenderDrawColor(renderer_transfo_blanc, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer_transfo_blanc, &rect_QBlanc);
    SDL_SetRenderDrawColor(renderer_transfo_blanc, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer_transfo_blanc, &rect_QBlanc);
    SDL_Texture* image_RB = SDL_CreateTextureFromSurface(renderer_transfo_blanc, image_reine_blanche);
    SDL_RenderCopy(renderer_transfo_blanc, image_RB, NULL, &rect_QBlanc);
    SDL_DestroyTexture(image_RB);
    SDL_FreeSurface(image_reine_blanche);

    //TOUR BLANCHE
    SDL_Rect rect_TBlanc = {120, 20, 100, 100};
    SDL_SetRenderDrawColor(renderer_transfo_blanc, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer_transfo_blanc, &rect_TBlanc);
    SDL_SetRenderDrawColor(renderer_transfo_blanc, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer_transfo_blanc, &rect_TBlanc);
    SDL_Texture* image_TB = SDL_CreateTextureFromSurface(renderer_transfo_blanc, image_tour_blanche);
    SDL_RenderCopy(renderer_transfo_blanc, image_TB, NULL, &rect_TBlanc);
    SDL_DestroyTexture(image_TB);
    SDL_FreeSurface(image_tour_blanche);

    //CAVALIER BLANC
    SDL_Rect rect_CBlanc = {220, 20, 100, 100};
    SDL_SetRenderDrawColor(renderer_transfo_blanc, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer_transfo_blanc, &rect_CBlanc);
    SDL_SetRenderDrawColor(renderer_transfo_blanc, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer_transfo_blanc, &rect_CBlanc);
    SDL_Texture* image_CB = SDL_CreateTextureFromSurface(renderer_transfo_blanc, image_cavalier_blanc);
    SDL_RenderCopy(renderer_transfo_blanc, image_CB, NULL, &rect_CBlanc);
    SDL_DestroyTexture(image_CB);
    SDL_FreeSurface(image_cavalier_blanc);

    //FOU BLANC
    SDL_Rect rect_FBlanc = {320, 20, 100, 100};
    SDL_SetRenderDrawColor(renderer_transfo_blanc, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer_transfo_blanc, &rect_FBlanc);
    SDL_SetRenderDrawColor(renderer_transfo_blanc, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer_transfo_blanc, &rect_FBlanc);
    SDL_Texture* image_FB = SDL_CreateTextureFromSurface(renderer_transfo_blanc, image_fou_blanc);
    SDL_RenderCopy(renderer_transfo_blanc, image_FB, NULL, &rect_FBlanc);
    SDL_DestroyTexture(image_FB);
    SDL_FreeSurface(image_fou_blanc);

    SDL_RenderPresent(renderer_transfo_blanc);

    int x = 0, y = 0;
    SDL_Event events;
    int continuer = 1;

    while (continuer=1)
    {
        SDL_WaitEvent(&events);
        switch(events.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(events.button.button == SDL_BUTTON_LEFT)
                {
                    x = events.button.x;
                    y = events.button.y;
                    if((x > rect_QBlanc.x) && (x < (rect_QBlanc.x + rect_QBlanc.w)) && (y > rect_QBlanc.y) && (y < (rect_QBlanc.y + rect_QBlanc.h)))
                    {
                        //plateau[ligne][colonne] = 5;
                        continuer = 0;
                        SDL_DestroyWindow(window_transfo_blanc);
                        return 5;
                    }
                    if((x > rect_TBlanc.x) && (x < (rect_TBlanc.x + rect_TBlanc.w)) && (y > rect_TBlanc.y) && (y < (rect_TBlanc.y + rect_TBlanc.h)))
                    {
                        //plateau[ligne][colonne] = 4;
                        continuer = 0;
                        SDL_DestroyWindow(window_transfo_blanc);
                        return 4;
                    }
                    if((x > rect_CBlanc.x) && (x < (rect_CBlanc.x + rect_CBlanc.w)) && (y > rect_CBlanc.y) && (y < (rect_CBlanc.y + rect_CBlanc.h)))
                    {
                        //plateau[ligne][colonne] = 3;
                        continuer = 0;
                        SDL_DestroyWindow(window_transfo_blanc);
                        return 3;
                    }
                    if((x > rect_FBlanc.x) && (x < (rect_FBlanc.x + rect_FBlanc.w)) && (y > rect_FBlanc.y) && (y < (rect_FBlanc.y + rect_FBlanc.h)))
                    {
                        //plateau[ligne][colonne] = 2;
                        continuer = 0;
                        SDL_DestroyWindow(window_transfo_blanc);
                        return 2;
                    }
                }
        }
    }
}



int transfo_noir(int **plateau, int ligne, int colonne)
{
    SDL_Window *window_transfo_noir = NULL;
    SDL_Renderer *renderer_transfo_noir = NULL;

    SDL_Surface *image_reine_noire = NULL;
    SDL_Surface *image_tour_noire = NULL;
    SDL_Surface *image_cavalier_noir = NULL;
    SDL_Surface *image_fou_noir = NULL;
    image_reine_noire = SDL_LoadBMP("B_Queen.bmp");
    image_tour_noire = SDL_LoadBMP("B_Rook.bmp");
    image_cavalier_noir = SDL_LoadBMP("B_Knight.bmp");
    image_fou_noir = SDL_LoadBMP("B_Bishop.bmp");

    SDL_Color noir = {0, 0, 0, 255};
    SDL_Color blanc = {255,255,255,255};

    window_transfo_noir = SDL_CreateWindow("Choisissez la transformation de votre pion :", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 440, 140, SDL_WINDOW_SHOWN);
    renderer_transfo_noir = SDL_CreateRenderer(window_transfo_noir, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //REINE NOIRE
    SDL_Rect rect_QNoire = {20, 20, 100, 100};
    SDL_SetRenderDrawColor(renderer_transfo_noir, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer_transfo_noir, &rect_QNoire);
    SDL_SetRenderDrawColor(renderer_transfo_noir, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer_transfo_noir, &rect_QNoire);
    SDL_Texture* image_RN = SDL_CreateTextureFromSurface(renderer_transfo_noir, image_reine_noire);
    SDL_RenderCopy(renderer_transfo_noir, image_RN, NULL, &rect_QNoire);
    SDL_DestroyTexture(image_RN);
    SDL_FreeSurface(image_reine_noire);

    //TOUR NOIRE
    SDL_Rect rect_TNoire = {120, 20, 100, 100};
    SDL_SetRenderDrawColor(renderer_transfo_noir, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer_transfo_noir, &rect_TNoire);
    SDL_SetRenderDrawColor(renderer_transfo_noir, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer_transfo_noir, &rect_TNoire);
    SDL_Texture* image_TN = SDL_CreateTextureFromSurface(renderer_transfo_noir, image_tour_noire);
    SDL_RenderCopy(renderer_transfo_noir, image_TN, NULL, &rect_TNoire);
    SDL_DestroyTexture(image_TN);
    SDL_FreeSurface(image_tour_noire);

    //CAVALIER NOIR
    SDL_Rect rect_CNoir = {220, 20, 100, 100};
    SDL_SetRenderDrawColor(renderer_transfo_noir, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer_transfo_noir, &rect_CNoir);
    SDL_SetRenderDrawColor(renderer_transfo_noir, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer_transfo_noir, &rect_CNoir);
    SDL_Texture* image_CN = SDL_CreateTextureFromSurface(renderer_transfo_noir, image_cavalier_noir);
    SDL_RenderCopy(renderer_transfo_noir, image_CN, NULL, &rect_CNoir);
    SDL_DestroyTexture(image_CN);
    SDL_FreeSurface(image_cavalier_noir);

    //FOU NOIR
    SDL_Rect rect_FNoir = {320, 20, 100, 100};
    SDL_SetRenderDrawColor(renderer_transfo_noir, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer_transfo_noir, &rect_FNoir);
    SDL_SetRenderDrawColor(renderer_transfo_noir, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer_transfo_noir, &rect_FNoir);
    SDL_Texture* image_FN = SDL_CreateTextureFromSurface(renderer_transfo_noir, image_fou_noir);
    SDL_RenderCopy(renderer_transfo_noir, image_FN, NULL, &rect_FNoir);
    SDL_DestroyTexture(image_FN);
    SDL_FreeSurface(image_fou_noir);

    SDL_RenderPresent(renderer_transfo_noir);

    int x = 0, y = 0;
    SDL_Event events;
    int continuer = 1;

    while (continuer=1)
    {
        SDL_WaitEvent(&events);
        switch(events.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(events.button.button == SDL_BUTTON_LEFT)
                {
                    x = events.button.x;
                    y = events.button.y;
                    if((x > rect_QNoire.x) && (x < (rect_QNoire.x + rect_QNoire.w)) && (y > rect_QNoire.y) && (y < (rect_QNoire.y + rect_QNoire.h)))
                    {
                        //plateau[ligne][colonne] = -5;
                        continuer = 0;
                        SDL_DestroyWindow(window_transfo_noir);
                        return -5;
                    }
                    if((x > rect_TNoire.x) && (x < (rect_TNoire.x + rect_TNoire.w)) && (y > rect_TNoire.y) && (y < (rect_TNoire.y + rect_TNoire.h)))
                    {
                        //plateau[ligne][colonne] = -4;
                        continuer = 0;
                        SDL_DestroyWindow(window_transfo_noir);
                        return -4;
                    }
                    if((x > rect_CNoir.x) && (x < (rect_CNoir.x + rect_CNoir.w)) && (y > rect_CNoir.y) && (y < (rect_CNoir.y + rect_CNoir.h)))
                    {
                        //plateau[ligne][colonne] = -3;
                        continuer = 0;
                        SDL_DestroyWindow(window_transfo_noir);
                        return -3;
                    }
                    if((x > rect_FNoir.x) && (x < (rect_FNoir.x + rect_FNoir.w)) && (y > rect_FNoir.y) && (y < (rect_FNoir.y + rect_FNoir.h)))
                    {
                        //plateau[ligne][colonne] = -2;
                        continuer = 0;
                        SDL_DestroyWindow(window_transfo_noir);
                        return -2;
                    }
                }
        }
    }
}



void transformation_pion(int **plateau, int ligne, int colonne, char Couleur)
{
    if (Couleur=='B') //Couleur = blanc = 1
    {
        transfo_blanc(plateau, ligne, colonne);
    }
    if (Couleur=='N') //Couleur = noir = 2
    {
        transfo_noir(plateau, ligne, colonne);
    }
}


void verif_transformation_pion_possible(int **plateau, int ligne, int colonne, char Couleur, char Couleur_Joueur)
{
    if (Couleur==Couleur_Joueur) //couleur du pion = couleur du joueur, donc si le pion est en ligne 0 alors il peut se transformer
    {
        if (ligne==0)
        {
            transformation_pion(plateau, ligne, colonne, Couleur);
        }
    }
    if (Couleur!=Couleur_Joueur) //couleur du pion != couleur du joueur, donc si le pion est en ligne 7 alors il peut se transformer
    {
        if (ligne==7)
        {
            transformation_pion(plateau, ligne, colonne, Couleur);
        }
    }
}


int **verif_transformation_IA(int **plateau, char CouleurIA)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(CouleurIA=='B')
            {
                if(plateau[i][7]==1)
                {
                    plateau[i][7]==5;
                }
            }
            if(CouleurIA=='N')
            {
                if(plateau[i][7]==-1)
                {
                    plateau[i][7]==-5;
                }
            }
        }
    }
    return(plateau);
}
