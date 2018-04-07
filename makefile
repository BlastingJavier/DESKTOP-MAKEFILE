#####################################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi -I./include
MODULOS=game_loop_exe dice_test set_test link_test space_test player_test object_test
##########################################################
#Opciones de enlazado para indicar el directorio donde localizar  las bibliotecas
###########################################################
SRCPATH = src/
INCPATH = include/
OBJPATH = obj/
#########################################################
OBJECTS = $(OBJPATH)command.o $(OBJPATH)game_loop.o $(OBJPATH)game.o $(OBJPATH)graphic_engine.o $(OBJPATH)screen.o $(OBJPATH)space.o $(OBJPATH)player.o $(OBJPATH)object.o $(OBJPATH)game_reader.o $(OBJPATH)set.o $(OBJPATH)dice.o $(OBJPATH)inventory.o $(OBJPATH)link.o
OBJECTSCOMMAND = $(OBJPATH)command.o
OBJECTSGALOOP = $(OBJPATH)game_loop.o
OBJECTSGAME = $(OBJPATH)game.o
OBJECTSGRAPHIC = $(OBJPATH)graphic_engine.o
OBJECTSSCREEN = $(OBJPATH)screen.o
OBJECTSSPACE = $(OBJPATH)space_test.o $(OBJPATH)space.o $(OBJPATH)set.o $(OBJPATH)link.o
OBJECTSDICE = $(OBJPATH)dice_test.o $(OBJPATH)dice.o
OBJECTSINVENTORY = $(OBJPATH)inventory_test.o $(OBJPATH)inventory.o
OBJECTSLINK = $(OBJPATH)link_test.o $(OBJPATH)link.o $(OBJPATH)space.o $(OBJPATH)set.o
OBJECTSSET = $(OBJPATH)set_test.o $(OBJPATH)set.o
OBJECTSPLAYER = $(OBJPATH)player_test.o $(OBJPATH)player.o $(OBJPATH)object.o $(OBJPATH)inventory.o $(OBJPATH)set.o
OBJECTSOBJECT = $(OBJPATH)object_test.o $(OBJPATH)object.o
##########################################################
##########################################################
OBJECTS_TO_CLEAN = $(OBJPATH)command.o $(OBJPATH)game_loop.o $(OBJPATH)game.o $(OBJPATH)graphic_engine.o $(OBJPATH)screen.o $(OBJPATH)space.o $(OBJPATH)object.o $(OBJPATH)game_reader.o $(OBJPATH)player.o $(OBJPATH)dice.o $(OBJPATH)dice_test.o $(OBJPATH)set.o $(OBJPATH)inventory.o $(OBJPATH)link.o
EXE_CLEAN = game_loop_exe dice_test set_test link_test inventory_test space_test player_test object_test
#HAY QUE PONER MAS
HEADERS_TO_SUBMIT =*.h
SOURCES_TO_SUBMIT = command.c game.c graphic_engine.c screen.c space.c game_loop.c dice.c set.c inventory.c link.c
SUPPORT_TO_SUBMIT = makefile
#######################################################
#En el caso de que haya instrucciones adicionales.
MEMORIES_TO_SUBMIT =*.pdf

.PHONY: all
all: $(MODULOS)
#COMANDOS
game_loop_exe:$(OBJECTS)
	$(CC) $(CFLAGS) -o game_loop_exe $(OBJECTS)
dice_test: $(OBJECTSDICE)
	$(CC) $(CFLAGS) -o dice_test $(OBJECTSDICE)
set_test : $(OBJECTSSET)
	$(CC) $(CFLAGS) -o set_test $(OBJECTSSET)
link_test : $(OBJECTSLINK)
	$(CC) $(CFLAGS) -o link_test $(OBJECTSLINK)
space_test : $(OBJECTSSPACE)
	$(CC) $(CFLAGS) -o space_test $(OBJECTSSPACE)
player_test : $(OBJECTSPLAYER)
	$(CC) $(CFLAGS) -o player_test $(OBJECTSPLAYER)
object_test : $(OBJECTSOBJECT)
	$(CC) $(CFLAGS) -o object_test $(OBJECTSOBJECT)


######################################################
#Generacion de los .o $(INCPATH) $(SRCPATH) $(OBJPATH)
#######################################################
$(OBJPATH)game_loop.o: $(SRCPATH)game_loop.c $(INCPATH)graphic_engine.h
	$(CC) $(CFLAGS) -c $(SRCPATH)game_loop.c -o $(OBJPATH)game_loop.o
$(OBJPATH)command.o:$(SRCPATH)command.c $(INCPATH)command.h
	$(CC) $(CFLAGS) -c $(SRCPATH)command.c -o $(OBJPATH)command.o
$(OBJPATH)game.o: $(SRCPATH)game.c $(INCPATH)game.h $(INCPATH)command.h $(INCPATH)space.h $(INCPATH)game_reader.h $(INCPATH)player.h $(INCPATH)object.h $(INCPATH)set.h $(INCPATH)dice.h $(INCPATH)inventory.h $(INCPATH)link.h
	$(CC) $(CFLAGS) -c $(SRCPATH)game.c -o $(OBJPATH)game.o
$(OBJPATH)graphic_engine.o : $(SRCPATH)graphic_engine.c $(INCPATH)graphic_engine.h $(INCPATH)screen.h $(INCPATH)game.h $(INCPATH)dice.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)graphic_engine.c -o $(OBJPATH)graphic_engine.o
$(OBJPATH)screen.o: $(SRCPATH)screen.c $(INCPATH)screen.h
	$(CC) $(CFLAGS) -c $(SRCPATH)screen.c -o $(OBJPATH)screen.o
$(OBJPATH)space.o: $(SRCPATH)space.c $(INCPATH)space.h $(INCPATH)types.h $(INCPATH)set.h
	$(CC) $(CFLAGS) -c $(SRCPATH)space.c -o $(OBJPATH)space.o
$(OBJPATH)object.o : $(SRCPATH)object.c $(INCPATH)object.h $(INCPATH)types.h $(INCPATH)space.h
	$(CC) $(CFLAGS) -c $(SRCPATH)object.c -o $(OBJPATH)object.o
$(OBJPATH)player.o : $(SRCPATH)player.c $(INCPATH)player.h $(INCPATH)types.h $(INCPATH)space.h $(INCPATH)object.h
	$(CC) $(CFLAGS) -c $(SRCPATH)player.c -o $(OBJPATH)player.o
$(OBJPATH)game_reader.o : $(SRCPATH)game_reader.c $(INCPATH)game_reader.h $(INCPATH)space.h $(INCPATH)command.h $(INCPATH)game.h $(INCPATH)set.h
	$(CC) $(CFLAGS) -c $(SRCPATH)game_reader.c -o $(OBJPATH)game_reader.o
$(OBJPATH)set.o : $(SRCPATH)set.c $(INCPATH)set.h
	$(CC) $(CFLAGS) -c $(SRCPATH)set.c -o $(OBJPATH)set.o
$(OBJPATH)dice.o : $(SRCPATH)dice.c $(INCPATH)dice.h
	$(CC) $(CFLAGS) -c $(SRCPATH)dice.c -o $(OBJPATH)dice.o
$(OBJPATH)inventory.o :$(SRCPATH)inventory.c $(INCPATH)inventory.h
	$(CC) $(CFLAGS) -c $(SRCPATH)inventory.c -o $(OBJPATH)inventory.o
$(OBJPATH)link.o :$(SRCPATH)link.c $(INCPATH)link.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)link.c -o $(OBJPATH)link.o


#########################################################################
#.o de los test
########################################################################
$(OBJPATH)dice_test.o : $(SRCPATH)dice_test.c $(INCPATH)dice.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)dice_test.c -o $(OBJPATH)dice_test.o
$(OBJPATH)set_test.o : $(SRCPATH)set_test.c $(INCPATH)set.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)set_test.c -o $(OBJPATH)set_test.o
$(OBJPATH)link_test.o :$(SRCPATH)link_test.c $(INCPATH)link_test.h $(INCPATH)link.h $(INCPATH)types.h $(INCPATH)space.h $(INCPATH)set.h
	$(CC) $(CFLAGS) -c $(SRCPATH)link_test.c -o $(OBJPATH)link_test.o
$(OBJPATH)space_test.o: $(SRCPATH)space_test.c $(INCPATH)space_test.h $(INCPATH)space.h $(INCPATH)set.h $(INCPATH)link.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)space_test.c -o $(OBJPATH)space_test.o
$(OBJPATH)player_test.o: $(SRCPATH)player_test.c $(INCPATH)player_test.h $(INCPATH)player.h $(INCPATH)types.h $(INCPATH)object.h $(INCPATH)inventory.h $(INCPATH)set.h
	$(CC) $(CFLAGS) -c $(SRCPATH)player_test.c -o $(OBJPATH)player_test.o
$(OBJPATH)object_test.o: $(SRCPATH)object_test.c $(INCPATH)object_test.h $(INCPATH)object.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)object_test.c -o $(OBJPATH)object_test.o


############################################################################
#Distribucion de programa
############################################################################
.PHONY: valgrind
valgrind:game_loop_exe
	valgrind ./game_loop_exe data.dat

.PHONY: clear
clear:
	rm -rf $(OBJECTS_TO_CLEAN) $(EXE_CLEAN) *.dSYM

.PHONY: clearobj
clearobj:
	rm -rf $(OBJECTS_TO_CLEAN)

.PHONY: clean
clean: clear
	rm -rf $(DIST_NAME) $(DIST_NAME).tar $(EJS) #para borrar los tar generados en caso de que se quiera . (con lo que tengan dentro - ejecutables)
	#tareas que otorgan distribucion (es decir facilidad para enviarlo)

.PHONY: runvv
runvv:
	@echo ">>>>>>Running game_loop_exe with valgrind"
	valgrind --leak-check=full --track-origins=yes ./game_loop_exe data.dat

.PHONY: dist
dist:
	@echo "Preparando para enviar"
	rm -f $(DIST_NAME).tar #si existe los soobrescribe (borra antes)
	mkdir -p $(DIST_NAME) #crea un directorio donde van a estar los archivos
	cp $(HEADERS_TO_SUBMIT) $(SOURCES_TO_SUBMIT) $(SUPPORT_TO_SUBMIT) $(MEMORIES_TO_SUBMIT) $(DIST_NAME)/  #se ponen en el directorio recien creado los archivos incluyendo pdfs
	zip $(DIST_NAME).tar $(DIST_NAME)/* #Se genera el comprimido .tar con el directorio creado
	rm -rf $(DIST_NAME)
	@echo "Estado:listo para enviar"
