#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"

#define MAX 100

void printTopK(Hostel arr[], int n, int k);

int main()
{
    FILE *file;
    Hostel list[MAX];
    Hostel filtered[MAX];

    int count = 0;
    int fcount = 0;

    float cgpa;
    int bedType;
    int ac;

    printf("Enter your CGPA: ");
    scanf("%f", &cgpa);

    printf("Enter bed type (1,2,3,4,6): ");
    scanf("%d", &bedType);

    printf("AC? (1 = yes, 0 = no): ");
    scanf("%d", &ac);

    file = fopen("hosteldata.txt", "r");

    if (file == NULL)
    {
        printf("Error opening hosteldata.txt\n");
        return 1;
    }

    while (fscanf(file, "%s %d %d %d",
                  list[count].block,
                  &list[count].bedType,
                  &list[count].ac,
                  &list[count].beds) != EOF)
    {
        count++;
    }

    fclose(file);

    for (int i = 0; i < count; i++)
    {
        if (list[i].bedType == bedType && list[i].ac == ac)
        {
            filtered[fcount] = list[i];

            filtered[fcount].chance =
                (list[i].beds / 248.0) * (cgpa / 10.0) * 100;

            fcount++;
        }
    }

    if (fcount == 0)
    {
        printf("No matching rooms found\n");
    }
    else
    {
        printTopK(filtered, fcount, 3);
    }

    return 0;
}