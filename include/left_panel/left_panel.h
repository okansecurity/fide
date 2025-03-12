#ifndef LEFT_PANEL_H
#define LEFT_PANEL_H

#include "../include.h"

void left_panel(GtkWidget *window){
	
	//left bar grid
	GtkWidget *left_panel_Grid = gtk_grid_new();
	
	
	GtkWidget *File_Expoler_button = gtk_button_new_with_label("📁");
	gtk_grid_attach(GTK_GRID(left_panel_Grid), File_Expoler_button, 0, 0, 1, 1);
	
	GtkWidget *git_button = gtk_button_new_with_label("🔗");
	gtk_grid_attach(GTK_GRID(left_panel_Grid), git_button, 0, 2, 1, 1);
	
	GtkWidget *Setting_button = gtk_button_new_with_label("⚙️");
	gtk_grid_attach(GTK_GRID(left_panel_Grid), Setting_button, 0, 3, 1, 1);
	
	
	gtk_grid_attach(GTK_GRID(main_grid), left_panel_Grid, 0, 2, 1, 1);
	
	}

#endif
