# Replace with location of SFML on your machine.
SFML = C:/Libraries/C++/SFML-2.5.1

OBJECTS = LifeBelow.o

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

LifeBelow.o : src/LifeBelow.cpp
	g++ -c -DSFML_STATIC $(INCLUDE) src/LifeBelow.cpp

clean :
	del $(PROGRAM_NAME) $(OBJECTS)