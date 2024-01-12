#include "process.h"
#include <stdio.h>


int demo()
{
    process_t p_0 = {0, READY};
    p_print(&p_0);

    process_t p_1 = {1, RUNNING};
    process_t p_2 = {2, READY};

    p_switch_state(&p_1);
    p_switch_state(&p_2);
    p_print(&p_1);
    p_print(&p_2);
    return 0;
}
