# Replace with location of SFML on your machine.
SFML = C:/Libraries/C++/SFML-2.5.1

OBJECTS = LifeBelow.o Game.o Window.o DevDisplay.o CursorManager.o World.o Level.o Cave.o TileMap.o Tile.o

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

Game.o : src/headers/Game.h src/Game.cpp src/headers/Window.h src/headers/Global.h src/headers/World.h src/headers/CursorManager.h src/headers/DevDisplay.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/Game.cpp

Window.o : src/headers/Window.h src/Window.cpp src/headers/Global.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/Window.cpp

DevDisplay.o : src/headers/DevDisplay.h src/DevDisplay.cpp src/headers/Global.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/DevDisplay.cpp

CursorManager.o : src/headers/CursorManager.h src/CursorManager.cpp src/headers/Direction.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/CursorManager.cpp

World.o : src/headers/World.h src/World.cpp src/headers/Global.h src/headers/CursorManager.h src/headers/Direction.h src/headers/Level.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/World.cpp

Level.o : src/headers/Level.h src/Level.cpp src/headers/Cave.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/Level.cpp

Cave.o : src/headers/Cave.h src/Cave.cpp src/headers/TileMap.h src/headers/Tile.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/Cave.cpp

TileMap.o : src/headers/TileMap.h src/TileMap.cpp src/headers/Tile.h
	g++ -c -DSFML_STATIC $(INCLUDE) src/TileMap.cpp

Tile.o : src/headers/Tile.h src/Tile.cpp
	g++ -c -DSFML_STATIC $(INCLUDE) src/Tile.cpp

clean :
	del $(PROGRAM_NAME) $(OBJECTS)