#include<stdio.h>
#include<stdlib.h>

int binarysearch(int arr[], int low, int high, int key)
{
        if(low<=high)
        {
                        int mid=(low+high)/2;
                        if(arr[mid]==key)
                        {
                                return mid;
                        }
                        else if(arr[mid]>key)
                        {
                                return binarysearch(arr,low,mid-1,key);
                        }
                        else if(arr[mid]<key)
                        {
                                return binarysearch(arr,mid+1,high,key);
                        }

        }
        return -1;

}

int main()
{
        int a[10],n,key,res;
        printf("Enter number of elements:");
        scanf("%d",&n);
        printf("Enter array elements\n");
        for(int i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        printf("Enter key to be searched:");
        scanf("%d",&key);
        res=binarysearch(a,0,n-1,key);
        if(res==-1)
        {
                printf("Element not found");
        }
        else
        {
                printf("%d found at index %d",key,res);
        }
        return 0;
}
