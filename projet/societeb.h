#ifndef SOCIETEB_H
#define SOCIETEB_H
#include "employe.h"
#include <iostream>
#include <fstream>
struct liste1
{
	employe *e;
	liste1 *suiv;
	liste1 *pred;
};

class societeb
{
	public:
		societeb();
		~societeb();
		ajouter(string,int,string,int,string,float);
		ajouterdebut(string,int,string,int,string,float);
		ajouterbp(string,int,string,int,string,float);
		afficher();
		rechercherne();
		recherchercin();
		recherchernom();
		modifier();
		suprimer();
		trier();
		save();
		load();
	private:
		liste1 *tete;
};

#endif
