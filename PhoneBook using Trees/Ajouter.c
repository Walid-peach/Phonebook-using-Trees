#include "Ajouter.h"


int getFileLinesNumber(FILE *fp){   //cette fonctions retourne le nombre des lignes d'un fichier
    if(fp==NULL) return -1;
    int ch=0;
    int lines=0;
    while(!feof(fp)){
      ch = fgetc(fp);
      if(ch == '\n'){
        lines++;
      }
    }
    return lines;
}
//------------------------------------
//cette fonction verifie l'existance du nom et prenom dans le fichier

bool rechercher( char *name1, char *name2 ){
  FILE *fp=fopen("repertoire1.txt","r");
  type_contact ptr =(type_contact)malloc(sizeof(_contact)) ;
  int i,n=getFileLinesNumber(fp);             //on affecte à n le nombre de ligne du fichier
  rewind(fp);
  for(i=0;i<n;i++){                    //on parcourt le fichier ligne par ligne
    fscanf(fp,"%s %s %s %s\n ",ptr->nom,ptr->prenom,ptr->telephone,ptr->mail);
    if(strcmp(name1,ptr->nom ) == 0 && strcmp(name2,ptr->prenom ) == 0 ){  //si les données saisis existe dans le fichier
            fclose(fp);
			return true;         //on retourne True si le nom et prenom existent
		}
  }
    fclose(fp);
    return false;               //sinn on retourne False
}
// -----------------------------
//fonction ajout en fichier avec ordre alphabetique

void AjouterContact (type_contact contacts ) {
    FILE *fcontact,*fprovisoire;
    fcontact    = fopen("repertoire1.txt","a+");
    fprovisoire = fopen("provisoire.txt","a+");
    int i,tru2=0,tru=0,n=getFileLinesNumber(fcontact);
    type_contact contact1=(type_contact)malloc(sizeof(_contact)) ;
    rewind(fcontact);
    rewind(fprovisoire);
    if(rechercher(contacts->nom ,contacts->prenom) ){tru=1;tru2=1; // si le contact existe on affiche le contact existe deja
    labelexiste=GTK_LABEL(gtk_builder_get_object(builder,"labelexiste"));
    gtk_label_set_text(labelexiste,"le contact existe deja ");}
    // si le fichier est vide on ajoute directement
    if(n==0){fprintf(fprovisoire,"%s    %s    %s    %s\n",contacts->nom, contacts->prenom, contacts->telephone, contacts-> mail) ;
    }
    else{for(i=0;i<n;i++){  //le contact n'existe pas
            fscanf(fcontact,"%s    %s    %s    %s\n",contact1->nom, contact1->prenom, contact1->telephone, contact1-> mail) ;
            //on compare le nom entre avec les noms existes
            if(strcmp(contact1->nom , contacts->nom ) >0 && tru==0){
                fprintf(fprovisoire,"%s    %s    %s    %s\n",contacts->nom, contacts->prenom, contacts->telephone, contacts-> mail);
                tru=1;}
                fprintf(fprovisoire,"%s    %s    %s    %s\n",contact1->nom, contact1->prenom, contact1->telephone, contact1-> mail);
                }
                //
            if(tru==0){fprintf(fprovisoire,"%s    %s    %s    %s\n",contacts->nom, contacts->prenom, contacts->telephone, contacts-> mail);}
        }

    // apres le contact est sauvegarde on l'affiche
    if(tru2==0){
            labelexiste=GTK_LABEL(gtk_builder_get_object(builder,"labelexiste"));
            gtk_label_set_text(labelexiste,"le contact est sauvegarde ");

    }

    fclose(fcontact);
    fclose(fprovisoire);
    remove("repertoire1.txt");
    rename("provisoire.txt","repertoire1.txt");

    g_signal_connect(G_OBJECT(windowAjouter), "destroy",G_CALLBACK(gtk_main_quit), NULL);
}



//-------------------------arbres
// fonction transforme un char a char*
char* chartostr1(char c){
  char str[2]={c,'\0'};
  char* str2=(char*)malloc(sizeof(char)) ;
  strcpy(str2, str);
  return str2;
}

char* chartostr(char c){
  switch(c){
    case 'a' :
    case 'b' :
    case 'c' :return "abc";break;
    case 'd' :
    case 'e' :
    case 'f' :return "def";break;
    case 'g' :
    case 'h' :
    case 'i' :return "ghi";break;
    case 'j' :
    case 'k' :
    case 'l' :return "jkl";break;
    case 'm' :
    case 'n' :
    case 'o' :return "mno";break;
    case 'p' :
    case 'q' :
    case 'r' :return "pqr";break;
    case 's' :
    case 't' :
    case 'u' :return "stu";break;
    case 'v' :
    case 'w' :
    case 'x' :return "vwx";break;
    case 'y' :
    case 'z' :return "yz";break;
  }
}
// fonction qui retourne le noeud qui contient str

Type_Node recherche(Type_Node root ,char* str){
  Type_Node ptr=root->firstChild;
  while(strcmp(ptr->lettre,str) != 0 && ptr->nextSibling != NULL){
    ptr=ptr->nextSibling;
  }
  return ptr;
}
// fonction qui cree les noeuds
Type_Node newNode(char* data){
    Type_Node node= (Type_Node)malloc(sizeof(_Node ));
    node->lettre = data;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    return (node);
}

// ajouter les noeuds du 1 ere niveaux

Type_Node NewNode1(Type_Node root,char* c){
  Type_Node node=newNode(c);
  if(root->firstChild == NULL){
        root->firstChild=newNode(c);
        return root;
  }
  node->nextSibling=root->firstChild;
  root->firstChild = node;
return root;
}
// creation des 2 eme niveau
Type_Node NewNode2(Type_Node root,char* c1,char* c2){
    if(strcmp(recherche(root, c1)->lettre , c1)==0)
      NewNode1(recherche(root, c1) , c2);
      else {
        NewNode1(root , c1);
        NewNode1(recherche(root, c1) , c2);
      }
    return root ;
    }


Type_Node NewNodeName(Type_Node root,char* c1,char* c2,char* name){


      if(strcmp(recherche(root, c1)->lettre , c1)==0){
        if(strcmp(recherche(recherche(root, c1), c2)->lettre , c2)==0){
          NewNode1(recherche(recherche(root, c1), c2) , name);
        }
        else{
          NewNode2(root,c1,c2);
          NewNodeName(root,c1,c2,name);
        }
      }
      else {
        NewNode2(root,c1,c2 );
        NewNodeName(root,c1,c2,name);
      }
    return root ;
    }





void showAjouter(void){





    builder       =gtk_builder_new_from_file ("SdaGlade.glade#");
    windowAjouter =GTK_WIDGET(gtk_builder_get_object (builder, "windowAjouter"));
    buttonSave    =GTK_WIDGET(gtk_builder_get_object (builder, "buttonSave"));
    buttonAnn     =GTK_WIDGET(gtk_builder_get_object (builder, "buttonAnn"));
    labelexiste   =GTK_LABEL(gtk_builder_get_object(builder,"labelexiste"));



    Enom =GTK_WIDGET(gtk_builder_get_object (builder, "ENom"));
    Eprenom =GTK_WIDGET(gtk_builder_get_object (builder, "EPrenom"));
    Etele =GTK_WIDGET(gtk_builder_get_object (builder, "ETel"));
    Email =GTK_WIDGET(gtk_builder_get_object (builder, "EMail"));

    gtk_window_set_position(GTK_WINDOW(windowAjouter), GTK_WIN_POS_CENTER);

    g_signal_connect(buttonSave, "clicked", G_CALLBACK(print),NULL);



    g_signal_connect(buttonAnn, "clicked", G_CALLBACK(close),NULL);





    gtk_widget_show_all(windowAjouter);
    gtk_main();


};
// fonction qui ajoute le contact apres la correction des champs vides
void corriger(type_contact ptr)
{
        char t[] = "------";
        //afficher un erreur si le nom ou le telephoen n'existe pas
        if( strlen(ptr->nom)==0 || strlen(ptr->telephone)==0){
            labelexiste=GTK_LABEL(gtk_builder_get_object(builder,"labelexiste"));
            gtk_label_set_text(labelexiste,"veuiller remplir les champs proposes");
        }
        else if( strlen(ptr->prenom)==0 && strlen(ptr->mail)==0){
          strcpy(ptr->prenom,t );
          strcpy(ptr->mail, t );
          AjouterContact(ptr);
        }
        else if (strlen(ptr->prenom)==0){
          strcpy(ptr->prenom,t );
            AjouterContact(ptr);
        }
        else if (strlen(ptr->mail)==0){
          strcpy(ptr->mail, t );
          AjouterContact(ptr);
        }
        else {
          AjouterContact(ptr);
        }
    g_signal_connect(G_OBJECT(windowAjouter), "destroy",G_CALLBACK(gtk_main_quit), NULL);
}


// la fonction lier au button sauvegarder
void print(GtkWidget *widget, gpointer data){

    type_contact ptr =(type_contact)malloc(sizeof(_contact));

    strcpy( ptr->nom, gtk_entry_get_text(GTK_ENTRY( Enom))) ;
    strcpy( ptr->prenom, gtk_entry_get_text(GTK_ENTRY( Eprenom))) ;
    strcpy( ptr->telephone, gtk_entry_get_text(GTK_ENTRY( Etele))) ;
    strcpy( ptr->mail, gtk_entry_get_text(GTK_ENTRY( Email))) ;

    // ------- l'ajout dans l'arbre

    if (!(rechercher(ptr->nom ,ptr->prenom))){
        Type_Node tree = newNode("root");
        NewNode1(tree, "\0");
        tree=NewNodeName(tree,chartostr1(ptr->nom[0]),chartostr(ptr->nom[1]) , ptr->nom);
        printf("%s %s %s \n",recherche(tree, chartostr1(ptr->nom[0]) )->lettre,recherche(tree, chartostr1(ptr->nom[0]))->firstChild->lettre,recherche(tree, chartostr1(ptr->nom[0]))->firstChild->firstChild->lettre);
    }
    // ------------- l'ajout dans le fichier

        corriger(ptr);

    g_signal_connect(G_OBJECT(windowAjouter), "destroy",G_CALLBACK(gtk_main_quit), NULL);

}


void close(GtkWidget *widget,gpointer data) {

    gtk_window_close (windowAjouter);
    g_signal_connect(G_OBJECT(windowAjouter), "destroy",G_CALLBACK(gtk_main_quit), NULL);

}

void quit(GtkWidget *widget,gpointer data){
    exit(0);
}



