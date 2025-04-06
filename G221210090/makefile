Tum: de ba ca


de:
	gcc -g -c -I "./include" ./src/main.c -o ./lib/main.o
	gcc -g -c -I "./include" ./src/Bitki.c -o ./lib/Bitki.o
	gcc -g -c -I "./include" ./src/Bocek.c -o ./lib/Bocek.o
	gcc -g -c -I "./include" ./src/Canli.c -o ./lib/Canli.o
	gcc -g -c -I "./include" ./src/Habitat.c -o ./lib/Habitat.o
	gcc -g -c -I "./include" ./src/Pire.c -o ./lib/Pire.o
	gcc -g -c -I "./include" ./src/Sinek.c -o ./lib/Sinek.o
	gcc -g -c -I "./include" ./src/CanliX.c -o ./lib/CanliX.o

ba:
	gcc -g ./lib/Bitki.o ./lib/Bocek.o ./lib/Canli.o ./lib/Habitat.o ./lib/Pire.o ./lib/Sinek.o ./lib/CanliX.o ./lib/main.o -o ./bin/program

ca:
	./bin/program