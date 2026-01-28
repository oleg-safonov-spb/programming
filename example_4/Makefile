# Параметры сборки
CC     = gcc
CFLAGS = -Wall -Werror -std=c17 -g
LIBS   = -lm

# Имена файлов (меняются только здесь)
TARGET      = employee_app
TEST_TARGET = test_suite
COMMON_OBJS = employee.o

# Сборка
all: $(TARGET)

$(TARGET): main.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Тесты
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): tests.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Компиляция
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)

.PHONY: all test clean
