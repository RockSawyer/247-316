 /**
 * @file   main.c, projet Lab1
 * @author 
 * @date   
 * @brief   Deux dés électroniques, éteints au départ. En appuyant une 1re fois 
            sur le bouton, le dé de gauche se brasse, les DEL passent très
            rapidement de 1 à 6. En appuyant, une seconde fois sur le bouton, on
            arrête le dé de gauche, le résultat reste affiché et le dé de droite
            reste éteint. En appuyant pour une 3e fois sur le bouton, le
            dé de droite se brasse et le dé de gauche s?éteint. Appuyer sur le  
            bouton une 4e fois, le dé de droite cesse de brasser, le 
            résultat reste affiché et le dé de gauche demeure éteint. Après 
            cette 5e étape, appuyer sur le bouton recommence. 
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
#define GAUCHE true
#define DROITE false

void initialisation(void); //fonction qui initialise le pic
void afficheDe(int chiffre, int deGouD);    //fonction affichant le dé

void main(void)
{
    initialisation();
   
    
    
    while(1) //boucle principale
    {   
        
        int i = 0;
        int j = 0;
        for(i=0; i<6 ;i++)  //1re boucle qui brasse le dé de gauche
        {
            
            afficheDe(i, GAUCHE);
            __delay_ms(500);
            
        }
        for(j=0; j<6; j++)  //2e boucle pour le dé de droite
        {
            afficheDe(j, DROITE);
            __delay_ms(500);
        }
            
            
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
    TRISD = 0; //Tout le port D en sortie
    TRISC = 0; //tout le port C en sotie

    //Attention! 
    ANSELH = 0;  // RB0 à RB4 en mode digital. Sur 18F45K20 AN et PortB sont sur les memes broches
    TRISB = 0xFF; //tout le port B en entree
   
    PORTD = 0; //DEL tous éteintes
}

/**
 * @brief affiche secantiellement les valeur de 1 a 6 pour chacun des de
 * @param int chiffre qui affiche le chiffre de 1 a 6
 * @param int deGouD qui selectionne le de de droite ou de gauche
 * @return Aucun
 */
void afficheDe(int chiffre, int deGouD)
{
    int tableauDe[6] = {7,11,3,10,2,8};
    
    PORTC = tableauDe[chiffre];
    PORTDbits.RD0 = deGouD;
    
    
}