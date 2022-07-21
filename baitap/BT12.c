#include<stdio.h>
#define MAX_N 100
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;
typedef struct{
	int n;
	List adj[MAX_N];
}Graph;
void make_null(List *pL){
	pL->size=0;
}
void push_back(List *pL,ElementType x){
	pL->data[pL->size]=x;
	pL->size++;
}
int element_at(List *pL,int i){
	return pL->data[i-1];
}
int count_list(List *pL){
	return pL->size;
}
void init_graph(Graph *pG,int n){
	int u;
	pG->n=n;
	for(u=1;u<=n;u++){
		make_null(&pG->adj[u]);
	}
}		
void add_edge(Graph *pG,int u,int v){
	push_back(&pG->adj[u],v);
	push_back(&pG->adj[v],u);
}
int adjacent(Graph *pG,int u,int v){
	int j;
	for(j=1;j<=pG->adj[u].size;j++){
		if(element_at(&pG->adj[u],j)==v)	
			return 1;
	return 0;
}
}
int degree(Graph *pG,int x){
	return pG->adj[x].size;
}
void neighbours(Graph *pG,int u){
	int v,j;
	for(v=1;v<=pG->adj[u].size;v++){
		printf("%d ",element_at(&pG->adj[u],v));
	}	
	printf("\n");
}
int main(){
	Graph G;
	int m,n,u,v,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e= 0;e<m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(u=1;u<=G.n;u++){
		printf("degree(%d) = %d\n",u,degree(&G,u));
	}
	int i;
	for(i=1;i<=G.n;i++){
		printf("neighbours(%d) = ",i);
		neighbours(&G,i);
	}
	return 0;
}													

