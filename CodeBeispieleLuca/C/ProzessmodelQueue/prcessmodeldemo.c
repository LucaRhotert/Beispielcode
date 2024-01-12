#include <stdio.h>
#include <unistd.h>

#include "Queue.h"
#include "process.h"
#include "processmodel.h"


int main()
{

    queue_t q = {NULL, NULL};

    process_t p_0 = {0, RUNNING};
    process_t p_1 = {1, READY};
    process_t p_2 = {2, READY};
    process_t p_3 = {3, READY};
    process_t p_4 = {4, READY};
    process_t p_5 = {5, READY};
    process_t p_6 = {6, READY};
    process_t p_7 = {7, READY};
    process_t p_8 = {8, READY};
    process_t p_9 = {9, READY};


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


    while (true)
    {
        print(&pp);
        step(&pp);
        sleep(1);
    }

    return 0;
}
