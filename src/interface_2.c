#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <stdint.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "interface_2.h"
#include "initialisation.h"
#include "IA.h"
#include "transformation.h"
#include "utils.h"
#include "etatechec.h"
#include "mouvements.h"

// Function to create a text texture
SDL_Texture* create_text(SDL_Renderer* renderer, const char* text, SDL_Color color, SDL_Rect* textRect, TTF_Font* g_font) {
    // Create text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(g_font, text, color);
    if (!textSurface) {
        printf("Failed to create text surface: %s\n", TTF_GetError());
        return NULL;
    }

    // Create texture from surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    if (!textTexture) {
        printf("Failed to create text texture: %s\n", SDL_GetError());
        return NULL;
    }

    // If textRect is provided, update it with the texture dimensions
    if (textRect) {
        int w, h;
        SDL_QueryTexture(textTexture, NULL, NULL, &w, &h);
        textRect->w = w;
        textRect->h = h;
    }

    return textTexture;
}

void abandonner_alt(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture, TTF_Font* g_font)
{
    // Create defeat window and renderer
    SDL_Window *window_defaite = NULL;
    SDL_Renderer *renderer_defaite = NULL;
    window_defaite = SDL_CreateWindow("Ecran defaite", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 375, SDL_WINDOW_SHOWN);
    renderer_defaite = SDL_CreateRenderer(window_defaite, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Load and display defeat image
    SDL_Surface *image_defaite = NULL;
    image_defaite = SDL_LoadBMP("src/addons/images/Defaite.bmp");

    SDL_Rect rectagle_image_defaite = {0, 0, 500, 375};
    SDL_Texture* mon_image = SDL_CreateTextureFromSurface(renderer_defaite, image_defaite);
    SDL_RenderCopy(renderer_defaite, mon_image, NULL, &rectagle_image_defaite);
    SDL_DestroyTexture(mon_image);
    SDL_FreeSurface(image_defaite);

    // Load and display restart button
    SDL_Surface *image_recommencer = NULL;
    image_recommencer = SDL_LoadBMP("src/addons/images/Recommencer.bmp");

    SDL_Rect rect_recommencer = {50, 200, 400, 100};
    SDL_Texture* mon_image_R = SDL_CreateTextureFromSurface(renderer_defaite, image_recommencer);
    SDL_RenderCopy(renderer_defaite, mon_image_R, NULL, &rect_recommencer);
    SDL_DestroyTexture(mon_image_R);
    SDL_FreeSurface(image_recommencer);

    SDL_RenderPresent(renderer_defaite);

    // Event loop for defeat screen
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
                        menu_alt(window, renderer, tmp, texture, g_font);
                        continuer = 0;
                    }
                }//if
        }//switch
    }//while
}

void jeu_alt(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture, int **board, char player_color, TTF_Font* g_font)
{
    SDL_Surface *surface_abandon = NULL;
    surface_abandon = SDL_LoadBMP("./src/addons/images/Abandonner.bmp");
    if (!surface_abandon) {
        printf("Failed to load Abandonner.bmp: %s\n", SDL_GetError());
    }

    // Initialize game colors
    SDL_Color orange = {255, 127, 40, 255};
    SDL_Color light_gray = {204, 209, 209, 255};
    SDL_Color dark_gray = {81, 90, 90, 255};
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color white = {255,255,255,255};

    // Define game board zones
    SDL_Rect rect_white_zone = {0, 0, 200, 600}; // Left side for captured white pieces
    SDL_Rect rect_black_zone = {1300, 0, 200, 600}; // Right side for captured black pieces
    SDL_Rect rect_game_zone = {350, 0, 800, 800}; // Main game board
    SDL_Rect rect_surrender_button = {1300, 700, 200, 100}; // Surrender button

    // Clear the renderer with white background
    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, black.a);

    // Draw the board zones
    SDL_RenderDrawRect(renderer, &rect_white_zone);
    SDL_RenderDrawRect(renderer, &rect_black_zone);
    SDL_RenderDrawRect(renderer, &rect_game_zone);
    SDL_RenderDrawRect(renderer, &rect_surrender_button);

    SDL_Rect rect_white_pieces_eliminated[4][4];

    //Zones Pieces EliminÈes
    //int g,h;
    for(int g=0; g < 4; g++)
    {
        for(int h=0; h < 4; h++)
        {
            rect_white_pieces_eliminated[g][h].x = h* 50;
            rect_white_pieces_eliminated[g][h].y = g* 50;
            rect_white_pieces_eliminated[g][h].w = rect_white_pieces_eliminated[g][h].h = 50;
            SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
            SDL_RenderFillRect(renderer,&rect_white_pieces_eliminated[g][h]);
        }
    }

    SDL_Rect rect_black_pieces_eliminated[4][4];

    //int k,l;
    for(int k=0; k < 4; k++)
    {
        for(int l=0; l < 4; l++)
        {
            rect_black_pieces_eliminated[k][l].x = 1300 + l* 50;
            rect_black_pieces_eliminated[k][l].y = k* 50;
            rect_black_pieces_eliminated[k][l].w = rect_black_pieces_eliminated[k][l].h = 50;
            SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
            SDL_RenderFillRect(renderer,&rect_black_pieces_eliminated[k][l]);
        }
    }

    SDL_Texture* abandon_texture = SDL_CreateTextureFromSurface(renderer, surface_abandon);
    SDL_FreeSurface(surface_abandon);

    SDL_RenderCopy(renderer, abandon_texture, NULL, &rect_surrender_button);

    // Draw the chess board
    SDL_Rect blocs[8][8];
    for(int i=0; i < 8; i++) {
        for(int j=0; j < 8; j++) {
            blocs[i][j].x = 350 + (j * 100);
            blocs[i][j].y = 0 + (i * 100);
            blocs[i][j].w = blocs[i][j].h = 100;

            if((i+j)%2 == 0) {
                SDL_SetRenderDrawColor(renderer, light_gray.r, light_gray.g, light_gray.b, light_gray.a);
                SDL_RenderFillRect(renderer, &blocs[i][j]);
            } else {
                SDL_SetRenderDrawColor(renderer, dark_gray.r, dark_gray.g, dark_gray.b, dark_gray.a);
                SDL_RenderFillRect(renderer, &blocs[i][j]);
            }
        }
    }

    // Load all piece textures first
    for(int i=0; i < 8; i++)
    {
        for(int j=0; j < 8; j++)
        {

            if(board[i][j] == -1) //Pion noir
            {
                SDL_Surface *surface_B_Pawn = NULL;
                //surface_B_Pawn = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/B_Pawn.bmp");
                surface_B_Pawn = IMG_Load("./src/addons/pieces/png/B_Pawn.png");
                SDL_Texture* B_Pawn = SDL_CreateTextureFromSurface(renderer, surface_B_Pawn);
                SDL_RenderCopy(renderer, B_Pawn, NULL, &blocs[i][j]);
                SDL_FreeSurface(surface_B_Pawn);
                SDL_DestroyTexture(B_Pawn);
            }
            if(board[i][j] == 1)//Pion blanc
            {
                SDL_Surface *surface_W_Pawn = NULL;
                //surface_W_Pawn = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/W_Pawn.bmp");
                surface_W_Pawn = IMG_Load("./src/addons/pieces/png/W_Pawn.png");
                SDL_Texture* W_Pawn = SDL_CreateTextureFromSurface(renderer, surface_W_Pawn);
                SDL_RenderCopy(renderer, W_Pawn, NULL, &blocs[i][j]);

                SDL_FreeSurface(surface_W_Pawn);
                SDL_DestroyTexture(W_Pawn);
            }
            if(board[i][j] == -2) //Fou noir
            {
                SDL_Surface *surface_B_Bishop = NULL;
                //surface_B_Bishop = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/B_Bishop.bmp");
                surface_B_Bishop = IMG_Load("./src/addons/pieces/png/B_Bishop.png");
                SDL_Texture* B_Bishop = SDL_CreateTextureFromSurface(renderer, surface_B_Bishop);
                SDL_RenderCopy(renderer, B_Bishop, NULL, &blocs[i][j]);

                SDL_FreeSurface(surface_B_Bishop);
                SDL_DestroyTexture(B_Bishop);
            }
            if(board[i][j]== 2)//Fou blanc
            {
                SDL_Surface *surface_W_Bishop = NULL;
                //surface_W_Bishop = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/W_Bishop.bmp");
                surface_W_Bishop = IMG_Load("./src/addons/pieces/png/W_Bishop.png");
                SDL_Texture* W_Bishop = SDL_CreateTextureFromSurface(renderer, surface_W_Bishop);
                SDL_RenderCopy(renderer, W_Bishop, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_Bishop);
                SDL_FreeSurface(surface_W_Bishop);
            }
            if(board[i][j] == -3) //Cavalier noir
            {
                SDL_Surface *surface_B_Knight = NULL;
                //surface_B_Knight = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/B_Knight.bmp");
                surface_B_Knight = IMG_Load("./src/addons/pieces/png/B_Knight.png");
                SDL_Texture* B_Knight = SDL_CreateTextureFromSurface(renderer, surface_B_Knight);
                SDL_RenderCopy(renderer, B_Knight, NULL, &blocs[i][j]);

                SDL_DestroyTexture(B_Knight);
                SDL_FreeSurface(surface_B_Knight);
            }
            if(board[i][j] == 3)//Cavalier blanc
            {
                SDL_Surface *surface_W_Knight = NULL;
                //surface_W_Knight = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/W_Knight.bmp");
                surface_W_Knight = IMG_Load("./src/addons/pieces/png/W_Knight.png");
                SDL_Texture* W_Knight = SDL_CreateTextureFromSurface(renderer, surface_W_Knight);
                SDL_RenderCopy(renderer, W_Knight, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_Knight);
                SDL_FreeSurface(surface_W_Knight);
            }
            if(board[i][j] == -4) //turn noir
            {
                SDL_Surface *surface_B_Rook = NULL;
                //surface_B_Rook = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/B_Rook.bmp");
                surface_B_Rook = IMG_Load("./src/addons/pieces/png/B_Rook.png");
                SDL_Texture* B_Rook = SDL_CreateTextureFromSurface(renderer, surface_B_Rook);
                SDL_RenderCopy(renderer, B_Rook, NULL, &blocs[i][j]);

                SDL_DestroyTexture(B_Rook);
                SDL_FreeSurface(surface_B_Rook);
            }
            if(board[i][j] == 4)//turn blanc
            {
                SDL_Surface *surface_W_Rook = NULL;
                //surface_W_Rook = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/W_Rook.bmp");
                surface_W_Rook = IMG_Load("./src/addons/pieces/png/W_Rook.png");
                SDL_Texture* W_Rook = SDL_CreateTextureFromSurface(renderer, surface_W_Rook);
                SDL_RenderCopy(renderer, W_Rook, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_Rook);
                SDL_FreeSurface(surface_W_Rook);
            }
            if(board[i][j] == -5) //Reine noir
            {
                SDL_Surface *surface_B_Queen = NULL;
                //surface_B_Queen = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/B_Queen.bmp");
                surface_B_Queen = IMG_Load("./src/addons/pieces/png/B_Queen.png");
                SDL_Texture* B_Queen = SDL_CreateTextureFromSurface(renderer, surface_B_Queen);
                SDL_RenderCopy(renderer, B_Queen, NULL, &blocs[i][j]);

                SDL_DestroyTexture(B_Queen);
                SDL_FreeSurface(surface_B_Queen);
            }
            if(board[i][j] == 5)//Reine blanc
            {
                SDL_Surface *surface_W_Queen = NULL;
                //surface_W_Queen = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/W_Queen.bmp");
                surface_W_Queen = IMG_Load("./src/addons/pieces/png/W_Queen.png");
                SDL_Texture* W_Queen = SDL_CreateTextureFromSurface(renderer, surface_W_Queen);
                SDL_RenderCopy(renderer, W_Queen, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_Queen);
                SDL_FreeSurface(surface_W_Queen);
            }
            if(board[i][j] == -6) //Roi noir
            {
                SDL_Surface *surface_B_King = NULL;
                //surface_B_King = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/B_King.bmp");
                surface_B_King = IMG_Load("./src/addons/pieces/png/B_King.png");
                SDL_Texture* B_King = SDL_CreateTextureFromSurface(renderer, surface_B_King);
                SDL_RenderCopy(renderer, B_King, NULL, &blocs[i][j]);

                SDL_DestroyTexture(B_King);
                SDL_FreeSurface(surface_B_King);
            }
            if(board[i][j] == 6)//Roi blanc
            {
                SDL_Surface *surface_W_King = NULL;
                //surface_W_King = SDL_LoadBMP("./src/addons/pieces/bmp_24bit/W_King.bmp");
                surface_W_King = IMG_Load("./src/addons/pieces/png/W_King.png");
                SDL_Texture* W_King = SDL_CreateTextureFromSurface(renderer, surface_W_King);
                SDL_RenderCopy(renderer, W_King, NULL, &blocs[i][j]);

                SDL_DestroyTexture(W_King);
                SDL_FreeSurface(surface_W_King);
            }
        }
    }

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Event loop
    SDL_Event events;
    int running = 1;

    // Captured white pieces
    int **board_white_pieces_eliminated;
    board_white_pieces_eliminated = malloc(sizeof(int *) *4);
    for (int a=0; a<4; a++)
    {
        board_white_pieces_eliminated[a] = malloc(sizeof(int)*4);
    }
    for (int b=0; b<4; b++)
    {
        for (int c=0; c<4; c++)
        {
            board_white_pieces_eliminated[b][c]=0;
        }
    }
    
    // Captured black pieces
    int **board_black_pieces_eliminated;
    board_black_pieces_eliminated = malloc(sizeof(int *) *4);
    for (int d=0;d<4;d++)
    {
        board_black_pieces_eliminated[d] = malloc(sizeof(int)*4);
    }
    for (int e=0;e<4;e++)
    {
        for (int f=0;f<4;f++)
        {
            board_black_pieces_eliminated[e][f]=0;
        }
    }

    // Highlights possible moves
    int i,j,k;
    int **board_highlighting;
    board_highlighting = malloc(sizeof(int *) *8);
    for (i=0;i<8;i++)
    {
        board_highlighting[i] = malloc(sizeof(int)*8);
    }
    for (j=0;j<8;j++)
    {
        for (k=0;k<8;k++)
        {
            board_highlighting[j][k]=0;
        }
    }
    
    // AI movement possibilities
    int l;
    int **board_IA_move;
    board_IA_move = malloc(sizeof(int *) *8);
    for (l=0;l<8;l++)
    {
        board_IA_move[l] = malloc(sizeof(int)*8);
    }

    int move_test;
    int IA_possible_move;

    int turn;

    if(player_color == 'B')
    {
        turn = 0;
    }
    if(player_color == 'N')
    {
        turn = 1;
    }

    int value;
    char color;

    int i_start;
    int j_start;

    int x,y;

    int checkMate;
    // checkMate = 1 -> fin

    checkMate = 0;

    int nb_click = 0;

    while (running && turn < 10) {
        SDL_Event event;

        if (turn % 2 == 0) {
            // ===== PLAYER TURN =====
            printf("Player Turn\n");

            bool playerMoved = false;
            while (!playerMoved && running) {
                SDL_WaitEvent(&event);

                if (event.type == SDL_QUIT ||
                   (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                    running = 0;
                    break;
                }

                if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;

                    // Check surrender button
                    if (x > rect_surrender_button.x && x < rect_surrender_button.x + rect_surrender_button.w &&
                        y > rect_surrender_button.y && y < rect_surrender_button.y + rect_surrender_button.h) {
                        abandonner_alt(window, renderer, tmp, texture, g_font);
                        running = 0;
                        break;
                    }

                    // Check board click
                    if (x > rect_game_zone.x && x < rect_game_zone.x + rect_game_zone.w &&
                        y > rect_game_zone.y && y < rect_game_zone.y + rect_game_zone.h) {

                        for (int i = 0; i < 8; i++) {
                            for (int j = 0; j < 8; j++) {
                                if (x > blocs[i][j].x && x < blocs[i][j].x + blocs[i][j].w &&
                                    y > blocs[i][j].y && y < blocs[i][j].y + blocs[i][j].h) {

                                    printf("You clicked on piece at i = %d and j = %d\n", i, j);
                                    playerMoved = true;
                                    break;
                                }
                            }
                            if (playerMoved) break;
                        }

                        if (!playerMoved)
                            printf("You misclick\n");
                    } else {
                        printf("You misclick\n");
                    }
                }
            }

            if (playerMoved) turn++; // Only after valid move
        } else {
            // ===== AI TURN =====
            printf("IA Turn\n");

            // Placeholder for AI logic
            SDL_Delay(1000);
            turn++;
        }

        SDL_Delay(10); // Just to be nice to the CPU
    }


    /*
    while(checkMate != 1 && running != 0)
    {
        SDL_Delay(1000);
        if(turn %2 == 0)
        {   
            // Player Turn
            SDL_WaitEvent(&events);
            switch(events.type)
            {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(events.button.button == SDL_BUTTON_LEFT)
                    {
                        // Position du clic
                        x = events.button.x;
                        y = events.button.y;
                        
                        if((x > rect_surrender_button.x) && (x < (rect_surrender_button.x + rect_surrender_button.w)) && (y > rect_surrender_button.y) && (y < (rect_surrender_button.y + rect_surrender_button.h)))
                        {
                            abandonner_alt(window, renderer, tmp, texture, g_font);
                            running = 0;
                        }

                        if(nb_click == 0)
                        {
                            if((x > rect_game_zone.x) && (x < (rect_game_zone.x + rect_game_zone.w)) && (y > rect_game_zone.y) && (y < (rect_game_zone.y + rect_game_zone.h)))
                            {
                                for(int i=0; i < 8; i++)
                                {
                                    for(int j=0; j < 8; j++)
                                    {
                                        if((x > blocs[i][j].x) && (x < (blocs[i][j].x + blocs[i][j].w)) && (y > blocs[i][j].y) && (y < (blocs[i][j].y + blocs[i][j].h)))
                                        {   
                                            printf("click on piece zone \n");
                                            //start_block = blocs[x][y];
                                            //Get the value of the piece on the block
                                            value = board[i][j];
                                            printf("%d\n", value);
                                            if(value > 0)
                                            {
                                                color = 'B';
                                            }
                                            if(value < 0)
                                            {
                                                color = 'N';
                                            }
                                            if(value != 0 && color == player_color)
                                            {
                                                i_start = i;
                                                j_start = j;

                                                printf("i_start = %d\n", i_start);
                                                printf("j_start = %d\n", j_start);

                                                // Call Mouvements with error checking
                                                int **temp_highlighting = Mouvements(board, i_start, j_start, color, player_color, value);
                                                if (temp_highlighting == NULL) {
                                                    printf("Mouvements returned NULL\n");
                                                    return;
                                                }

                                                printf("temp_highlighting = %d\n", temp_highlighting);

                                                
                                                SDL_Color green = {59,234,120,128};

                                                for(int i=0; i<8; i++)
                                                {
                                                    for(int j=0; j<8; j++)
                                                    {
                                                        //printf("%d", &board_highlighting[i][j]);
                                                        if(board_highlighting[i][j] == 1)
                                                        {
                                                            printf("%d\n", board_highlighting[i][j]);
                                                            //printf("%d\n", i);
                                                            //printf("%d\n", j);
                                                            //On recupère soit la valeur blocs soit sa ligne et sa colonne
                                                            SDL_SetRenderDrawColor(renderer, green.r, green.g, green.b, green.a);
                                                            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                                                            SDL_RenderFillRect(renderer, &blocs[i][j]);
                                                            SDL_RenderPresent(renderer);
                                                        }
                                                    }
                                                }
                                                
                                                nb_click = 1;
                                            }
                                        }//end if click on piece zone
                                    }
                                }
                            }//end if click on game zone
                        }//end events button left
                        else if(nb_click == 1)
                        {
                            printf("second click\n");

                            if((x > rect_game_zone.x) && (x < (rect_game_zone.x + rect_game_zone.w)) && (y > rect_game_zone.y) && (y < (rect_game_zone.y + rect_game_zone.h)))
                            {
                                for(int i=0; i < 8; i++)
                                {
                                    for(int j=0; j < 8; j++)
                                    {
                                        if((x > blocs[i][j].x) && (x < (blocs[i][j].x + blocs[i][j].w)) && (y > blocs[i][j].y) && (y < (blocs[i][j].y + blocs[i][j].h)))
                                        {
                                            int i_end = i;
                                            int j_end = j;

                                            if(board_highlighting[i][j] == 1)
                                            {
                                                board[i_start][j_start] = 0;

                                                if(board[i_end][j_end] > 0)
                                                {
                                                    for(int g=0; g < 4; g++)
                                                    {
                                                        for(int h=0; h < 4; h++)
                                                        {
                                                            if(board_white_pieces_eliminated[g][h] == 0)
                                                            {
                                                                board_white_pieces_eliminated[g][h] = board[i_end][j_end];
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }

                                                if(board[i_end][j_end] < 0)
                                                {
                                                    for(int g=0; g < 4; g++)
                                                    {
                                                        for(int h=0; h < 4; h++)
                                                        {
                                                            if(board_black_pieces_eliminated[g][h] == 0)
                                                            {
                                                                board_black_pieces_eliminated[g][h] = board[i_end][j_end];
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }   

                                                if(value == 1 && i_end == 0)
                                                {
                                                    board[i_end][j_end] = transfo_blanc(board, i_end, j_end);
                                                }

                                                else if(value == -1 && i_end == 0)
                                                {
                                                    board[i_end][j_end] = transfo_noir(board, i_end, j_end);
                                                }

                                                else board[i_end][j_end] = value;

                                                turn++;
                                            }
                                        }//end if click on piece zone
                                    }
                                }//end for loop
                            }//end if click on game zone

                            for(int i=0; i < 8; i++)
                            {
                                for(int j=0; j < 8; j++)
                                {
                                    blocs[i][j].x = 350 + (j* 100);
                                    blocs[i][j].y = 0 + (i* 100);
                                    blocs[i][j].w = blocs[i][j].h = 100;

                                    if((i+j)%2 == 0)
                                    {
                                        SDL_SetRenderDrawColor(renderer, light_gray.r, light_gray.g, light_gray.b, light_gray.a);
                                        SDL_RenderFillRect(renderer,&blocs[i][j]);
                                    }
                                    if((i+j)%2 != 0)
                                    {
                                        SDL_SetRenderDrawColor(renderer, dark_gray.r, dark_gray.g, dark_gray.b, dark_gray.a);
                                        SDL_RenderFillRect(renderer,&blocs[i][j]);
                                    }
                                }
                            }

                            //Display
                            for(int i=0; i < 8; i++)
                            {
                                for(int j=0; j < 8; j++)
                                {
                                    if(board[i][j] == -1) //Black Pawn
                                    {
                                        SDL_Surface *surface_B_Pawn = NULL;
                                        surface_B_Pawn = IMG_Load("./src/addons/pieces/png/B_Pawn.png");
                                        SDL_Texture* B_Pawn = SDL_CreateTextureFromSurface(renderer, surface_B_Pawn);
                                        SDL_RenderCopy(renderer, B_Pawn, NULL, &blocs[i][j]);

                                        SDL_FreeSurface(surface_B_Pawn);
                                        SDL_DestroyTexture(B_Pawn);
                                    }
                                    if(board[i][j] == 1)//White Pawn
                                    {
                                        SDL_Surface *surface_W_Pawn = NULL;
                                        surface_W_Pawn = IMG_Load("./src/addons/pieces/png/W_Pawn.png");
                                        SDL_Texture* W_Pawn = SDL_CreateTextureFromSurface(renderer, surface_W_Pawn);
                                        SDL_RenderCopy(renderer, W_Pawn, NULL, &blocs[i][j]);

                                        SDL_FreeSurface(surface_W_Pawn);
                                        SDL_DestroyTexture(W_Pawn);
                                    }
                                    if(board[i][j] == -2) //Black Bishop
                                    {
                                        SDL_Surface *surface_B_Bishop = NULL;
                                        surface_B_Bishop = IMG_Load("./src/addons/pieces/png/B_Bishop.png");
                                        SDL_Texture* B_Bishop = SDL_CreateTextureFromSurface(renderer, surface_B_Bishop);
                                        SDL_RenderCopy(renderer, B_Bishop, NULL, &blocs[i][j]);

                                        SDL_FreeSurface(surface_B_Bishop);
                                        SDL_DestroyTexture(B_Bishop);
                                    }
                                    if(board[i][j]== 2)//White Bishop
                                    {
                                        SDL_Surface *surface_W_Bishop = NULL;
                                        surface_W_Bishop = IMG_Load("./src/addons/pieces/png/W_Bishop.png");
                                        SDL_Texture* W_Bishop = SDL_CreateTextureFromSurface(renderer, surface_W_Bishop);
                                        SDL_RenderCopy(renderer, W_Bishop, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_Bishop);
                                        SDL_FreeSurface(surface_W_Bishop);
                                    }
                                    if(board[i][j] == -3) //Black Knight
                                    {
                                        SDL_Surface *surface_B_Knight = NULL;
                                        surface_B_Knight = IMG_Load("./src/addons/pieces/png/B_Knight.png");
                                        SDL_Texture* B_Knight = SDL_CreateTextureFromSurface(renderer, surface_B_Knight);
                                        SDL_RenderCopy(renderer, B_Knight, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(B_Knight);
                                        SDL_FreeSurface(surface_B_Knight);
                                    }
                                    if(board[i][j] == 3)//White Knight
                                    {
                                        SDL_Surface *surface_W_Knight = NULL;
                                        surface_W_Knight = IMG_Load("./src/addons/pieces/png/W_Knight.png");
                                        SDL_Texture* W_Knight = SDL_CreateTextureFromSurface(renderer, surface_W_Knight);
                                        SDL_RenderCopy(renderer, W_Knight, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_Knight);
                                        SDL_FreeSurface(surface_W_Knight);
                                    }
                                    if(board[i][j] == -4) //Black Rook
                                    {
                                        SDL_Surface *surface_B_Rook = NULL;
                                        surface_B_Rook = IMG_Load("./src/addons/pieces/png/B_Rook.png");
                                        SDL_Texture* B_Rook = SDL_CreateTextureFromSurface(renderer, surface_B_Rook);
                                        SDL_RenderCopy(renderer, B_Rook, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(B_Rook);
                                        SDL_FreeSurface(surface_B_Rook);
                                    }
                                    if(board[i][j] == 4)//White Rook
                                    {
                                        SDL_Surface *surface_W_Rook = NULL;
                                        surface_W_Rook = IMG_Load("./src/addons/pieces/png/W_Rook.png");
                                        SDL_Texture* W_Rook = SDL_CreateTextureFromSurface(renderer, surface_W_Rook);
                                        SDL_RenderCopy(renderer, W_Rook, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_Rook);
                                        SDL_FreeSurface(surface_W_Rook);
                                    }
                                    if(board[i][j] == -5) //Black Queen
                                    {
                                        SDL_Surface *surface_B_Queen = NULL;
                                        surface_B_Queen = IMG_Load("./src/addons/pieces/png/B_Queen.png");
                                        SDL_Texture* B_Queen = SDL_CreateTextureFromSurface(renderer, surface_B_Queen);
                                        SDL_RenderCopy(renderer, B_Queen, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(B_Queen);
                                        SDL_FreeSurface(surface_B_Queen);
                                    }
                                    if(board[i][j] == 5)//White Queen
                                    {
                                        SDL_Surface *surface_W_Queen = NULL;
                                        surface_W_Queen = IMG_Load("./src/addons/pieces/png/W_Queen.png");
                                        SDL_Texture* W_Queen = SDL_CreateTextureFromSurface(renderer, surface_W_Queen);
                                        SDL_RenderCopy(renderer, W_Queen, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(W_Queen);
                                        SDL_FreeSurface(surface_W_Queen);
                                    }
                                    if(board[i][j] == -6) //Black King
                                    {
                                        SDL_Surface *surface_B_King = NULL;
                                        surface_B_King = IMG_Load("./src/addons/pieces/png/B_King.png");
                                        SDL_Texture* B_King = SDL_CreateTextureFromSurface(renderer, surface_B_King);
                                        SDL_RenderCopy(renderer, B_King, NULL, &blocs[i][j]);

                                        SDL_DestroyTexture(B_King);
                                        SDL_FreeSurface(surface_B_King);
                                    }
                                    if(board[i][j] == 6)//White King
                                    {
                                        SDL_Surface *surface_W_King = NULL;
                                        surface_W_King = IMG_Load("./src/addons/pieces/png/W_King.png");
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
                                    rect_white_pieces_eliminated[g][h].x = h* 50;
                                    rect_white_pieces_eliminated[g][h].y = g* 50;
                                    rect_white_pieces_eliminated[g][h].w = rect_white_pieces_eliminated[g][h].h = 50;
                                    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
                                    SDL_RenderFillRect(renderer,&rect_white_pieces_eliminated[g][h]);
                                }
                            }

                            for(int k=0; k < 4; k++)
                            {
                                for(int l=0; l < 4; l++)
                                {
                                    rect_black_pieces_eliminated[k][l].x = 1300 + l* 50;
                                    rect_black_pieces_eliminated[k][l].y = k* 50;
                                    rect_black_pieces_eliminated[k][l].w = rect_black_pieces_eliminated[k][l].h = 50;
                                    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
                                    SDL_RenderFillRect(renderer,&rect_black_pieces_eliminated[k][l]);
                                }
                            }

                            for(int i=0; i < 4; i++)
                            {
                                for(int j=0; j < 4; j++)
                                {
                                    if(board_black_pieces_eliminated[i][j] == -1) //Black Pawn
                                    {
                                        SDL_Surface *surface_B_Pawn = NULL;
                                        surface_B_Pawn = IMG_Load("./src/addons/pieces/png/B_Pawn.png");
                                        SDL_Texture* B_Pawn = SDL_CreateTextureFromSurface(renderer, surface_B_Pawn);
                                        SDL_RenderCopy(renderer, B_Pawn, NULL, &rect_black_pieces_eliminated[i][j]);

                                        SDL_FreeSurface(surface_B_Pawn);
                                        SDL_DestroyTexture(B_Pawn);
                                    }
                                    if(board_white_pieces_eliminated[i][j] == 1)//White Pawn
                                    {
                                        SDL_Surface *surface_W_Pawn = NULL;
                                        surface_W_Pawn = IMG_Load("./src/addons/pieces/png/W_Pawn.png");
                                        SDL_Texture* W_Pawn = SDL_CreateTextureFromSurface(renderer, surface_W_Pawn);
                                        SDL_RenderCopy(renderer, W_Pawn, NULL, &rect_white_pieces_eliminated[i][j]);

                                        SDL_FreeSurface(surface_W_Pawn);
                                        SDL_DestroyTexture(W_Pawn);
                                    }
                                    if(board_black_pieces_eliminated[i][j] == -2) //Black Bishop
                                    {
                                        SDL_Surface *surface_B_Bishop = NULL;
                                        surface_B_Bishop = IMG_Load("./src/addons/pieces/png/B_Bishop.png");
                                        SDL_Texture* B_Bishop = SDL_CreateTextureFromSurface(renderer, surface_B_Bishop);
                                        SDL_RenderCopy(renderer, B_Bishop, NULL, &rect_black_pieces_eliminated[i][j]);

                                        SDL_FreeSurface(surface_B_Bishop);
                                        SDL_DestroyTexture(B_Bishop);
                                    }
                                    if(board_white_pieces_eliminated[i][j]== 2)//White Bishop
                                    {
                                        SDL_Surface *surface_W_Bishop = NULL;
                                        surface_W_Bishop = IMG_Load("./src/addons/pieces/png/W_Bishop.png");
                                        SDL_Texture* W_Bishop = SDL_CreateTextureFromSurface(renderer, surface_W_Bishop);
                                        SDL_RenderCopy(renderer, W_Bishop, NULL, &rect_white_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(W_Bishop);
                                        SDL_FreeSurface(surface_W_Bishop);
                                    }
                                    if(board_black_pieces_eliminated[i][j] == -3) //Black Knight
                                    {
                                        SDL_Surface *surface_B_Knight = NULL;
                                        surface_B_Knight = IMG_Load("./src/addons/pieces/png/B_Knight.png");
                                        SDL_Texture* B_Knight = SDL_CreateTextureFromSurface(renderer, surface_B_Knight);
                                        SDL_RenderCopy(renderer, B_Knight, NULL, &rect_black_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(B_Knight);
                                        SDL_FreeSurface(surface_B_Knight);
                                    }
                                    if(board_white_pieces_eliminated[i][j] == 3)//White Knight
                                    {
                                        SDL_Surface *surface_W_Knight = NULL;
                                        surface_W_Knight = IMG_Load("./src/addons/pieces/png/W_Knight.png");
                                        SDL_Texture* W_Knight = SDL_CreateTextureFromSurface(renderer, surface_W_Knight);
                                        SDL_RenderCopy(renderer, W_Knight, NULL, &rect_white_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(W_Knight);
                                        SDL_FreeSurface(surface_W_Knight);
                                    }
                                    if(board_black_pieces_eliminated[i][j] == -4) //Black Rook
                                    {
                                        SDL_Surface *surface_B_Rook = NULL;
                                        surface_B_Rook = IMG_Load("./src/addons/pieces/png/B_Rook.png");
                                        SDL_Texture* B_Rook = SDL_CreateTextureFromSurface(renderer, surface_B_Rook);
                                        SDL_RenderCopy(renderer, B_Rook, NULL, &rect_black_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(B_Rook);
                                        SDL_FreeSurface(surface_B_Rook);
                                    }
                                    if(board_white_pieces_eliminated[i][j] == 4)//White Rook
                                    {
                                        SDL_Surface *surface_W_Rook = NULL;
                                        surface_W_Rook = IMG_Load("./src/addons/pieces/png/W_Rook.png");
                                        SDL_Texture* W_Rook = SDL_CreateTextureFromSurface(renderer, surface_W_Rook);
                                        SDL_RenderCopy(renderer, W_Rook, NULL, &rect_white_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(W_Rook);
                                        SDL_FreeSurface(surface_W_Rook);
                                    }
                                    if(board_black_pieces_eliminated[i][j] == -5) //Black Queen
                                    {
                                        SDL_Surface *surface_B_Queen = NULL;
                                        surface_B_Queen = IMG_Load("./src/addons/pieces/png/B_Queen.png");
                                        SDL_Texture* B_Queen = SDL_CreateTextureFromSurface(renderer, surface_B_Queen);
                                        SDL_RenderCopy(renderer, B_Queen, NULL, &rect_black_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(B_Queen);
                                        SDL_FreeSurface(surface_B_Queen);
                                    }
                                    if(board_white_pieces_eliminated[i][j] == 5)//White Queen
                                    {
                                        SDL_Surface *surface_W_Queen = NULL;
                                        surface_W_Queen = IMG_Load("./src/addons/pieces/png/W_Queen.png");
                                        SDL_Texture* W_Queen = SDL_CreateTextureFromSurface(renderer, surface_W_Queen);
                                        SDL_RenderCopy(renderer, W_Queen, NULL, &rect_white_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(W_Queen);
                                        SDL_FreeSurface(surface_W_Queen);
                                    }
                                    if(board_black_pieces_eliminated[i][j] == -6) //Black King
                                    {
                                        SDL_Surface *surface_B_King = NULL;
                                        surface_B_King = IMG_Load("./src/addons/pieces/png/B_King.png");
                                        SDL_Texture* B_King = SDL_CreateTextureFromSurface(renderer, surface_B_King);
                                        SDL_RenderCopy(renderer, B_King, NULL, &rect_black_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(B_King);
                                        SDL_FreeSurface(surface_B_King);
                                    }
                                    if(board_white_pieces_eliminated[i][j] == 6)//White King
                                    {
                                        SDL_Surface *surface_W_King = NULL;
                                        surface_W_King = IMG_Load("./src/addons/pieces/png/W_King.png");
                                        SDL_Texture* W_King = SDL_CreateTextureFromSurface(renderer, surface_W_King);
                                        SDL_RenderCopy(renderer, W_King, NULL, &rect_white_pieces_eliminated[i][j]);

                                        SDL_DestroyTexture(W_King);
                                        SDL_FreeSurface(surface_W_King);
                                    }
                                    SDL_RenderPresent(renderer);
                                }
                            }
                            
                            nb_click = 0;
                        


                        }
                    }//end events button left
            }//end events
        }//end player turn (check if multiple of 2)
        if(turn % 2 != 0)
        {
            printf("\nIA Turn\n");
            SDL_Delay(100);
            turn++;
        }
    }//end game loop
    */

    // Cleanup
    if (board_highlighting != NULL) {
        for (int i = 0; i < 8; i++) {
            if (board_highlighting[i] != NULL) {
                free(board_highlighting[i]);
            }
        }
        free(board_highlighting);
    }

    if (board_IA_move != NULL) {
        for (int i = 0; i < 8; i++) {
            if (board_IA_move[i] != NULL) {
                free(board_IA_move[i]);
            }
        }
        free(board_IA_move);
    }

    if (board_white_pieces_eliminated != NULL) {
        for (int i = 0; i < 4; i++) {
            if (board_white_pieces_eliminated[i] != NULL) {
                free(board_white_pieces_eliminated[i]);
            }
        }
        free(board_white_pieces_eliminated);
    }

    if (board_black_pieces_eliminated != NULL) {
        for (int i = 0; i < 4; i++) {
            if (board_black_pieces_eliminated[i] != NULL) {
                free(board_black_pieces_eliminated[i]);
            }
        }
        free(board_black_pieces_eliminated);
    }
}

void menu_alt(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture, TTF_Font* g_font)
{   
    // Initialize menu variables
    int x = 0, y = 0;
    int **board;
    board = malloc(sizeof(int *) *8);
    for(int i=0; i<8; i++)
    {
        board[i] = malloc(sizeof(int)*8);
    }

    int joueur_blanc = 0;
    int joueur_noir = 1;

    // Load and display menu background
    SDL_Surface *display = NULL, *text = NULL, *background = NULL, *surface = NULL, *background_image = NULL;

    background_image = SDL_LoadBMP("src/addons/images/echecs.bmp");
    if (background_image == NULL) {
        printf("Failed to load echecs.bmp: %s\n", SDL_GetError());
        return;
    }
    
    // Create texture from background image
    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, background_image);
    if (!backgroundTexture) {
        printf("Failed to create background texture: %s\n", SDL_GetError());
        SDL_FreeSurface(background_image);
        return;
    }
    
    // Set up colors
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color black = {0, 0, 0, 255};

    // Clear the renderer
    SDL_RenderClear(renderer);

    // Render background image
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    // Clean up background resources
    SDL_DestroyTexture(backgroundTexture);
    SDL_FreeSurface(background_image);

    SDL_Rect white_rect = {550, 400, 100, 100};
    SDL_Rect black_rect = {850, 400, 100, 100};

    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
    SDL_RenderFillRect(renderer, &white_rect);
    SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, black.a);
    SDL_RenderDrawRect(renderer, &white_rect);
    SDL_RenderFillRect(renderer, &black_rect);

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Event loop
    SDL_Event events;
    int running = 1;

    while (running) {
        SDL_WaitEvent(&events);
        switch(events.type)
        {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(events.button.button == SDL_BUTTON_LEFT)
                {
                    x = events.button.x;
                    y = events.button.y;
                    if((x > white_rect.x) && (x < (white_rect.x + white_rect.w)) && (y > white_rect.y) && (y < (white_rect.y + white_rect.h)))
                    {
                        initialisation_blanc(board);
                        printf("bouton blanc click\n");
                        jeu_alt(window, renderer, tmp, texture, board, 'B', g_font);

                    }
                    if((x > black_rect.x) && (x < (black_rect.x + black_rect.w)) && (y > black_rect.y) && (y < (black_rect.y + black_rect.h)))
                    {
                        initialisation_noir(board);
                        printf("bouton noir click\n");
                        jeu_alt(window, renderer, tmp, texture, board, 'N', g_font);

                    }
                }
        }
    }
}