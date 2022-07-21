#include<stdio.h>
#define MAX_N 100
typedef struct{
	int n,m;
	int A[MAX_N][MAX_N];
}Graph;
void init_graph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
	int u,v;
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++)
			pG->A[u][v]=0;
	}
}
void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
}
int main(){
	Graph G;
	int e,n,m,u,v;
	scanf("%d",&n);
	init_graph(&G,n);
	for(e=1;e<=n;e++){
		while(1){
			scanf("%d",&u);
			if(u==0)
				break;
			else{
			  add_edge(&G,e,u);
			}
		}
	}
	for(u=1;u<=G.n;u++){
		for(v=1;v<=G.n;v++)
			printf("%d ",G.A[u][v]);
		printf("\n");
	}
	return 0;
}	
