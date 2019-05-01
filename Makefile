# Le compilateur à utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g -lMLV

# Les programmes principaux
# On donne le fichier cpp et la liste des fichiers .o qu'ils utilisent

main: main.cpp coord.o animal.o grille.o fonctionSimu.o
#testenscoord: testenscoord.cpp coord.o enscoord.o

# Les différents composants
# on donne le fichier cpp ainsi que la liste des fichiers .hpp dont ils dépendent
coord.o: coord.cpp coord.hpp
animal.o: animal.cpp animal.hpp
grille.o: grille.cpp grille.hpp
fonctionSimu.o: fonctionSimu.cpp fonctionSimu.hpp

# Pour faire le ménage
clean:
	rm -f main test *.o
