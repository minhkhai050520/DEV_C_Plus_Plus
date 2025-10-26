objects = main.o

main: $(objects)
	g++ -g -o main $(objects)

main.o: main.cpp class_screen.h class_window_mgr.h
	g++ -g -c main.cpp -o main.o

.PHONY: clean
clean:
	del main.exe $(objects)