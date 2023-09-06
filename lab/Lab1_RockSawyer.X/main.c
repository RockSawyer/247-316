 /**
 * @file   main.c, projet Lab1
 * @author Rock Sawyer
 * @date   1er septembre 2023
 * @brief  Chaser qui change de direction en appuyant sur g ou d
 * @version 1.0
 * Environnement:
 *     Développement: MPLAB X IDE (version 6.05)
 *     Compilateur: XC8 (version 2.40)
 *     Matériel: Carte démo du Pickit4. PIC 18F45K20
 */

#include <xc.h>
#include <stdbool.h>                // pour l'utilisation du type bool
#include "serie.h"
#include <conio.h>                  // pour l'utilisation de kbhit et getch

#define _XTAL_FREQ 1000000          //Constante utilisée par __delay_ms(x). Doit = fréq interne du uC
#define GAUCHE true
#define DROITE false

void initialisation(void);

void main(void)
{
    initialisation();
    init_serie();
    bool sens = 0;
    char car;
    
    while(1)                        //boucle principale
    {        
        
        //putch('a');
         if (kbhit())               //boucle qui surveille si une touche a ete tapee
            {
                car = getch();
            
                if (car == 'd')     //si la touche d est tapee
                   {
                        sens = 0;   //le sens du chaser est la droite
                   }
                if (car == 'g')     //si la touche g est taper
                {
                    sens = 1;       //le sens du chaser devient la gauche
                }
            }
            __delay_ms(100);
        
        
        
        if(sens == 0)               //pour éviter que le chaser s'arrete si
        {                           //si aucune led est allumer on le fait
            PORTD = PORTD << 1;     //reomencer au debut 
           
            if (PORTD == 0)
            {
              PORTD = 1;    
            }
            __delay_ms(100);
        }
        else
        {
            PORTD = PORTD >> 1;
            if (PORTD == 0)
            {
                PORTD = 128;
            }
            __delay_ms(100);
        }
        if (PORTBbits.RB0 == 0)     //si bouton appuyé?
        {
            while (PORTBbits.RB0 == 0);//on attend que le bouton soit relâché
            sens = !sens;
            
        }
        
    }
    
}


/**
 * @brief Initialisation des différents regesitres du PIC
 * @param Aucun
 * @return Aucun
 */
void initialisation(void)
{
    TRISD = 0;                      //Tout le port D en sortie
    //Attention! 
    ANSELH = 0;                     // RB0 à RB4 en mode digital. Sur 18F45K20 AN et PortB sont sur les memes broches
    TRISB = 0xFF;                   //tout le port B en entree
   
    PORTD = 1;                      //DEL tous éteintes
}

