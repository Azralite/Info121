#include "fonctionSimu.hpp"
#include "MLV.h"
#include <string>
#include <cmath>
#define cyan   MLV_rgba(0,175,255,255)
#define transp   MLV_rgba(0,0,0,0)
#define rouge   MLV_rgba(200,0,0,255)
#define blanc MLV_rgba(255,255,255,255)
#define gris MLV_rgba(119,136,153, 255)
#define noir MLV_rgba(0,0,0, 255)

int rayon = 12;

/**Desinne un cercle dans une image de la couleur indiqué
 *@param[in] une couleur
 *@return une image d'un rond
 **/
MLV_Image *drawCircle(MLV_Color couleur){
  MLV_Image *image = MLV_create_image(rayon*2,rayon*2);
  for(int x = 0; x < rayon*2; x++)
    for(int y = 0; y < rayon*2; y++)
      if((rayon-x)*(rayon-x) + (rayon-y)*(rayon-y) <= rayon*rayon)
        MLV_set_pixel_on_image(x, y, couleur, image);
      else
        MLV_set_pixel_on_image(x, y, transp, image);
  return image;
}

/**Transforme un entier en chaîne de caractère
 *@param[in] un entier
 *@return une chaîne de caractère
 **/
std::string intToString(int x){
  int x1 = x;
  int i = 0;
  while(x1/10 > 0){
    x1/=10;
    i++;
  }
  std::string s = "";
  while(i >= 0){
    int y = x/(pow(10,i));
    char c = '1' + y -1;
    x -= y * pow(10,i);
    s.push_back(c);
    i--;
  }
  return s;
}

/**Ecrit dans une image le nombre de lapin et de renard
 *@param[out] l'image sur laquelle on dessine
 *@param[in] un entier correspondant au nombre de lapin
 *@param[in] un entier correspondant au nombre de renard
 *@return une image
 **/
MLV_Image *nombreAnimal(MLV_Image *image, int nbLapin, int nbRenard){
  std::string l = "Nombre de lapin : " + intToString(nbLapin);
  std::string r = "Nombre de renard : " + intToString(nbRenard);
  const char* L = l.c_str();
  const char* R = r.c_str();
   MLV_Font* font = MLV_load_font( "arial.ttf" , 20 );
  MLV_draw_text_with_font_on_image(10, 10, L, font, noir, image);
  MLV_draw_text_with_font_on_image(10, 30, R, font, noir, image);
  return image;
}

/**Dessine la simulation du modèle proie/predateur sur une image
 *@param[in] une grille
 *@return une image
 **/
MLV_Image *imageSimulation(grille t){
  MLV_Image *imageRenard = drawCircle(rouge);
  MLV_Image *imageLapin = drawCircle(cyan);
  MLV_Image *image = MLV_create_image (rayon*2*20, rayon*2*20 + 80);
  for(int i = 0; i < rayon*2*20; i++)
    for(int n = 0; n < rayon*2*20 + 80; n++)
      MLV_set_pixel_on_image(i,n, blanc, image);

  for(int i = 0; i < 20; i++)
    for(int n = 0; n < 20; n++)
      if(especeAnimal(t[i][n]) == lapin)
        MLV_draw_image_on_image(imageLapin, image, i*rayon*2,80+ n*rayon*2);
      else if(especeAnimal(t[i][n]) == renard)
        MLV_draw_image_on_image(imageRenard, image, i*rayon*2, 80+n*rayon*2);
  return image;
}

int main(){
  srand (time(NULL));
  grille g, sauv;
  initialiseGrille(g);
  mlv::window_t foxWar = mlv::window_t( "FoxWar", "essai", rayon*2*20, rayon*2*20 + 80);
  MLV_clear_window (blanc);
  MLV_Image *image;
  while(nbLapin(g) > 0 && nbRenard(g) > 0){
    image = imageSimulation(g);
    image = nombreAnimal(image, nbLapin(g), nbRenard(g));
    MLV_draw_image(image, 0, 0);
    foxWar.update();
    grilleVide(sauv);
    updateGrille(g, sauv);
    //afficheGrille(sauv,0,0);
    copieGrille(g, sauv);
    //afficheGrille(g,nbLapin(g),nbRenard(g));
    MLV_wait_milliseconds(250);
  }
}
