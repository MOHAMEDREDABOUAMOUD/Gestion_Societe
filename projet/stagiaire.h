#ifndef STAGIAIRE_H
#define STAGIAIRE_H
#include "etudiant.h"

class stagiaire:public etudiant
{
	public:
		stagiaire(string,int,int);
		stagiaire(string,int,string,int,string,int,string,string);
		~stagiaire();
		setdateD(string);
		setdateF(string);
		int getnst();
		string getdateD();
		string getdateF();
	private:
		const int nst;
		string dateD;
		string dateF;
};

#endif
