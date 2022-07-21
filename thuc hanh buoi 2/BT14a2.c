#include<stdio.h>
#define MAX_N 100
#define MAX_SIZE 500
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
void add_edge(Graph *pG,int u,int v){
	pG->A[u][v]=1;
	pG->m++;
}
int adjacent(Graph *pG,int u,int v){
	return pG->A[u][v]>0;
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
int num[MAX_N],min_num[MAX_N];
int k;
Stack S;
int on_stack[MAX_N];
int count;
int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
void SCC(Graph *pG,int u){
	num[u]=min_num[u]=k;k++;
	push(&S,u);
	on_stack[u]=1;
	int v;
	for(v=1;v<=pG->n;v++){
		if(adjacent(pG,u,v)){
			if(num[v]<0){
				SCC(pG,v);
				min_num[u]=min(min_num[u],min_num[v]);
			}
			else if(on_stack[v])
				min_num[u]=min(min_num[u],num[v]);
		}
	}
	if(num[u]==min_num[u]){
		//printf("Tim duoc BPLT manh, %d la dinh khop.\n",u);
		int w;
		do{
			w=top(&S);
			pop(&S);
			count++;
			on_stack[w]=0;
		}while (w!=u);
	}
}
int main(){
	Graph G;
	int n,m,u,v,e,t;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0;e<m;e++) {
    	scanf("%d%d",&u,&v,&t);
    	if(t==1){
    		add_edge(&G,u,v);
		}
		else if(t==2){
			add_edge(&G,u,v);
			add_edge(&G,v,u);
		}
	}
	for(u=1;u<=G.n;u++){
		num[u]=-1;
		on_stack[u]=0;
	}
	k=1;
	count=0;
	make_null_stack(&S);
	for(u=1;u<=G.n;u++){
		if(num[u]==-1)
			SCC(&G,u);
	}
	if(count==1){
		printf("OKIE");
	}
	else printf("NO");
	return 0;
}
