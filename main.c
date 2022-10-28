#include <stdio.h>

/* NTS: 
* A magic square of order n
* is an arrangement of the numbers 1, 2, ..., n^2 in an n x n matrix,
* with each number occurring exactly once, and such that the sum of
* the entries of any row, any column, or any main diagonal is the same.
* The magic constant of a normal magic square depends on n and has the following formula:
* magic constant = n(n^2+1)/2
*/

int main(void)
{
    /* IMPORTANT STUFF */
    printf("The magic square will only work when 'n' is an odd number.\n");
    
    int n, i, j, k, l, m, magic_const, sum = 0;
    int magic_square[100][100];

    printf("Enter the order of the magic square: ");
    scanf_s("%d", &n);

    magic_const = n * (n * n + 1) / 2;

    /* Initialize the magic square to all zeros */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            magic_square[i][j] = 0;

    /* Place the number 1 in the middle of row 0 */
    i = 0;
    j = n / 2;
    magic_square[i][j] = 1;

    /* Place the remaining numbers */
    for (k = 2; k <= n * n; k++)
    {
        i--;
        j++;

        /* If the number is to be placed outside the magic square's bounds, wrap around */
        if (i < 0 && j == n)
        {
            i += 2;
            j--;
        }
        else
        {
            /* If the number is to be placed outside the magic square's bounds, wrap around */
            if (i < 0)
                i = n - 1;
            if (j == n)
                j = 0;
        }

        /* If the number is to be placed in a cell that already contains a number, place it below the previously placed number */
        if (magic_square[i][j] != 0)
        {
            i += 2;
            j--;
        }

        magic_square[i][j] = k;
    }

    /* Print the magic square */
    printf("The magic square of order %d is:\n\n", n);
    for (l = 0; l < n; l++)
    {
        for (m = 0; m < n; m++)
            printf("%5d", magic_square[l][m]);
        printf("\n");
    }

    /* Check if the sum of each row is equal to the magic constant */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            sum += magic_square[i][j];
        if (sum != magic_const)
        {
            printf("The sum of row %d is %d, which is not equal to the magic constant %d.\n", i + 1, sum, magic_const);
            return 0;
        }
        else { printf("The sum of row %d is %d, which is equal to the magic constant %d.\n", i + 1, sum, magic_const); }
        sum = 0;
    }

    /* Check if the sum of each column is equal to the magic constant */
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
            sum += magic_square[i][j];
        if (sum != magic_const)
        {
            printf("The sum of column %d is %d, which is not equal to the magic constant %d.\n", j + 1, sum, magic_const);
            return 0;
        }
        else { printf("The sum of column %d is %d, which is equal to the magic constant %d.\n", j + 1, sum, magic_const); }
        sum = 0;
    }

    return 0;
}