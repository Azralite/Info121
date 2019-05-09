#include "animal.hpp"

const int gridSize = 40;

using grille = animal [gridSize][gridSize];

/** Initialise une grille grille
 *@param[out] g une grille
 **/
void grilleVide(grille g);

/** Copie la grille g1 dans g2
 *@param[in] g1 la grille à copier
 *@param[out] g2 la grille dans laquelle on effectue la copie
 **/
void copieGrille(grille g1, grille newG);

/** Renvoie l'animal au coordonnée indiqué
 *@param[in] g une grille
 *@param[in] c coordonnée de l'animal concerné
 *@return l'animal au coordonnée c
 **/
animal getAnimal(grille g, coord c);

/** Place l'animal au bon endroit dans la grille
 *@param[out] la grille g dans laquelle on place l'animal
 *@param[in] a l'animal à placer dans la grille
 **/
void setAnimal(grille g,  animal a);
