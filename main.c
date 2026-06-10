#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Структура узла
struct point
{
    int x;
    int y;

    struct point* next;
    struct point* prev;
};

//Функции

//Добавить в голову
bool addToHead(struct point** head, int x, int y)
{
    bool res = false;

    if (head)
    {
        struct point *new_head = (struct point*)malloc(sizeof(struct point));

        if (new_head)
        {
            new_head -> x = x;
            new_head -> y = y;
            new_head -> next = *head;
            new_head -> prev = NULL;

            if (*head)
            {
                (*head) -> prev = new_head;
            }

            *head = new_head;

            res = true;
        }
    }

    return res;
}

//Добваить в хвост
bool addToTail(struct point** head, int x, int y)
{
    bool res = false;

    if (head)
    {
        struct point *new_tail = (struct point*)malloc(sizeof(struct point));

        if (new_tail)
        {
            new_tail -> x = x;
            new_tail -> y = y;
            new_tail -> next = NULL;
            new_tail -> prev = NULL;

            if (*head)
            {
                struct point *curr;

                for (curr = *head; curr -> next; curr = curr -> next);

                curr -> next = new_tail;
                new_tail -> prev = curr;
            }
            else
            {
                *head = new_tail;
            }

            res = true;
        }
    }

    return res;
}

//Вывод содержимого списка
void printList(struct point* head)
{
    if (head)
    {
        struct point *ptrIx = NULL;
        ptrIx = head;
        
        size_t i = 0;

        while (ptrIx)
        {
            printf("%d element: x = %d y = %d\n", i, ptrIx->x, ptrIx->y);
            //printf("prev = %d next = %d\n", ptrIx -> prev, ptrIx -> next);
            
            ptrIx = ptrIx -> next;
            i++;
        }
    }
    else
    {
        printf("list is empty\n");
    }
}

int main()
{
    struct point *list_head = NULL;

    printList(list_head);

    printf("\n");

    //bool check = addToHead(&list_head, 21, 23);
    //check = addToHead(&list_head, 22, 28);

    addToTail(&list_head, 45, 33);
    addToTail(&list_head, 48, 36);

    printList(list_head);

    return 0;
}