#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX],top=-1,i;

void push();
void pop();
void palindrome();
void display();

int main()
{
        int ch=1;
        while(ch>0 && ch<5)
        {
                printf("Enter Choice\n");
                printf("1.Push\n");
                printf("2.Pop\n");
                printf("3.Check Palindrome\n");
                printf("4.Display Stack\n");
                printf("5.Exit\n");
                printf("\nEnter Choice:");
                scanf("%d",&ch);
                printf("\n");
                switch(ch)
                {
                        case 1: push();
                                break;
                        case 2: pop();
                                break;
                        case 3: palindrome();
                                break;
                        case 4: display();
                                break;
                        case 5: ch=5;
                                break;
                        default: printf("Invalid Choice\n\n");
                                 ch=1;
                }
        }
        return 0;
}
