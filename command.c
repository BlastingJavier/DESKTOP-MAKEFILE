/**
*@brief Implementa los comandos
*
*@file command.c
*@author FJNR & AMH & CMF & MLR
*@version 1.0aadsf
*@date 01/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "command.h"

/** @brief Longitud maxima de comando*/
#define CMD_LENGHT 128 

/** @brief Numero maximo de comandos*/
#define N_CMD 12 

/**
 * @brief Puntero a char, es una tabla de comandos que el jugador introduce por pantalla
*/
char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "South", "North","West","East","Get","Drop","dice_roll","Movement","check"};
/**
 * @brief Puntero a char, es una tabla de comandos que tendra que pulsar el jugador en la partida
*/
char *short_cmd_to_str[N_CMD] = {"","","e","s","n","w","a","g","d","t","m","c"};



/**
* @author Alejandro Martin
* @brief Implementa los comandos, recogiendo el "input" ,
   transformándolo en un valor numérico de T_command;
* @param No param.
* @return cmd (campo de estructura T_command)
*/
T_Command get_user_input(char *p,char *movement){
  T_Command cmd = NO_CMD;/*-1*/
  char input[CMD_LENGHT] = "";/*Variable "input" (string), leera el comando*/
  int i=UNKNOWN - NO_CMD + 1; /*2*/
  int k;/*Contador secundario para el movimiento*/
  char * palabra =NULL;
  *p = '\0';
  *movement = '\0';

  if (fgets(input,sizeof(input),stdin) != NULL){/*Si lee el comando correctamente*/
    cmd = UNKNOWN; /*cmd=0, siempre*/
    input[strlen(input)-1]='\0';
    palabra = strtok(input, " "); /*Esto hace que coja la palabra hasta el espacio el blanco*/

    while (cmd == UNKNOWN && i < N_CMD){ /*Compara el comando introducido por el jugador con los de la lista*/

      if (!strcasecmp(palabra,short_cmd_to_str[i]) || !strcasecmp(palabra,cmd_to_str[i])){/*Si coinciden "cmd" = el valor que le correponde*/

        cmd = i /*=2*/ + NO_CMD/*=-1*/;
        palabra = strtok(NULL, " "); /*Las demas veces que llamamos a strtok lo hacemos con NULL, pues ya cogio la cadena*/

	 /*Control de errores*/
        if(palabra==NULL){
          if (cmd == GET || cmd == DROP){
            return UNKNOWN;
          }
          else if (cmd == MOVEMENT){
            return UNKNOWN;
          }
          else if (cmd == CHECK){
            return UNKNOWN;
          }
        }
        else{
          if (cmd == GET || cmd == DROP){
            strcpy(p, palabra); /*Copiamos la cadena partida en el parametro*/

          }
          else if (cmd == MOVEMENT){
            for (k=0;k<N_CMD;k++){
              if (!strcasecmp(palabra,cmd_to_str[k]) || !strcasecmp(palabra,short_cmd_to_str[k])){
                strcpy(movement,palabra);
                cmd = (k-1); /*Es un numero magico lo se pero no habia otra*/
              }
            }
          }
          else if (cmd == CHECK){ /*Se podria haber puesto en el primer if pero asi se deja mas claro*/
            strcpy(p, palabra); /*Copiamos la cadena partida en el parametro*/
          }
          else{
            return UNKNOWN;
          }
        }
      }
      else {
	      i++; /*Despues del control de errores, comprobamos en otros cmd*/
      }
    }
  }

  return cmd;
}
