#include <gtk/gtk.h>

#if 0
gboolean selection_changed(GtkTreeSelection *selection, GtkLabel *label) {
    GtkTreeView *treeView;
    GtkTreeModel *model;
    GtkTreeIter iter;
    gchar *active;
    
    treeView = gtk_tree_selection_get_tree_view(selection);
    model = gtk_tree_view_get_model(treeView);
    gtk_tree_selection_get_selected(selection, &model, &iter);
    gtk_tree_model_get(model, &iter,
                       1, &active,
                       -1);

    gtk_label_set_text(label, active);
}
#endif








GtkDialog *
hello_world_dialog_new ()
{
    GtkWidget *dialog;
    
    dialog = gtk_dialog_new_with_buttons ("Hello World",
                                          NULL,
                                          GTK_DIALOG_DESTROY_WITH_PARENT |
                                          //GTK_DIALOG_NO_SEPARATOR,
                                          GTK_UI_MANAGER_SEPARATOR,
                                          "Close", GTK_RESPONSE_OK, NULL);
    gtk_container_add (GTK_CONTAINER (GTK_DIALOG (dialog)),
                       gtk_label_new ("Hello World!"));
    gtk_widget_show_all (dialog);
    
    return GTK_DIALOG (dialog);
}



void
hello_world_dialog_show ()
{
    GtkWidget *dialog = GTK_WIDGET (hello_world_dialog_new ());
    
    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}

GtkWidget *
hello_world_button_new (int padding)
{
    GtkIconTheme *icon_theme;
    GdkPixbuf *icon;
    GtkWidget *icon_image, *button;
    
    icon_theme = gtk_icon_theme_get_default ();
    icon = gtk_icon_theme_load_icon (icon_theme,  "network-wired", 40, 0, NULL);
 //   if (icon == NULL)
   //     icon = gtk_icon_theme_load_icon (icon_theme,
     //                                    "qgn_list_gene_default_app",
       //                                  40, 0, NULL);
    
    icon_image = gtk_image_new_from_pixbuf (icon);
    gtk_misc_set_padding (GTK_MISC (icon_image), padding, padding);
    g_object_unref (G_OBJECT (icon));
    button = gtk_button_new ();
    gtk_container_add (GTK_CONTAINER (button), icon_image);
    
    gtk_widget_show_all (button);
    
    return button;
}






int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *treeView;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkWidget *label;
    GtkWidget *vbox;
    GtkTreeSelection *selection;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Cloud Instances");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 50);

#if 0    
    treeView = gtk_tree_view_new_with_model(createModel());

    renderer = gtk_cell_renderer_pixbuf_new();
    column = gtk_tree_view_column_new_with_attributes(
                     "Provider", renderer,
                     "pixbuf", PIXBUF_COL,
                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (treeView), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                     "Instance", renderer,
                     "text", TEXT_COL,
                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW (treeView), column);
#endif

   // label = gtk_label_new("gftp-48x48.png");
 //   vbox = gtk_vbox_new(FALSE, 5);

//    gtk_box_pack_start(GTK_BOX(vbox), treeView, TRUE, TRUE, 5);
  //  gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 5);
  //  gtk_container_add(GTK_CONTAINER(window), vbox);

//    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeView));
//    gtk_tree_view_expand_all(GTK_TREE_VIEW(treeView));
//    g_signal_connect(G_OBJECT(selection), "changed",
//                     G_CALLBACK(selection_changed), label);

    GtkWidget *button;
    
    button = hello_world_button_new (10);
    g_signal_connect (button, "clicked",
                      G_CALLBACK (hello_world_dialog_show), NULL);


    gtk_container_add(GTK_CONTAINER(window), button);
    
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

