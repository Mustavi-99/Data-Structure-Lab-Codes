#include<bits/stdc++.h>
using namespace std;
void quick_sort(int arr[],int f,int l)
{
    if(f<l)
    {
        int i= f+1;
        int j=l;
        while(arr[i]<arr[f])
            i++;
        while(arr[j]>arr[f])
            j--;
        while(i<j)
        {
            swap(arr[i],arr[j]);
            while(arr[i]<arr[f])
                i++;
            while(arr[j]>arr[f])
                j--;
        }
        swap(arr[j],arr[f]);
        quick_sort(arr,f,j-1);
        quick_sort(arr,j+1,l);
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
    quick_sort(arr,0,len);
    for(i=0; i<len; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

