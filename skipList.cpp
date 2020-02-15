#include "skipList.hpp"
#include "cellule.hpp"
#include <iostream>
#include <vector>

SkipList::SkipList() {
  bidon = new Cellule(); 
  taille = 0;
  //std::cout << "taille = " << taille << std::endl;
  //std::cout << "bidon->tab.size() = " << bidon->tab.size() << std::endl;
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
  for(int i=0; i<taille; i++) {
  	// std::cout << "afficher 1st loop i = " << i << std::endl;
    for(int j=c->tab.size()-1; j>0; j--) {
      // std::cout << "afficher 2nd loop j = " << j << std::endl;
      if(c->tab[j] != nullptr) {
        std::cout << "pour la cellule c numero " << i << ", c->tab[" << j << "] pointe sur cellule de valeur = " << c->tab[j]->val << std::endl;
      } else if(c->tab[j] == nullptr) {
        std::cout << "pour la cellule c numero " << i << ", c->tab[" << j << "] pointe sur nullptr " << std::endl;
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
  std::srand(std::time(nullptr));

  int t = 1;  
  if(std::rand()%2) t++;
  // std::cout << "t = " << t << std::endl;
  Cellule *nouvelle = new Cellule(t, valeur);

  //si la hauteur de la nouvelle cellule depasse la hauteur de la cellule bidon

  int h = bidon->tab.size(); 
  // std::cout << "h = " << h << std::endl << std::endl;
  // if(t>h) std::vector<Cellule *> update(t);
  // else 
  std::vector<Cellule *> update;
  
  
  // std::cout << "toto" << std::flush;
  // Cellule *c = bidon;
  // for(int i=bidon->tab.size()-1; i>0; i--) {
  //   if(c->tab[i]->val != nullptr && c->tab[i]->val <= valeur) {
  //      update->push_back(c->tab[i]);
  //      c = c->tab[i];
  //   }
  // }

  // std::cout << "bidon->tab.size() = " << bidon->tab.size() << std::endl;
  Cellule *c = bidon;

  // if (c->tab[0] == nullptr) {
  // 	std::cout << "NULLPTR  " << std::endl;
  // }
  // if (c->val == 0) {
  // 	std::cout << "c->tab[i]->val == 0 " << std::endl;
  // }

	// for(int i=bidon->tab.size()-1; i>0; i--) {
	//     std::cout << "hello  " << std::endl;
	    // while((c->tab[i] != nullptr) && (c->val <= valeur)) {
	    // 	c = c->tab[i];
	    //   	std::cout << "c->tab[i]->val " << c->tab[i]->val << std::endl;
	    // }
	 //    update.push_back(c);
	 //    std::cout << "hello 3 " << std::endl;
  // }


  for(int i=bidon->tab.size()-1; i>=0; i--) {
    // std::cout << "i =  " << i << std::endl;
    while((c->tab[i] != nullptr) && (c->tab[i]->val <= valeur)) {
    	// std::cout << ".. i =  " << i << std::endl;
    	c = c->tab[i];
      	// std::cout << "c->tab[i]->val " << c->tab[i]->val << std::endl;
    }
    update.push_back(c);
    // std::cout << "hello 3 " << std::endl;
  }

  if(t > h) {
  	bidon->tab.resize(t);
  	for(int i=h; i<t; i++) {
  		bidon->tab[i] = nouvelle;
  	}
  }
  // std::cout << "apres check if t>h, h = " << bidon->tab.size() << std::endl << std::endl;

  // std::cout << "update.size() = " << update.size() << std::endl;
  // std::cout << "nouvelle->tab.size() = " << nouvelle->tab.size() << std::endl;

  // std::cout << "nouvelle->afficher() = " << std::endl;
  // nouvelle->afficher();
  // std::cout << "bidon->afficher() = " << std::endl;
  // bidon->afficher();
  // nouvelle->tab[0] = update[0];
  // std::cout << "update[0]->val = " << update[0]->val << std::endl;
  
  // std::cout << "update[0]->afficher() = " << std::endl;
  // update[0]->afficher();
  // std::cout << "nouvelle->tab[0]->afficher() = " << std::endl;
  // nouvelle->tab[0]->afficher();


	// std::cout << "talle de update should be is = " << update.size() << std::endl;
	// if(update[0]->val == 0) {
	// 	std::cout << "0000000000 " << std::endl;
	// }
	// if(update[0]->tab[0] == nullptr) {
	// 	std::cout << "NULLPTR " << std::endl;
	// } 
  
  for(int i=0; i<update.size(); i++) {
  	// std::cout << "last loop i = " << i << std::endl;
  	// std::cout << "update[i]->tab[i]->val = " << update[i]->tab[i]->val << std::endl;
  	if(update[i]->tab[i] == nullptr || update[i]->tab[i]->val >= valeur) {
  		// std::cout << "if with i = " << i << std::endl;
  		nouvelle->tab[i] = update[i]->tab[i];
  		update[i]->tab[i] = nouvelle;
  	} 
  }
 
  taille++;
  std::cout << "fin" << std::endl;
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







