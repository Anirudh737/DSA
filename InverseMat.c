#include <stdio.h>

int main()
 {
    int n, i, j, k;

    // get matrix size from user
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    double matrix[n][n], identity[n][n];
    printf("Enter the elements of the matrix row-wise:\n");
    for(i=0; i<n; i++)
        {
        for(j=0; j<n; j++)
        {
            scanf("%lf", &matrix[i][j]);

            // initialize identity matrix
            if(i == j)
                {
                identity[i][j] = 1;
            }
            else
            {
                identity[i][j] = 0;
            }
        }
    }

    // perform row operations to convert matrix to row-echelon form
    for(k=0; k<n; k++)
        {
        for(i=k+1; i<n; i++)
         {
            double factor = matrix[i][k] / matrix[k][k];
            for(j=k+1; j<n; j++)
            {
                matrix[i][j] -= factor * matrix[k][j];
            }
            matrix[i][k] = 0;
            for(j=0; j<n; j++)
             {
                identity[i][j] -= factor * identity[k][j];
            }
        }
    }

    // perform back-substitution to convert matrix to reduced row-echelon form
    for(k=n-1; k>=0; k--)
        {
        for(i=k-1; i>=0; i--)
         {
            double factor = matrix[i][k] / matrix[k][k];
            for(j=n-1; j>=k; j--) {
                matrix[i][j] -= factor * matrix[k][j];
            }
            matrix[i][k] = 0;
            for(j=0; j<n; j++)
             {
                identity[i][j] -= factor * identity[k][j];
            }
        }
    }

    // check if matrix is invertible
    int invertible = 1;
    for(i=0; i<n; i++) {
        if(matrix[i][i] == 0) {
            invertible = 0;
            break;
        }
    }
    if(invertible) // if matrix is invertible, extract inverted matrix from identity matrix
        {
        printf("The inverse of the matrix is:\n");
         for( i=0;i<n;i++)
   {
       for (j=0;j<n;j++)
       {
           printf("%lf ",identity[i][j]);
       }
       printf("\n");
   }
    }
}

