/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

public class Uczen extends Dziecko implements Podstawowy, Szkola {

    @Override
    public void zabawa()
    {
        System.out.println("Pora zagrac w Minecrafta");
    }
    
    @Override
    public void obowiazki()
    {
        System.out.println("Trzeba sie pouczyc");
    }
    
    @Override
    public void ileLat() {
        super.ileLat();
    }

    @Override
    public void cechy() {
        super.cechy();
    }

    @Override
    public void wierszyk() {
        super.wierszyk();
    }

    @Override
    public void wyliczanka() {
        super.wyliczanka();
    }

    @Override
    public void pij() {
        super.pij();
    }

    @Override
    public void jedz() {
        super.jedz();
    }

    @Override
    public void spij() {
        System.out.println("Jest juz 23 - pora spac");
    }

    @Override
    public void wstan() {
        System.out.println("Juz 7 - pora wstawac");
    }

    @Override
    public void uczSie() {
        obowiazki();
    }

    @Override
    public void odrobLekcje() {
        System.out.println("Trzeba odrobic lekcje");
    }

    @Override
    public void spoznienie() {
        System.out.println("Dzien dobry, przepraszam za spoznienie");
    }

    @Override
    public void przerwa() {
        System.out.println("W koncy przerwa");
    }
}
