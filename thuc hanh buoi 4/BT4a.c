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
void add_edge(Graph *pG,int u,int v) {
    pG->A[v][u]+=1;
}
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;

void make_null(List* L) {
	L->size = 0;
}

void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}

ElementType element_at(List* L, int i) {
	return L->data[i-1];
}

int count_list(List* L) {
	return L->size;
}

int empty_list(List* L) {
	return L->size == 0;
}
void copy_list(List *pS1,List *pS2){
	int i,x;
	make_null(pS1);
	for(i=1;i<=pS2->size;i++){
		x=element_at(pS2,i);
		push_back(pS1,x);
	}
}
int r[MAX_N];
void rank(Graph *pG){
	int d[MAX_N];
	int u,v;
	for(u=1;u<=pG->n;u++){
		d[u]=0;
		for(v=1;v<=pG->n;v++){
			if(pG->A[v][u]!=0)
				d[u]++;
		}
	}
	List S1,S2;
	make_null(&S1);
	for(u=1;u<=pG->n;u++)	
		if(d[u]==0)
			push_back(&S1,u);
	int i,k=1;
	while(S1.size>0){
		make_null(&S2);
		for(i=1;i<=S1.size;i++){
			int u=element_at(&S1,i);
			r[u]=k;
			for(v=1;v<=pG->n;v++)
				if(pG->A[u][v]!=0){
					d[v]--;
					if(d[v]==0)
						push_back(&S2,v);
				}
		}
		copy_list(&S1,&S2);
		k++;
	}		
}
int main(){
	Graph G;
	int n,m,u,v,e,sum=0;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0;e<m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	rank(&G);
	for(u=1;u<=n;u++){
		printf("%d\n",r[u]);
		sum=sum+r[u];
	}
	printf("%d",sum);
	return 0;
}
