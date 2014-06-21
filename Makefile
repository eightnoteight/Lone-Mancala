#Octadic-Wilderness MakeFile
#Licensed under GPL v2.0
#see the LICENSE for license details

SRC = lone-mancala.c
CC = gcc
BIN 	= lone-mancala
INSTALLPATH = /usr/local/bin/
CFLAGS = -Wall

Octadic-Wilderness : ${SRC}

	@echo "build ${SRC}"
	@echo "CC ${CFLAGS} ${SRC}"
	@${CC} ${CFLAGS} ${SRC} -o ${BIN} -lncurses -lm

install : ${BIN}

	@echo "installing binary file to ${INSTALLPATH}${BIN}"
	@cp ${BIN} ${INSTALLPATH}
	@chmod 755 ${INSTALLPATH}${BIN}
	@echo "installed. Happys Wilderness"

uninstall : 

	@echo "uninstalling binary file (${INSTALLPATH}${BIN})"
	@rm -f ${INSTALLPATH}${BIN}
	@echo "uninstalled :'(."

clean :

	@echo "cleaning"
	@echo "rm ${BIN}"
	@rm ${BIN}
	@echo "cleaned."