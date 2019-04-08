#include <iostream>
#include <cstdlib>


struct coord{
  int x;
  int y;
};

struct EnsCoord {
  coord t[8];
  int taille;
};

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

void creeEC(EnsCoord &EC){
  EC.taille = 0; 
}

coord randomEC() //Utile ?
  
void ajouteEC(EnsCoord EC, coord c){
    EC.t[EC.taille] = c;
    EC.taille++;
}

EnsCoord trouverVoisins(coord a){
  EnsCoord EC = creeEC(EC);
  int x = getX(a);
  int y = getY(a);
  for(int i = -1; i <= 1; i++)
      for(int n = -1; n <= 1; n++)
        if(x+i != 0 || y+n != 0){
          EC.t[EC.taille] = {x+i, y+n};
          EC.taille++;
        }
  return EC;
}

int main() {
  return 0;
}
