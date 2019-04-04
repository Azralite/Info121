#include <iostream>
#include <cstdlib>


struct coord{
  int x;
  int y;
};

struct EnsCoord {
  //?
}

// On recopie les fonctions du td
coord creerCoord(int x, int y){
  coord res;
  res.x = x;
  res.y = y;
  return res;
}

int getX(coord a){
  return a.x;
}


int getY(coord a){
  return a.y;
}

bool egalCoord(coord a, coord b){
  if(a.x != b.x)
    return false;
  if(a.y != b.y)
    return false;
  else
    return true;
}


coord randomEC()
int main() {
  return 0;
}
