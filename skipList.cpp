#include "skipList.hpp"
#include "cellule.hpp"
#include <iostream>
#include <vector>

SkipList::SkipList() {
  bidon = new Cellule(); 
  taille = 0;
  //std::cout << "constructor, taille = " << taille << std::endl;
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
  std::cout << "taille de la liste = " << taille << std::endl;
  for(int i=0; i<=taille; i++) { //
  	std::cout << "afficher 1st loop i = " << i << std::endl;
  	// std::cout << "ATTENTION c->tab.size() = " << c->tab.size() << std::endl;
    for(int j=0; j<c->tab.size(); j++) {
      std::cout << "afficher 2nd loop j = " << j << std::endl;
      if(c == bidon && c->tab[j] != nullptr) {
      	std::cout << "La cellule bidon (i = " << i << "), bidon->tab[" << j << "] pointe sur cellule de valeur = " << c->tab[j]->val << std::endl;
      } else if(c == bidon && c->tab[j] == nullptr) {
      	std::cout << "La cellule bidon (i = " << i << "), bidon->tab[" << j << "] pointe sur nullptr" << std::endl;
      } else if(c->tab[j] != nullptr) {
        std::cout << "pour la cellule c numero " << i << " de val : " << c->val << ", c->tab[" << j << "] pointe sur cellule de valeur = " << c->tab[j]->val << std::endl;
      } else if(c->tab[j] == nullptr) {
        std::cout << "pour la cellule c numero " << i << " de val : " << c->val << ", c->tab[" << j << "] pointe sur nullptr " << std::endl;
      }
    }
    // if(c->tab[0] == bidon->tab[0]) std::cout << "c->tab[0] == bidon->tab[0] TRUE and bidon->tab[0]->tab.size() = " << bidon->tab[0]->tab.size() << std::endl;
    c = c->tab[0];
  } 
}

void SkipList::inserer(int valeur) {
  int t = 1;  
  if(std::rand()%2) t++;
  //t = t+std::rand()%6;
  std::cout << "pour insert valeur = " << valeur << ", t = " << t << std::endl;
  Cellule *nouvelle = new Cellule(t, valeur);
  // nouvelle->tab.resize(t);
	std::cout << "hello 1" << std::endl;

  int h = bidon->tab.size(); 
  std::vector<Cellule *> update;
  
// if(t > h) {
//   	std::cout << "hello 8" << std::endl;
//   	bidon->tab.resize(t);
//   	for(int i=h; i<t; i++) {
//   		bidon->tab[i] = nouvelle;
//   		std::cout << "hello 9" << std::endl;
//   	}
//   }

	Cellule *c = bidon;



	for(int i=bidon->tab.size()-1; i>=0; i--) {
	  	std::cout << "hello 4" << std::endl;
	    while((c->tab[i] != nullptr) && (c->tab[i]->val <= valeur)) {
	    	// std::cout << "hello 5" << std::endl;
	    	c = c->tab[i];
	    	// update.push_back(c);
	    	std::cout << "hello 6" << std::endl;
	    }
	    if(update.size() > 0) {
		    if(update.back() != c) {
		   		update.push_back(c);
		   		std::cout << "hello 6.6" << std::endl;
		   	}
	    } else if(update.size() == 0) {
		    std::cout << "hello 6.9" << std::endl;
		   	update.push_back(c);
	    }
	    //update.push_back(c);
	    std::cout << "hello 6.1" << std::endl;
	  }
	  
	// for(int i=bidon->tab.size()-1; i>=0; i--) {
	//   	std::cout << "hello 4" << std::endl;
	//     while((c->tab[i] != nullptr) && (c->tab[i]->val <= valeur)) {
	//     	// std::cout << "hello 5" << std::endl;
	//     	c = c->tab[i];
	//     	// update.push_back(c);
	//     	std::cout << "hello 6" << std::endl;
	//     }
	//     std::cout << "hello 6.1" << std::endl;
	//     // if(c == nullptr) {
	//     // 	std::cout << "NULL PTR i = " << i << std::endl;
	//     // }
	//     if(c->tab.size() < nouvelle->tab.size()) {
		    // if(update.size() > 0) {
		    // 	if(update.back() != c) {
		    // 		update.push_back(c);
		    // 		std::cout << "hello 6.6" << std::endl;
		    // 	}
		    // } else if(update.size() == 0) {
		    // 	std::cout << "hello 6.9" << std::endl;
		    // 	update.push_back(c);
		    // }
	// 	}
	//     //update.push_back(c);
	//     // std::cout << "hello 7" << std::endl;
	//   }

	  std::cout << "update.size() = " << update.size() << std::endl;
	  

	// if(t > h) {
	//   	std::cout << "hello 88" << std::endl;
	//   	for(int i=h; i<t; i++) {
	//   		bidon->tab.push_back(nouvelle);
	//   		nouvelle->tab[i] = nullptr;
	//   		std::cout << "hello 99" << std::endl;
	//   	}
 //  	}

  std::cout << "hello 7.5" << std::endl;

  // if(t > h) {
  // 	std::cout << "hello 8" << std::endl;
  // 	bidon->tab.resize(t);
  // 	for(int i=h; i<t; i++) {
  // 		bidon->tab[i] = nouvelle;
  // 		std::cout << "hello 9" << std::endl;
  // 	}
  // }
  
  // for(int i=0; i<bidon->tab.size(); i++) {
  // 	std::cout << "hello 10" << std::endl;
  // 	if(/*update[i]->tab.size()>i &&*/ (update[i]->tab[i] == nullptr || update[i]->tab[i]->val >= valeur)) {
  // 		std::cout << "hello 11" << std::endl;
  // 		nouvelle->tab[i] = update[i]->tab[i];
  // 		std::cout << "hello 12" << std::endl;
  // 		update[i]->tab[i] = nouvelle;
  // 	} 
  // 	std::cout << "hello 13" << std::endl;
  // }

  for(int i=0; i<update.size(); i++) {
  	std::cout << "hello 12 i = " << i << std::endl;
  	for(int j=update[i]->tab.size()-1; j>=0; j--) {
  		std::cout << "hello 12.12 j = " << j << std::endl;
  		if(j < nouvelle->tab.size()) {
  			if(update[i]->tab[j] == nullptr) {
  				std::cout << "nullptr " << std::endl;
  				nouvelle->tab[j] = update[i]->tab[j];
		  		update[i]->tab[j] = nouvelle;
  			} 
  				//else {
  			// 	std::cout << "update[i]->tab[j]->val = " << update[i]->tab[j]->val << std::endl;
  			// }
  			else if(update[i]->tab[j]->val > nouvelle->val || j == 0 || nouvelle->tab.size() >= update[i]->tab.size()) {
	  			nouvelle->tab[j] = update[i]->tab[j];
		  		update[i]->tab[j] = nouvelle;
		  		std::cout << "hello 11.11" << std::endl;
		  	}
  		}
  		std::cout << "hello 11" << std::endl;
  	}
  }

  if(t > h) {
	  	std::cout << "hello 88" << std::endl;
	  	for(int i=h; i<t; i++) {
	  		//bidon->tab.resize(t);
	  		bidon->tab.push_back(nouvelle);
	  		nouvelle->tab[i] = nullptr;
	  		std::cout << "hello 99" << std::endl;
	  	}
  	}

  taille++;
  std::cout << "fin inserer(), taille = " << taille << std::endl;
}

bool SkipList::search(int valeur) {
  Cellule *c = bidon;
  for(int i=bidon->tab.size()-1; i>0; i--) {
    while((c->tab[i] != nullptr) && (c->tab[i]->val <= valeur)) {
      if(c->tab[i]->val == valeur) return true;
      else c = c->tab[i];
    }
  }
	//if(c->tab[0]->val == valeur) return true;
	return false;
}







