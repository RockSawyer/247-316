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
#include "Lcd4Lignes.h"
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
#define PORT_LIGNE PORTB
#define NB_MSG 3
#define LONG_MSG 15


void initialisation(void); //fonction qui initialise le pic
//void afficheDe(int chiffre, int deGouD);    //fonction affichant le dé
//void setDel(int ligne, int colonne);   //fct qui affiche la DEL 
//void
//void testMatrice(void);
//bool deplace(int sens, int* ptrLigne, int* ptrColonne);
//void affichePerdu(void);
//void getSens(int *nouveauSens);
void jouePendu(char* mot);
void MenuAccueil(void);



void main(void)
{
    initialisation();
    lcd_init();
    lcd_putMessage("1- Bonhomme pendu   2- Charivari");
    //MenuAccueil();
    char trouve[LONG_MSG];
    char messages[NB_MSG][LONG_MSG] = {"1erMot","2eMot","3eMot" };
            
                 
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
    TRISA = 0;      //Tout le port A en sortie
    TRISB = 0;      //tout le port B en sotie

    //Attention! 
    ANSEL = 0;     // PORTA en mode digital
    //PORTA = 0;      //DEL du port B tous éteintes
    //PORTD = 1;      //DEL du port C tous éteintes
    
    //Configuration du port analogique
    /*ANSELbits.ANS0 = 1;   //A0 en mode analogique
    ADCON0bits.ADON = 1;    //Convertisseur AN à on
    ADCON1 = 0;             //Vref+ = VDD et Vref- = VSS
    ADCON2bits.ADFM = 0;    //Alignement à gauche des 10bits de la conversion (8 MSB dasn ADRESH, 2 LSB à gauche dans ADRESL)
    ADCON2bits.ACQT = 7;    //20 TAD (on laisse le max de temps au Chold du convertisseur AN pour se charger)
    ADCON2bits.ADCS = 6;    //Fosc/64 (Fréquence pour la conversion la plus longue possible)*/
}


    
    


/**
 * @brief affiche la DEL de la matrice demander
 * @param int tableauLi[6] qui sera la serie de DEL sur l'axe des x
 * @param int tableauCo[6] qui sera la série de DEL sur l'axe des y
 * @return Aucun
 */
void setDel(int ligne, int colonne)
{
    
    int tableauLi[6] = {0, 0b10, 0b100, 0b1000, 0b10000, 0b100000};
    int tableauCo[6] = {0,0b11111100, 0b11111010, 0b11110110, 0b11101110, 0b11011110};
    
    
    
    PORTB = tableauLi[ligne];
    PORTC = tableauCo[colonne];
    
}

/**
 * @brief affiche secantiellement chaque DEL de la matrice
 * @param int i qui sera le compteur de DEL sur l'axe des x
 * @param int j qui sera le compteur de DEL sur l'axe des y
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
            
        }
    }
}

/**
 * @brief 
 * @param int sens qui sera le sens demander pour la DEL
 * @param int *ptrLigne qui sera le pointeur de DEL sur l'axe des x
 * @param int *ptrColonne qui sera le pointeur de DEL sur l'axe des y
 * @return Aucun
 */

bool deplace(int sens, int* ptrLigne, int* ptrColonne)
{
    
}


/**
 * @brief affiche la DEL de la matrice demander
 * @param int tableauLi[6] qui sera la serie de DEL sur l'axe des x
 * @param int tableauCo[6] qui sera la série de DEL sur l'axe des y
 * @return Aucun
 */

void jouePendu(char *mot)
{
    char trouve[LONG_MSG];
    for(int i = 0; i < LONG_MSG; i++)
    {
        trouve[i] = false;
    }
    do()
    {
        kbhit();
    }
}




/**
 * @brief affiche la DEL de la matrice demander
 * @param int tableauLi[6] qui sera la serie de DEL sur l'axe des x
 * @param int tableauCo[6] qui sera la série de DEL sur l'axe des y
 * @return Aucun
 */

void MenuAccueil(void)
{
    lcd_putMessage("1- Bonhomme pendu\n2- Charivari\n");
}
