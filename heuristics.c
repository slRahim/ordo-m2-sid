//
// Created by Abderrahim on 12/25/2022.
//

#include "heuristics.h"

char *stringTas(const task_t task) {
    char *res = (char *) malloc(BUFSIZ * sizeof(char));
    sprintf(
            res,
            "Tache[ id : %d , duration : %d , duedate : %d ]",
            task.id_task, task.duration, task.due_date
    );
    return res;
}

void heuristic1(task_t tab[NB_TACHE_MAX], unsigned int size , machine_t m1 , machine_t m2 , machine_t m3, zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDueDate);

    for (int i = 0; i <size ; i=i+3) {
        if(m1.zone_a.process_time+tab[i].duration<=m1.start_pause){

        }else{
            if(m2.zone_a.process_time+tab[i].duration<=m2.start_pause){

            }else{
                if(m3.zone_a.process_time+tab[i].duration<=m3.start_pause){

                }else{
//                    start of zone B








                }
            }
        }


        if(tab[i].due_date >= (m1.zone_a.process_time+tab[i].duration)){
            m1.zone_a.tab[i]=tab[i];
        }else{

        }

        m2.zone_a.tab[i]=tab[i+1];
        m3.zone_a.tab[i]=tab[i+2];
    }



    zone_retard.tab[0]=tab[3];
    zone_retard.nb_tasks=1;

    print_machine(m1);
//    print_machine(m2);
//    print_machine(m3);

//    print_zone(zone_retard);



//   print tab after edd sort
//    char *res = (char *) malloc(BUFSIZ * sizeof(char));
//    int i = 0;
//    sprintf(
//            res,
//            "EDD[ \n");
//    for (i = 0; i < size; i++) {
//        task_t *currentTask = &tab[i];
//        char *s_task = stringTas(*currentTask);
//        strcat(res, s_task);
//        strcat(res, "\n");
//        free(s_task);
//    }
//    strcat(res, " ]");
//
//    char* txt = res;
//    printf("%s\n" , txt);
}


void heuristic2(task_t tab[NB_TACHE_MAX], unsigned int size,machine_t m1,machine_t m2,machine_t m3 , zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDueDate);

    print_machine(m1);



}


void heuristic3(task_t tab[NB_TACHE_MAX], unsigned int size,machine_t m1,machine_t m2,machine_t m3 , zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDueDate);

}


void heuristic4(task_t tab[NB_TACHE_MAX], unsigned int size,machine_t m1,machine_t m2,machine_t m3 , zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDueDate);

}

void localSearch(task_t tab[NB_TACHE_MAX], unsigned int size,machine_t m1,machine_t m2,machine_t m3 , zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDueDate);

}
