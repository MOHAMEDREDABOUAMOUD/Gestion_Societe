#ifndef ETUDIANT_H
#define ETUDIANT_H
#include "Personne.h"
class etudiant:public Personne
{
	public:
		etudiant(string,int);
		etudiant(string,int,string,int,string);
		~etudiant();
		setniveau(string);
		int getnet();
		string getniveau();
	private:
		const int net;
		string niveau;
};

#endif
