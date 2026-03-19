#include <mysql.h>
#include <stdio.h>
#include <gtk/gtk.h>

static void print_query(GtkWidget *widget, gpointer data)
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "";
    char *database = "test";

    conn = mysql_init(NULL);

    /* Connect to database */
    if (!mysql_real_connect(conn, server, user, password, database, 3306, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    /* send SQL query */
    if (mysql_query(conn, "show tables"))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    /* output table name */
    printf("MySQL Tables in <test> database:\n");

    while ((row = mysql_fetch_row(res)) != NULL)
        printf("%s \n", row[0]);

    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

    gtk_window_set_child(GTK_WINDOW(window), box);

    button = gtk_button_new_with_label("Send Query");

    g_signal_connect(button, "clicked", G_CALLBACK(print_query), NULL);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);

    gtk_box_append(GTK_BOX(box), button);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    system("pause");
    return status;
}
