#include <stdio.h>

/* Khai b�o CTDL Graph*/
#define MAX_N 100
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    int u,v;
    for (u = 1 ; u <= n; u++)
        for (v = 1 ; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
    if (u != v)
        pG->A[v][u] += 1;
        
    if (pG->A[u][v] > 1)
        printf("da cung (%d, %d)\n", u, v);
    if (u == v)
        printf("khuyen %d\n", u);
    
    
    pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
    return pG->A[u][v] > 0;
}

#define WHITE 0
#define GRAY  1
#define BLACK 2

int color[MAX_N];		//Luu tr?ng th�i c?a c�c d?nh
int parent[MAX_N];		//Luu tr?ng th�i c?a c�c d?nh
int has_circle;		//�? th? ch?a tr�nh hay kh�ng
int start, end;

void DFS(Graph *pG, int u, int p) {								
	//1. T� m�u dang duy?t cho u
	color[u] = GRAY;
	parent[u] = p;
	int v;
	//2. X�t c�c d?nh k? c?a u
	for (v = 1; v <= pG->n; v++)
		if (adjacent(pG, u, v)) {
			if (v == p)
			    continue;

			if (color[v] == WHITE) 		//2a. N?u v chua duy?t
				DFS(pG, v, u);   		//g?i d? quy duy?t n�
			else if (color[v] == GRAY) { //2b. v dang duy?t
				has_circle = 1;   	//ch?a chu tr�nh
				start = u;
				end = v;
			}
		}

	//3. T� m�u duy?t xong cho u
	color[u] = BLACK;
}


int main() {
	//1. Khai b�o d? th? G
	Graph G;
	//2. �?c d? li?u v� d?ng d? th?
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
	    scanf("%d%d", &u, &v);
	    add_edge(&G, u, v);
	}

	for (u = 1; u <= G.n; u++)							
		color[u] = WHITE; 								
	//2. Kh?i t?o bi?n has_circle								
	has_circle = 0;										
	//3. Duy?t to�n b? d? th? d? ki?m tra chu tr�nh					
	for (u = 1; u <= G.n; u++)							
		if (color[u] == WHITE)	//u chua duy?t				
			DFS(&G, u, -1);		//g?i DFS(&G, u) d? duy?t t? u
	//4. Ki?m tra has_circle	

    if (has_circle) {
        int A[100], i = 0;
        A[0] = start;
        int u = start;
        do {
            u = parent[u];
            i++;
            A[i] = u;
        } while (u != v);
        int j;
        for (j = i; j >= 0; j--)
            printf("%d ", A[j]);

        printf("%d\n", A[i]);
    } else
        printf("-1\n");
    
    return 0;
}


