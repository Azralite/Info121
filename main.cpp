#include "fonctionSimu.hpp"
#include "MLV.h"
#define cyan   MLV_rgba(0,175,255,255)
#define transp   MLV_rgba(0,0,0,0)
#define rouge   MLV_rgba(200,0,0,255)
#define blanc MLV_rgba(255,255,255,255)
#define gris MLV_rgba(119,136,153, 255)
using namespace mlv;

//int gridSize = 20;
int rayon = 10;

MLV_Image *drawCircle(MLV_Color couleur){
  MLV_Image *image = MLV_create_image(rayon*2,rayon*2);
  for(int x = 0; x < rayon*2; x++)
    for(int y = 0; y < rayon*2; y++)
      if((rayon*2-x)*(rayon*2-x) + (rayon*2-y)*(rayon*2-y) <= rayon*rayon*4)
        MLV_set_pixel_on_image(x, y, couleur, image);
      else
        MLV_set_pixel_on_image(x, y, transp, image);
  return image;
}

MLV_Image *imageSimulation(grille t){
  MLV_Image *imageRenard = drawCircle(rouge);
  MLV_Image *imageLapin = drawCircle(cyan);
  MLV_Image *image = MLV_create_image (rayon*2*20, rayon*2*20);
  for(int i = 0; i < rayon*2*20; i++)
    for(int n = 0; n < rayon*2*20; n++)
      MLV_set_pixel_on_image(i,n, blanc, image);

  for(int i = 0; i < 20; i++)
    for(int n = 0; n < 20; n++)
      if(especeAnimal(t[i][n]) == lapin)
        MLV_draw_image_on_image(imageLapin, image, i*rayon*2, n*rayon*2);
      else if(especeAnimal(t[i][n]) == renard)
        MLV_draw_image_on_image(imageRenard, image, i*rayon*2, n*rayon*2);
  return image;
}

int main(){
  srand (time(NULL));
  grille g, sauv;
  initialiseGrille(g);
  mlv::window_t foxWar = mlv::window_t( "FoxWar", "essai", 20*rayon*2 + 20*2*rayon, 20*rayon*2 + 20*2*rayon);
  MLV_clear_window (gris);
  while(nbLapin(g) > 0 && nbRenard(g) > 0){
    MLV_draw_image(imageSimulation(g), 20*rayon, 10*rayon);
    //MLV_draw_image(graph(nbLapin(g), nbRenard(g)), 20*rayon, 20*rayon*2+10)
    foxWar.update();
    grilleVide(sauv);
    updateGrille(g, sauv);
    afficheGrille(sauv,0,0);
    copieGrille(g, sauv);
    afficheGrille(g,nbLapin(g),nbRenard(g));
    MLV_wait_milliseconds(500);
  }
}
