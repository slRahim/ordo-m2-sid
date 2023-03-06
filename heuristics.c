//
// Created by Abderrahim And Hamza on 12/25/2022.
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

void initDurations(int cM[3][2], machine_t machines[NB_MACHINE_MAX], int size_m) {
    int k;
    for (k = 0; k < size_m; ++k) {
        cM[k][0] = 0;
        cM[k][1] = machines[k].end_pause;
    }
}

void heuristic1(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t machines[NB_MACHINE_MAX], unsigned int size_m,
                zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDueDate);

    int cM[3][2];
    initDurations(cM, machines, size_m);

    int i, c = 0;

    for (i = 0; i < size; i++) {
        if (tab[i].duration + cM[c][0] <= machines[c].start_pause && tab[i].duration + cM[c][0] <= tab[i].due_date) {
            tab[i].zone_position = c + 1;
            cM[c][0] += tab[i].duration;
        } else if (tab[i].duration + cM[c][1] <= 24 && tab[i].duration + cM[c][1] <= tab[i].due_date) {
            tab[i].zone_position = (c + 1) * 2;
            cM[c][1] += tab[i].duration;
        } else tab[i].zone_position = size_m * 2 + 1;
        if (++c > 2)
            c = 0;
    }
    // TODO : print Tasks
}


void heuristic2(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t machines[NB_MACHINE_MAX], unsigned int size_m,
                zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDueDate);
    int i, j, l;

    int cM[3][2];
    initDurations(cM, machines, size_m);

    bool zone;

    for (i = 0; i < size; i++) {
        zone = false;
        for (l = 0; l < size_m; l++) {
            if (tab[i].duration + cM[l][0] <= machines[l].start_pause &&
                tab[i].duration + cM[l][0] <= tab[i].due_date) {
                tab[i].zone_position = l + 1;
                cM[l][0] += tab[i].duration;
                zone = true;
                break;
            } else if (tab[i].duration + cM[l][1] <= 24 && tab[i].duration + cM[l][1] <= tab[i].due_date) {
                tab[i].zone_position = (l + 1) * 2;
                cM[l][1] += tab[i].duration;
                zone = true;
                break;
            }
        }
        if (!zone) tab[i].zone_position = size_m * 2 + 1;
    }
    // TODO : print Tasks
}

void heuristic3(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t machines[NB_MACHINE_MAX], unsigned int size_m,
                zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDuration);
    quickSort(tab, 0, size - 1, withDurationAndDueDate);


    int taille = size / size_m;
    if (size % size_m > 0)
        taille++;
    int tailles[size_m];
    int i, l;
    for (i = 0; i < size_m; ++i) {
        if (i < size_m - 1)
            tailles[i] = taille;
        else tailles[i] = taille - ((size / size_m) - (size % size_m));
    }
    task_t **tasks = (task_t **) malloc(size_m * sizeof(task_t *));
    for (i = 0; i < size_m; ++i) {
        tasks[i] = (task_t *) malloc(tailles[i] * sizeof(task_t));
    }
    //affectations
    int k, c = 0, n = 0;
    for (i = 0; i < size; i++) {
        tasks[c][n] = tab[i];
        c++;
        if (c == 3) {
            c = 0;
            n++;
        }
    }

    for (k = 0; k < size_m; ++k) {
        quickSort(tasks[k], 0, tailles[k] - 1, withDueDate);
    }

    int cM[3][2];
    initDurations(cM, machines, size_m);

    for (i = 0; i < size_m; i++) {
        for (l = 0; l < tailles[i]; ++l) {
            if (tasks[i][l].duration + cM[i][0] <= machines[i].start_pause &&
                tasks[i][l].duration + cM[i][0] <= tasks[i][l].due_date) {
                tasks[i][l].zone_position = i + 1;
                cM[i][0] += tasks[i][l].duration;
            } else if (tasks[i][l].duration + cM[i][1] <= 24 &&
                       tasks[i][l].duration + cM[i][1] <= tasks[i][l].due_date) {
                tasks[i][l].zone_position = (i + 1) * 2;
                cM[i][1] += tasks[i][l].duration;
            } else tasks[i][l].zone_position = size_m * 2 + 1;
        }

    }
    //TODO : affectation zone in tab

    // TODO : print Tasks
}


void heuristic4(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t machines[NB_MACHINE_MAX], unsigned int size_m,
                zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDuration);
    quickSort(tab, 0, size - 1, withDurationAndDueDate);


    int taille = size / size_m;
    if (size % size_m > 0)
        taille++;
    int tailles[size_m];
    int i;
    for (i = 0; i < size_m; ++i) {
        if (i < size_m - 1)
            tailles[i] = taille;
        else tailles[i] = taille - ((size / size_m) - (size % size_m));
    }
    task_t **tasks = (task_t **) malloc(size_m * sizeof(task_t *));
    for (i = 0; i < size_m; ++i) {
        tasks[i] = (task_t *) malloc(tailles[i] * sizeof(task_t));
    }
    //affectations
    int k, c = 0;

    for (k = 0; k < size_m; ++k) {
        for (int l = 0; l < tailles[k]; ++l) {
            tasks[k][l] = tab[c];
            c++;
        }
        quickSort(tasks[k], 0, tailles[k] - 1, withDueDate);
    }
    int l;
    int cM[3][2];
    initDurations(cM, machines, size_m);
    for (i = 0; i < size_m; i++) {
        for (l = 0; l < tailles[i]; ++l) {
            if (tasks[i][l].duration + cM[i][0] <= machines[i].start_pause &&
                tasks[i][l].duration + cM[i][0] <= tasks[i][l].due_date) {
                tasks[i][l].zone_position = i + 1;
                cM[i][0] += tasks[i][l].duration;

            } else if (tasks[i][l].duration + cM[i][1] <= 24 &&
                       tasks[i][l].duration + cM[i][1] <= tasks[i][l].due_date) {
                tasks[i][l].zone_position = (i + 1) * 2;
                cM[i][1] += tasks[i][l].duration;
            } else tasks[i][l].zone_position = size_m * 2 + 1;
        }
    }

    //TODO : affectation zone in tab

    // TODO : print Tasks
}

void
localSearch(task_t tab[NB_TACHE_MAX], unsigned int size, machine_t m1, machine_t m2, machine_t m3, zone_t zone_retard) {
    quickSort(tab, 0, size - 1, withDueDate);

}
