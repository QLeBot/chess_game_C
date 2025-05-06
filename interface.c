#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <stdbool.h>

#include "interface.h"
#include "initialisation.h"
#include "mouvements.h"
#include "IA.h"
#include "transformation.h"

void abandonner(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture)//d�faite
{
    SDL_Window *window_defaite = NULL;
    SDL_Renderer *renderer_defaite = NULL;
    window_defaite = SDL_CreateWindow("Ecran defaite", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 375, SDL_WINDOW_SHOWN);
    renderer_defaite = SDL_CreateRenderer(window_defaite, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface *image_defaite = NULL;
    image_defaite = SDL_LoadBMP("addons/images/Defaite.bmp");

    SDL_Rect rectagle_image_defaite = {0, 0, 500, 375};
    SDL_Texture* mon_image = SDL_CreateTextureFromSurface(renderer_defaite, image_defaite);
    SDL_RenderCopy(renderer_defaite, mon_image, NULL, &rectagle_image_defaite);
    SDL_DestroyTexture(mon_image);
    SDL_FreeSurface(image_defaite);

    SDL_Surface *image_recommencer = NULL;
    image_recommencer = SDL_LoadBMP("addons/images/Recommencer.bmp");

    SDL_Rect rect_recommencer = {50, 200, 400, 100};
    SDL_Texture* mon_image_R = SDL_CreateTextureFromSurface(renderer_defaite, image_recommencer);
    SDL_RenderCopy(renderer_defaite, mon_image_R, NULL, &rect_recommencer);
    SDL_DestroyTexture(mon_image_R);
    SDL_FreeSurface(image_recommencer);

    SDL_RenderPresent(renderer_defaite);

    //Boucle infinie jusqu'� fermeture
    SDL_Event eventsA;
    int continuer = 1;
    int x, y;

    while (continuer)
    {
        SDL_WaitEvent(&eventsA);
        switch(eventsA.type)
        {
            case SDL_QUIT:
                SDL_DestroyWindow(window_defaite);
                SDL_DestroyWindow(window);
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(eventsA.button.button == SDL_BUTTON_LEFT)
                {
                    x = eventsA.button.x;
                    y = eventsA.button.y;
                    if((x > rect_recommencer.x) && (x < (rect_recommencer.x + rect_recommencer.w)) && (y > rect_recommencer.y) && (y < (rect_recommencer.y + rect_recommencer.h)))
                    {
                        SDL_DestroyWindow(window_defaite);
                        menu(window, renderer, tmp, texture);
                        continuer = 0;
                    }
                }//if
        }//switch
    }//while
}

void victoire(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture)//victoire
{
    SDL_Window *window_victoire = NULL;
    SDL_Renderer *renderer_victoire = NULL;
    window_victoire = SDL_CreateWindow("Ecran victoire", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 375, SDL_WINDOW_SHOWN);
    renderer_victoire = SDL_CreateRenderer(window_victoire, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface *image_victoire = NULL;
    image_victoire = SDL_LoadBMP("addons/images/Victoire.bmp");

    SDL_Rect rectagle_image_victoire = {0, 0, 500, 375};
    SDL_Texture* mon_image = SDL_CreateTextureFromSurface(renderer_victoire, image_victoire);
    SDL_RenderCopy(renderer_victoire, mon_image, NULL, &rectagle_image_victoire);
    SDL_DestroyTexture(mon_image);
    SDL_FreeSurface(image_victoire);

    SDL_Surface *image_recommencer = NULL;
    image_recommencer = SDL_LoadBMP("addons/images/Recommencer.bmp");

    SDL_Rect rect_recommencer = {50, 200, 400, 100};
    SDL_Texture* mon_image_R = SDL_CreateTextureFromSurface(renderer_victoire, image_recommencer);
    SDL_RenderCopy(renderer_victoire, mon_image_R, NULL, &rect_recommencer);
    SDL_DestroyTexture(mon_image_R);
    SDL_FreeSurface(image_recommencer);

    SDL_RenderPresent(renderer_victoire);

    //Boucle infinie jusqu'� fermeture
    SDL_Event eventsV;
    int continuer = 1;
    int x, y;

    while (continuer)
    {
        SDL_WaitEvent(&eventsV);
        switch(eventsV.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(eventsV.button.button == SDL_BUTTON_LEFT)
                {
                    x = eventsV.button.x;
                    y = eventsV.button.y;
                    if((x > rect_recommencer.x) && (x < (rect_recommencer.x + rect_recommencer.w)) && (y > rect_recommencer.y) && (y < (rect_recommencer.y + rect_recommencer.h)))
                    {
                        SDL_DestroyWindow(window_victoire);
                        menu(window, renderer, tmp, texture);
                        continuer = 0;
                    }
                }//if
        }//switch
    }//while
}

void jeu(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture, int **plateau, char Couleur_Joueur)
{

    //int statut = EXIT_FAILURE;

    //char tour;

    //printf("tout va bien\n");

    /*
    for(int i=0; i < 8; i++)
    {
        for(int j=0; j < 8; j++)
        {
            printf("%d", plateau[i][j]);
        }
    }

    */
    //printf("\ntout va encore bien\n");

    /*
    if(Couleur_Joueur == "blanc")
    {
        tour = Joueur;
    }
    if(Couleur_Joueur == "noir")
    {
        tour = IA;
    }
    */

    //printf(&plateau[0][0]);

    SDL_Surface *surface_abandon = NULL;
    surface_abandon = SDL_LoadBMP("addons/images/Abandonner.bmp");

    SDL_Color orange = {255, 127, 40, 255};
    SDL_Color gris_clair = {204, 209, 209, 255};
    SDL_Color gris_fonce = {81, 90, 90, 255};
    SDL_Color noir = {0, 0, 0, 255};
    SDL_Color blanc = {255,255,255,255};

    SDL_Rect rect_zone_blanc = {0, 0, 200, 600};
    SDL_Rect rect_zone_noir = {1300, 0, 200, 600};
    SDL_Rect rect_zone_jeu = {350, 0, 800, 800};

    SDL_Rect rect_zone_abandon = {1300, 700, 200, 100};

    SDL_SetRenderDrawColor(renderer, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);

    SDL_RenderDrawRect(renderer, &rect_zone_blanc);
    SDL_RenderDrawRect(renderer, &rect_zone_noir);
    SDL_RenderDrawRect(renderer, &rect_zone_jeu);
    SDL_RenderDrawRect(renderer, &rect_zone_abandon);

    SDL_Rect rect_pieces_blanches_eliminees[4][4];

    //Zones Pieces Elimin�es
    //int g,h;
    for(int g=0; g < 4; g++)
    {
        for(int h=0; h < 4; h++)
        {
            rect_pieces_blanches_eliminees[g][h].x = h* 50;
            rect_pieces_blanches_eliminees[g][h].y = g* 50;
            rect_pieces_blanches_eliminees[g][h].w = rect_pieces_blanches_eliminees[g][h].h = 50;
            SDL_SetRenderDrawColor(renderer, blanc.r, blanc.g, blanc.b, blanc.a);
            SDL_RenderFillRect(renderer,&rect_pieces_blanches_eliminees[g][h]);
        }
    }

    SDL_Rect rect_pieces_noires_eliminees[4][4];

    //int k,l;
    for(int k=0; k < 4; k++)
    {
        for(int l=0; l < 4; l++)
        {
            rect_pieces_noires_eliminees[k][l].x = 1300 + l* 50;
            rect_pieces_noires_eliminees[k][l].y = k* 50;
            rect_pieces_noires_eliminees[k][l].w = rect_pieces_noires_eliminees[k][l].h = 50;
            SDL_SetRenderDrawColor(renderer, blanc.r, blanc.g, blanc.b, blanc.a);
            SDL_RenderFillRect(renderer,&rect_pieces_noires_eliminees[k][l]);
        }
    }


    //Version double dimension
    SDL_Rect blocs[8][8];

    /*
    blocs[0][0].x = 350;
    blocs[0][0].y = 0;
    blocs[0][0].w = blocs[0][0].h = 100;

    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderFillRect(renderer,&blocs[0][0]);

    blocs[0][1].x = 450;
    blocs[0][1].y = 0;
    blocs[0][1].w = blocs[0][1].h = 100;

    SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
    SDL_RenderFillRect(renderer,&blocs[0][1]);
    */

    //int i,j;
    for(int i=0; i < 8; i++)
    {
        for(int j=0; j < 8; j++)
        {
            blocs[i][j].x = 350 + (j* 100);
            blocs[i][j].y = 0 + (i* 100);
            blocs[i][j].w = blocs[i][j].h = 100;
            //SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
            //SDL_RenderFillRect(renderer,&blocs[i][j]);

            if((i+j)%2 == 0)
            {
                SDL_SetRenderDrawColor(renderer, gris_clair.r, gris_clair.g, gris_clair.b, gris_clair.a);
                SDL_RenderFillRect(renderer,&blocs[i][j]);
            }
            if((i+j)%2 != 0)
            {
                SDL_SetRenderDrawColor(renderer, gris_fonce.r, gris_fonce.g, gris_fonce.b, gris_fonce.a);
                SDL_RenderFillRect(renderer,&blocs[i][j]);
            }

        }
    }

    //Affichage

    for(int i=0; i < 8; i++)
    {
        for(int j=0; j < 8; j++)
        {

            if(plateau[i][j] == -1) //Pion noir
            {
                SDL_Surface *surface_B_Pawn = NULL;
                surface_B_Pawn = SDL_LoadBMP("addons/pieces/B_Pawn.bmp");
                SDL_Texture* B_Pawn = SDL_CreateTextureFromSurface(renderer, surface_B_Pawn);
                SDL_RenderCopy(renderer, B_Pawn, NULL, &blocs[i][j]);

                SDL_FreeSurface(surface_B_Pawn);
                SDL_DestroyTexture(B_Pawn);
            }
            if(plateau[i][j] == 1)//Pion blanc
            {
                SDL_Surface *surface_W_Pawn = NULL;
                surface_W_Pawn = SDL_LoadBMP("addons/pieces/W_Pawn.bmp");
                SDL_Texture* W_Pawn = SDL_CreateTextureFromSurface(renderer, surface_W_Pawn);
                SDL_RenderCopy(renderer, W_Pawn, NULL, &blocs[i][j]);

                SDL_FreeSurface(surface_W_Pawn);
                SDL_DestroyTexture(W_Pawn);
            }
            if(plateau[i][j] == -2) //Fou noir
            {
                SDL_Surface *surface_B_Bishop = NULL;
                surface_B_Bishop = SDL_LoadBMP("addons/pieces/B_Bishop.bmp");
                SDL_Texture* B_Bishop = SDL_CreateTextureFromSurface(renderer, surface_B_Bishop);
                SDL_RenderCopy(renderer, B_Bishop, NULL, &blocs[i][j]);

                SDL_FreeSurface(surface_B_Bishop);
                SDL_DestroyTexture(B_Bishop);
            }
            if(plateau[i][j]== 2)//Fou blanc
            {
                SDL_Surface *surface_W_Bishop = NULL;
                surface_W_Bishop = SDL_LoadBMP("addons/pieces/W_Bishop.bmp");
                SDL_Texture* W_Bishop = SDL_CreateTextureFromSurface(renderer, surface_W_Bishop);
                SDL_RenderCopy(renderer, W_Bishop, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_Bishop);
                SDL_FreeSurface(surface_W_Bishop);
            }
            if(plateau[i][j] == -3) //Cavalier noir
            {
                SDL_Surface *surface_B_Knight = NULL;
                surface_B_Knight = SDL_LoadBMP("addons/pieces/B_Knight.bmp");
                SDL_Texture* B_Knight = SDL_CreateTextureFromSurface(renderer, surface_B_Knight);
                SDL_RenderCopy(renderer, B_Knight, NULL, &blocs[i][j]);

                SDL_DestroyTexture(B_Knight);
                SDL_FreeSurface(surface_B_Knight);
            }
            if(plateau[i][j] == 3)//Cavalier blanc
            {
                SDL_Surface *surface_W_Knight = NULL;
                surface_W_Knight = SDL_LoadBMP("addons/pieces/W_Knight.bmp");
                SDL_Texture* W_Knight = SDL_CreateTextureFromSurface(renderer, surface_W_Knight);
                SDL_RenderCopy(renderer, W_Knight, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_Knight);
                SDL_FreeSurface(surface_W_Knight);
            }
            if(plateau[i][j] == -4) //Tour noir
            {
                SDL_Surface *surface_B_Rook = NULL;
                surface_B_Rook = SDL_LoadBMP("addons/pieces/B_Rook.bmp");
                SDL_Texture* B_Rook = SDL_CreateTextureFromSurface(renderer, surface_B_Rook);
                SDL_RenderCopy(renderer, B_Rook, NULL, &blocs[i][j]);

                SDL_DestroyTexture(B_Rook);
                SDL_FreeSurface(surface_B_Rook);
            }
            if(plateau[i][j] == 4)//Tour blanc
            {
                SDL_Surface *surface_W_Rook = NULL;
                surface_W_Rook = SDL_LoadBMP("addons/pieces/W_Rook.bmp");
                SDL_Texture* W_Rook = SDL_CreateTextureFromSurface(renderer, surface_W_Rook);
                SDL_RenderCopy(renderer, W_Rook, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_Rook);
                SDL_FreeSurface(surface_W_Rook);
            }
            if(plateau[i][j] == -5) //Reine noir
            {
                SDL_Surface *surface_B_Queen = NULL;
                surface_B_Queen = SDL_LoadBMP("addons/pieces/B_Queen.bmp");
                SDL_Texture* B_Queen = SDL_CreateTextureFromSurface(renderer, surface_B_Queen);
                SDL_RenderCopy(renderer, B_Queen, NULL, &blocs[i][j]);

                SDL_DestroyTexture(B_Queen);
                SDL_FreeSurface(surface_B_Queen);
            }
            if(plateau[i][j] == 5)//Reine blanc
            {
                SDL_Surface *surface_W_Queen = NULL;
                surface_W_Queen = SDL_LoadBMP("addons/pieces/W_Queen.bmp");
                SDL_Texture* W_Queen = SDL_CreateTextureFromSurface(renderer, surface_W_Queen);
                SDL_RenderCopy(renderer, W_Queen, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_Queen);
                SDL_FreeSurface(surface_W_Queen);
            }
            if(plateau[i][j] == -6) //Roi noir
            {
                SDL_Surface *surface_B_King = NULL;
                surface_B_King = SDL_LoadBMP("addons/pieces/B_King.bmp");
                SDL_Texture* B_King = SDL_CreateTextureFromSurface(renderer, surface_B_King);
                SDL_RenderCopy(renderer, B_King, NULL, &blocs[i][j]);

                SDL_DestroyTexture(B_King);
                SDL_FreeSurface(surface_B_King);
            }
            if(plateau[i][j] == 6)//Roi blanc
            {
                SDL_Surface *surface_W_King = NULL;
                surface_W_King = SDL_LoadBMP("addons/pieces/W_King.bmp");
                SDL_Texture* W_King = SDL_CreateTextureFromSurface(renderer, surface_W_King);
                SDL_RenderCopy(renderer, W_King, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_King);
                SDL_FreeSurface(surface_W_King);
            }
        }
    }

    /*
    //Version Simple dimension
    SDL_Rect cases[64]; // D�claration du tableau contenant les cases blanches
    SDL_Point ligne_depart,ligne_arrivee;
    // D�claration du point de d�part et du point d'arriv�e d'une ligne


    SDL_Rect damier = {350, 0, 800, 800};

    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
    //SDL_RenderClear(renderer);
    SDL_RenderFillRect(renderer, &damier);


    cases[0].x = 350;
    cases[0].y = 0;
    cases[0].w = cases[0].h = 100;

    SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
    SDL_RenderFillRect(renderer,&cases[0]);

    for(int i = 1; i != 64; i++)
    {

        if((0<=i && i<8) || (16<=i && i<24) || (32<=i && i<40) || (48<=i && i<56))
        {
            if(i%8 == 0)
            {
                cases[i].x = cases[i-8].x;
                cases[i].y = cases[i-1].y + 100;
                cases[i].w = cases[i].h = 100;
                SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
                SDL_RenderFillRect(renderer,&cases[i]);
            }
            if(i%8 != 0)
            {
                if(i%2 != 0)
                {
                    cases[i].x = cases[i-1].x + 100;
                    cases[i].y = cases[i-1].y;
                    cases[i].w = cases[i].h = 100;
                    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
                    SDL_RenderFillRect(renderer,&cases[i]);
                }
                if(i%2 == 0)
                {
                    cases[i].x = cases[i-1].x + 100;
                    cases[i].y = cases[i-1].y;
                    cases[i].w = cases[i].h = 100;
                    SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
                    SDL_RenderFillRect(renderer,&cases[i]);
                }
            }
        }
        if((8<=i && i<16) || (24<=i && i<32) || (40<=i && i<48) || (56<=i && i<64))
        {
            if(i%8 == 0)
            {
                cases[i].x = cases[i-8].x;
                cases[i].y = cases[i-1].y + 100;
                cases[i].w = cases[i].h = 100;
                SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
                SDL_RenderFillRect(renderer,&cases[i]);
            }
            if(i%8 !=0)
            {
                if(i%2 != 0)
                {
                    cases[i].x = cases[i-1].x + 100;
                    cases[i].y = cases[i-1].y;
                    cases[i].w = cases[i].h = 100;
                    SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
                    SDL_RenderFillRect(renderer,&cases[i]);
                }
                if(i%2 == 0)
                {
                    cases[i].x = cases[i-1].x + 100;
                    cases[i].y = cases[i-1].y;
                    cases[i].w = cases[i].h = 100;
                    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
                    SDL_RenderFillRect(renderer,&cases[i]);
                }
            }
        }
    }
    */

    //printf("jusqu'ici tout va bien");

    SDL_RenderPresent(renderer);

    //SDL_DestroyTexture(B_Pawn);
    //SDL_FreeSurface(surface_B_Pawn);


    //Boucle infinie jusqu'� fermeture
    SDL_Event events;

    int continuer = 1;
    //bool quit = false;



    //int a,b,c;
    int **tab_pieces_blanches_eliminees;
    tab_pieces_blanches_eliminees = malloc(sizeof(int *) *4);
    for (int a=0; a<4; a++)
    {
        tab_pieces_blanches_eliminees[a] = malloc(sizeof(int)*4);
    }
    for (int b=0; b<4; b++)
    {
        for (int c=0; c<4; c++)
        {
            tab_pieces_blanches_eliminees[b][c]=0;
        }
    }

    //int d,e,f;
    int **tab_pieces_noires_eliminees;
    tab_pieces_noires_eliminees = malloc(sizeof(int *) *4);
    for (int d=0;d<4;d++)
    {
        tab_pieces_noires_eliminees[d] = malloc(sizeof(int)*4);
    }
    for (int e=0;e<4;e++)
    {
        for (int f=0;f<4;f++)
        {
            tab_pieces_noires_eliminees[e][f]=0;
        }
    }


    //printf("%c",Couleur_Joueur);

    //printf("c'est pass�");


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

    int l;
    int **tableau_mouvement_IA; //pour tester les mouvements de l'IA
    tableau_mouvement_IA = malloc(sizeof(int *) *8);
    for (l=0;l<8;l++)
    {
        tableau_mouvement_IA[l] = malloc(sizeof(int)*8);
    }

    int test_deplacement;
    int IA_deplacement_possible;

    int tour;

    if(Couleur_Joueur == 'B')
    {
        tour = 0;
        //printf("match B");
    }
    if(Couleur_Joueur == 'N')
    {
        tour = 1;
        //printf("match N");
    }

    //printf(tour);


    int valeur;
    char couleur;

    int i_depart;
    int j_depart;

    int x,y;

    int echecMat;
    // echecMat = 1 -> fin

    echecMat = 0;

    int nb_click = 0;

    while(echecMat != 1 && continuer != 0)
    {
        SDL_Delay(1000);
        //printf("ok");
        if(tour %2 == 0)
        {
            //Mouvement Joueur
            SDL_WaitEvent(&events);
            switch(events.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(events.button.button == SDL_BUTTON_LEFT)
                    {
                        //Postion du clic
                        x = events.button.x;
                        y = events.button.y;

                        if((x > rect_zone_abandon.x) && (x < (rect_zone_abandon.x + rect_zone_abandon.w)) && (y > rect_zone_abandon.y) && (y < (rect_zone_abandon.y + rect_zone_abandon.h)))
                        {
                            abandonner(window, renderer, tmp, texture);
                            continuer = 0;
                        }

                        if(nb_click == 0)
                        {
                            if((x > rect_zone_jeu.x) && (x < (rect_zone_jeu.x + rect_zone_jeu.w)) && (y > rect_zone_jeu.y) && (y < (rect_zone_jeu.y + rect_zone_jeu.h)))
                            {
                                for(int i=0; i < 8; i++)
                                {
                                    for(int j=0; j < 8; j++)
                                    {
                                        if((x > blocs[i][j].x) && (x < (blocs[i][j].x + blocs[i][j].w)) && (y > blocs[i][j].y) && (y < (blocs[i][j].y + blocs[i][j].h)))
                                        {
                                            //case_depart = blocs[x][y];
                                            //Il faut aussi parcourir plateau pour r�cup�rer le type de piece sur le bloc
                                            valeur = plateau[i][j];
                                            if(valeur > 0)
                                            {
                                                couleur = 'B';
                                                printf("%c\n",couleur);
                                            }
                                            if(valeur < 0)
                                            {
                                                couleur = 'N';
                                                printf("%c\n",couleur);
                                            }
                                            if(valeur != 0 && couleur == Couleur_Joueur)//v�rification qu'il y ai une pi�ce sur la case et qu'elle soit de la m�me couleur que le joueur
                                            {
                                                i_depart = i;
                                                j_depart = j;
                                                tableau_highlighting = Mouvements(plateau, i_depart, j_depart, couleur, Couleur_Joueur, valeur);
                                                /*
                                                for(int i=0;i<8;i++)
                                                {
                                                    for(int j=0;j<8;j++)
                                                    {
                                                        printf("%d", tableau_highlighting[i][j]);
                                                    }
                                                    printf("\n");
                                                }
                                                */
                                                //affichage_higlight(tableau_highlighting);
                                                printf("premier clic\n");
                                                printf("Position click: (%d, %d)\n", x, y);
                                                //**tableau_highlighting = Mouvements_Pion(plateau, i_depart, j_depart, 'blanc', 'B', pion_deja_bouge(plateau, i_depart, 'B', 'B'));
                                                //Mouvements_Pion(plateau, i_depart, j_depart, 'blanc', 'B', pion_deja_bouge(plateau, i_depart, 'B', 'B'));

                                                //Affichage highlight
                                                SDL_Color vert = {59,234,120,128};

                                                for(int i=0; i<8; i++)
                                                {
                                                    for(int j=0; j<8; j++)
                                                    {
                                                        //printf("%d", &tableau_highlighting[i][j]);
                                                        if(tableau_highlighting[i][j] == 1)
                                                        {
                                                            //printf("%d\n", tableau_highlighting[i][j]);
                                                            //printf("%d\n", i);
                                                            //printf("%d\n", j);
                                                            //On recup�re soit la valeur blocs soit sa ligne et sa colonne
                                                            SDL_SetRenderDrawColor(renderer, vert.r, vert.g, vert.b, vert.a);
                                                            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                                                            SDL_RenderFillRect(renderer, &blocs[i][j]);
                                                            SDL_RenderPresent(renderer);
                                                        }
                                                    }
                                                }

                                                nb_click = 1;
                                            }

                                        }

                                    }
                                }
                            }
                        }
                        else if(nb_click == 1)
                        {
                            printf("deuxième clic\n");
                            //printf("Position click: (%d, %d)\n", x, y);

                            if((x > rect_zone_jeu.x) && (x < (rect_zone_jeu.x + rect_zone_jeu.w)) && (y > rect_zone_jeu.y) && (y < (rect_zone_jeu.y + rect_zone_jeu.h)))
                            {
                                for(int i=0; i < 8; i++)
                                {
                                    for(int j=0; j < 8; j++)
                                    {
                                        if((x > blocs[i][j].x) && (x < (blocs[i][j].x + blocs[i][j].w)) && (y > blocs[i][j].y) && (y < (blocs[i][j].y + blocs[i][j].h)))
                                        {
                                            int i_arrivee = i;
                                            int j_arrivee = j;

                                            //printf("Coordonnees depart: (%d, %d)\n", i_depart,j_depart);
                                            //printf("Coordonnees arrivee: (%d, %d)\n", i_arrivee,j_arrivee);

                                            if(tableau_highlighting[i][j] == 1) //v�rification que la case cliqu�e soit highlight
                                            {
                                                plateau[i_depart][j_depart] = 0; //efface la pi�ce de sa position de d�part

                                                if(plateau[i_arrivee][j_arrivee] > 0)
                                                {
                                                    for(int g=0; g < 4; g++)
                                                    {
                                                        for(int h=0; h < 4; h++)
                                                        {
                                                            if(tab_pieces_blanches_eliminees[g][h] == 0)
                                                            {
                                                                tab_pieces_blanches_eliminees[g][h] = plateau[i_arrivee][j_arrivee];
                                                                //printf("%d", tab_pieces_blanches_eliminees[i][j]);
                                                                //printf("\n");
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }

                                                if(plateau[i_arrivee][j_arrivee] < 0)
                                                {
                                                    for(int g=0; g < 4; g++)
                                                    {
                                                        for(int h=0; h < 4; h++)
                                                        {
                                                            if(tab_pieces_noires_eliminees[g][h] == 0)
                                                            {
                                                                tab_pieces_noires_eliminees[g][h] = plateau[i_arrivee][j_arrivee];
                                                                //printf("%d", tab_pieces_noires_eliminees[i][j]);
                                                                //printf("\n");
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }



                                                if(valeur == 1 && i_arrivee == 0)
                                                {
                                                    plateau[i_arrivee][j_arrivee] = transfo_blanc(plateau,i_arrivee,j_arrivee);
                                                }

                                                else if(valeur == -1 && i_arrivee == 0)
                                                {
                                                    plateau[i_arrivee][j_arrivee] = transfo_noir(plateau,i_arrivee,j_arrivee);
                                                }

                                                else plateau[i_arrivee][j_arrivee] = valeur;

                                                /*
                                                if((i_depart+j_depart)%2 == 0)
                                                {
                                                    SDL_SetRenderDrawColor(renderer, gris_clair.r, gris_clair.g, gris_clair.b, gris_clair.a);
                                                    SDL_RenderFillRect(renderer,&blocs[i_depart][j_depart]);
                                                }
                                                if((i_depart+j_depart)%2 != 0)
                                                {
                                                    SDL_SetRenderDrawColor(renderer, gris_fonce.r, gris_fonce.g, gris_fonce.b, gris_fonce.a);
                                                    SDL_RenderFillRect(renderer,&blocs[i_depart][j_depart]);
                                                }
                                                */
                                                tour++;

                                            }


                                        }
                                    }
                                }
                            }

                            for(int i=0; i < 8; i++)
                            {
                                for(int j=0; j < 8; j++)
                                {
                                    blocs[i][j].x = 350 + (j* 100);
                                    blocs[i][j].y = 0 + (i* 100);
                                    blocs[i][j].w = blocs[i][j].h = 100;
                                    //SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
                                    //SDL_RenderFillRect(renderer,&blocs[i][j]);

                                    if((i+j)%2 == 0)
                                    {
                                        SDL_SetRenderDrawColor(renderer, gris_clair.r, gris_clair.g, gris_clair.b, gris_clair.a);
                                        SDL_RenderFillRect(renderer,&blocs[i][j]);
                                    }
                                    if((i+j)%2 != 0)
                                    {
                                        SDL_SetRenderDrawColor(renderer, gris_fonce.r, gris_fonce.g, gris_fonce.b, gris_fonce.a);
                                        SDL_RenderFillRect(renderer,&blocs[i][j]);
                                    }

                                }
                            }

                            //Affichage
                            for(int i=0; i < 8; i++)
                            {
                                for(int j=0; j < 8; j++)
                                {
                                    //printf("test");
                                    if(plateau[i][j] == -1) //Pion noir
                                    {
                                        SDL_Surface *surface_B_Pawn = NULL;
                                        surface_B_Pawn = SDL_LoadBMP("addons/pieces/B_Pawn.bmp");
                                        SDL_Texture* B_Pawn = SDL_CreateTextureFromSurface(renderer, surface_B_Pawn);
                                        SDL_RenderCopy(renderer, B_Pawn, NULL, &blocs[i][j]);

                                        SDL_FreeSurface(surface_B_Pawn);
                                        SDL_DestroyTexture(B_Pawn);
                                    }
                                    if(plateau[i][j] == 1)//Pion blanc
                                    {
                                        SDL_Surface *surface_W_Pawn = NULL;
                                        surface_W_Pawn = SDL_LoadBMP("addons/pieces/W_Pawn.bmp");
                                        SDL_Texture* W_Pawn = SDL_CreateTextureFromSurface(renderer, surface_W_Pawn);
                                        SDL_RenderCopy(renderer, W_Pawn, NULL, &blocs[i][j]);

                                        SDL_FreeSurface(surface_W_Pawn);
                                        SDL_DestroyTexture(W_Pawn);
                                    }
                                    if(plateau[i][j] == -2) //Fou noir
                                    {
                                        SDL_Surface *surface_B_Bishop = NULL;
                                        surface_B_Bishop = SDL_LoadBMP("addons/pieces/B_Bishop.bmp");
                                        SDL_Texture* B_Bishop = SDL_CreateTextureFromSurface(renderer, surface_B_Bishop);
                                        SDL_RenderCopy(renderer, B_Bishop, NULL, &blocs[i][j]);

                                        SDL_FreeSurface(surface_B_Bishop);
                                        SDL_DestroyTexture(B_Bishop);
                                    }
                                    if(plateau[i][j]== 2)//Fou blanc
                                    {
                                        SDL_Surface *surface_W_Bishop = NULL;
                                        surface_W_Bishop = SDL_LoadBMP("addons/pieces/W_Bishop.bmp");
                                        SDL_Texture* W_Bishop = SDL_CreateTextureFromSurface(renderer, surface_W_Bishop);
                                        SDL_RenderCopy(renderer, W_Bishop, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_Bishop);
                                        SDL_FreeSurface(surface_W_Bishop);
                                    }
                                    if(plateau[i][j] == -3) //Cavalier noir
                                    {
                                        SDL_Surface *surface_B_Knight = NULL;
                                        surface_B_Knight = SDL_LoadBMP("addons/pieces/B_Knight.bmp");
                                        SDL_Texture* B_Knight = SDL_CreateTextureFromSurface(renderer, surface_B_Knight);
                                        SDL_RenderCopy(renderer, B_Knight, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(B_Knight);
                                        SDL_FreeSurface(surface_B_Knight);
                                    }
                                    if(plateau[i][j] == 3)//Cavalier blanc
                                    {
                                        SDL_Surface *surface_W_Knight = NULL;
                                        surface_W_Knight = SDL_LoadBMP("addons/pieces/W_Knight.bmp");
                                        SDL_Texture* W_Knight = SDL_CreateTextureFromSurface(renderer, surface_W_Knight);
                                        SDL_RenderCopy(renderer, W_Knight, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_Knight);
                                        SDL_FreeSurface(surface_W_Knight);
                                    }
                                    if(plateau[i][j] == -4) //Tour noir
                                    {
                                        SDL_Surface *surface_B_Rook = NULL;
                                        surface_B_Rook = SDL_LoadBMP("addons/pieces/B_Rook.bmp");
                                        SDL_Texture* B_Rook = SDL_CreateTextureFromSurface(renderer, surface_B_Rook);
                                        SDL_RenderCopy(renderer, B_Rook, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(B_Rook);
                                        SDL_FreeSurface(surface_B_Rook);
                                    }
                                    if(plateau[i][j] == 4)//Tour blanc
                                    {
                                        SDL_Surface *surface_W_Rook = NULL;
                                        surface_W_Rook = SDL_LoadBMP("addons/pieces/W_Rook.bmp");
                                        SDL_Texture* W_Rook = SDL_CreateTextureFromSurface(renderer, surface_W_Rook);
                                        SDL_RenderCopy(renderer, W_Rook, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_Rook);
                                        SDL_FreeSurface(surface_W_Rook);
                                    }
                                    if(plateau[i][j] == -5) //Reine noir
                                    {
                                        SDL_Surface *surface_B_Queen = NULL;
                                        surface_B_Queen = SDL_LoadBMP("addons/pieces/B_Queen.bmp");
                                        SDL_Texture* B_Queen = SDL_CreateTextureFromSurface(renderer, surface_B_Queen);
                                        SDL_RenderCopy(renderer, B_Queen, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(B_Queen);
                                        SDL_FreeSurface(surface_B_Queen);
                                    }
                                    if(plateau[i][j] == 5)//Reine blanc
                                    {
                                        SDL_Surface *surface_W_Queen = NULL;
                                        surface_W_Queen = SDL_LoadBMP("addons/pieces/W_Queen.bmp");
                                        SDL_Texture* W_Queen = SDL_CreateTextureFromSurface(renderer, surface_W_Queen);
                                        SDL_RenderCopy(renderer, W_Queen, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_Queen);
                                        SDL_FreeSurface(surface_W_Queen);
                                    }
                                    if(plateau[i][j] == -6) //Roi noir
                                    {
                                        SDL_Surface *surface_B_King = NULL;
                                        surface_B_King = SDL_LoadBMP("addons/pieces/B_King.bmp");
                                        SDL_Texture* B_King = SDL_CreateTextureFromSurface(renderer, surface_B_King);
                                        SDL_RenderCopy(renderer, B_King, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(B_King);
                                        SDL_FreeSurface(surface_B_King);
                                    }
                                    if(plateau[i][j] == 6)//Roi blanc
                                    {
                                        SDL_Surface *surface_W_King = NULL;
                                        surface_W_King = SDL_LoadBMP("addons/pieces/W_King.bmp");
                                        SDL_Texture* W_King = SDL_CreateTextureFromSurface(renderer, surface_W_King);
                                        SDL_RenderCopy(renderer, W_King, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_King);
                                        SDL_FreeSurface(surface_W_King);
                                    }
                                    SDL_RenderPresent(renderer);

                                }
                            }

                            for(int g=0; g < 4; g++)
                            {
                                for(int h=0; h < 4; h++)
                                {
                                    rect_pieces_blanches_eliminees[g][h].x = h* 50;
                                    rect_pieces_blanches_eliminees[g][h].y = g* 50;
                                    rect_pieces_blanches_eliminees[g][h].w = rect_pieces_blanches_eliminees[g][h].h = 50;
                                    SDL_SetRenderDrawColor(renderer, blanc.r, blanc.g, blanc.b, blanc.a);
                                    SDL_RenderFillRect(renderer,&rect_pieces_blanches_eliminees[g][h]);
                                }
                            }

                            for(int k=0; k < 4; k++)
                            {
                                for(int l=0; l < 4; l++)
                                {
                                    rect_pieces_noires_eliminees[k][l].x = 1300 + l* 50;
                                    rect_pieces_noires_eliminees[k][l].y = k* 50;
                                    rect_pieces_noires_eliminees[k][l].w = rect_pieces_noires_eliminees[k][l].h = 50;
                                    SDL_SetRenderDrawColor(renderer, blanc.r, blanc.g, blanc.b, blanc.a);
                                    SDL_RenderFillRect(renderer,&rect_pieces_noires_eliminees[k][l]);
                                }
                            }

                            for(int i=0; i < 4; i++)
                            {
                                for(int j=0; j < 4; j++)
                                {
                                    //printf("Pieces Noires Eliminees\n");
                                    //printf("%d", tab_pieces_noires_eliminees[i][j]);

                                    if(tab_pieces_noires_eliminees[i][j] == -1) //Pion noir
                                    {
                                        SDL_Surface *surface_B_Pawn = NULL;
                                        surface_B_Pawn = SDL_LoadBMP("addons/pieces/B_Pawn.bmp");
                                        SDL_Texture* B_Pawn = SDL_CreateTextureFromSurface(renderer, surface_B_Pawn);
                                        SDL_RenderCopy(renderer, B_Pawn, NULL, &rect_pieces_noires_eliminees[i][j]);

                                        SDL_FreeSurface(surface_B_Pawn);
                                        SDL_DestroyTexture(B_Pawn);
                                    }
                                    if(tab_pieces_blanches_eliminees[i][j] == 1)//Pion blanc
                                    {
                                        SDL_Surface *surface_W_Pawn = NULL;
                                        surface_W_Pawn = SDL_LoadBMP("addons/pieces/W_Pawn.bmp");
                                        SDL_Texture* W_Pawn = SDL_CreateTextureFromSurface(renderer, surface_W_Pawn);
                                        SDL_RenderCopy(renderer, W_Pawn, NULL, &rect_pieces_blanches_eliminees[i][j]);

                                        SDL_FreeSurface(surface_W_Pawn);
                                        SDL_DestroyTexture(W_Pawn);
                                    }
                                    if(tab_pieces_noires_eliminees[i][j] == -2) //Fou noir
                                    {
                                        SDL_Surface *surface_B_Bishop = NULL;
                                        surface_B_Bishop = SDL_LoadBMP("addons/pieces/B_Bishop.bmp");
                                        SDL_Texture* B_Bishop = SDL_CreateTextureFromSurface(renderer, surface_B_Bishop);
                                        SDL_RenderCopy(renderer, B_Bishop, NULL, &rect_pieces_noires_eliminees[i][j]);

                                        SDL_FreeSurface(surface_B_Bishop);
                                        SDL_DestroyTexture(B_Bishop);
                                    }
                                    if(tab_pieces_blanches_eliminees[i][j]== 2)//Fou blanc
                                    {
                                        SDL_Surface *surface_W_Bishop = NULL;
                                        surface_W_Bishop = SDL_LoadBMP("addons/pieces/W_Bishop.bmp");
                                        SDL_Texture* W_Bishop = SDL_CreateTextureFromSurface(renderer, surface_W_Bishop);
                                        SDL_RenderCopy(renderer, W_Bishop, NULL, &rect_pieces_blanches_eliminees[i][j]);

                                        SDL_DestroyTexture(W_Bishop);
                                        SDL_FreeSurface(surface_W_Bishop);
                                    }
                                    if(tab_pieces_noires_eliminees[i][j] == -3) //Cavalier noir
                                    {
                                        SDL_Surface *surface_B_Knight = NULL;
                                        surface_B_Knight = SDL_LoadBMP("addons/pieces/B_Knight.bmp");
                                        SDL_Texture* B_Knight = SDL_CreateTextureFromSurface(renderer, surface_B_Knight);
                                        SDL_RenderCopy(renderer, B_Knight, NULL, &rect_pieces_noires_eliminees[i][j]);

                                        SDL_DestroyTexture(B_Knight);
                                        SDL_FreeSurface(surface_B_Knight);
                                    }
                                    if(tab_pieces_blanches_eliminees[i][j] == 3)//Cavalier blanc
                                    {
                                        SDL_Surface *surface_W_Knight = NULL;
                                        surface_W_Knight = SDL_LoadBMP("addons/pieces/W_Knight.bmp");
                                        SDL_Texture* W_Knight = SDL_CreateTextureFromSurface(renderer, surface_W_Knight);
                                        SDL_RenderCopy(renderer, W_Knight, NULL, &rect_pieces_blanches_eliminees[i][j]);

                                        SDL_DestroyTexture(W_Knight);
                                        SDL_FreeSurface(surface_W_Knight);
                                    }
                                    if(tab_pieces_noires_eliminees[i][j] == -4) //Tour noir
                                    {
                                        SDL_Surface *surface_B_Rook = NULL;
                                        surface_B_Rook = SDL_LoadBMP("addons/pieces/B_Rook.bmp");
                                        SDL_Texture* B_Rook = SDL_CreateTextureFromSurface(renderer, surface_B_Rook);
                                        SDL_RenderCopy(renderer, B_Rook, NULL, &rect_pieces_noires_eliminees[i][j]);

                                        SDL_DestroyTexture(B_Rook);
                                        SDL_FreeSurface(surface_B_Rook);
                                    }
                                    if(tab_pieces_blanches_eliminees[i][j] == 4)//Tour blanc
                                    {
                                        SDL_Surface *surface_W_Rook = NULL;
                                        surface_W_Rook = SDL_LoadBMP("addons/pieces/W_Rook.bmp");
                                        SDL_Texture* W_Rook = SDL_CreateTextureFromSurface(renderer, surface_W_Rook);
                                        SDL_RenderCopy(renderer, W_Rook, NULL, &rect_pieces_blanches_eliminees[i][j]);

                                        SDL_DestroyTexture(W_Rook);
                                        SDL_FreeSurface(surface_W_Rook);
                                    }
                                    if(tab_pieces_noires_eliminees[i][j] == -5) //Reine noir
                                    {
                                        SDL_Surface *surface_B_Queen = NULL;
                                        surface_B_Queen = SDL_LoadBMP("addons/pieces/B_Queen.bmp");
                                        SDL_Texture* B_Queen = SDL_CreateTextureFromSurface(renderer, surface_B_Queen);
                                        SDL_RenderCopy(renderer, B_Queen, NULL, &rect_pieces_noires_eliminees[i][j]);

                                        SDL_DestroyTexture(B_Queen);
                                        SDL_FreeSurface(surface_B_Queen);
                                    }
                                    if(tab_pieces_blanches_eliminees[i][j] == 5)//Reine blanc
                                    {
                                        SDL_Surface *surface_W_Queen = NULL;
                                        surface_W_Queen = SDL_LoadBMP("addons/pieces/W_Queen.bmp");
                                        SDL_Texture* W_Queen = SDL_CreateTextureFromSurface(renderer, surface_W_Queen);
                                        SDL_RenderCopy(renderer, W_Queen, NULL, &rect_pieces_blanches_eliminees[i][j]);

                                        SDL_DestroyTexture(W_Queen);
                                        SDL_FreeSurface(surface_W_Queen);
                                    }
                                    if(tab_pieces_noires_eliminees[i][j] == -6) //Roi noir
                                    {
                                        SDL_Surface *surface_B_King = NULL;
                                        surface_B_King = SDL_LoadBMP("addons/pieces/B_King.bmp");
                                        SDL_Texture* B_King = SDL_CreateTextureFromSurface(renderer, surface_B_King);
                                        SDL_RenderCopy(renderer, B_King, NULL, &rect_pieces_noires_eliminees[i][j]);

                                        SDL_DestroyTexture(B_King);
                                        SDL_FreeSurface(surface_B_King);
                                    }
                                    if(tab_pieces_blanches_eliminees[i][j] == 6)//Roi blanc
                                    {
                                        SDL_Surface *surface_W_King = NULL;
                                        surface_W_King = SDL_LoadBMP("addons/pieces/W_King.bmp");
                                        SDL_Texture* W_King = SDL_CreateTextureFromSurface(renderer, surface_W_King);
                                        SDL_RenderCopy(renderer, W_King, NULL, &rect_pieces_blanches_eliminees[i][j]);

                                        SDL_DestroyTexture(W_King);
                                        SDL_FreeSurface(surface_W_King);
                                    }
                                    SDL_RenderPresent(renderer);
                                }
                            }

                            //SDL_RenderPresent(renderer);





                            nb_click = 0;
                            //tour++;
                        }
                    }
                    /*

                    if(events.button.button == SDL_BUTTON_LEFT)
                    {
                        x = events.button.x;
                        y = events.button.y;

                        //printf("deuxi�me clic");

                        if((x > rect_zone_jeu.x) && (x < (rect_zone_jeu.x + rect_zone_jeu.w)) && (y > rect_zone_jeu.y) && (y < (rect_zone_jeu.y + rect_zone_jeu.h)))
                        {
                            for(int i=0; i < 8; i++)
                            {
                                for(int j=0; j < 8; j++)
                                {
                                    if((x > blocs[i][j].x) && (x < (blocs[i][j].x + blocs[i][j].w)) && (y > blocs[i][j].y) && (y < (blocs[i][j].y + blocs[i][j].h)))
                                    {
                                        printf("deuxi�me clic");
                                        printf(i,j);


                                        if(tableau_highlighting[i][j] == 1)
                                        {
                                            //Mouvement
                                            if(plateau[i][j] != 0)
                                            {
                                                //valeur_pieces_eliminees = plateau[i][j];
                                                //parcours du tableau pieces �limin�es
                                                //tab_pieces_blanches_eliminees[][] = valeur_pieces_eliminees;
                                                //plateau[i][j] = valeur;

                                            }
                                            if(plateau[i][j] == 0)
                                            {
                                                //plateau[i][j] = valeur;
                                            }
                                            //On passe � tour+1
                                            tour++;
                                        }
                                        if(tableau_highlight[i][j] == 0)
                                        {
                                            //Recommencer tour
                                            //Tour = Joueur
                                        }


                                    }
                                }
                            }
                        }
                    }
                    */

            }
        }
        if(tour %2 != 0)
        {
            printf("\nTour de l'IA\n");
            SDL_Delay(1000);//pause delay entre chaque tour de jeu

            int valeurIA, i_depart, j_depart;

            int *depart_IA;
            depart_IA = malloc(sizeof(int) * 4);

            test_deplacement = 0;
            IA_deplacement_possible = 0;

            while(test_deplacement <= 100)
            {
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        tableau_mouvement_IA[i][j]=0;
                    }
                }

                //Mouvement IA
                if(Couleur_Joueur=='B')
                {
                    printf("test IA_Noire\n");
                    depart_IA = IA_noir(plateau);
                    tableau_mouvement_IA = depart_IA[3];
                }
                if(Couleur_Joueur=='N')
                {
                    printf("test IA_blanche\n");
                    depart_IA = IA_blanc(plateau);
                    tableau_mouvement_IA = depart_IA[3];
                }
                //printf("%c", tableau_mouvement_IA[0][0]);
                valeurIA = depart_IA[0];
                i_depart = depart_IA[1];
                j_depart = depart_IA[2];
                printf("dans interface - valeur  :    %i\n", valeurIA);
                printf("dans interface - ligne   :    %i\n", i_depart);
                printf("dans interface - colonne :    %i\n", j_depart);

                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d", tableau_mouvement_IA[i][j]);
                        if(tableau_mouvement_IA[i][j]==1)
                        {
                            IA_deplacement_possible++;
                            //r�cup les position i-j de chaque 1
                        }
                    }
                    printf("\n");
                }
                if(IA_deplacement_possible!=0)
                {
                    int num_hasard;
                    int i_arrive;
                    int j_arrive;

                    int ligne_position_roi;
                    int colonne_position_roi;

                    int MouvEchec;

                    int **tableau_mouvement_temp;
                    tableau_mouvement_temp = malloc(sizeof(int *) *8);
                    for(int i=0; i<8; i++)
                    {
                        tableau_mouvement_temp[i] = malloc(sizeof(int)*8);
                    }

                    int *tableau_mouvement_lignes;
                    tableau_mouvement_lignes = malloc(sizeof(int) * 8);
                    for (int i=0;i<8;i++)
                    {
                        tableau_mouvement_lignes[i] = 0;
                    }

                    int *tableau_mouvement_colonnes;
                    tableau_mouvement_colonnes = malloc(sizeof(int) * 8);
                    for (int i=0;i<8;i++)
                    {
                        tableau_mouvement_colonnes[i] = 0;
                    }

                    int taille_tableau_mouvement = 0;

                    if(test_deplacement==100)
                    {
                        victoire(window, renderer, tmp, texture);
                        break;
                    }

                    for(int i=0; i < 8; i++)
                    {
                        for(int j=0; j < 8; j++)
                        {
                            if(tableau_mouvement_IA[i][j] == 1)
                            {
                                tableau_mouvement_lignes[taille_tableau_mouvement] = i;
                                tableau_mouvement_colonnes[taille_tableau_mouvement] = j;
                                taille_tableau_mouvement++;
                            }
                        }
                    }
                    //printf("taille : %i\n", taille_tableau_mouvement);
                    num_hasard = nombre_random(taille_tableau_mouvement);
                    //printf("random : %i\n", num_hasard);

                    i_arrive = tableau_mouvement_lignes[num_hasard];
                    j_arrive = tableau_mouvement_colonnes[num_hasard];
                    printf("i arrivée :  %i\n", i_arrive);
                    printf("j arrivée :  %i\n", j_arrive);

                    for(int i=0; i < 8; i++)
                    {
                        for(int j=0; j < 8; j++)
                        {
                            tableau_mouvement_temp[i][j] = plateau[i][j];
                        }
                    }

                    tableau_mouvement_temp[i_depart][j_depart] = 0;
                    tableau_mouvement_temp[i_arrive][j_arrive] = valeurIA;

                    if(Couleur_Joueur=='B')
                    {
                        tableau_mouvement_temp = verif_transformation_IA(tableau_mouvement_temp, 'N');//� retravailler car marche pas trop
                    }
                    if(Couleur_Joueur=='N')
                    {
                        tableau_mouvement_temp = verif_transformation_IA(tableau_mouvement_temp, 'B');
                    }

                    if(Couleur_Joueur=='B')// couleurIA = Noir
                    {
                        for(int a=0;a<8;a++)
                        {
                            for(int b=0;b<8;b++)
                            {
                                if(tableau_mouvement_IA[a][b]==-6)
                                {
                                    ligne_position_roi=a;
                                    colonne_position_roi=b;
                                }
                            }
                        }
                        printf("i_roi : %i\n", ligne_position_roi);
                        printf("j_roi : %i\n", colonne_position_roi);
                        MouvEchec = Etat_Echec(tableau_mouvement_temp, ligne_position_roi, colonne_position_roi, 'N', 'B');
                        //MouvEchec = 0;
                        printf("%i\n",MouvEchec);
                    }
                    if(Couleur_Joueur=='N')//couleurIA = Blanc
                    {
                        for(int a=0;a<8;a++)
                        {
                            for(int b=0;b<8;b++)
                            {
                                if(tableau_mouvement_IA[a][b]==6)
                                {
                                    ligne_position_roi=a;
                                    colonne_position_roi=b;
                                }
                            }
                        }
                        //MouvEchec = Etat_Echec(tableau_mouvement_temp, ligne_position_roi, colonne_position_roi, 'B', 'N');
                        MouvEchec = 0;
                        printf("%i\n",MouvEchec);
                    }

                    if(MouvEchec==0)
                    {
                        for(int i=0; i < 8; i++)
                        {
                            for(int j=0; j < 8; j++)
                            {
                                plateau[i][j] = tableau_mouvement_temp[i][j];
                            }
                        }
                        test_deplacement+=1000;//pour �tre s�r de sortir de la boucle 'while(test_deplacement<=100);'
                    }
                    if(MouvEchec==1)
                    {
                        for(int i=0; i < 8; i++)
                        {
                            for(int j=0; j < 8; j++)
                            {
                                tableau_mouvement_temp[i][j] = 0;
                            }
                        }
                        test_deplacement++;
                    }
                }
                if(IA_deplacement_possible==0)
                {
                    test_deplacement++;
                }
            }
            //Affichage
            for(int i=0; i < 8; i++)
            {
                for(int j=0; j < 8; j++)
                {
                    blocs[i][j].x = 350 + (j* 100);
                    blocs[i][j].y = 0 + (i* 100);
                    blocs[i][j].w = blocs[i][j].h = 100;
                    //SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
                    //SDL_RenderFillRect(renderer,&blocs[i][j]);

                    if((i+j)%2 == 0)
                    {
                        SDL_SetRenderDrawColor(renderer, gris_clair.r, gris_clair.g, gris_clair.b, gris_clair.a);
                        SDL_RenderFillRect(renderer,&blocs[i][j]);
                    }
                    if((i+j)%2 != 0)
                    {
                        SDL_SetRenderDrawColor(renderer, gris_fonce.r, gris_fonce.g, gris_fonce.b, gris_fonce.a);
                        SDL_RenderFillRect(renderer,&blocs[i][j]);
                    }

                }
            }
            for(int i=0; i < 8; i++)
            {
                for(int j=0; j < 8; j++)
                {
                    //printf("test");
                    if(plateau[i][j] == -1) //Pion noir
                    {
                        SDL_Surface *surface_B_Pawn = NULL;
                        surface_B_Pawn = SDL_LoadBMP("addons/pieces/B_Pawn.bmp");
                        SDL_Texture* B_Pawn = SDL_CreateTextureFromSurface(renderer, surface_B_Pawn);
                        SDL_RenderCopy(renderer, B_Pawn, NULL, &blocs[i][j]);

                        SDL_FreeSurface(surface_B_Pawn);
                        SDL_DestroyTexture(B_Pawn);
                    }
                    if(plateau[i][j] == 1)//Pion blanc
                    {
                        SDL_Surface *surface_W_Pawn = NULL;
                        surface_W_Pawn = SDL_LoadBMP("addons/pieces/W_Pawn.bmp");
                        SDL_Texture* W_Pawn = SDL_CreateTextureFromSurface(renderer, surface_W_Pawn);
                        SDL_RenderCopy(renderer, W_Pawn, NULL, &blocs[i][j]);

                        SDL_FreeSurface(surface_W_Pawn);
                        SDL_DestroyTexture(W_Pawn);
                    }
                    if(plateau[i][j] == -2) //Fou noir
                    {
                        SDL_Surface *surface_B_Bishop = NULL;
                        surface_B_Bishop = SDL_LoadBMP("addons/pieces/B_Bishop.bmp");
                        SDL_Texture* B_Bishop = SDL_CreateTextureFromSurface(renderer, surface_B_Bishop);
                        SDL_RenderCopy(renderer, B_Bishop, NULL, &blocs[i][j]);

                        SDL_FreeSurface(surface_B_Bishop);
                        SDL_DestroyTexture(B_Bishop);
                    }
                    if(plateau[i][j]== 2)//Fou blanc
                    {
                        SDL_Surface *surface_W_Bishop = NULL;
                        surface_W_Bishop = SDL_LoadBMP("addons/pieces/W_Bishop.bmp");
                        SDL_Texture* W_Bishop = SDL_CreateTextureFromSurface(renderer, surface_W_Bishop);
                        SDL_RenderCopy(renderer, W_Bishop, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(W_Bishop);
                        SDL_FreeSurface(surface_W_Bishop);
                    }
                    if(plateau[i][j] == -3) //Cavalier noir
                    {
                        SDL_Surface *surface_B_Knight = NULL;
                        surface_B_Knight = SDL_LoadBMP("addons/pieces/B_Knight.bmp");
                        SDL_Texture* B_Knight = SDL_CreateTextureFromSurface(renderer, surface_B_Knight);
                        SDL_RenderCopy(renderer, B_Knight, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(B_Knight);
                        SDL_FreeSurface(surface_B_Knight);
                    }
                    if(plateau[i][j] == 3)//Cavalier blanc
                    {
                        SDL_Surface *surface_W_Knight = NULL;
                        surface_W_Knight = SDL_LoadBMP("addons/pieces/W_Knight.bmp");
                        SDL_Texture* W_Knight = SDL_CreateTextureFromSurface(renderer, surface_W_Knight);
                        SDL_RenderCopy(renderer, W_Knight, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(W_Knight);
                        SDL_FreeSurface(surface_W_Knight);
                    }
                    if(plateau[i][j] == -4) //Tour noir
                    {
                        SDL_Surface *surface_B_Rook = NULL;
                        surface_B_Rook = SDL_LoadBMP("addons/pieces/B_Rook.bmp");
                        SDL_Texture* B_Rook = SDL_CreateTextureFromSurface(renderer, surface_B_Rook);
                        SDL_RenderCopy(renderer, B_Rook, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(B_Rook);
                        SDL_FreeSurface(surface_B_Rook);
                    }
                    if(plateau[i][j] == 4)//Tour blanc
                    {
                        SDL_Surface *surface_W_Rook = NULL;
                        surface_W_Rook = SDL_LoadBMP("addons/pieces/W_Rook.bmp");
                        SDL_Texture* W_Rook = SDL_CreateTextureFromSurface(renderer, surface_W_Rook);
                        SDL_RenderCopy(renderer, W_Rook, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(W_Rook);
                        SDL_FreeSurface(surface_W_Rook);
                    }
                    if(plateau[i][j] == -5) //Reine noir
                    {
                        SDL_Surface *surface_B_Queen = NULL;
                        surface_B_Queen = SDL_LoadBMP("addons/pieces/B_Queen.bmp");
                        SDL_Texture* B_Queen = SDL_CreateTextureFromSurface(renderer, surface_B_Queen);
                        SDL_RenderCopy(renderer, B_Queen, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(B_Queen);
                        SDL_FreeSurface(surface_B_Queen);
                    }
                    if(plateau[i][j] == 5)//Reine blanc
                    {
                        SDL_Surface *surface_W_Queen = NULL;
                        surface_W_Queen = SDL_LoadBMP("addons/pieces/W_Queen.bmp");
                        SDL_Texture* W_Queen = SDL_CreateTextureFromSurface(renderer, surface_W_Queen);
                        SDL_RenderCopy(renderer, W_Queen, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(W_Queen);
                        SDL_FreeSurface(surface_W_Queen);
                    }
                    if(plateau[i][j] == -6) //Roi noir
                    {
                        SDL_Surface *surface_B_King = NULL;
                        surface_B_King = SDL_LoadBMP("addons/pieces/B_King.bmp");
                        SDL_Texture* B_King = SDL_CreateTextureFromSurface(renderer, surface_B_King);
                        SDL_RenderCopy(renderer, B_King, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(B_King);
                        SDL_FreeSurface(surface_B_King);
                    }
                    if(plateau[i][j] == 6)//Roi blanc
                    {
                        SDL_Surface *surface_W_King = NULL;
                        surface_W_King = SDL_LoadBMP("addons/pieces/W_King.bmp");
                        SDL_Texture* W_King = SDL_CreateTextureFromSurface(renderer, surface_W_King);
                        SDL_RenderCopy(renderer, W_King, NULL, &blocs[i][j]);

                        SDL_DestroyTexture(W_King);
                        SDL_FreeSurface(surface_W_King);
                    }
                    SDL_RenderPresent(renderer);
                }
            }

            tour++;
        }
    }


    /*
    case SDL_MOUSEBUTTONDOWN:
        if(events.button.button == SDL_BUTTON_LEFT)
        {
            //Postion du clic
            x = events.button.x;
            y = events.button.y;

            if((x > rect_zone_abandon.x) && (x < (rect_zone_abandon.x + rect_zone_abandon.w)) && (y > rect_zone_abandon.y) && (y < (rect_zone_abandon.y + rect_zone_abandon.h)))
            {
            }
        }


    while (continuer)
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
                    //Postion du clic
                    x = events.button.x;
                    y = events.button.y;

                    if((x > rect_zone_jeu.x) && (x < (rect_zone_jeu.x + rect_zone_jeu.w)) && (y > rect_zone_jeu.y) && (y < (rect_zone_jeu.y + rect_zone_jeu.h)))
                    {
                        for(int i=0; i < 8; i++)
                        {
                            for(int j=0; j < 8; j++)
                            {
                                if((x > blocs[i][j].x) && (x < (blocs[i][j].x + blocs[i][j].w)) && (y > blocs[i][j].y) && (y < (blocs[i][j].y + blocs[i][j].h)))
                                {
                                    //case_depart = blocs[x][y];
                                    //Il faut aussi parcourir plateau pour r�cup�rer le type de piece sur le bloc
                                    valeur = plateau[i][j];
                                    if(valeur > 0)
                                    {
                                        couleur = "blanc";
                                    }
                                    if(valeur < 0)
                                    {
                                        couleur = "noir";
                                    }
                                    if(valeur != 0 && couleur == Couleur_Joueur);//v�rification qu'il y ai une pi�ce sur la case et qu'elle soit de la m�me couleur que le joueur
                                    {
                                        i_depart = i;
                                        j_depart = j;
                                        tableau_highligthing = Mouvements(plateau, i, j, couleur, Couleur_Joueur, valeur);
                                        affichage_higlight(tableau_highlighting);

                                    }

                                }

                            }
                        }
                    }
                }
                if(events.button.button == SDL_BUTTON_LEFT)
                {
                    x = events.button.x;
                    y = events.button.y;

                    if((x > rect_zone_jeu.x) && (x < (rect_zone_jeu.x + rect_zone_jeu.w)) && (y > rect_zone_jeu.y) && (y < (rect_zone_jeu.y + rect_zone_jeu.h)))
                    {
                        for(int i=0; i < 8; i++)
                        {
                            for(int j=0; j < 8; j++)
                            {
                                if((x > blocs[i][j].x) && (x < (blocs[i][j].x + blocs[i][j].w)) && (y > blocs[i][j].y) && (y < (blocs[i][j].y + blocs[i][j].h)))
                                {
                                    if(tableau_highlighting[i][j] == 1)
                                    {
                                        //Mouvement
                                        if(plateau[i][j] != 0)
                                        {
                                            valeur_pieces_eliminees = plateau[i][j];
                                            //parcours du tableau pieces �limin�es
                                            tableau[][] = valeur_pieces_eliminees;
                                            plateau[i][j] = valeur;
                                        }
                                        if(plateau[i][j] == 0)
                                        {
                                            plateau[i][j] = valeur;
                                        }
                                        //
                                        //Tour = IA
                                    }
                                    if(tableau_highlight[i][j] == 0)
                                    {
                                        //Recommencer tour
                                        //Tour = Joueur
                                    }
                                }
                            }
                        }
                    }
                }
        }
    }
    */


}

void menu(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture)
{
    int x = 0, y = 0;


    int **plateau;
    plateau = malloc(sizeof(int *) *8);
    for(int i=0; i<8; i++)
    {
        plateau[i] = malloc(sizeof(int)*8);
    }

    int joueur_blanc = 0;
    int joueur_noir = 1;

    SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL, *surface = NULL, *image_fond = NULL;

    image_fond = SDL_LoadBMP("addons/images/echecs.bmp");

    SDL_Color orange = {255, 127, 40, 255};
    SDL_Color noir = {0, 0, 0, 255};
    SDL_Color blanc = {255,255,255,255};
    SDL_Color rouge = {191, 59, 59, 255};

    //SDL_RenderClear(renderer);
/*
    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);

    SDL_Rect rect[50];
    size_t i = 0;
    for(i = 0; i < 50; i++)
    {
    rect[i].w = 50;
    rect[i].h = 50;
    rect[i].x = 100 * (i % 5) + 50 * ((i / 5) % 2);
    rect[i].y = 50 * (i / 5);
    }

    SDL_RenderFillRects(renderer, rect, 50);

*/

/*
    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderClear(renderer);
*/

    /*
    SDL_SetRenderTarget(renderer, texture); //La cible de rendu est maintenant texture.
    SDL_RenderCopy(renderer, tmp, NULL, NULL); //On copie tmp sur texture
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(renderer, NULL); //La cible de rendu est de nouveau le renderer.
    //On peut maintenant dessiner sur notre texture
    */
    SDL_Rect rectangle_image = {0, 0, 1500, 800};
    SDL_Texture* mon_image = SDL_CreateTextureFromSurface(renderer, image_fond);
    SDL_RenderCopy(renderer, mon_image, NULL, &rectangle_image);

    //SDL_DestroyTexture(mon_image);
    //SDL_FreeSurface(image_fond);

    //SDL_RenderClear(renderer);

    //SDL_SetRenderTarget(renderer, NULL);
    SDL_Rect rect_blanc = {550, 400, 100, 100};
    SDL_Rect rect_noir = {850, 400, 100, 100};
    /*
    SDL_Rect rect_rouge1 = {540, 390, 110, 110};
    SDL_Rect rect_rouge2 = {540, 390, 110, 110};

    SDL_SetRenderDrawColor(renderer, rouge.r, rouge.g, rouge.b, rouge.a);
    SDL_RenderFillRect(renderer, &rect_rouge1);
    SDL_RenderFillRect(renderer, &rect_rouge2);
    */
    SDL_SetRenderDrawColor(renderer, blanc.r, blanc.g, blanc.b, blanc.a);
    SDL_RenderFillRect(renderer, &rect_blanc);
    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
    SDL_RenderDrawRect(renderer, &rect_blanc);
    SDL_RenderFillRect(renderer, &rect_noir);



    SDL_RenderPresent(renderer);

/*
    SDL_Event event;
    int continuer = 1;
    while (continuer)
    {
    SDL_WaitEvent(&event);
    switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;

        }
    }

*/

    //Boucle infinie jusqu'� fermeture
    SDL_Event events;
    int continuer = 1;
    //bool quit = false;

    //int plateau_initialise;

    while (continuer)
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
                    if((x > rect_blanc.x) && (x < (rect_blanc.x + rect_blanc.w)) && (y > rect_blanc.y) && (y < (rect_blanc.y + rect_blanc.h)))
                    {
                        initialisation_blanc(plateau);
                        jeu(window, renderer, tmp, texture, plateau, 'B');
                        //initialisation_blanc(plateau);
                        //affichage(plateau, &window, &renderer);
                        //return 1;
                        //printf("bouton blanc click\n");
                        //continuer = 0;
                        //break;

                    }
                    if((x > rect_noir.x) && (x < (rect_noir.x + rect_noir.w)) && (y > rect_noir.y) && (y < (rect_noir.y + rect_noir.h)))
                    {
                        initialisation_noir(plateau);
                        jeu(window, renderer, tmp, texture, plateau, 'N');
                        //affichage(plateau, &window, &renderer);
                        //return 0;
                        //printf("bouton noir click\n");
                        //continuer = 0;
                        //break;

                    }
                }
        }


    }

}


void affichage_highlight(SDL_Renderer *renderer, int **tableau_highlighting, SDL_Rect **blocs)
{
    SDL_Color vert = {59,234,120,128};

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(tableau_highlighting[i][j] == 1)
            {
                //On recup�re soit la valeur blocs soit sa ligne et sa colonne
                SDL_SetRenderDrawColor(renderer, vert.r, vert.g, vert.b, vert.a);
                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                SDL_RenderFillRect(renderer, &blocs[i][j]);
            }
        }
    }
}


/*
void affichage_pieces_eliminees(int valeur)
{
    int a,b,c,i,j;

    int **tab_pieces_blanches_eliminees;
    tab_pieces_blanches_eliminees = malloc(sizeof(int *) *4);
    for (a=0;a<4;a++)
    {
        tab_pieces_blanches_eliminees[i] = malloc(sizeof(int)*4);
    }
    for (b=0;b<4;b++)
    {
        for (c=0;c<4;c++)
        {
            tab_pieces_blanches_eliminees[i][j]=0;
        }
    }
    if(valeur > 0)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(tab_pieces_blanches_eliminees[i][j] == 1)
                {
                    if(valeur == 1)//Pion blanc
                    {
                        SDL_RenderCopy(renderer, W_Pawn, NULL, &rect_pieces_blanches_eliminees[i][j]);
                    }
                    if(valeur == 2)//Fou blanc
                    {
                        SDL_RenderCopy(renderer, W_Bishop, NULL, &rect_pieces_blanches_eliminees[i][j]);
                    }
                    if(valeur == 3)//Cavalier blanc
                    {
                        SDL_RenderCopy(renderer, W_Knight, NULL, &rect_pieces_blanches_eliminees[i][j]);
                    }
                    if(valeur == 4)//Tour blanc
                    {
                        SDL_RenderCopy(renderer, W_Rook, NULL, &rect_pieces_blanches_eliminees[i][j]);
                    }
                    if(valeur == 5)//Reine blanc
                    {
                        SDL_RenderCopy(renderer, W_Queen, NULL, &rect_pieces_blanches_eliminees[i][j]);
                    }
                }
            }
        }
    }
}
*/





