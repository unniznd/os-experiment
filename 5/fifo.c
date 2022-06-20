#include <stdio.h>
int main()
{
    int referenceString[10], temp[100], pageFaults = 0, m, n, s, pages, frames, modCounter = 0;

    printf("\nEnter the number of Pages:\t");
    scanf("%d", &pages);
    printf("\nEnter reference string values:\n");
    for (m = 0; m < pages; m++)
    {
        printf("Value No. [%d]:\t", m + 1);
        scanf("%d", &referenceString[m]);
    }
    printf("\n What are the total number of frames:\t");
    {
        scanf("%d", &frames);
    }
    temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for (n = 0; n < pages; ++n)
    {
        printf("Loop : %d\n", n + 1);
        int flag = 0;
        for (m = 0; m < frames; ++m)
        {
            if (temp[m] == -1)
            {
                flag = 1;
                temp[m] = referenceString[n];
                pageFaults++;
                break;
            }
            else if (temp[m] == referenceString[n])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            temp[modCounter % frames] = referenceString[n];
            modCounter++;
        }
        for (s = 0; s < frames; s++)
        {
            printf("%d\t", temp[s]);
        }
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}