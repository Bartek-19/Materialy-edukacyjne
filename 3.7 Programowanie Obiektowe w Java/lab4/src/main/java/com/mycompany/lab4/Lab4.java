package com.mycompany.lab4;
import java.util.Random;
import java.util.Arrays;
import java.util.Scanner;
import java.lang.Math;

public class Lab4 {

    public static void main(String[] args) {
        Scanner wejscie = new Scanner(System.in);
        Random generator = new Random();
        
        System.out.println("> ZAD1");
        zad1();
        System.out.println("\n> ZAD2");
        zad2(wejscie, generator);
        System.out.println("\n> ZAD3");
        zad3();
    }
    
    static void zad1()
    {
        int[] tab = new int[100];
        double srednia[] = new double[10];
        int count[] = new int[10];
        int i, j;
        
        Arrays.fill(srednia, 0.0);
        Arrays.fill(count, 0);
        
        for(i=0; i<tab.length; i++)
            tab[i] = i;
            
        for(j=0; j<tab.length-1; j++)
        {
            if(tab[j]<100)
                System.out.print("  ");
            else if(tab[j]<1000)
                System.out.print(" ");
            
            if(j<10)
                System.out.print("0");
            System.out.print(tab[j] + ", ");
            if(j%10==9)
                System.out.println();
            srednia[j%10] += tab[j];
            count[j%10]++;
        }
        if(tab[j]<100)
            System.out.print("  ");
        else if(tab[j]<1000)
            System.out.print(" ");
        System.out.println(tab[j] + ";");
        System.out.println("----------------------------------------");
        
        for(i=0; i<srednia.length; i++)
        {
            srednia[i] /= count[i];
            System.out.print(srednia[i] + ", ");
        }
        System.out.println("\n");
    }
    
    static void zad2(Scanner input, Random rand)
    {
        int n;
        double st;
                
        do{
            System.out.print("Podaj wymiar tablicy NxN:  ");
            n = input.nextInt();
        }while(n<=0);
        
        int tab[][] = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                tab[i][j] = rand.nextInt(11)+10;
        
        System.out.println("Tablica na poczatku:");
        for(int i=0; i<n; i++)
        {
            System.out.print("[");
            for(int j=0; j<n; j++)
                System.out.print(tab[i][j] + "  ");
            System.out.print("]\n");
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    tab[i][j] = rand.nextInt(1)*2 - 1;
                else
                    tab[i][j] = rand.nextInt(40)-20;
            }
        }
        
        System.out.println("\nTablica po wypelnieniu:");
        for(int i=0; i<n; i++)
        {
            System.out.print("[");
            for(int j=0; j<n; j++)
            {
                if(tab[i][j]>9 || (tab[i][j]<0 && tab[i][j]>-10))
                    System.out.print(" ");
                else if(tab[i][j]>=0)
                    System.out.print("  ");
                System.out.print(tab[i][j] + "  ");
            }
            System.out.print("]\n");
        }
        st = stosunek(tab);
        System.out.println("Stosunek liczb o parzystych i do liczb o nieparzystym j:  " + st);
    }
    
    static double stosunek(int tab[][])
    {
        int parzyste = 0, nieparzyste = 0;
        double wynik;
        
        for(int i=0; i<tab.length; i++)
            for(int j=0; j<tab[i].length; j++)
            {
                if(i%2==0)
                    parzyste += tab[i][j];
                if(j%2==1)
                    nieparzyste += tab[i][j];
            }
        
        wynik =  (double)(parzyste/nieparzyste);
        return wynik;
    }
    
    static void zad3()
    {
        Random rand = new Random();
        Scanner input = new Scanner(System.in);
        okrag okregi[] = tworzenieTablicy(input);
        int i=0;
        
        System.out.println("Utworzono " + okregi.length + " okregow\n");
        if(okregi.length<2)
        {
            System.out.println("Okrag w tablicy");
            okregi[0].informacje();
            System.out.println("Nie da sie go porownac z innymi okregami - za malo elementow tablicy");
        }
        else
        {
            int i1 = rand.nextInt(okregi.length), i2 = rand.nextInt(okregi.length);
            System.out.println("Porownywanie okregow "+i1+" i "+i2+".");
            porownanieOkregow(okregi[i1], okregi[i2]);
        }
        
        System.out.println("Informacje o wszystkich okregach");
        for(okrag o : okregi)
        {
            System.out.print("Okrag "+i+"  ");
            o.informacje();
            i++;
        }
    }
    
    static okrag[] tworzenieTablicy(Scanner input)
    {
        int n;
        do{
            System.out.print("Podaj ilosc okregow:  ");
            n = input.nextInt();
        }while(n<=0);
        
        okrag[] okregi = new okrag[n];
        for (int i = 0; i < n; i++) {
            okregi[i] = new okrag();
        }
        return okregi;
    }
    
    static void porownanieOkregow(okrag o1, okrag o2)
    {
        double dyst;
        dyst = Math.abs(Math.sqrt(Math.pow((o1.x - o2.x), 2.0)+Math.pow((o1.y - o2.y), 2.0)) );
        
        System.out.print("Okrag pierwszy  ");
        o1.informacje();
        System.out.print("Okrag drugi     ");
        o2.informacje();
        System.out.print("Podane okregi sa ");
        if(o1.r==o2.r && dyst==0)
            System.out.println("pokrywajace sie");
        else if(dyst==0)
            System.out.println("wspolsrodkowe");
        else if(dyst==Math.abs(o1.r-o2.r))
            System.out.println("styczne wewnetrznie");
        else if(dyst==o1.r+o2.r)
            System.out.println("styczne zewnetrznie");
        else if(dyst>Math.abs(o1.r-o2.r) && dyst<o1.r+o2.r)
            System.out.println("przecinajace sie");
        else if(dyst<Math.abs(o1.r-o2.r))
            System.out.println("rozlaczne wewnetrznie");
        else
            System.out.println("rozlaczne zewnetrznie");
        System.out.println();
    }
    
    public static class okrag {
        
        int x, y, r;
        
        public okrag()
        {
            Random rand = new Random();
            x = rand.nextInt(91)+5;
            y = rand.nextInt(91)+5;
            r = rand.nextInt(5)+1;
        }

        public void informacje()
        {
            System.out.println("X: " + x + ", Y: " + y + ", R: " + r);
        }
    }
}
