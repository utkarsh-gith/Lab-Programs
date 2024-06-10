//Binary Search(Iterative & Recursive):

#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;

int iBinarySearch(vector<int> num, int n, int ele){
    int low = 0, high = n-1, mid;
    while(low<=high){
        mid = low + (high - low)/2;
        if(num[mid] == ele){
            return mid;
        }
        else if(num[mid] < ele){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

int rBinarySearch(vector<int> num, int low, int high ,int ele){
    if(low<=high){
        int mid =  low + (high - low)/2;
        if(num[mid] == ele)
            return mid;
        else if(num[mid] < ele){
            return rBinarySearch(num,mid+1,high,ele);
        }
        else{
            return rBinarySearch(num,low,mid-1,ele);
        }
    }
    return -1;
}

int main(){
    vector<int> num;
    int n, ele, res;
    clock_t start1, start2, end1, end2;
    double t1,t2;

    n= 1000;
    for(int i = 0;i < 1000;i++){
        num.push_back(i+1);
    }

    cout<<endl<<"Enter element to be searched: ";
    cin>>ele;

    start1 = clock();
    res = iBinarySearch(num,n,ele);
    if(res == -1)
        cout<<ele<<" not found"<<endl;
    else    
        cout<<ele<<" found at index "<<res<<endl;
    end1 = clock();
    t1 = ((end1-start1)*1000000)/CLOCKS_PER_SEC;
    cout<<"Time taken for iterative Binary Search: "<<t1<<" micro second"<<endl;

    start2 = clock();
    res = rBinarySearch(num,0,n-1,ele);
    if(res == -1)
        cout<<ele<<" not found"<<endl;
    else    
        cout<<ele<<" found at index "<<res<<endl;
    end2 = clock();
    t2 = ((end2-start2)*1000000)/CLOCKS_PER_SEC;
    cout<<"Time taken for recursive Binary Search: "<<t2<<" micro second"<<endl<<endl;

    return 0;
}
