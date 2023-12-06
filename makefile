# makefile du projet

main: main.o gestionClient/gestionClient.o gestionJet/gestionJet.o gestionLocation/gestionLocation.o menu/menu.o
	gcc main.o gestionClient/gestionClient.o gestionJet/gestionJet.o gestionLocation/gestionLocation.o menu/menu.o -o main -Wall

main.o: main.c gestionClient/gestionClient.h gestionJet/gestionJet.h gestionLocation/gestionLocation.h menu/menu.h
	gcc main.c -c -Wall

gestionClient.o: gestionClient/gestionClient.c gestionClient/gestionClient.h
	gcc gestionClient/gestionClient.c -c -Wall

gestionJet.o: gestionJet/gestionJet.c gestionJet/gestionJet.h
	gcc gestionJet/gestionJet.c -c -Wall

gestionLocation.o: gestionLocation/gestionLocation.c gestionLocation/gestionLocation.h
	gcc gestionLocation/gestionLocation.c -c -Wall

menu.o: menu/menu.c menu/menu.h gestionClient/gestionClient.h
	gcc menu/menu.c -c -Wall
