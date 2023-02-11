#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_HEIGHT 700
#define WINDOW_WIDTH 1000

static void open_file_dialog(GtkWidget *widget, gpointer data)
{
	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new("Open File",
										GTK_WINDOW(data),
										GTK_FILE_CHOOSER_ACTION_OPEN,
										"_Cancel",
										GTK_RESPONSE_CANCEL,
										"_Open",
										GTK_RESPONSE_ACCEPT,
										NULL);

	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
		char *filename;
		GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
		filename = gtk_file_chooser_get_filename(chooser);
		printf("Selected file: %s\n", filename);
		g_free(filename);
	}

	gtk_widget_destroy(dialog);
}

static void save_file_dialog(GtkWidget *widget, gpointer data)
{
	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new("Save File",
										GTK_WINDOW(data),
										GTK_FILE_CHOOSER_ACTION_SAVE,
										"_Cancel",
										GTK_RESPONSE_CANCEL,
										"_Save",
										GTK_RESPONSE_ACCEPT,
										NULL);

	gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);

	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
		char *filename;
		GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
		filename = gtk_file_chooser_get_filename(chooser);
		printf("Selected file: %s\n", filename);
		g_free(filename);
	}

	gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	
	GtkWidget *window;
	GtkWidget *box;
	
	GdkPixbuf *pixbuf;
	GtkWidget *image;

	GtkWidget *menubar;
	GtkWidget *file_Mi;
	GtkWidget *file_Menu;
	GtkWidget *load_Mi;
	GtkWidget *select_Mi;
	GtkWidget *select_Menu;
	GtkWidget *select_all_Mi;
	GtkWidget *select_zone_Mi;
	GtkWidget *crop_Mi;
	GtkWidget *rotate_Mi;
	GtkWidget *equalize_Mi;
	GtkWidget *apply_Mi;
	GtkWidget *apply_Menu;
	GtkWidget *edge_Mi;
	GtkWidget *sharpen_Mi;
	GtkWidget *blur_Mi;
	GtkWidget *gaussian_blur_Mi;
	GtkWidget *save_Mi;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Image Editor");
	gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), box);

	menubar = gtk_menu_bar_new();
	
	file_Menu = gtk_menu_new();
	file_Mi = gtk_menu_item_new_with_label("File");
	load_Mi = gtk_menu_item_new_with_label("Load");
	save_Mi = gtk_menu_item_new_with_label("Save");
	
	crop_Mi = gtk_menu_item_new_with_label("Crop");
	equalize_Mi = gtk_menu_item_new_with_label("Equalize");
	rotate_Mi = gtk_menu_item_new_with_label("Rotate");

	select_Menu = gtk_menu_new();
	select_Mi = gtk_menu_item_new_with_label("Select");
	select_zone_Mi = gtk_menu_item_new_with_label("Select Zone");
	select_all_Mi = gtk_menu_item_new_with_label("Select All");

	apply_Menu = gtk_menu_new();
	apply_Mi = gtk_menu_item_new_with_label("Apply");
	edge_Mi = gtk_menu_item_new_with_label("Edge");
	sharpen_Mi = gtk_menu_item_new_with_label("Sharpen");
	blur_Mi = gtk_menu_item_new_with_label("Blur");
	gaussian_blur_Mi = gtk_menu_item_new_with_label("Gaussian Blur");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_Mi), file_Menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_Menu), load_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_Menu), save_Mi);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(select_Mi), select_Menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(select_Menu), select_all_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(select_Menu), select_zone_Mi);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(apply_Mi), apply_Menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(apply_Menu), edge_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(apply_Menu), sharpen_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(apply_Menu), blur_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(apply_Menu), gaussian_blur_Mi);

	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), select_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), crop_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rotate_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), apply_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), equalize_Mi);

	gtk_box_pack_start(GTK_BOX(box), menubar, FALSE, FALSE, 0);

	g_signal_connect(G_OBJECT(window), "destroy",
			G_CALLBACK(gtk_main_quit), NULL);
	
	g_signal_connect(G_OBJECT(load_Mi), "activate",
		G_CALLBACK(open_file_dialog), NULL);

	g_signal_connect(G_OBJECT(save_Mi), "activate",
		G_CALLBACK(save_file_dialog), NULL);

	pixbuf = gdk_pixbuf_new_from_file_at_scale("miguel.jpg", WINDOW_WIDTH, WINDOW_HEIGHT, TRUE, NULL);
	image = gtk_image_new_from_pixbuf(pixbuf);
	gtk_widget_set_size_request(image, WINDOW_WIDTH, WINDOW_HEIGHT);
	gtk_container_add(GTK_CONTAINER(box), image);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
