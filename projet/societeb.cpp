#include "societeb.h"


societeb::societeb()
{
	tete=NULL;
}

societeb::~societeb()
{
	
}

societeb::ajouter(string c,int ag,string no,int ne,string qu,float s)
{
	liste1 *p,*q;
	if(tete==NULL)
	{
		employe *e=NULL;
		e= new employe(c,ag,no,ne,qu,s);
		tete=new liste1;
		tete->e=e;
		tete->pred=tete;
		tete->suiv=tete;
	}
	else if(tete->suiv==tete)
	{
		p= new liste1;
		employe *e=NULL;
		e= new employe(c,ag,no,ne,qu,s);
		p->e=e;
		tete->suiv=p;
		tete->pred=p;
		p->suiv=tete;
		p->pred=tete;
	}
	else
	{
		q=tete->pred;
		employe *e=NULL;
		e= new employe(c,ag,no,ne,qu,s);
		p=new liste1;
		p->e=e;
		p->pred=q;
		p->suiv=tete;
		q->suiv=p;
		tete->pred=p;
	}
}

societeb::ajouterdebut(string c,int ag,string no,int n,string qu,float s)
{
	liste1 *p,*q;
	if(tete==NULL)
	{
		ajouter(c,ag,no,n,qu,s);
	}
	else
	{
		employe *e=NULL;
		e=new employe(c,ag,no,n,qu,s);
		p= new liste1;
		p->e=e;
		p->suiv=tete;
		p->pred=tete->pred;
		tete->pred->suiv=p;
		tete->pred=p;
		tete=p;
	}
	
}

societeb::ajouterbp(string c,int ag,string no,int ne,string qu,float s)
{
	int trouve=0;
	liste1 *p,*q;
	employe *e=NULL;
	e=new employe(c,ag,no,ne,qu,s);
	q=new liste1;
	p=tete;
	
	if(p==NULL)
	{
		ajouter(c,ag,no,ne,qu,s);
	}
	else if(e->getage()<p->e->getage())
	{
		ajouterdebut(c,ag,no,ne,qu,s);
	}
	else
	{
		p=p->suiv;
		while((p!=tete)&&(trouve==0))
		{
			if(e->getage()<p->e->getage())
			{
				q->e=e;
				q->suiv=p;
				q->pred=p->pred;
				p->pred->suiv=q;
				p->pred=q;
				trouve=1;
			}
			p=p->suiv;
		}	
		if(trouve==0)
		{
			ajouter(c,ag,no,ne,qu,s);
		}
	}
}

societeb::afficher()
{
	liste1 *p;
	p=tete;
	if(p==NULL)
	{
		cout<<"liste vide !";
	}
	else
	{
		cout<<p->e->getcn()<<"|"<<p->e->getage()<<"|"<<p->e->getnom()<<"|"<<p->e->getne()<<"|"<<p->e->getqualite()<<"|"<<p->e->getsalaire()<<endl;	
		p=p->suiv;
		while(p!=tete)
		{
			cout<<p->e->getcn()<<"|"<<p->e->getage()<<"|"<<p->e->getnom()<<"|"<<p->e->getne()<<"|"<<p->e->getqualite()<<"|"<<p->e->getsalaire()<<endl;	
			p=p->suiv;
		}	
	}
	
}

societeb::rechercherne()
{
	liste1 *p;
	p=tete;
	int ne,trouve=0;
	
	cout<<"donner le num d'employe que vous voulez recuperer ses infos :";
	cin>>ne;
	
	if(p->e->getne()==ne)
	{
		cout<<p->e->getcn()<<"|"<<p->e->getage()<<"|"<<p->e->getnom()<<"|"<<p->e->getne()<<"|"<<p->e->getqualite()<<"|"<<p->e->getsalaire()<<endl;
		trouve=1;
	}
	p=p->suiv;
		
	while(p!=tete)
	{
		if(p->e->getne()==ne)
		{
			cout<<p->e->getcn()<<"|"<<p->e->getage()<<"|"<<p->e->getnom()<<"|"<<p->e->getne()<<"|"<<p->e->getqualite()<<"|"<<p->e->getsalaire()<<endl;
			trouve=1;
		}
		p=p->suiv;
	}
	if(trouve==0)
	{
		cout<<"employe introuvable";
	}
}

societeb::recherchercin()
{
	liste1 *p;
	p=tete;
	int trouve=0;
	string cn;
	
	cout<<"donner le cin que vous voulez recuperer ses infos :";
	cin>>cn;
	
	if(p->e->getcn()==cn)
	{
		cout<<p->e->getcn()<<"|"<<p->e->getage()<<"|"<<p->e->getnom()<<"|"<<p->e->getne()<<"|"<<p->e->getqualite()<<"|"<<p->e->getsalaire()<<endl;
		trouve=1;
	}
	p=p->suiv;
		
	while(p!=tete)
	{
		if(p->e->getcn()==cn)
		{
			cout<<p->e->getcn()<<"|"<<p->e->getage()<<"|"<<p->e->getnom()<<"|"<<p->e->getne()<<"|"<<p->e->getqualite()<<"|"<<p->e->getsalaire()<<endl;
			trouve=1;
		}
		p=p->suiv;
	}
	if(trouve==0)
	{
		cout<<"employe introuvable";
	}
}

societeb::recherchernom()
{
	liste1 *p;
	p=tete;
	int trouve=0;
	string nom;
	
	cout<<"donner le nom que vous voulez recuperer ses infos :";
	cin>>nom;
	
	if(p->e->getnom()==nom)
	{
		cout<<p->e->getcn()<<"|"<<p->e->getage()<<"|"<<p->e->getnom()<<"|"<<p->e->getne()<<"|"<<p->e->getqualite()<<"|"<<p->e->getsalaire()<<endl;
		trouve=1;
	}
	p=p->suiv;
		
	while(p!=tete)
	{
		if(p->e->getnom()==nom)
		{
			cout<<p->e->getcn()<<"|"<<p->e->getage()<<"|"<<p->e->getnom()<<"|"<<p->e->getne()<<"|"<<p->e->getqualite()<<"|"<<p->e->getsalaire()<<endl;
			trouve=1;
		}
		p=p->suiv;
	}
	if(trouve==0)
	{
		cout<<"employe introuvable";
	}
}

societeb::modifier()
{
	int n,ag;
	int ne;
	string qu,c,no;
	float s;

	employe *e=NULL;
	liste1 *p=NULL;
	
	cout<<"donner le num d'employe que vous voulez modifier :";
	cin>>n;

	cout<<"veuillez saisir l'age       :";
	cin>>ag;
	
	cout<<"veuillez saisir le nom      :";
	cin>>no;
	
	cout<<"veuillez saisir la qualite  :";
	cin>>qu;
	
	cout<<"veuillez saisir le salaire  :";
	cin>>s;
	
	
	p=tete;
	if(p==NULL)
	{
		cout<<"employe introuvable";
	}
	else if(p->e->getne()==n)
	{
		e= new employe(p->e->getcn(),ag,no,n,qu,s);
		p->e=e;
	}
	else
	{
		p=p->suiv;
		while((p->e->getne()!=n)&&(p!=tete))
		{
			p=p->suiv;
		}
			e= new employe(p->e->getcn(),ag,no,n,qu,s);
			p->e=e;
	}
}

societeb::suprimer()
{
	int n,trouve=0;
	liste1 *p,*q;
	cout<<"donner le num d'employe que vous voulez supprimer :";
	cin>>n;
	if(tete->suiv==tete)
	{
		delete tete;
		tete=NULL;
		trouve=1;
	}
	else if(tete->e->getne()==n)
	{
		p=tete;
		tete=tete->suiv;
		p->pred->suiv=tete;
		tete->pred=p->pred;
		delete p;
		trouve=1;
	}
	else
	{
		p=tete->suiv;
		while((p!=tete)&&(trouve==0))
		{
			if(p->e->getne()==n)
			{
				p->pred->suiv=p->suiv;
				p->suiv->pred=p->pred;
				delete p;
				trouve=1;	
			}
				p=p->suiv;	
		}
		
	}
	if(trouve==0)
	{
		cout<<"employe introuvable !";
	}
}

societeb::trier()
{
	liste1 *p,*q;
	employe *e=NULL;
	p=tete;
	q=p->suiv;
	while(p->suiv!=tete)
	{
		while(q!=tete)
		{
			if(p->e->getage()>q->e->getage())
			{
				e=p->e;
				p->e=q->e;
				q->e=e;
			}
			q=q->suiv;
		}
		p=p->suiv;
		if(p!=NULL)
		{
			q=p->suiv;			
		}
	}
}

societeb::save()
{
	ofstream f("data2.txt",ios::out|ios::trunc);
	if(f.good())
	{
		liste1 *p;
		p=tete;
		if(p->suiv==NULL)
			{
				f<<p->e->getcn()<<endl<<p->e->getage()<<endl<<p->e->getnom()<<endl<<p->e->getne()<<endl<<p->e->getqualite()<<endl<<p->e->getsalaire();
				p=p->suiv;	
			}
		else
			{
				f<<p->e->getcn()<<endl<<p->e->getage()<<endl<<p->e->getnom()<<endl<<p->e->getne()<<endl<<p->e->getqualite()<<endl<<p->e->getsalaire()<<endl;
				p=p->suiv;
			}
		p=p->suiv;
		while(p!=tete)
		{
			if(p->suiv==tete)
			{
				f<<p->e->getcn()<<endl<<p->e->getage()<<endl<<p->e->getnom()<<endl<<p->e->getne()<<endl<<p->e->getqualite()<<endl<<p->e->getsalaire();
				p=p->suiv;	
			}
			else
			{
				f<<p->e->getcn()<<endl<<p->e->getage()<<endl<<p->e->getnom()<<endl<<p->e->getne()<<endl<<p->e->getqualite()<<endl<<p->e->getsalaire()<<endl;
				p=p->suiv;
			}
			
		}	
		f.close();
	}
	
}

societeb::load()
{
	liste1 *p,*q;
	employe *e;
	int n,ag;float s;string qu,no,c;
	
	ifstream f("data2.txt",ios::in);
	if(f.good())
	{
		while(!f.eof())
		{
			f>>c;f>>ag;f>>no;f>>n;f>>qu;f>>s;
			ajouter(c,ag,no,n,qu,s);
		}	
		f.close();
	}
}
