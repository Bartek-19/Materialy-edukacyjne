/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;
import java.util.Scanner;

public class Trojkat extends Wielokat {
    private double a, h;
    
    public Trojkat(double A, double H)
    {
        if(A<0)
            System.out.println("NIe mozna utworzyc trojkata - ujemna dlugosc boku");
        else if(H<0)
            System.out.println("NIe mozna utworzyc trojkata - ujemna wysokosc");
        else{
            a = A;
            h = H;
            this.pole = obliczPole();
            this.obwod = obliczObwod();
        }
    }
    
    private double obliczPole()
    {
        return 0.5*a*h;
    }
    
    private double obliczObwod()
    {
        return a*3;
    }

    @Override
    protected String podajParametry() {
        return "A:  "+a+", H:  "+h+", Pole:  "+this.pole+", Obwod:  "+this.obwod;
    }

    @Override
    public void setParametry() {
        Scanner in = new Scanner(System.in);
        do{
            System.out.print("Podaj bok trojkata:  ");
            a = in.nextDouble();
        }while(a<0);
        do{
            System.out.print("Podaj wysokosc trojkata:  ");
            h = in.nextDouble();
        }while(h<0);
        this.pole = obliczPole();
        this.obwod = obliczObwod();
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
