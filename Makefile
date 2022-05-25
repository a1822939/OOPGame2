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



test-heal: unit_Test2-Heal.cpp heal.cpp Heal.h player.cpp character.cpp player.h character.h
	g++ unit_Test2-Heal.cpp heal.cpp player.cpp character.cpp -std=c++14 -o test-heal

test-attack: unit_Test1-Attack.cpp attack.cpp Attack.h player.cpp character.cpp player.h character.h
	g++ unit_Test1-Attack.cpp attack.cpp player.cpp character.cpp -std=c++14 -o test-attack

test: test-heal test-attack
	./test-heal
	./test-attack


clean:
	rm *.o output

run:
	g++ character.cpp player.cpp display.cpp game.cpp main.cpp attack.cpp heal.cpp