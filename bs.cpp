#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int x){
    int small = 0;
    int large = n-1;

    while(small<=large){
        int mid = (small+large)/2;

        if(a[mid]==x){
            return mid;
        } else if(a[mid]<x){
            small = mid+1;
        } else{
            large = mid-1;
        }
    }
    return -1;
}