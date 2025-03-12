#include "include/include.h"
#include "include/main_panel/main_panel.h"
#include "include/left_panel/left_panel.h"

static void activate (GtkApplication* app){
  main_grid = gtk_grid_new();
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Free Integrated Development Environment");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
  
  
  menu_bar(window);
  left_panel(window);
  
  gtk_window_set_child(GTK_WINDOW(window), main_grid);
  gtk_window_present (GTK_WINDOW (window));
}

int main (void){
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.fide", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), 0, 0);
  g_object_unref (app);

  return status;
}
