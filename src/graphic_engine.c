/**
 * @brief Define un motor gráfico
 *
 * @file graphic_engine.c
 *@author FJNR & AMH & CMF & MLR
 * @version 1.0
 *@date 05/02/2018
 * @copyright GNU Public License
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "graphic_engine.h"
#include "dice.h"

/** @brief Numero de objeto de */
#define NUM_OBJ 4
/** @brief constante del comando CHECK*/
#define CHECK_CONSTANT 10

/**                 Definidos en:
                        ||
                        ||
                        V
WORD_SIZE = 1000 <==types.h
MAX_SPACES = 100 <==space.h
FIRST_SPACE = 1 <==space.h
NO_ID = -1 <==types.h
NO_CMD = -1 <==command.h
UNKNOWN = 0 <==command.h
EXIT = 1 <==command.h
FOLLOWING = 2 <==command.h
PREVIOUS = 3 <==command.h
SCREEN_MAX_STR = 80 <==screen.h
P.F.: Private Function
*/

/**
 *@brief Estructura que define el Graphic_engine tamaño del area
*/
struct _Graphic_engine{
  Area *map, /*Area del mapa*/
       *descript,/*Zona de descipcion de la pantalla*/
       *banner, /*Zona del banner en el interfaz*/
       *help,/*Ayuda (comandos que se pueden utilizar)*/
       *feedback, /*Zona de feedback, donde se muestran los comandos*/
       *player_info,/*Informacion del personaje (objetos que lleva)*/
       *object_info,
       *space_info;
};



/**
 * @author Francisco Nanclares
 * @brief Tiene la función de crear el área (se generan unos puntos en la
    pantalla con: (x,y,width,height)) de los interfaces del juego
    (inicializa la estructura de Graphic_engine)
 * @param nada
 * @return "ge", el puntero que contiene los elementos de la estructura
    (punteros de tipo Area)
 */
Graphic_engine *graphic_engine_create(){
  /*Conserva el valor (static)*/
  static Graphic_engine *ge = NULL;

  if (ge){
    return ge;
  }

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));
  /*Definicion de areas*/
  ge->map      = screen_area_init( 1, 1, 48, 22);
  ge->descript = screen_area_init(51, 4, 27, 7);
  ge->banner   = screen_area_init(40, 24, 23, 1);
  ge->help     = screen_area_init( 1,25, 105, 2);
  ge->feedback = screen_area_init( 1,27, 105,3);
  ge->player_info = screen_area_init(51,14,27,7);
  ge->object_info = screen_area_init(79,4,27,7);
  ge->space_info = screen_area_init(79,14,27,7);

  return ge;
}



/**
 * @author Francisco Nanclares
 * @brief Tiene la función de liberar la memoria de todos los campos de ge
 * @param "ge", el puntero a "Graphic_engine"
 * @return, ya que es una función de tipo void
 */
void graphic_engine_destroy(Graphic_engine *ge){
  if (!ge){
    return;
  }

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);
  screen_area_destroy(ge->player_info);
  screen_area_destroy(ge->object_info);
  screen_area_destroy(ge->space_info);

  screen_destroy();
  free(ge);
}



/*
 * @author Francisco Nanclares
 * @brief Dibuja cada área en la pantalla de salida (se generan puntos en la
    pantalla con: (x,y,width,height))
 * @param "ge",  el puntero a "Graphic_engine"
 * @param "game", el puntero a "Game"
 * @return, ya que es una función de tipo void
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;/*Id*/
  Id id_left ,id_right;
  int i,cuenta_atras;/*Opcion posterior (por ahora solo controla la variable dado)numero*/
  Space* space_actual = NULL;
  Space *space_next = NULL;
  Space *space_previous = NULL;

  Link *possible_link_next = NULL;
  Link *possible_link_previous = NULL;
  Link *possible_link_right = NULL;
  Link *possible_link_left = NULL;

  Id id_space_connection_left1 = NO_ID;
  Id id_space_connection_left2 = NO_ID;

  Id id_space_connection_right1 = NO_ID;
  Id id_space_connection_right2 = NO_ID;

  Id id_space_connection_north1 = NO_ID;
  Id id_space_connection_north2 = NO_ID;

  Id id_space_connection_south1 = NO_ID;
  Id id_space_connection_south2 = NO_ID;

  Id id_link = NO_ID;

  char* obj[NUM_OBJ];/*Array de objetos*/
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[];/*string del nombre del comando*/
  char *gdesc[3];/*strings de descripcion grafica*/
  /*Dibuja el área de mapa*/
  Object *object;

  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){
    /* Obtiene la estructura de tipo Space para id_act (casilla actual),
      y el id de las casillas anterior (id_back) y posterior (id_next) respecto
      del jugador */
    space_actual = game_get_space(game, id_act);

    id_back = space_get_link_north(space_actual);
    id_next = space_get_link_south(space_actual);
    id_left = space_get_link_west(space_actual);
    id_right = space_get_link_east(space_actual);

    possible_link_left = game_get_link(game,id_left);
    possible_link_right = game_get_link(game,id_right);
    possible_link_next = game_get_link(game,id_next);
    possible_link_previous = game_get_link(game,id_back);

    for (i=0;i<NUM_OBJ;i++){
      /*3 espacios porque es lo que ocupa nuestro nombre de objeto en data.dat*/
      obj[i] = "   ";
    }

    /*Como ahora tenemos varios objeto ...*/
    for (i=0;i<MAX_ID;i++){
      if ((object = game_get_object(game,i)) != NULL){
        if (game_get_object_location(game,object) == id_back){
          obj[i] = object_get_name(object);
        }
      }
    }
    /*Casilla anterior (efecto de refresco)*/
    if (id_back != NO_ID) {
      id_link = link_get_id(possible_link_previous);
      id_space_connection_north2 = link_get_id_space2(possible_link_previous);
      space_previous = game_get_space(game,id_space_connection_north2);



      gdesc[0] = space_get_gdesc1(space_previous);
      gdesc[1] = space_get_gdesc2(space_previous);
      gdesc[2] = space_get_gdesc3(space_previous);

      sprintf(str, "      | %s%2d |",gdesc[0],(int)id_space_connection_north2);
      screen_area_puts(ge->map, str);
      sprintf(str, "      | %s |",gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      | %s |",gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      | %s  %s  %s  %s|",obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      +-------------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "            ^%2d",(int)id_link);
      screen_area_puts(ge->map, str);
    }

    for (i=0;i<NUM_OBJ;i++){
      obj[i] = "   ";
    }

    for (i=0;i<MAX_ID;i++){
      if ((object = game_get_object(game,i)) != NULL){
        if (game_get_object_location(game,object) == id_act){
          obj[i] = object_get_name(object);
        }
      }
    }
      /*Las casillas hay que redimensionarlas*/
    /*Casilla actual (efecto de refresco)*/
    if (id_act != NO_ID) {
      space_actual = game_get_space(game,id_act);
      id_space_connection_left2 = link_get_id_space2(possible_link_left);/*Hay un uno left1 o right1 no necesario*/
      id_space_connection_right2 = link_get_id_space2(possible_link_right);

      gdesc[0] = space_get_gdesc1(space_actual);
      gdesc[1] = space_get_gdesc2(space_actual);
      gdesc[2] = space_get_gdesc3(space_actual);

      if (id_act != NO_ID && id_left != NO_ID && id_right !=NO_ID){
        sprintf(str, " %2d+-------------------+%2d",(int)id_left,(int)id_right);
        screen_area_puts(ge->map, str);
        sprintf(str, "%2d<--| 8D             %2d |-->%2d",(int)id_space_connection_left2,(int)id_act,(int)id_space_connection_right2);
      }
      else if(id_act !=NO_ID && id_left == NO_ID && id_right != NO_ID){
        sprintf(str, "  +-------------------+%2d",(int)id_right);
        screen_area_puts(ge->map, str);
        sprintf(str, "  | 8D             %2d |-->%2d",(int)id_act,(int)id_space_connection_right2);
      }
      else if(id_act !=NO_ID && id_left != NO_ID && id_right == NO_ID){
        sprintf(str, " %2d +-------------------+",(int)id_left);
        screen_area_puts(ge->map, str);
        sprintf(str, "%2d<--| 8D             %2d |",(int)id_space_connection_left2,(int)id_act);
      }
      else {
        sprintf(str, "    +-------------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "    | 8D             %2d |",(int)id_act);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      |                   |");
      screen_area_puts(ge->map, str);
      sprintf(str, "      |                   |");
      screen_area_puts(ge->map, str);
      sprintf(str, "      | %s |",gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      | %s |",gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      | %s |",gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |                   |");
      screen_area_puts(ge->map, str);
      sprintf(str, "      |                   |");
      screen_area_puts(ge->map, str);
      sprintf(str, "      | %s  %s  %s  %s|",obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "      +-------------------+");
      screen_area_puts(ge->map, str);
    }
    for (i=0;i<NUM_OBJ;i++){
      obj[i] = "   ";
    }

    for (i=0;i<MAX_ID;i++){
      if ((object = game_get_object(game,i)) != NULL){
        if (game_get_object_location(game,object) == id_next){
          obj[i] = object_get_name(object);
        }
      }
    }
    /*Casilla siguiente (efecto de refresco)*/
    if (id_next != NO_ID) {
      id_link = link_get_id(possible_link_next);
      id_space_connection_south2 = link_get_id_space2(possible_link_next);
      space_next = game_get_space(game,id_space_connection_south2);



      gdesc[0] = space_get_gdesc1(space_next);
      gdesc[1] = space_get_gdesc2(space_next);
      gdesc[2] = space_get_gdesc3(space_next);
      sprintf(str, "        v%2d",(int)id_link);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-------------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s%2d|",gdesc[0],(int)id_space_connection_south2);
      screen_area_puts(ge->map, str);
      sprintf(str, "  | %s |",gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  | %s |",gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  | %s  %s  %s  %s|",obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
    }
  }

  /*Dibuja la zona descriptiva*/

  screen_area_clear(ge->descript);
  sprintf(str,"Object Location:");
  screen_area_puts(ge->descript,str);

  /*Se encarga de recorrer el array de objetos pone el nombre que le hemos otorgado
    en el fichero de datos*/

  for (i=0;i<MAX_ID;i++){
    if ((object = game_get_object(game,i)) != NULL){
      obj_loc = game_get_object_location(game,object);
      if (obj_loc != NO_ID){
        sprintf(str,"%s:%d",object_get_name(object),(int)obj_loc);
        screen_area_puts(ge->descript,str);
      }
    }
  }

  screen_area_clear(ge->player_info);
  sprintf(str,"Inventory items: ");
  screen_area_puts(ge->player_info,str);
  /*Se encarga de recorrer el array de objetos y ver si el player tiene ese objeto,
    si lo tiene, lo muestra en otra pantalla (player_info)*/
  for (i=0;i<MAX_ID; i++){
    if ((object = game_get_object(game,i)) != NULL){
      obj_loc = game_get_object_player(game,object);
      if (obj_loc ==TRUE){
        sprintf(str,"  %s",object_get_name(object));
        screen_area_puts(ge->player_info,str);
      }
    }
  }


  /*Dibuja la zona del banner*/
  screen_area_puts(ge->banner, " The game of the Goose ");

  /*Dibuja la zona de help*/
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     movement=>movement+(north,south,west,east) / exit=>e / grasp=>g / drop=>d / throw_die=>t / check=>c");
  screen_area_puts(ge->help, str);

  /*Dibuja el área de feedback*/
  last_cmd = game_get_last_command(game);

  if (game_get_last_command_flag(game)==ERROR){
    sprintf(str, " %s: ERROR", cmd_to_str[last_cmd-NO_CMD]);
    screen_area_puts(ge->feedback, str);
  }
  else {
    sprintf(str, " %s: OK", cmd_to_str[last_cmd-NO_CMD]);
    screen_area_puts(ge->feedback, str);
  }


  cuenta_atras = dice_get_last_shot(game_get_dice(game));
  sprintf(str, "Last throw (dice): %d",cuenta_atras);
  screen_area_puts(ge->descript,str);

  /*Parte nueva iteracion 3*/
  screen_area_clear(ge->object_info);
  sprintf(str,"Object info:");
  screen_area_puts(ge->object_info,str);
  if (last_cmd == CHECK_CONSTANT){
    sprintf(str,"%s",game_get_object_description(game));
    screen_area_puts(ge->object_info,str);
  }

  screen_area_clear(ge->space_info);
  sprintf(str,"Space info:");
  screen_area_puts(ge->space_info,str);
  if (last_cmd = CHECK_CONSTANT){
    sprintf(str,"%s",game_get_space_description(game));
    screen_area_puts(ge->space_info,str);
  }

  /*Lo pasa al terminal*/
  screen_paint();
  printf("prompt:> ");
}