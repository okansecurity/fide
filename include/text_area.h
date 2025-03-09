#include "include.h"

void text_area_f(const char *file_content, const char *window_title) {
    text_area = gtk_grid_new();

    text_view = gtk_text_view_new();
    gtk_grid_attach(GTK_GRID(text_area), text_view, 0, 0, 1, 1);

    gtk_widget_set_size_request(text_view, 400, 300);
    gtk_widget_set_hexpand(text_view, TRUE);
    gtk_widget_set_vexpand(text_view, TRUE);

    gtk_widget_set_hexpand(text_area, TRUE);
    gtk_widget_set_vexpand(text_area, TRUE);

    gtk_box_append(GTK_BOX(main_box), text_area);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    if (file_content != NULL) {
        gtk_text_buffer_set_text(buffer, file_content, -1);
    } else {
        printf("No content to display\n");
    }

    gtk_widget_show(text_area);
    gtk_widget_show(text_view);
}
