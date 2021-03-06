/**
 * @file VisiteurForme.hpp
 * @brief header.
 * @author PIVARD Julien, CLECH Sandy
 *
 * Header pour le fichier VisiteurForme.cpp.
 * Définit la classe concrète VisiteurForme.
 * */


#ifndef visiteurforme_hpp
#define visiteurforme_hpp

#include "VisiteurFormeAbstrait.hpp"
#include "BaseFait.hpp"

#include "FormeConclusionBoolTrue.hpp"
#include "FormeConclusionBoolFalse.hpp"
#include "FormeConclusionEntierFait.hpp"
#include "FormeConclusionEntierExpression.hpp"
#include "FormeConclusionSymboliqueConstante.hpp"
#include "FormeConclusionSymboliqueFait.hpp"

#include "FormePremisseBoolTrue.hpp"
#include "FormePremisseBoolFalse.hpp"
#include "FormePremisseEntierExpression.hpp"
#include "FormePremisseEntierFait.hpp"
#include "FormePremisseSymboliqueConstante.hpp"
#include "FormePremisseSymboliqueFait.hpp"

#include "FaitAbstrait.hpp"


namespace sysexp
{

    namespace modele
    {

        /**
        * @brief Représente le visiteur de règle.
        *
        * Déclaration de la classe VisiteurForme.
        * */
        class VisiteurForme : public VisiteurFormeAbstrait
        {

            public:

                /**
                 * @typedef PtrVisiteurForme
                 *
                 * Un alias pour se faciliter l'utilisation de shared pointer de VisiteurForme.
                 * */
                typedef std::shared_ptr< VisiteurForme > PtrVisiteurForme;

            public:

                /**
                * Constructeur logique
                *
                * @param[in] baseFait
                * La @ref baseFait_ de fait que l'on va remplir.
                * */
                VisiteurForme( const BaseFait::PtrBaseFait & baseFait );

                /**
                 * Visite la règle passée en argument.
                 * Ajoute la conclusion de la règle à la base de faits si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionBoolTrue
                 * */
                void visiter( const FormeConclusionBoolTrue & conclusion );

                /**
                 * Visite la règle passée en argument.
                 * Ajoute la conclusion de la règle à la base de faits si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionBoolFalse
                 * */
                void visiter( const FormeConclusionBoolFalse & conclusion );

                /**
                 * Visite la règle passée en argument.
                 * Ajoute la conclusion de la règle à la base de faits si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionEntierExpression
                 * */
                void visiter( const FormeConclusionEntierExpression & conclusion );

                /**
                 * Visite la règle passé en argument.
                 * Ajoute la conclusion de la règle à la base de fait si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionEntierFait
                 * */
                void visiter( const FormeConclusionEntierFait & conclusion );

                /**
                 * Visite la règle passée en argument.
                 * Ajoute la conclusion de la règle à la base de faits si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionSymboliqueConstante
                 * */
                void visiter( const FormeConclusionSymboliqueConstante & conclusion );

                /**
                 * Visite la règle passée en argument.
                 * Ajoute la conclusion de la règle à la base de faits si celle ci est déclenchée.
                 *
                 * @param[in,out] conclusion
                 * La conclusion que l'on veut visiter.
                 * @see FormeConclusionSymboliqueFait
                 * */
                void visiter( const FormeConclusionSymboliqueFait & conclusion );

            public:

                /**
                 * Visite la règle passée en argument.
                 * Mémorise que la prémisse est valide.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseBoolTrue
                 * */
                void visiter( const FormePremisseBoolTrue & premisse );

                /**
                 * Visite la règle passée en argument.
                 * Mémorise que la prémisse est valide.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseBoolFalse
                 * */
                void visiter( const FormePremisseBoolFalse & premisse );

                /**
                 * Visite la règle passée en argument.
                 * Mémorise que la prémisse est valide.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseSymboliqueConstante
                 * */
                void visiter( const FormePremisseSymboliqueConstante & premisse );

                /**
                 * Visite la règle passée en argument.
                 * Mémorise que la prémisse est valide.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseSymboliqueFait
                 * */
                void visiter( const FormePremisseSymboliqueFait & premisse );

                /**
                 * Visite la règle passée en argument.
                 * Mémorise que la prémisse est valide.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseEntierExpression
                 * */
                void visiter( const FormePremisseEntierExpression & premisse );

                /**
                 * Visite la règle passée en argument.
                 * Mémorise que la prémisse est valide.
                 *
                 * @param[in,out] premisse
                 * La conclusion que l'on veut visiter.
                 * @see FormePremisseEntierFait
                 * */
                void visiter( const FormePremisseEntierFait & premisse );

            public:

                VisiteurForme( const VisiteurForme & autre ) = delete;

                VisiteurForme & operator=( const VisiteurForme & autre ) = delete;

        };

    }
}

#endif
