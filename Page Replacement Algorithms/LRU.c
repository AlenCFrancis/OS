#include<stdio.h>

int i,j,nof,nor,flag=0,ref[50],frm[50],pf=0,victim=-1;
int recent[10],lrucal[50],count=0;

int lruvictim();

void main()
{
    printf("\n\t\t\t LRU PAGE REPLACEMENT ALGORITHM");
    
    printf("\n Enter no.of Frames: ");
    scanf("%d",&nof);

    printf(" Enter no.of reference string: ");
    scanf("%d",&nor);

    printf("\n Enter reference string: ");
    for(i=0;i<nor;i++)
        scanf("%d",&ref[i]);

    printf("\n\n\t\t LRU PAGE REPLACEMENT ALGORITHM\n");

    for(i=0;i<nof;i++)
        frm[i] = -1;

    for(i=0;i<nor;i++)
    {
        flag = 0;

        for(j=0;j<nof;j++)
        {
            if(frm[j] == ref[i])
            {
                flag = 1;
                recent[j] = count++;
                break;
            }
        }

        if(flag == 0)
        {
            pf++;

            if(i < nof)
            {
                frm[i] = ref[i];
                recent[i] = count++;
            }
            else
            {
                victim = lruvictim();
                frm[victim] = ref[i];
                recent[victim] = count++;
            }
        }

        printf("\n");
        for(j=0;j<nof;j++)
        {
            if(frm[j] == -1)
                printf("-\t");
            else
                printf("%d\t",frm[j]);
        }
    }

    printf("\n\n Page Faults = %d",pf);
}

int lruvictim()
{
    int min,i,pos=0;
    min = recent[0];

    for(i=1;i<nof;i++)
    {
        if(recent[i] < min)
        {
            min = recent[i];
            pos = i;
        }
    }

    return pos;
}
