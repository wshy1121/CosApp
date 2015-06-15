############################################################################
#
# Makefile for DH-DVR_ARM2510
#
# arm-uclinux-elf-gcc version 3.4.3
#
############################################################################
#CROSS  = sh4-linux-uclibc-
#CROSS  = arm-none-linux-gnueabi-
#CROSS  = arm-linux-gnueabihf-
CXXFLAGS += -std=c++0x -lpthread -I ../CrossPlat -I../TraceWorker -I../NetApp -I../LogCore -I.

LIBS += -L./lib  -ldl -lNetApp -lLogCore -lEncrypt -lCrossPlat -lTraceWorker 

CPP	=	@echo " g++ $@"; $(CROSS)g++
CC	=	@echo " gcc $@"; $(CROSS)gcc
LD	=	@echo " ld  $@"; $(CROSS)ld
AR  = @echo " ar  $@"; $(CROSS)ar
STRIP	=	@echo " strip $@"; $(CROSS)strip
RANLIB = @echo " ranlib  $@"; $(CROSS)ranlib

CP	= cp -rf
RM	= rm

AFLAGS	+= -r   

LIB_OBJS += main.o Sqlite/CppSQLite3.o Sqlite/SqliteManager.o Sqlite/sqlite3.o 

LIB_TARGET=logManager

all	:	$(LIB_TARGET)

$(LIB_TARGET): $(LIB_OBJS)
	$(CPP) -g -o $(LIB_TARGET) $(LIB_OBJS) $(LIBS) $(CXXFLAGS)
	
.c.o:
	$(CC) -c $(CFLAGS) $^ -o $@

.cpp.o:
	$(CPP) -c -Wall $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(LIB_OBJS) deamon 

install:
	cp $(LIB_TARGET) ../Libs/libwrapmalloc.a 


	
