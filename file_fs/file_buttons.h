#ifndef FILE_BUTTON_H
#define FILE_BUTTON_H

#include "file_area.h"
#include "open_file.h"
#include "save_file.h"

void file_button(GtkWidget *main_grid, GtkWidget *notebook, GtkWidget *window) {
    GtkWidget *file_button = gtk_menu_button_new();
    GtkWidget *file_menu = gtk_popover_new();
    gtk_menu_button_set_label(GTK_MENU_BUTTON(file_button), "File");

    GtkWidget *file_menu_grid = gtk_grid_new();
    gtk_popover_set_child(GTK_POPOVER(file_menu), file_menu_grid);

    GtkWidget *new_file = gtk_button_new_with_label("New File");
    
    GtkWidget *open_file = gtk_button_new_with_label("Open File");
    g_signal_connect(open_file, "clicked", G_CALLBACK(open_file_f), notebook);

    GtkWidget *save_file = gtk_button_new_with_label("Save File");
    g_signal_connect(save_file, "clicked", G_CALLBACK(read_text_from_notebook), notebook);

    gtk_grid_attach(GTK_GRID(file_menu_grid), new_file, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(file_menu_grid), open_file, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(file_menu_grid), save_file, 0, 2, 1, 1);

    gtk_menu_button_set_popover(GTK_MENU_BUTTON(file_button), file_menu);
    gtk_grid_attach(GTK_GRID(main_grid), file_button, 1, 0, 1, 1);
} 

#endif
