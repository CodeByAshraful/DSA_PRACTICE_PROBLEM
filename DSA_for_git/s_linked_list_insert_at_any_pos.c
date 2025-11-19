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
void insert_at_any_pos(int data,int position)
{
    struct node*newNode,*tmp=head;
    newNode=(struct node*)malloc(sizeof(struct node));

    newNode->data=data;
    newNode->next=NULL;
    for(int i=1; i<position-1; i++ )
    {
        tmp=tmp->next;
        if(tmp==NULL)
            break;

    }
    if(tmp!=NULL)
    {
        newNode->next=tmp->next;
        tmp->next=newNode;
    }
    else
    {
        printf("/nUnable to insert data at given position");
    }
    printf("\nInserted data successfully");

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
    int n,data,position;
    printf("Enter the size of the linked list : ");
    scanf("%d",&n);
    create_linked_list(n);
    printf("Enter the inserted value : ");
    scanf("%d",&data);
    printf("Enter the position you want to insert: ");
    scanf("%d",&position);
    insert_at_any_pos(data,position);
    print_linked_list(head);

    return 0;
}

