git:
	git add -A 
	git commit -m "function working"
	git push
	git pull

output: main.o attack.o character.o display.o game.o heal.o player.o
	g++ main.o attack.o character.o display.o game.o heal.o player.o -o output
main.o: main.cpp
	g++ -c main.cpp
attack.o: attack.cpp attack.h move.h
	g++ -c attack.cpp
character.o: character.cpp character.h
	g++ -c character.cpp
display.o: display.cpp display.h
	g++ -c display.cpp
game.o: game.cpp game.h
	g++ -c game.cpp
heal.o: heal.cpp heal.h move.h
	g++ -c heal.cpp
player.o: player.cpp player.h
	g++ -c player.cpp

test-player: player.o test.cpp
	g++ test.cpp player.o

test-heal: heal.o .cpp
	g++ heal.o test1.cpp

test: 
	test-player
	test-heal

clean:
	rm *.o output

run:
	g++ character.cpp player.cpp display.cpp game.cpp main.cpp attack.cpp heal.cpp