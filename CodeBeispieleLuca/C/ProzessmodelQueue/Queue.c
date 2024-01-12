#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "process.h"


void q_add(struct queue *q, struct process *p)
{
    // Speicher Resavieren mit malloc
    q_node_t *node = (q_node_t *)malloc(sizeof(q_node_t));

    node->next = NULL;
    node->p = p;


    if (NULL == q->start)
    {
        q->start = node;
    }
    else
    {
        q->end->next = node;
    }

    q->end = node;
    q->end->next = NULL;
}

struct process *q_remove(struct queue *q)
{
    if (NULL == q)
    {
        return NULL;
    }

    if (NULL == q->start)
    {
        return NULL;
    }

    struct process *pro = q->start->p;
    struct q_node *freeme = q->start;
    q->start = q->start->next;

    free(freeme);
    return pro;
}

void q_print(queue_t *queue)
{
    if (NULL == queue)
    {
        return;
    }

    //printf("\nQueue contains elements with a capacity of .\n");

    if (NULL == queue->start)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    else
    {
        printf("\n\nQueue contains:\n");
        q_node_t *current = queue->start;

        while (NULL != current)
        {
            p_print(current->p);
            current = current->next;
        }
    }
}
