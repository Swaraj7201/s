#include <iostream>
#include <vector>
#include <omp.h>
#include <time.h>
using namespace std;

void merge(vector<int> &arr, int s, int mid, int e){
    int len1 = mid-s+1;
    int len2 = e - mid;

    vector<int> L;
    vector<int> R;

    for(int i=0; i<len1; i++)
    {
        L.push_back(arr[s+i]);
    }

    for(int j=0; j<len2; j++)
    {
        R.push_back(arr[mid+1+j]);
    }

    int i=0;
    int j=0;
    int k=s;
    while(i<len1 && j<len2)
    {
        if(L[i] < R[j])
        {
            arr[k]=L[i];
            i++;
            k++;
        }else{
            arr[k]=R[j];
            j++;
            k++;
        }
    }

    while(i<len1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<len2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }

}



void mergeSort(vector<int> &arr, int s , int e)
{
    if(s>=e){
        return;
    }

    int mid = s + (e-s)/2;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
             mergeSort(arr, s , mid);

        }
        #pragma omp section
        {
            mergeSort(arr, mid+1, e);

        }
    }
        merge(arr, s, mid, e);
}
 
int main()
{   
    vector<int> arr;
    int n=100;

    for(int i=0; i<n; i++)
    {
        int el = rand() % 200;
        arr.push_back(el);
    }

    clock_t start = clock();
    
    mergeSort(arr, 0, n-1);

    clock_t end = clock();


    
    for(int i=0; i<n; i++)
    {
        cout<< arr[i] << " , ";
    }

    cout<< endl << "running time is :" << end - start;
    return 0;
}