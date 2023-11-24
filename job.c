/*
 * Replace the following string of 0s with your student number
 * 220451374
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job.h"


/* 
 * DO NOT EDIT the job_new function.
 */
job_t* job_new(pid_t pid, unsigned int id, unsigned int priority, 
    const char* label) {
    return job_set((job_t*) malloc(sizeof(job_t)), pid, id, priority, label);
}

/* 
 * TODO: you must implement this function
 */
job_t* job_copy(job_t* src, job_t* dst) {

    if(!src){
        return NULL;
    }
    if(strlen(src->label) != (MAX_NAME_SIZE-1)){
        return NULL;
    }
    if(src == dst){
        return dst;
    }
    if(!dst) {
        dst = (job_t *) malloc(sizeof(job_t));
        if (dst == NULL)
            return NULL;
    }

    dst->pid = src->pid;
    dst->id = src->id;
    dst->priority = src->priority;
    strncpy(dst->label, src->label, MAX_NAME_SIZE-1);
    dst->label[MAX_NAME_SIZE-1] = '\0';
    return dst;

}

/* 
 * TODO: you must implement this function
 */
void job_init(job_t* job) {
    if(job){
        job->pid = 0;
        job->id = 0;
        job->priority = 0;
        strcpy(job->label, PAD_STRING);
    }
}

/*
 * TODO: you must implement this function
 */
bool job_is_equal(job_t* j1, job_t* j2) {
    if(j1 == NULL && j2 == NULL){
        return true;
    }
    if(!j1 || !j2){
        return false;
    }
    if(j1 == j2){
        return true;
    }
    bool comparePid = j1->pid==j2->pid;
    bool compareId = j1->id==j2->id;
    bool comparePriority = j1->priority==j2->priority;
    int compareResult = strcmp(j1->label, j2->label);

    if(comparePid && compareId && comparePriority && (compareResult == 0)){
        return true;
    }
    return false;
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - read the information in job.h about padding and truncation of job
 *      labels
 */
job_t* job_set(job_t* job, pid_t pid, unsigned int id, unsigned int priority,
    const char* label) {

    if(!job){
        return job;
    }
    job->pid = pid;
    job->id = id;
    job->priority = priority;

    if(label == NULL || ((strlen(label)) == 0)){
        strcpy(job->label, PAD_STRING);
    } else{
        int expectedLen = MAX_NAME_SIZE - 1;
        int labelLength = (strlen(label)-1);
        if(expectedLen == labelLength){
            strcpy(job->label, label);
            job->label[MAX_NAME_SIZE-1] = '\0';
        } else if(labelLength < expectedLen){
            strcpy(job->label, PAD_STRING);
            strncpy(job->label, label, strlen(label));
            job->label[MAX_NAME_SIZE-1] = '\0';
        } else if(labelLength > expectedLen){
            strncpy(job->label, label, MAX_NAME_SIZE-1);
            job->label[MAX_NAME_SIZE-1] = '\0';
        }
    }
    return job;
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - see malloc and calloc system library functions for dynamic allocation, 
 *      and the documentation in job.h for when to do dynamic allocation
 */
char* job_to_str(job_t* job, char* str) {
    if(!job){
        return NULL;
    }
    if(strlen(job->label) != (MAX_NAME_SIZE-1)){
        return NULL;
    }
    if(!str){
        str = (char *)malloc(sizeof(char) * JOB_STR_SIZE);
    }
    snprintf(str, JOB_STR_SIZE, JOB_STR_FMT, job->pid, job->id, job->priority, job->label);
    str[JOB_STR_SIZE] = '\0';
//    printf("JOB TO STR: %s\n", str);
    return str;
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - see the hint for job_to_str
 */
job_t* str_to_job(char* str, job_t* job) {
    if(!str || ((strlen(str)) != (JOB_STR_SIZE-1))) {
        return NULL;
    }

    if(!job){
        job = (job_t*) malloc(sizeof(job_t));
        if(!job){
            return NULL;
        }
    }

    int numPassedValues = sscanf(str, JOB_STR_FMT,(int*) &job->pid, &job->id, &job->priority, job->label);
    job->label[MAX_NAME_SIZE] = '\0';
    if((strlen(job->label)) != (MAX_NAME_SIZE-1)){

        return NULL;
    }
//    printf("ARGUMENTS PASSED WHILE CONVERSION: %d\n", numPassedValues);
    if(numPassedValues == 4){
        return job;
    } else{
        job_delete(job);
    }
    return NULL;
}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look at the allocation of a job in job_new
 */
void job_delete(job_t* job) {
    if(job){
        free(job);
    }
    return;
}