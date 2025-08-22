/**
 *   Programeksempel nr 1 - Introduserende eksempel til programmering i C.
 *
 *   Med bruk av:
 *     - Inkludere biblioteksfil for I/O
 *     - Hovedprogram
 *     - Heltallsvariabler
 *     - Tilordning
 *     - Aritmetikk
 *     - Utskrift
 *
 *   @file     EKS_01.C  (nesten identisk til Program 2.6 i l�reboka)
 *   @author   Stephen G.Kochan  /  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf


/**
 *  Hovedprogrammet:
 */
int main()  {                     //  ALLE program Må ha EN 'main'.
                                  //  Blokker omsluttes av '{'  og '}.
          //  Definerer 3x heltallsvariable.
                                  //  Programsetninger avsluttes med ';'
    long int value1,sum, value2;                              //  Ofte EN programsetning pr.linje.

    value1 = 5000000000000;                  //  Gir 2x av variablene verdier.
    value2 = 25;
    sum = value1 + value2;        //  Foretar summasjon inn i den tredje.

                                  //  Utskrift av resultatet:
                                  //  %i angir at skal erstattes av en 'int'.
    printf("The sum of %i and %i is %i\n", value1, value2, sum);

    return 0;                     //  Avslutter programmet.


                      //  Noen viktige poenger:
                      //  =====================

                      //  Prim�rt brukes SM� bokstaver i SPR�KET,
                      //              og det er FORSKJELL p� store og sm�.

                      //  Blanke, tab og linjeskift ignoreres av kompilatoren.

                      //  '#' er preprosessordirektiv (flere andre finnes).
}