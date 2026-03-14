#include <stdio.h>

int max[10][10], alloc[10][10], need[10][10];
int avail[10];
int n, r;

void input();
void calculateNeed();
void display();
int safetyCheck();

int main()
{
    int i,p,req[10];
    char ch;

    printf("----- BANKER'S ALGORITHM -----\n");

    input();
    calculateNeed();
    display();

    if(safetyCheck())
        printf("\nSystem is in SAFE state\n");
    else
        printf("\nSystem is in UNSAFE state\n");

    printf("\nDo you want to request resources? (Y/N): ");
    scanf(" %c",&ch);

    if(ch=='y' || ch=='Y')
    {
        printf("Enter Process Number: ");
        scanf("%d",&p);

        printf("Enter Request for each resource:\n");
        for(i=0;i<r;i++)
            scanf("%d",&req[i]);

        /* temporary allocation */
        for(i=0;i<r;i++)
        {
            alloc[p][i]+=req[i];
            avail[i]-=req[i];
        }

        calculateNeed();
        display();

        if(safetyCheck())
            printf("\nRequest Granted (SAFE)\n");
        else
            printf("\nRequest Denied (UNSAFE)\n");
    }

    return 0;
}

void input()
{
    int i,j;

    printf("Enter number of Processes: ");
    scanf("%d",&n);

    printf("Enter number of Resources: ");
    scanf("%d",&r);

    printf("\nEnter MAX Matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    printf("\nEnter ALLOCATION Matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    printf("\nEnter AVAILABLE Resources\n");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);
}

void calculateNeed()
{
    int i,j;

    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            need[i][j]=max[i][j]-alloc[i][j];
}

void display()
{
    int i,j;

    printf("\nProcess\tAllocation\tMax\tNeed\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t",i);

        for(j=0;j<r;j++)
            printf("%d ",alloc[i][j]);

        printf("\t\t");

        for(j=0;j<r;j++)
            printf("%d ",max[i][j]);

        printf("\t");

        for(j=0;j<r;j++)
            printf("%d ",need[i][j]);

        printf("\n");
    }
}

int safetyCheck()
{
    int work[10],finish[10]={0};
    int safeSeq[10];
    int i,j,count=0;

    for(i=0;i<r;i++)
        work[i]=avail[i];

    while(count<n)
    {
        int found=0;

        for(i=0;i<n;i++)
        {
            if(!finish[i])
            {
                int possible=1;

                for(j=0;j<r;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        possible=0;
                        break;
                    }
                }

                if(possible)
                {
                    for(j=0;j<r;j++)
                        work[j]+=alloc[i][j];

                    safeSeq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if(!found)
            return 0;
    }

    printf("\nSafe Sequence: ");
    for(i=0;i<n;i++)
        printf("P%d ",safeSeq[i]);

    return 1;
}
