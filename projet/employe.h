#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "Personne.h"
#include <iostream>
using namespace std;

struct listestagiaire
{
	int info;
	listestagiaire *suiv;	
};

class employe: public Personne
{
	public:
		employe(string,int);
		employe(string,int,string,int,string,float);
		void setqualite(string);
		void setsalaire(float);
		int getne();
		string getqualite();
		float getsalaire();	
		int getnbs();
		void incnbs();
		void ajouterstgiaire(int);
		void afficherstagiaire();
	private:
		const int ne;
		string qualite;
		float salaire;
		int nbs=0;
		listestagiaire *tetest=NULL;
};

#endif
