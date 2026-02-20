#include<iostream>
using namespace std;

void matrixpointer(int mat[][4],int n,int m){
    cout<<mat<<endl;//points to first row
    cout<<*mat<<"="<<mat[0][0]<<endl;
     cout<<mat+1<<"="<<mat[0][1]<<endl;


    cout<<"0 row pointer="<<mat<<endl;     //&mat[0]
    cout<<"1 row pointer="<<(mat+1)<<endl;//&mat[1]
    cout<<"2 row pointer="<<mat+2<<endl;  //&mat[2]
    
    cout<<"0 row first element="<<*mat<<endl;//* dereference decays to the pointer mat to array pointer points to first element of array mat[0][0] int[0]
    cout<<"0 row second element="<<*mat+1<<endl;//address of &mat[0][1]
    cout<<"0 row third element="<<*mat+2<<endl;//address of &mat[0][2]
    //decays the mat into inside pointer(array) by dereference that also pointer of array
     cout<<*mat<<endl;//points to the first element address &mat[0][0]
    cout<<*(mat+1)<<endl;//points to the first element address &mat[1][0]
        cout<<*(mat+2)<<endl;
     //now dereferencing the array pointer that gives the value

     cout<<**mat<<endl;
     cout<<*(*(mat)+1)<<endl;
     cout<<*(*(mat)+2)<<endl;
     cout<<**(mat+1)<<endl;
       
     cout<<*(*(mat+1)+1)<<endl;// *(*(row)+column)
     cout<<*(*(mat+1)+2)<<endl;
     cout<<*(*(mat+1)+3)<<endl;
}

int main(){
    int mat[3][4]={{1,11,3,4},
               {5,6,7,8},
               {9,10,11,12}};
    matrixpointer(mat,3,4);

return 0;

}