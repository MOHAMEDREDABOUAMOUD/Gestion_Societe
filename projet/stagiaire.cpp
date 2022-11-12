#include "stagiaire.h"

stagiaire::stagiaire(string c,int ne,int ns):etudiant(c,ne),nst(ns)
{
	dateD="";
	dateF="";
}
stagiaire::stagiaire(string c,int ag,string no,int ne,string nv,int ns,string dD,string dF):etudiant(c,ag,no,ne,nv),nst(ns)
{
	dateD=dD;
	dateF=dF;
}
stagiaire::~stagiaire()
{
	
}
stagiaire::setdateD(string dD)
{
	dateD=dD;
}
stagiaire::setdateF(string dF)
{
	dateF=dF;
}
int stagiaire::getnst()
{
	return nst;
}
string stagiaire::getdateD()
{
	return dateD;
}
string stagiaire::getdateF()
{
	return dateF;
}




