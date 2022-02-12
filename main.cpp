#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};

struct Node* ListedLink;

struct Node* yeniDugum(int data)
{
  struct Node* link = (struct Node*)malloc(sizeof(struct Node));
  link->data = data;
  link->next = NULL;
  return(link);
}

bool isNumberExist(int data)
{
  struct Node* temp = ListedLink;
  while(temp != NULL)
  {
    if(temp->data == data)
      return true;
    temp = temp->next;
  }
  return false;
}

int findLenght()
{
    int sayac = 0;
    struct Node* temp = ListedLink;
    while(temp != NULL)
    {
        sayac++;
        temp = temp->next;
    }
    return sayac;
}

void Reverse()
{
    struct Node* previousLink = NULL;
    struct Node* currentLink = ListedLink;
    struct Node* nextLink = NULL;

    while(currentLink != NULL)
    {
        nextLink = currentLink->next;
        currentLink->next = previousLink;

        previousLink = currentLink;
        currentLink = nextLink;
    }
    ListedLink = previousLink;
}

void removeFromAnywhere(int data){
    if(ListedLink == NULL)
        return;
    if(ListedLink->next == NULL && ListedLink->data == data)
        ListedLink = NULL;
    else
    {
        if(ListedLink->data == data)
        {
            if(ListedLink->next == NULL)
                ListedLink = NULL;
            else
            {
                struct Node* secondLink = ListedLink->next;
                ListedLink = secondLink;
            }
            return;
        }
        struct Node* temp = ListedLink;
        while(temp->next->data != data && temp != NULL)
            temp = temp->next;
        if(temp == NULL)
            return;
        if(temp->next->next == NULL && temp->next->data == data)
            if(ListedLink != NULL && ListedLink->next == NULL)
                ListedLink = NULL;
            else
            {
                struct Node* temp = ListedLink;
                while(temp->next->next != NULL)
                    temp = temp->next;
                free(temp->next);
                temp->next = NULL;
            }
        else
        {
            struct Node* integerForDelete = temp->next;
            struct Node* baglanacakEleman = integerForDelete->next;
            temp->next = baglanacakEleman;
            free(integerForDelete);
        }
    }
}

void insertAsLast(int data)
{
    struct Node* newLink = yeniDugum(data);
    if(ListedLink == NULL)
    {
        ListedLink = newLink;
        return;
    }
    else
    {
        struct Node* temp = ListedLink;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newLink;
    }

}

void insertAsFirst(int data)
{
    struct Node* newLink = yeniDugum(data);
    if(ListedLink == NULL)
        ListedLink = newLink;
    else
    {
        struct Node* temp = ListedLink;
        ListedLink = newLink;
        ListedLink->next = temp;
    }

}

void Menu()
{
    int choose, input;
    printf("\n[1] Insert As First");
    printf("\n[2] Insert As Last");
    printf("\n[3] Remove From Anywhere");
    printf("\n[4] Reverse");
    printf("\n[5] Find Lenght");
    printf("\nChoose:");
    scanf("%d", &choose);
    switch(choose)
    {
        case 1:
            printf("\nInput:");
            scanf("%d", &input);
            if(isNumberExist(input))
                printf("\nNumber is exists");
            else
                insertAsFirst(input);
            break;
        case 2:
            printf("\nInput:");
            scanf("%d", &input);
            if (isNumberExist(input))
                printf("\nNumber is exists");
            else
                insertAsLast(input);
            break;
        case 3:
            printf("\n Input:");
            scanf("%d", &input);
            if (isNumberExist(input))
                removeFromAnywhere(input);
            else
                printf("\nNumber is not exists");
            break;
        case 4:
            Reverse();
            break;
        case 5:
            input = findLenght();
            printf("Lenght: %d\n", input);
            break;
        default:
            printf("\nWrong choose!");
            break;
    }
    printf("\n");
    struct Node* temp = ListedLink;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    while(1)
        Menu();
}

