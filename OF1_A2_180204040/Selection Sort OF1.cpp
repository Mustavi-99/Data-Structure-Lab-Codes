#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int a[], int n)
{
    int i,j,min_index,temp;
    long long int compare=0,swa=0;;

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
    selection_sort(arr,len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time for selection sort: %lf\n",bubble_time);

}
