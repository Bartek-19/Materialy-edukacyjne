package com.mycompany.lab5;
import java.awt.Color;

public class Lab5 {

    public static void main(String[] args) {
        Color kolor = new Color(128, 128, 128);
        Figura kw1 = new kwadrat(1.5);
        Figura e1 = new Elipsa(5, 4, 0, 3, 0, 0);
        Elipsa o1 = new Okrag(5, 2.1, 4.7);
        Figura f1 = new Figura(30, 12, kolor);
        Figura w1 = new Wielokat(10);
        Wielokat kw2 = new kwadrat(4);
        Wielokat t1 = new Trojkat(2.1, -1.2);
        Wielokat p1 = new prostokat(0.1, 0.2);
        prostokat kw3 = new kwadrat(80.3);
        
        Uczen ucz1 = new Uczen();
        Student st1 = new Student();
        Emeryt em1 = new Emeryt();
        
        System.out.println("Dziedziczenie klas\n");
        
        System.out.println("> Figura:");
        f1.getParametry();
        f1.setParametry();
        f1.getParametry();
        
        System.out.println("\n> Elipsa:");
        e1.getParametry();
        e1.setParametry();
        e1.getParametry();
        
        System.out.println("\n> Okrag:");
        o1.getParametry();
        o1.setParametry();
        o1.getParametry();
        
        System.out.println("\n> Wielokat:");
        w1.getParametry();
        w1.setParametry();
        w1.getParametry();
        
        System.out.println("\n> Trojkat:");
        t1.getParametry();
        t1.setParametry();
        t1.getParametry();
        
        System.out.println("\n> Prostokat:");
        p1.getParametry();
        p1.setParametry();
        p1.getParametry();
        
        System.out.println("\n> Kwadrat new Figura():");
        kw1.getParametry();
        kw1.setParametry();
        kw1.getParametry();
        
        System.out.println("\n> Kwadrat new Wielokat():");
        kw2.getParametry();
        kw2.setParametry();
        kw2.getParametry();
        
        System.out.println("\n> Kwadrat new Prostokat():");
        kw3.getParametry();
        kw3.setParametry();
        kw3.getParametry();
        
        System.out.println("\nInterfejsy i abstrakcja\n");
        
        System.out.println("\n> Uczen:");
        ucz1.ileLat();
        ucz1.cechy();
        ucz1.wstan();
        ucz1.jedz();
        ucz1.pij();
        ucz1.spoznienie();
        ucz1.uczSie();
        ucz1.wierszyk();
        ucz1.przerwa();
        ucz1.odrobLekcje();
        ucz1.wyliczanka();
        ucz1.zabawa();
        ucz1.spij();
        
        System.out.println("\n> Student:");
        st1.ileLat();
        st1.cechy();
        st1.pracuj();
        st1.placPodatki();
        st1.studiuj();
        st1.wstan();
        st1.jedz();
        st1.pij();
        st1.ogladam();
        st1.stanieWKorku();
        st1.spoznienie();
        st1.przerwaNaKawe();
        st1.zabawa();
        st1.spij();
        st1.nieIdzNaZajecia();
        st1.jazda();
        st1.sloiki();
        st1.obowiazki();
        
        System.out.println("\n> Emeryt:");
        em1.ileLat();
        em1.cechy();
        em1.wstan();
        em1.jedz();
        em1.pij();
        em1.idzDoLekarza();
        em1.jazda();
        em1.ogladam();
        em1.odbierzEmeryture();
        em1.wspomozWnuczka();
        em1.idzDoSklepu();
        em1.zabawa();
        em1.obowiazki();
        em1.spij();
    }
}
