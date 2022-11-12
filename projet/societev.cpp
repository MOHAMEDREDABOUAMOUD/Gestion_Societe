#include "societev.h"

societev::societev()
{
	
}

societev::~societev()
{
	
}

societev::ajouter(string c,int ag,string no,int ne,string qu,float s)
{
	employe *e=NULL;
	
	e= new employe(c,ag,no,ne,qu,s);
	tab.push_back(e);
}

societev::ajouterdebut(string c,int ag,string no,int ne,string qu,float s)
{
	employe *e=NULL;
	
	e= new employe(c,ag,no,ne,qu,s);
	tab.insert(tab.begin(),e);
}

societev::afficher()
{
	for(int i=0;i<tab.size();i++)
	{
		cout<<endl<<tab[i]->getcn()<<" | "<<tab[i]->getage()<<" | "<<tab[i]->getnom()<<" | "<<tab[i]->getne()<<" | "<<tab[i]->getqualite()<<" | "<<tab[i]->getsalaire()<<" | "<<endl;
	}
}

societev::rechercherne()
{
	int n;
	cout<<"veuillez saisir un num d'employe :";
	cin>>n;
	for(int i=0;i<tab.size();i++)
	{
		if(tab[i]->getne()==n)
		{
			cout<<endl<<tab[i]->getcn()<<" | "<<tab[i]->getage()<<" | "<<tab[i]->getnom()<<" | "<<tab[i]->getne()<<" | "<<tab[i]->getqualite()<<" | "<<tab[i]->getsalaire()<<" | "<<endl;
		}
		
	}
}

societev::recherchercin()
{
	string cn;
	cout<<"veuillez saisir un nom d'employe :";
	cin>>cn;
	for(int i=0;i<tab.size();i++)
	{
		if(tab[i]->getcn()==cn)
		{
			cout<<endl<<tab[i]->getcn()<<" | "<<tab[i]->getage()<<" | "<<tab[i]->getnom()<<" | "<<tab[i]->getne()<<" | "<<tab[i]->getqualite()<<" | "<<tab[i]->getsalaire()<<" | "<<endl;
		}
	}
}

societev::recherchernom()
{
	string nom;
	cout<<"veuillez saisir un nom d'employe :";
	cin>>nom;
	for(int i=0;i<tab.size();i++)
	{
		if(tab[i]->getnom()==nom)
		{
			cout<<endl<<tab[i]->getcn()<<" | "<<tab[i]->getage()<<" | "<<tab[i]->getnom()<<" | "<<tab[i]->getne()<<" | "<<tab[i]->getqualite()<<" | "<<tab[i]->getsalaire()<<" | "<<endl;
		}
	}
}


societev::modifier()
{
	int n;
	cout<<"veuillez saisir un num d'employe pour le modifier:";
	cin>>n;
	for(int i=0;i<tab.size();i++)
	{
		if(tab[i]->getne()==n)
		{
			int ag;
			
			string qu,c,no;
			float s;
		
			employe *e=NULL;
		
			cout<<"veuillez saisir l'age       :";
			cin>>ag;
			
			cout<<"veuillez saisir le nom      :";
			cin>>no;
			
			cout<<"veuillez saisir la qualite  :";
			cin>>qu;
			
			cout<<"veuillez saisir le salaire  :";
			cin>>s;
			
			c=tab[i]->getcn();
	
			e= new employe(c,ag,no,n,qu,s);
			tab[i]=e;
			i=tab.size();
		}
	}
}

societev::suprimer()
{
	int n,j;
	cout<<"veuillez saisir un num d'employe pour le suprimer:";
	cin>>n;
	for(int i=0;i<tab.size();i++)
	{
		if(tab[i]->getne()==n)
		{
			tab.erase(tab.begin()+i);
		}
	}
}

societev::ajouterbp(string c,int ag,string no,int ne,string qu,float s)
{
	int trouve=0,i;
	employe *e=NULL;
	e=new employe(c,ag,no,ne,qu,s);
	
	if(tab.size()==0)
	{
		tab.insert(tab.begin(),e);
	}
	else if(e->getage()<tab[0]->getage())
	{
		tab.insert(tab.begin(),e);
	}
	else
	{
		for(i=0;i<tab.size();i++)
		{
			if(e->getage()<tab[i]->getage())
			{
				tab.insert(tab.begin()+i,e);
				i=tab.size();
				trouve=1;
			}
		}
		if(trouve==0)
		{
			tab.insert(tab.begin()+tab.size(),e);
		}
	}
}

societev::trier()
{
	employe *e;
	for(int i=0;i<tab.size();i++)
	{
		for(int j=i+1;j<tab.size();j++)
		{
			if(tab[i]->getage()>tab[j]->getage())
			{
				e=tab[i];
				tab[i]=tab[j];
				tab[j]=e;
			}
		}
	}
}

societev::save()
{
	ofstream f("data1.txt",ios::out|ios::trunc);
	if(f.good())
	{
		for(int i=0;i<tab.size();i++)
		{
			//f<<tab.size()<<endl;
			if(i==tab.size()-1)
			{
				f<<tab[i]->getcn()<<" ";
				f<<tab[i]->getage()<<" ";
				f<<tab[i]->getnom()<<" ";
				f<<tab[i]->getne()<<" ";
				f<<tab[i]->getqualite()<<" ";
				f<<tab[i]->getsalaire();
			}
			else
			{
				f<<tab[i]->getcn()<<" ";
				f<<tab[i]->getage()<<" ";
				f<<tab[i]->getnom()<<" ";
				f<<tab[i]->getne()<<" ";
				f<<tab[i]->getqualite()<<" ";
				f<<tab[i]->getsalaire()<<endl;
			}
			
		}	
		f.close();
	}
	
}

societev::load()
{
	employe *e;
	int n,ag;float s;string qu,no,c;
	int nb=0;
	
	ifstream f("data1.txt",ios::in);
	if(f.good())
	{
		while(!f.eof())
		{
				f>>c>>ag>>no>>n>>qu>>s;
				e= new employe(c,ag,no,n,qu,s);
				tab.push_back(e);
		}	
		f.close();
	}
}

int societev::rechercherfichier()
{
	string cn,c,no,qu;int n,ag,pos=0;float s;
	ifstream f("data1.txt",ios::in);
	if(f.good())
	{
		cout<<"veuillez saisir un cin d'employe :";
		cin>>cn;
		
		while(!f.eof())
		{
			f>>c>>ag>>no>>n>>qu>>s;
			if(c==cn)
			{
				f.close();
				return pos;
			}
			pos=pos+1;
		}
		f.close();
		return -1;
	}
}

societev::suprimerf()
{
	int cp=0;
	string cn,c,no,qu;int n,ag;float s;
	int pos=rechercherfichier();
	if(pos!=-1)
	{
		ifstream f("data1.txt",ios::in);
		ofstream f2("data4.txt",ios::out|ios::trunc);
		if(f.good())
		{
			while(!f.eof())
			{
				if(pos!=cp)
				{
					f>>c>>ag>>no>>n>>qu>>s;
					f2<<c<<ag<<no<<n<<qu<<s;
					if(!f.eof())
					{
						f2<<endl;
					}
				}
				else
				{
					f>>c>>ag>>no>>n>>qu>>s;
				}
				cp++;
			}
			f.close();
			f2.close();
			remove("data1.txt");
			rename("data4.txt","data1.txt");
		}	
	}
	
}
