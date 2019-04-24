#include "grille.hpp"

const int gridSize = 20

/*@param un entiers
 *renvoie aléatoirement un entiers entre 0 et val
 */
int hasard(int val);

/*@param [in] un animal
* @param [in] les cases vides autour
* @return true si l'animal se reproduit
* @return false sinon
*/
bool seReproduitAnimal(animal a, EnsCoord c);

void initialiseGrille(const grille &g);

void verifieGrille(const grille &g);

EnsCoord voisinsEspece(const grille &g, coord c, espece e);

/*@param[in] une grille
 *@param[in] une espece
 *@return l'ensemble des coordonnées de l'espèce dans la grille
 */
ensCoord toutEspece(grille g, espece e);

/*@param[in/out] une grille
 *@param[in/out] un renard
 *renvoie true si un lapin est voisins de r et mets à jour ces coordonnées. Renvoie false si non
 */
bool attaqueRenard(grille g, animal r);
/*@param[in] une grille
 *@param[in/out] une grille
 *Deplace tous les lapins de g1 dans g2 de manière aléatoire
 */
void deplaceTousLapins(grille g1, grille g2);

/*@param[in] une grille
 *@param[in/out] une grille
 *Deplace tous les renards de g1 dans g2 de manière aléatoire
 */
void deplaceTousRenards(grille g1, grille g2);

/*@param[in] une grille
 *@param[in] une espece
 *@param[in/out] une grille
 *Deplace tous les animaux de l'espece e de g1 dans g2 de manière aléatoire

void deplaceTousEspece(grille g1, espece e, grille g2); // en remplacement potentiel de deplaceTousRenards et deplaceTousLapins
*/

/*@param[in] une grille
 *@param[in/out] une grille
 *mets à jour la grille g1 et la renvoie dans g2
 */
void updateGrille(grille g1, grille g2);

/*@param[in] une grille
 *affiche la grille
 */
void afficheGrille(grille g);
