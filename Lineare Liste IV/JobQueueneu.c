//
//  JobQueueneu.c
//  Lineare Liste IV
//
//  Created by Marlon Juntorius on 16.01.23.
//

#include <stdlib.h>
#include "JobQueueneu.h"
#include<stdio.h>

int pushJQ(JobQueue_t* pJQ, Job_t* pJob) {
    
    QueueEL_t* new_node = (QueueEL_t*)
    
    malloc(sizeof(QueueEL_t));
    
    new_node->job = *pJob; new_node->next = NULL;
    
    if (pJQ->first == NULL) { pJQ->first = new_node; pJQ->last = new_node; pJQ->count++;
        
        return 0;
        
    }
    
    QueueEL_t* temp = pJQ->first;
    QueueEL_t* prev = NULL;
    
    while (temp != NULL && temp->job.priority >= pJob->priority) {

        prev = temp;

        temp = temp->next; }

    if (prev == NULL) { new_node->next = pJQ->first; pJQ->first = new_node;
        
    } else
    {
        new_node->next = prev->next;

        prev->next = new_node;
        
    }

    if (new_node->next == NULL) {

    pJQ->last = new_node;
    }

    pJQ->count++;

    return 0;
    
}



Job_t popJQ(JobQueue_t* pJQ) {

    if (pJQ->first == NULL) { Job_t empty = {0, ""};

        return empty;
        
    }

    QueueEL_t* temp = pJQ->first;
    
    pJQ->first = pJQ->first->next;
    
    Job_t job = temp->job;
    
    free(temp);

    pJQ->count--; if(pJQ->first == NULL)
    {
    pJQ->last = NULL;
    }
    
    return job;
    
}


void printJQ(JobQueue_t* pJQ) { QueueEL_t* temp = pJQ->first; while (temp != NULL) {
    
    printf("Priority: %d, Description: %s\n", temp ->job.priority, temp ->job.description);
    
    temp = temp->next;
    
}
}
