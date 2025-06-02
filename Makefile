# Target
TARGET=				opengl

# Compilers
CC=					clang
CXX=				clang++

# Directories
INCDIRS=			-I. -I./include -I/usr/X11R6/include -I/usr/local/include
LIBDIRS=			-L/usr/X11R6/lib -L/usr/local/lib

# Libraries
LDLIBS=				-lGL -lGLEW -lglfw

# Flags
DEBUG=				-g3 -O0 -DTESTING
C_WARN=				-Wall -Wextra -Werror -Wpedantic
C_STD=				-std=c99
CXX_STD=			-std=c++17

# Combined flags
CFLAGS=				${INCDIRS} ${DEBUG} ${C_WARN} ${C_STD}
CXXFLAGS=			${INCDIRS} ${DEBUG} ${C_WARN} ${CXX_STD}
LDFLAGS=			${LIBDIRS} ${DEBUG} ${LDLIBS}

# Sources and Objects
CSRCS=				src/glad.c
CXXSRCS=			main.cpp
COBJS=				${CSRCS:.c=.o}
CXXOBJS=			${CXXSRCS:.cpp=.o}
OBJS=				${COBJS} ${CXXOBJS}

# Default target
all: ${TARGET}
	echo "all"

${TARGET}: ${OBJS}
	echo "target"
	${CXX} ${OBJS} ${LDFLAGS} -o ${TARGET}

.SUFFIXES: .c .cpp .o

.c.o:
	echo ".c.o"
	${CC} ${CFLAGS} -c $< -o $@

.cpp.o:
	echo ".cpp.o"
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	echo "clean"
	rm -f ${OBJS} ${TARGET} *.core

run: ${TARGET}
	echo "run"
	./${TARGET}

install: ${TARGET}
	echo "install"
	rm -f /usr/local/bin/${TARGET}
	cp ${TARGET} /usr/local/bin/${TARGET}

commit:
	echo "commit"
	git add .
	git commit -m "AUTO COMMIT: `date +'%Y-%m-%d %H:%M:%S'`"
	git push origin main

.PHONY: all clean run install commit

