#include "Personne.h"

Personne::Personne(string c):cn(c)
{
	age=0;
	nom="";
}

Personne::Personne(int age,string nom,string c):cn(c)
{
	this->age=age;
	this->nom=nom;
}

Personne::~Personne()
{
	
}

int Personne::getage()
{
	return age;
}

void Personne::setage(int age)
{
	this->age=age;
}

string Personne::Etat()
{
	if(age<18)
	{
		return "mineur";
	}
	else
	{
		return "majeur";
	}
}

string Personne::getnom()
{
	return nom;
}

void Personne::setnom(string nom)
{
	this->nom=nom;
}

string Personne::getcn()
{
	return cn;
}

void Personne::Afficher()
{
	cout<<"Personne : "<<age<<" "<<nom<<" "<<cn<<endl;
}
