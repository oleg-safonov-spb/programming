# Настройки компилятора
CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g
LIBS = -lm

# Имена файлов (меняются только здесь)
TARGET = serialize_app
OBJS = main.o file_io.o

# Главная цель
all: $(TARGET)

# Линковка: сборка исполняемого файла из объектных
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Компиляция: превращение .c файлов в объектные .o
# Символ % — это шаблон, который подходит к любому имени файла
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка проекта от временных файлов
clean:
	rm -f *.o $(TARGET) *.bin

.PHONY: all clean
