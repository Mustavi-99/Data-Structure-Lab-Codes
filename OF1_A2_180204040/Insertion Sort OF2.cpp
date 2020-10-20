#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int arr[], int n)
{
    int i, key, j,compare=0,swa=0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            compare++;
            arr[j + 1] = arr[j];
            swa++;
            j = j - 1;
        }
        swa++;
        arr[j + 1] = key;
    }
    printf("Swap Number=%d \nComparison number= %d\n",swa,compare);
}

int main()
{
    int arr[1005];
    int max, i;
    clock_t start_time, end_time;
    double bubble_time;

    printf("Enter the Upper bound: ");
    scanf("%d", &max);

    srand(time(0));
    for(i=0;i<1000;i++)
    {
        arr[i]=rand()%max+1;
    }

    start_time = clock();
    insertion_sort(arr,1000);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time for insertion sort: %lf\n",bubble_time);

}

