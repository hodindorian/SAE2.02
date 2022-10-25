/**
*\ file liste.cpp
*\ brief Ce fichier sert à définir le code de la classe liste
*\ author ASTOLFI Vincent
*\ date 1 avril 2022
*/

#include "liste.hpp"
#include "menu.hpp"
#include "erreur.hpp"
#include <string>
#include <iostream>

using namespace std;
/**
* \ brief constructeur de la classe liste
*/
Liste::Liste(int nbMaillon)
	:nbMaillon{nbMaillon}
{}
/**
* \ brief permet de récuperer le nbMaillon de la classe liste qui est un attribut privé
* \ return un int, nbMaillon
*/
int Liste::getNbMaillon() const{
	return nbMaillon;
}
/**
* \ brief permet de créer une liste de maillon
* \ param vector<string>
*/
void Liste::creerList(vector<string> v){
	for (vector<string>::iterator it=v.begin();it!=v.end();it++){
		Maillon * m = new Maillon {(*it)};
		LesMaillons.push_back(m);
	}
}

/**
 * \ brief permet de créer une liste de pointeur de maillon mais pour la partie automatique
 * \ param vector<Maillon*> 
 */
void Liste::creerListAuto(vector<Maillon*> v){
	for (vector<Maillon*>::iterator it=v.begin();it!=v.end();it++){
		LesMaillons.push_back((*it));
	}
}
/**
* \ permet d'afficher la liste créer auparavant
*/
void Liste::affichListe(){
	for (list<Maillon*>::iterator it=LesMaillons.begin(); it!=LesMaillons.end(); ++it){
		cout<<"-"<<static_cast<int>(distance(LesMaillons.begin(),it))+1<<" "<<**it<<endl;
	}
}
/**
* \ brief créer un nouveau lien entre 2 maillon, une dépendance
*/
void Liste::creerDependense(){
	string choixMaillon;
	int tmp=0;
	cout<< "Quel objet voulez vous utilisez :\t";
	cin>>choixMaillon;
	for(list<Maillon*>::iterator it=LesMaillons.begin();it!=LesMaillons.end();it++){
		if((**it).getDesignation()==choixMaillon){
			system("clear");
			tmp=1;
			int res=1;
			while(res!=0){
				res=menuChoix();
				if(res==1){
					try {
						(**it).affichTransfoListe();
					} catch (const VideException &e) {
						string choix;
						cout << "Voulez-vous créer la liste de transformation possible de "<<(**it).getDesignation()<<" ?" <<endl;
						cout << "(oui/non)\t";
						cin>>choix;
						if(choix=="oui"){
							(**it).creerListeTransfo(this->LesMaillons, *this);						
						}else{
							cout << "Retour au menu.\n";
						}
					}
				}
				if(res==3){
					(**it).creerListeTransfo(this->LesMaillons, *this);
					system("clear");
				}
				if(res==2){
					string enQuoi;
					cout << "En quoi voulez vous transformer "<<(**it)<<" ?\n";
					cin>>enQuoi;
					vector<string> tmp;
					tmp.clear();
					try{
						(**it).transformer(enQuoi, tmp);
					} catch (const VideException &e){
						string choix;
						cout << "Voulez-vous créer la liste de transformation possible de "<<(**it).getDesignation()<<endl<<"Votre choix (oui/non) : ";
						cin>>choix;
						if(choix=="oui"){
							(**it).creerListeTransfo(this->LesMaillons, *this);
						}else{
							cout << "Retour au menu.\n";
						}
					}
				}
				if(res==4){
					try{
						(**it).supprimerListeTransfo();
					}catch (const VideException &e){
						string choix;
						cout << "Voulez-vous créer la liste de transformation possible de "<<(**it).getDesignation()<<endl<<"Votre choix (oui/non) : ";
						cin>>choix;
						if(choix=="oui"){
							(**it).creerListeTransfo(this->LesMaillons, *this);
						}else{
							cout << "Retour au menu.\n";
						}
					}
				}
			}
		}
		if(static_cast<int>(distance(LesMaillons.begin(),(it)))==static_cast<int>(LesMaillons.size()-1)){
			if (tmp==0){
				throw InconnueException{choixMaillon};
			}
			return ;
		}
	}
	
}

/**
 * \ brief permet de vider proporement les données contenue par la liste afin d'éviter les fuites de mémoire
 */
void Liste::viderLaListe(){
	for(list<Maillon*>::iterator it=LesMaillons.begin();it!=LesMaillons.end();it++){
		(**it).viderLesListes();
	}
	LesMaillons.clear();
}