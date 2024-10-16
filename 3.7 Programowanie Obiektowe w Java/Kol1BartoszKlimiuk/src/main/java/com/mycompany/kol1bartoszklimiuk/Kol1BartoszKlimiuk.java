/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.kol1bartoszklimiuk;
import java.util.Scanner;
import java.util.Random;

public class Kol1BartoszKlimiuk {
    public static void main(String[] args) {
        int wier, kol, i, j, max1, max2, iMax, jMax;
        Scanner in = new Scanner(System.in);
        Random rand = new Random();
        
        do{
            System.out.print("Podaj ilosc wierszy:  ");
            wier = in.nextInt();
        }while(wier<=0);
        do{
            System.out.print("Podaj ilosc kolumn:  ");
            kol = in.nextInt();
        }while(kol<=0);
        
        int[][] tab = new int[wier][kol];
        
        for(i=0; i<wier; i++)
        {
            for(j=0; j<kol; j++)
            {
                tab[i][j] = rand.nextInt(41)+10;
            }
        }
        
        max1 = tab[0][0];
        iMax = 0;
        jMax = 0;
        for(i=0; i<wier; i++)
        {
            for(j=0; j<kol; j++)
            {
                if(tab[i][j]>max1)
                {
                    max1 = tab[i][j];
                    iMax = i;
                    jMax = j;
                }
            }
        }
        
        max2 = tab[0][0];
        for(i=0; i<wier; i++)
        {
            for(j=0; j<kol; j++)
            {
                if(tab[i][j]>max2 && i!=iMax && j!= jMax)
                    max2 = tab[i][j];
            }
        }
        
        System.out.println("\nDwa najwieksze elementy tablicy to: "+max1+" i "+max2+"\n");
        
        System.out.println("Tablica:");
        for(i=0; i<wier; i++)
        {
            for(j=0; j<kol; j++)
            {
                System.out.print(tab[i][j]+", ");
            }
            System.out.println();
        }
    }
}