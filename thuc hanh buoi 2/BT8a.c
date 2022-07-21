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
		if((pG->edges[e].u==u && pG->edges[e].v==v)||(pG->edges[e].u==v && pG->edges[e].v==u)){
			return 1;
		}
	}
	return 0;
}
typedef int ElementType;
typedef struct{
	ElementType data[MAX_SIZE];
	int top_idx;
}Stack;
void make_null_stack(Stack *pS){
	pS->top_idx=-1;
}
void push(Stack *pS,ElementType u){
	pS->top_idx++;
	pS->data[pS->top_idx]=u;
}
ElementType top(Stack *pS){
	return pS->data[pS->top_idx];
}
void pop(Stack *pS){
	pS->top_idx--;
}
int empty(Stack *pS){
	return pS->top_idx==-1;
}
int mark[MAX_N];
void DFS(Graph *pG,int s){
	Stack S;
	make_null_stack(&S);
	push(&S,s);
	int v;
	while(!empty(&S)){
		int u=top(&S);
		pop(&S);
		if(mark[u]!=0)
			continue;
		mark[u]=1;
		for(v=1;v<=pG->n;v++){
			if(adjacent(pG,u,v))
				push(&S,v);
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
	for(u=1;u<=G.n;u++){
		mark[u]=0;
	}
	int cnt=0;
	for(u=1;u<=G.n;u++){
		if(mark[u]==0){
			DFS(&G,u);
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
