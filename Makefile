TARGET   	:= opengl

CMP      	:= clang
CINCS	 	:= -I. -I/usr/local/include
LINCS    	:= -I. -L/usr/X11R6/lib -L/usr/local/lib -lGL -lGLEW -lglfw 
DBFLAGS  	:= -g3 -O0 -DTESTING
STFLAGS   	:= -std=c++17 -Wall -Wextra -Werror -Wpedantic
CFLAGS   	:= ${CINCS} ${DBFLAGS} ${STFLAGS} 
LFLAGS   	:= ${LINCS} ${DBFLAGS} ${STFLAGS} 

SRCS		:= main.cpp 
OBJS  		:= ${SRCS:.cpp=.o}

${TARGET}: ${OBJS}
	@${CMP} ${OBJS} ${LFLAGS} -o ${TARGET}

.cpp.o:
	@${CMP} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJS} ${TARGET} *.core

run: ${TARGET}
	@./${TARGET}

all:
	@clear; ${MAKE} clean; ${MAKE}; ${MAKE} run;

commit:
	@git add .
	@git commit -m "AUTO COMMIT: `date +'%Y-%m-%d %H:%M:%S'`"
	@git push origin main

install: ${TARGET}
	@rm /usr/local/bin/${TARGET}
	@cp ${TARGET} /usr/local/bin/${TARGET}

MAKEFLAGS += --no-print-directory
.PHONY: clean run all commit install


