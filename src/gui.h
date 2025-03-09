#ifndef GUI_H
#define GUI_H

#include "../include/include.h"
#include "../include/menu_bar.h"
#include "../include/text_area.h"

// Pencere oluşturmak için kullandım
void window_f(GtkApplication* app, gpointer user_data){
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Free Integrated Development Environment");
    gtk_window_set_default_size (GTK_WINDOW (window), 900, 600);
  
    // Ana box
    main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_window_set_child(GTK_WINDOW(window), main_box);
  
    // Menü ve dosya açma işlevi
    menu_bar();
  
    gtk_widget_show(main_box);
    gtk_window_present (GTK_WINDOW (window));
}

// Ana görsel fonksiyonum
void gui_main_f(void) {
    int status;
    
    app = gtk_application_new("org.gtk.fide", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(window_f), NULL);
    status = g_application_run(G_APPLICATION(app), 0, NULL);
    g_object_unref(app);
}

#endif
