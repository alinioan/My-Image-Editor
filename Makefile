# Copyright 2023 Alexandru Alin-Ioan
# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
GTKFLAGS=`pkg-config --cflags gtk+-3.0`
GTKLIB=`pkg-config --libs gtk+-3.0`

# define targets
TARGETS= window


build: $(TARGETS) 
	$(CC) $(CFLAGS) $(GTKFLAGS) window.o -o image_editor_GUI $(GTKLIB)

window: window.c
	$(CC) $(CFLAGS) $(GTKFLAGS) -c window.c -o window.o $(GTKLIB)