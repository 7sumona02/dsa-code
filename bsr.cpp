#include <iostream>
using namespace std;

int binarySearch(int a[], int small, int large, int x){
    int mid;
    if(small>large){
        return;
    }
    mid = (small+large)/2;
    if(a[mid]==x){
        return mid;
    } else if(a[mid]<x){
        return binarySearch(a,mid+1,large,x);
    } else{
        return binarySearch(a,small,mid-1,x);
    }
}