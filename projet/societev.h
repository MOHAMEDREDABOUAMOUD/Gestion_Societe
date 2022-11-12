#include "employe.h"
#include <iostream>
#ifndef SOCIETEV_H
#define SOCIETEV_H
#include <fstream>
#include <vector>
using namespace std;

class societev
{
	public:
		societev();
		~societev();
		ajouter(string,int,string,int,string,float);
		afficher();
		rechercherne();
		modifier();
		suprimer();
		ajouterbp(string,int,string,int,string,float);
		trier();
		recherchercin();
		recherchernom();
		ajouterdebut(string,int,string,int,string,float);
		save();
		load();
		suprimerf();
		int rechercherfichier();
	private:
		vector<employe*>tab;
};
#endif
