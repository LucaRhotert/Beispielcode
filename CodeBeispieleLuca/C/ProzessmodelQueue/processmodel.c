#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "process.h"
#include "processmodel.h"

void print(struct pctx *ctx)
{
    q_print(ctx->qready);
    puts("");
    p_print(ctx->running);
    puts("\n");
}

void step(struct pctx *ctx)
{
    p_switch_state(ctx->running);

    q_add(ctx->qready, ctx->running);

    ctx->running = q_remove(ctx->qready);
    p_switch_state(ctx->running);
}
