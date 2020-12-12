#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>

#include "taxi.h"
#include "genera_mappa.h"

int main(int argc, char * argv[]){ 
	int SO_HOLES = atoi(argv[3]), SO_SOURCES = atoi(argv[2]), SO_TIMENSEC_MIN = atoi(argv[7]), 
	    SO_TIMENSEC_MAX = atoi(argv[8]), SO_CAP_MIN = atoi(argv[5]), SO_CAP_MAX = atoi(argv[6]);
	int mid, i, j;
	struct mappa * mappa;	

	mid = shmget(IPC_PRIVATE, sizeof(* mappa), S_IRUSR | S_IWUSR);
	TEST_ERROR;
	/*printf("%d",mid);*/
	mappa = shmat(mid, NULL, 0);  
	TEST_ERROR;
	
	inizializza_mappa(mappa);
	genera_holes(mappa, SO_HOLES);
	genera_sources(mappa, SO_SOURCES);
	definisci_tempi(mappa, SO_TIMENSEC_MIN, SO_TIMENSEC_MAX);
	definisci_capienza(mappa, SO_CAP_MIN, SO_CAP_MAX);
	stampa_mappa(mappa);
	/*for(i=0;i<SO_HEIGHT;i++){
		for(j=0;j<SO_WIDTH;j++){
			printf("%d %d %ld %d\n",i,j,mappa->mappa[i][j].tempo_attr,mappa->mappa[i][j].capacita);
		}
	}*/
	shmctl(mid, 0, IPC_RMID);
	exit(EXIT_SUCCESS);
}
