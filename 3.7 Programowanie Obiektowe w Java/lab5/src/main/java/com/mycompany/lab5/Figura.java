/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;
import java.awt.Color;
import java.util.Scanner;

public class Figura {
    protected double pole, obwod;
    private Color kolor;
    
    protected void rysuj()
    {
        System.out.println("Narysowano figure");
    }
    protected void usun()
    {
        System.out.println("Usunieto figure");
    }
    protected void przesun()
    {
        System.out.println("Przesunieto figure");
    }
    protected String podajParametry()
    {
        return "Pole: " + pole + ", Obwod: " + obwod + ", Kolor: " + kolor;
    }
    public Figura()
    {}
    public Figura(int p, int o, Color k)
    {
        if(pole < 0)
            System.out.println("Podano ujemne pole w konstruktorze");
        else
            pole = p;
        
        if(obwod < 0)
            System.out.println("Podano ujemny obwod w konstruktorze");
        else
            obwod = o;
        
        kolor = k;
    }
    
    public void setParametry()
    {
        Scanner wejscie = new Scanner(System.in);
        int r, g, b;
        
        do{
            System.out.print("Podaj pole figury:  ");
            pole = wejscie.nextInt();
        }while(pole<0);
        do{
            System.out.print("Podaj obwod figury:  ");
            obwod = wejscie.nextInt();
        }while(obwod<0);
        System.out.print("Podaj kolor figury (r, g, b):  ");
        System.out.print("r: ");
        do{ r = wejscie.nextInt(); }while(r<0 || r>255);
        System.out.print("g: ");
        do{ g = wejscie.nextInt(); }while(g<0 || g>255);
        System.out.print("b: ");
        do{ b = wejscie.nextInt(); }while(b<0 || b>255);
        kolor = new Color(r, g, b);
    }
    
    public void getParametry()
    {
        System.out.println(this.podajParametry());
    }
}
