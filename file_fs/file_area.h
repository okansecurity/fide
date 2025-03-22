#ifndef FILE_AREA_H
#define FILE_AREA_H


static void close_tab(GtkWidget *widget, gpointer data) {
    GtkNotebook *notebook = GTK_NOTEBOOK(data);
    gint page_num = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(widget), "page_num"));
    gtk_notebook_remove_page(notebook, page_num);
}

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
    
    GtkWidget *close_button = gtk_button_new_with_label("X");

    g_signal_connect(close_button, "clicked", G_CALLBACK(close_tab), notebook);

    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_append(GTK_BOX(hbox), label);
    gtk_box_append(GTK_BOX(hbox), close_button);

    gtk_notebook_append_page(notebook, scrolled_window, hbox);
}


#endif
