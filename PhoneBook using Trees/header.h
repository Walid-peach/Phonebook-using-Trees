#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <gtk/gtk.h>
#include <stdbool.h>
#include "Ajouter.h"
#include "Afficher.h"x
#include "rechercher.h"




    GtkBuilder *builder;
    GtkWidget *windowMenu;
    GtkWidget *Enom;
    GtkWidget *Eprenom;
    GtkWidget *Etele;
    GtkWidget *Email;
    GtkListStore *liststore;
    GtkTreeView *Tv;
    GtkTreeViewColumn *cnom;
    GtkTreeViewColumn *cprenom;
    GtkTreeViewColumn *ctel;
    GtkTreeViewColumn *cmail;
    GtkTreeSelection *selection;
    GtkCellRenderer *cl1;
    GtkCellRenderer *cl2;
    GtkCellRenderer *cl3;
    GtkCellRenderer *cl4;
    GtkWidget *buttonAjouter;
    GtkWidget *buttonAnnM;
    GtkWidget *buttonRefresh;
    GtkWidget *buttonRechrecher;
    GtkTreeIter iter;
// declaration de type contact
typedef struct contact {
    char nom[25];
    char prenom[25];
    char telephone[25];
    char mail[25];
}_contact;
typedef struct contact* type_contact;

//declaration noeud tout les noeud sont des chaine de caractere parceque dans les feuilles on va stocker juste le prenom du contact
typedef struct Node{
        char *lettre;
        struct Node *firstChild;
        struct Node *nextSibling;
    }_Node;
typedef struct Node* Type_Node;


#endif // HEADER_H_INCLUDED
