#ifndef INTERFACE_2_H_INCLUDED
#define INTERFACE_2_H_INCLUDED

void jeu_alt(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture, int **board, char player_color, TTF_Font* g_font);

void menu_alt(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture, TTF_Font* g_font);

//void affichage(int **plateau, SDL_Window *window, SDL_Renderer *renderer);

//void affichage_pieces_eliminees(int valeur);

//void affichage_higlight(SDL_Renderer *renderer,int **tableau_highlighting, SDL_Rect **blocs);


#endif // INTERFACE_2_H_INCLUDED