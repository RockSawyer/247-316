 /**
 * @file   main.c, projet Lab1
 * @author 
 * @date   
 * @brief   Deux d�s �lectroniques, �teints au d�part. En appuyant une 1re fois 
            sur le bouton, le d� de gauche se brasse, les DEL passent tr�s
            rapidement de 1 � 6. En appuyant, une seconde fois sur le bouton, on
            arr�te le d� de gauche, le r�sultat reste affich� et le d� de droite
            reste �teint. En appuyant pour une 3e fois sur le bouton, le
            d� de droite se brasse et le d� de gauche s?�teint. Appuyer sur le  
            bouton une 4e fois, le d� de droite cesse de brasser, le 
            r�sultat reste affich� et le d� de gauche demeure �teint. Apr�s 
            cette 5e �tape, appuyer sur le bouton recommence. 
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

void initialisation(void); //fonction qui initialise le pic
void afficheDe(int chiffre, int deGouD);    //fonction affichant le d�

void main(void)
{
    initialisation();
   
    
    
    while(1) //boucle principale
    {   
        
        int i = 0;
        int j = 0;
        for(i=0; i<6 ;i++)  //1re boucle qui brasse le d� de gauche
        {
            
            afficheDe(i, GAUCHE);
            __delay_ms(500);
            
        }
        for(j=0; j<6; j++)  //2e boucle pour le d� de droite
        {
            afficheDe(j, DROITE);
            __delay_ms(500);
        }
            
            
        //PORTDbits.RD7 = PORTDbits.RD7 ^ 1; //On change l'�tat de la DEL 0
        //__delay_ms(300); //pour laisser le temps de voir la DEL � son nouvel �tat
        
        
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
    TRISC = 0; //tout le port C en sotie

    //Attention! 
    ANSELH = 0;  // RB0 � RB4 en mode digital. Sur 18F45K20 AN et PortB sont sur les memes broches
    TRISB = 0xFF; //tout le port B en entree
   
    PORTD = 0; //DEL tous �teintes
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