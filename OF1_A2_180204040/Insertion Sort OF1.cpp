#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    long long int compare=0,swa=0;
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
    printf("Swap Number=%lld \nComparison number= %lld\n",swa,compare);
}

int main()
{
    int arr[500005];
    int len, i;
    clock_t start_time, end_time;
    double bubble_time;

    printf("Enter Array Length: ");
    scanf("%d", &len);

    srand(time(0));
    for(i=0;i<len;i++)
    {
        arr[i]=rand()%100+1;
    }

    start_time = clock();
    insertion_sort(arr,len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time for insertion sort: %lf\n",bubble_time);

}
