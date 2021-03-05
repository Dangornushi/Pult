run:
	g++ -lpthread -c src/comp.cpp
	g++ -lpthread -c src/run.cpp
	g++ -lpthread -c src/define.cpp
	g++ comp.o define.o -o bin/comp.exe
	g++ run.o define.o -o bin/run.exe
	del *.o

run.cpp:
	g++ -lpthread -c src/run.cpp
	g++ -lpthread -c src/define.cpp
	g++ run.o define.o -o bin/run.exe
	del *o

python:
	del bin/run.exe
	pyinstaller src/run.py --onefile
	del build/run

all:
	g++ -lpthread -c src/comp.cpp
	g++ -lpthread -c src/define.cpp
	g++ -lpthread -c src/run.cpp
	g++ comp.o define.o -o bin/comp.exe
	g++ run.o define.o -o bin/run.exe
	g++ -o bin/pult.exe src/pult.cpp
	del *.o
