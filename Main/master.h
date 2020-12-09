#define SO_WIDTH 15	/*larghezza*/
#define SO_HEIGHT 15	/*altezza*/
#define NOT_HOLES 0
#define HOLES 1
#define SOURCES 2

#define TEST_ERROR    if (errno) {dprintf(STDERR_FILENO,		\
					  "%s:%d: PID=%5d: Error %d (%s)\n", \
					  __FILE__,			\
					  __LINE__,			\
					  getpid(),			\
					  errno,			\
					  strerror(errno));}
					  
typedef struct{
	int type;
	long time_min;
	long time_max;
	int cap_min;
	int cap_max;
}point;

void inizializza_mappa(point mappa[SO_HEIGHT][SO_WIDTH]);
void genera_holes(point mappa[SO_HEIGHT][SO_WIDTH]);
void genera_sources(point mappa[SO_HEIGHT][SO_WIDTH]);
void stampa_mappa(point mappa[SO_HEIGHT][SO_WIDTH]);
