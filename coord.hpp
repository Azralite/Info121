#include <iostream>
#include <cstdlib>
//#include <unistd.h>
const int TAILLE = 20;

struct coord{
  int x;
  int y;
};

struct EnsCoord {
   coord tab[TAILLE*TAILLE];
   int taille;
};

/*@param [in] un x
* @param [in] un y
* @return une coordonnée
*/
coord creerCoord(int x, int y);

/*@param [in] une coordonée
* @return le x
*/
int getX(coord a);

/*@param [in] une coordonée
* @return le y
*/
int getY(coord a);

/*@param [in] deux coordonnées
* @return true si les deux coordonnées sont les mêmes
* @return false si les deux coordonées sont différentes
*/
bool egalCoord(coord a, coord b);

/*@param [in] deux entiers
* @return le plus grand des deux
*/
int max (int a, int b);

/*@param [in] deux entiers
* @return le plus petit des deux
*/
int min(int a, int b);

/*@return un ensemble de coordonnée de taille 0
*/
EnsCoord creeEC();

/*@param [in] un ensemble de coordonnées
* @param [in] une coordonnée
* ajoute la coordonnée a l'ensemble
*/
void ajouteEC(EnsCoord &a, coord c);

/*@param [in] un ensemble de coordonnées
*@return une coordonnée aléatoire d'un ensemble
*/
coord randomEC(EnsCoord c);

/*@param [in]un ensemble de coordonnées
* @return la taille de l'ensemble
*/
int tailleEC(EnsCoord a);

/*@param [in] un ensemble de coordonnée et un entier
 *@return la a-ième coordonnée de l'ensemble
*/
coord coordEC(EnsCoord e, int a);

/*@param[in/out] un ensemble de coordonées
 *@param une coordonée
 *supprimer la coordonée dans l'ensemble des coordonée
 */
void supprimeCoord(EnsCoord &ec, coord c);

/*@param [in] une coordonnée
* @return l'ensemble des coordonnées des cases voisine
*/
EnsCoord trouverVoisin(coord c);
