#define SO_WIDTH 6	/*larghezza*/
#define SO_HEIGHT 6	/*altezza*/
#define HOLES 1
#define NOT_HOLES 0
#define TEST_ERROR    if (errno) {dprintf(STDERR_FILENO,		\
					  "%s:%d: PID=%5d: Error %d (%s)\n", \
					  __FILE__,			\
					  __LINE__,			\
					  getpid(),			\
					  errno,			\
					  strerror(errno));}
					  
typedef struct{
	int val;
}point;

void stampa_mappa(point mappa[SO_HEIGHT][SO_WIDTH]);
void inizializza_mappa(point mappa[SO_HEIGHT][SO_WIDTH]);
