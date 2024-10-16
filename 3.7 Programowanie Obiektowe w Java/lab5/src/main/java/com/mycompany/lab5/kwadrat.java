/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

import java.util.Scanner;

public class kwadrat extends prostokat {
    private double a;
    
    public kwadrat(double Bok)
    {
        if(Bok<0)
            System.out.println("Nie mozna utworzyc kwadratu - ujemny bok");
        else
        {
            a = Bok;
            this.pole = a*a;
            this.obwod = 4*a;
        }
    }
    
    @Override
    public void getParametry() {
        System.out.println(podajParametry());
    }

    @Override
    public void setParametry() {
        Scanner in = new Scanner(System.in);
        do{
            System.out.print("Podaj bok kwadratu:  ");
            a = in.nextDouble();
        }while(a<0);
        this.pole = a*a;
        this.obwod = 4*a;
    }

    @Override
    protected String podajParametry() {
        return "A:  "+a+", Pole:  "+this.pole+", Obwod:  "+this.obwod;
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
