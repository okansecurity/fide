#ifndef INCLUDE_H
#define INCLUDE_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

GtkWidget *window = NULL;
GtkApplication *app = NULL;

//main box 
GtkWidget *main_box = NULL;

GtkWidget *dialog = NULL;

//text bölümü
GtkWidget *text_area = NULL;
GtkWidget *text_view = NULL;
char *file_in;
void text_area_f(const char *file_content, const char *window_title);

#endif
