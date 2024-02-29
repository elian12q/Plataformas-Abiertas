#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

//Prototipo funciones
void clicked_quad(GtkButton *button, gpointer user_data);
int check_game_status(int t, char matrix[3][3]);

//Definir una estructura para guardar 
typedef struct {
    // Definir un array para almacenar estatus de cada casilla
    // Cada vez que se marca X o O, se pasa el char a su posicion en la matriz
    char quads[3][3];
    GtkLabel *turn_label;
} Status;

// Definir punteros hacia todos los objetos presentes en la plantilla de glade
GtkWidget *window;
GtkWidget *screen_play;
GtkWidget *game_tittle;
GtkWidget *turn_label;
GtkWidget *grid;
GtkWidget *button_quad_1_1;
GtkWidget *button_quad_1_2;
GtkWidget *button_quad_1_3;
GtkWidget *button_quad_2_1;
GtkWidget *button_quad_2_2;
GtkWidget *button_quad_2_3;
GtkWidget *button_quad_3_1;
GtkWidget *button_quad_3_2;
GtkWidget *button_quad_3_3;
GtkBuilder *builder;


int check_game_status(int t, char matrix[3][3]){
    /* Funcion que se encarga de verificar si hasta el momento existe un ganandor o no.
    Esta verificacion se realiza a partir de los casos exitosos para tres posiciones de
    la matriz: [0][0], [1][1] y [2][2] para cubrir de esta forma las ocho posibilidades
    de ganar.*/

    // Verificar casos de victoria para [0][0]
    if (matrix[0][0] == 'X' || matrix[0][0] == 'O'){
        // Si la casilla tiene X o O, se comienza la verificacion
        if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2]){
            // Comprobar igualdad para linea horizontal
            if (matrix[0][0] == 'X'){
                // Retorna 0, corresponde a la victoria de X
                return 0;
            }
            else{
                //Retorna 1, corresponde a la victoria de O
                return 1;
            }
        }
        else if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]){
            // Comprobar igualdad para linea vertical
            if (matrix[0][0] == 'X'){
                //Victoria de X
                return 0;
            }
            else{
                //Retorna 1, corresponde a la victoria de O
                return 1;
            }
        }
        else if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
            //Comprobar igualda para linea diagonal
             if (matrix[0][0] == 'X'){
                //Victoria de X
                return 0;
            }
            else{
                //Retorna 1, corresponde a la victoria de O
                return 1;
            }
        }
        else{
            // Seguir revisando
        }
    }
    // Verificar casos de victoria para [1][1]
    if (matrix[1][1] == 'X' || matrix[1][1] == 'O'){
        // Si la casilla tiene X o O, se comienza la verificacion
        if (matrix[1][1] == matrix[0][1] && matrix[0][1] == matrix[2][1]){
            // Comprobar igualdad para linea vertical
            if (matrix[1][1] == 'X'){
                // Retorna 0, corresponde a la victoria de X
                return 0;
            }
            else{
                //Retorna 1, corresponde a la victoria de O
                return 1;
            }
        }
        else if (matrix[1][1] == matrix[1][0] && matrix[1][0] == matrix[1][2]){
            // Comprobar igualdad para linea horizontal
            if (matrix[1][1] == 'X'){
                //Victoria de X
                return 0;
            }
            else{
                //Retorna 1, corresponde a la victoria de O
                return 1;
            }
        }
        else if (matrix[1][1] == matrix[2][0] && matrix[2][0] == matrix[0][2]){
            //Comprobar igualdad para linea diagonal /
             if (matrix[1][1] == 'X'){
                //Victoria de X
                return 0;
            }
            else{
                //Retorna 1, corresponde a la victoria de O
                return 1;
            }
        }
        else{
            // Seguir revisando
        }
    }
    // Verificar casos de victoria para [2][2]
    if (matrix[2][2] == 'X' || matrix[2][2] == 'O'){
        // Si la casilla tiene X o O, se comienza la verificacion
        if (matrix[2][2] == matrix[2][1] && matrix[2][1] == matrix[2][0]){
            // Comprobar igualdad para linea horizontal
            if (matrix[2][2] == 'X'){
                // Retorna 0, corresponde a la victoria de X
                return 0;
            }
            else{
                //Retorna 1, corresponde a la victoria de O
                return 1;
            }
        }
        else if (matrix[2][2] == matrix[1][2] && matrix[1][2] == matrix[0][2]){
            // Comprobar igualdad para linea vertical
            if (matrix[2][2] == 'X'){
                //Victoria de X
                return 0;
            }
            else{
                //Retorna 1, corresponde a la victoria de O
                return 1;
            }
        }
        else{
            // Al no cumplir ninguna condicion, sigue jugando
            return 2;
        }
    }
    else{
        // Sigue jugando
        return 2;
    }
}


int main(int argc, char **argv){
    // Funcion principal en donde se coloca todo el codigo referente a la interfaz
    // Inicializar GTK
    gtk_init(&argc, &argv);

    // Inicializar constructor
    builder = gtk_builder_new_from_file ("templates_glade.glade");

    // Cargar pantalla de inicio
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    // Activar senal para cerrar ventanta
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Definir conexiones entre botones y codigo
    screen_play = GTK_WIDGET(gtk_builder_get_object(builder, "screen_play"));
    game_tittle = GTK_WIDGET(gtk_builder_get_object(builder, "game_tittle"));
    turn_label = GTK_WIDGET(gtk_builder_get_object(builder, "turn_label"));
    button_quad_1_1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_1_1"));
    button_quad_1_2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_1_2"));
    button_quad_1_3 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_1_3"));
    button_quad_2_1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_2_1"));
    button_quad_2_2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_2_2"));
    button_quad_2_3 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_2_3"));
    button_quad_3_1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_3_1"));
    button_quad_3_2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_3_2"));
    button_quad_3_3 = GTK_WIDGET(gtk_builder_get_object(builder, "button_quad_3_3"));

    // Mostrar todos los elementos de start_window
    gtk_widget_show(window);

    //Instancia de Status e inicializacion de la matriz
    Status game  = {0};
    game.turn_label = GTK_LABEL(turn_label);

    //Conectar senales con los botones
    g_signal_connect(button_quad_1_1, "clicked", G_CALLBACK(clicked_quad), &game);
    g_signal_connect(button_quad_1_2, "clicked", G_CALLBACK(clicked_quad), &game);
    g_signal_connect(button_quad_1_3, "clicked", G_CALLBACK(clicked_quad), &game);
    g_signal_connect(button_quad_2_1, "clicked", G_CALLBACK(clicked_quad), &game);
    g_signal_connect(button_quad_2_2, "clicked", G_CALLBACK(clicked_quad), &game);
    g_signal_connect(button_quad_2_3, "clicked", G_CALLBACK(clicked_quad), &game);
    g_signal_connect(button_quad_3_1, "clicked", G_CALLBACK(clicked_quad), &game);
    g_signal_connect(button_quad_3_2, "clicked", G_CALLBACK(clicked_quad), &game);
    g_signal_connect(button_quad_3_3, "clicked", G_CALLBACK(clicked_quad), &game);

    //Gtk Main
    gtk_main(); 

    return 0;
}


void clicked_quad(GtkButton *button, gpointer user_data){
    // Funcion relacionada al clickeo de cada uno de los botones
    // Se debe chequear el texto del boton
    GtkWidget *button_label = gtk_bin_get_child(GTK_BIN(button));
    const char *button_text = gtk_label_get_text(GTK_LABEL(button_label));

    // Instanciar estructura para cambiar mensaje y modificar matriz
    Status *change_status = (Status *)user_data;

    // Establecer contador de turnos que ayudara a determinar quien tiene el turno
    static int turn = 0;

    // Definir una variable entera para recibir status del juego
    static int win_tie = -1;

    // Variable auxiliar para almacenar caracter marcado por el usuario
    char aux_char;

    // Mensajes en pantalla (Turnos y Victoria)
    const char *turn_x = "Turno de X";
    const char *turn_o = "Turno de O";
    const char *win_x  = "El ganador es X";
    const char *win_o = "El ganador es O";
    const char *tie = "Empate";

    // Colocar X o O en el recuadro segun corresponda
    if (strcmp(button_text, "X") != 0 && strcmp(button_text, "O") != 0){
        // Verificar que el cuadrante no tiene ni X ni O
        // De acuerdo al valor de turn % 2 se pondra una X o una O en el recuadro
        if (turn % 2 == 0){
        // Turno de x
        gtk_button_set_label(GTK_BUTTON(button), "X");
        
        // Aumentar el contador y cambiar var auxiliar
        turn++;
        aux_char = 'X';

        // Cambiar el texto que indica el turno
        gtk_label_set_text(change_status->turn_label, turn_o);

        }
        else {
        // Turno de o
        gtk_button_set_label(GTK_BUTTON(button), "O");

        // Aumentar el contador y cambiar var auxiliar
        turn++;
        aux_char = 'O';

        // Cambiar el texto que indica el turno
        gtk_label_set_text(change_status->turn_label, turn_x);
        }

        // Actualizar los valores de la matriz
        if (button == GTK_BUTTON(button_quad_1_1)){
            change_status->quads[0][0] = aux_char;
        }
        else if (button == GTK_BUTTON(button_quad_1_2)){
            change_status->quads[0][1] = aux_char;
        }
        else if (button == GTK_BUTTON(button_quad_1_3)){
            change_status->quads[0][2] = aux_char;
        }
        else if (button == GTK_BUTTON(button_quad_2_1)){
            change_status->quads[1][0] = aux_char;
        }
        else if (button == GTK_BUTTON(button_quad_2_2)){
            change_status->quads[1][1] = aux_char;
        }
        else if (button == GTK_BUTTON(button_quad_2_3)){
            change_status->quads[1][2] = aux_char;
        }
        else if (button == GTK_BUTTON(button_quad_3_1)){
            change_status->quads[2][0] = aux_char;
        }
        else if (button == GTK_BUTTON(button_quad_3_2)){
            change_status->quads[2][1] = aux_char;
        }
        else if (button == GTK_BUTTON(button_quad_3_3)){
            change_status->quads[2][2] = aux_char;
        }
        else{
            // Omitir
        }

        /* Despues de actualizar la matriz de forma que contenga los mismos
        valores de las casillas que se muestran en pantalla, se recurre a
        una funcion para chequear al llenar una casilla si ya existe un ganador
        */

        win_tie = check_game_status(turn, change_status->quads);

        // Cambiar el mensaje en pantalla de acuerdo al valor retornado
        if (win_tie == 0){
            // El ganador es X
            gtk_label_set_text(change_status->turn_label, win_x);

            // Crear un dialogo para avisa que el juego finalizo
            GtkWidget *finish = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
            GTK_BUTTONS_CLOSE, "El juego ha finalizado, el ganador es X.");

            gtk_dialog_run(GTK_DIALOG(finish));
            gtk_widget_destroy(finish);

            // Cerar el programa
            gtk_main_quit();
        }
        else if (win_tie == 1){
            // El ganador es O
            gtk_label_set_text(change_status->turn_label, win_o);
            gtk_main_quit();

            // Crear un dialogo para avisa que el juego finalizo
            GtkWidget *finish = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
            GTK_BUTTONS_CLOSE, "El juego ha finalizado, el ganador es O.");

            gtk_dialog_run(GTK_DIALOG(finish));
            gtk_widget_destroy(finish);

            // Cerar el programa
            gtk_main_quit();
        }
        else if (win_tie == 2 && turn == 9){
            // Si ya pasaron 9 turnos, el juego termino en empate
            gtk_label_set_text(change_status->turn_label, tie);
            gtk_main_quit();

            // Crear un dialogo para avisa que el juego finalizo
            GtkWidget *finish = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
            GTK_BUTTONS_CLOSE, "El juego ha finalizado en empate.");

            gtk_dialog_run(GTK_DIALOG(finish));
            gtk_widget_destroy(finish);

            // Cerar el programa
            gtk_main_quit();
        }
        else{
            // Si devuelve 2 y aun quedan casillas vacias sigue jugando
        }
    }
    else{
        // Si esta ocupado no ocurre nada
    }
}