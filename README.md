# Info121

**Bug réglé:**

* Erreur de segmentation dût à randomEC qui renvoyait un chiffre entre -1 et sizeGrid-1
* l'affichage du même tableau à chaque boucle dû à une simple inversion entre les 2 grilles passé en paramètres à copieGrille
* Les animaux ne se déplaçaient que en haut et vers la gauche dût à la fonction trouverVoisin


**Bug toujours present:**

* Problème avec repro des Lapin car le nb de lapin n'augmente jamais
