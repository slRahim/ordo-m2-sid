//
// Created by Abderrahim And Hamza on 12/25/2022.
//

#include "init_core.h"


int alea_entre_bornes(int min, int max) {
    return rand() % (max - min) + min;
}

/*-------------------------------------------------------INITIALISATION-------------------------------------------------------*/

task_t init_task(unsigned int id_task, unsigned int duration, unsigned int due_date) {
    task_t res;
    // affectation des champs
    res.id_task = id_task;
    res.duration = duration;
    res.due_date = due_date;

    return res;
}

zone_t init_zone(unsigned int id_zone, unsigned int id_parent_machine, unsigned int nb_tasks) {
    zone_t res;
    res.id_zone = id_zone;
    res.id_parent_machine = id_parent_machine;
    res.nb_tasks = nb_tasks;
    res.process_time = 0;

    return res;
}

machine_t init_machine(unsigned int id_machine, unsigned int pause_duration, unsigned int start_pause) {
    machine_t res;

    res.id_machine = id_machine;
    res.pause_duration = pause_duration;
    res.start_pause = start_pause;
    res.end_pause = start_pause + pause_duration;

    res.zone_a = init_zone(2 * id_machine - 1, id_machine, 0);
    res.zone_b = init_zone(2 * id_machine, id_machine, 0);


    return res;
}

task_t *init_tab_task(int taille) {
    //la taille doit au moins etre de 3 on en mets au moins 2 a 0 pour etre sur d'avoir au moins des tache avec un debut de 0
    task_t *res = (task_t *) malloc(taille * sizeof(task_t));

//    int i;
//    for (i = 0; i < 3; i++) {
//        res[i] = init_task(i + 1, alea_entre_bornes(10, 40), 0);
//    }
//    for (i = 3; i < taille; i++) {
//        res[i] = init_task(i + 1, alea_entre_bornes(10, 40), alea_entre_bornes(0, 15));
//    }

    res[0] = init_task(1, 2, 6);
    res[1] = init_task(2, 1, 3);
    res[2] = init_task(3, 1, 10);
    res[3] = init_task(4, 6, 15);
    res[4] = init_task(5, 12, 16);
    res[5] = init_task(6, 10, 20);
    res[6] = init_task(7, 4, 5);
    res[7] = init_task(8, 5, 8);
    res[8] = init_task(9, 3, 7);
    res[9] = init_task(10, 8, 11);
    res[10] = init_task(11, 1, 2);
    return res;
}

/*-------------------------------------------------------AFFICHAGE-------------------------------------------------------*/
char *stringTask(const task_t task) {
    char *res = (char *) malloc(BUFSIZ * sizeof(char));
    sprintf(
            res,
            "Task{ id : %d , duration : %d , duedate : %d , zone : %d }",
            task.id_task, task.duration, task.due_date, task.zone_position
    );
    return res;
}


char *stringZone(const zone_t zone) {
    char *res = (char *) malloc(BUFSIZ * sizeof(char));
    int i = 0;
    sprintf(
            res,
            "Zone{id : %d ,parent_machine : %d ,nb : %d ,process_time : %d, tasks[\n",
            zone.id_zone,
            zone.id_parent_machine,
            zone.nb_tasks,
            zone.process_time
    );
    for (i = 0; i < zone.nb_tasks; i++) {
        task_t *currentTask = &zone.tab[i];
        char *s_task = stringTask(*currentTask);
        strcat(res, s_task);
        strcat(res, "\n");
        free(s_task);
    }
    strcat(res, " ]}");
    return res;
}

char *stringMachine(const machine_t machine) {
    char *res = (char *) malloc(BUFSIZ * sizeof(char));
    sprintf(
            res,
            "Machine{ id : %d , pause_duration : %d , start_pause : %d , end_pause : %d ,zones[\n",
            machine.id_machine, machine.pause_duration, machine.start_pause, machine.end_pause
    );
    zone_t *zone_a = &machine.zone_a;
    zone_t *zone_b = &machine.zone_b;

    char *s_zone_a = stringZone(*zone_a);
    strcat(res, s_zone_a);
    strcat(res, "\n");
    free(s_zone_a);

    char *s_zone_b = stringZone(*zone_b);
    strcat(res, s_zone_b);
    strcat(res, "\n");
    free(s_zone_b);

    strcat(res, " ]}");

    return res;
}


void print_tache(const task_t task) {
    char *s_task = stringTask(task);
    printf("%s\n", s_task);
    free(s_task);
}

void print_machine(const machine_t machine) {
    char *s_machine = stringMachine(machine);
    printf("%s\n", s_machine);
    free(s_machine);
}

void print_zone(const zone_t zone) {
    char *s_zone = stringZone(zone);
    printf("%s\n", s_zone);
    free(s_zone);
}

void print_solution(const solution_t *sol) {
//    int i;
//    for (i = 0; i < sol->nb_tache; i++) {
//        if (i % 2 == 0) {
//            char *s_tache = stringTask(sol->tab[i]);
//            printf("Machine 1: %s\n", s_tache);
//            free(s_tache);
//        }
//
//        if (i % 2 == 1) {
//            char *s_tache = stringTask(sol->tab[i]);
//            printf("Machine 2: %s\n", s_tache);
//            free(s_tache);
//        }
//    }

}


int partitionner(task_t *tableau, int p, int r, bool (*fct)(task_t task1, task_t task2)) {
    task_t pivot = tableau[p];
    int i = p - 1, j = r + 1;
    task_t temp;
    while (1) {
        do
            j--;
        while (fct(tableau[j], pivot)); //>
        do
            i++;
        while (fct(pivot, tableau[i]));
        if (i < j) {
            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        } else
            return j;
    }
}

void quickSort(task_t *tableau, int p, int r, bool (*fct)(task_t tache1, task_t tache2)) {
    int q;
    if (p < r) {
        q = partitionner(tableau, p, r, fct);
        quickSort(tableau, p, q, fct);
        quickSort(tableau, q + 1, r, fct);
    }
}

bool withDueDate(task_t task1, task_t task2) {
    return task1.due_date > task2.due_date;
}

bool withDuration(task_t task1, task_t task2) {
    return task1.duration > task2.duration;
}

bool withDurationAndDueDate(task_t task1, task_t task2) {

    if (task2.duration == 12 && task1.duration == 10) printf("fghjkl");
    if (task1.duration > task2.duration)
        return true;
    else if (task1.duration = task2.duration) {
        if (task1.due_date > task2.due_date)
            return true;
        else return false;
    } else return false;
}




