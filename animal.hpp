#include "coord.hpp"

enum espece { vide, lapin, renard };

struct animal {coord c; espece b; int nour;};

animal creerAnimal(espece e, coord c);

coord coordAnimal(animal a);

espece especeAnimal(animal a);

int nourritureRenard(animal a);

bool estVide(animal a);

void changeCoordAnimal(coord c, animal &a);

void mangeAnimal(animal &a);

void faimRenard(animal &a);

bool mortRenard(animal a);

bool seReproduitAnimal(animal a, EnsCoord c);
