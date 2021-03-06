#include "coord.hpp"

enum espece { vide, lapin, renard };


//On prend 0 pour les Hommes et 1 pour les Femmes
struct animal {coord c; espece b; int nour; int sexe; int vie;};




/*@param [in] une espece
* @param [in] une coordonnée
* @return un animal
*/
animal creerAnimal(espece e, coord c);

/*@param [in] un animal
* @return la coordonnée de l'animal
*/
coord coordAnimal(animal a);

/*@param [in] un animal
* @return l'espece de l'animal
*/
espece especeAnimal(animal a);

/*@param [in] un animal
* @return 0 ou 1  en fonction de son sexe
*/
int sexeAnimal(animal a);
/*@param [in] un animal
* @return la nourriture de l'animal si c'est un renard
* @return 0 si ce n'est pas un renard
*/
int nourritureRenard(animal a);

/*@param [in] un animal
* @return true si l'animal est du type vide
* @return false sinon
*/
bool estVide(animal a);

/*@param [in] une coordonnée
* @param [in/out] un animal
*/
void changeCoordAnimal(coord c, animal &a);

/* @param [in/out] un animal
* modifie sa quantité de nourriture
*/
void mangeAnimal(animal &a);

/*@param [in/out] un animal
* reduit sa nourriture de 1 si c'est un renard
* ne fait rien si ce n'est pas un renard
*/
void faimRenard(animal &a);

/*@param [in] un animal
* @return true si l'animal est un renard et que ca nourriture est < 0
* @return false sinon
*/
bool mortRenard(animal a);

/*@param[in] un animal
*@return true si le lapin est mort false sinon
*/
bool mortLapin(animal a);

/*@param[in/out] un animal
* met à jour son age
*/
void updateAgeAnimal(animal &a);
