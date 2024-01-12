#include "Queue.h"
#include "process.h"
#include <stdio.h>

int demo()
{
    process_t p_0 = {0, RUNNING};
    process_t p_1 = {1, READY};
    process_t p_2 = {2, READY};


    queue_t q = {NULL, NULL};
    q_print(&q);

    q_add(&q, &p_0);
    q_add(&q, &p_1);
    q_add(&q, &p_2);
    q_print(&q);

    p_print(q_remove(&q));
    q_print(&q);

    return 0;
}
