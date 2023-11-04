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
#include <string.h> //pour strlen
#define _XTAL_FREQ 1000000 //Constante utilisée par __delay_ms(x). Doit = fréq interne du uC
#define NB_MSG 3
#define LONG_MSG 15



void initialisation(void); //fonction qui initialise le pic

void jouePendu(char* mot);
//void MenuAccueil(void);



void main(void)
{
    char messages[NB_MSG][LONG_MSG] = {"nimportekoi","2eMot","3eMot"};
    initialisation();
    lcd_init();
    init_serie();
    //MenuAccueil();
   // char trouve[LONG_MSG];
    jouePendu(messages[0]);       
    
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
    
}


    
    











/**
 * @brief fonction qui permet de jouer au jeu le pendu
 * @param char *mot, qui est le mot à trouver
 * @param 
 * @return Aucun
 */

void jouePendu(char *mot)
{
    bool toutTrouver = true;
    char Lettre = 0;
    bool trouve[LONG_MSG];
    int longMess = strlen(mot);
    
    for(int i = 0; i < longMess; i++)
    {
        trouve[i] = false;
        lcd_ecritChar('_');
    }
    do
    {
        if(kbhit())
        {
            Lettre = getch();
            for(int i = 0; i < longMess; i++)
            {
                if(Lettre == mot[i])
                {
                    trouve[i] = true;
                    
                    
                }
            }
            for(int i = 0; i < longMess; i++)
            {
                if(trouve[i] == true)
                {
                    
                    lcd_gotoXY(i+1,1);
                    lcd_ecritChar(mot[i]);
                    
                }
            }
            
            for(int i = 0; i < longMess; i++)
            {
                if(trouve[i] == true)
                {
                    toutTrouver = true;
                    break;
                }
                else
                {
                    toutTrouver = false;
                }
                
            }
            
        }    
    }
        
    while(toutTrouver);
   
    
}




/**
 * @brief affiche la DEL de la matrice demander
 * @param int tableauLi[6] qui sera la serie de DEL sur l'axe des x
 * @param int tableauCo[6] qui sera la série de DEL sur l'axe des y
 * @return Aucun
 */

/*void MenuAccueil(void)
{
    lcd_putMessage("1- Bonhomme pendu\n2- Charivari");
}*/
