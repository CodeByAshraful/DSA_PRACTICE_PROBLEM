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
void delete_at_any_pos(int pos)
{
  struct node* toDelete,*prevNode;
    if(head==NULL)
    printf("\nList is already empty");
    toDelete=head;
    prevNode=head;
    for(int i=1; i<=pos-1; i++)
    {
        prevNode=toDelete;
        toDelete=toDelete->next;
        if(toDelete==NULL)
            break;
    }

    if(toDelete!=NULL)
    {
        if(toDelete==head)
            head=head->next;
        prevNode->next=toDelete->next;
        toDelete->next=NULL;
        free(toDelete);
        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
    else
        printf("\nWrong Position");



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
    int n,pos;
    printf("Enter the size of the linked list : ");
    scanf("%d",&n);
    create_linked_list(n);
    printf("Enter the position you want to delete : ");
    scanf("%d",&pos);
    delete_at_any_pos(pos);
    print_linked_list(head);

    return 0;
}


