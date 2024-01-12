#ifndef PROCESS_H
#define PROCESS_H

/*************************/
/*      INCLUDES         */
/*************************/

#include <stdint.h>

/*************************/
/*   DEFINES AND TYPES   */
/*************************/

enum state
{
    READY,
    RUNNING
};

typedef struct process
{
    uint32_t p_id;
    enum state state_t;
} process_t;

/*************************/
/*       FUNCTIONS       */
/*************************/

void p_switch_state(struct process *p);

void p_print(struct process *p);

#endif // PROCESS_H
