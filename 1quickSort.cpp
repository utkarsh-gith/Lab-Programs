//QuickSort

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void printArray(int *arr,int n){
    cout<<endl<<"Array Elements:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}

int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int *arr,int low, int high){
    if(low<high){
        int partionIndex = partition(arr,low,high);

        quickSort(arr,low,partionIndex-1);
        quickSort(arr,partionIndex+1,high);
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
    quickSort(arr,0,n-1);
    end= clock();

    printArray(arr,n);

    double t;
    t = ((end-start)*1000000)/CLOCKS_PER_SEC;
    cout<<"Time taken: "<<t<<" micro second"<<endl<<endl;

    return 0;
}
