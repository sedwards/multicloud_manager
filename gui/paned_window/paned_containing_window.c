/* example-start paned paned.c */

#include <stdio.h>
#include <gtk/gtk.h>

/* Create the list of "messages" */
GtkWidget *create_list( void )
{
    
    GtkWidget *scrolled_window;
    GtkWidget *list;
    GtkWidget *list_item;
    
    int i;
    char buffer[16];
    
    /* Create a new scrolled window, with scrollbars only if needed */
    scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
                                    GTK_POLICY_AUTOMATIC,
                                    GTK_POLICY_AUTOMATIC);
    return scrolled_window;
}

/* Create a scrolled text area that displays a "message" */
GtkWidget *create_log_box( void )
{
    GtkWidget *table;
    GtkWidget *text;
    GtkWidget *hscrollbar;
    GtkWidget *vscrollbar;
    GtkEntryBuffer *buffer;
    
    /* Create a table to hold the text widget and scrollbars */
    table = gtk_table_new (2, 2, FALSE);
    
    /* Put a text widget in the upper left hand corner. Note the use of
     * GTK_SHRINK in the y direction */
    //text = gtk_text_new (NULL, NULL);
    
    buffer = gtk_entry_buffer_new (NULL, 0);
    gtk_table_attach (GTK_TABLE (table), buffer, 0, 1, 0, 1,
                      GTK_FILL | GTK_EXPAND,
                      GTK_FILL | GTK_EXPAND | GTK_SHRINK, 0, 0);
    
    gtk_widget_show (table);

    
    GtkWidget *contents;
    GtkWidget *sw;

    sw = gtk_scrolled_window_new (NULL, NULL);
    
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (sw),
                                    GTK_POLICY_AUTOMATIC,
                                    GTK_POLICY_AUTOMATIC);
    
    gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (sw),
                                         GTK_SHADOW_IN);
    
    gtk_table_attach (GTK_TABLE (table),
                      sw,
                      /* X direction */       /* Y direction */
                      0, 1,                   3, 4,
                      GTK_EXPAND | GTK_FILL,  GTK_EXPAND | GTK_FILL,
                      0,                      0);
    
    contents = gtk_text_view_new ();
    gtk_widget_grab_focus (contents);
    
    gtk_container_add (GTK_CONTAINER (sw),
                       contents);
  
    
    return table;
}

int main( int   argc,
         char *argv[] )
{
    GtkWidget *window;
    GtkWidget *vpaned;
    GtkWidget *list;
    GtkWidget *text;
    
    gtk_init (&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Paned Windows");
    g_signal_connect (G_OBJECT (window), "destroy",
                        G_CALLBACK (gtk_main_quit), NULL);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
   // gtk_widget_set_usize (GTK_WIDGET(window), 450, 400);
    
    /* create a vpaned widget and add it to our toplevel window */
    
    vpaned = gtk_vpaned_new ();
    gtk_container_add (GTK_CONTAINER(window), vpaned);
    gtk_widget_show (vpaned);
    
    /* Now create the contents of the two halves of the window */
    
 //   list = create_list();
    list = create_log_box ();
    gtk_paned_add1 (GTK_PANED(vpaned), list);
    gtk_widget_show (list);
    
    text = create_log_box ();
    gtk_paned_add2 (GTK_PANED(vpaned), text);
    gtk_widget_show (text);
    
    gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    
    gtk_widget_show_all (window);

    gtk_main ();
    return 0;
}
/* example-end */
