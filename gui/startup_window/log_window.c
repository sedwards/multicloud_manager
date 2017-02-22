#include <gtk/gtk.h>

/* Create a scrolled text area that displays a "message" */
GtkWidget *create_log_box( void )
{
    GtkWidget *table;
    //GtkWidget *text;
    //GtkWidget *hscrollbar;
    //GtkWidget *vscrollbar;
    //GtkEntryBuffer *buffer;
    
    /* Create a table to hold the text widget and scrollbars */
    table = gtk_table_new (2, 2, FALSE);
    
    /* Put a text widget in the upper left hand corner. Note the use of
     * GTK_SHRINK in the y direction */
    //text = gtk_text_new (NULL, NULL);
    
 //   buffer = gtk_entry_buffer_new (NULL, 0);
 //   gtk_table_attach (GTK_TABLE (table), buffer, 0, 1, 0, 1,
   //                   GTK_FILL | GTK_EXPAND,
     //                 GTK_FILL | GTK_EXPAND | GTK_SHRINK, 0, 0);
    
//    gtk_widget_show (table);
    
    
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
