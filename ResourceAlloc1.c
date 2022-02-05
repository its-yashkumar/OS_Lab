#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>

int main()
{
    int numProc, numRes, i, j, k;
    int finish[20], safeSeq[20], ind = 0;

    numProc = 4;
    numRes = 2;

    int currAlloc[4][2] = {{7, 2},
                           {1, 3},
                           {1, 1},
                           {3, 0}};

    int maxAlloc[4][2] = {{9, 5},
                          {2, 6},
                          {2, 2},
                          {5, 0}};

    int availRes[2] = {2, 1};

    int needRes[10][10];

    for (int k = 0; k < numProc; k++)
    {
        finish[k] = 0;
    }

    for (int i = 0; i < numProc; i++)
    {
        for (j = 0; j < numRes; j++)
        {
            needRes[i][j] = maxAlloc[i][j] - currAlloc[i][j];
        }
    }

    for (int k = 0; k < numProc; k++)
    {
        for (int i = 0; i < numProc; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < numRes; j++)
                {
                    if (needRes[i][j] > availRes[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    safeSeq[ind++] = i;
                    for (int l = 0; l < numRes; l++)
                    {
                        availRes[l] = availRes[l] + currAlloc[i][l];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    int final = 1;

    for (int i = 0; i < numProc; i++)
    {
        if (finish[i] == 0)
        {
            flag = 0;
            printf("!!The system is not in safe mode!!\n");
            final = 0;
            break;
        }
    }

    if (final == 1)
    {
        printf("The safe sequence is: \n");
        for (i = 0; i < numProc - 1; i++)
        {
            printf("P[%d]    ->  ", safeSeq[i]);
        }
        printf(" P[%d]  \n", safeSeq[numProc - 1]);
    }

    return 0;
}