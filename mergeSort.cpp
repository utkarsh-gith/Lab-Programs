//MergeSort

#include<iostream>
#include<cstdlib>
using namespace std;

void printArray(int *arr,int n){
    cout<<endl<<"Array Elements:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}

void merge(int *arr, int low,int mid, int high){

    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *arr1 = new int [n1];
    int *arr2 = new int [n2];
    
    for(int i=0;i<n1;i++){
        arr1[i] = arr[low + i];
    }
    for(int j=0;j<n2;j++){
        arr2[j] = arr[mid + 1 + j];
    }
    
    int i=0,j=0,k=low;

    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }
    while(i<n1){
        arr[k++] = arr1[i++];
    }
    while(j<n2){
        arr[k++] = arr2[j++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *arr, int low, int high){
    if(low<high){
        int mid = low + (high - low)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid +1, high);

        merge(arr , low , mid, high);
    }
}

int main(){
    int n,h=1000,l=0;

    cout<<endl<<"Enter size of array: ";
    cin>>n;

    int *arr = new int[n];
    clock_t start,end;

    for(int i=0;i<n;i++){
        arr[i] = rand()%(h-l+1);
    }

    printArray(arr,n);

    start = clock();
    mergeSort(arr,0,n-1);
    end= clock();

    printArray(arr,n);

    double t;
    t = ((end-start)*1000000)/CLOCKS_PER_SEC;
    cout<<"Time taken: "<<t<<" micro second"<<endl<<endl;

    return 0;
}
