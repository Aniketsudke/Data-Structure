#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
struct Node *Head = NULL;

void CreateList(void)
{
    struct Node *ptr, *last;
    int x, m;
    do
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the Data :");
        scanf("%d", &m);
        ptr->Data = m;
        ptr->Next = NULL;
        if (Head == NULL)
        {
            Head = ptr;
        }
        else
        {
            last = Head;
            while (last->Next != NULL)
            {
                last = last->Next;
            }
            last->Next = ptr;
        }
        printf("Continue (0):");
        scanf("%d", &x);

    } while (x == 0);
}
void DisplayList(struct Node *p)
{

    while (p != NULL)
    {
        printf("%d \t", p->Data);
        p = p->Next;
    }
}
void SearchList(struct Node *p, int key)
{
    int Flag = 0;
    while (p != NULL)
    {
        if (key == p->Data)
        {
            Flag = 1;
            break;
        }
        p = p->Next;
    }
    if (Flag == 1)
    {
        printf("Data is Found");
    }
    else
    {
        printf("Data is not Found");
    }
}
void InsertList(struct Node *p, int place, int element)
{
    struct Node *x;// Temp Variable
    x = p;
    int count = 1;
    while (p != NULL)
    {
        if (count == place)// Count the Node that we check.
        {
            struct Node *New; // Create a New Node to Store the new Data
            New = (struct Node *)malloc(sizeof(struct Node));
            New->Data = element;
            x->Next = New; // New Node Address Store inside the Privous Node 
            New->Next = p; //Place position Node Address given to the New Node
        }
        x = p;
        p = p->Next;
        count ++;
    }
}
void DeleteList(struct Node *p, int key)
{
    struct Node *x;
    x = p;
    while (p != NULL)
    {
        if (key == p->Data)
        {
            x->Next = p->Next;
            p->Next = NULL;
            free(p);
            break;
        }
        x = p;
        p = p->Next;
    }
}
int main()
{
    struct Node *temp;
    int key,place;
    CreateList();
    DisplayList(Head);
    printf("Key :");
    scanf("%d", &key);
    printf("Place :");
    scanf("%d",&place);
    // SearchList(Head,key);
    // DeleteList(Head,key);
    InsertList(Head,place,key);
    DisplayList(Head);
    return 0;
}