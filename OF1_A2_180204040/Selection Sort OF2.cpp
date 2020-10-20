#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int a[], int n)
{
    int i,j,min_index,temp,compare=0,swa=0;;

    for(i=0;i<n-1;i++)
    {
        min_index = i;
        for(j=i+1;j<n;j++)
        {
            compare++;
            if(a[j]<a[min_index])
            {
                min_index = j;
            }
        }
        if(min_index!=i)
        {
            temp = a[min_index];
            a[min_index]=a[i];
            a[i] = temp;
            swa++;
        }
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
    selection_sort(arr,1000);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time for selection sort: %lf\n",bubble_time);

}


