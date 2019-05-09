#include "grille.hpp"


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

/*@param[out] une grille g
 *place aléatoirement les animaux selon les variables globales pour initialiser la grille
 */
void initialiseGrille( grille g);

/*@param[in] une grille g
 *@param[in] la coordonnée de l'animal dont on cherche les voisins
 *@param[in] l'espece de l'animal voisin recherché
 *@return l'ensemble des coordonnées des cases voisines contenant l'expèce recherché
 */
EnsCoord voisinsEspece(const grille &g, coord c, espece e);

/*@param[in] une grille
 *@param[in] une espece
 *@return l'ensemble des coordonnées des animaux de cette espèce dans la grille
 */
EnsCoord toutEspece(grille g, espece e);

/*@param[in/out] une grille
 *@param[in/out] un renard
 *renvoie true si un lapin est voisins de r et mets à jour ces coordonnées. Renvoie false si non
 */
bool attaqueRenard(grille g, animal &r);

/*@param[in] l'ancienne grille g1
 *@param[in/out] la nouvelle grille
 *Deplace tous les lapins de g1 dans newG de manière aléatoire
 */
void deplaceTousLapins(grille g1, grille newG);

/*@param[in] l'ancienne grille g1
 *@param[in/out] la nouvelle grille g2
 *Deplace tous les renards de g1 dans g2 de manière aléatoire
 */
void deplaceTousRenards(grille g1, grille g2);

/*@param[in] l'ancienne grille g1
 *@param[in/out] une grille
 *mets à jour la grille g1 et la renvoie dans g2
 */
void updateGrille(grille g1, grille g2);

/*@param[in] une grille g
 *@return le nombre de lapin dans la grille
 */
int nbLapin(grille g);

/*@param[in] une grille g
 *@return le nombre de renard dans la grille
 */
int nbRenard(grille g);

/*@param[in] une grille
 *affiche la grille
 */
void afficheGrille(grille g, int l, int r);
