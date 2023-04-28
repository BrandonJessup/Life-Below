# Replace with location of SFML on your machine.
SFML = C:/Libraries/C++/SFML-2.5.1

OBJECTS = LifeBelow.o Game.o Window.o

PROGRAM_NAME = "Life Below.exe"

INCLUDE = -I "$(SFML)/include"

LIBRARIES += -L "$(SFML)/lib"
LIBRARIES += -lsfml-network-s
LIBRARIES += -lsfml-window-s
LIBRARIES += -lsfml-graphics-s
LIBRARIES += -lsfml-system-s
LIBRARIES += -lopengl32
LIBRARIES += -lwinmm
LIBRARIES += -lgdi32
LIBRARIES += -lws2_32
LIBRARIES += -lfreetype
LIBRARIES += -static-libgcc
LIBRARIES += -static-libstdc++
LIBRARIES += -static -lwinpthread

program : $(OBJECTS)
	g++ -o $(PROGRAM_NAME) $(INCLUDE) $(OBJECTS) $(LIBRARIES)

LifeBelow.o : src/LifeBelow.cpp src/headers/Game.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/LifeBelow.cpp

Game.o : src/headers/Game.h src/Game.cpp src/headers/Window.h src/headers/Global.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/Game.cpp

Window.o : src/headers/Window.h src/Window.cpp src/headers/Global.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/Window.cpp

clean :
	del $(PROGRAM_NAME) $(OBJECTS)