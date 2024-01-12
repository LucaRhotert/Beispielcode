#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H

/*************************/
/*        INCLUDES       */
/*************************/

#include "Queue.h"
#include "process.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

/*************************/
/*   DEFINES AND TYPES   */
/*************************/

typedef struct pctx
{
    struct queue *qready;
    struct process *running;
} pcxt_t;

/*************************/
/*       FUNCTIONS       */
/*************************/

void print(struct pctx *ctx);

void step(struct pctx *ctx);

#endif // PROCESSMODEL_H
