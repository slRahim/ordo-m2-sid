//
// Created by Abderrahim on 12/25/2022.
//

#ifndef ORD_M2_SID_INIT_CORE_H
#define ORD_M2_SID_INIT_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


#define NB_TACHE_MAX 100

int alea_entre_bornes(int min, int max);

/*---------------------------------------------------------STRUCTURES---------------------------------------------------------*/

//////////////////////////////////// task
typedef struct {
    unsigned int duration,
            due_date,
            zone_position,
            id_task;

} task_t;

/////////////////////////////////// zone
typedef struct {
    task_t tab[NB_TACHE_MAX];
    unsigned int nb_tasks,
            process_time,
            id_zone,
            id_parent_machine;

} zone_t;

/////////////////////////////////// machine
typedef struct {
    unsigned int id_machine,
            pause_duration,
            start_pause,
            end_pause;
    zone_t zone_a,
        zone_b ;

} machine_t;


//////////////////////////////////  solution

typedef struct {
    task_t* tab[NB_TACHE_MAX];
    unsigned int nb_tache;
} solution_t;

/*----------------------------------------------------------FONCTIONS----------------------------------------------------------*/

task_t *init_tab_task(int taille);

task_t init_task(unsigned int id_task, unsigned int duration, unsigned int due_date);

zone_t init_zone(unsigned int id_zone , unsigned int id_parent_machine , unsigned int nb_tasks);

machine_t init_machine(unsigned int id_machine , unsigned int pause_duration , unsigned int start_pause);

solution_t init_solution(machine_t m1, machine_t m2);

void print_tache(const task_t task);

void print_machine(const machine_t machine);

void print_zone(const zone_t zone);

void print_solution(const solution_t *sol);

void quickSort(task_t *tableau, int p, int r,bool (*fct)(task_t task1 , task_t task2) );

bool withDueDate(task_t task1,task_t task2);

#endif //ORD_M2_SID_INIT_CORE_H
