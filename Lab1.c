#include<stdio.h>
#include<stdlib.h>
#define max 5

void create();
void insert();
void delete();
void display();

int a[max],n=0;

int main()
{
    while(1)
    {
        int ch;
        printf("\nEnter Choice: 1.Create 2.Insert 3.Delete 4.Display 5.Exit\n");
        printf("Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                   break;
            case 2:insert();
                   break;
            case 3:delete();
                   break;
            case 4:display();
                   break;
            case 5:exit(0);
            default: printf("Invalid Option\n");
        }
    }
    return 0;
}

void create()
{
    printf("Enter number of elements: ");
    scanf("%d",&n);
    if(n>5)
    {
        printf("Not enough space\n");
    }
    else
    {
        printf("Enter array elements:\n");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    }
}

void display()
{
    if(n==0)
    {
        printf("Empty array\n");
    }
    else
    {
        printf("Array Elements:\n");
        for(int i=0;i<n;i++)
        {
            printf("%d. %d\t",i+1,a[i]);
        }
        printf("\n");
    }
}

void insert()
{
    if(n==max)
    {
        printf("Array is full\n");
    }
    else
    {
        printf("Enter position: ");
        int pos;
        scanf("%d",&pos);
        if(pos<1 || pos>n+1)
        {
            printf("Invalid postion\n");
        }
        else
        {
            printf("Enter element: ");
            int ele;
            scanf("%d",&ele);
            for(int i=n-1;i>=pos-1;i--)
            {
                a[i+1]=a[i];
            }
            a[pos-1]=ele;
            n++;
        }
    }
}

void delete()
{
    if(n==0)
    {
        printf("Empty Array\n");
    }
    else
    {
        printf("Enter position: ");
        int pos;
        scanf("%d",&pos);
        if(pos<1 || pos>n)
        {
            printf("Invalid postion\n");
        }
        else
        {
            for(int i=pos-1;i<n;i++)
            {
                a[i]=a[i+1];
            }
            n--;
        }
    }
}
