#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    for(int i=0; i<n; i++)
    {   
        #pragma omp parallel for
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
 
int main()
{
    vector<int> arr = {6,5,4,3,2,1,7};
    int n=7;

    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();

    for(int i=0; i<n; i++)
    {
        cout<< arr[i]<<" , ";
    }
    
    cout<<endl<<"time req is :" << end-start;

    return 0;
}