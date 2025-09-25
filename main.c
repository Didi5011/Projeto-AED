#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1-Lisboa, 2-Evora, 3-Beja, 4-Faro, 5-Santarem, 6-Guarda, 7-Madrid, 8-Aveiro, 9-Porto, 10-Braga,
11-Chaves, 12-Dili
*/

#define NONE 0
#define LISBOA 1
#define EVORA 2
#define BEJA 3
#define FARO 4
#define SANTAREM 5
#define GUARDA 6
#define MADRID 7
#define AVEIRO 8
#define PORTO 9
#define BRAGA 10
#define CHAVES 11
#define DILI 12


/*Struct para guardar o ficheiro map*/
struct map {
    int origem;
    int destino;
    char trans[20];
    int tempo;
    int custo;
    int inicio;
    int fim;
    int period;
};

/*Struct para guardar o ficheiro quest*/
struct quest {
    char task[64];
    int torigem;
    int tdestino;
    int thora;
};
        /*Função da task1*/
        int task01(struct map *lista, int n, int origem, int destino) {
            int count = 0;
            for(int i = 0; i < n; i++){
                if ((lista[i].origem == origem && lista[i].destino == destino) || (lista[i].origem == destino && lista[i].destino == origem)) {
            count++;
                }
            }
            return count;
        }

        /*Função da task2*/
        int task02(struct map *lista, int n, int origem, int destino){
            int min = -1;
            for(int i = 0; i < n; i++) {
                if ((lista[i].origem == origem && lista[i].destino == destino) || (lista[i].origem == destino && lista[i].destino == origem)) {
                    if (min == -1 || lista[i].tempo < min) {
                        min = lista[i].tempo;
                    }
                }
            }
            return min;
        }

        /*Função da task3*/
        int task03(struct map *lista, int n, int origem, int destino){
            int preco = -1;
            for(int i = 0; i < n; i++){
                if((lista[i].origem == origem && lista[i].destino == destino) || (lista[i].origem == destino && lista[i].destino == origem)){
                    if (preco == -1 || lista[i].custo < preco ){
                        preco = lista[i].custo;
                    }
                }
            }
            return preco;
        }
        /*Função da task4*/
        int task04(struct map *lista, int n, int origem, int destino, int partida){
            int cedo = -1;
            for(int i = 0; i < n; i++){
                if((lista[i].origem == origem && lista[i].destino == destino) || (lista[i].origem == destino && lista[i].destino == origem)){
                    int inicio = lista[i].inicio;
            if (inicio >= partida) {
                if (cedo == -1 || inicio < cedo) {
                    cedo = inicio;
                }
            }
        }
    }
    return cedo;

    /*Funcao da task5*/
    int task05(struct map *lista, int n, int origem, int destino) {
      int intermedias[20];            /*Lista de viagens que partem da origem*/
      int n_intermedias = 0;

    /* Procura todas as viagens que incluam a origem de que estamos a procura*/
    for (int i = 0; i < n; i++) {
        if (lista[i].origem == origem) {
            intermedias[n_intermedias] = lista[i].destino;
            n_intermedias++;
        } else if (lista[i].destino == origem) {
            intermedias[n_intermedias] = lista[i].origem;
            n_intermedias++;
        }
    }
  }
}
    /* Para cada cidade intermedia*/
    for (int i = 0; i < n_intermedias; i++) {
        
        /*Procura se ha alguma ligacao da via intermedia com o destino de que estamos a procura*/
        for (int j = 0; j < n; j++) {
            if (lista[i].origem == intermedias[i] && lista[i].destino == destino ||
                lista[i].destino == intermedias[i] && lista[i].origem == destino) {
                return 1;
            }
        }
    }

    return -1;    


int main () {

    /*abrir o ficheiro mapa em read mode em fptr*/
    FILE *fptr; 
    fptr = fopen("Enunciado_mapa.map", "r");

    /*ler o numero de cidades e ligacões*/
    int cidades, ligacoes;
    fscanf(fptr, "%d %d", &cidades, &ligacoes);

    struct map lista[100]; /*Criar uma variável struct de map chamada lista*/
    int n = 0;

    while (fscanf(fptr, "%d %d %s %d %d %d %d %d", 
        &lista[n].origem,
        &lista[n].destino,
        lista[n].trans,
        &lista[n].tempo,
        &lista[n].custo,
        &lista[n].inicio,
        &lista[n].fim,
        &lista[n].period) == 8) {
            n++;
        }
    
    
        
    /*abrir o ficheiro quest em read mode em fptr2*/
    FILE *fptr2;
    fptr2 = fopen("Enunciado_tasks_16.quests", "r");
    if (!fptr2) {
        perror("Erro ao abrir Enunciado_tasks_16.quests");
        return 1;
    }

    struct quest lista2[100]; /*Criar uma variável struct de quest chamada lista2*/
    int m = 0;

    while (1) {
    int r = fscanf(fptr2, "%63s %d %d %d",
                   lista2[m].task,
                   &lista2[m].torigem,
                   &lista2[m].tdestino,
                   &lista2[m].thora);
    if (r == EOF) break;
    if (r == 3) {
        lista2[m].thora = 0; /* thora não fornecida na linha */
        m++;
    } else if (r == 4) {
        m++;
    } else {
        /* linha mal-formada: consumir até fim da linha e ignorar */
        int c;
        while ((c = fgetc(fptr2)) != '\n' && c != EOF) { }
    }
    /*evitar overflow do array */
    if (m >= 100) break;
}


    FILE *fptr3 = fopen("Enunciado_tasks_16.results", "w");
    if (fptr3 == NULL) {
        perror("Erro a criar Enunciado_tasks_16.results");
        return 1;
}

    for (int i = 0; i < m; i++) {
    if (strcmp(lista2[i].task, "Task1") == 0) {
        int viagens = task01(lista, n, lista2[i].torigem, lista2[i].tdestino);
        fprintf(fptr3, "%s %d %d -> %d viagens directas\n",
                lista2[i].task,
                lista2[i].torigem,
                lista2[i].tdestino,
                viagens);
    }

    else if (strcmp(lista2[i].task, "Task2") == 0) {
        int menor = task02(lista, n, lista2[i].torigem, lista2[i].tdestino);
        if (menor == -1) {
            fprintf(fptr3, "%s %d %d -> nenhuma ligação direta\n",
                    lista2[i].task,
                    lista2[i].torigem,
                    lista2[i].tdestino);
        } else {
            fprintf(fptr3, "%s %d %d -> menor tempo = %d\n",
                    lista2[i].task,
                    lista2[i].torigem,
                    lista2[i].tdestino,
                    menor);
        }
    }

    else if (strcmp(lista2[i].task, "Task3") == 0) {
        int menor_custo = task03(lista, n, lista2[i].torigem, lista2[i].tdestino);
        if (menor_custo == -1) {
            fprintf(fptr3, "%s %d %d -> nenhuma ligação direta\n",
                    lista2[i].task,
                    lista2[i].torigem,
                    lista2[i].tdestino);
        } else {
            fprintf(fptr3, "%s %d %d -> menor custo = %d\n",
                    lista2[i].task,
                    lista2[i].torigem,
                    lista2[i].tdestino,
                    menor_custo);
        }
    }

    else if (strcmp(lista2[i].task, "Task4") == 0) {
        int menor_hora = task04(lista, n, lista2[i].torigem, lista2[i].tdestino, lista2[i].thora);
        if (menor_hora == -1) {
            fprintf(fptr3, "%s %d %d %d -> nenhuma ligação direta\n",
                    lista2[i].task,
                    lista2[i].torigem,
                    lista2[i].tdestino,
                    lista2[i].thora);
        } else {
            fprintf(fptr3, "%s %d %d %d -> hora mais cedo = %d\n",
                    lista2[i].task,
                    lista2[i].torigem,
                    lista2[i].tdestino,
                    lista2[i].thora,
                    menor_hora);
        }
    }
}

fclose(fptr3);

    return 0;
}

    return 0;
}
