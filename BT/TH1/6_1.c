#include <stdio.h>

#define MAX_N 100

typedef struct{
    int u, v;
}Edge;

typedef struct{
    int n, m;
    Edge edges[MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int adjacent(Graph *pG, int u, int v){
    for(int i = 0; i < pG->m; i++)
        if((pG->edges[i].u == u && pG->edges[i].v == v)
        || (pG->edges[i].u == v && pG->edges[i].v == u)) return 1;
    return 0;
}

void neighbours(Graph *pG, int u){
    for(int v = 1; v <= pG->n; v++)
        if(adjacent(pG, u, v))
            printf("%d ", v);
    printf("\n");
}

int main(){
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for(int e = 0; e < m; e++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++){
        printf("neighbours(%d) = ", u);
        neighbours(&G, u);
    }    
    return 0;
}