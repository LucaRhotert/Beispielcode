#include <stdio.h>

#include "Queue.h"
#include "process.h"
#include "processmodel.h"

int demo()
{
    //printf("Hello World!\n");
    queue_t q = {NULL, NULL};
    process_t p_0 = {0, READY};

    //p_switch_state(&p_0);
    //p_print(&p_0);

    process_t p_1 = {1, RUNNING};

    //p_switch_state(&p_1);
    //p_print(&p_1);

    process_t p_2 = {2, READY};

    //p_switch_state(&p_2);
    //p_print(&p_2);

    // q_node_t n0 = {NULL, &p_0};
    // q_node_t n1 = {NULL, &p_1};
    // q_node_t n2 = {NULL, &p_2};

    //p_print(q_remove(&q));
    //q_remove(&q);


    //queue_t q1 = {NULL, NULL};
    //q_print(&q1); // leere Queue

    process_t p_3 = {3, READY};
    process_t p_4 = {4, READY};
    process_t p_5 = {5, READY};
    process_t p_6 = {6, READY};
    process_t p_7 = {7, RUNNING};
    process_t p_8 = {8, RUNNING};
    process_t p_9 = {9, RUNNING};

    q_add(&q, &p_0);
    q_add(&q, &p_1);
    q_add(&q, &p_2);
    q_add(&q, &p_3);
    q_add(&q, &p_4);
    q_add(&q, &p_5);
    q_add(&q, &p_6);
    q_add(&q, &p_7);
    q_add(&q, &p_8);
    q_add(&q, &p_9);

    pcxt_t pp = {&q, &p_0};
    print(&pp);

    printf("\n\n\n");
    p_print(q_remove(&q));
    p_print(q_remove(&q));
    p_print(q_remove(&q));
    process_t p_10 = {10, READY};
    process_t p_11 = {11, READY};
    q_add(&q, &p_10);
    q_add(&q, &p_11);

    print(&pp);


    return 0;
}
