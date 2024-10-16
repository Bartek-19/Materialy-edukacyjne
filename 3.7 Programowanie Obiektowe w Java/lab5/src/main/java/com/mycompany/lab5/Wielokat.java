/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;
import java.util.Scanner;

public class Wielokat extends Figura{
    private int wierzcholki, boki, sumaKatow;
    
    public Wielokat()
    {}
    
    public Wielokat(int n)
    {
        if(n<0)
            System.out.println("Nie mozna utworzyc wielokata");
        else
        {
            wierzcholki = n;
            boki = n;
            sumaKatow = (n-2)*180;
        }
    }
    
    @Override
    public void getParametry() {
        System.out.println(podajParametry());
    }

    @Override
    public void setParametry() {
        Scanner input =new Scanner(System.in);
        do{
            System.out.print("Podaj ilosc wierzcholkow:  ");
            wierzcholki = input.nextInt();
        }while(wierzcholki<2);
        boki = wierzcholki;
        sumaKatow = (boki-2)*180;
    }

    @Override
    protected String podajParametry() {
        return "Wierzcholki: "+wierzcholki+", Boki: "+boki+", Suma Katow Wewnetrznych: "+sumaKatow; 
    }

    @Override
    protected void przesun() {
        super.przesun(); 
    }

    @Override
    protected void usun() {
        super.usun(); 
    }

    @Override
    protected void rysuj() {
        super.rysuj(); 
    }
}
