/*
 * File:   main.c
 * Author: 
 * Brief:  Exercices pour le cours 316. Recherche dans un tableau.
 *         Trouver le bon nip. Met en ordre
 * Created on 1 novembre 2017, 09:42
 */


#include <xc.h>
#include <stdbool.h>
#include <string.h> //pour strcmp 
#include <stdlib.h> // pour rand
#include <stdio.h> // pour sprintf
 
/********* Prototypes ********/
bool verifNip(int index, char *leNip);
int trouveAQui(char* leNip);
long essaisNip(void);
void metEnOrdre(void);
 
/***********constantes *******/
#define NB_USAGER 10
#define _XTAL_FREQ 1000000 //Constante utilisée par __delay_ms(x). Doit = fréq interne du uC
 
const char g_nip[NB_USAGER][5] = 
{
    "1234", "9327", "9460", "0022", "9848",
    "0482", "9999", "5288", "1114", "1195",
};
char g_nipEnOrdre[NB_USAGER][5];
 
void main(void) 
{
 
    char s1[10];
    char s2[] = "Allo";
    strcpy(s1,s2); //copie la chaine de caractères s2 dans la chaine s1. Donc s1 = Allo 
 
    int test = 0; //variable pour les tests des exercices
    int usager = 1;
    char sonNip[] = "0022";
    long nbEssais = 0;
 
    //No 1 : Vérifie si le nip entré est bon (no usager et son nip)
    usager = 1;
    if (verifNip(usager,sonNip))
        test = 1;
 
    //No 2: Trouve le no d'usager à qui appartient le nip. Retourne -1 si aucun
    usager = trouveAQui(sonNip);
 
    //No 3; Choisi un nip au hasard et compte combien d'essaie avant de trouver un nip parmi la liste
    //nbEssais = essaisNip();
 
 
    //No 4: Met en ordre dans g_nipEnOrdre
    metEnOrdre();
    test = 0;
 
 
 
}
 
//No 1
bool verifNip(int index, char *leNip)
{
    if (strcmp (g_nip[index],leNip) == 0 )
        return true;
    else
        return false;
 
}
 
//No 2
int trouveAQui(char* leNip)
{
    int retour = -1;
    int i=0;
 
    do
    {
        if (strcmp (g_nip[i],leNip)==0)
            retour = i;
        i++;
    }while (i < NB_USAGER);
 
    return retour;
}
 
//No 3
long essaisNip(void)
{ 
 
    int essais = 0;
    int nipHasard = 0;
    char leNip[5];
 
    //Pour du vrai hasard... , on doit rajouter ces lignes. 
    //Ne fonctionne pas en mode simulateur.
    //T1CONbits.TMR1ON = 1;
    //srand(TMR1);  
    do
    {
        nipHasard = abs(rand())  % 10000; //on veut un nombre positif entre 0 et 9999
        sprintf(leNip, "%04d", nipHasard); //on convertit nipHasard en tableau de byte. Min 4 digits et 0 en avant au besoin
        leNip[4]='\0';
        if (trouveAQui(leNip) != -1)
            return essais;
        essais++;
    }
    while (essais < (long)1000); //1000x est déjà très long
 
    return essais;
}

/**
 * @brief no 4 Copie tous les nip du tableau g_nip dans le tableau g_nipEnOrdre et met tout les les nip en ordre croissant
 * @param 
 * @return Aucun
 */
void metEnOrdre(void)
{
    char temp = 0;
    for(int i = 0; i < NB_USAGER; i++ )
    {
        for(int j = 0; j < 5; j++)
        {
            temp = g_nip[i][j];
            g_nipEnOrdre[i][j] = temp;
            temp = 0;
        }
    }
}
