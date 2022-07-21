#include <stdio.h>
#define MAX_N 100
#define oo 999999
#define NO_EDGE -1
typedef struct {
    int n,m;
    int W[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *pG, int n) {
    pG->n =n;
    pG->m =0;
    int u,v;
    for (u =1;u<=n;u++)
        for (v=1;v<=n;v++)
            pG->W[u][v] =NO_EDGE;
}

void add_edge(Graph *pG,int u,int v,int w) {
    pG->W[u][v]=w;
}

int mark[MAX_N];
int pi[MAX_N];
int p[MAX_N];

void MooreDijkstra(Graph *pG, int s) {
	int u,v,it;
	for (u=1;u<=pG->n;u++) {
		pi[u]=oo;
		mark[u]=0;
	}
	pi[s]=0; 
	p[s]=-1; 
	for(it=1;it<pG->n;it++){
		int j,min_pi=oo;
		for (j=1;j<=pG->n;j++)
			if (mark[j]==0 && pi[j]<min_pi){
				min_pi =pi[j];
				u =j;
			}
		mark[u]=1;
		for(v=1;v<=pG->n;v++)
			if(pG->W[u][v]!=NO_EDGE && mark[v]==0)
				if (pi[u]+pG->W[u][v]<pi[v]){
					pi[v]=pi[u]+pG->W[u][v];
					p[v]=u;
				}
	}
}


int main() {
    Graph G;
    int n,m,e;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);
    for(e=0;e<m;e++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(&G,u,v,w);
    }
    int s,t;
    scanf("%d%d",&s,&t);
    MooreDijkstra(&G,s);
    int path[MAX_N];
    int k=0;
    int current=t;
    while(current!=-1){
    	path[k]=current;k++;
    	current=p[current];
	}
	int u;
	printf("%d",path[k-1]);
	for(u=k-2;u>=0;u--){
		printf(" -> %d",path[u]);
	}
    return 0;
}