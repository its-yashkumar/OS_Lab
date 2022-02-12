
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include<malloc.h>
#include <stdlib.h>

struct Proc
{
    int ID;
    int reqSize;
    int allotBlock;
};

struct MemBlock
{
    int isTaken;
    void *size;
};

struct Proc Array[1000];
struct MemBlock Blocks[1000];
int totBlockSpace = 0;

void dispBlocks(int n)
{
    printf("Block Representation : \n");
    for (int i = 0; i < n; ++i)
    {
        printf("[ B%d: %d ]   🔗   ", i + 1, _msize(Blocks[i].size));
    }
}

void dispProcs(int n)
{
    printf("\nID\tProcess size\tAllotment\t");
    for (int i = 0; i < n; ++i)
    {
        printf("\nP%d\t %d\t\t", Array[i].ID + 1, Array[i].reqSize);
        if (Array[i].allotBlock != -1)
        {
            printf("B%d", Array[i].allotBlock + 1);
        }
        else
        {
            printf("Not alloted");
        }
    }
    printf("\n");
}

void firstFit(int numBlocks, int numProcs)
{
    for (int i = 0; i < numProcs; ++i)
    {
        for (int j = 0; j < numBlocks; ++j)
        {
            int s = _msize(Blocks[j].size);
            if (Array[i].reqSize <= s && Blocks[j].isTaken == 0)
            {
                totBlockSpace -= Array[i].reqSize;
                Array[i].allotBlock = j;
                Blocks[j].isTaken = 1;
                break;
            }
        }
    }
}

void bestFit(int numBlocks, int numProcs)
{
    for (int i = 0; i < numProcs; ++i)
    {
        int currSize = -1, currIndex = -1;
        for (int j = 0; j < numBlocks; ++j)
        {
            int s = _msize(Blocks[j].size);
            if (Array[i].reqSize <= s && Blocks[j].isTaken == 0)
            {
                if (currSize > s || currSize == -1)
                {
                    currSize = s;
                    currIndex = j;
                }
            }
        }
        Array[i].allotBlock = currIndex;
        if (currIndex != -1)
        {
            totBlockSpace -= Array[i].reqSize;
            Blocks[currIndex].isTaken = 1;
        }
    }
}

void worstFit(int numBlocks, int numProcs)
{
    for (int i = 0; i < numProcs; ++i)
    {
        int currSize = -1, currIndex = -1;
        for (int j = 0; j < numBlocks; ++j)
        {
            int s = _msize(Blocks[j].size);
            if (Array[i].reqSize <= s && Blocks[j].isTaken == 0)
            {
                if (s > currSize || currSize == -1)
                {
                    currSize = s;
                    currIndex = j;
                }
            }
        }
        Array[i].allotBlock = currIndex;
        if (currIndex != -1)
        {
            totBlockSpace -= Array[i].reqSize;
            Blocks[currIndex].isTaken = 1;
        }
    }
}

int main()
{
    int numProc, numBlocks;

    printf("\nEnter number of memory blocks : ");
    scanf("%d", &numBlocks);

    printf("\nEnter memory block sizes : \n");
    for (int i = 0; i < numBlocks; ++i)
    {
        int tempSize;

        printf("Enter Block %d : ", i + 1);
        scanf("%d", &tempSize);
        totBlockSpace += tempSize;

        Blocks[i].isTaken = 0;
        Blocks[i].size = malloc(tempSize);
    }

    dispBlocks(numBlocks);

    printf("\nEnter number of processes : ");
    scanf("%d", &numProc);

    printf("\n\nEnter processes required size :\n");
    for (int i = 0; i < numProc; ++i)
    {
        Array[i].ID = i;
        Array[i].allotBlock = -1;

        printf("For P%d : ", i + 1);
        scanf("%d", &Array[i].reqSize);
    }

    char choice;

    while (choice != 'X')
    {

        printf("\n\nChoose process allocation algo:");
        printf("\nF.First Fit");
        printf("\nB.Best Fit");
        printf("\nW.Worst Fit");
        printf("\nInput: ");

        scanf("%c", &choice);
        switch (choice)
        {
        case 1:
            firstFit(numBlocks, numProc);
            printf("\n\nFirst Fit : ");
            break;
        case 2:
            bestFit(numBlocks, numProc);
            printf("\n\nBest Fit : ");
            break;
        case 3:
            worstFit(numBlocks, numProc);
            printf("\n\nWorst Fit : ");
            break;
        default:
            printf("\n\nINVALID INPUT");
            break;
        }

        dispBlocks(numBlocks);
        dispProcs(numProc);

        printf("\nTotal empty space: %d", totBlockSpace);
        printf("\n\n");
    }

    return 0;
}