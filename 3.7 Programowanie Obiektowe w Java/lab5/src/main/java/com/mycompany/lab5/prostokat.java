/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;
import java.util.Scanner;

public class prostokat extends Wielokat {
    private double a, b;
    
    public prostokat()
    {}
    
    public prostokat(double A, double B)
    {
        if(A<0 || B<0)
            System.out.println("Nie mozna utworzyc prostokata - ujemny/e bok/i");
        else{
            a = A;
            b = B;
            this.pole = a*b;
            this.obwod = 2*a+2*b;
        }
    }
    
    @Override
    protected String podajParametry() {
        return "A:  "+a+", B:  "+b+", Pole:  "+this.pole+", Obwod:  "+this.obwod;
    }

    @Override
    public void setParametry() {
        Scanner in = new Scanner(System.in);
        do{
            System.out.print("Podaj bok A:  ");
            a = in.nextDouble();
        }while(a<0);
        do{
            System.out.print("Podaj bok B:  ");
            b = in.nextDouble();
        }while(b<0);
        this.pole = a*b;
        this.obwod = 2*a+2*b;
    }

    @Override
    public void getParametry() {
        System.out.println(podajParametry());
    }
    
    @Override
    protected void rysuj() {
        super.rysuj();
    }

    @Override
    protected void usun() {
        super.usun();
    }

    @Override
    protected void przesun() {
        super.przesun();
    }
}
