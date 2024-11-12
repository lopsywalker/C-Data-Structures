#include <stdio.h>
#include <stdlib.h>

/* Struct for individual linked list nodes */
typedef struct list_node 
{
/* Struct pointer needs to have explicit name */ 
struct list_node* next_node;
void *value_ptr;
// int value;
char type[8] = NULL;
} list_node_t;


/**
 * \brief Creates a new node for linked list
 */
struct list_node* new_list_node(void *value, char type[])
{
    /*
     If head does not exist, make new node head
     if head does exist move pointer
     change values of new nodes being made.
     */
    struct list_node* newNode = malloc(sizeof(list_node_t));
    newNode->value_ptr  = malloc(sizeof(value));
    newNode->type = type;
    newNode->next_node = NULL;
    return newNode;
}

/**
 * \brief Adds node to list linked to the given head pointer
 * \param head node head that you want to add a node to
 * \param append node that you want added to the list
 */
void add_to_list(struct list_node* head, struct list_node* append)
{
    if (head->next_node == NULL) 
    {
        head->next_node = append;
    }

    else
    {
        struct list_node* current_node = head; 
        while(current_node != NULL)
        {
            current_node = current_node->next_node;
        }
        current_node->next_node = append;
        append->next_node = NULL;
    }
}

void iterate(struct list_node* list_node)
{
    while(list_node != NULL) 
    {
        printf("%s\n", list_node->value_ptr);
        // TODO: Dereferencing void pointers
        list_node = list_node->next_node;
    }
}

int main()
{
    // Example stuff
struct list_node* new_node = new_list_node(5);
struct list_node* new_node_1 = new_list_node(3);
add_to_list(new_node, new_node_1);
iterate(new_node);

return 0;
}