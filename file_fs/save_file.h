#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include "file_area.h"
#include "open_file.h"

void write_file(char *text, const char *file_name) {
    FILE *fptr = fopen(file_name, "w");
    fprintf(fptr, "%s", text);
    fclose(fptr);
}

void read_text_from_notebook(GtkButton *button, GtkNotebook *notebook) {
    gint page_num = gtk_notebook_get_current_page(notebook);
    if (page_num == -1) return; 

    GtkWidget *page = gtk_notebook_get_nth_page(notebook, page_num);
    if (!page) return;

    GtkWidget *tab_label = gtk_notebook_get_tab_label(GTK_NOTEBOOK(notebook), page);
    const gchar *tab_title = NULL;

    if (GTK_IS_LABEL(tab_label)) {
        tab_title = gtk_label_get_text(GTK_LABEL(tab_label));
    }

    GtkTextView *text_view = GTK_TEXT_VIEW(page);
    if (!GTK_IS_TEXT_VIEW(text_view)) {
        GtkWidget *child = gtk_widget_get_first_child(page);
        if (!GTK_IS_TEXT_VIEW(child)) return;
        text_view = GTK_TEXT_VIEW(child);
    }

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
    GtkTextIter start, end;
    gchar *text;

    gtk_text_buffer_get_bounds(buffer, &start, &end);
    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    write_file(text, tab_title);
    
    g_free(text);
}



#endif
