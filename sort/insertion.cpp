#include <iostream>
using namespace std;

void insertionsort(int a[],int n){
    int i,j,num;
    for(int i=1;i<n;i++){
        num = a[i];
        for(int j=i-1;j>=0;j--){
            if(a[j]>num){
                a[j+1] = a[j];
            } else{
                break;
            }
            a[j+1] = num;
        }
    }
}

int main(){

    return 0;
}