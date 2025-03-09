#include "include.h"
#include "file_button.h"

void menu_bar(void) {
    GtkWidget *menu = gtk_grid_new();
    GtkWidget *menu_button = file_buttons_f();

    // Grid'e ekleme
    gtk_grid_attach(GTK_GRID(menu), menu_button, 0, 0, 1, 1);

    // Ana kutuya ekle
    gtk_box_append(GTK_BOX(main_box), menu);
}
