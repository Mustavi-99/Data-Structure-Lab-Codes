#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int p, int q, int r);

void merge_sort(int arr[], int p, int r)
{
    if (p < r)
    {

        int q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);

        merge(arr, p, q, r);
    }
}
void merge(int arr[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;

    int L[n1+1], R[n2+1];

    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + j+1];
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    i = 0;
    j = 0;
    for(k = p; k<=r; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }



}
int main()
{

    int len, i;
    printf("Enter Array Length: ");
    scanf("%d", &len);
    int arr[len];
    srand(time(0));
    for(i=0; i<len; i++)
    {
        arr[i]=rand()%50;
    }

    merge_sort(arr,0,len);
    for(i=0; i<len; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

