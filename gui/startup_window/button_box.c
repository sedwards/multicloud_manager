/* Button Boxes
 *
 * The Button Box widgets are used to arrange buttons with padding.
 */

/* Boxes are going away in favor of grids. At some point we should switch too */

#include <gtk/gtk.h>


/* Our usual callback function */
static void callback( GtkWidget *widget,
                     gpointer   data )
{
    g_print ("Hello again - %s was pressed\n", (char *) data);
}

static GtkWidget *icon_label_box( gchar     *stock_icon_name,
                                 gchar     *label_text )
{
    GtkWidget *box;
    GtkWidget *label;
    GdkPixbuf *icon;
    GtkWidget *image;
    
    /* Create box for image and label */
    box = gtk_box_new (FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (box), 2);
    
    /* Load theme */
    GtkIconTheme *icon_theme;
    icon_theme = gtk_icon_theme_get_default ();
    
    /* stock icon from theme */
    icon = gtk_icon_theme_load_icon (icon_theme, stock_icon_name, 40, 0, NULL);
    image = gtk_image_new_from_pixbuf (icon);
    
    /* From local file if not from theme */
    // image = gtk_image_new_from_file ("some filename");
    
    /* Create a label for the button */
    label = gtk_label_new (label_text);
    
    /* Pack the image and label into the box */
    gtk_box_pack_start (GTK_BOX (box), image, FALSE, FALSE, 3);
    gtk_box_pack_end (GTK_BOX (box), label, FALSE, FALSE, 3);
    
    gtk_widget_show (image);
    gtk_widget_show (label);
    
    return box;
}


static GtkWidget *
create_bbox (gint  horizontal,
	     char *title, 
	     gint  spacing,
	     gint  layout)
{
  GtkWidget *frame;
  GtkWidget *bbox;
  GtkWidget *button;
    
  frame = gtk_frame_new (title);

  if (horizontal)
    bbox = gtk_hbutton_box_new ();
  else
    bbox = gtk_vbutton_box_new ();

  gtk_container_set_border_width (GTK_CONTAINER (bbox), 5);
  gtk_container_add (GTK_CONTAINER (frame), bbox);

#if 0
  /* Case for a button with an icon */
  GtkIconTheme *icon_theme;
  icon_theme = gtk_icon_theme_get_default ();
    
    GdkPixbuf *icon;
    GtkWidget *icon_image;
    GtkWidget *label;
    icon = gtk_icon_theme_load_icon (icon_theme,  "network-idle", 40, 0, NULL);
    
    icon_image = gtk_image_new_from_pixbuf (icon);
    //      gtk_misc_set_padding (GTK_MISC (icon_image), 10, 10);
    g_object_unref (G_OBJECT (icon));
    button = gtk_button_new ();
    
    //label = gtk_label_new ("Providers and Instances");
    gtk_button_set_label (button, "Providers and Instances");
       gtk_button_set_always_show_image  (button, TRUE);
    gtk_container_add (GTK_CONTAINER (button), icon_image);
//    gtk_container_add (GTK_CONTAINER (bbox), label);
    gtk_container_add (GTK_CONTAINER (bbox), button);
    

    GdkPixbuf *icon2;
    GtkWidget *icon_image2;
    
    icon2 = gtk_icon_theme_load_icon (icon_theme,  "network-wired", 40, 0, NULL);
    
    icon_image2 = gtk_image_new_from_pixbuf (icon2);
    //    gtk_misc_set_padding (GTK_MISC (icon_image), 10, 10);
    g_object_unref (G_OBJECT (icon2));
    button2 = gtk_button_new ();
    gtk_button_set_label (button2, "Network Configurations");
    gtk_container_add (GTK_CONTAINER (button2), icon_image2);
    gtk_container_add (GTK_CONTAINER (bbox), button2);
   
#endif
    
    
  /* stock buttons */
  gtk_button_box_set_layout (GTK_BUTTON_BOX (bbox), layout);
  gtk_box_set_spacing (GTK_BOX (bbox), spacing);
  
  button = gtk_button_new_from_stock (GTK_STOCK_OK);
  gtk_container_add (GTK_CONTAINER (bbox), button);
  
  button = gtk_button_new_from_stock (GTK_STOCK_CANCEL);
  gtk_container_add (GTK_CONTAINER (bbox), button);
  
  button = gtk_button_new_from_stock (GTK_STOCK_HELP);
  gtk_container_add (GTK_CONTAINER (bbox), button);
    

#if 0
    GtkWidget *button2;
    GtkWidget *sub_box;
    GtkWidget *label;
    GdkPixbuf *icon;
    GtkWidget *image;

    sub_box = gtk_hbox_new (FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (sub_box), 2);
   
    
   // /* Create box for image and label */
   // box = gtk_box_new (FALSE, 0);
  //  gtk_container_set_border_width (GTK_CONTAINER (box), 2);
    /* Create a new button */
    button2 = gtk_button_new ();
    
    /* Load theme */
    GtkIconTheme *icon_theme;
    icon_theme = gtk_icon_theme_get_default ();
    
    /* stock icon from theme */
    icon = gtk_icon_theme_load_icon (icon_theme, "network-idle", 40, 0, NULL);
    image = gtk_image_new_from_pixbuf (icon);
    
    /* From local file if not from theme */
    // image = gtk_image_new_from_file ("some filename");
    
    /* Create a label for the button */
    label = gtk_label_new ("some text");
    
    /* Pack the image and label into the box */
    gtk_box_pack_start (GTK_BOX (sub_box), image, FALSE, FALSE, 3);
    gtk_box_pack_end (GTK_BOX (sub_box), label, FALSE, FALSE, 3);
   
    gtk_container_add (GTK_CONTAINER (sub_box), button2);
    gtk_container_add (GTK_CONTAINER (bbox), sub_box);
#endif
    
    
    GtkWidget *button2;
    GtkWidget *box;
    
    /* Create a new button */
    button2 = gtk_button_new ();
    
    /* Connect the "clicked" signal of the button to our callback */
    g_signal_connect (button2, "clicked",
                      G_CALLBACK (callback), (gpointer) "cool button");
    
    /* This calls our box creating function */
    box = icon_label_box ("network-idle", "Providers and Such");
    
    /* Pack and show all our widgets */
    //   gtk_widget_show (box);
    
    gtk_container_add (GTK_CONTAINER (button2), box);
    
    //    gtk_widget_show (button);
    
    gtk_container_add (GTK_CONTAINER (bbox), button2);
    
    
  return frame;
}

GtkWidget *
do_button_box (GtkWidget *do_widget)
{
  static GtkWidget *window = NULL;
  GtkWidget *main_vbox;
  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *grid;
  GtkWidget *frame_horz;
  GtkWidget *frame_vert;
	
    /* We want to show text with our buttons */
    GtkSettings *default_settings = gtk_settings_get_default();
    g_object_set(default_settings, "gtk-button-images", TRUE, NULL);
    
    
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

#if 0
      GtkWidget *button2;
      GtkWidget *custom;
      
      /* Custom button with label */
      button2 = gtk_button_new ();
      custom = icon_label_box("network-wired", "custom labeled button");
      gtk_container_add (GTK_CONTAINER (button2), custom);
      gtk_container_add (GTK_CONTAINER (vbox), custom);
#endif
      
/* Vertical Button Boxes
 
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
*/
       
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
