#ifndef MOUVEMENTS_H_INCLUDED
#define MOUVEMENTS_H_INCLUDED

int **Mouvements(int **plateau, int ligne, int colonne, char Couleur, char Couleur_Joueur, int valeur);

int **Mouvements_Roi(int **plateau, int ligne, int colonne, char Couleur);
int **Mouvements_Reine(int **plateau, int ligne, int colonne, char Couleur);
int **Mouvements_Tour(int **plateau, int ligne, int colonne, char Couleur);
int **Mouvements_Cavalier(int **plateau, int ligne, int colonne, char Couleur);
int **Mouvements_Fou(int **plateau, int ligne, int colonne, char Couleur);
int **Mouvements_Pion(int **plateau, int ligne, int colonne, char Couleur, char Couleur_Joueur, int Deja_Bouge);


#endif //MOUVEMENTS_H_INCLUDED
