/**
*\ file liste.hpp
*\ brief Ce fichier sert à créer la classe liste pour le réseau en liste
*\ author ASTOLFI Vincent
*\ date 1 avril 2022
*/

#ifndef LISTE_HPP
#define LISTE_HPP

#include <list>
#include <string>
#include <vector>

class Maillon;
class Liste{
private:
	int nbMaillon;
public:
	std::list<Maillon*> LesMaillons; 
public:
	Liste(int nbMaillon);
	int getNbMaillon() const;
	void creerList(std::vector<std::string> v);
	void creerListAuto(std::vector<Maillon*> v);
	void affichListe();
	void creerDependense();
	void viderLaListe();
};

#endif
