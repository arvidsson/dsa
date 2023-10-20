#include "common.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Stack
{
    int length;
    Node *head;
} Stack;

void print_stack(Stack *s)
{
    Node *it = s->head;
    printf("[");
    while (it)
    {
        printf("%d", it->value);
        if (it->next)
        {
            printf(", ");
        }
        it = it->next;
    }
    printf("]\n");
}

Stack *new_stack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->length = 0;
    s->head = NULL;
    return s;
}

void delete_stack(Stack *s)
{
    if (s != NULL)
    {
        free(s);
        s = NULL;
    }
}

Node *new_node(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void delete_node(Node *node)
{
    if (node != NULL)
    {
        free(node);
        node = NULL;
    }
}

void push(Stack *s, int value)
{
    s->length++;

    Node *node = new_node(value);

    if (s->head == NULL)
    {
        s->head = node;
        print_stack(s);
        return;
    }

    Node *head = s->head;
    s->head = node;
    s->head->next = head;

    print_stack(s);
}

int pop(Stack *s)
{
    if (s->head == NULL)
    {
        return -1;
    }

    s->length--;

    int value = s->head->value;
    Node *head = s->head;
    s->head = s->head->next;
    delete_node(head);

    print_stack(s);

    return value;
}

int peek(Stack *s)
{
    if (s->head != NULL)
    {
        return s->head->value;
    }

    return -1;
}

int main(int argc, char **argv)
{
    println("Running tests...");

    Stack *s = new_stack();

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);

    assert(s->length == 5);
    assert(peek(s) == 5);

    int value = pop(s);
    assert(value == 5);
    assert(s->length = 4);

    delete_stack(s);

    println("All tests passed!");
}