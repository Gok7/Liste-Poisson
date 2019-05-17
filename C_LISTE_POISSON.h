/* 
 * File:   C_LISTE_POISSON.h
 * Author: carrefour
 *
 * Created on 17 octobre 2013, 10:47
 */

#ifndef C_LISTE_POISSON_H
#define	C_LISTE_POISSON_H
#include "C_POISSON.h"
#include <vector>
#include "C_POISSON.h"
#include "C_ESPACE.h"
using namespace std;

class C_LISTE_POISSON {
public:
    
    virtual ~C_LISTE_POISSON();
    void ajoute_poisson(C_POISSON* un_poisson);
    void affiche_toi();
    void deplace_toi();
    void set_espace(C_ESPACE* un_espace);
    
protected:

    C_ESPACE* espace = nullptr;
    vector<C_POISSON*> poissons;
};

#endif	/* C_LISTE_POISSON_H */

