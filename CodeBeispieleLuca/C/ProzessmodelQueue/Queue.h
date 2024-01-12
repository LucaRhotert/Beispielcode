#ifndef QUEUE_H
#define QUEUE_H

/*************************/
/*      INCLUDES         */
/*************************/

#include "process.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

/*************************/
/*   DEFINES AND TYPES   */
/*************************/

typedef struct q_node
{
    struct q_node *next;
    struct process *p;
} q_node_t;

typedef struct queue
{
    q_node_t *start;
    q_node_t *end;
} queue_t;

/*************************/
/*       FUNCTIONS       */
/*************************/

void q_add(struct queue *q, struct process *p);

struct process *q_remove(struct queue *q);

void q_print(queue_t *queue);

#endif // QUEUE_H
