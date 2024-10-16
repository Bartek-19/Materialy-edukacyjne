/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

public class Emeryt extends Dorosly implements Podstawowy, Emerytura{

    @Override
    public void ileLat() {
        System.out.println("Panie ja mam 84 lata");
    }

    @Override
    public void cechy() {
        System.out.println("Jestem stary, bez energii i mam duzo czasu wolnego");
    }

    @Override
    public void ogladam() {
        super.ogladam();
    }

    @Override
    public void jazda() {
        System.out.println("Jade sobie autobusem miejskim do lekarza");
    }

    @Override
    public void pij() {
        System.out.println("Pije sobie kompot z wlasnych owcow");
    }

    @Override
    public void jedz() {
        super.jedz();
    }

    @Override
    public void idzDoLekarza() {
        System.out.println("Za 2 godziny mam lekarza - trzeba isc na autobus");
    }

    @Override
    public void odbierzEmeryture() {
        System.out.println("Juz dziesiaty, powinna dzisiaj przyjsc emerytura");
    }

    @Override
    public void wspomozWnuczka() {
        System.out.println("Masz wnusiu 50 zlotych na wakacje, przyda ci sie");
    }

    @Override
    public void idzDoSklepu() {
        System.out.println("Przydaloby sie kupuc rzeczy na obiad");
    }

    @Override
    public void spij() {
        System.out.println("Juz 19 - trzeba isc spac");
    }

    @Override
    public void wstan() {
        System.out.println("Juz 6 rano - trzeba wstawac");
    }
    
    @Override
    public void zabawa()
    {
        System.out.println("Pora sie wybrac na jakies tance");
    }
    
    @Override
    public void obowiazki()
    {
        System.out.println("Juz 17, najwyzsza pora zbierac sie na msze");
    }
}
