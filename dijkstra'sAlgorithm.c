#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

int available[100];
int index[100];
int distance[100];
int path[100];

typedef struct vertex
{
    int v_no;
    int weight;
}vertex;

typedef struct stack
{
    int arr[100];
    int top;
}stack;

typedef struct node
{
    vertex data;
    struct node* next;
}node;

typedef struct heap
{
    vertex a[100];
    int size;
}heap;

//prototypes

void readGraph(node** graph, int v);
void addEdge(node** graph, int src, int dest, int wt);
void dijsktra(node** graph, int v, int src);
void initHeap(heap* h);
void decreaseKey(heap* h, int src, int wt);
void swap(int a, int b);
int isEmpty(heap* h);
vertex extractMin(heap* h);
void heapify(heap* h, int i);


int main()
{
    node* graph[100] = {NULL};
    int v, src;
    printf("Vertices?\n");
    scanf("%d", &v);

    readGraph(graph, v);
    printf("Enter src for Dijstra\n");
    scanf("%d", &src);
    dijsktra(graph, v, src);

    for(int i = 0; i<v; ++i)
        printf("%d -> %d requires %d\n", src, i, distance[i]);

    printf("\n");

    printPath(v, src);
}

void printPath(int v, int src)
{
    stack s;
    s.top = -1;

    int i = src, j = 0;
    for(j = 0; j<v; ++j)
    {
        i = j;
        while(i != path[i])
        {
            push(&s, path[i]);
            i = path[i];
        }


        if(j != src)
        {
            printf("to reach %d:  ", j);
        }

        while(j != src && s.top != -1)
            printf("%d->", pop(&s));

        if(j != src)
            printf("%d\n", j);

    }
}

int pop(stack* s)
{
    int t = s->arr[s->top];
    s->top--;
    return t;
}

void push(stack* s, int p)
{
    s->top++;
    s->arr[s->top] = p;
}

void dijsktra(node** graph, int v, int src)
{
    heap h;
    int i;
    initHeap(&h);
    vertex e, u;
    int ver, d;
    for(i = 0; i<v; ++i)
    {
        h.a[i].v_no = i;
        h.a[i].weight = INT_MAX;
        available[i] = 1;
        index[i] = i;
    }

    initPath(src);
    h.size = v;

    decreaseKey(&h, src, 0);

    while(!isEmpty(&h))
    {
        u = extractMin(&h);
        ver = u.v_no;
        d = u.weight;
        distance[ver] = d;

        node* p = graph[ver];
        while(p)
        {
            e = p->data;
            if( available[e.v_no] && (e.weight + d < h.a[index[e.v_no]].weight) )
            {
                decreaseKey(&h, index[e.v_no], e.weight + d);
                path[e.v_no] = ver;
            }

            p = p->next;
        }
    }
}

void initPath(int src)
{
    int i = 0;
    for(i = 0; i<100; ++i)
        path[i] = src;
}

vertex extractMin(heap* h)
{
    vertex e = h->a[0];
    available[h->a[0].v_no] = 0;
    h->a[0] = h->a[h->size - 1];
    index[h->a[0].v_no] = 0;

    h->size --;

    heapify(h, 0);
    return e;
}

void heapify(heap* h, int i)
{
    int left = 2*i + 1, right = 2*i + 2;
    int min = i;
    vertex e;

    vertex* arr = h->a;
    if(left < h->size && arr[left].weight < arr[min].weight)
        min = left;

    if(right < h->size && arr[right].weight < arr[min].weight)
        min = right;

    if(min != i)
    {
        index[arr[min].v_no] = i;
        index[arr[i].v_no] = min;
        e = arr[min];
        arr[min] = arr[i];
        arr[i] = e;

        heapify(h, min);
    }
}

int isEmpty(heap* h)
{
    if(h->size == 0)
        return 1;
    return 0;
}

void decreaseKey(heap* h, int src, int wt)
{
    h->a[src].weight = wt;

    int i = src;
    vertex temp;
    temp = h->a[src];

    while(i > 0 && temp.weight < h->a[(i-1)/2].weight)
    {
        h->a[i] = h->a[(i-1)/2];
        index[h->a[(i-1)/2].v_no] = i;
        i = (i-1)/2;
    }
    h->a[i] = temp;
    index[temp.v_no] = i;
}


void swap(int a, int b)
{
    int temp = index[a];
    index[a] = index[b];
    index[b] = temp;
}

void readGraph(node** graph, int v)
{
    int i, k, j, wt, dest;
    for(i = 0; i<v; ++i)
    {
        printf("How many edges emerge from %d?\n", i);
        scanf("%d", &k);

        for(j = 0; j<k; ++j)
        {
            printf("Dest?\n");
            scanf("%d", &dest);
            printf("Weight?\n");
            scanf("%d", &wt);
            addEdge(graph, i, dest, wt);
        }
    }
}

void addEdge(node** graph, int src, int dest, int wt)
{
    node* p;
    p = (node* ) malloc(sizeof(node));
    p->data.v_no = dest;
    p->data.weight = wt;
    p->next = NULL;

    if(graph[src] == NULL)
        graph[src] = p;
    else
    {
        node* q = graph[src];
        while(q->next)
            q = q->next;

        q->next = p;
    }
}

void initHeap(heap* h)
{
    h->size = 0;
}
