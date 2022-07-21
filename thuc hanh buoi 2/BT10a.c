#include<stdio.h>
#define MAX_N 500
#define MAX_SIZE 100
typedef struct{
	int u,v;
}Edge;
typedef struct{
	int n,m;
	Edge edges[MAX_N];
}Graph;
void init_graph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
}
void add_edge(Graph *pG,int u,int v){
	pG->edges[pG->m].u=u;
	pG->edges[pG->m].v=v;
	pG->m++;
}
int degree(Graph *pG,int u){
	int e,deg_u=0;
	for(e=0;e<pG->m;e++){
		if(pG->edges[e].u==u)
			deg_u++;
		if(pG->edges[e].v==u)
			deg_u++;
	}
	return deg_u;
}
int adjacent(Graph *pG,int u,int v){
	int e;
	for(e=0;e<pG->m;e++){
		if((pG->edges[e].u==u && pG->edges[e].v==v)){
			return 1;
		}
	}
	return 0;
}
typedef struct{
	int u,p;
}ElementType;
typedef struct{
	ElementType data[MAX_SIZE];
	int front,rear;
}Queue;
void make_null_queue(Queue *pQ){
	pQ->front=0;
	pQ->rear=-1;
}
void enqueue(Queue *pQ,ElementType u){
	pQ->rear++;
	pQ->data[pQ->rear]=u;
}
int empty(Queue *pQ){
	return pQ->front > pQ->rear;
}
ElementType front(Queue *pQ){
	return pQ->data[pQ->front];
}
void dequeue(Queue *pQ){
	pQ->front++;
}
#define WHITE 0
#define GRAY 1
#define BLACK 2
int color[MAX_N];
int has_circle;
void DFS(Graph *pG,int u){
	color[u]=GRAY;
	int v;
	for(v=1;v<=pG->n;v++){
		if(adjacent(pG,u,v)){
			if(color[v]==WHITE)
				DFS(pG,v);
			else if(color[v]==GRAY)
				has_circle=1;	
		}
	}
	color[u]=BLACK;
}
int main(){
	Graph G;
	int n,m,u,v,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0;e<m;e++) {
    	scanf("%d%d",&u,&v);
    	add_edge(&G,u,v);
	}
	for(u=1;u<=G.n;u++){
		color[u]=WHITE;
	}
	has_circle=0;
	for(u=1;u<=G.n;u++){
		if(color[u]==WHITE)
			DFS(&G,u);
	}
	if(has_circle==1){
		printf("CIRCLED");
	}
	else printf("NO CIRCLE");
	return 0;
}
