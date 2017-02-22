#include "config.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>
#include <glib/gstdio.h>

#include "demos.h"

GtkWidget *
do_ui_manager (GtkWidget * window);

GtkWidget *create_log_box( void );

void mcm_gtk_platform_specific_init(void);

int
main (int argc, char **argv)
{
  GtkWidget *window;
  GtkWidget *ui_manager;
  GtkWidget *button_box;
  GtkWidget *paned;
  GtkWidget *notebook;
  GtkWidget *mainbox;

  GtkWidget *tree;
  GtkWidget *text;
  GtkTextTag *tag;
  
  gtk_init (&argc, &argv);

//  setup_default_icon ();
  
  /* Setup Main Window */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "GTK+ Code Demos");
  g_signal_connect_after (window, "destroy",
		    G_CALLBACK (gtk_main_quit), NULL);

  /* Add classic menu bar */
  ui_manager = do_ui_manager (window);

  /* Create a pane to hold all of our child windows */
  paned = gtk_paned_new (GTK_ORIENTATION_VERTICAL);
  gtk_container_add (GTK_CONTAINER(ui_manager), paned);
  gtk_widget_show (paned);

  mainbox = gtk_box_new (FALSE, 0);
  gtk_paned_add1 (GTK_PANED(paned), mainbox);


  /* treeview servers,clusters and instances */
  tree = do_treeview (mainbox);
  //gtk_box_pack_start (GTK_BOX (mainbox), tree, FALSE, FALSE, 0);


  /* Main Window Button Box */
  button_box = do_button_box (mainbox);
  gtk_box_pack_start (GTK_BOX (mainbox), button_box, TRUE, TRUE, 0);
  

  /* Create log window for operations */
  text = create_log_box ();
 // gtk_paned_add2 (GTK_PANED(vpaned), text);
  gtk_paned_pack2 (GTK_PANED (paned), text, 1, 1);
  gtk_paned_set_position(GTK_PANED (paned), 650);

  /* Label - FIXME: to become status bar after debugging */
    
  /* Finish drawing our completed window*/
  gtk_window_set_default_size (GTK_WINDOW (window), 1152, 864);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  /* Local Platform Hacks */
  mcm_gtk_platform_specific_init();
  gtk_widget_show_all (window);
  
  gtk_main ();

  return 0;
}


