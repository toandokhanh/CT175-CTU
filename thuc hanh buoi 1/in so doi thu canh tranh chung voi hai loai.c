#include<stdio.h>
#define MAX_N 100
#define MAX_M 500
typedef struct{
	int n,m;
	int A[MAX_N][MAX_M];
}Graph;
void init_graph(Graph *pG,int n,int m){
	int u,e;
	pG->n=n;
	pG->m=m;
	for(u=1;u<=n;u++){
		for(e=1;e<=m;e++){
			pG->A[u][e]=0;
		}
	}
}
void add_edge(Graph *pG,int e,int u,int v){
	pG->A[u][e]=1;
	pG->A[v][e]=1;
}
int adjacent(Graph *pG,int u,int v){
	int e;
	for(e=1;e<=pG->m;e++){
		if(pG->A[u][e]==1 && pG->A[v][e]==1)
			return 1;
	}
	return 0;
}
int degree(Graph *pG,int u){
	int e,deg_u=0;
	for(e=1;e<=pG->m;e++)
		if(pG->A[u][e]==1)
			deg_u++;
	return deg_u;
}
void neighbours(Graph *G,int x,int y){ 
	int e; 
	for(e=1;e<=G->n;e++){ 
		if(x!=e){ 
			if(adjacent(G,x,e)==1 && adjacent(G,y,e)==1){ 
				printf("%d ",e); 
			} 
		} 
	} 
}
int main(){ 
	Graph G; 
	int count=0; 
	int n,m,u,v,e,x,y; 
	scanf("%d%d",&n,&m); 
	init_graph(&G,n,m); 
	for(e=1;e<=m;e++){ 
		scanf("%d%d",&u,&v); 
		add_edge(&G,e,u,v); 
	} 
	scanf("%d%d",&x,&y);
	for(e=1;e<=n;e++){  
		if((x!=e) && (y!=e)){
			if(adjacent(&G,x,e)!=0 && adjacent(&G,y,e)!=0){
				count++;
			}
	}
	}
	printf("%d",count);
	return 0;
}			
