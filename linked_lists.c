#include "list_tests.h"
/*
 * Function create_node
 * --------------------
 * returns a pointer to the new node containing given data
 * data: data for node to hold
 * data_size: size of data in bytes
 */
Node* create_node(const void* data, const size_t data_size)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = malloc(data_size);
    memcpy(node->data, data, data_size);
    node->next = NULL;

    return node;
}

/*
 * Function create_list
 * --------------------
 * returns a pointer to a new singly linked list
 * The head node is initialized as NULL.
 */
LinkedList* create_list()
{
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->first = NULL;
    return list;
}

/*
 * Function destroy
 * --------------------
 * frees the memory used to store a node's
 * data as well as the node itself
 * node: the node to destroy
 */
void destory(Node* node)
{
    free(node->data);
    free(node);
}

/*
 * Function get_string
 * --------------------
 * returns a char representation of the list
 * list: the linked list
 * formatter: turns the list data into a string
 */
char* get_string(const LinkedList* list, char* (*formatter) (void*))
{
    char* buffer = (char*) malloc(1024 * sizeof(char));

    if (list == NULL)
    {
        strcpy(buffer, "NULL");
        return buffer;
    }

    strcpy(buffer, "[");
    Node* current = list->first;
    while (current != NULL)
    {
        sprintf(buffer, "%s%s", buffer, formatter(current->data));

        current = current->next;
        if(current != NULL)
        {
            sprintf(buffer, "%s, ", buffer);
        }
    }
    sprintf(buffer, "%s]", buffer);

    return buffer;
}

/*
 * Function list_size
 * --------------------
 * returns the number of elements in the list
 * list: the linked list
 */
int list_size(const LinkedList* list)
{
    if(list == NULL)
    {
        return -1;
    }

    int count = 1;
    Node* current = list->first;

    if (current == NULL)
    {
        return 0;
    }

    while (current != NULL)
    {
        current = current->next;
        if(current != NULL)
        {
            count++;
        }
    }

    return count;
}

/*
 * Function add_beginning
 * --------------------
 * returns true when the new node has been added
 * to the beginning of the linked list
 * list: the linked list
 * data: data for node to hold
 * data_size: size of data in bytes
 */
bool add_beginning(LinkedList* list, const void* data, const size_t data_size)
{
    if (list_size(list) == 0)
    {
        list->first = create_node(data, data_size);
        return true;
    }

    if (list == NULL) {
        return false;
    }

    Node* new_node = create_node(data, data_size);
    new_node->next = list->first;
    list->first = new_node;
    return true;
}

/*
 * Function add_end
 * --------------------
 * returns true when the new node has been added
 * to the end of the linked list
 * list: the linked list
 * data: data for node to hold
 * data_size: size of data in bytes
 */
bool add_end(LinkedList* list, const void* data, const size_t data_size)
{
    if (list_size(list) == 0)
    {
        list->first = create_node(data, data_size);
        return true;
    }

    if (list == NULL)
    {
        return false;
    }

    Node* current = list->first;
    int count = 0;
    while (count < list_size(list) - 1)
    {
        current = current->next;
        count++;
    }

    Node* new_node = create_node(data, data_size);
    current->next = new_node;

    return true;
}

/*
 * Function add_n
 * --------------------
 * returns true when the new node has been added
 * to the nth place of the linked list
 * list: the linked list
 * n: the index of the new node
 * data: data for node to hold
 * data_size: size of data in bytes
 */
bool add_n(LinkedList* list, const int n, const void* data, const size_t data_size)
{
    if (list == NULL)
    {
        return false;
    }
    // if the size of the list is less than n
    // then add the new element to the end of the list
    if (list_size(list) < n)
    {
        add_end(list, data, data_size);
        return true;
    }

    // if the list size if 0
    // create the first node in the list
    if (list_size(list) == 0)
    {
        list->first = create_node(data, data_size);
        return true;
    }
    // if n is the first index in the list
    // or less than 0
    // add beginning
    if (n <= 0)
    {
        add_beginning(list, data, data_size);
        return true;
    }

    Node* current = list->first;
    int count = 0;

    while (count < n - 1)
    {
        current = current->next;
        count++;
    }

    Node* new_node = create_node(data, data_size);
    Node* temp = current->next; // temp pointer to the current next node
    current->next = new_node; // change the current next node pointer to the new node
    new_node->next = temp; // set the new_node pointer to the temp pointer

    return true;
}

/*
 * Function remove_first
 * --------------------
 * returns true after removing the first
 * node in the list
 * list: the linked list
 */
bool remove_first(LinkedList* list)
{
    if (list == NULL)
    {
        return false;
    }
    // get the current first node
    Node* current = list->first;
    // set the first node to the current next node
    list->first = current->next;
    // destroy the first "current" node
    destory(current);
    return true;
}

/*
 * Function remove_last
 * --------------------
 * returns true after removing the last
 * node in the list
 * list: the linked list
 */
bool remove_last(LinkedList* list)
{
    if (list == NULL)
    {
        return false;
    }

    Node* current = list->first;
    Node* previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    destory(current);
    return true;
}

/*
 * Function remove_n
 * --------------------
 * returns true after removing the nth
 * node in the list
 * list: the linked list
 * n: the index of the node to remove
 */
bool remove_n(LinkedList* list, const int n)
{
    if (list == NULL)
    {
        return false;
    }
    // if the size of the list is less than n
    // then remove_last
    if (list_size(list) < n)
    {
        remove_last(list);
        return true;
    }


    // if n is the first index in the list
    // remove_first
    if (n == 0)
    {
        remove_first(list);
        return true;
    }

    Node* current = list->first;
    int count = 0;
    Node* previous = NULL;
    while (count < n)
    {
        previous = current;
        current = current->next;
        count++;
    }

    previous->next = current->next;
    destory(current);

    return true;
}

/*
 * Function get_first
 * --------------------
 * returns the first
 * node in the list
 * list: the linked list
 */
void* get_first(const LinkedList* list)
{
    if (list == NULL)
    {
        return 0;
    }
    Node* node = list->first;
    return node->data;
}

/*
 * Function get_last
 * --------------------
 * returns the last
 * node in the list
 * list: the linked list
 */
void* get_last(const LinkedList* list)
{
    if (list == NULL)
    {
        return 0;
    }
    Node* current = list->first;
    Node* previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    return current->data;
}

/*
 * Function remove_last
 * --------------------
 * returns the nth
 * node in the list
 * list: the linked list
 * n: the node to retrieve
 */
void* get_n(const LinkedList* list, const int n)
{
    if (list == NULL)
    {
        return 0;
    }
    // if the size of the list is less than n
    // then get the last
    if (list_size(list) < n)
    {
        return get_last(list);
    }


    // if n is the first index in the list
    // get_first
    if (n <= 0)
    {
        return get_first(list);
    }

    int count = 0;
    Node* current = list->first;
    while (count < n)
    {
        current = current->next;
        count++;
    }

    return current->data;
}
