#ifndef MAIN_PANEL_H
#define MAIN_PANEL_H

#include "../include.h"

void menu_bar(GtkWidget *window) {
	
    // main grid
    GtkWidget *menu_Bar_Grid = gtk_grid_new();


    
    // Settings buton ayarları
    //******************************
    GtkWidget *setting_button = gtk_menu_button_new();
    GtkWidget *setting_menu = gtk_popover_new();
    gtk_menu_button_set_label(GTK_MENU_BUTTON(setting_button), "Settings");

    GtkWidget *setting_menu_grid = gtk_grid_new();
    gtk_popover_set_child(GTK_POPOVER(setting_menu), setting_menu_grid);

    GtkWidget *appearance = gtk_button_new_with_label("Appearance");
    GtkWidget *preferences = gtk_button_new_with_label("Preferences");
    GtkWidget *plugins = gtk_button_new_with_label("Plugins");

    gtk_grid_attach(GTK_GRID(setting_menu_grid), appearance, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(setting_menu_grid), preferences, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(setting_menu_grid), plugins, 0, 2, 1, 1);

    gtk_menu_button_set_popover(GTK_MENU_BUTTON(setting_button), setting_menu);
    gtk_grid_attach(GTK_GRID(menu_Bar_Grid), setting_button, 0, 0, 1, 1);
    //******************************

    // File buton ayarları
    //******************************
    GtkWidget *file_button = gtk_menu_button_new();
    GtkWidget *file_menu = gtk_popover_new();
    gtk_menu_button_set_label(GTK_MENU_BUTTON(file_button), "File");

    GtkWidget *file_menu_grid = gtk_grid_new();
    gtk_popover_set_child(GTK_POPOVER(file_menu), file_menu_grid);

    GtkWidget *new_file = gtk_button_new_with_label("New File");
    GtkWidget *open_file = gtk_button_new_with_label("Open File");
    GtkWidget *save_file = gtk_button_new_with_label("Save File");

    gtk_grid_attach(GTK_GRID(file_menu_grid), new_file, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(file_menu_grid), open_file, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(file_menu_grid), save_file, 0, 2, 1, 1);

    gtk_menu_button_set_popover(GTK_MENU_BUTTON(file_button), file_menu);
    gtk_grid_attach(GTK_GRID(menu_Bar_Grid), file_button, 1, 0, 1, 1);
    //******************************

    // Compiler & Run Settings buton ayarları
    //******************************
    GtkWidget *compiler_run_setting_button = gtk_menu_button_new();
    GtkWidget *compiler_run_setting = gtk_popover_new();
    gtk_menu_button_set_label(GTK_MENU_BUTTON(compiler_run_setting_button), "Compiler & Run");

    GtkWidget *compiler_run_setting_grid = gtk_grid_new();
    gtk_popover_set_child(GTK_POPOVER(compiler_run_setting), compiler_run_setting_grid);

    GtkWidget *compiler = gtk_button_new_with_label("Compiler Settings");
    GtkWidget *run = gtk_button_new_with_label("Run Settings");
    GtkWidget *debugger = gtk_button_new_with_label("Debugger");

    gtk_grid_attach(GTK_GRID(compiler_run_setting_grid), compiler, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(compiler_run_setting_grid), run, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(compiler_run_setting_grid), debugger, 0, 2, 1, 1);

    gtk_menu_button_set_popover(GTK_MENU_BUTTON(compiler_run_setting_button), compiler_run_setting);
    gtk_grid_attach(GTK_GRID(menu_Bar_Grid), compiler_run_setting_button, 2, 0, 1, 1);
    //******************************

    // Compiler & Run butonları
    //******************************
    GtkWidget *compiler_button = gtk_button_new_with_label("Compile");
    GtkWidget *run_button = gtk_button_new_with_label("Run");

    GtkWidget *compiler_and_run_grid = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(compiler_and_run_grid), compiler_button, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(compiler_and_run_grid), run_button, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(menu_Bar_Grid), compiler_and_run_grid, 3, 0, 2, 1);
    //******************************

    // Ana pencereye menü çubuğunu ekle
    
    gtk_grid_attach(GTK_GRID(main_grid), menu_Bar_Grid, 1, 0, 3, 1);
}

#endif
