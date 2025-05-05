#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

void creation_fenetre(pWindow,pRenderer)
{
    //creation de la fennetre
    //pWindow = SDL_CreateWindow("interface Risk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1500, 800, SDL_WINDOW_RESIZABLE);
    //pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    //SDL_Surface *texte= NULL;


    //affichage de la map
    SDL_SetRenderDrawColor(pRenderer, 211, 211, 211, 255);
    SDL_RenderClear(pRenderer);
    SDL_Surface*image =SDL_LoadBMP("risk_mapBMP.bmp");
    SDL_Texture*pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);
    SDL_FreeSurface(image);
    SDL_RenderClear(pRenderer);
    SDL_RenderCopy(pRenderer, pTextureImage, NULL, NULL);
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderPresent(pRenderer);

    //SDL_Rect position;
    //position.x= 200;
    //position.y=600;
    //police = TTF_OpenFont("empire.ttf", 65);
    //SDL_Color couleurNoire = {0, 0, 0};
    //SDL_Surface*texte = TTF_RenderText_Blended(police, "Bienvenue Sur RISK !", couleurNoire);
    //SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, texte);
    //SDL_FreeSurface(texte);
    //TTF_CloseFont(police);

    //SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
    //SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    //SDL_RenderCopy(pRenderer, texture, NULL, &position);

    //SDL_RenderPresent(pRenderer);


}



void menu(pWindow,pRenderer,police)
{

    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
    SDL_RenderClear(pRenderer);
    SDL_Rect position;
    position.x= 300;
    position.y=400;
    police = TTF_OpenFont("empire.ttf", 65);
    SDL_Color couleurRouge = {255, 0, 0};
    SDL_Surface*texte = TTF_RenderText_Blended(police, "Bienvenue Sur RISK !", couleurRouge);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, texte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);

    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderCopy(pRenderer, texture, NULL, &position);
    SDL_RenderPresent(pRenderer);


    //gestion des evenements
    SDL_Event event;
    int continuer = 1;
    while (continuer)
    {
    SDL_WaitEvent(&event); /* R�cup�ration de l'�v�nement dans event */
    switch(event.type) /* Test du type d'�v�nement */
        {
        case SDL_QUIT:
        continuer = 0;
        break;

        switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
            continuer = 0;
            break;


            }

        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_RIGHT) /* On arr�te le programme si on a fait un clic droit */
            continuer = 0;
            break;

        case SDL_KEYDOWN: /* Si appui sur une touche */
            switch( event.key.keysym.sym )
            {
            case SDLK_SPACE:
            creation_fenetre(pWindow,pRenderer);
            break;
            }



        }
    }
}




void break_window()
{


    SDL_Event event;
    bool isOpen = true ;
    while (isOpen)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                isOpen = false;
                break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    isOpen = false;
                    break;
                }
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_RIGHT) /* On arr�te le programme si on a fait un clic droit */
                    isOpen = false;
                    break;
            break;
            }

        }
    }
}
