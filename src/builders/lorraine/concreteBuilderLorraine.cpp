#include "concreteBuilderLorraine.hpp"

 namespace sysexp{

	 namespace builders{

	 	namespace lorraine{

			ConcreteBuilderLorraine::ConcreteBuilderLorraine(std::istream & fichier):
			 fichier_(fichier),
			 regle_(nullptr)
			 {}

			 void
			 ConcreteBuilderLorraine::construireJeuDeRegle(){
				 Lexical lexical(fichier_);
				 Syntaxique syn(lexical);
				 regle_ = syn.parser();
			 }

			 const sysexp::modele::RegleAbstraite::PtrRegleAbstraite &
			 ConcreteBuilderLorraine::getResult() const{
				 return regle_;
			}
		}
	}
}

