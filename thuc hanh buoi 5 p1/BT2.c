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
    pG->W[v][u]=w;
    pG->m++;
}
int pi[MAX_N];
int p[MAX_N];
int mark[MAX_N];
int Prim(Graph *pG,Graph *pT,int s){
	int i,u,v,x;
	for(u=1;u<=pG->n;u++){
		pi[u]=oo;
		p[u]=-1;
		mark[u]=0;
	}
	pi[s]=0;
	for(i=1;i<pG->m;i++){
		int min_dist=oo;
		for(x=1;x<=pG->n;x++){
			if(mark[x]==0 && pi[x]<min_dist){
				min_dist=pi[x];
				u=x;
			}
		}
		mark[u]=1;
		for(v=1;v<=pG->n;v++){
			if(pG->W[u][v]!=NO_EDGE){
				if(mark[v]==0 && pi[v]>pG->W[u][v]){
					pi[v]=pG->W[u][v];
					p[v]=u;
				}
			}
		}
	}
	init_graph(pT,pG->n);
	int sum_w=0;
	for(u=1;u<=pG->n;u++){
		if(p[u]!=-1){
			int w=pG->W[p[u]][u];
			add_edge(pT,p[u],u,w);
			sum_w+=w;
		}
	}
	return sum_w;
}
int main(){
	Graph G,T;
	int n,m,u,v,w,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=1;e<=m;e++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	int sum_w=Prim(&G,&T,1);
	printf("%d\n",sum_w);
	for(u=1;u<=n;u++){
        for(v=u;v<=n;v++){
        	if(T.W[u][v]!=NO_EDGE){
            	printf("%d %d %d\n",u,v,T.W[u][v]);
        	}
        }
    }
	return 0;
}
