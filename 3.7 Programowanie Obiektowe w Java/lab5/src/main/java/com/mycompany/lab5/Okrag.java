/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;
import java.lang.Math;
import java.util.Scanner;

public class Okrag extends Elipsa {
    private double r, Xs, Ys;
    
    public Okrag(double R, double X, double Y)
    {
        if(R<0)
            System.out.println("Nie mozna utworzyc okregu - ujemny promien");
        else{
            r = R;
            Xs = X;
            Ys = Y;
            this.pole = obliczPole();
            this.obwod = obliczObwod();
        }  
    }
    
    private double obliczPole()
    {
        return Math.PI*r*r;
    }
    
    private double obliczObwod()
    {
        return 2*Math.PI*r;
    }
    
    @Override
    protected String podajParametry() {
        return "R:  "+r+", Srodek okregu:  ("+Xs+";"+Ys+"), Pole:  "+this.pole+", Obwod:  "+this.obwod;
    }

    @Override
    public void setParametry() {
        Scanner in = new Scanner(System.in);
        do{
            System.out.print("Podaj promien okregu:  ");
            r = in.nextDouble();
        }while(r<0);
        System.out.println("Podaj wspolzedne srodka okregu:");
        Xs = in.nextDouble();
        Ys = in.nextDouble();
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
