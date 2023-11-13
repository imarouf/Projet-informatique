# makefile du projet

main: main.o gestionClient/gestionClient.o gestionJet/gestionJet.o gestionLocation/gestionLocation.o menu/menu.o
	gcc main.o gestionClient/gestionClient.o gestionJet/gestionJet.o gestionLocation/gestionLocation.o menu/menu.o -o main -Wall

main.o: main.c gestionClient/gestionClient.h gestionJet/gestionJet.h gestionLocation/gestionLocation.h menu/menu.h
	gcc -c main.c -Wall

gestionClient.o: gestionClient/gestionClient.c gestionClient/gestionClient.h
	gcc -c gestionClient/gestionClient.c -Wall

gestionJet.o: gestionJet/gestionJet.c gestionJet/gestionJet.h
	gcc -c gestionJet/gestionJet.c -Wall

gestionLocation.o: gestionLocation.c gestionLocation.h
	gcc -c gestionLocation/gestionLocation.c -Wall

menu.o: menu.c menu.h gestionClient/gestionClient.h
	gcc -c menu/menu.c -Wall
