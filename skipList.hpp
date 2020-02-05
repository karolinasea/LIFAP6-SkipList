#ifndef SKIP_LISTE_HPP
#define SKIP_LISTE_HPP
#include "cellule.hpp"

class SkipList {
public:
  Cellule *bidon;
  int taille;
  
  SkipList();
  ~SkipList();
  void afficher();
  void inserer(int valeur);
  bool search(int valeur); 
  
} ;

#endif
