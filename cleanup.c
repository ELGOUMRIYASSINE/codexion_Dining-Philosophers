#include "header.h"

void *create_node(void *ptr)
{
    t_leak* node;

    node = (t_leak *)malloc(sizeof(t_leak));
    if (!node)
        return NULL;
    node->space = ptr;
    node->next_space = NULL;
    return (node);
}

void *add_back(t_leak **tracker, t_leak *space)
{
    t_leak *current;

    current = *tracker;
    while (current->next_space)
        current = current->next_space;
    current->next_space = space;
}

void *tracked_malloc(size_t size, t_leak **tracker)
{
    void    *ptr;
    t_leak  *space;

    ptr = malloc(size);
    if (!ptr)
        return NULL;
    space = create_node(ptr);
    if (!space)
        return NULL;
    add_back(tracker, space);
    return (ptr);
}