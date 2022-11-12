#include "etudiant.h"

etudiant::etudiant(string c,int n):Personne(c),net(n)
{
	niveau="";
}
etudiant::etudiant(string c,int ag,string no,int n,string nv):Personne(ag,no,c),net(n)
{
	niveau=nv;
}
etudiant::~etudiant()
{
	
}
etudiant::setniveau(string nv)
{
	niveau=nv;
}
int etudiant::getnet()
{
	return net;
}
string etudiant::getniveau()
{
	return niveau;
}
