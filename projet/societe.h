#ifndef SOCIETE_H
#define SOCIETE_H
#include "employe.h"
#include "stagiaire.h"
#include <iostream>
#include<fstream>
using namespace std;

struct liste
{
	employe *e;
	liste *suiv;
};

struct listestg
{
	stagiaire *s;
	listestg *suiv;
};

class societe
{
	public:
		societe();
		~societe();
		int uniquene(int);
		int uniquecin(string);
		ajouter(string,int,string,int,string,float);
		afficher();
		rechercherne();
		recherchercin();
		recherchernom();
		modifier();
		suprimer();
		save();
		load();
		ajouterdebut(string,int,string,int,string,float);
		trier();
		ajouterbp(string,int,string,int,string,float);
		ajouterstg(string,int,string,int,string,int,string,string);
		afficherstg();
	private:
		liste *tete=NULL;
		listestg *tetestg=NULL;
};

#endif
