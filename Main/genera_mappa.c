#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h> 
#include "genera_mappa.h"
#include "taxi.h"

void inizializza_mappa(struct mappa * map){
	int i, j;
	 
	for(i=0; i<SO_HEIGHT;i++){
		for(j=0;j<SO_WIDTH;j++){
			map->mappa[i][j].type = NOT_HOLES;
		}
	}
}

void genera_holes(struct mappa * map, int SO_HOLES){
	int i, j, k=0,riga=0, col=0, cond;
	
	srand(getpid());
	while(k<SO_HOLES){
		do{
			cond=0;
			riga = rand()%SO_HEIGHT;
			col = rand()%SO_WIDTH;
			
			if(map->mappa[riga][col].type==NOT_HOLES){
				for(i=riga-1;i<=riga+1 && !cond;i++){
					for(j=col-1;j<=col+1 && !cond;j++){
						if(i>=0 && i<SO_HEIGHT && j>=0 && j<SO_WIDTH && map->mappa[i][j].type==HOLES)
							cond=1;
					}
				}
				if(!cond) 
					map->mappa[riga][col].type = HOLES;
			}else
				cond = 1;
			
		}while(cond==1);
		
		k++;
	}
}

void genera_sources(struct mappa * map, int SO_SOURCES){
	int i, j, k=0,riga=0, col=0, cond;
	
	srand(getpid());
	while(k<SO_SOURCES){
		do{
			cond=0;
			riga = rand()%SO_HEIGHT;
			col = rand()%SO_WIDTH;
			
			if(map->mappa[riga][col].type==NOT_HOLES)
				map->mappa[riga][col].type = SOURCES;
			else 
				cond=1;
			
		}while(cond==1);
		
		k++;
	}
}

void definisci_tempi(struct mappa * map, int SO_TIMENSEC_MIN, int SO_TIMENSEC_MAX){
	int i, j;
	
	for(i=0;i<SO_HEIGHT;i++){
		for(j=0;j<SO_WIDTH;j++){
			if(map->mappa[i][j].type != HOLES)
				map->mappa[i][j].tempo_attr = (rand() % (SO_TIMENSEC_MAX - SO_TIMENSEC_MIN + 1)) + SO_TIMENSEC_MIN;
			else
				map->mappa[i][j].tempo_attr = 0;
		}
	}
}

void definisci_capienza(struct mappa * map, int SO_CAP_MIN, int SO_CAP_MAX){
	int i, j;
	
	for(i=0;i<SO_HEIGHT;i++){
		for(j=0;j<SO_WIDTH;j++){
			if(map->mappa[i][j].type != HOLES)
				map->mappa[i][j].capacita = (rand() % (SO_CAP_MAX - SO_CAP_MIN + 1)) + SO_CAP_MIN;
			else
				map->mappa[i][j].capacita = 0;
		}
	}
}

void stampa_mappa(struct mappa * map){
	int i, j;
	
	for(j=0; j<SO_WIDTH; j++)
	{
	    printf("----");
	}
	printf("-\n");

    	for(i=0; i<SO_HEIGHT; i++)
    	{
    		for(j=0; j<SO_WIDTH; j++)
		{
				if(map->mappa[i][j].type == HOLES)
					printf("| * ");
				else if(map->mappa[i][j].type == SOURCES)
					printf("| S ");
				else 
					printf("|   ");
		}
  		printf("|\n");
  		if(i != SO_HEIGHT-1)
  		{
    			for(j=0; j<SO_WIDTH; j++)
			{
		    		printf("|---");
			}
  			printf("|\n");
		}		
	}	
	
	for(j=0; j<SO_WIDTH; j++)
	{
	    printf("----");
	}
	printf("-\n");
}
