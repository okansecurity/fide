gcc $(pkg-config --cflags gtk4) -o fide main.c $(pkg-config --libs gtk4)
