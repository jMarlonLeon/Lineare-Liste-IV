//
//  main.c
//  Lineare Liste IV
//
//  Created by Marlon Juntorius on 16.01.23.
//

#include <stdio.h>
#include "JobQueueneu.h"



int main(int argc, const char * argv[]) {
    //zwei leere Queues vom Typ JobQueue_t definieren
    
    JobQueue_t jobQueue_1 = { "Queue1", 0 };
    JobQueue_t jobQueue_2 = { "Queue2", 0 };
    
    // 5 neue Jobs (also Job- Objekte erstellen)
    
    Job_t Job_1 = {10, "Essen gehen"};
    Job_t Job_2 = {5, "Lesen"};
    Job_t Job_3 = {20, "Zähne putzen"};
    Job_t Job_4 = {30, "Schlafen"};
    Job_t Job_5 = {100, "Lernen"};
    Job_t ReturnJob = {0,""};
    
    
    // Job- Objekte in die JobQueue_q laden via unserer PushJQ- funktion
    pushJQ(&jobQueue_1,  &Job_1);
    //auf die Addresse von jobQueue_1 mit '&'  verweisen. Danach Job- Objekt 'Job_x' mit '&' zuweisen ( Addresse an Addresse zusweisen)

    pushJQ(&jobQueue_1,  &Job_2);
    
    pushJQ(&jobQueue_1,  &Job_3);
    
    pushJQ(&jobQueue_2,  &Job_4);
    
    pushJQ(&jobQueue_2,  &Job_5);
    

    // Ausgeben des Inhalts unserer Queue mithilfe der von uns implementierten Funkion 'printJQ(''&''JobQueue')'
    printJQ(&jobQueue_1);
    
  
    // Ausgeben des Inhalts unserer Queue mithilfe der von uns implementierten Funkion 'printJQ(''&''JobQueue')'
    printJQ(&jobQueue_2);
    
    
    // Herauslösen eines Elements aus einer JobQueue mithilfe der von uns implementierten Funktion Job_x = 'popJq(''&''JobQueue'')'
    

    ReturnJob = popJQ(&jobQueue_1);
    printf("\nElement (%s)  aus JobQueue1 geloescht: \n", ReturnJob.description);
    // Überprüfung der Operation popJQ für Job_3 mihilfe der Ausgabe der Funktion "printJQ)"
    printf("%d, %s \n", ReturnJob.priority, ReturnJob.description );
    
    printf("\nElemente JobQueue1:");
    // Ausgabe der Anzahle der Elemente in jobQueue_1
    printf("\n%d \n", jobQueue_1.count);
    
}

