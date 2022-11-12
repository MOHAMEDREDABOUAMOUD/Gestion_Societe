#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>
using namespace std;

class Personne
{
	public:
		Personne(string);//constructeur sans parametre // constructeur par défault
		Personne(int,string,string);//constructeur avec parametre
		~Personne();//Destructeur
		int getage();//getter
		void setage(int);//setter
		string getnom();
		void setnom(string);
		string getcn();
		string Etat();//Autres Methodes
		void Afficher();
	protected:
		int age;
		string nom;
		const string cn;
		
};
#endif
