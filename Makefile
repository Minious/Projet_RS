CC = gcc
CFLAGS = -g -Wall
SRCDIR = src
INCDIR = include
BUILDDIR = build
PGM = ptar
INC = -I $(INCDIR)
OBJDIR = obj
TARGET = bin/$(PGM)
OBJ = $(wildcard $(OBJDIR)/*.o)

$(shell mkdir -p $(OBJDIR))
$(shell mkdir -p bin)

all: main run

# Generic task
%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $(OBJDIR)/$@


main: utils.o warehouse.o network.o generator.o parser.o djikstra.o main.o 
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)


clean:
	rm -rf bin $(TARGET) $(OBJDIR)


valgrind: main
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -v ./bin/main


run:
	@echo -e "\n## Running ./$(TARGET)...\n"
	@./$(TARGET)
