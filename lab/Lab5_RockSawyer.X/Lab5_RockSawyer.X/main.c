 /**
 * @file   main.c, projet Lab1
 * @author 
 * @date   
 * @brief  
 * @version 1.0
 * Environnement:
 *     D�veloppement: MPLAB X IDE (version 6.05)
 *     Compilateur: XC8 (version 2.40)
 *     Mat�riel: Carte d�mo du Pickit4. PIC 18F45K20
 */

#include <xc.h>
#include <stdbool.h>  // pour l'utilisation du type bool
#include "serie.h"


#define _XTAL_FREQ 1000000 //Constante utilis�e par __delay_ms(x). Doit = fr�q interne du uC
#define GAUCHE true
#define DROITE false

void initialisation(void);

void main(void)
{
    initialisation();
    init_serie();
    
    while(1) //boucle principale
    {        
        PORTDbits.RD0 = PORTDbits.RD0 ^ 1; //On change l'�tat de la DEL 0
        __delay_ms(300); //pour laisser le temps de voir la DEL � son nouvel �tat
        
     }
}


/**
 * @brief Initialisation des diff�rents regesitres du PIC
 * @param Aucun
 * @return Aucun
 */
void initialisation(void)
{
    TRISD = 0; //Tout le port D en sortie
    //Attention! 
    ANSELH = 0;  // RB0 � RB4 en mode digital. Sur 18F45K20 AN et PortB sont sur les memes broches
    TRISB = 0xFF; //tout le port B en entree
   
    PORTD = 0; //DEL tous �teintes
}

