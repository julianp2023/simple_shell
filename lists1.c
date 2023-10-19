#include "shell.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the first node
 * @str: string to be duplicated and added as the new node's str
 * @num: integer to be added as the new node's num
 * Return: address of the new element or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_node;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    new_node->str = _strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->num = num;
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the first node
 * @str: string to be duplicated and added as the new node's str
 * @num: integer to be added as the new node's num
 * Return: address of the new element or NULL if it fails
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *last_node;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    new_node->str = _strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->num = num;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        last_node = *head;
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
    }

    return (new_node);
}

/**
 * print_list_str - prints all elements of a list_t list
 * @h: pointer to the first node
 * Return: size of the list
 */
size_t print_list_str(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }
    return (i);
}

/**
 * delete_node_at_index - deletes the node at index of a list_t list
 * @head: pointer to the first node
 * @index: index of the node to be deleted
 * Return: 1 if succeeded, -1 if failed
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    unsigned int i = 0;
    list_t *current, *prev;

    if (*head == NULL)
        return (-1);

    current = *head;

    if (index == 0)
    {
        *head = current->next;
        free(current->str);
        free(current);
        return (1);
    }

    prev = *head;

    while (current != NULL)
    {
        if (i == index)
        {
            prev->next = current->next;
            free(current->str);
            free(current);
            return (1);
        }

        prev = current;
        current = current->next;
        i++;
    }

    return (-1);
}

/**
 * free_list - frees a list_t list
 * @head_ptr: pointer to the first node
 */
void free_list(list_t **head_ptr)
{
    list_t *current, *next;

    if (*head_ptr == NULL)
        return;

    current = *head_ptr;
    while (current != NULL)
    {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }

    *head_ptr = NULL;
}

