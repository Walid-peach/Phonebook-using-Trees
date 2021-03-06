#include "header.h"

void on_buttonRefresh_clicked (GtkButton *b){
    gtk_widget_destroy(windowMenu);
    showMenu();
}
// fonction qui afficher le Menu
void showMenu (){
    builder          = gtk_builder_new_from_file ("SdaGlade.glade#");               // declaration du Builder

    gtk_builder_connect_signals(builder, NULL);


        // declarations des compos du Menu
    windowMenu       = GTK_WIDGET(gtk_builder_get_object (builder, "windowMenu"));
    liststore        = GTK_LIST_STORE(gtk_builder_get_object(builder,"liststore"));
    Tv               = GTK_TREE_VIEW(gtk_builder_get_object(builder,"Tv"));
    cnom             = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"cnom"));
    cprenom          = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"cprenom"));
    cl1              = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cl1"));
    selection        = GTK_TREE_SELECTION(gtk_builder_get_object(builder, "select"));
    cl2              = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cl2"));
    cl3              = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cl3"));
    cl4              = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cl4"));
    buttonAjouter    = GTK_WIDGET(gtk_builder_get_object (builder, "buttonAjouter"));
    buttonAnnM       = GTK_WIDGET(gtk_builder_get_object (builder, "buttonAnnM"));
    buttonRefresh    = GTK_WIDGET(gtk_builder_get_object (builder, "buttonRefresh"));
    buttonRechrecher = GTK_WIDGET(gtk_builder_get_object (builder, "buttonRechrecher"));
    selection        = gtk_tree_view_get_selection(GTK_TREE_VIEW(Tv));



    afficher_contact();



    gtk_window_set_position(GTK_WINDOW(windowMenu), GTK_WIN_POS_CENTER);
    //gtk_window_resize(GTK_WINDOW(windowMenu), 600, 600);

    g_signal_connect(buttonAjouter, "clicked", G_CALLBACK(showAjouter),NULL);

    g_signal_connect(buttonAnnM, "clicked", G_CALLBACK(quit),NULL);
    g_signal_connect(buttonRefresh, "clicked", G_CALLBACK(on_buttonRefresh_clicked),NULL);
    g_signal_connect(buttonRechrecher, "clicked", G_CALLBACK(showRechercher),NULL);


    gtk_widget_show_all(windowMenu);
    gtk_main();

}



int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);//initialisation du gtk

    showMenu();

    return 0;
}






