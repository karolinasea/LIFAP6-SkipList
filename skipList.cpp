#include "skipList.hpp"
#include "cellule.hpp"
#include <iostream>
#include <vector>

SkipList::SkipList() {
  bidon = nullptr; //or something else ??
  taille = 0;
}

SkipList::~SkipList() {
  for(int i=0; i<taille; i++) {
    Cellule *c = bidon->tab[0];
    delete bidon;
    bidon = c;
  }
}

void SkipList::afficher() {
  Cellule *c = bidon;
  for(int i=0; i<0; i++) {
    for(int j=c->tab.size(); j>0; j--) {
      if(c->tab[i] != nullptr) {
        std::cout << "c->tab[" << j << "]->val = " << c->tab[j]->val << std::endl;
      }
    }
    c = c->tab[0];
  } 
  /*while(c != nullptr) {
    std::cout << c->val << std::endl;
    c = c->tab[0];
  }*/
}

void SkipList::inserer(int valeur) {
  std::vector<Cellule *> update;
  Cellule *nouvelle = new Cellule;
  nouvelle->val = valeur;
  //determine hauteur with pile ou face

  Cellule *c = bidon;
  // for(int i=bidon->tab.size()-1; i>0; i--) {
  //   if(c->tab[i]->val != nullptr && c->tab[i]->val <= valeur) {
  //      update->push_back(c->tab[i]);
  //      c = c->tab[i];
  //   }
  // }
  
  for(int i=bidon->tab.size()-1; i>0; i--) {
    while((c->tab[i] != nullptr) && (c->tab[i]->val <= valeur)) c = c->tab[i];
    update[i] = c;
  }
}

bool SkipList::search(int valeur) {
  Cellule *c = bidon;
  for(int i=bidon->tab.size()-1; i>0; i--)
    while((c->tab[i] != nullptr) && (c->tab[i]->val <= valeur))
      c = c->tab[i];
  if(c->tab[0]->val == valeur)
    return true;
  else
    return false;
}







