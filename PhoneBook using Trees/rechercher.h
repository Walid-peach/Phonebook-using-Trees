#ifndef RECHERCHER_H
#define RECHERCHER_H
#include "header.h"
#include "Ajouter.h"



    GtkWidget *windowRechercher;
    GtkWidget *buttonSearch;
    GtkWidget *buttonAnnR;
    GtkWidget *buttonSupp;
    GtkWidget *buttonModifier;
    GtkWidget *EnomR;

    GtkListStore *liststore1;
    GtkTreeView *Tv1;
    GtkTreeViewColumn *cnom1;
    GtkTreeViewColumn *cprenom1;
    GtkTreeViewColumn *ctel1;
    GtkTreeViewColumn *cmail1;
    GtkTreeSelection *selection1;
    GtkCellRenderer *cl5;
    GtkCellRenderer *cl6;
    GtkCellRenderer *cl7;
    GtkCellRenderer *cl8;
    GtkTreeIter iter1;
    GtkLabel *labelRecherche;


void showRechercher(GtkWidget *widget,gpointer data);
void closeR(GtkWidget *widget,gpointer data);
void afficher_recherche(void);
void supprimer(void);
Type_Node searchchanged(Type_Node root,char* name);
Type_Node searchname(Type_Node root,char* name);
void remplirtrouves( Type_Node root);
void chercherContact(char *name);
void SuppContact(char *name);
type_contact recherfiles( char *name);
void Searchall(GtkWidget *widget,gpointer data);
void modifier(void);


#endif  RECHERCHER_H

