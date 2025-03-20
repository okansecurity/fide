#include "editor.h"

void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget* window = gtk_application_window_new(app);
    GtkWidget* main_grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), main_grid);
    
    gtk_window_set_title(GTK_WINDOW(window), "Free Integrated Development Environment");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    
    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget* notebook = gtk_notebook_new();
    gtk_widget_set_hexpand(notebook, TRUE);
    gtk_widget_set_vexpand(notebook, TRUE);
    gtk_box_append(GTK_BOX(box), notebook);

    file_button(main_grid, notebook, window);
    /*create_new_tab(GTK_NOTEBOOK(notebook), "no-file");
    create_new_tab(GTK_NOTEBOOK(notebook), "no-file2");*/

    gtk_grid_attach(GTK_GRID(main_grid), box, 1, 1, 10, 10);
    gtk_window_present(GTK_WINDOW(window));
} 

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.fide", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
} 
