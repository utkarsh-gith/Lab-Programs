#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int call[MAX];
int rear=-1,front=-1;

void insert()
{
        int callid;
        if(rear==MAX-1)
        {
                printf("Queue Overflow\n");
        }
        else
        {
                printf("Enter Caller ID to be added:");
                scanf("%d",&callid);
                if(rear==-1)
                {
                        front=0;
                        call[++rear]=callid;
                }
                else
                {
                        call[++rear]=callid;
                }
        }
}

void delete()
{
        if(front==-1)
        {
                printf("Queue underflow\n");
        }
        else
        {
                printf("Caller ID:%d Deleted\n",call[front++]);
                if(front>rear)
                {
                        printf("All elements deleted\nQueue Reset\n");
                        front=rear=-1;
                }
        }
}


void display()
{
        if(rear==-1)
        {
                printf("Stack Underflow");
        }
        else
        {
                int c=1;
                for(int i=front;i<=rear;i++)
                        printf("Caller ID %d:%d",c++,call[i]);
        }
}
int main()
{
        while(1)
        {
                int x;
                printf("Choose options\n");
                printf("1.Add Caller ID\n");
                printf("2.Delete Caller ID\n");
                printf("3.Display ALL CAller ID\n");
                printf("Press any other key forExit\n");
                scanf("%d",&x);
                switch(x)
                {
                        case 1: insert();
                                break;
                        case 2: delete();
                                break;
                        case 3: display();
                                break;
                        default: exit(0);
                }
        }
        return 0;

}
