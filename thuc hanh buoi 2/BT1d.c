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
typedef int ElementType;
typedef struct{
	int data[MAX_SIZE];
	int front,rear;
}Queue;
void make_null_Queue(Queue *pQ){
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
int mark[MAX_N];
void BFS(Graph *pG,int s){
	Queue Q;
	make_null_Queue(&Q);
	enqueue(&Q,s);
	int v;
	while(!empty(&Q)){
		int u=front(&Q);
		dequeue(&Q);
		if(mark[u]!=0){
			continue;
		}
		printf("%d\n",u);
		mark[u]=1;
		for(v=1;v<=pG->n;v++){
			if(adjacent(pG,u,v)){
				enqueue(&Q,v);	
		}
	}
	}
}
int main(){
	Graph G;
	int n,m,u,v,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for (e=0;e<m;e++) {
    	scanf("%d%d",&u,&v);
    	add_edge(&G,u,v);
	}
	int s;
	scanf("%d",&s);
	for(u=1;u<=G.n;u++){
		mark[u]=0;
	}
	BFS(&G,s);
	return 0;	
}
