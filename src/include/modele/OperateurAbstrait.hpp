/**
 * @file OperateurAbstrait.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier OperateurAbstrait.cpp.
 * Définit la classe abstraite OperateurAbstrait.
 * */


#ifndef operateurabstrait_hpp
#define operateurabstrait_hpp

#include <cstdlib>

#include "ValeurAbstraite.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
        * @brief Un squelette d'opérateur abstrait pour les expressions entière.
        *
        * Déclaration de la classe OperateurAbstrait.
        * */
        class OperateurAbstrait : public ValeurAbstraite
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] filsGauche
                 * Le @ref filsGauche_ de l'opération.
                 * @param[in] filsDroit
                 * Le @ref filsDroit_ de l'opération.
                 *
                 * @see ValeurAbstraite
                 * */
                OperateurAbstrait( const ValeurAbstraite::PtrValeur & filsGauche, const ValeurAbstraite::PtrValeur & filsDroit );

                /**
                 * Destructeur de OperateurAbstrait.
                 * */
                virtual ~OperateurAbstrait() = default;

            public:

                OperateurAbstrait( const OperateurAbstrait & autre ) = delete;

                OperateurAbstrait & operator=( const OperateurAbstrait & autre ) = delete;

            protected:

                /**
                 * Le fils gauche de l'opération.
                 * @see ValeurAbstraite
                 * */
                const ValeurAbstraite::PtrValeur filsGauche_;

                /**
                 * Le fils droit de l'opération.
                 * @see ValeurAbstraite
                 * */
                const ValeurAbstraite::PtrValeur filsDroit_;

        };

    }
}

#endif
