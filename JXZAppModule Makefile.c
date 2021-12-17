EXE = PrintProcess
OBJ = PrintProcess.o
CFLAGS += -I.
all: $(EXE)
$(EXE): $(OBJ)
	$(CC) -o PrintProcess PrintProcess.c -lpthread

romfs:
	$(ROMFSINST) PrintProcess /bin/$(EXE)
	