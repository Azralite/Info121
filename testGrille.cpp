#include "grille.hpp"

#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ << "line " << __LINE__ <<": " << #test << std::endl

void testGrilleVide(){
  grille g;
  grilleVide(g);
  for(int i = 0; i < gridSize; i++)
    for(int n = 0; n < gridSize; n++)
      ASSERT(especeAnimal(g[i][n]) == vide);
}

void testGetAnimal(){
  grille g;
  grilleVide(g);
  g[10][20] = creerAnimal(lapin, creerCoord(10,20));
  g[15][26] = creerAnimal(renard, creerCoord(15, 26));
  animal a = getAnimal(g, creerCoord(10, 20));
  ASSERT(especeAnimal(a) == lapin);
  ASSERT(egalCoord(coordAnimal(a), creerCoord(10, 20)));
  animal b = getAnimal(g, creerCoord(15,26));
  ASSERT(especeAnimal(b) == renard);
  ASSERT(egalCoord(coordAnimal(b), creerCoord(15,26)));
  ASSERT(egalCoord(coordAnimal(a), creerCoord(10,20)));
  ASSERT(egalCoord(coordAnimal(b), creerCoord(15,26)));
}

void testSetAnimal(){
  animal a = creerAnimal(lapin, creerCoord(10, 20));
  animal b = creerAnimal(renard, creerCoord(15, 26));

  grille g;
  grilleVide(g);

  setAnimal(g, a);
  setAnimal(g, b);

  animal a1 = getAnimal(g, creerCoord(10, 20));
  animal b1 = getAnimal(g, creerCoord(15,26));

  ASSERT(especeAnimal(a1) == lapin);
  ASSERT(especeAnimal(b1) == renard);
  ASSERT(egalCoord(coordAnimal(a1), creerCoord(10,20)));
  ASSERT(egalCoord(coordAnimal(b1), creerCoord(15,26)));
}

int main(){
  testGrilleVide();
  testGetAnimal();
  testSetAnimal();
}
