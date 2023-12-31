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
#include <stdio.h>          //pour printf
#include <xc.h>
#include <stdbool.h>        // pour l'utilisation du type bool
#include "Lcd4Lignes.h"
#include "serie.h"
#include <string.h>         //pour strlen
#include <stdlib.h>         //pour rand
#define _XTAL_FREQ 1000000  //Constante utilis�e par __delay_ms(x). Doit = fr�q interne du uC
#define NB_MSG 3
#define LONG_MSG 15



void initialisation(void);  //fonction qui initialise le pic
//void MenuAccueil(void);
void jouePendu(char* mot);
bool joueCharivari(char* mot);
void afficheMelange(char* mot);

void main(void)
{
    char messages[NB_MSG][LONG_MSG] = {"portable","2eMot","3eMot"};
    initialisation();
    lcd_init();
    init_serie();
    //MenuAccueil();
   // char trouve[LONG_MSG];
    //jouePendu(messages[0]);
    joueCharivari(messages[0]);
    
}


/**
 * @brief Initialisation des diff�rents regesitres du PIC
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
 * @param char *mot, qui est le mot � trouver
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
                    //int printf("fini");
                }
                
            }
            
        }    
    }
        
    while(toutTrouver);
   
    
}

/**
 * @brief 
 * @param 
 * @return
 */

bool joueCharivari(char* mot)
{
    char c = 0;
    //char msgRecu[];
    
    afficheMelange(mot);
   
    do
    {
       kbhit();
       {
            c = getch();
            //msgRecu = c;
       }
    }   
    while(c=='\r' || c==27);
        
     
    
    
}



/**
 * @brief affiche la DEL de la matrice demander
 * @param int tableauLi[6] qui sera la serie de DEL sur l'axe des x
 * @param int tableauCo[6] qui sera la s�rie de DEL sur l'axe des y
 * @return Aucun
 */

/*void MenuAccueil(void)
{
    lcd_putMessage("1- Bonhomme pendu\n2- Charivari");
}*/


/**
 * @brief 
 * @param 
 * @return
 */

void afficheMelange(char *mot)
{   
    //bool occupe = false;
    char oqp[4][20];
    char lgMot = strlen(mot);
    char lettre = 0;
    int ligne = 0;
    int colonne = 0;
    

        {
            lettre = mot[i];
            ligne = rand()%20;
            colonne = rand()%4;
            lcd_gotoXY(ligne, colonne);
            lcd_ecritChar(lettre);
        }
    }    
    
    
}