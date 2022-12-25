#include <stdio.h>
#include <stdlib.h>
#include "init_core.h"
#include "heuristics.h"
#include "genetic.h"


void application() {
    int nb_tasks = 11;

    task_t *tabJob = init_tab_task(nb_tasks); //Initialiser le tableau des taches

    machine_t m1 = init_machine(1, 5, 7);
    machine_t m2 = init_machine(2, 4, 10);
    machine_t m3 = init_machine(3, 7, 17);

    solution_t s1, s2, s3, s4, s5;

    printf("\n\t------------------------------------------- HEURISTIQUE 1 -------------------------------------------\n\n");
    heuristic1(tabJob, nb_tasks);

//    creationSolution(&s1, m1.nb_tache, m2.nb_tache, &m1, &m2);
    print_solution(&s1);


    printf("\n\n\t------------------------------------------- HEURISTIQUE 2 -------------------------------------------\n\n");
    heuristic2(tabJob, nb_tasks);

//    creationSolution(&s2, m1.nb_tache, m2.nb_tache, &m1, &m2);
    print_solution(&s2);


    printf("\n\n\t------------------------------------------- HEURISTIQUE 3 -------------------------------------------\n\n");
    heuristic3(tabJob, nb_tasks);

//    creationSolution(&s3, m1.nb_tache, m2.nb_tache, &m1, &m2);
    print_solution(&s3);


    printf("\n\n\t------------------------------------------- HEURISTIQUE 4 -------------------------------------------\n\n");
    heuristic4(tabJob, nb_tasks);

//    creationSolution(&s4, m1.nb_tache, m2.nb_tache, &m1, &m2);
    print_solution(&s4);


    printf("\n\n\t------------------------------------------- Recherche locale -------------------------------------------\n\n");
    heuristic4(tabJob, nb_tasks);

//    creationSolution(&s4, m1.nb_tache, m2.nb_tache, &m1, &m2);
    print_solution(&s5);

    printf("\n\n\t-------------------------------------- ALGORITHME GENETIQUE : MUTATION --------------------------------------\n\n");

    printf("AVANT LA MUTATION :\n\n");
    print_solution(&s3);


    printf("\n\nAPRES LA MUTATION :\n\n");
    solution_t sol = mutation2(s3);
    print_solution(&sol);


    printf("\n\n\t-------------------------------------- ALGORITHME GENETIQUE : CROISEMENT --------------------------------------\n\n");
    printf("\n\nAVANT LE CROISEMENT :\n\n");
    printf("\nSOLUTION 1 :\n");
    print_solution(&s1);
    printf("\n\nSOLUTION 2 :\n");
    print_solution(&s2);

    croisement(&s1, &s2);

    printf("\n\nAPRES LE CROISEMENT :\n\n");
    printf("\nSOLUTION 1 :\n");
    print_solution(&s1);
    printf("\n\nSOLUTION 2 :\n");
    print_solution(&s2);

}

int main() {
    srand(time(NULL));
    application();
    return 0;
}