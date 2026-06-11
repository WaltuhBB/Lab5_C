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

//Добавление на позицию
bool addAtPos(struct point** head, int x, int y, size_t pos)
{
    bool res = false;

    if (head)
    {
        struct point *new_el = (struct point*)malloc(sizeof(struct point));

        if (new_el)
        {
            new_el -> x = x;
            new_el -> y = y;
            new_el -> next = NULL;
            new_el -> prev = NULL;
            
            if (*head)
            {
                struct point *curr;
                size_t i = 0;

                for (curr = *head; curr -> next && i != pos; curr = curr -> next)
                {
                    i++;
                }

                if (i == pos)
                {
                    if (i == 0)
                    {
                        new_el -> next = *head;
                        (*head) -> prev = new_el;
                        *head = new_el;
                    }
                    else
                    {
                        new_el -> next = curr;
                        new_el -> prev = curr -> prev;
                        
                        curr -> prev -> next = new_el;
                        curr -> prev = new_el;
                    }

                    res = true;
                }
                else
                {
                    //curr -> next = new_el;
                    //new_el -> prev = curr;

                    free(new_el);
                    res = false;
                }
            }
            else
            {
                *head = new_el;

                res = true;
            }

            //res = true;
        }
    }

    return res;
}

//Добавить до узла
bool addBefore(struct point** head, int x, int y, int x_data, int y_data)
{
    bool res = false;

    if (head)
    {
        struct point *new_el = (struct point*)malloc(sizeof(struct point));

        if (new_el)
        {
            new_el -> x = x;
            new_el -> y = y;
            new_el -> next = NULL;
            new_el -> prev = NULL;

            if (*head)
            {
                struct point *curr;

                for (curr = *head; curr -> next && !(curr -> x == x_data && curr -> y == y_data); curr = curr -> next);

                if (curr -> x == x_data && curr -> y == y_data)
                {
                    if (curr == *head)
                    {
                        new_el -> next = *head;
                        (*head) -> prev = new_el;
                        *head = new_el;
                    }
                    else
                    {
                        new_el -> next = curr;
                        new_el -> prev = curr -> prev;
                        
                        curr -> prev -> next = new_el;
                        curr -> prev = new_el;
                    }
                    
                    res = true;
                }
                else
                {
                    free(new_el);
                }
            }
            else
            {
                free(new_el);
            }
        }
    }

    return res;
}

//Добавить после узла
bool addAfter(struct point** head, int x, int y, int x_data, int y_data)
{
    bool res = false;

    if (head)
    {
        struct point *new_el = (struct point*)malloc(sizeof(struct point));

        if (new_el)
        {
            new_el -> x = x;
            new_el -> y = y;
            new_el -> next = NULL;
            new_el -> prev = NULL;

            if (*head)
            {
                struct point *curr;

                for (curr = *head; curr -> next && !(curr -> x == x_data && curr -> y == y_data); curr = curr -> next);

                if (curr -> x == x_data && curr -> y == y_data)
                {
                    if (curr -> next == NULL)
                    {
                        curr -> next = new_el;
                        new_el -> prev = curr;
                    }
                    else
                    {
                        new_el -> prev = curr;
                        new_el -> next = curr -> next;

                        curr -> next -> prev = new_el;
                        curr -> next = new_el;
                    }
                    
                    res = true;
                }
                else
                {
                    free(new_el);
                }
            }
            else
            {
                free(new_el);
            }
        }
    }

    return res;
}

//Поиск узла
struct point* find(struct point* head, int x, int y)
{
    struct point *res = NULL;

    if (head)
    {
        struct point *curr;

        for (curr = head; curr -> next && !(curr -> x == x && curr -> y == y); curr = curr -> next);

        if (curr -> x == x && curr -> y == y)
        {
            res = curr;
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

//Удаление головы
void delHead(struct point** head)
{
    if (head && *head)
    {
        struct point *tmp = *head;
        
        if (tmp -> next == NULL)
        {
            *head = NULL;
        }
        else
        {
            *head = tmp -> next;
            (*head) -> prev = NULL;
        }

        free(tmp);
    }
}

//Удаление хвоста
void delTail(struct point** head)
{
    if (head && *head)
    {
        struct point *curr;

        for (curr = *head; curr -> next; curr = curr -> next);

        if (curr -> prev == NULL)
        {
            *head = NULL;
        }
        else
        {
            curr -> prev -> next = NULL;
        }

        free(curr);
    }
}

//Удаление по позиции
void delAtPos(struct point** head, size_t pos)
{
    if (head && *head)
    {
        struct point *curr;
        size_t i = 0;

        for (curr = *head; curr -> next && i < pos; curr = curr -> next)
        {
            i++;
        }

        if (i == pos)
        {
            if (i == 0)
            {
                struct point *tmp = *head;
        
                if (tmp -> next == NULL)
                {
                    *head = NULL;
                }
                else
                {
                    *head = tmp -> next;
                    (*head) -> prev = NULL;
                }

                free(tmp);
            }
            else
            {
                curr -> prev -> next = curr -> next;

                if (curr -> next != NULL)
                {
                    curr -> next -> prev = curr -> prev;
                }

                free(curr);
            }
        }

    }
}

//Удаление по данным
void delNode(struct point** head, int x, int y)
{
    if (head && *head)
    {
        struct point *curr;
    
        for (curr = *head; curr -> next && !(curr -> x == x && curr -> y == y); curr = curr -> next);

        if (curr -> x == x && curr -> y == y)
        {
            if (curr -> prev == NULL)
            {
                struct point *tmp = *head;
            
                if (tmp -> next == NULL)
                {
                    *head = NULL;
                }
                else
                {
                    *head = tmp -> next;
                    (*head) -> prev = NULL;
                }

                free(tmp);
            }
            else
            {
                curr -> prev -> next = curr -> next;

                if (curr -> next != NULL)
                {
                    curr -> next -> prev = curr -> prev;
                }

                free(curr);
            }
        }
    }
}


int main()
{
    struct point *list_head = NULL;

    printList(list_head);

    printf("\n");

    addToHead(&list_head, 21, 23);
    addToHead(&list_head, 22, 28);

    addToTail(&list_head, 45, 33);
    addToTail(&list_head, 48, 36);

    addAtPos(&list_head, 124, 155, 0);
    //addAtPos(&list_head, 124, 155, 2);
    //addAtPos(&list_head, 124, 155, 100);

    //addBefore(&list_head, 403, 408, 124, 155);
    //addBefore(&list_head, 403, 408, 21, 23);
    addBefore(&list_head, 403, 408, 48, 36);

    //addAfter(&list_head, 1000, 903, 124, 155);
    //addAfter(&list_head, 1000, 903, 21, 23);
    addAfter(&list_head, 1000, 903, 48, 36);
    
    //printList(find(list_head, 124, 155));
    //printList(find(list_head, 45, 33));
    //printList(find(list_head, 1000, 903));
    //printList(find(list_head, 334874987, 12954376));

    //printList(list_head);

    //printf("\n");

    //delHead(&list_head);
    //delTail(&list_head);

    //delAtPos(&list_head, 0);
    //delAtPos(&list_head, 3);
    //delAtPos(&list_head, 6);

    //delNode(&list_head, 124, 155);
    //delNode(&list_head, 45, 33);
    //delNode(&list_head, 1000, 903);

    printList(list_head);

    return 0;
}