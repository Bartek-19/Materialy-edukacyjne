/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

public abstract class Czlowiek {
    protected int wiek = 4200000;
    
    public abstract void jedz();
    public abstract void pij();
    
    public void ileLat()
    {
        System.out.println("Czlowiek ma "+wiek+" lat");
    }
    
    public void cechy()
    {
        System.out.println("Czlowiek jest gatunkiem z rodziny czlowiekowatych, z rzedu naczelnych");
    }
}
