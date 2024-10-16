/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;
import java.lang.Math;
import java.util.Scanner;

public class Elipsa extends Figura{
    protected double F1x, F2x, F1y, F2y;
    protected double a, b, c;
    
    public Elipsa()
    {}
    
    public Elipsa(double A, double B, double X1, double X2, double Y1, double Y2)
    {
        if(a<b || a<0 || b<0)
            System.out.println("Nie mozna utworzyc elipsy");
        else{
            a = A;
            b = B;
            F1x = X1;
            F2x = X2;
            F1y = Y1;
            F2y = Y2;
            c = odlOgniskOdSrodka(A, B);
            this.pole = Math.PI*a*b;
            this.obwod = Math.PI*(1.5*(a+b)-Math.sqrt(a*b));
        }
    }
    
    protected double odlOgniskOdSrodka(double A, double B)
    {
        return Math.sqrt(A*A - B*B);
    }
    
    @Override
    public void getParametry() {
        System.out.print(podajParametry());
    }

    @Override
    public void setParametry() {
        Scanner input = new Scanner(System.in);
        do{
            System.out.print("Podaj dlugosc polosi wiekszej: ");
            do{ this.a = input.nextDouble(); }while(a<0);
            System.out.print("Podaj dlugosc polosi mniejszej: ");
            do{ this.b = input.nextDouble(); }while(b<0);
            if(a<b)
                System.out.println("Polosie maja nieodpowiednie dlugosci - podaj jeszcze raz!");
        } while(a<b);
        c = odlOgniskOdSrodka(a, b);
        System.out.print("Podaj wspolzedne O1: ");
        F1x = input.nextDouble();
        F1y = input.nextDouble();
        System.out.print("Podaj wspolzedne O2: ");
        F2x = input.nextDouble();
        F2y = input.nextDouble();
        this.pole = Math.PI*a*b;
        this.obwod = Math.PI*(1.5*(a+b)-Math.sqrt(a*b));
    }

    @Override
    protected String podajParametry() {
        return "O1: ("+F1x+";"+F1y+"), O2: ("+F2x+";"+F2y+"), a: "+a+", b: "+b+", c: "+c+", Pole:  "+this.pole+", Obwod:  "+this.obwod;
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
