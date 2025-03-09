#include "include.h"

void on_save_button_clicked(void) {
    printf("Daha başaramadım\n");
}

char *file_open(char *file) {
    char *file_name = file;
    long file_size = 0;
    char *file_content = NULL;
    FILE *active_file = fopen(file_name, "r");

    if (active_file == NULL) {
        printf("Error opening file: %s\n", file_name);
        return NULL;
    }

    fseek(active_file, 0, SEEK_END);
    file_size = ftell(active_file);
    rewind(active_file);

    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        fclose(active_file);
        printf("Memory allocation failed\n");
        return NULL;
    }

    fread(file_content, 1, file_size, active_file);
    file_content[file_size] = '\0'; 

    fclose(active_file);
    return file_content;
}

void select_file(GtkDialog *dialog, int response) {
    if (response == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        g_autoptr(GFile) file = gtk_file_chooser_get_file(chooser);
        char *filename = g_file_get_path(file);

        if (filename) {
            char *file_content = file_open(filename);

            if (file_content != NULL) {
                // Text area'yı dosya içeriği ile güncelle
                text_area_f(file_content, filename); 

                free(file_content); 
            } else {
                printf("Failed to load file content\n");
            }

            g_free(filename); 
        }
    }

    gtk_window_destroy(GTK_WINDOW(dialog));
}




static void on_open_button_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;

    dialog = gtk_file_chooser_dialog_new("Open File",
                                         NULL,
                                         action,
                                         ("_Cancel"),
                                         GTK_RESPONSE_CANCEL,
                                         ("_Open"),
                                         GTK_RESPONSE_ACCEPT,
                                         NULL);

    g_signal_connect(dialog, "response", G_CALLBACK(select_file), NULL);
    gtk_window_present(GTK_WINDOW(dialog));
}


GtkWidget *file_buttons_f(void)
{
    GtkWidget *menu_button = gtk_menu_button_new();
    gtk_menu_button_set_label(GTK_MENU_BUTTON(menu_button), "File");

    GtkWidget *popover = gtk_popover_new();
    gtk_menu_button_set_popover(GTK_MENU_BUTTON(menu_button), popover);
    gtk_popover_set_position(GTK_POPOVER(popover), GTK_POS_BOTTOM);

    GtkWidget *menu_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *item1 = gtk_button_new_with_label("Open");
    GtkWidget *item2 = gtk_button_new_with_label("Save");

    g_signal_connect(item1, "clicked", G_CALLBACK(on_open_button_clicked), NULL);

    gtk_box_append(GTK_BOX(menu_box), item1);
    gtk_box_append(GTK_BOX(menu_box), item2);
    gtk_popover_set_child(GTK_POPOVER(popover), menu_box);

    return menu_button;
}
