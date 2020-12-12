#flag per la compilazione
CFLAGS = -std=c89 -pedantic

SO_TAXI = 1
SO_SOURCES = 10
SO_HOLES = 7
SO_TOP_CELLS = 4
SO_CAP_MIN = 5
SO_CAP_MAX = 6
SO_TIMENSEC_MIN = 7
SO_TIMENSEC_MAX = 8
SO_TIMEOUT = 9
SO_DURATION = 10

taxigame: master.o genera_mappa.o
	gcc $(CFLAGS) -o taxigame *.o 

master.o: master.c taxi.h
	gcc $(CFLAGS) -c master.c

genera_mappa.o:	genera_mappa.c genera_mappa.h
	gcc $(CFLAGS) -c genera_mappa.c
	
clean:
	rm -f *.o taxigame *~
	
run:	
	./taxigame $(SO_TAXI) $(SO_SOURCES) $(SO_HOLES) $(SO_TOP_CELLS) $(SO_CAP_MIN) $(SO_CAP_MAX) $(SO_TIMENSEC_MIN) $(SO_TIMENSEC_MAX) $(SO_TIMEOUT) $(SO_DURATION)
