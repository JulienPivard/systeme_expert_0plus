/**
 * @file FaitBool.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier FaitBool.cpp.
 * Définit la classe concrète FaitBool.
 * */

#ifndef faitbool_hpp
#define faitbool_hpp

#include <cstdlib>

#include "FaitAbstrait.hpp"


namespace sysexp
{

    namespace modele
    {
        /**
         * @class FaitBool FaitBool.hpp
         * @brief Représente un fait booléen. Sa valeur ne peut pas être modifiée.
         *
         * Déclaration de la classe concrète FaitBool.
         * Cette classe permet de représenter un fait booléen et sa valeur booléenne.
         * */
        class FaitBool : public FaitAbstrait
        {

            public:

                /**
                 * @typedef PtrFaitBool
                 *
                 * Nom facile pour un shared_ptr de FaitBool.
                 * */
                typedef std::shared_ptr< FaitBool > PtrFaitBool;

            public:

                /**
                 * Constructeur logique du fait booléen.
                 *
                 * @param[in] nom
                 * Le @ref nom_ du fait booléen.
                 * @param[in] valeur
                 * La @ref valeur_ du fait booléen.
                 * */
                FaitBool( const std::string & nom, const bool & valeur );

                /**
                 * Accesseur.
                 *
                 * @return La @ref valeur_ du fait booléen.
                 * */
                bool lireValeur() const;

            public:

                FaitBool( const FaitBool & autre ) = delete;

                FaitBool & operator=( const FaitBool & autre ) = delete;

            protected:

                /**
                 * La valeur de notre fait booléen, soit true soit false.
                 * La valeur d'un fait n'est pas censé changer.
                 * */
                const bool valeur_;

        };
    }
}

#endif
