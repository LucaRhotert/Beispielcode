#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"


void p_switch_state(struct process *p)
{
    switch (p->state_t)
    {
    case READY:
        p->state_t = RUNNING;
        break;

    case RUNNING:
        p->state_t = READY;
        break;

    default:
        break;
    }
}

void p_print(struct process *p)
{
    if (p->state_t == RUNNING)
    {
        printf("Process ID: %d, State: RUNNING\n", p->p_id);
    }
    else
    {
        printf("Process ID: %d, State: READY\n", p->p_id);
    }
}
