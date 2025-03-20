#ifndef FILE_AREA_H
#define FILE_AREA_H

void create_new_tab(GtkNotebook* notebook, const char *file_name, const gchar *file_content) {
    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_widget_set_hexpand(scrolled_window, TRUE);
    gtk_widget_set_vexpand(scrolled_window, TRUE);
    
    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), text_view);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    
    if (file_content) {
        GtkTextIter end;
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_buffer_insert(buffer, &end, file_content, -1);
    }
    
    GtkWidget *label = gtk_label_new(file_name);
    gtk_notebook_append_page(notebook, scrolled_window, label);
}

#endif
