/**
 * @file ValeurAbstraite.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier ValeurAbstraite.cpp.
 * Définit la classe abstraite ValeurAbstraite.
 * */

#ifndef valeurabstraite_hpp
#define valeurabstraite_hpp

#include "BaseFait.hpp"
#include <memory>

/**
 * @namespace sysexp
 * */
namespace sysexp
{
    /**
     * @namespace sysexp::modele
     * */
    namespace modele
    {

        /**
         * @class Valeur ValeurAbstraite.hpp
         *
         * Déclaration de la classe abstraite Valeur.
         * */
        class ValeurAbstraite
        {

            public:

                /**
                 * @typedef Valeur
                 *
                 * La valeur stocké sous forme de shared_ptr.
                 * */
                typedef std::shared_ptr<sysexp::modele::ValeurAbstraite> Valeur;

            public:

                /**
                 * Permet d'évaluer la valeur.
                 *
                 * @param[in] baseFait
                 * La base de fait à utiliser pour évaluer les expressions.
                 * */
                virtual const long int & interpret( const BaseFait & baseFait ) const = 0;

                /**
                 * Destructeur virtuel.
                 * */
                virtual ~ValeurAbstraite() = default;

            protected:

        };

    }
}

#endif