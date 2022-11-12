#include <iostream>
#include <conio.h>
#include "societe.h"
#include "societev.h"
#include "societeb.h"
using namespace std;

void menurechercher()
{
	cout<<"MENU RECHERCHER"<<endl<<endl<<"1-rechercher par ne"<<endl<<"2-rechercher par nom"<<endl<<"3-rechercher par cin"<<endl<<"4-retour"<<endl<<"votre choix :";
}

void ajouter(societev &s)
{
	int ne,ag;
	string qu,c,no;
	float sa;
	
		cout<<"veuillez saisir le cin              :";
		cin>>c;
	
	cout<<"veuillez saisir l'age               :";
	cin>>ag;
	
	cout<<"veuillez saisir le nom              :";
	cin>>no;	
	
		cout<<"veuillez saisir le num de l'employe :";
		cin>>ne;		

	cout<<"veuillez saisir la qualite          :";
	cin>>qu;
		
	cout<<"veuillez saisir le salaire          :";
	cin>>sa;
		
	s.ajouter(c,ag,no,ne,qu,sa);
}

void ajouterdb(societev &s)
{
	int ne,ag;
	string qu,c,no;
	float sa;
	

		cout<<"veuillez saisir le cin              :";
		cin>>c;
	
	cout<<"veuillez saisir l'age               :";
	cin>>ag;
	
	cout<<"veuillez saisir le nom              :";
	cin>>no;
		
		cout<<"veuillez saisir le num de l'employe :";
		cin>>ne;		
		
	cout<<"veuillez saisir la qualite          :";
	cin>>qu;
		
	cout<<"veuillez saisir le salaire          :";
	cin>>sa;
		
	s.ajouterdebut(c,ag,no,ne,qu,sa);	
}

void ajouterbp(societev &s)
{
	int ne,ag;
	string qu,c,no;
	float sa;
	
		cout<<"veuillez saisir le cin              :";
		cin>>c;
	
	cout<<"veuillez saisir l'age               :";
	cin>>ag;
	
	cout<<"veuillez saisir le nom              :";
	cin>>no;
		
		cout<<"veuillez saisir le num de l'employe :";
		cin>>ne;		
		
	cout<<"veuillez saisir la qualite          :";
	cin>>qu;
		
	cout<<"veuillez saisir le salaire          :";
	cin>>sa;
		
	s.ajouterbp(c,ag,no,ne,qu,sa);	
}

void afficher(societev s)
{
	s.afficher();
}

void recherchercn(societev s)
{
	s.recherchercin();
}

void recherchernom(societev s)
{
	s.recherchernom();
}

void rechercherne(societev s)
{
	s.rechercherne();
}

void rechercher(societev s)
{
	int choix;
	while(choix!=4)
	{
		system("cls");
		menurechercher();
		cin>>choix;
		switch(choix)
		{
			case 1:
				rechercherne(s);getch();
				break;
			case 2:
				recherchernom(s);getch();
				break;
			case 3:
				recherchercn(s);getch();
				break;
		}
	}
}

void modifier(societev &s)
{
	s.modifier();
}

void suprimer(societev &s)
{
	s.suprimer();
}

void trier(societev &s)
{
	s.trier();
}

void save(societev s)
{
	s.save();
}

void load(societev &s)
{
	s.load();	
}

void menu()
{
	cout<<"MENU"<<endl<<endl<<"1-Ajouter"<<endl<<"2-Afficher"<<endl<<"3-Rechercher"<<endl<<"4-Modifier"<<endl<<"5-Suprimer"<<endl<<"6-save"<<endl<<"7-load"<<endl<<"8-trier"<<endl<<"9-ajouter au debut"<<endl<<"10-ajouter bp"<<endl<<"11-chercherfichier"<<endl<<"12-suprimerfichier"<<endl<<"13-Quiter"<<endl<<"votre choix :";
}
		
main()
{
	societev s;	
	
	int a=0,pos,p;
	
	while(a!=13)
	{
		system("cls");
		menu();
		cin>>a;
		system("cls");
		
		switch(a)
		{
			case 1:
				cout<<"\t\t l'ajout d'un employe \n\n";
				ajouter(s);
				break;
			case 2:
				cout<<"\t\t tableau des employes \n\n";
				afficher(s);
				getch();
				break;
			case 3:
				system("cls");
				rechercher(s);
				break;
			case 4:
				cout<<"\t\t tmodification d'un employe \n\n";
				modifier(s);
				break;
			case 5:
				cout<<"\t\t supression d'un employe \n\n";
				suprimer(s);getch();
				break;
			case 6:
				cout<<"\t\t sauvegarder \n\n";
				save(s);
				break;
			case 7:
				cout<<"\t\t charger \n\n";
				load(s);
				break;
			case 8:
				cout<<"\t\t trier le tableau \n\n";getch();
				trier(s);
				break;
			case 9:
				cout<<"\t\t l'ajout d'un employe au debut \n\n";
				ajouterdb(s);
				break;
			case 10:
				cout<<"\t\t l'ajout d'un employe a la bonne place \n\n";
				ajouterbp(s);
				break;
			case 11:
				p=s.rechercherfichier();
				cout<<p;getch();
				break;
			case 12:
				s.suprimerf();
				break;
		}		
	}

}

//void menurechercher()
//{
//	cout<<"MENU RECHERCHER"<<endl<<endl<<"1-rechercher par ne"<<endl<<"2-rechercher par nom"<<endl<<"3-rechercher par cin"<<endl<<"4-retour"<<endl<<"votre choix :";
//}
//
//void ajouter(societe *&s)
//{
//	int ne,ag;
//	string qu,c,no;
//	float sa;
//	
//	do
//	{
//		cout<<"veuillez saisir le cin              :";
//		cin>>c;
//	}while(s->uniquecin(c)==1);
//	
//	cout<<"veuillez saisir l'age               :";
//	cin>>ag;
//	
//	cout<<"veuillez saisir le nom              :";
//	cin>>no;	
//	
//	do
//	{
//		cout<<"veuillez saisir le num de l'employe :";
//		cin>>ne;		
//	}while(s->uniquene(ne)==1);
//		
//	cout<<"veuillez saisir la qualite          :";
//	cin>>qu;
//		
//	cout<<"veuillez saisir le salaire          :";
//	cin>>sa;
//		
//	s->ajouter(c,ag,no,ne,qu,sa);
//}
//
//void ajouterdb(societe *&s)
//{
//	int ne,ag;
//	string qu,c,no;
//	float sa;
//	
//	do
//	{
//		cout<<"veuillez saisir le cin              :";
//		cin>>c;
//	}while(s->uniquecin(c)==1);
//	
//	cout<<"veuillez saisir l'age               :";
//	cin>>ag;
//	
//	cout<<"veuillez saisir le nom              :";
//	cin>>no;
//		
//	do
//	{
//		cout<<"veuillez saisir le num de l'employe :";
//		cin>>ne;		
//	}while(s->uniquene(ne)==1);
//		
//	cout<<"veuillez saisir la qualite          :";
//	cin>>qu;
//		
//	cout<<"veuillez saisir le salaire          :";
//	cin>>sa;
//		
//	s->ajouterdebut(c,ag,no,ne,qu,sa);	
//}
//
//void ajouterbp(societe *&s)
//{
//	int ne,ag;
//	string qu,c,no;
//	float sa;
//	
//	do
//	{
//		cout<<"veuillez saisir le cin              :";
//		cin>>c;
//	}while(s->uniquecin(c)==1);
//	
//	cout<<"veuillez saisir l'age               :";
//	cin>>ag;
//	
//	cout<<"veuillez saisir le nom              :";
//	cin>>no;
//		
//	do
//	{
//		cout<<"veuillez saisir le num de l'employe :";
//		cin>>ne;		
//	}while(s->uniquene(ne)==1);
//		
//	cout<<"veuillez saisir la qualite          :";
//	cin>>qu;
//		
//	cout<<"veuillez saisir le salaire          :";
//	cin>>sa;
//		
//	s->ajouterbp(c,ag,no,ne,qu,sa);	
//}
//
//void afficher(societe *s)
//{
//	s->afficher();
//}
//
//void recherchercn(societe *s)
//{
//	s->recherchercin();
//}
//
//void recherchernom(societe *s)
//{
//	s->recherchernom();
//}
//
//void rechercherne(societe *s)
//{
//	s->rechercherne();
//}
//
//void rechercher(societe *s)
//{
//	int choix;
//	while(choix!=4)
//	{
//		system("cls");
//		menurechercher();
//		cin>>choix;
//		switch(choix)
//		{
//			case 1:
//				rechercherne(s);getch();
//				break;
//			case 2:
//				recherchernom(s);getch();
//				break;
//			case 3:
//				recherchercn(s);getch();
//				break;
//		}
//	}
//}
//
//void modifier(societe *s)
//{
//	s->modifier();
//}
//
//void suprimer(societe *s)
//{
//	s->suprimer();
//}
//
//void trier(societe *&s)
//{
//	s->trier();
//}
//
//void save(societe *s)
//{
//	s->save();
//}
//
//void load(societe *&s)
//{
//	s->load();	
//}
//
//void ajouterstg(societe *&s)
//{
//	int ne,ag,nst;
//	string qu,c,no,dD,dF;
//	float sa;
//	
//	do
//	{
//		cout<<"veuillez saisir le cin              :";
//		cin>>c;
//	}while(s->uniquecin(c)==1);
//	
//	cout<<"veuillez saisir l'age               :";
//	cin>>ag;
//	
//	cout<<"veuillez saisir le nom              :";
//	cin>>no;	
//	
//	do
//	{
//		cout<<"veuillez saisir le num de l'employe :";
//		cin>>ne;		
//	}while(s->uniquene(ne)==1);
//		
//	cout<<"veuillez saisir la qualite          :";
//	cin>>qu;
//		
//	cout<<"veuillez saisir le salaire          :";
//	cin>>sa;
//	
//	cout<<"veuillez saisir le num de stagiaire :";
//	cin>>nst;
//	
//	cout<<"veuillez saisir la dateD            :";
//	cin>>dD;
//	
//	cout<<"veuillez saisir la dateF            :";
//	cin>>dF;
//		
//	s->ajouterstg(c,ag,no,ne,qu,nst,dD,dF);
//}
//
//void afficherstg(societe *s)
//{
//	s->afficherstg();
//}
//
//void menu()
//{
//	cout<<"MENU"<<endl<<endl<<"1-Ajouter"<<endl<<"2-Afficher"<<endl<<"3-Rechercher"<<endl<<"4-Modifier"<<endl<<"5-Suprimer"<<endl<<"6-save"<<endl<<"7-load"<<endl<<"8-trier"<<endl<<"9-ajouter au debut"<<endl<<"10-ajouter bp"<<endl<<"11-Ajouter stagiaire"<<endl<<"12-Afficher stagiaire"<<endl<<"13-Quiter"<<endl<<"votre choix :";
//}
//		
//main()
//{
//	societe *s=NULL;	
//	s=new societe();
//	
//	int a=0,pos;
//	
//	while(a!=13)
//	{
//		system("cls");
//		menu();
//		cin>>a;
//		system("cls");
//		
//		switch(a)
//		{
//			case 1:
//				cout<<"\t\t l'ajout d'un employe \n\n";
//				ajouter(s);
//				break;
//			case 2:
//				cout<<"\t\t tableau des employes \n\n";
//				afficher(s);
//				getch();
//				break;
//			case 3:
//				system("cls");
//				rechercher(s);
//				break;
//			case 4:
//				cout<<"\t\t tmodification d'un employe \n\n";
//				modifier(s);
//				break;
//			case 5:
//				cout<<"\t\t supression d'un employe \n\n";
//				suprimer(s);getch();
//				break;
//			case 6:
//				cout<<"\t\t sauvegarder \n\n";
//				save(s);
//				break;
//			case 7:
//				cout<<"\t\t charger \n\n";
//				load(s);
//				break;
//			case 8:
//				cout<<"\t\t trier le tableau \n\n";getch();
//				trier(s);
//				break;
//			case 9:
//				cout<<"\t\t l'ajout d'un employe au debut \n\n";
//				ajouterdb(s);
//				break;
//			case 10:
//				cout<<"\t\t l'ajout d'un employe a la bonne place \n\n";
//				ajouterbp(s);
//				break;
//			case 11:
//				cout<<"\t\t l'ajout d'un stagiaire \n\n";
//				ajouterstg(s);getch();
//				break;
//			case 12:
//				cout<<"\t\t tableau des stagaires \n\n";
//				afficherstg(s);
//				getch();
//				break;
//		}		
//	}
//
//}
