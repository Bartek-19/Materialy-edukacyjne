/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

public class Student extends Dorosly implements Podstawowy, Studia, Praca{

    @Override
    public void ileLat() {
        System.out.println("Mam 23 lata");
    }

    @Override
    public void cechy() {
        super.cechy();
    }

    @Override
    public void ogladam() {
        System.out.println("Ogladam teraz jutuby");
    }

    @Override
    public void jazda() {
        System.out.println("Jade teraz pociagiem do domu");
    }

    @Override
    public void pij() {
        System.out.println("Pije teraz piwo");
    }

    @Override
    public void jedz() {
        super.jedz();
    }

    @Override
    public void spij() {
        System.out.println("Juz 2 w nocy - pora spac");
    }

    @Override
    public void wstan() {
        System.out.println("Za pol godziny laby - pora wstawac");
    }

    @Override
    public void studiuj() {
        System.out.println("Pic piwo, spac i nie chodzic na wyklady - i tak w kolko");
    }

    @Override
    public void nieIdzNaZajecia() {
        System.out.println("No to nic, trzeba wykorzystac nieobecnosci");
    }

    @Override
    public void spoznienie() {
        System.out.println("Dobry, przepraszam za spoznienie");
    }

    @Override
    public void sloiki() {
        System.out.println("Dziekuje mamo za bigos, bardzo dobry wyszedl");
    }
    
    @Override
    public void zabawa()
    {
        System.out.println("Na reszcie wieczor - pora isc na impreze");
    }
    
    @Override
    public void obowiazki()
    {
        System.out.println("Sesja nadchodzi. Chyba trzeba zaczac sie uczyc.");
    }

    @Override
    public void pracuj() {
        System.out.println("Pracuje sobie na pol etatu w jakiejs korporacji");
    }

    @Override
    public void placPodatki() {
        System.out.println("Dobrze jest miec status studenta i nie placic podatku dochodowego");
    }

    @Override
    public void przerwaNaKawe() {
        System.out.println("Juz minelo 15 minut pracy, chyba pora na kawe");
    }

    @Override
    public void stanieWKorku() {
        System.out.println("Znowu sie spoznie do pracy przez te korki");
    }
}
