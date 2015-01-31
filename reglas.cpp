//
//  reglas.cpp
//  wxhello01
//
//  Created by Julio Cesar Cabrera on 13/01/14.
//  Copyright (c) 2014 Julio Cesar Cabrera. All rights reserved.
//

#include "reglas.h"




void CalculaVecindad(int h,int m,int radio,char arrayTemporal[][],char array[][])
{
    
    if(radio < 1)
    {
        return;
    }
    // console.log("h "+h + " m "+m + " radio " +radio );
    
    //int max = arrayTemporal.length ;
    //var maxTwo
    
    char valorCalculado;
    char valorActual;
    char valorContar;
    
    char numNegro=0;
    char numRojo = 0;
    char numBlanco = 0;
    
    char  i = 0;
    char  j = 0;
    char  k = 0;

   // char * arrayTemporal;
    //char * array;
    
    for(k = 0 ; k < 7 ; k++)
    {
        switch(k)
        {
            case 0: //superior-inferior Derecho
                i = h+1;
                
                if(h%2 ==0 )
                    j = m+1;
                else
                    j = m -1;
                break;
            case 1:  //mitad Izquierda
                i = h-1;
                j = m;
                break;
            case 2:   //Superior En medio
                i = h;
                j = m+1;
                break;
            case 3:   //Inferior En medio
                i = h;
                j = m-1;
                break;
            case 4:   //Superior-Inferior Izquierda
                i = h-1;
                
                if(h%2 ==0 )
                    j = m+1;
                else
                    j = m -1;
                
                break;
                
            case 5:   //mitad Derecha
                i = h+1;
                j = m;
                break;
            default:
                i = h;
                j = m;
                break;
        }
        
        
        //	console.log("i "+i + " j "+j);
        
        
        if(arrayTemporal[i] != NULL)
        {
            if(arrayTemporal[i][j] != NULL)
            {
                valorContar = arrayTemporal[i][j];
                
                if(valorContar==BLANCO)
                {
                    numBlanco++;
                    //	console.log("i "+i + " j "+j+ " BLANCO");
                }
                else if (valorContar==NEGRO)
                {
                    // console.log("i "+i + " j "+j+ " NEGRO");
                    numNegro++;
                }
                else
                {
                    numRojo++;
                    // console.log("i "+i + " j "+j+ " ROJO");
                }
                
            }
            else
            {
                numBlanco++;
                // console.log("i "+i + " j "+j+ " BLANCO");
            }
        }
        else
        {
            numBlanco++;
            // console.log("i "+i + " j "+j+ " BLANCO");
        }
        
        CalculaVecindad(i,j,radio-1);
    }
    
    // console.log("BLANCO "+ numBlanco);
    // console.log("NEGRO "+ numNegro);
    // console.log("ROJO "+ numRojo);
    // console.log(" ");
    
    if( array[h] != NULL)
    {
        //								array[h][m]=arrayTemporal[h][m];
    }
    else
    {
        array[h]=[];
        //								array[h][m]=arrayTemporal[h][m];
    }
    
    /*       0 1 2 3 4 5 6 7
     ...............
     0: 0 1 2 1 2 2 2 2
     1: 0 2 2 1 2 2 2
     2: 0 0 2 1 2 2
     i=2s 3: 0 2 2 1 2
     4: 0 0 2 1
     5: 0 0 2
     6: 0 0
     7: 0
     
     
     */
    
    
    
    if ( numRojo == 2 ) //columna 2
    {
        valorCalculado =  NEGRO;
        
        // console.log(" numRojo == 2  ");
    }
    else if (numRojo >= 4 )     //columna 4,5,6,7
    {
        valorCalculado =  NEGRO;
        // console.log(" numRojo >= 4 ");
    }
    else if (numRojo == 3)   //columna 3
    {
        valorCalculado =  ROJO;
        // console.log("  numRojo == 3 ");
    }
    else if (numRojo == 0) // columna 0
    {
        valorCalculado =  BLANCO;
        // console.log(" numRojo == 0)  ");
    }
    
    else if(numNegro == 0 ) //  columna 1
    {
        valorCalculado =  ROJO;
        // console.log(" numNegro == 0  ");
    }
    else if( numNegro == 3)
    {
        valorCalculado =  NEGRO;
        // console.log(" numNegro == 3 ");
    }
    else if( numNegro == 1 )
    {
        valorCalculado =  NEGRO;
        // console.log(" numNegro == 1  ");
    }
    else
    {
        valorCalculado =  BLANCO;
        // console.log(" else ");
    }
    //array[h][m]=arrayTemporal[h][m];
    if(valorCalculado != BLANCO)
    {
        array[h][m]=valorCalculado;
        //console.log(" numRojo == 2  ");
    }
    numBlanco = 0;
    numNegro = 0;
    numRojo = 0;
    
    
    
}
