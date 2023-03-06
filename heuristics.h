//
// Created by Abderrahim And Hamza on 12/25/2022.
//

#ifndef ORD_M2_SID_HEURISTICS_H
#define ORD_M2_SID_HEURISTICS_H

#include "init_core.h"

void heuristic1(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t machines[NB_MACHINE_MAX], unsigned int size_m,
                zone_t zone_retard);

void heuristic2(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t machines[NB_MACHINE_MAX], unsigned int size_m,
                zone_t zone_retard);

void heuristic3(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t machines[NB_MACHINE_MAX], unsigned int size_m,
                zone_t zone_retard);

void heuristic4(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t machines[NB_MACHINE_MAX], unsigned int size_m,
                zone_t zone_retard);

void initDurations(int cM[3][2], machine_t machines[NB_MACHINE_MAX], int size_m);

void localSearch(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t m1, machine_t m2, machine_t m3,
                 zone_t zone_retard);

#endif //ORD_M2_SID_HEURISTICS_H
