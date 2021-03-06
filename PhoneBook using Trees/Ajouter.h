#ifndef AJOUTER_H
#define AJOUTER_H
#include "header.h"


//--------------Declaration des Variables

    GtkWidget *windowAjouter;
    GtkLabel *labelexiste;
    GtkWidget *buttonSave;
    GtkWidget *buttonAnn;



//prototypes des fonctions utilisés dans ajouter.c

bool rechercher( char *name1, char* name2 );
void AjouterContact (type_contact contacts );
void showAjouter(void);
void print(GtkWidget *widget, gpointer data);
int  getFileLinesNumber(FILE *fp);
void windowexistedeja(GtkWidget *widget, gpointer data);
void close(GtkWidget *widget,gpointer data);
void quit(GtkWidget *widget,gpointer data);
void corriger(type_contact ptr);






#endif  AJOUTER_H
