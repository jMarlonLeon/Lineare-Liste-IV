//
//  JobQueueneu.h
//  Lineare Liste IV
//
//  Created by Marlon Juntorius on 16.01.23.
//

#ifndef JobQueueneu_h
#define JobQueueneu_h

#include <stdio.h>

typedef struct{
    
    int priority;
    char description[100];
    
} Job_t;


typedef struct QueueEL {
    
    Job_t job;
    struct QueueEL* next;
    
} QueueEL_t;


typedef struct {
    
    char name[100];
    QueueEL_t* first;
    QueueEL_t* last;
    int count;
    
} JobQueue_t;


int pushJQ (JobQueue_t *pJQ, Job_t *pJob);

Job_t popJQ (JobQueue_t *pJQ);

void printJQ (JobQueue_t *pJQ);


#endif /* JobQueueneu_h */
