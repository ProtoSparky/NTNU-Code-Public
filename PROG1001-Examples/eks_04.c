/**
 *   Programeksempel nr 4 - Artimetiske operatorer.
 *
 *   Omhandler de aritmetiske operatorene:
 *     - +   -   *   /   %
 *     - +=  -=  *=  /=  %=
 *     - ++  --    (øke eller minske en verdi med EN)
 *     -  -  (negasjonen til en verdi, f.eks.  -7  eller   -778.24)
 *
 *   @file     EKS_04.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>         //  printf

const int VERDI = 10;      ///<  Consten 'VERDI'

/**
 *  Hovedprogrammet:
 */
int main()  {
   int  tall1 = 11, tall2 = 22, tall3 = 8, tall4 = 5, svar;

   svar = (tall1 * tall2) + (tall3 / tall4);
   printf("Svaret er: %i\n", svar);
                           //  Operatorpresedens gir samme svaret som ovenfor:
   svar = tall1 * tall2 + tall3 / tall4;
   printf("Svaret er: %i\n", svar);
                           //  Ved parentesbruk endres utregningen/svaret:
   svar = ((tall1 * tall2) + tall3) / tall4;
   printf("Svaret er: %i\n", svar);

   svar = tall1 % tall4;   //  11 % 5  = 1 i rest
   printf("Svaret er: %i\n", svar);

   svar = tall2 % tall3;   //  22 % 8  = 6 i rest
   printf("Svaret er: %i\n", svar);

   printf("Negasjonen til 'tall2' og 'tall3' er: %i  %i\n", -tall2, -tall3);

   printf("\n\n'tall2' (%i) ", tall2);
   tall2 = tall2 + VERDI;
   printf("Okt med %i er: %i\n", VERDI, tall2);

   tall2 += VERDI;
   printf("Okt med enda %i er: %i\n", VERDI, tall2);

   tall2 *= VERDI;
   printf("Multiplisert med %i er: %i\n", VERDI, tall2);
                           //  Tilsvarende med:    -=   /=   og  %=

   tall2 += 1;             //  Ulike måter å øke kun med 1:
   printf("Okt med 1 er: %i\n", tall2);

   tall2++;            //  Øker ETTER bruk. Singel setning, så uten betydning.
   printf("Okt med enda 1 er: %i\n", tall2);

   ++tall2;            //  Øker FØR bruk. Singel setning, så uten betydning.
   printf("Okt med enda 1 er: %i\n", tall2);

   printf("Okt med enda 1 er: %i\n", ++tall2);     //  Øker FØR bruk.

   printf("Okt ETTERPAA med 1 er: %i\n", tall2++);  //  Øker ETTER bruk.

   printf("NAA er den okt: %i\n", tall2);
                       //   Tilsvarende med:    --

   return 0;
}
