CFLAGS = -Wall -Werror -Wextra -std=c11
OS = $(shell uname)

ifeq ($(OS), Linux)
	LDLIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	LDLIBS = -lcheck -lm
endif

all : style clean install

test : tests.o s21_smart_calc.a
	gcc $(CFLAGS) tests.o s21_smart_calc.a -lcheck -lm -lpthread -lsubunit  -o test
	./test

tests.o : tests.c
	gcc $(CFLAGS) -c tests.c -o tests.o

s21_smart_calc.o: s21_smart_calc.c s21_smart_calc.h
	gcc $(CFLAGS) -c s21_smart_calc.c -o s21_smart_calc.o

s21_smart_calc.a: s21_smart_calc.o
	ar rc s21_smart_calc.a s21_smart_calc.o
	ranlib s21_smart_calc.a

install:
	mkdir -p ../build
	cd view && qmake && make && make clean && rm -rf Makefile && mv SmartCalc ../../build/

uninstall:
	rm -rf ../build/SmartCalc

dist:
	mkdir -p ../dist
	cp -R ../build/SmartCalc ../dist
	cd ../dist && tar cvzf SmartCalc_v1.0.tgz *
	cd ../dist && rm -rf SmartCalc

gcov_flag:
	$(eval CFLAGS += --coverage)

gcov_report: clean gcov_flag test
	mkdir -p gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov
	open gcov/index.html
	rm -rf *.gcno *.gcda *.gcov

style:
	clang-format -n -style=Google *.c *.h
	clang-format -i -style=Google *.c *.h

clean :
	rm -rf *.o test *.gc* *.a *.info

rebuild: clean all
