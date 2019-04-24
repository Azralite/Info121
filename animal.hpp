#include "coord.hpp"

enum espece { vide, lapin, renard };

struct animal {coord c; espece b; int nour;};


//Variable global pour les renards
int FoodInit = 5;
int FoodLapin = 5;
int FoodReprod = 8;
int MaxFood = 10;
float ProbBirthRenard = 0.05;
//Variable global pour les lapins
float ProbBirthLapin = 0.3;
int MinFreeBirthLapin = 4;

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
* @return la nourriture de l'animal si c'est un renard
* @return 0 si ce n'est pas un renard
*/
int nourritureRenard(animal a);

/*@param [in] un animal
* @return true si l'animal est du type vide
* @return false sinon
*/
bool estVide(animal a);

/*@param une coordonnée
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
