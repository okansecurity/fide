#ifndef OPEN_FILE_H
#define	OPEN_FILE_H

typedef char* string;

string read_file(const char* file_name) {
    int len = 0;
    int capacity = 2;
    string file_content = (string)malloc(capacity * sizeof(char));

    if (file_content == NULL) {
        fprintf(stderr, "Bellek tahsisi başarısız.\n");
        exit(1);
    }

    FILE *fptr = fopen(file_name, "r");

    if (fptr == NULL) {
        fprintf(stderr, "Dosya açılamadı: %s\n", file_name);
        free(file_content);
        return NULL;
    }

    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        file_content[len] = ch;
        len++;

        if (len >= capacity) {
            capacity *= 2;
            file_content = (string)realloc(file_content, capacity * sizeof(char));
            if (file_content == NULL) {
                fprintf(stderr, "Bellek yeniden tahsisi başarısız.\n");
                fclose(fptr);
                return NULL;
            }
        }
    }

    file_content[len] = '\0';
    fclose(fptr);

    return file_content;
}

void on_file_selected(GtkDialog *dialog, gint response_id, GtkWidget *notebook) {
    if (response_id == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        GFile *filename = gtk_file_chooser_get_file(chooser);

        string a_file_name = g_file_get_path(filename);
        if (!a_file_name) {
            fprintf(stderr, "Dosya adı alınamadı.\n");
            g_object_unref(filename);
            gtk_window_destroy(GTK_WINDOW(dialog));
            return;
        }

        string file_content_new = read_file(a_file_name);
        if (file_content_new) {
            create_new_tab(GTK_NOTEBOOK(notebook), a_file_name, file_content_new);
            free(file_content_new);
        }

        g_free(a_file_name);
        g_object_unref(filename);
    }

    gtk_window_destroy(GTK_WINDOW(dialog));
}

void open_file_f(GtkWidget *window, GtkWidget *notebook) {
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;

    dialog = gtk_file_chooser_dialog_new("OPEN FILE FOR FIDE",
                                         GTK_WINDOW(window),
                                         action,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         "_Open", GTK_RESPONSE_ACCEPT,
                                         NULL);

    g_signal_connect(dialog, "response", G_CALLBACK(on_file_selected), notebook);
    gtk_window_present(GTK_WINDOW(dialog));
}

#endif
