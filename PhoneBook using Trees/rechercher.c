#include "rechercher.h"

void showRechercher(GtkWidget *widget,gpointer data){


    builder          = gtk_builder_new_from_file ("SdaGlade.glade#");
    windowRechercher = GTK_WIDGET(gtk_builder_get_object (builder, "windowRechercher"));
    buttonSearch     = GTK_WIDGET(gtk_builder_get_object (builder, "buttonSearch"));
    buttonAnnR       = GTK_WIDGET(gtk_builder_get_object (builder, "buttonAnnR"));
    buttonSupp       = GTK_WIDGET(gtk_builder_get_object (builder, "buttonSupp"));
    buttonModifier   = GTK_WIDGET(gtk_builder_get_object (builder, "buttonModifier"));
    liststore1       = GTK_LIST_STORE(gtk_builder_get_object(builder,"liststore1"));
    Tv1              = GTK_TREE_VIEW(gtk_builder_get_object(builder,"Tv1"));
    cnom             = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"cnom1"));
    cprenom          = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"cprenom1"));
    cl1              = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cl5"));
    selection        = GTK_TREE_SELECTION(gtk_builder_get_object(builder, "select1"));
    cl2              = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cl6"));
    cl3              = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cl7"));
    cl4              = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cl8"));
    selection        = gtk_tree_view_get_selection(GTK_TREE_VIEW(Tv1));
    EnomR            = GTK_WIDGET(gtk_builder_get_object (builder, "ENomR"));




    gtk_window_set_position(GTK_WINDOW(windowRechercher), GTK_WIN_POS_CENTER);

    g_signal_connect(buttonSearch, "clicked", G_CALLBACK(Searchall),NULL);
    g_signal_connect(buttonSupp, "clicked", G_CALLBACK(supprimer),NULL);
    g_signal_connect(buttonModifier, "clicked", G_CALLBACK(modifier),NULL);





    g_signal_connect(buttonAnnR, "clicked", G_CALLBACK(closeR),NULL);





    gtk_widget_show_all(windowRechercher);
    gtk_main();



}

void afficher_recherche(void)
{
        FILE *frecherch;

        type_contact contact1=(type_contact)malloc(sizeof(_contact)) ;
        frecherch = fopen("trouver.txt","r");
        int i,n=getFileLinesNumber(frecherch);
        rewind(frecherch);
        for(i=0;i<n;i++){
        fscanf(frecherch,"%s    %s    %s    %s\n",contact1->nom, contact1->prenom, contact1->telephone, contact1-> mail) ;
        gtk_list_store_append(liststore1, &iter1);
        gtk_list_store_set(liststore1, &iter1,0 , contact1->nom,-1);
        gtk_list_store_set(liststore1, &iter1,1 , contact1->prenom,-1);
        gtk_list_store_set(liststore1, &iter1,2 , contact1->telephone,-1);
        gtk_list_store_set(liststore1, &iter1,3 , contact1-> mail,-1);

        }
    fclose(frecherch);
    remove("trouver.txt");
}


void Searchall(GtkWidget *widget,gpointer data){

        type_contact ptr =(type_contact)malloc(sizeof(_contact));

        strcpy( ptr->nom, gtk_entry_get_text(GTK_ENTRY( EnomR))) ;
        printf("%s",ptr->nom);
        chercherContact(ptr->nom);
        afficher_recherche();
        //g_signal_connect(G_OBJECT(windowRechercher), "destroy",G_CALLBACK(gtk_main_quit), NULL);



}

void closeR(GtkWidget *widget,gpointer data) {

    gtk_window_close (windowRechercher);
    g_signal_connect(G_OBJECT(windowRechercher), "destroy",G_CALLBACK(gtk_main_quit), NULL);

}


Type_Node searchchanged(Type_Node root,char* name){
  if(name[1] == '\0'){
  Type_Node ptr=recherche(root,chartostr1(name[0])) ;
  if(strcmp(ptr->lettre ,chartostr1(name[0])) ==0 ) {
    ptr=ptr->firstChild;
    do{
      Type_Node ptr2=ptr->firstChild;
      do{
      printf("%s \n",ptr2->lettre);
      ptr2=ptr2->nextSibling;
      }while(ptr2 !=NULL);
      ptr=ptr->nextSibling;
    }while(ptr !=NULL);
  }
  else return NULL;
  }
  else if(name[2] == '\0'){
    Type_Node ptr=recherche(root,chartostr1(name[0])) ;
    if(strcmp(ptr->lettre ,chartostr1(name[0])) ==0 ) {
    ptr=recherche(ptr,chartostr(name[1]));
    if(strcmp(ptr->lettre ,chartostr(name[1])) ==0 ) {
    Type_Node ptr2=ptr->firstChild;
    do{
      printf("%s \n",ptr2->lettre);
      ptr2=ptr2->nextSibling;
    }while(ptr2 !=NULL);
    }
    else return NULL;
  }
  else return NULL;
  }
  else return NULL;
return root;
}

Type_Node searchname(Type_Node root,char* name){
  Type_Node ptr=recherche(root, chartostr1(name[0]));
  if(strcmp(ptr->lettre,chartostr1(name[0]))==0 ){
    ptr=recherche(ptr, chartostr(name[1]));
    if(strcmp(ptr->lettre,chartostr(name[1]))==0 ){
          ptr=recherche(ptr, name);
          if(strcmp(ptr->lettre,name)==0){
            return ptr;
          }
    }
    else return NULL;
  }
  else return NULL;
}

void remplirtrouves( type_contact root){
  FILE *fp=fopen("repertoire1.txt","r");
  FILE *tr=fopen("trouver.txt","a+");
  type_contact ptr =(type_contact)malloc(sizeof(_contact)) ;
  int i,n=getFileLinesNumber(fp);             //on affecte à n le nombre de ligne du fichier
  rewind(fp);
  for(i=0;i<=n;i++){                    // on parcourt le fichier ligne par ligne
    fscanf(fp,"%s %s %s %s\n ",ptr->nom,ptr->prenom,ptr->telephone,ptr->mail);
    if(strcmp(root->nom,ptr->nom ) == 0 ){  //allez aux noms
        fprintf(tr,"%s    %s    %s    %s\n",ptr->nom, ptr->prenom, ptr->telephone, ptr-> mail);
            fclose(fp);
            fclose(tr);
		}
  }

}
//--------------------------------------------------------------
type_contact recherfiles( char *name){
  FILE *fp=fopen("repertoire1.txt","r");
  type_contact ptr =(type_contact)malloc(sizeof(_contact)) ;
  int i,n=getFileLinesNumber(fp);             //on affecte à n le nombre de ligne du fichier
  rewind(fp);
  for(i=0;i<=n;i++){                    //on parcourt le fichier ligne par ligne
    fscanf(fp,"%s %s %s %s\n ",ptr->nom,ptr->prenom,ptr->telephone,ptr->mail);
    if(strcmp(name,ptr->nom ) == 0 ){  //si les données saisis existe dans le fichier
            fclose(fp);
			return ptr;         //on retourne un pointeur de type contact qui contient les infos du contact
		}
  }
    fclose(fp);
    return NULL;               //sinn on retourne un pointeur nulle
}
void chercherContact(char *name)
{
    Type_Node root=(Type_Node)malloc(sizeof(_Node));
    //printf("%l",strlen(name));
    if(strlen(name)==0)
    {
      printf("veuillez entrer un nom \n");
      labelRecherche=GTK_LABEL(gtk_builder_get_object(builder,"labelRecherche"));
            gtk_label_set_text(labelRecherche,"veuillez entrer un nom ");
    }
    /*else if (0<(strlen(name)<3) && (recherfiles( char *name)!=NULL))
    {
         remplirtrouves(searchchanged(root,name));
    }*/

    else if ((strlen(name)>2) && (recherfiles( name)!=0))
    {
        printf("%s\n",recherfiles(name)->nom);

         remplirtrouves( recherfiles( name)->nom);
         labelRecherche=GTK_LABEL(gtk_builder_get_object(builder,"labelRecherche"));
            gtk_label_set_text(labelRecherche,"le resultat de la recherche ");
    }
    else {printf("le contact n\''existe pas\n ");
          labelRecherche=GTK_LABEL(gtk_builder_get_object(builder,"labelRecherche"));
            gtk_label_set_text(labelRecherche,"le contact n'existe pas ");

    }
}


void SuppContact(char *name){
      FILE *fPtr,*fPtr2;
      fPtr = fopen ("repertoire1.txt", "r");
      fPtr2 = fopen("provisoire1.txt","a+");
      type_contact ptr1 =(type_contact)malloc(sizeof(_contact));
      int i,n=getFileLinesNumber(fPtr);
      rewind(fPtr);
      for(i=0;i<n;i++){
        fscanf(fPtr,"%s %s %s %s",ptr1->nom,ptr1->prenom,ptr1->telephone,ptr1->mail);     //on recupere toutes les données des joueurs existants sauf du joueur que l'on souhaite supprimer
        if(strcmp(name,ptr1->nom ) != 0 )
          fprintf(fPtr2,"%s %s %s %s\n",ptr1->nom,ptr1->prenom,ptr1->telephone,ptr1->mail);   //on pose ces données dand un autre fichier
      }
    fclose(fPtr);
    fclose(fPtr2);
    remove("repertoire1.txt");                     //on efface les dernier fichier
    rename("provisoire1.txt","repertoire1.txt");
}


void supprimer(void) {
        type_contact ptr =(type_contact)malloc(sizeof(_contact));

        strcpy( ptr->nom, gtk_entry_get_text(GTK_ENTRY( EnomR))) ;
        printf("%s",ptr->nom);
        SuppContact(ptr->nom);
        labelRecherche=GTK_LABEL(gtk_builder_get_object(builder,"labelRecherche"));
        gtk_label_set_text(labelRecherche,"le contact est supprime");


}


void modifier(void){
        type_contact ptr =(type_contact)malloc(sizeof(_contact));

        strcpy( ptr->nom, gtk_entry_get_text(GTK_ENTRY( EnomR)));
        SuppContact(ptr->nom);
        showAjouter();



}

