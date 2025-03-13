#ifndef TEXT_AREA_H
#define TEXT_AREA_H

#include "../include.h"

void text_area(GtkWidget *window) {
    GtkWidget *text_paned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_widget_set_hexpand(text_paned, TRUE);
    gtk_widget_set_vexpand(text_paned, TRUE);

    GtkWidget *scrolled_window = gtk_scrolled_window_new();

    GtkWidget *source_view = gtk_source_view_new();
    GtkSourceBuffer *source_buffer = gtk_source_buffer_new(NULL);

    gtk_text_view_set_buffer(GTK_TEXT_VIEW(source_view), GTK_TEXT_BUFFER(source_buffer));

    GtkSourceLanguageManager *language_manager = gtk_source_language_manager_get_default();
    GtkSourceLanguage *language = gtk_source_language_manager_get_language(language_manager, "NULL");
    gtk_source_buffer_set_language(source_buffer, language);

    gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(source_view), TRUE);

    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), source_view);

    gtk_paned_set_start_child(GTK_PANED(text_paned), scrolled_window);

    gtk_grid_attach(GTK_GRID(main_grid), text_paned, 1, 1, 10, 10);
}

#endif
