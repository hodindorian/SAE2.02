/**
*\ file erreur.hpp
*\ brief Ce fichier sert à créer le code générant les erreurs
*\ author ASTOLFI Vincent
*\ date 1 avril 2022
*/


#ifndef ERREUR_HPP
#define ERREUR_HPP

#include <iostream>
#include <exception>
#include <string>
/**
* \ brief créer une erreur quand un objet n'as pas de transformation possible
* \ param std::string msg
* \ return un message d'erreur et une exeption
*/
class VideException:public std::exception{
    std::string msg{"\033[01;31mERROR : votre objet n'as aucune transformation possible\033[00m\n"};
public:
    VideException() {std::cout<<msg;}
    const char *what() const noexcept override { return msg.c_str(); }
};
/**
* \ brief créer une erreur quand un objet est appelé mais n"existe pas
* \ param std::string msg
* \ return un message d'erreur et une exeption
*/
class InconnueException:public std::exception{
    std::string m;
    std::string msg{"\033[01;31mERROR : le maillon "+m+" n'existe pas !\033[00m\n"};
public:
    InconnueException(std::string m) :m{m} {std::cout<<msg;}
    const char *what() const noexcept override {return msg.c_str(); }
};
/**
* \ brief créer une erreur quand on donne un choix qui n'est pas proposé
* \ param std::string msg
* \ return un message d'erreur et une exeption
*/
class MauvaisCINException: public std::exception{
    std::string msg{"\033[01;31mERROR : veuillez donner l'un des choix possible !\033[00m\n"};
public:
    MauvaisCINException() {std::cout<<msg;}
    const char *what() const noexcept override { return msg.c_str(); }
};

#endif // ERREUR_HPP