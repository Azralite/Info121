#include "animal.hpp"

#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ << "line " << __LINE__ <<": " << #test << std::endl

void testCoordAnimal(){
  animal a = creerAnimal(lapin, creerCoord(5,6));
  ASSERT(egalCoord(coordAnimal(a), creerCoord(5,6)));
}

void testEspeceAnimal(){
  animal a = creerAnimal(lapin, creerCoord(5,6));
  ASSERT(especeAnimal(a) == lapin);
}

void testSexeAnimal() {
  animal a = creerAnimal(lapin, creerCoord(5,6));
  ASSERT(sexeAnimal(a) == 0 || sexeAnimal(a) == 1);
}

void testNourritureRenard() {
  animal a = creerAnimal(renard, creerCoord(2,3));
  animal b = creerAnimal(lapin, creerCoord(5,6));
  ASSERT(nourritureRenard(b) == 0);
  ASSERT(nourritureRenard(a) == 5);
}

void testEstVide(){
  animal a = creerAnimal(vide, creerCoord(2,1));
  animal b = creerAnimal(lapin, creerCoord(5,6));
  ASSERT(estVide(a));
  ASSERT(!estVide(b));
}

int main(){
  testCoordAnimal();
  testEspeceAnimal();
  testSexeAnimal();
  testNourritureRenard();
  testEstVide();
  return 0;
}
