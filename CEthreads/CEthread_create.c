//
// Created by duesan on 30/09/24.
//
#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "CEthread.h"
int CEthread_create(CEthreads_t *ce_thread){
    ce_thread->stack = malloc(ce_thread->stack_size);
    if (ce_thread->stack == NULL) {
        return -1;
    }
    return clone((int (*)(void *))ce_thread->start_routine, ce_thread->stack + ce_thread->stack_size,
                 CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD, ce_thread->arg);
}


