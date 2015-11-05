#include "jeton.hpp"
#include "fabriqueJeton.hpp"
#include "lexical.hpp"
#include <sstream>
#include <istream>
#include <fstream>
#include <iostream>
using namespace sysexp::builders;

void
representationJeton(std::istream & chaine) {
	const char* types[] = {"parentheseOuvrante", "parentheseFermante", "superieur", "inferieur",
					"operateurPlus", "operateurMoins", "operateurMul", "operateurDiv",
					"egal", "finExpression", "identificateur", "entier",
					"si", "non", "et", "alors", "separateur", "inconnu", "finFichier"};
	Lexical lexical = Lexical(chaine);
	Jeton jeton = lexical.suivant();
	while(!jeton.estFinFichier()){
		sysexp::type::Type typeJeton = jeton.lireType();
		std::cout << types[typeJeton] << std::endl;
		jeton = lexical.suivant();
	}
}

int
main(int argc, char* argv[] ){
    // Controle du nombre d'argument sur la ligne de commande
    if( argc > 1 )
    {
        std::cout << "Usage "
            << argv[0]
            << std::endl;
    }
    if( argc != 1 )
    {
        std::cerr << "Trop d'argument, tartine de pus !"
            << std::endl;
        return EXIT_FAILURE;
    }
	std::istringstream chaine("alors et si non");
	representationJeton(chaine);
	return EXIT_SUCCESS;
}

