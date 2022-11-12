#include "employe.h"

employe::employe(string c,int n):Personne(0,"",c),ne(n)
{
	qualite="";
	salaire=0;
}
employe::employe(string c,int ag,string no,int n,string q,float s):Personne(ag,no,c),ne(n)
{
	qualite=q;
	salaire=s;
}
int employe::getnbs()
{
	return nbs;
}
void employe::incnbs()
{
	nbs++;
}
void employe::setqualite(string q)
{
	qualite=q;
}
void employe::setsalaire(float s)
{
	salaire=s;
}
int employe::getne()
{
	return ne;
}
string employe::getqualite()
{
	return qualite;
}
float employe::getsalaire()
{
	return salaire;
}
void employe::ajouterstgiaire(int ns)
{
	listestagiaire *p,*q;
	if(tetest==NULL)
	{
		p=new listestagiaire;
		p->info=ns;
		p->suiv=NULL;
		tetest=p;
	}
	else
	{
		p=tetest;
		while(p->suiv!=NULL)
		{
			p=p->suiv;
		}
		q=new listestagiaire;
		q->info=ns;
		q->suiv=NULL;
		p->suiv=q;
	}
}
void employe::afficherstagiaire()
{
	listestagiaire *p;
	p=tetest;
	while(p!=NULL)
	{
		cout<<p->info<<" | ";
		p=p->suiv;
	}
	cout<<endl;
}
