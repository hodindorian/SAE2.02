/**
*\ file matrice.hpp
*\ brief Ce fichier sert à définir la classe Matrice
*\ author JACQUELIN Bastien
*\ date 1 avril 2022
*/

#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <string>
#include <vector>
#include <iostream>


class Matrice{
    private:
    int nbItems;
    int a;
    std::vector<std::vector<int>> matrice;//tranfo
    std::vector<std::string> items;//liste items
    std::vector<int> tested;//obj testé qui ne tranfo pas directement en obj dmd
    std::vector<int> required;//obj par lesquel ont passe pr arriver


    public:
    Matrice(int nbItems,std::vector<std::string> items);
    Matrice(int nbItems,int a,std::vector<std::string> items);
    ~Matrice();
    void remplirMatriceAuto();
    void remplirMatrice();
    void afficherMatrice();
    void remplirTab();
    void AfficherTab();
    int tranfoDirect(std::string deb,std::string res);
    int research(std::string& rech);
    bool researchTransfo(int base, int rech, int jump);
    bool present(int pos);
    void menu();
};

#endif
