
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void bubble_sort(int arr[], int n);

int main()
{

    int n = 10;
    int num[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {

        num[i] = rand() % 100 + 1;

    }

    bubble_sort(num, n);
    printf("Sorted num: ");

    for (int i = 0; i < n; i++)

        {

        printf("%d ", num[i]);

    }

    printf("\n");

    return 0;

}

void bubble_sort(int arr[], int n)
{

    int i, j, temp;

    for (i = 1; i <= n-1; i++)
        {
        for (j = 0; j < n-i-1; j++)
         {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }

    }

}
