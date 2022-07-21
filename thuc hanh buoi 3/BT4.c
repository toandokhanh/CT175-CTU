#include <stdio.h>
#define MAX_N 100
#define oo 999999
#define NO_EDGE 0
int w[MAX_N];
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
	pi[s]=w[s]; 
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
    int m,n,ii,jj,k,u,v,i,j;
    scanf("%d%d",&m,&n);
    init_graph(&G,n*m);
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		scanf("%d",&u);
    		w[i*n+j+1]=u;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			int di[]={-1,1,0,0};
			int dj[]={0,0,-1,1};
			for(k=0;k<4;k++){
				ii=i+di[k];
				jj=j+dj[k];
				if(ii>=0 && ii<m && jj>=0 && jj<n){
					v=ii*n+jj+1;
					u=i*n+j+1;
					G.W[u][v]=w[v];
				}
			}
		}
	}
    MooreDijkstra(&G, 1);
    printf("%d",pi[G.n]);
    return 0;
}
