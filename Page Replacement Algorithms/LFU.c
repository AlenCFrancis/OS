#include<stdio.h>

int main()
{
    int total_frames,total_pages,hit = 0;
    int pages[25],frame[10],arr[25],time[25];
    int m, n, page, flag, k, minimum_time, temp;

    printf("Enter Total Number of Pages:\t");
    scanf("%d",&total_pages);

    printf("Enter Total Number of Frames:\t");
    scanf("%d",&total_frames);

    for(m = 0;m<total_frames;m++)
    {
        frame[m] = -1;
    }

    for(m=0;m<25;m++)
    {
        arr[m] = 0;
        time[m] = 0;
    }

    printf("Enter Values of Reference String\n");
    for(m=0;m<total_pages;m++)
    {
        scanf("%d",&pages[m]);
    }

    for(m=0;m<total_pages;m++)
    {
        flag = 0;
        page = pages[m];

        for(n=0;n<total_frames;n++)
        {
            if(frame[n] == page)
            {
                flag = 1;
                hit++;
                arr[n]++;
                time[n] = m;
                break;
            }
        }

        if(flag == 0)
        {
            int pos = -1;

            for(n=0;n<total_frames;n++)
            {
                if(frame[n] == -1)
                {
                    pos = n;
                    break;
                }
            }

            if(pos != -1)
            {
                frame[pos] = page;
                arr[pos] = 1;
                time[pos] = m;
            }
            else
            {
                int min = arr[0];
                pos = 0;

                for(n=1;n<total_frames;n++)
                {
                    if(arr[n] < min)
                    {
                        min = arr[n];
                        pos = n;
                    }
                    else if(arr[n] == min)
                    {
                        if(time[n] < time[pos])
                            pos = n;
                    }
                }

                frame[pos] = page;
                arr[pos] = 1;
                time[pos] = m;
            }
        }

        printf("\n");

        for(k=0;k<total_frames;k++)
        {
            if(frame[k] == -1)
                printf("-\t");
            else
                printf("%d\t",frame[k]);
        }
    }

    printf("\nTotal Hits:\t%d",hit);
    printf("\nTotal Page Faults:\t%d",total_pages-hit);

    return 0;
}
