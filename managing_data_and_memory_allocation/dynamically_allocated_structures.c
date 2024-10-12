#include <stdio.h>
#include <stdlib.h>
/*Types*/
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    int count;
    Node *head;
} LinkedList;

/*Definitions*/
LinkedList *init_linked_list();
void destroy_linked_list(LinkedList *);
void print_linked_list(LinkedList *);
void print_node(Node *);
void insert_node(LinkedList *, int);
void remove_node(LinkedList *, Node *);

int main(int argc, char *argv[])
{

    LinkedList *my_list = init_linked_list();
    if (!my_list)
    {
        return 1;
    }

    insert_node(my_list, 1);
    print_linked_list(my_list);

    insert_node(my_list, 2);
    print_linked_list(my_list);

    insert_node(my_list, 3);
    print_linked_list(my_list);

    insert_node(my_list, 4);
    print_linked_list(my_list);

    remove_node(my_list, my_list->head->next);
    print_linked_list(my_list);

    destroy_linked_list(my_list);

    return 0;
}

LinkedList *init_linked_list()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list != NULL)
    {
        list->count = 0;
        list->head = NULL;
    }
    return list;
}

void destroy_linked_list(LinkedList *list)
{
    if (list == NULL)
    {
        return;
    }
    Node *current = list->head;
    while (current != NULL)
    {
        Node *next = current->next;
        remove_node(list, current);
        current = next;
    }
    // Free Linked List memory
    free(list);
    printf("List Destroyed.\n");
}