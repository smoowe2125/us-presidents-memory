memgame : src/game.cpp src/game.hpp src/main.cpp src/gameobject.hpp src/gameobject.cpp src/spriteman.hpp src/spriteman.cpp
	g++ -L/usr/lib -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -I/home/jaciu/Downloads/Programming\ Workspace/C++/MemoryGame/src/ ./src/*.cpp -o memgame
	g++ -L/usr/lib -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -I/home/jaciu/Downloads/Programming\ Workspace/C++/MemoryGame/src/ ./src/*.cpp -o memgame.exe