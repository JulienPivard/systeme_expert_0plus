#include <cstdlib>

#include "FaitEntier.hpp"

namespace sysexp
{
    namespace modele
    {

        FaitEntier::FaitEntier( const std::string & nom, const long int & valeur ):
            FaitAbstrait( nom ),
            valeur_( valeur )
        {
        }

        const long int &
        FaitEntier::lireValeur() const
        {
            return valeur_;
        }

    }
}
