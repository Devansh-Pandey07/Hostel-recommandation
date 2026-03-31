#include <stdio.h>
#include "room.h"

void swap(Hostel *a, Hostel *b)
{
    Hostel temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Hostel arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left].chance > arr[largest].chance)
        largest = left;

    if (right < n && arr[right].chance > arr[largest].chance)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(Hostel arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printTopK(Hostel arr[], int n, int k)
{
    buildHeap(arr, n);

    printf("\nTop %d Hostel Options\n\n", k);

    for (int i = 0; i < k && n > 0; i++)
    {
        printf("%d. Block %s | Beds: %d | Chance: %.2f%%\n",
               i+1,
               arr[0].block,
               arr[0].beds,
               arr[0].chance);

        swap(&arr[0], &arr[n-1]);
        n--;

        heapify(arr, n, 0);
    }
}