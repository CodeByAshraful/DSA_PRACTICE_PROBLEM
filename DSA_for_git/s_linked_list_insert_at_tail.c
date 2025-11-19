#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head;
void create_linked_list(int n)
{
    struct node *newNode,*tmp;
    int data,i;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("\nUnable to allocate memory");
    }
    else
    {
        int data;
        printf("\nEnter the node n.1 : ");
        scanf("%d",&data);

        newNode->data=data;
        newNode->next=NULL;

        head=newNode;
        tmp=head;
    }
    for(int i=2; i<=n; i++)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        if(newNode==NULL)
        {
            printf("\nUnable to allocate memory");
            break;
        }
        else
        {
            printf("\nEnter the node n.%d : ",i);
            scanf("%d",&data);

            newNode->data=data;
            newNode->next=NULL;

            tmp->next=newNode;
            tmp=tmp->next;

        }
    }
     printf("\n");

}
void insert_at_tail(int data)
{
    struct node*newNode,*tmp=head;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(newNode==NULL)
        printf("\nUnable to allocate memory ");

    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=newNode;

    printf("\nInserted tail successfully");

}

void print_linked_list(struct node* head)
{
    struct node*tmp=head;
    if(tmp==NULL)
    {
        printf("\nList is empty");
    }
    printf("The printed list : ");
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
}
int main()
{
    int n,data;
    printf("Enter the size of the linked list : ");
    scanf("%d",&n);
    create_linked_list(n);
    printf("Enter the inserted tail value : ");
    scanf("%d",&data);
    insert_at_tail(data);
    print_linked_list(head);

    return 0;
}


