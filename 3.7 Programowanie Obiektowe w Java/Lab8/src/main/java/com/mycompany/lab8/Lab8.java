package com.mycompany.lab8;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Lab8 {

    public static void main(String[] args) {
        System.out.println("\n> Zadanie 8.1");
        Zad8_1();
        System.out.println("\n> Zadanie 8.2");
        Zad8_2();
        System.out.println("\n> Zadanie 8.3");
        Zad8_3();
    }
    
    static void Zad8_1()
    {
        ArrayList<String> ListaPrzedmiotow = new ArrayList();
        ListaPrzedmiotow.add("Programowanie Obiektove w Java");
        ListaPrzedmiotow.add("Wprowadzenie Do Systemow Baz Danych");
        ListaPrzedmiotow.add("Algorytmy Analizy Numerycznej");
        ListaPrzedmiotow.add("Matematyka Dla Informatykow");
        ListaPrzedmiotow.add("Metrologia");
        
        System.out.println("Lista przedmiotow do zaliczenia:");
        for(String str : ListaPrzedmiotow)
        {
            wypisywanie(str, () -> {System.out.println("1. "+str);} );
        }
    }
    
    static void wypisywanie(String s, Interfejs1 it)
    {
        it.wypisywanieAbstract();
    }
    
    static void Zad8_2()
    {
        int n;
        Scanner in = new Scanner(System.in);
        Integer zmiana, temp;
        Comparator<Integer> comp = (x, y) -> {return Integer.compare(x, y);};

        do{
            System.out.print("Podaj ilosc elementow w tablicy:  ");
            n = in.nextInt();
        }while(n<=0);
        
        Integer[] tab = new Integer[n];
        
        for(int i=0; i<n; i++)
        {
            System.out.print("Podaj element "+i+":  ");
            tab[i] = in.nextInt();
        }
        
        for(int j=1; j<n; j++)
            for(int i=0; i<n-j; i++)
            {
                zmiana = comp.compare(tab[i], tab[i+1]);
                if(zmiana>0)
                {
                    temp = tab[i+1];
                    tab[i+1] = tab[i];
                    tab[i] = temp;
                }
            }
        
        System.out.println("\nTablica po posortowaniu:");
        for(Integer i:tab)
            System.out.print(i+", ");
        System.out.println();
    }
    
    static void Zad8_3()
    {
        int n;
        String temp;
        Scanner in = new Scanner(System.in);
        ArrayList<String> Lista = new ArrayList();
        Comparator<String> comp = (s1, s2) -> {return Integer.compare(s1.length(), s2.length());};
        
        do {
            System.out.print("Podaj ilosc lancuchow znakow:  ");
            n = in.nextInt();
        }while(n<=0);
        
        for(int i=0; i<n; i++)
        {
            System.out.println("Podaj lancuch "+i+":  ");
            temp = in.nextLine();
            Lista.add(temp);
        }
        
        Lista.sort(comp);
        
        System.out.println("\nLancuchy znakow posortowane wzgledem dlugosci");
        for(String s:Lista)
            System.out.println(s);
    }
}
