/* Button Boxes
 *
 * The Button Box widgets are used to arrange buttons with padding.
 */

#include <gtk/gtk.h>

static GtkWidget *
create_bbox (gint  horizontal,
	     char *title, 
	     gint  spacing,
	     gint  layout)
{
  GtkWidget *frame;
  GtkWidget *bbox;
  GtkWidget *button;
  GtkWidget *button2;
    
  frame = gtk_frame_new (title);

  if (horizontal)
    bbox = gtk_hbutton_box_new ();
  else
    bbox = gtk_vbutton_box_new ();

  gtk_container_set_border_width (GTK_CONTAINER (bbox), 5);
  gtk_container_add (GTK_CONTAINER (frame), bbox);

/*
  gtk_button_box_set_layout (GTK_BUTTON_BOX (bbox), layout);
  gtk_box_set_spacing (GTK_BOX (bbox), spacing);
  
  button = gtk_button_new_from_stock (GTK_STOCK_OK);
  gtk_container_add (GTK_CONTAINER (bbox), button);
  
  button = gtk_button_new_from_stock (GTK_STOCK_CANCEL);
  gtk_container_add (GTK_CONTAINER (bbox), button);
  
  button = gtk_button_new_from_stock (GTK_STOCK_HELP);
  gtk_container_add (GTK_CONTAINER (bbox), button);
*/
    
    /* Case for a button with an icon */
    GtkIconTheme *icon_theme;
    icon_theme = gtk_icon_theme_get_default ();

    GdkPixbuf *icon;
    GtkWidget *icon_image;
    icon = gtk_icon_theme_load_icon (icon_theme,  "network-idle", 40, 0, NULL);
    
    icon_image = gtk_image_new_from_pixbuf (icon);
 //      gtk_misc_set_padding (GTK_MISC (icon_image), 10, 10);
    g_object_unref (G_OBJECT (icon));
    button = gtk_button_new ();
 //   gtk_button_set_label (button, "Providers and Instances");
 //   gtk_button_set_always_show_image  (button, TRUE);
    gtk_container_add (GTK_CONTAINER (button), icon_image);
    gtk_container_add (GTK_CONTAINER (bbox), button);

    
    
 //////////////////////////////////
    
    /* Case for a button with an icon */
    // GtkIconTheme *icon_theme;
    GdkPixbuf *icon2;
    GtkWidget *icon_image2;
    
//    icon_theme = gtk_icon_theme_get_default ();
    icon2 = gtk_icon_theme_load_icon (icon_theme,  "network-wired", 40, 0, NULL);
    
    icon_image2 = gtk_image_new_from_pixbuf (icon2);
//    gtk_misc_set_padding (GTK_MISC (icon_image), 10, 10);
    g_object_unref (G_OBJECT (icon2));
    button2 = gtk_button_new ();
//    gtk_button_set_label (button2, "Network Configurations");
    gtk_container_add (GTK_CONTAINER (button2), icon_image2);
    gtk_container_add (GTK_CONTAINER (bbox), button2);

 ///////////////////////////////////////
    
  return frame;
}

GtkWidget *
do_button_box (GtkWidget *do_widget)
{
  static GtkWidget *window = NULL;
  GtkWidget *main_vbox;
  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *frame_horz;
  GtkWidget *frame_vert;
	
  if (!window)
  {
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_screen (GTK_WINDOW (window),
			   gtk_widget_get_screen (do_widget));
    gtk_window_set_title (GTK_WINDOW (window), "Button Boxes");
    
    g_signal_connect (window, "destroy",
		      G_CALLBACK (gtk_widget_destroyed),
		      &window);
    
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    main_vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), main_vbox);
    
    frame_horz = gtk_frame_new ("Horizontal Button Boxes");
    gtk_box_pack_start (GTK_BOX (main_vbox), frame_horz, TRUE, TRUE, 10);
    
    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (vbox), 10);
    gtk_container_add (GTK_CONTAINER (frame_horz), vbox);

    gtk_box_pack_start (GTK_BOX (vbox), 
			create_bbox (TRUE, "Spread", 40, GTK_BUTTONBOX_SPREAD),
			TRUE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), 
			create_bbox (TRUE, "Edge", 40, GTK_BUTTONBOX_EDGE),
			TRUE, TRUE, 5);
    
    gtk_box_pack_start (GTK_BOX (vbox), 
			create_bbox (TRUE, "Start", 40, GTK_BUTTONBOX_START),
			TRUE, TRUE, 5);
    
    gtk_box_pack_start (GTK_BOX (vbox), 
			create_bbox (TRUE, "End", 40, GTK_BUTTONBOX_END),
			TRUE, TRUE, 5);

    frame_vert = gtk_frame_new ("Vertical Button Boxes");
    gtk_box_pack_start (GTK_BOX (main_vbox), frame_vert, TRUE, TRUE, 10);
    
    hbox = gtk_hbox_new (FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox), 10);
    gtk_container_add (GTK_CONTAINER (frame_vert), hbox);

    gtk_box_pack_start (GTK_BOX (hbox), 
			create_bbox (FALSE, "Spread", 30, GTK_BUTTONBOX_SPREAD),
			TRUE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (hbox), 
			create_bbox (FALSE, "Edge", 30, GTK_BUTTONBOX_EDGE),
			TRUE, TRUE, 5);

    gtk_box_pack_start (GTK_BOX (hbox), 
			create_bbox (FALSE, "Start", 30, GTK_BUTTONBOX_START),
			TRUE, TRUE, 5);

    gtk_box_pack_start (GTK_BOX (hbox), 
			create_bbox (FALSE, "End", 30, GTK_BUTTONBOX_END),
			TRUE, TRUE, 5);
  }

  if (!gtk_widget_get_visible (window))
    {
      gtk_widget_show_all (window);
    }
  else
    {	 
      gtk_widget_destroy (window);
      window = NULL;
    }

  return window;
}
