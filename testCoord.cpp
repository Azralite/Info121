#include "coord.hpp"



#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ << "line " << __LINE__ <<": " << #test << std::endl


void testCreeCoord(){
  coord a = creerCoord(1,6);
  ASSERT(getX(a) == 1);
  ASSERT(getY(a) == 6);
}

void testEgalCoord(){
  coord a = creerCoord(1,6);
  coord b = creerCoord(1,6);
  coord c = creerCoord(2,6);
  ASSERT(egalCoord(a,b));
  ASSERT(!egalCoord(b,c));
}

void testTailleEC(){
  EnsCoord a = creeEC();
  ASSERT(tailleEC(a) == 0);
  coord b = creerCoord(1,6);
  ajouteEC(a,b);
  ASSERT(tailleEC(a) == 1);
}

void testCoordEC(){
  EnsCoord a = creeEC();
  coord b = creerCoord(1,6);
  ajouteEC(a,b);
  ASSERT(egalCoord(coordEC(a,0), creerCoord(1,6)));
}


int main(){
  testCreeCoord();
  testEgalCoord();
  testTailleEC();
  testCoordEC();
  return 0;
}
