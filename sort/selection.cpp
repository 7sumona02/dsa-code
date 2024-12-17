#include <iostream>
using namespace std;

// O(n2)

void selectionsort(int a[],int n){
    int i,j,small,b;
    for(int i=0;i<n-1;i++){
        small = a[i];
        for(int j=i+1;i<n;j++){
            if(small>a[j]){
                small = a[j];
                b = j;
            }
        }
    }
}

int main(){

    return 0;
}