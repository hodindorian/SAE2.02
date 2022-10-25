/**
*\ file main.cpp
*\ brief Ce fichier sert à créer les fonctions appelant les différents réseau et objet
*\ author JACQUELIN Batsien, ASTOLFI Vincent, HODIN Dorian
*\ date 1 avril 2022
*/

#include "liste.hpp"
#include "maillon.hpp"
#include "menu.hpp"
#include "erreur.hpp"
#include "matrice.hpp"
#include <iostream>
#include <vector>

using namespace std;
/**
* \ brief sert à appeler les menus et l'interface de choix de réseau
*/
void test(){
    int nbObjet;
    vector<string> vObjet;
    system("clear");
    cout<< "\033[01;34m########## Bienvenue dans notre jeu ##########\n\n\033[00m";
    //system("sleep 1");
    cout<<"Vous allez créer un tableau d'objet que vous allez pouvoir transformer en d'autre objet.\nPar exemple un Arbre est transformable en planche, une planche en table, etc...\n";
    //system("sleep 3");

    cout<<endl;

    cout<<("\033[01;32mCréation de vos objet :\033[00m\n");
    cout<<("Nombre d'objet que vous voulez dans votre jeu :\t");
    cin>>nbObjet;

    for(int i=0; i<nbObjet; ++i){
        string objet;
        cout<<"\033[01;35mNom de l'objet n°"<<i+1<<" : \033[00m";
        cin>>objet;
        vObjet.push_back(objet);
    }

    cout<<endl;

    cout<<"Votre liste d'objet a été créé avec succés vous allez rentrez dans le jeu\n\033[01;31m5\n";
    system("sleep 1");
    cout<<"4\n";
    system("sleep 1");
    cout<<"3\n";
    system("sleep 1");
	cout<<"2\n";
	system("sleep 1");
	cout<<"1\n\033[00m";
	system("sleep 1");

	system("clear");

	while(true){
		system("clear");
		int choixReseau;
		cout << "\033[01;32mQuel réseau voulez vous utilisez ?\033[00m\n1- Réseau en liste\n2- Réseau en matrice\n0- Quitter\n\033[01;35mVotre choix : \033[00m";
		cin>>choixReseau;

		if(choixReseau==1){
			Liste L1{nbObjet};
			L1.creerList(vObjet);
			int res=1;
			system("clear");
			while(res!=0){
				res=menuBase();
				if(res==1){
					L1.affichListe();
				}
				if(res==2){
					try{
						L1.creerDependense();
					} catch (const InconnueException &e) {
							string choix; 
							cout << "Veuillez choisir un autre objet.\nVoulez vous les affichers pour vous les remémorer ?\nVotre choix (oui/non) :";
							cin>>choix;
							if(choix=="oui"){
								L1.affichListe();
							}else{
								cout<<"Très bien, retour au menu.\n";
								system("sleep 2"); system("clear");
							}
						}
					}
				}
			}

		if(choixReseau==2){
			system("clear");
			Matrice M1{nbObjet,vObjet};
			M1.menu();
		}
		if(choixReseau==0){
			break;
		}
	}
}
/**
* \ brief sert à appeler la fonction test définit juste avant
*/
int main(){
	test();
	return 0;
}
