/**
 * @file FormeConclusionBoolTrue.hpp
 * @brief header.
 * @author PIVARD Julien
 *
 * Header pour le fichier FormeConclusionBoolTrue.cpp.
 * Définit la classe concrète FormeConclusionBoolTrue.
 * */


#ifndef formeconclusionbooltrue_hpp
#define formeconclusionbooltrue_hpp

#include <string>

#include "FormeAbstraiteConclusion.hpp"

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
         * @class FormeConclusionBoolTrue FormeConclusionBoolTrue.hpp
         *
         * Déclaration de la classe FormeConclusionBoolTrue.
         * */
        class FormeConclusionBoolTrue : public FormeAbstraiteConclusion
        {

            public:

                /**
                 * Constructeur logique
                 *
                 * @param[in] nom
                 * Le nom de la conclusion booléenne.
                 * */
                FormeConclusionBoolTrue( const std::string & nom );

                /**
                 * Méthode de visite.
                 *
                 * @param[in, out] visiteur
                 * Le visiteur qui vas évaluer la conclusion booléenne.
                 * */
                void accept( const std::shared_ptr< VisiteurFormeAbstrait > & visiteur );

        };

    }
}

#endif
