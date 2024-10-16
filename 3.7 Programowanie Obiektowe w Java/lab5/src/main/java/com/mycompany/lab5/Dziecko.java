/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

public abstract class Dziecko extends Czlowiek {

    protected abstract void zabawa();
    protected abstract void obowiazki();
    
    @Override
    public void jedz()
    {
        System.out.println("Jem teraz chipsy");
    }
    
    @Override
    public void pij()
    {
        System.out.println("Pije teraz Cole");
    }
    
    public void wyliczanka()
    {
        System.out.println("Raz, dwa, trzy - dzis obiadu nie zjesz ty!");
    }
    
    public void wierszyk()
    {
        System.out.println("Idzie Grzes przez wies\nworek piasku niesie");
        System.out.println("A przez dziurke, piasek ciurkiem\nspie sie za Grzesiem");
    }
    
    @Override
    public void cechy() {
        System.out.println("Jestem mlody, ruchliwy i pelen energii");
    }

    @Override
    public void ileLat() {
        System.out.println("Mam 13 lat");
    }
}
