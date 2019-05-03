#include "fonctionSimu.hpp"
#include "MLV.h"
#define cyan   MLV_rgba(0,175,255,255)
#define transp   MLV_rgba(0,0,0,0)
#define rouge   MLV_rgba(200,0,0,255)
using namespace mlv;
//int gridSize = 20;

MLV_Image *imageSimulation(grille t){
  MLV_Image *image = MLV_create_image (10*20, 10*20);
  for(int i = 0; i < 20; i++)
    for(int n = 0; n < 20; n++)
      if(especeAnimal(t[i][n]) == lapin)
        MLV_draw_circle_on_image(5+i*10, 5+n*10, 5, cyan, image);
      else if(especeAnimal(t[i][n]) == renard)
        MLV_draw_circle_on_image(5+i*10, 5+n*10, 5, rouge, image);
  return image;
}

void afficheCoord(coord a){
  int x = getX(a);
  int y = getY(a);
  std::cout << x << " " << y << '\n';
}

int main(){
  srand (time(NULL));
  grille g, sauv;
  initialiseGrille(g);
  mlv::window_t foxWar = mlv::window_t( "FoxWar", "essai", 200, 200 );
  while(nbLapin(g) > 0 && nbRenard(g) > 0){
    MLV_Image *image = imageSimulation(g);
    MLV_draw_image(image, 0, 0);
    foxWar.update();
    grilleVide(sauv);
    updateGrille(g, sauv);
    afficheGrille(sauv,0,0);
    copieGrille(g, sauv);
    afficheGrille(g,nbLapin(g),nbRenard(g));
    sleep(1);
  }
  /*grille test;
  initialiseGrille(test);
  afficheGrille(test,1000,1000);
  EnsCoord a = creeEC();
  a = toutEspece(test, lapin);
  int lon = tailleEC(a);
  std::cout << lon << '\n';
  coord b;
  for(int i = 0; i < lon; i++){
    b = coordEC(a,i);

  }*/
}
