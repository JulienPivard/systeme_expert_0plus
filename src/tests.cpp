#include "jeton.hpp"
#include "fabriqueJeton.hpp"
#include "lexical.hpp"
#include "syntaxique.hpp"
#include <sstream>
#include <iostream>
#include <istream>
#include <fstream>

using namespace sysexp::builders;

void
representationJeton(std::istream & chaine) {
        const char* types[] = {"parentheseOuvrante", "parentheseFermante", "superieur", "inferieur",
                              "operateurPlus", "operateurMoins", "operateurMul", "operateurDiv",
                              "egal", "finExpression", "identificateur", "entier",
                              "si", "non", "et", "alors", "separateur", "inconnu", "finFichier", 
                              "supEgal", "infEgal", "different", "faitBool", "faitSymb", "faitEnt"};
        Lexical lexical = Lexical(chaine);
        Jeton jeton = lexical.suivant();
        while(!jeton.estFinFichier()){
                sysexp::type::Type typeJeton = jeton.lireType();
                std::cout << types[typeJeton] << "(" << jeton.lireRepresentation() << ")" << std::endl;
                jeton = lexical.suivant();
        }
}

int
main(int argc, char* argv[] ){
    if( argc > 1 ){
        std::cout << "Usage "
            << argv[0]
            << std::endl;
    }
    if( argc != 1 ){
        std::cerr << "Trop d'argument, tartine de pus !"
            << std::endl;
        return EXIT_FAILURE;
    }
        //"/home/sandy/Documents/M1/C++/projet-c/src/lorraine.txt"
        std::istringstream chaine("faits_booleens = caca, bite; \n\
                                   faits_symboliques = putite, puti, mia; \n\
                                   faits_entiers = rot, pet;\n\
                                   non caca; \n\
                                   bite; \n\
                                   putite = mia; \n\
                                   puti = intelligent;");
        //representationJeton(chaine);
        Lexical lexical = Lexical(chaine);
        Syntaxique syn(lexical);
        syn.parser();
        return EXIT_SUCCESS;
}
