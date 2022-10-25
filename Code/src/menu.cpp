/**
*\ file menu.cpp
*\ brief Ce fichier sert à définir le code des fonctions menus
*\ author JACQUELIN Bastien, ASTOLFI Vincent, HODIN Dorian
*\ date 1 avril 2022
*/

#include "menu.hpp"
#include "erreur.hpp"
#include <iostream>

using namespace std;

/**
* \ brief affiche le menu des choix pour le réseau en liste
* \ return un int en fonction du choix de l'utilisateur
*/
int menuChoix(){
    int choix=0;
    cout<<"\033[01;34m===========================================\n";
    cout<<"||\033[00m\033[01;31m------------MENU DEPENDANCE------------\033[00m\033[01;34m||\n";
    cout<<"||\033[00m        Que voulez vous faire ?        \033[01;34m||\n";
    cout<<"||\033[00m                                       \033[01;34m||\n";
    cout<<"||\033[00m 1- Afficher la liste de trasformation \033[01;34m||\n";
    cout<<"||\033[00m 2- Afficher si transfo                \033[01;34m||\n";
    cout<<"||\033[00m 3- Créer vos dépendance               \033[01;34m||\n";
    cout<<"||\033[00m 4- Suprimmer vos dépendance           \033[01;34m||\n";
    cout<<"||\033[00m 0- Quitter                            \033[01;34m||\n";
    cout<<"===========================================\033[00m\n";

    cout<<"\n\033[01;35mVotre choix : \033[00m";
    cin>>choix;
    return choix;
}

/**
* \ brief affiche le menu principal du réseau en liste
* \ return un int en fonction du choix de l'utilisateur
*/
int menuBase(){
    int choix=0;
    cout<<"\033[01;34m=======================================\n";
    cout<<"||\033[00m\033[01;31m----------------MENU---------------\033[00m\033[01;34m||\n";
    cout<<"||\033[00m      Que voulez vous faire ?      \033[01;34m||\n";
    cout<<"||\033[00m                                   \033[01;34m||\n";
    cout<<"||\033[00m 1- Afficher vos objet             \033[01;34m||\n";
    cout<<"||\033[00m 2- Gérer les dépendances          \033[01;34m||\n";
    cout<<"||\033[00m 0- Quitter                        \033[01;34m||\n";
    cout<<"=======================================\033[00m\n";

    cout<<"\n\033[01;35mVotre choix : \033[00m";
    cin>>choix;
    return choix;
}

/**
 * \ brief affiche le menu principale des transformation pour la partie automatique
 * \ return int en fonction du choix de l'utilisateur
 */
int menuChoixAuto(){
    int choix=0;
    cout<<"\033[01;34m===========================================\n";
    cout<<"||\033[00m\033[01;31m------------MENU DEPENDANCE------------\033[00m\033[01;34m||\n";
    cout<<"||\033[00m        Que voulez vous faire ?        \033[01;34m||\n";
    cout<<"||\033[00m                                       \033[01;34m||\n";
    cout<<"||\033[00m 1- Afficher la liste de trasformation \033[01;34m||\n";
    cout<<"||\033[00m 2- Afficher si transfo                \033[01;34m||\n";
    cout<<"||\033[00m 0- Quitter                            \033[01;34m||\n";
    cout<<"===========================================\033[00m\n";

    cout<<"\n\033[01;35mVotre choix : \033[00m";
    cin>>choix;
    return choix;
}

/**
 * \ brief  affiche le menu principale pour la partie automatique
 * \ return int en fonction du choix de l'utilisateur
 */
int menuBaseAuto(){
    int choix=0;
    cout<<"\033[01;34m=======================================\n";
    cout<<"||\033[00m\033[01;31m----------------MENU---------------\033[00m\033[01;34m||\n";
    cout<<"||\033[00m      Que voulez vous faire ?      \033[01;34m||\n";
    cout<<"||\033[00m                                   \033[01;34m||\n";
    cout<<"||\033[00m 1- Afficher vos objet             \033[01;34m||\n";
    cout<<"||\033[00m 2- Choisir un objet à utiliser    \033[01;34m||\n";
    cout<<"||\033[00m 0- Quitter                        \033[01;34m||\n";
    cout<<"===========================================\033[00m\n";
    
    cout<<"\n\033[01;35mVotre choix : \033[00m";
    cin>>choix;
    return choix;

}