#include <stdio.h>

int findLFU(int freq[], int temp[], int n)
{
    int i, minimum = freq[temp[0]], pos = 0;

    for (i = 1; i < n; ++i)
    {
        int z = temp[i];
        if (freq[z] < minimum && freq[z] != 0)
        {
            minimum = freq[z];
            pos = i;
        }
    }
    return pos;
}
int main()
{
    int referenceString[10], temp[100], pageFaults = 0, m, n, s, pages, freq[10], frames, counter = 0;

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
    for (m = 0; m < 10; m++)
    {

        freq[m] = 0;
    }
    for (n = 0; n < pages; ++n)
    {
        printf("\nLoop : %d\n", n + 1);
        int flag = 0;
        for (m = 0; m < frames; ++m)
        {
            if (temp[m] == -1)
            {
                flag = 1;
                temp[m] = referenceString[n];
                pageFaults++;
                freq[referenceString[n]] += 1;

                break;
            }
            else if (temp[m] == referenceString[n])
            {
                flag = 1;
                freq[referenceString[n]] += 1;
                break;
            }
        }
        if (flag == 0)
        {
            int pos = findLFU(freq, temp, frames);
            temp[pos] = referenceString[n];
            freq[referenceString[n]] += 1;
        }
        for (s = 0; s < frames; s++)
        {
            printf("%d : %d\t", temp[s], freq[temp[s]]);
        }
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}