#include "Afficher.h"
// fonction qui afficher tous les contacts dans l 'interface
void afficher_contact(void)
{
        FILE *fcontact;

        fcontact = fopen("repertoire1.txt","r");

        type_contact contact1=(type_contact)malloc(sizeof(_contact)) ;

        int i,n=getFileLinesNumber(fcontact);
        rewind(fcontact);
        for(i=0;i<n;i++){
        fscanf(fcontact,"%s    %s    %s    %s\n",contact1->nom, contact1->prenom, contact1->telephone, contact1-> mail) ;
        gtk_list_store_append(liststore, &iter);
        gtk_list_store_set(liststore, &iter,0 , contact1->nom,-1);
        gtk_list_store_set(liststore, &iter,1 , contact1->prenom,-1);
        gtk_list_store_set(liststore, &iter,2 , contact1->telephone,-1);
        gtk_list_store_set(liststore, &iter,3 , contact1-> mail,-1);

        }
    fclose(fcontact);
}




