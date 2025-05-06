#ifndef TRANSFORMATIONPION_H_INCLUDED
#define TRANSFORMATIONPION_H_INCLUDED


int transfo_blanc(int **plateau, int ligne, int colonne);
int transfo_noir(int **plateau, int ligne, int colonne);
void transformation_pion(int **plateau, int ligne, int colonne, char Couleur);
void verif_transformation_pion_possible(int **plateau, int ligne, int colonne, char Couleur, char Couleur_Joueur);
int **verif_transformation_IA(int **plateau, char CouleurIA);


#endif //TRANSFORMATIONPION_H_INCLUDED
