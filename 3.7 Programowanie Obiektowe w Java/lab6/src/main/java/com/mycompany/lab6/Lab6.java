package com.mycompany.lab6;
import java.util.*;

public class Lab6 {

    public static void main(String[] args) {
        int sumaKwadratow;
        
        System.out.println("> Kalkulator");
        kalkulator();
        System.out.println("> Liczba rzeczywista");
        liczbaRzeczywista();
        System.out.println("> Liczba calkowita");
        sumaKwadratow = liczbaCalkowita();
        System.out.println("Suma kwadratow podanej liczby:  " + sumaKwadratow);
    }
    
    static void kalkulator()
    {
        int wyborKalkulatora = 0;
        int a, b;
        double wynik;
        Scanner in = new Scanner(System.in);
        
        try {
            do{
                System.out.println("> Kalkulator\n0. Wyjscie\n1. Dodawanie\n2. Odejmowanie");
                System.out.println("3. Mnozenie\n4. Dzielenie\n5. Potegowanie");
                System.out.print("Podaj swoj wybor:  ");
                wyborKalkulatora = in.nextInt();
                switch(wyborKalkulatora)
                {
                case 0:
                    System.out.println("Wylaczam kalkulator");
                    break;
                case 1:
                    try {
                        System.out.print("Podaj a:  ");
                        a = in.nextInt();
                        System.out.print("Podaj b:  ");
                        b = in.nextInt();
                        wynik = a + b;
                        System.out.println("a + b = " + a);
                    } catch(InputMismatchException imex) {
                        System.out.println("Wprowadzono bledne znaki z klawiatury");
                    }
                    break;
                case 2:
                    try {
                        System.out.print("Podaj a:  ");
                        a = in.nextInt();
                        System.out.print("Podaj b:  ");
                        b = in.nextInt();
                        wynik = a - b;
                        System.out.println("a - b = " + a);
                    } catch(InputMismatchException imex) {
                        System.out.println("Wprowadzono bledne znaki z klawiatury");
                    }
                    break;
                case 3:
                    try {
                        System.out.print("Podaj a:  ");
                        a = in.nextInt();
                        System.out.print("Podaj b:  ");
                        b = in.nextInt();
                        wynik = a * b;
                        System.out.println("a * b = " + a);
                    } catch(InputMismatchException imex) {
                        System.out.println("Wprowadzono bledne znaki z klawiatury");
                    }
                    break;
                case 4:
                    try {
                        System.out.print("Podaj a:  ");
                        a = in.nextInt();
                        System.out.print("Podaj b:  ");
                        b = in.nextInt();
                        wynik = a / b;
                        System.out.println("a / b = " + a);
                    } catch(InputMismatchException imex) {
                        System.out.println("Wprowadzono bledne znaki z klawiatury");
                    } catch(ArithmeticException aex) {
                        System.out.println("Nie wolno dzielic przez zero");
                    }
                    break;
                case 5:
                    try {
                        System.out.print("Podaj podstawe:  ");
                        a = in.nextInt();
                        System.out.print("Podaj wykladnik:  ");
                        b = in.nextInt();
                        wynik = Math.pow(a, b);
                        System.out.println("a^b = " + a);
                    } catch(InputMismatchException imex) {
                        System.out.println("Wprowadzono bledne znaki z klawiatury");
                    }
                    break;
                default:
                    System.out.println("Podano zly numer");
                }
            } while(wyborKalkulatora != 0);
        } catch(InputMismatchException imex) {
                System.out.println("Wprowadzono bledne znaki z klawiatury");
        }
    }
    
    static void liczbaRzeczywista()
    {
        Scanner in = new Scanner(System.in);
        float liczba, mantysa;
        int cecha;
        
        try{
            System.out.println("Podaj liczbe rzezcywista:  ");
            liczba = Float.parseFloat(in.nextLine());
            mantysa = liczba;
            cecha = 0;
            if(liczba>=1 || liczba<=-1)
                while(mantysa>10)
                {
                    mantysa /= 10;
                    cecha += 1;
                }
            else
                while(mantysa<1 && mantysa>-1)
                {
                    mantysa *= 10;
                    cecha -= 1;
                }
            System.out.println("Podana liczba to " + mantysa + "*10^" + cecha);
        } catch(InputMismatchException imex) {
            System.out.println("Wprowadzono bledne znaki z klawiatury");
        }
    }
    
    static int liczbaCalkowita()
    {
        int sumaKw=0, liczba, cyfra;
        Scanner in = new Scanner(System.in);
        
        try {
            System.out.print("Podaj liczbe calkowita:  ");
            liczba = in.nextInt();
            while(liczba!=0)
            {
                cyfra = liczba%10;
                sumaKw += cyfra*cyfra;
                liczba /= 10;
            }
            return sumaKw;
        } catch(InputMismatchException imex) {
            System.out.println("Wprowadzono bledne znaki z klawiatury");
            return 0;
        } 
    }
}
