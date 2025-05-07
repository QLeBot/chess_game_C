#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
//#include "interface.h"
#include "interface_2.h"

//void jeu(window, renderer, couleur);

//A Faire
/*
 - Gestion d'affichage des pieces éliminées OK --> créer tableau (malloc ?)
 - Gestion déplacements pieces (commencé pas encore complétement intégré)
        comment gérer le tour par tour
 - Gestion affichage des cases de déplacement possible en vert. OK --> créer tableau
 - Transformation pion
*/

/*
Pour coloration en vert

SDL_Color vert = {59,234,120,128}
//On recupère soit la valeur blocs soit sa ligne et sa colonne
SDL_SetRenderDrawColor(renderer, vert.r, vert.g, vert.b, vert.a);
SDL_RenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
SDL_RenderFillRect(rect);

*/

int main(int argc, char *argv[])
{
    int x = 0, y = 0;

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *display = NULL, *text = NULL, *background = NULL, *surface = NULL;
    SDL_Texture *texture = NULL, *tmp = NULL;
    TTF_Font* g_font = NULL;

    SDL_Color orange = {255, 127, 40, 255};
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color white = {255,255,255,255};

    surface = SDL_LoadBMP("src/addons/images/echecs.bmp");
    //SDL_Rect position;

    int statut = EXIT_FAILURE;

    //Initialisation SDL
    if(0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        goto Quit;
    }

    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        fprintf(stderr, "Erreur IMG_Init : %s\n", IMG_GetError());
        goto Quit;
    }

    // Initialize SDL_ttf
    if(TTF_Init() == -1) {
        fprintf(stderr, "Erreur TTF_Init : %s\n", TTF_GetError());
        goto Quit;
    }

    // Load font
    g_font = TTF_OpenFont("src/addons/fonts/demoness.otf", 24);
    if(!g_font) {
        fprintf(stderr, "Erreur TTF_OpenFont : %s\n", TTF_GetError());
        goto Quit;
    }

    //Création Window
    window = SDL_CreateWindow("Jeu d'Echecs", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1500, 800, SDL_WINDOW_SHOWN);

    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s\n", SDL_GetError());
        goto Quit;
    }

    //Création Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }

    if(NULL == surface)
    {
        fprintf(stderr, "Erreur IMG_Load : %s", IMG_GetError());
        goto Quit;
    }

    tmp = SDL_CreateTextureFromSurface(renderer, surface);
    //SDL_FreeSurface(tmp);

    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        goto Quit;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, surface->w, surface->h);

    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        goto Quit;
    }

    //
    if(0 != SDL_SetRenderDrawColor(renderer,  white.r, white.g, white.b, white.a))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }

    if(0 != SDL_RenderClear(renderer))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }

    //menu(window, renderer, tmp, texture);
    menu_alt(window, renderer, tmp, texture, g_font);

    statut = EXIT_SUCCESS;

Quit:
    if(g_font != NULL)
        TTF_CloseFont(g_font);
    TTF_Quit();
    IMG_Quit();
    if(NULL != texture)
        SDL_DestroyTexture(texture);
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}


