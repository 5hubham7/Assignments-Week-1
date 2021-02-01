#include <stdio.h>

int board[20], count;

int main()
{
    int n, i, j;

    void queen(int row, int n);

    queen(1, 8);

    return 0;
}

void printSolution(int n)
{
    int i;
    printf("\nSolution %d:\n", ++count);

    for (i = 1; i <= n; ++i)
        printf("queen %d in column no.: %d\n", i, board[i]);

    printf("\n");
}

int checkPlace(int k, int column)
{
    int i;

    for (i = 1; i <= k - 1; ++i)
        if ((board[i] == column) || (abs(board[i] - column) == abs(i - k)))
            return 0;

    return 1;
}

void queen(int k, int n)
{
    int column;

    for (column = 1; column <= n; ++column)
    {
        if (checkPlace(k, column))
        {
            board[k] = column;

            if (k == n)
                printSolution(n);

            else
                queen(k + 1, n);
        }
    }
}

/* OUTPUT:-

Solution 91:                                                                                                                                       
queen 1 in column no.: 8                                                                                                                           
queen 2 in column no.: 3                                                                                                                           
queen 3 in column no.: 1                                                                                                                           
queen 4 in column no.: 6                                                                                                                           
queen 5 in column no.: 2                                                                                                                           
queen 6 in column no.: 5                                                                                                                           
queen 7 in column no.: 7                                                                                                                           
queen 8 in column no.: 4                                                                                                                           
                                                                                                                                                   
                                                                                                                                                   
Solution 92:                                                                                                                                       
queen 1 in column no.: 8                                                                                                                           
queen 2 in column no.: 4                                                                                                                           
queen 3 in column no.: 1                                                                                                                           
queen 4 in column no.: 3                                                                                                                           
queen 5 in column no.: 6                                                                                                                           
queen 6 in column no.: 2                                                                                                                           
queen 7 in column no.: 7                                                                                                                           
queen 8 in column no.: 5

*/