/**
*\ file maillon.cpp
*\ brief Ce fichier sert à définir le code de la classe Maillon
*\ author ASTOLFI Vincent
*\ date 1 avril 2022
*/

#include "maillon.hpp"
#include <iostream>
#include "erreur.hpp"

using namespace std;
/**
* \ brief créer le constructeur de maillon
*/
Maillon::Maillon(string nom)
       :designation{nom}
{}
/**
* \ brief permet de récuperer la designation de la classe Maillon qui est un attribut privé
* \ return un string, designation
*/
string Maillon::getDesignation() const{
       return designation;
}
/**
* \ brief permet de créer une liste des transformations possibles entre les différents objets
* \ param list<Maillon>, objet Liste
*/
void Maillon::creerListeTransfo(list<Maillon*> l, Liste L1){
       while(true){
              string choixTransfo;
              cout << "\nEn quoi voulez vous que votre objet soit transormable ? (-1 pour sortir)\nVotre choix : ";
              cin>>choixTransfo;
              if(choixTransfo=="-1"){return;}
              if(choixTransfo==this->getDesignation()){
                     cout << "\033[01;31mVous ne pouvez pas transformer un objet en lui même, veuillez en choisir un autre.\033[00m\n";
                     continue;
              }
              for(list<Maillon*>::iterator it=l.begin();it!=l.end();it++){
                     if((*it)->getDesignation()==choixTransfo){
                            cout << "\033[01;32mObjet trouvé, votre objet est transformable en "<<choixTransfo<<"\033[00m."<<endl;
                            this->transfo.push_back(*it);
                            break;
                     }
                     if(static_cast<int>(distance(l.begin(),it))+1==static_cast<int>(l.size())){
                            string choixAffichage;
                            cout << "\033[01;31mL'objet que vous cherchez n'existe pas.\033[00m\nVoulez vous afficher tout vos objets ? (oui/non)\nVotre choix : ";
                            cin>>choixAffichage;
                            if(choixAffichage=="oui"){
                                   L1.affichListe();
                            }
                     }
              }
       }
       system("clear");
}
/**
* \ brief permet d'afficher la liste des transformations possibles
*/
void Maillon::affichTransfoListe(){
       if (this->transfo.size()==0) { throw VideException{}; }
       for(list<Maillon*>::iterator it=transfo.begin();it!=transfo.end();it++){
              cout<<this->getDesignation()<<" est transformable en "<<(**it).getDesignation()<<endl;
       }
}
/**
* \ brief permet de transformer un objet en un autre objet
* \ param string, vector<string>
*/
void Maillon::transformer(string m, vector<string> tmp){
       // error if the object can't transform in anything
       if(this->transfo.size()==0 && tmp.size()==0){ throw VideException{};}

       if(this->transfo.size()==0){return;}

       // adding the name of the first object in a vector to write it later when the transformation if find
       tmp.push_back(this->getDesignation());
       
       // go through the possible transformation of the object to see if it can transform into the one we are looking for
       for(list<Maillon*>::iterator it=this->transfo.begin();it!=this->transfo.end();it++){
              
              // if the trandformation is find 
              if((**it)==m){
                     // display the results
                     cout<<"Tranformation trouver !\n";
                     for(vector<string>::iterator it=tmp.begin(); it!=tmp.end();it++){
                            if(it==tmp.begin()){
                                   cout << *it <<" est transformable en ";
                            }
                            else {
                                   cout << *it << ", " << *it << " est transformable en ";
                            }
                     }
                            cout << m << endl;
                     if(static_cast<int>(tmp.size())>1){
                            vector<string>::iterator it2=tmp.begin();
                            cout<<"Donc "<<*it2<< " est transformable en "<<m<<endl;
                            break;
                     }
              }
              // if it can't find a direct transformation it recall the functiun with other object in
              (**it).transformer(m, tmp);
       }
       return;
}
/**
* \ brief surcharge de l'opérateur !=
* \ param deux objets Maillon
* \ return un booléen en fonction du résultat de la comparaison
*/
bool operator!=(const Maillon& m1, const Maillon& m2){
       if(m1.getDesignation()!=m2.getDesignation()){ return true;}
       return false;
}
/**
* \ brief surcharge de l'opérateur ==
* \ param deux objets Maillon*
* \ return un booléen en fonction du résultat de la comparaison
*/
bool operator==(const Maillon& m1, const Maillon& m2){
       return m1.getDesignation()==m2.getDesignation();
}
/**
* \ brief surcharge de l'opérateur <<
* \ param ostream et un maillon
* \ return ostream
*/
std::ostream& operator<<(std::ostream& s,Maillon &m){
	s<<"Objet : "<<m.getDesignation();
	return s;
}