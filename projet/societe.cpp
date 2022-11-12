#include "societe.h"

societe::societe()
{
	tete=NULL;
}

societe::~societe()
{
	
}

int societe::uniquecin(string cn)
{
	liste *p=tete;
	while(p!=NULL)
	{
		if(p->e->getcn()==cn)
		{
			return 1;
		}
		p=p->suiv;
	}
	return 0;
}

int societe::uniquene(int ne)
{
	liste *p=tete;
	while(p!=NULL)
	{
		if(p->e->getne()==ne)
		{
			return 1;
		}
		p=p->suiv;
	}
	return 0;
}

societe::ajouter(string c,int ag,string no,int ne,string qu,float s)
{
	liste *p,*q;
	employe *e=NULL;
	
	if(tete==NULL)
	{
		tete= new liste;
		e= new employe(c,ag,no,ne,qu,s);
		tete->e=e;
		tete->suiv=NULL;
	}
	else
	{
		e= new employe(c,ag,no,ne,qu,s);
		
		q=tete;
		while(q->suiv!=NULL)
		{
			q=q->suiv;
		}
		p=new liste;
		p->e=e;
		q->suiv=p;
		p->suiv=NULL;		
	}
}

societe::ajouterdebut(string c,int ag,string no,int n,string qu,float s)
{
	liste *p,*q;
	employe *e=NULL;
	e=new employe(c,ag,no,n,qu,s);
	p= new liste;
	p->e=e;
	q=tete;
	tete=p;
	p->suiv=q;
}

societe::ajouterbp(string c,int ag,string no,int n,string qu,float s)
{
	int trouve=0;
	liste *p,*q;
	employe *e=NULL;
	e=new employe(c,ag,no,n,qu,s);
	q=new liste;
	p=tete;
	
	if(p==NULL)
	{
		societe::ajouter(c,ag,no,n,qu,s);
	}
	else if(e->getage()<p->e->getage())
	{
		societe::ajouterdebut(c,ag,no,n,qu,s);
	}
	else
	{
		while((p->suiv!=NULL)&&(trouve==0))
		{
			if(e->getage()<p->suiv->e->getage())
			{
				q->e=e;
				q->suiv=p->suiv;
				p->suiv=q;
				trouve=1;
			}
			p=p->suiv;
		}	
		if(trouve==0)
		{
			societe::ajouter(c,ag,no,n,qu,s);
		}
	}
}

societe::afficher()
{
	liste *p;
	p=tete;
	if(p==NULL)
	{
		cout<<"liste vide !";
	}
	while(p!=NULL)
	{
		cout<<p->e->getcn()<<" | "<<p->e->getage()<<" | "<<p->e->getnom()<<" | "<<p->e->getne()<<" | "<<p->e->getqualite()<<" | "<<p->e->getsalaire()<<" | ";
		p->e->afficherstagiaire();	
		p=p->suiv;
	}
}
societe::rechercherne()
{
	liste *p;
	p=tete;
	int ne,trouve=0;
	
	cout<<"donner le num d'employe que vous voulez recuperer ses infos :";
	cin>>ne;
	
	while(p!=NULL)
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
societe::recherchercin()
{
	liste *p;
	p=tete;
	string cn;
	int trouve=0;
	
	cout<<"donner le cin d'employe que vous voulez recuperer ses infos :";
	cin>>cn;
	
	while(p!=NULL)
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
societe::recherchernom()
{
	liste *p;
	p=tete;
	string nom;
	int trouve=0;
	
	cout<<"donner le nom d'employe que vous voulez recuperer ses infos :";
	cin>>nom;
	
	while(p!=NULL)
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
societe::modifier()
{
	int n,ag;
	int ne;
	string qu,c,no;
	float s;

	employe *e=NULL;
	liste *p=NULL;
	
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
	while((p->e->getne()!=n)&&(p!=NULL))
	{
		p=p->suiv;
	}
	if(p==NULL)
	{
		cout<<"employe introuvable";
	}
	else
	{
		e= new employe(p->e->getcn(),ag,no,n,qu,s);
		p->e=e;		
	}
}
societe::suprimer()
{
	int n,trouve=0;
	liste *p,*q;
	cout<<"donner le num d'employe que vous voulez supprimer :";
	cin>>n;
	p=tete;
	if(tete->e->getne()==n)
	{
		tete=tete->suiv;
		delete(p);
		trouve=1;
	}
	else
	{
		while((p!=NULL)&&(p->e->getne()!=n))
		{
			q=p;
			p=p->suiv;
		}
		if(p!=NULL)
		{
			q->suiv=p->suiv;
			delete(p);
			trouve=1;	
		}
		
	}
	if(trouve==0)
	{
		cout<<"employe introuvable !";
	}
}

societe::trier()
{
	liste *p=NULL,*q=NULL;
	employe *e=NULL;
	p=tete;
	q=p->suiv;
	while(p!=NULL)
	{
		while(q!=NULL)
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

societe::save()
{
	ofstream f("data.txt",ios::out|ios::trunc);
	if(f.good())
	{
		liste *p;
		p=tete;
		while(p!=NULL)
		{
			if(p->suiv==NULL)
			{
				f<<p->e->getcn()<<endl;
				f<<p->e->getage()<<endl;
				f<<p->e->getnom()<<endl;
				f<<p->e->getne()<<endl;
				f<<p->e->getqualite()<<endl;
				f<<p->e->getsalaire();
				p=p->suiv;	
			}
			else
			{
				f<<p->e->getcn()<<endl;
				f<<p->e->getage()<<endl;
				f<<p->e->getnom()<<endl;
				f<<p->e->getne()<<endl;
				f<<p->e->getqualite()<<endl;
				f<<p->e->getsalaire()<<endl;
				p=p->suiv;
			}
			
		}	
		f.close();
	}
	
}

societe::load()
{
	liste *p,*q;
	employe *e;
	int n,ag;float s;string qu,no,c;
	
	ifstream f("data.txt",ios::in);
	if(f.good())
	{
		while(!f.eof())
		{
			if(tete==NULL)
			{
				tete= new liste;
				f>>c;f>>ag;f>>no;f>>n;f>>qu;f>>s;
				e= new employe(c,ag,no,n,qu,s);
				tete->e=e;	
				tete->suiv=NULL;	
			}
			else
			{
				f>>c;f>>ag;f>>no;f>>n;f>>qu;f>>s;
				e= new employe(c,ag,no,n,qu,s);
				q=tete;
				while(q->suiv!=NULL)
				{
					q=q->suiv;
				}
				p=new liste;
				p->e=e;
				q->suiv=p;
				p->suiv=NULL;
			}
		}	
		f.close();
	}
}

societe::ajouterstg(string c,int ag,string no,int ne,string nv,int ns,string dD,string dF)
{
	listestg *p,*q;
	stagiaire *s=NULL;
	
	
	liste *employ=tete;
	bool exist=false;
	while((employ!=NULL)&&(exist==false))
	{
			if(employ->e->getnbs()<3)
			{
				employ->e->incnbs();
				employ->e->ajouterstgiaire(ns);
				exist=true;
			}
			else
			{
				employ=employ->suiv;
			}
	}
	if(exist==false)
	{
		cout<<"impossible d'ajouter un stagiaire!"<<endl;
	}
	else
	{
		if(tetestg==NULL)
		{
			tetestg= new listestg;
			s= new stagiaire(c,ag,no,ne,nv,ns,dD,dF);
			tetestg->s=s;
			tetestg->suiv=NULL;
		}
		else
		{
			s= new stagiaire(c,ag,no,ne,nv,ns,dD,dF);
			q=tetestg;
			while(q->suiv!=NULL)
			{
				q=q->suiv;
			}
			p=new listestg;
			p->s=s;
			q->suiv=p;
			p->suiv=NULL;
		}
	}
	
	
	
	
//	if(tetestg==NULL)
//	{
//		liste *employ=tete;
//		bool exist=false;
//		while((employ!=NULL)&&(exist==false))
//		{
//				if(employ->e->getnbs()<3)
//				{
//					employ->e->incnbs();
//					employ->e->ajouterstgiaire(ns);
//					exist=true;
//				}
//				else
//				{
//					employ=employ->suiv;
//				}
//		}
//		if(exist==false)
//		{
//			cout<<"impossible d'ajouter un stagiaire!"<<endl;
//		}
//		else
//		{
//			tetestg= new listestg;
//			s= new stagiaire(c,ag,no,ne,nv,ns,dD,dF);
//			tetestg->s=s;
//			tetestg->suiv=NULL;
//		}
//	}
//	else
//	{
//		liste *employ=tete;
//		bool exist=false;
//		while((employ!=NULL)&&(exist==false))
//		{
//				if(employ->e->getnbs()<3)
//				{
//					employ->e->incnbs();
//					employ->e->ajouterstgiaire(ns);
//					exist=true;
//				}
//				else
//				{
//					employ=employ->suiv;
//				}
//		}
//		if(exist==false)
//		{
//			cout<<"impossible d'ajouter!"<<endl;
//		}
//		else
//		{
//			s= new stagiaire(c,ag,no,ne,nv,ns,dD,dF);
//			q=tetestg;
//			while(q->suiv!=NULL)
//			{
//				q=q->suiv;
//			}
//			p=new listestg;
//			p->s=s;
//			q->suiv=p;
//			p->suiv=NULL;	
//		}
//	}
}
societe::afficherstg()
{
	listestg *p;
	p=tetestg;
	if(p==NULL)
	{
		cout<<"liste vide !";
	}
	while(p!=NULL)
	{
		cout<<p->s->getcn()<<"|"<<p->s->getage()<<"|"<<p->s->getnom()<<"|"<<p->s->getnet()<<"|"<<p->s->getniveau()<<"|"<<p->s->getnst()<<"|"<<p->s->getdateD()<<"|"<<p->s->getdateF()<<endl;	
		p=p->suiv;
	}
}
