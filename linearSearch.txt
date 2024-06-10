//Linear Search:

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
int linearSearch(int *arr,int n, int ele){
    for(int i = 0;i < n;i++){
        if(arr[i] == ele)
            return i;
    }
    return -1;
}

int main(){
    int n,ele,h=100,l=0;
    cout<<endl<<"Enter size of array: ";
    cin>>n;
    int *arr = new int[n];
    clock_t start,end;
    for(int i=0;i<n;i++){
        arr[i] = rand()%(h-l+1);
    }
    cout<<"Enter element to be searched: ";
    cin>>ele;
    printArray(arr,n);
    start = clock();
    int res = linearSearch(arr,n,ele);
    if(res == -1)
        cout<<ele<<" not found"<<endl;
    else    
        cout<<ele<<" found at index "<<res<<endl;
    end= clock();
    double t;
    t = ((end-start)*1000000)/CLOCKS_PER_SEC;
    cout<<"Time taken: "<<t<<" micro second"<<endl<<endl;
}
