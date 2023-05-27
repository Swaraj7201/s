// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<omp.h>
#include<time.h>

using namespace std;

int partition(vector<int> &arr, int s, int e){
    int pivot = arr[s];

    int cnt=0;

    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    int pivot_index = s + cnt;
    swap(arr[s], arr[pivot_index]);

    int i=s;
    int j=e;

    while(i<pivot_index && j > pivot_index)
    {
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<pivot_index && j > pivot_index){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivot_index;

}


void quickSort(vector<int> &arr, int s, int e)
{
    if(s>=e) {
        return;
    }

    int p = partition(arr, s, e);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            quickSort(arr, s, p-1);
        }
        #pragma omp section
        {
            quickSort(arr, p+1, e);
        }
    }



}
 
int main()
{
    vector<int> arr={8,9,7,2,3,1,4,5};
    int n=8;

    clock_t start = clock();

    quickSort(arr, 0, n-1);

    clock_t end = clock();

    for(int i=0; i<n; i++)
    {
        std::cout<<arr[i]<<" , ";
    }
    
    std::cout<< endl <<"time is : "<< end - start;
    return 0;
}