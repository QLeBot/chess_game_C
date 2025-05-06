#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

void jeu(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture, int **plateau, char Couleur_Joueur);

void menu(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *tmp, SDL_Texture *texture);

void affichage(int **plateau, SDL_Window *window, SDL_Renderer *renderer);

void affichage_pieces_eliminees(int valeur);

void affichage_higlight(SDL_Renderer *renderer,int **tableau_highlighting, SDL_Rect **blocs);


#endif // INTERFACE_H_INCLUDED
