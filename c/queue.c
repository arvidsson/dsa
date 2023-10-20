#include "common.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    int length;
    Node *head;
    Node *tail;
} Queue;

void print_queue(Queue *q)
{
    Node *it = q->head;
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

Queue *new_queue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void delete_queue(Queue *q)
{
    if (q != NULL)
    {
        free(q);
        q = NULL;
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

void enqueue(Queue *q, int value)
{
    q->length++;

    Node *node = new_node(value);

    if (q->tail == NULL)
    {
        q->head = q->tail = node;
        print_queue(q);
        return;
    }

    q->tail->next = node;
    q->tail = node;

    print_queue(q);
}

int deque(Queue *q)
{
    if (q->head == NULL)
    {
        return -1;
    }

    q->length--;

    int value = q->head->value;
    Node *head = q->head;
    q->head = q->head->next;
    delete_node(head);

    print_queue(q);

    return value;
}

int peek(Queue *q)
{
    if (q->head != NULL)
    {
        return q->head->value;
    }

    return -1;
}

int main(int argc, char **argv)
{
    println("Running tests...");

    Queue *q = new_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    assert(q->length == 5);
    assert(peek(q) == 1);

    int value = deque(q);
    assert(value == 1);
    assert(q->length = 4);

    delete_queue(q);

    println("All tests passed!");
}