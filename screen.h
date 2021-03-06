/**
 * @brief Define la pantalla
 *
 *
 * @file screen.h
 * @author FJNR & AMH & CMF & MLR
 * @version 1.0
 * @date 04/02/2018
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__
#define SCREEN_MAX_STR 80

/**
 * @brief Estructura que define la posición y tamaño de cada área ,y un puntero a char
  (cursor) que sirve para una "linked list"
*/
typedef struct _Area Area;



/**
 * @author Francisco Nanclares
 * @brief Reserva memoria dinámica para data y pone todos los caractes a BG_CHAR
 * @param nada
 * @return, nada ya que es una función de tipo void
 */
void  screen_init();



/**
 * @author Francisco Nanclares
 * @brief Libera memoria dinámica para "__data"
 * @param nada
 * @return, nada ya que es una función de tipo void
 */
void  screen_destroy();



/**
 * @author Francisco Nanclares
 * @brief Colorea la pantalla de azul donde no hay interfaz
    y de gris donde se desarrolla el juego.
 * @param nada
 * @return,nada ya que es una función de tipo void
 */
void  screen_paint();



/**
 * @author Francisco Nanclares
 * @brief Escribe por pantalla prompt: y coge las columnas al imprimir
 * @param str, un puntero a char, el string
 * @return,nada ya que es una función de tipo void
 */
void  screen_gets(char *str);



/**
 * @author Alejandro Martin
 * @brief Crea memoria dinámica para el area y copia el caracter c a los
  primeros n caracteres del string
 * @param x, coordenada cuadrada de un área
 * @param y, coordenada cuadrada de un área
 * @param width, la anchura
 * @param height, la altura
 * @return area, la estructura
 */
Area* screen_area_init(int x, int y, int width, int height);



/**
 * @author Alejandro Martin
 * @brief Libera memoria almacenada de manera dinamica de area
 * @param area, la estructura
 * @return nada, porque es una función de tipo void
 */
void  screen_area_destroy(Area* area);



/**
 * @author Carlos Miret
 * @brief Borra lo que hay en la pantalla
 * @param area, la estructura
 * @return nada, porque es una función de tipo void
 */
void  screen_area_clear(Area* area);



/**
 * @author Carlos Miret
 * @brief Resetea el cursor
 * @param area, la estructura
 * @return nada, porque es una función de tipo void
 */
void  screen_area_reset_cursor(Area* area);



/**
 * @author Carlos Miret
 * @brief Si la pantalla se va del limite la sube y se remplazan los caracteres
    especiales/
 * @param area, la estructura
 * @param str, un puntero a char, el string
 * @return nada, porque es una función de tipo void
 */
void  screen_area_puts(Area* area, char *str);

#endif
