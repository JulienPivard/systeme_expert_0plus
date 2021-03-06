#include "RegleAvecPremisse.hpp"

namespace sysexp
{

    namespace modele
    {

        RegleAvecPremisse::RegleAvecPremisse( const unsigned int & numeroRegle,
                const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse,
                const FormeAbstraiteConclusion::PtrFormeAbstraiteConclusion & conclusion ):
            RegleAbstraite( numeroRegle, conclusion )
        {
            ajouterPremisse( premisse );
        }

        void RegleAvecPremisse::ajouterPremisse( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & premisse )
        {
            premisses_.insert( premisse );
        }

        bool RegleAvecPremisse::verifierPremisses( const BaseFait::PtrBaseFait & base )
        {
            bool resultat = true;
            for( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & prem : premisses_ )
            {
                VisiteurForme::PtrVisiteurForme visiteur( new VisiteurForme( base ) );
                prem->accept( visiteur );
                // Pour mieux voir ce qui se passe lors du déclenchement.
                if( traceExecution_ )
                {
                    std::cout << std::endl
                        << "Vérification de la prémisse : "
                        << prem->lireNom()
                        << std::endl
                        << "Règle numéro "
                        << numeroRegle_
                        << " nom "
                        << conclusion_->lireNom()
                        << std::endl;
                    visiteur->afficher();
                    // Fin de debogage.
                }
                // Vérification des flags d'erreur du visiteur.
                verifFlagErreurVisiteur( visiteur );
                // Si l'évaluation de toutes les prémisses n'est pas vraie,
                // alors on stop la boucle.
                resultat = resultat && visiteur->getPremisseVerifiee();
                if( !resultat )
                {
                    break;
                }
            }
            return resultat;
        }

        void RegleAvecPremisse::afficher() const
        {
            RegleAbstraite::afficher();
            std::cout << "La/Les prémisse(s) : "
                << std::endl;
            for( const FormeAbstraitePremisse::PtrFormeAbstraitePremisse & prem : premisses_ )
            {
                std::cout << "Nom prémisse : "
                    << prem->lireNom()
                    << std::endl;
            }
        }

    }

}
