#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
 

GtkWidget *g_lbl_count;
GtkWidget *lbl_input;
GtkWidget *text_input;
GtkWidget *text_input1;
GtkWidget *lbl_input1;
GtkWidget *lbl_input2;
GtkWidget *lbl_input3;
GtkWidget *lbl_input4;
GtkWidget *lbl_input5;
GtkWidget *lbl_input6;
GtkWidget *lbl_input7;
GtkWidget *btn_input;
GtkWidget *btn_search;
GtkWidget *lbl_search;
GtkWidget *lbl_search1;
GtkWidget *text_search;
GtkWidget *text_search2;
GtkWidget *btn_set;
GtkWidget *btn_start;
GtkWidget *text_search3;

int number = 1000,person = 10,who = 0,check = 0,id = 0,idi = 0,i = 0;
const char *day[15],*dot[5],*days[15];

typedef struct data
{
    int ids,debt;
};

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    text_input = GTK_WIDGET(gtk_builder_get_object(builder, "text_input"));
    text_input1 = GTK_WIDGET(gtk_builder_get_object(builder, "text_input1"));

    GdkColor color;
    color.red = 0x3434;
    color.green = 0x6565;
    color.blue = 0xa4a4;
    gtk_widget_modify_bg( window, 0, &color );
 
    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}
 
// called when window is closed
void on_start_button_clicked()
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "GtkWindow"));
    gtk_builder_connect_signals(builder, NULL);

    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));
    lbl_input = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_input"));
    lbl_input1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_input1"));
    lbl_input2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_input2"));
    lbl_input3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_input3"));
    lbl_input3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_input4"));
    lbl_input3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_input5"));
    lbl_input6 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_input6"));
    lbl_input7 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_input7"));
    btn_input = GTK_WIDGET(gtk_builder_get_object(builder, "btn_input"));
    text_search3 = GTK_WIDGET(gtk_builder_get_object(builder, "text_search3"));
    *days = "DD/MM/YYYY";
    
    g_object_unref(builder);
 
    gtk_widget_show(window);                
}
void on_btn_hello_clicked()
{
    static unsigned int count = 5;
    char str_count[30] = {0};
    
    count++;
    sprintf(str_count, "%d", count);
    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);
}
void on_text_input_changed(GtkEntry *e)
{
    char input[100] = {0};
    *dot = ".";
    long long int num = atoi(gtk_entry_get_text(e));
    number = num*100;
    sprintf(input,"%lld",num*100+1);
    gtk_label_set_text(GTK_LABEL(lbl_input), input);
    sprintf(input,"%lld",num*100+2);
    gtk_label_set_text(GTK_LABEL(lbl_input1), input);
    sprintf(input,"%lld",num*100+3);
    gtk_label_set_text(GTK_LABEL(lbl_input2), input);
    sprintf(input,"%lld",num*100+4);
    gtk_label_set_text(GTK_LABEL(lbl_input3), input);
}
void on_text_search3_changed(GtkEntry *t)
{
    char input[100] = {0};
    *days = (gtk_entry_get_text(t));
    sprintf(input,"%s",*days);
    gtk_label_set_text(GTK_LABEL(lbl_input7), input);
}
void on_text_input1_changed(GtkEntry *i)
{
    char input[100] = {0};
    int num = atoi(gtk_entry_get_text(i));
    person = num;
    sprintf(input,"%d",number+num);
    gtk_label_set_text(GTK_LABEL(lbl_input6), input);
}
void on_btn_input_clicked()
{
 FILE *fp;
    fp  = fopen ("Data/data.txt", "a");
    char input[100] = {0};
    sprintf(input,"%s",*days);
    fputs("=========================  ", fp);
    fputs(input, fp);
    fputs("  =========================\n", fp);
    for (int i = 1; i < person+1; i++)
{
        sprintf(input,"%d",number+i);
        fputs(input, fp);
        fputs(" : ", fp);
        fputs("0 \n", fp);

}
    fclose(fp);   

}
void on_btn_start_clicked()
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_user"));
    gtk_builder_connect_signals(builder, NULL);
    btn_search = GTK_WIDGET(gtk_builder_get_object(builder, "btn_search"));
    text_search = GTK_WIDGET(gtk_builder_get_object(builder, "text_search"));
    lbl_search = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_search"));
    lbl_search1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_search1"));
    text_search2 = GTK_WIDGET(gtk_builder_get_object(builder, "text_search2"));
    btn_set = GTK_WIDGET(gtk_builder_get_object(builder, "btn_set"));

    g_object_unref(builder);
 
    gtk_widget_show(window); 
}
void on_text_search2_changed(GtkEntry *s)
{

    *day = (gtk_entry_get_text(s));
}
void on_btn_set_clicked()
{
    FILE *fp;
    fp  = fopen ("Data/data.txt", "a");
    char input[100] = {0};
    sprintf(input,"%s",*day);
    fputs("=========================  ", fp);
    fputs(input, fp);
    fputs("  =========================\n", fp);
    fclose(fp);
}
void on_text_search_changed(GtkEntry *s)
{

    int num = atoi(gtk_entry_get_text(s));
    id = num;
}
void on_text_search1_changed(GtkEntry *s)
{

    int num = atoi(gtk_entry_get_text(s));
    idi = num;
}
void on_btn_search_clicked()
{
    FILE *fp;
    fp  = fopen ("Data/data.txt", "a");
    char input[100] = {0};
    sprintf(input,"%d",id);
    fputs(input, fp);
    fputs(" : ", fp);
    sprintf(input,"%d",idi);
    fputs(input, fp);
    fputs("\n", fp);
    fclose(fp);
}

void on_window_main_destroy()
{
    gtk_main_quit();
}



