#include <stdio.h>
#define MAXN 100
#define oo 999999
#define NO_EDGE -999999

typedef struct {
    int n, m;
    int W[MAXN][MAXN];
}Graph;
void init_graph(Graph *pG,int n) {
    pG->n =n;
    pG->m =0;
    int u,v;
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            pG->W[u][v]=NO_EDGE;
}

void add_edge(Graph *pG,int u,int v,int w) {
    pG->W[u][v]=w;
    pG->m++;
}


#define oo 999999
int pi[MAXN][MAXN];
int next[MAXN][MAXN];
void FloydWarshall(Graph *pG) {
    int u,v,k;
    for(u=1;u<=pG->n;u++)
        for(v=1;v<=pG->n;v++){
            pi[u][v]=oo;
            next[u][v]=-1;
        }
    for(u=1;u<=pG->n;u++)
        pi[u][u]=0;
    for(u=1;u<=pG->n;u++)
        for(v=1;v<=pG->n;v++)
            if(pG->W[u][v]!=NO_EDGE) {
                pi[u][v]=pG->W[u][v]; 
                next[u][v]=v;
            }
    for(k=1;k<=pG->n;k++){
        for (u=1;u<=pG->n;u++) {
            if(pi[u][k]==oo)
                continue;
            for(v=1;v<=pG->n;v++){
                if(pi[k][v]==oo)
                    continue;
                if(pi[u][k]+pi[k][v]<pi[u][v]){
                    pi[u][v]=pi[u][k]+pi[k][v];
                    next[u][v]=next[u][k];
                }
            }
        }
	}
	int negative_cycle=0;
	for(u=1;u<=pG->n;u++){
		if(pi[u][u]==oo){
			continue;
		}
		if(pi[u][u]<0){
			negative_cycle=1;
			printf("YES");
			break;
		}
	}
	if(negative_cycle==0){
		printf("NO");
	}
}


int main() {
    Graph G;
    int n, m, e;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);
    for(e=0;e<m;e++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(&G,u,v,w);
    }
    FloydWarshall(&G);
    return 0;
}
