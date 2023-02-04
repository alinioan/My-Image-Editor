#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	
	GtkWidget *window;
	GtkWidget *box;

	GtkWidget *menubar;
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
	gtk_window_set_default_size(GTK_WINDOW(window), 1000, 700);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), box);

	menubar = gtk_menu_bar_new();
	
	load_Mi = gtk_menu_item_new_with_label("Load");
	crop_Mi = gtk_menu_item_new_with_label("Crop");
	equalize_Mi = gtk_menu_item_new_with_label("Equalize");
	save_Mi = gtk_menu_item_new_with_label("Save");
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

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(select_Mi), select_Menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(select_Menu), select_all_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(select_Menu), select_zone_Mi);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(apply_Mi), apply_Menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(apply_Menu), edge_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(apply_Menu), sharpen_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(apply_Menu), blur_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(apply_Menu), gaussian_blur_Mi);

	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), load_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), select_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), crop_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rotate_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), apply_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), equalize_Mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), save_Mi);

	gtk_box_pack_start(GTK_BOX(box), menubar, FALSE, FALSE, 0);

	g_signal_connect(G_OBJECT(window), "destroy",
			G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
