/* 
 * File:   C_LISTE_POISSON.cpp
 * Author: carrefour
 * 
 * Created on 17 octobre 2013, 10:47
 */


#include <vector>
#include <windows.h>
#include "glut.h"

#include "C_POISSON.h"
#include "C_LISTE_POISSON.h"

#define DEBUG_C_POISSON 0

#if DEBUG_C_POISSON >0
        #include <iostream>
        using namespace std;
#endif

        
using namespace std;
        
C_LISTE_POISSON::~C_LISTE_POISSON(){
    
#if DEBUG_C_SPHERE >0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif
    
}


void C_LISTE_POISSON::ajoute_poisson(C_POISSON* P_poisson){

#if DEBUG_C_SPHERE >0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif
    
    poissons.push_back(P_poisson);
    
}

void C_LISTE_POISSON::affiche_toi(){
    
#if DEBUG_C_SPHERE >1
    cerr << __PRETTY_FUNCTION__ << endl;
#endif
    
    for(auto& L_poisson : poissons) {
        
        L_poisson->Deplace_toi();
        
        float L_x;
        float L_y;
        float L_z;
        
        L_poisson->get_position(&L_x, &L_y, &L_z);
    }
    
}

void C_LISTE_POISSON::deplace_toi(){
    
#if DEBUG_C_SPHERE >0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif
    
    for(auto& L_poisson : poissons) {
        
        L_poisson->Deplace_toi();
        
        float L_x;
        float L_y;
        float L_z;
        
        L_poisson->get_position(&L_x, &L_y, &L_z);
        
        
        C_ESPACE::T_POSITION L_position;
        
        L_position = espace->ou_suis_je(L_x,L_y,L_z);
        
        if ((L_position & C_ESPACE::GAUCHE)== C_ESPACE::GAUCHE) L_position->retourne_toi_x();
        if ((L_position & C_ESPACE::DROITE)== C_ESPACE::DROITE) L_position->retourne_toi_x();
        
        if ((L_position & C_ESPACE::BAS)== C_ESPACE::BAS) L_position->retourne_toi_y();
        if ((L_position & C_ESPACE::HAUT)== C_ESPACE::HAUT) L_position->retourne_toi_y();
        
        if ((L_position & C_ESPACE::DEVANT)== C_ESPACE::DEVANT) L_position->retourne_toi_z();
        if ((L_position & C_ESPACE::DERRIERE)== C_ESPACE::DERRIERE) L_position->retourne_toi_z();
    }
    
}

void C_LISTE_POISSON::set_espace(C_ESPACE* un_espace){
    
    
    
}