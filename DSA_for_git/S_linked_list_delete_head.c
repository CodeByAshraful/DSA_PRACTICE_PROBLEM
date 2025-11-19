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
void delete_at_head()
{
  struct node* toDelete;
    if(head==NULL)
        printf("\nList is already empty");
    toDelete=head;
    head=head->next;
    free(toDelete);
    printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");

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
    int n;
    printf("Enter the size of the linked list : ");
    scanf("%d",&n);
    create_linked_list(n);
    delete_at_head();
    print_linked_list(head);

    return 0;
}

