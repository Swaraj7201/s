#include<bits/stdc++.h>
using namespace std;

 
int main()
{

    const int row1=2;
    const int col1=2;
    const int row2=col1;
    const int col2=2;

    int mat1[row1][col1];
    int mat2[row2][col2];

    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++){
            mat1[i][j]= rand()%10;
        }
    }

    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++){
            mat2[i][j]= rand()%10;
        }
    }

    cout<< "Matrix 1 :"<<endl;
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++){
            cout<< mat1[i][j]<< " ";
        }
        cout<<endl;
    }

    cout<<"Matrix 2 :" << endl;
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++){
            cout<< mat2[i][j]<< " ";
        }
        cout<<endl;
    }


    cout<< "Multiplication : "<<endl;
    
    int mat3[row1][col2];

    for(int i=0; i<row1; i++){
        #pragma omp parallel for
        for(int j=0; j<col2; j++){
            mat3[i][j]=0;
            #pragma omp parallel for
            for(int k=0; k<col1; k++)
            {
                mat3[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }


    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++){
            cout<< mat3[i][j]<< " ";
        }
        cout<<endl;
    }

    


    return 0;
}