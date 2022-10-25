/**
*\ file maillon.hpp
*\ brief Ce fichier sert à créer la classe maillon 
*\ author ASTOLFI Vincent
*\ date 1 avril 2022
*/

#ifndef MAILLON_HPP
#define MAILLON_HPP

#include <string>
#include <list>
#include <vector>
#include "liste.hpp"

class Maillon{
private:
	std::string designation;
public:
	std::list<Maillon*> transfo;
	
public:
	Maillon(std::string nom);
	std::string getDesignation() const;
	void creerListeTransfo(std::list<Maillon*> l, Liste L1);
	void supprimerListeTransfo();
	void creerListeTransfoA(Maillon &m1,std::list<Maillon*> l);
	void affichTransfoListe();
	void transformer(std::string m, std::vector<std::string> tmp);
	void viderLesListes();

};

std::ostream& operator<<(std::ostream& s,Maillon &m);
bool operator!=(const Maillon& m1, const Maillon& m2);
bool operator==(const Maillon& m1, const Maillon& m2);

#endif
