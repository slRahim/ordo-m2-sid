//
// Created by Abderrahim on 12/25/2022.
//

#include "genetic.h"

void croisement(solution_t* sol1, solution_t* sol2){

    int taille = sol1->nb_tache;
    int alea;
    int j = 0;
    solution_t temp = *sol1;

    alea = alea_entre_bornes(2,taille-2);
    printf("alea : %d\n",alea);
    for(j = alea;j<taille;j++){
        sol1->tab[j] = sol2->tab[j];
        sol2->tab[j]=temp.tab[j];
    }

}

solution_t mutation2 ( solution_t solution){
    solution_t  resultat ;
    int rand  = alea_entre_bornes(2,solution.nb_tache/2 - 1 ) ;
    int i,j = rand ;
    int k = 0;

    for ( i=rand+1 ; i < solution.nb_tache ; i++ ){
        task_t a  = solution.tab[rand] ;
        task_t b = solution.tab[i] ;
//        if(i%2 == rand%2){
//            if((b.date_debut <= a.date_debut) && (b.duree >= a.duree)){
//                resultat = solution ;
//                resultat.sommePonderee = 0;
//                resultat.tab[rand] = b ;
//                resultat.tab[rand].date_fin = resultat.tab[rand-2].date_fin + resultat.tab[rand].duree;
//                resultat.tab[i] = a ;
//                for(j=rand; j<solution.nb_tache; j+=2){
//                    resultat.tab[j].date_fin = resultat.tab[j-2].date_fin + resultat.tab[j].duree;
//                }
//                for(k = 0; k < resultat.nb_tache; k++){
//                    resultat.sommePonderee += resultat.tab[k].date_fin * resultat.tab[k].poids;
//                }
//                return resultat ;
//            }else{
//                printf("mutation impossible");
//                return solution;
//            }
//
//        }
    }
}
