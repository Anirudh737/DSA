#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
#include <time.h>
#include<string.h>
struct stack
{
    int data[SIZE],top,a,b,c,d;
};

void push(struct stack *sptr,int num)
{
    if(sptr->top == SIZE-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top] = num;
    }
}

int pop(struct stack *sptr)
{
    int num;
    if(sptr->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        for(int k=sptr->top;k>-1;k--)
        num = sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}

void peek(struct stack *sptr)
{
    if(sptr->top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("%d\n",sptr->data[sptr->top]);
    }
}

void display(struct stack *sptr)
{
    int i;
    if(sptr->top == -1)
    {
        printf("Empty stack\n");
    }
    else
    {
        for(i=sptr->top;i>=0;i--)
        {
            printf("%d\n",sptr->data[i]);
        }
    }
}
void count(struct stack *sptr)
{
    int q=sptr->top;
    while(q!=-1)
    {
        switch(sptr->data[q])
        {
            case 1:sptr->a++;
                break;
            case 2:sptr->b++;
                break;
            case 5:sptr->c++;
                break;
            case 10:sptr->d++;
                break;
        }
        q--;
    }
    printf("1=%d 2=%d 5=%d 10=%d\n",sptr->a,sptr->b,sptr->c,sptr->d);
}

int main()
{
    int choice,data,r;
    int arr[SIZE];
    struct stack*sptr;
    struct stack s;
    int num,upper,lower,n,x=0;
    printf("Enter the LOWER and UPPER value of the interval\n");
    scanf("%d %d",&lower,&upper);
    srand(time(0));
    sptr = &s;
    s.a=s.b=s.c=s.d=0;
    sptr->top = -1;
    FILE *fptr;
    FILE *fptr1;
    FILE *fptr2;
    FILE *fptr3;
    FILE *fptr4;
    fptr = fopen("stacktext.txt","w");
    if(fptr==NULL)
    {
        printf("Could not open the file\n");
        exit(0);
    }
    else
    {
    for (int i =0 ;i < upper;i++)
    {
        int y;
    y = rand()%upper+lower;
    printf("%d ",y);
    fprintf(fptr,"%d",y);
    arr[x] = y;
    x++;
    }
    fclose(fptr);
    printf("\n");
    }
    x = 0;
    fptr1 = fopen("stackPush.txt","w");
    fptr2 = fopen("poplog.txt","w");
    fptr3 = fopen("stacktimeLog.txt","w");
    rewind(fptr);
    fscanf(fptr,"%d",r);
    printf("%d",r);
    printf("\n");
    while(1)
    {
        printf("1:Push operation 2:Pop operation 3:Peek 4:Display 5:Count 6:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        int z  = arr[x];
        switch (choice)
        {
            case 1:
                if(arr[x] == NULL)
                {
                    printf("No data to push\n");
                }
                else
                {
                push(sptr,arr[x]);
                printf("Stack Push file opened\n");
                fprintf(fptr1,"%d",arr[x]);
                printf("Stack Push updated\n");
                fprintf(fptr3,"Pushed %d\n",arr[x]);
                x++;
                }
                break;
            case 2:
                data = pop(sptr);
                printf("POPPED : %d \n",data);
                fprintf(fptr2,"%d",data);
                fprintf(fptr2,"popped : %d\n",data);
                fprintf(fptr3,"popped %d\n",data);
                break;
            case 3:peek(sptr);
                break;
            case 4:display(sptr);
                break;
            case 5:count(sptr);
                break;
            case 6:exit(0);
            default:printf("Invalid input\n");
                break;
        }
    }
}
