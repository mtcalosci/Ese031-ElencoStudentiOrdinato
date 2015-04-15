#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char cognome [MAX_STRLEN];
    char nome [MAX_STRLEN];
    int eta;
    char classe[MAX_STRLEN];
};

// Definisci studente come struct s_studente
struct s_studente studente[N];

// Dichiara il prototipo della funzione di ordinamento
void Ordina_Record(struct s_studente v[]);

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati
    for(i = 0; i < N; i++) {
        printf("Inserisci il nome dello studente %d: ", i);
        scanf("%s", studente[i].nome);
        printf("Inserisci il cognome dello studente %d: ", i);
        scanf("%s", studente[i].cognome);
        printf("Inserisci la classe dello studente %d: ", i);
        scanf("%s", studente[i].classe);
        printf("Inserisci l'eta' dello studente %d: ", i);
        scanf("%d", &(studente[i].eta));
        
    }
    
    // Ordina l'elenco (con funzione)
    Ordina_Record(studente);
    
    // Codice per la stampa dei dati (uno studente per riga)
    for(i = 0; i < N; i++) {
    printf("%s; %s; %d; %s;", studente[i].nome, studente[i].cognome, studente[i].eta, studente[i].classe);
    printf("\n");
    }
    return (EXIT_SUCCESS);
}

// Definisci la funzione di ordinamento
void Ordina_Record(struct s_studente v[]) {
    struct s_studente aiuto;
    int x,i,pos_min;
    
    for(x = 0; x < (N - 1); x++) {        
    pos_min = x;
      for(i = x + 1; i < N; i++) {          
            if(strcmp(v[i].cognome,v[pos_min].cognome) < 0) {
            pos_min = i;
            }
      
                    if(x != pos_min) {           
                    aiuto = v[x];
                    v[x] = v[pos_min];
                    v[pos_min] = aiuto;
                    }
        }
    }
}