/**
*\ file matrice.cpp
*\ brief Ce fichier sert à définir le code de la classe Matrice
*\ author JACQUELIN Bastien
*\ date 1 avril 2022
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "matrice.hpp"

using namespace std;

/**
* \ brief constructeur de la classe Matrice
*/
Matrice::Matrice(int nbItems,std::vector<std::string> items):nbItems{nbItems},items{items}{
    remplirMatrice();
}
/**
* \ brief constructeur de la classe Matrice pour le test automatique
*/
Matrice::Matrice(int nbItems,int a,std::vector<std::string> items) :nbItems{nbItems},a{a},items{items}{
    remplirMatriceAuto();
}

/**
* \ brief sert à remplir la matrice automatiquement
*/
void Matrice::remplirMatriceAuto(){
    matrice={{-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,-1,1,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,-1,0,0,0,0,0,1,0,0,0,0,0,1},{0,0,0,-1,1,1,0,0,0,0,0,1,0,1,0},{0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,-1,1,0,0,0,0,0,0,0},{0,1,0,0,0,0,1,-1,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,-1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,-1,1,0,1,0,0},{0,0,0,0,0,0,0,0,0,1,-1,0,1,0,0},{0,0,0,1,0,0,0,0,0,0,0,-1,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,-1,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,-1,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,-1}};
}
/**
* \ brief sert à remplir la matrice en fonction des choix de l'utilisateur
*/
void Matrice::remplirMatrice(){//relations entre items
    string val;
    int relation; //0: no relations, -1: cannot transform in itself & 1: relation possible
    vector<string>::iterator it1=items.begin();
    for (int i=0; i<nbItems; i++)
    {
        vector<int> v;
        vector<string>::iterator it2=items.begin();
        for (int j=0; j<nbItems; j++)
        {
            if (i==j)
            {              
                v.push_back(-1);
                it2++;
                continue;
            }
            cout << "\n\033[01;35mL'objet "<< *it1 << " peut-il se transformer en " << *it2 << "?\033[00m\n 0 : Pas de transformation\n 1 : Transformation possible\n";
            cin>>relation;
            if (relation!=0 && relation!=1)// Verification of values
            {
                while(relation!=0 && relation!=1)
                {
                    cout<<"\033[01;31mMauvaise entrée, \"0\" si la transformation ne peut se faire sinon si la relation est possible saisissez \"1\"\033[00m";
                    cin>>relation;
                }
            }            
            v.push_back(relation);
            it2++;
        }
        matrice.push_back(v);
        it1++;
    }   
}
/**
* \ brief sert à afficher la matrice
*/
void Matrice::afficherMatrice(){
    int relation, sizeM;
    sizeM=matrice.size();
    cout << "\nVerticalement: Objet de départ. \nHorizontalement: Objet d'arrivée.\n" << endl;
    for (int i=0; i<sizeM; i++)
    {
        for (int j=0; j<sizeM; j++)
        {
            relation=matrice[i][j];
            cout << relation <<" ";
        }
        cout <<"\n";
    }  
}

// void Matrice::remplirTab(){// insertion dans vector contenant nom des items
//     string val;
//     for (int i=0; i<nbItems; i++)
//     {
//         cout << "Nom de l'item: \n";
//         cin>>val;
//         items.push_back(val);
//     }   
// }

/**
* \ brief sert à afficher tout les objets de la matrice
*/
void Matrice::AfficherTab(){
    vector<string>::iterator it=items.begin();//
    int count=1;
    for (string s : items)
    {
        cout << "Nom de l'item " << count <<" : " << *it <<"\n";
        it++;
        count++;
    }
}

/**
* \ brief sert à rechercher un objet dans la matrice en fonction de son nom
* \ param un string, le nom de l'objet recherché
* \ return un int
*/
int Matrice::research(string& rech){
    for (int i=0; i<nbItems; i++)
    {
        if (rech==items[i])
        {
            return i;
        }
        if (i==nbItems-1)
        {
            cout << "L'objet n'existe pas"<<endl;//Item not found
            return -1;
        }
    }
    return -1;
}

/**
* \ brief sert à afficher un menu pour les différents choix de l'utilisateur
*/
void Matrice::menu(){
    string base, trans;
    int choix=-1;
    while (choix!=0)
    {
        cout<<"\033[01;34m=============================================\n";
        cout<<"||\033[00m\033[01;31m-------------------MENU------------------\033[00m\033[01;34m||\n";
        cout<<"||\033[00m         Que voulez vous faire ?         \033[01;34m||\n";
        cout<<"||\033[00m                                         \033[01;34m||\n";
        cout<<"||\033[00m 1- Affciher les différents objets       \033[01;34m||\n";
        cout<<"||\033[00m 2- Afficher les différentes relations   \033[01;34m||\n";
        cout<<"||\033[00m 3- Rechercher une transformation        \033[01;34m||\n";
        cout<<"||\033[00m 0- Quitter                              \033[01;34m||\n";
        cout<<"=============================================\033[00m\n";
        cout<<"\n\033[01;35mVotre choix : \033[00m";
        cin>>choix;
        switch (choix)
        {
        case 1:
            AfficherTab();
            break;
        case 2:
            afficherMatrice();
            break;
        case 3:
            cout<<"Objet à transformer: \n";
            cin>>base;
            while(research(base)==-1)//Error,the basic object doesn't exists
            {
                cout<<"\033[01;31mL'objet de base que vous souhaitez transformer n'existe pas.\033[00m\n \t Saisissez un nouvel item à transformer, \'0\' pour quitter\n";
                cin>>base;
                if (base=="0")
                {
                    return;
                } 
            }
            cout<<"Objet recherché: \n";
            cin>>trans;
            while(research(trans)==-1)//Error, the research object doesn't exists
            {
                cout<<"\033[01;31mL'objet final recherché que vous souhaitez transformer n'existe pas.\033[00m\n \t Saisissez un nouvel item final à transformer, \'0\' pour quitter\n";
                cin>>trans;
                if (trans=="0")
                {
                    return;
                } 
            }

            tranfoDirect(base,trans);
            break;
        case -1:
            continue;
        default:
            continue;
        }
    }
    

}
/**
* \ brief sert à afficher si un objet peut se transformer directement en un autre objet
* \ param deux strings
* \ return un int en fonction du résultat de la tentative de transormation
*/
int Matrice::tranfoDirect(string deb ,string res){
    int posRes, posDeb, cr, sizeR;
    posDeb=research(deb);
    posRes=research(res);

    if (matrice[posDeb][posRes]==1)
    {
        cout << "\033[01;32mTransformation directe possible\n";
        cout <<items[posDeb]<<" se transforme directement en "<<items[posRes]<<"\033[00m" <<endl;
        return 1;
    }
    else{
        cout << "\033[01;31mTransformation directe impossible\033[00m"<<endl;
        //recherche transfo possible
        cr=researchTransfo(posDeb,posRes,0);
        
        if (cr==false)//If no transformation possible
        {
            cout<<"\033[01;31mL'objet "<<items[posDeb]<<" ne peut se transformer en "<<items[posRes]<<".\033[00m\n";
            return -1;
        }
        cout<<"\033[01;32mL'objet "<<items[posDeb]<<" peut se transformer en "<<items[posRes]<<" en se tranformant d'abord en ";
        sizeR=required.size();
        for (int i=sizeR-1; i>=0; i--)//Display of all the items needed to transform the basic item in the researched one.
        {
            if (i==0)
            {
                cout<<items[required[i]]<<".\n";
                break;
            }
            cout<<items[required[i]]<<" puis en ";            
        }
        
        return 0;
    }
}

/**
* \ brief sert à savoir si un objet est transformable en un autre, directement ou en plusieurs étapes
* \ param trois int
* \ return un booléen en fonction du résultat de la tentative de transformation de l'objet en un autre
*/
bool Matrice::researchTransfo(int base, int rech, int jump){
    bool cr, cr1;
    if (matrice[base][rech]==1)// The item research is directly accessible from the basic item
    {

        return true;
    }
    else{
        for (int i=jump;i<nbItems; i++)//For each transformation of the items
        {

            if (matrice[base][i]==1)//If the item allows 1 or more transformation
            {

                if (present(i)==true)//Value already tested
                {
                    if (i==nbItems-1)//Last Value, was already tested, no transformation
                    {
                        //no way
                        return false;
                    }
                    continue;
                }
                cr1=researchTransfo(i,rech,0);
                if (cr1==false)
                {
                    cr=researchTransfo(base,rech,i+1);//jump +1 (transfo +1) for the previous item check, this item was already tests or has no issues
                    if (cr==false)
                    {
                        tested.push_back(i);
                        continue;
                    }                
                }
                required.push_back(i);
                return true;
            }
        }
        return false;
    }
}

/**
* \ brief vérifie si l'objet en position pos a déjà été déclaré comme une transformation d'un autre objet
* \ param un int
* \ return un booléen en fonction du résultat du test
*/
bool Matrice::present(int pos){
    int taille=tested.size();
    for (int i=0; i<taille; i++)
    {
        ::cout <<"rentree for ";
        if (tested[i]==pos)
        {
            return true;
        }
    }
    return false;
}
/**
* \ brief destructeur de l'objet Matrice
*/
Matrice::~Matrice(){}