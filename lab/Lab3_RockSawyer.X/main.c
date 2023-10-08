 /**
 * @file   main.c, projet Lab1
 * @author 
 * @date   
 * @brief    
 * @version 1.0
 * Environnement:
 *     Développement: MPLAB X IDE (version 6.05)
 *     Compilateur: XC8 (version 2.40)
 *     Matériel: Carte démo du Pickit4. PIC 18F45K20
 */

#include <xc.h>
#include <stdbool.h>  // pour l'utilisation du type bool
#include "serie.h"


#define _XTAL_FREQ 1000000 //Constante utilisée par __delay_ms(x). Doit = fréq interne du uC
//#define LIGNE true
//#define COLONNE false
#define GAUCHE 0
#define HAUT 1
#define DROITE 2
#define BAS 3
#define FLECHE_G 'A'
#define FLECHE_H 'W'
#define FLECHE_D 'D'
#define FLECHE_B 'S'
#define NBLIGNE 5
#define NBCOLONNE 5
#define PORT_COLONNE PORTC
//#define PORT_LIGNE PORTB

void initialisation(void); //fonction qui initialise le pic
//void afficheDe(int chiffre, int deGouD);    //fonction affichant le dé
void setDel(int ligne, int colonne);   //fct qui affiche la DEL 
//void
void testMatrice(void);
/*bool deplace(int sens, int* ptrLigne, int* ptrColonne);
void affichePerdu(void);
void getSens(int *nouveauSens);*/

void main(void)
{
    initialisation();
    testMatrice();
    /*int sens;
    int ligne;
    int colonne;*/
    /*int L = 3;
    int C = 2;
    setDel(L, C);*/
    //PORTB = 0b00000010;
    //PORTC = 0b11111100;
    //PORTB = 8;
    //PORTC = 246;
            
                 
    NOP();
   
    
    
    while(1) //boucle principale
    {   
        
        /*int i = 0;
        int j = 0;
        for(i=0; i<5 ;i++)  //1re boucle qui brasse le dé de gauche
        {
            
            //setDel(i, a);
            __delay_ms(500);
            
        
            for(j=0; j<5; j++)  //2e boucle pour le dé de droite
            {
                setDel(i, j);
                __delay_ms(500);
            }
           
        }*/    
            
        //PORTDbits.RD7 = PORTDbits.RD7 ^ 1; //On change l'état de la DEL 0
        //__delay_ms(300); //pour laisser le temps de voir la DEL à son nouvel état
        
        
     }
}


/**
 * @brief Initialisation des différents regesitres du PIC
 * @param Aucun
 * @return Aucun
 */
void initialisation(void)
{
    TRISB = 0; //Tout le port B en sortie
    TRISC = 0; //tout le port C en sotie

    //Attention! 
    ANSELH = 0;  // RB0 à RB4 en mode digital. Sur 18F45K20 AN et PortB sont sur les memes broches
    //TRISB = 0xFF; //tout le port B en entree
   
    PORTB = 0; //DEL du port B tous éteintes
    PORTC = 1; //DEL du port C tous éteintes
}

/**
 * @brief affiche secantiellement les valeur de 1 a 6 pour chacun des de
 * @param int chiffre qui affiche le chiffre de 1 a 6
 * @param int deGouD qui selectionne le de de droite ou de gauche
 * @return Aucun
 */
/*void afficheDe(int chiffre, int deGouD)
{
    int tableauDe[6] = {7,11,3,10,2,8};
    
    PORTC = tableauDe[chiffre];
    PORTDbits.RD0 = deGouD;
    
    
}*/

/**
 * @brief affiche secantiellement chaque DEL de la matrice
 * @param int ligne qui sera la serie de DEL sur l'axe des x
 * @param int colonne qui sera la série de DEL sur l'axe des y
 * @return Aucun
 */
void setDel(int ligne, int colonne)
{
    //int tempLi = 0;
    //int tempCo = 0;
    int tableauLi[6] = {0, 0b10, 0b100, 0b1000, 0b10000, 0b100000};
    int tableauCo[6] = {0,0b11111100, 0b11111010, 0b11110110, 0b11101110, 0b11011110};
    
    
    
    PORTB = tableauLi[ligne];
    PORTC = tableauCo[colonne];
    //PORTDbits.RD0 = deGouD;
}

/**
 * @brief affiche secantiellement chaque DEL de la matrice
 * @param int ligne qui sera la serie de DEL sur l'axe des x
 * @param int colonne qui sera la série de DEL sur l'axe des y
 * @return Aucun
 */

void testMatrice(void)
{
    for (int i = 1; i < 6; i++)
    {
        __delay_ms(300);
        for (int j = 1; j < 6; j++)
        {
            setDel(i,j);
            __delay_ms(300);
            if(i == 6  j == 6)
            {
                PORTB = 0b00000000;
                PORTC = 0b11111110;
            }
        }
    }
}


