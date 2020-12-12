#define SO_HEIGHT 10	/*altezza*/
#define SO_WIDTH 20	/*larghezza*/
#define NOT_HOLES 0
#define HOLES 1
#define SOURCES 2

typedef struct{
	int type;
	long tempo_attr;
	int capacita;
}point;

struct mappa{
	point mappa[SO_HEIGHT][SO_WIDTH];
};

void inizializza_mappa(struct mappa *);
void genera_holes(struct mappa *, int);
void genera_sources(struct mappa *, int);
void definisci_tempi(struct mappa *, int, int);
void definisci_capienza(struct mappa *, int, int);
void stampa_mappa(struct mappa *);
