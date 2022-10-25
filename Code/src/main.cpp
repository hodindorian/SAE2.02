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

    cout<<"Votre liste d'objet a été créée avec succés vous allez rentrez dans le jeu\n\033[01;31m5\n";
	/*
    system("sleep 1");
    cout<<"4\n";
    system("sleep 1");
    cout<<"3\n";
    system("sleep 1");
	cout<<"2\n";
	system("sleep 1");
	cout<<"1\n\033[00m";
	system("sleep 1");
	*/

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
						cout << "Veuillez choisir un autre objet.\nVoulez vous les afficher pour vous les remémorer ?\nVotre choix (oui/non) :";
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
			if(res==0){
				L1.viderLaListe();
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
* \ brief sert à tester automatiquement les fonctions
*/
void autotest(){
	vector<Maillon*> l;
    vector<string> vObjetA;
	Maillon* Arbre=new Maillon {"Arbre"};
	Maillon* Planche= new Maillon{"Planche"};
	Maillon* Baton=new Maillon{"Baton"};
	Maillon* Fer=new Maillon{"Fer"};
	Maillon* Pioche=new Maillon{"Pioche"};
	Maillon* Epee=new Maillon{"Epée"};
	Maillon* Table=new Maillon{"Table"};
	Maillon* Bouclier=new Maillon{"Bouclier"};
	Maillon* Echelle=new Maillon{"Echelle"};
	Maillon* Or=new Maillon{"Or"};
	Maillon* LingotDor=new Maillon{"Lingot_d'Or"};
	Maillon* Boussole=new Maillon{"Boussole"};
	Maillon* Couronne=new Maillon{"Couronne"};
	Maillon* Armure=new Maillon{"Armure"};
	Maillon* Canne=new Maillon{"Canne_à_peche"};
	l.push_back(Arbre);
	l.push_back(Planche);
	l.push_back(Baton);
	l.push_back(Fer);
	l.push_back(Pioche);
	l.push_back(Epee);
	l.push_back(Table);
	l.push_back(Bouclier);
	l.push_back(Echelle);
	l.push_back(Or);
	l.push_back(LingotDor);
	l.push_back(Boussole);
	l.push_back(Couronne);
	l.push_back(Armure);
	l.push_back(Canne);

	cout << "---------- Test avec des listes ----------" << endl;
	Liste L{15};
	L.creerListAuto(l);
	L.affichListe();
	cout << endl;
	(*Arbre).creerListeTransfoA(*Planche,L.LesMaillons);
	(*Planche).creerListeTransfoA(*Baton,L.LesMaillons);
	(*Planche).creerListeTransfoA(*Table,L.LesMaillons);
	(*Planche).creerListeTransfoA(*Bouclier,L.LesMaillons);
	(*Baton).creerListeTransfoA(*Echelle,L.LesMaillons);
	(*Baton).creerListeTransfoA(*Canne,L.LesMaillons);
	(*Fer).creerListeTransfoA(*Pioche,L.LesMaillons);
	(*Fer).creerListeTransfoA(*Epee,L.LesMaillons);
	(*Fer).creerListeTransfoA(*Boussole,L.LesMaillons);
	(*Fer).creerListeTransfoA(*Armure,L.LesMaillons);
	(*Table).creerListeTransfoA(*Bouclier,L.LesMaillons);
	(*Table).creerListeTransfoA(*Planche,L.LesMaillons);
	(*Bouclier).creerListeTransfoA(*Planche,L.LesMaillons);
	(*Bouclier).creerListeTransfoA(*Table,L.LesMaillons);
	(*LingotDor).creerListeTransfoA(*Or,L.LesMaillons);
	(*LingotDor).creerListeTransfoA(*Couronne,L.LesMaillons);
	(*Boussole).creerListeTransfoA(*Fer,L.LesMaillons);
	(*Couronne).creerListeTransfoA(*Or,L.LesMaillons);
	(*Couronne).creerListeTransfoA(*LingotDor,L.LesMaillons);
	(*Echelle).creerListeTransfoA(*Baton,L.LesMaillons);
	(*Armure).creerListeTransfoA(*Fer,L.LesMaillons);
	(*Canne).creerListeTransfoA(*Baton,L.LesMaillons);	
	(*Or).creerListeTransfoA(*LingotDor,L.LesMaillons);
	(*Or).creerListeTransfoA(*Couronne,L.LesMaillons);
	(*Arbre).affichTransfoListe();
	(*Planche).affichTransfoListe();
	(*Baton).affichTransfoListe();
	(*Fer).affichTransfoListe();
	try {
	(*Pioche).affichTransfoListe();
	}
	catch (VideException &e){
		cout << "Pioche n'est pas transformable." << endl;
	}
	try {
	(*Epee).affichTransfoListe();
	}
	catch (VideException &e){
		cout << "Epée n'est pas transformable." << endl;
	}
	(*Table).affichTransfoListe();
	(*Bouclier).affichTransfoListe();
	(*Echelle).affichTransfoListe();
	(*Or).affichTransfoListe();
	(*LingotDor).affichTransfoListe();
	(*Boussole).affichTransfoListe();
	(*Couronne).affichTransfoListe();
	(*Armure).affichTransfoListe();
	(*Canne).affichTransfoListe();
	cout << "\n---------- Test avec une matrice ----------" << endl;
	Matrice M{15,0,vObjetA};
	M.AfficherTab();
	M.afficherMatrice();

	string choix;
	cout << "\nSouhaitez vous tester des transformations ?\nVotre choix (oui/non) : ";
	cin>>choix;
	if(choix=="oui"){
		int resBase=1;
		int res=1;
		system("clear");
		while(resBase!=0){
			resBase=menuBaseAuto();
			if(resBase==1){
				L.affichListe();
			}
			if(resBase==2){
				string choixMaillon;
				cout << "\nVeuillez choisir le nom de l'objet que vous voulez utiliser\nVotre Choix : ";
				cin>> choixMaillon;
				for(list<Maillon*>::iterator it=L.LesMaillons.begin();it!=L.LesMaillons.end();it++){
					if((**it).getDesignation()==choixMaillon){
						system("clear");
						while(res!=0){
							res=menuChoixAuto();
							if(res==1){
								(**it).affichTransfoListe();
							}
							if(res==2){
								string enQuoi;
								cout << "En quoi voulez vous transformer "<<(**it)<<" ?\n";
								cin>>enQuoi;
								vector<string> tmp;
								tmp.clear();
								try{
									(**it).transformer(enQuoi, tmp);
								}catch (const VideException &e){
									cout<<"Transformation introuvable.\nVeuillez en essayer une autre.\n";								
								}
							}
						}
					}
				}
			}
		}
	}
}
/**
* \ brief sert à appeler les fonctions test et autotest définit juste avant
*/
int main(){
	int choix;
	cout << "Voulez vous choisir le réseau créé automatiquement ou le créer vous même ?\n1- Auto\n2- Créer soit même\nVotre choix : ";
	cin>>choix;

	if(choix==1){ autotest() ;}
	else {test();}
	return 0;
}
