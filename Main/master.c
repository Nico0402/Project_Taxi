#include "master.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>

int SO_HOLES;

int main(int argc, char * argv[]){
	point mappa[SO_HEIGHT][SO_WIDTH];
	SO_HOLES = atoi(argv[3]);
	
	inizializza_mappa(mappa);
	stampa_mappa(mappa);
	exit(EXIT_SUCCESS);
}

void inizializza_mappa(point mappa[SO_HEIGHT][SO_WIDTH]){
	int i, j, k,riga=0, col=0, cond;
	
	for(i=0; i<SO_HEIGHT;i++){
		for(j=0;j<SO_WIDTH;j++){
			mappa[i][j].val = NOT_HOLES;
		}
	}
	 
	k=0;
	srand(getpid());
	while(k<SO_HOLES){
		do{
			cond=0;
			riga = rand()%SO_HEIGHT;
			col = rand()%SO_WIDTH;
			
			if(mappa[riga][col].val==NOT_HOLES){
				for(i=riga-1;i<=riga+1 && !cond;i++){
					for(j=col-1;j<=col+1 && !cond;j++){
						if(i>=0 && i<=SO_HEIGHT && j>=0 && j<=SO_WIDTH && mappa[i][j].val==HOLES)
							cond=1;
					}
				}
				if(!cond)
					mappa[riga][col].val = HOLES;
			}else
				cond = 1;
			
		}while(cond==1);
		
		k++;
	}
}

void stampa_mappa(point mappa[SO_HEIGHT][SO_WIDTH]){
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
				if(mappa[i][j].val == HOLES)
					printf("| * ");
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
