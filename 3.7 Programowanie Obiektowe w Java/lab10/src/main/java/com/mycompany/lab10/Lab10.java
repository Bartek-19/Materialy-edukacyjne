package com.mycompany.lab10;

import static java.lang.Thread.sleep;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.concurrent.Semaphore;
import java.util.concurrent.SynchronousQueue;

public class Lab10 {

    public static void main(String[] args) {
        try {
            System.out.println("> Zadanie 1");
            Zadanie1();
            sleep(500);
            System.out.println("\n> Zadanie 2");
            Zadanie2();
        } catch(Exception e) {
            System.out.println("\nWystapil blad w programie glownym");
        }
        
    }

    static void Zadanie1() {
        Zad1 RUN = new Zad1();
        Thread watek1 = new Thread(RUN);
        Thread watek2 = new Thread(RUN);
        Thread watek3 = new Thread(RUN);
        watek1.start();
        watek2.start();
        watek3.start();
    }

    static void Zadanie2() {
        Konsument kons = new Konsument();
        Producent prod = new Producent(kons);
        int i = 0;

        try {
            System.out.println("Rozpoczeto produkcje");
            prod.start();
            kons.start();
            while (i < 5) {
                prod.produkcja();
                kons.konsumpcja();
                i++;
            }
            prod.interrupt();
            kons.interrupt();
        } catch (Exception e) {
            System.out.println("Wystapil blad");
        }
    }
    
    static void Zadanie3()
    {
        SynchronousQueue<Thread> kolejka = new SynchronousQueue<>();
        SmazenieNalesnika procedura1 = new SmazenieNalesnika();
        SmarowanieNalesnika procedura2 = new SmarowanieNalesnika();
        ZwijanieNalesnika procedura3 = new ZwijanieNalesnika();
        
        kolejka.add(procedura1);
        kolejka.add(procedura2);
        kolejka.add(procedura3);

    }
}

class Zad1 implements Runnable {
    int x;
    Random rand = new Random();

    @Override
    public void run() {
        try {
            x = rand.nextInt(101);
            System.out.println("Wartosc x w podanym watku wynosi " + x);
        } catch (Exception e) {
        }
    }
}

class Konsument extends Thread {
    Queue<Integer> bufor = new LinkedList<>();
    Semaphore semafor = new Semaphore(1);

    public void konsumpcja() {
        try {
            semafor.acquire();
            while (bufor.isEmpty()) {
                semafor.release();
                semafor.acquire();
            }

            int wartosc = bufor.poll();
            System.out.println("Dokonano konsumpcji. Wartość: " + wartosc);
            semafor.release();
        } catch (InterruptedException e) {
            System.out.println("Przerwano konsumpcję");
        }
    }
}

class Producent extends Thread {
    private Konsument konsument;
    Semaphore semafor;

    public Producent(Konsument konsument) {
        this.konsument = konsument;
        this.semafor = konsument.semafor;
    }

    public void produkcja() {
        try {
            semafor.acquire();
            int wartosc = new Random().nextInt(101);
            System.out.println("Dokonano produkcji. Wartość: " + wartosc);
            konsument.bufor.offer(wartosc);
            semafor.release();
        } catch (InterruptedException e) {
            System.out.println("Przerwano produkcję");
        }
    }
}

class SmazenieNalesnika extends Thread {
    private final String komunikat = "Wlasnie smaze nalesnika";
    
    public void Smazenie() {
        System.out.println(komunikat);
    }
}

class SmarowanieNalesnika extends Thread {
    private final String komunikat = "Wlasnie smaruje nalesnika dzemem";
    
    public void Smarowanie() {
        System.out.println(komunikat);
    }
}

class ZwijanieNalesnika extends Thread {
    private final String komunikat = "Wlasnie zwijam nalesnika w rulon";
    
    public void Zwijanie() {
        System.out.println(komunikat);
    }
}