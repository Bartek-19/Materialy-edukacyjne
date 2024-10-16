/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

public abstract class Dorosly extends Czlowiek {

    protected abstract void zabawa();
    protected abstract void obowiazki();
    
    @Override
    public void jedz()
    {
        System.out.println("Jem teraz obiad");
    }
    
    @Override
    public void pij()
    {
        System.out.println("Pije teraz czerwone wino");
    }
    
    public void jazda()
    {
        System.out.println("Jade sobie autem");
    }
    
    public void ogladam()
    {
        System.out.println("Ogladam teraz telewizje");
    }
    
    @Override
    public void cechy() {
        System.out.println("Jestem dojrzaly, zmeczony i siwieje");
    }

    @Override
    public void ileLat() {
        System.out.println("Mam 40 lat");
    }
}
