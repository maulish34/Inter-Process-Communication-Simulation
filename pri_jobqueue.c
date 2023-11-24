/*
 * Replace the following string of 0s with your student number
 * 000000000
 */
#include <stdlib.h>
#include <stdbool.h>
#include "pri_jobqueue.h"
#include <stdio.h>

/* 
 * TODO: you must implement this function that allocates a job queue and 
 * initialise it.
 * Hint:
 * - see job_new in job.c
 */
pri_jobqueue_t* pri_jobqueue_new() {

    pri_jobqueue_t* job_queue = (pri_jobqueue_t *) malloc(sizeof(pri_jobqueue_t));

    if(!job_queue){
        return NULL;
    }

    pri_jobqueue_init(job_queue);

    return job_queue;
}

/* 
 * TODO: you must implement this function.
 */
void pri_jobqueue_init(pri_jobqueue_t* pjq) {

    pjq->size = 0;
    pjq->buf_size=JOB_BUFFER_SIZE;

    for(int i = 0; i < JOB_BUFFER_SIZE; i++){
        job_init(&pjq->jobs[i]);
    }

    return;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 *      - if a queue is not empty, and the highest priority job is not in the 
 *      last used slot on the queue, dequeueing a job will result in the 
 *      jobs on the queue having to be re-arranged
 *      - remember that the job returned by this function is a copy of the job
 *      that was on the queue
 */
job_t* pri_jobqueue_dequeue(pri_jobqueue_t* pjq, job_t* dst) {
    if(pri_jobqueue_is_empty(pjq)){
        return NULL;
    }

    int highestPriorityIdx = 0;
    int currentJobPriority;

    for(int i = 0; i < JOB_BUFFER_SIZE; i++){
        currentJobPriority = pjq->jobs[i].priority;
        if(pjq->jobs[i].priority && currentJobPriority != 0 && currentJobPriority < pjq->jobs[highestPriorityIdx].priority){
            highestPriorityIdx = i;
        }
    }

    if(!dst){
        dst = (job_t*) malloc(sizeof(job_t));
        if(!dst){
            return NULL;
        }
    }

    job_copy(&(pjq->jobs[highestPriorityIdx]), dst);
    job_init(&(pjq->jobs[highestPriorityIdx]));
    pjq->size--;
    return dst;
}

/* 
 * TODO: you must implement this function.
 * Hints:
 * - if a queue is not full, and if you decide to store the jobs in 
 *      priority order on the queue, enqueuing a job will result in the jobs 
 *      on the queue having to be re-arranged. However, it is not essential to
 *      store jobs in priority order (it simplifies implementation of dequeue
 *      at the expense of extra work in enqueue). It is your choice how 
 *      you implement dequeue (and enqueue) to ensure that jobs are dequeued
 *      by highest priority job first (see pri_jobqueue.h)
 * - remember that the job passed to this function is copied to the 
 *      queue
 */
void pri_jobqueue_enqueue(pri_jobqueue_t* pjq, job_t* job) {
    if((pri_jobqueue_is_full(pjq) || !job || job->priority == 0)){
        return;
    }

    job_copy(job, &(pjq->jobs[pri_jobqueue_size(pjq)]));
    pjq->size++;

    return;
}
   
/* 
 * TODO: you must implement this function.
 */
bool pri_jobqueue_is_empty(pri_jobqueue_t* pjq) {
    if(!pjq || pjq->size == 0){
        return true;
    }

    return false;
}

/* 
 * TODO: you must implement this function.
 */
bool pri_jobqueue_is_full(pri_jobqueue_t* pjq) {

    if(!pjq || pjq->size >= 128){
        return true;
    }


    return false;
}

/* 
 * TODO: you must implement this function.
 * Hints:
 *      - remember that the job returned by this function is a copy of the 
 *      highest priority job on the queue.
 *      - both pri_jobqueue_peek and pri_jobqueue_dequeue require copying of 
 *      the highest priority job on the queue
 */
job_t* pri_jobqueue_peek(pri_jobqueue_t* pjq, job_t* dst) {
    if(pri_jobqueue_is_empty(pjq)){
        return NULL;
    }

    int highestPriorityIdx = 0;
    int currentJobPriority;

//    int countInitialised = 0;
//    for(int j = 0; j < JOB_BUFFER_SIZE; j++){
//        if(pjq->jobs[j].priority){
//            countInitialised++;
//        }
//    }
//    printf("=============================\n");
//    printf("Total initialised jobs: %d, JOB BUFF SIZE: %d, LIST SIZE: %d\n", countInitialised, JOB_BUFFER_SIZE, pjq->buf_size);
//    printf("=============================\n");


    for(int i = 0; i < JOB_BUFFER_SIZE; i++){
        currentJobPriority = pjq->jobs[i].priority;
        if(pjq->jobs[i].priority && currentJobPriority != 0 && currentJobPriority < pjq->jobs[highestPriorityIdx].priority){
            highestPriorityIdx = i;
        }
    }

    if(!dst){
        dst = (job_t*) malloc(sizeof(job_t));
        if(!dst){
            return NULL;
        }
    }

    job_copy(&(pjq->jobs[highestPriorityIdx]), dst);
//    job_init(&(pjq->jobs[highestPriorityIdx]));
    return dst;
}

/* 
 * TODO: you must implement this function.
 */
int pri_jobqueue_size(pri_jobqueue_t* pjq) {
    if(!pjq){
        return 0;
    } else{
        return pjq->size;
    }
}

/* 
 * TODO: you must implement this function.
 */
int pri_jobqueue_space(pri_jobqueue_t* pjq) {
    if(!pjq) {
        return 0;
    }

    return pjq->buf_size - pjq->size;

}

/* 
 * TODO: you must implement this function.
 *  Hint:
 *      - see pri_jobqeue_new
 */
void pri_jobqueue_delete(pri_jobqueue_t* pjq) {

    if (pjq) {
        free(pjq);
    }

    return;
}
