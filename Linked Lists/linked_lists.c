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

// documentation here
int list_size(const LinkedList* list)
{
    return 0;
}

// documentation here
bool add_beginning(LinkedList* list, const void* data, const size_t data_size)
{
    Node* new_node = create_node(data, data_size);

    new_node->next = list->first;
    list->first = new_node;
    return true;
}

// documentation here
bool add_end(LinkedList* list, const void* data, const size_t data_size)
{
    return false;
}

// documentation here
bool add_n(LinkedList* list, const int n, const void* data, const size_t data_size)
{
    return false;
}

// documentation here
bool remove_first(LinkedList* list)
{
    return false;
}

// documentation here
bool remove_last(LinkedList* list)
{
    return false;
}

// documentation here
bool remove_n(LinkedList* list, const int n)
{
    return false;
}

// documentation here
void* get_first(const LinkedList* list)
{
    return NULL;
}

// documentation here
void* get_last(const LinkedList* list)
{
    return NULL;
}

// documentation here
void* get_n(const LinkedList* list, const int n)
{
    return NULL;
}
