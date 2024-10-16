package com.mycompany.lab7_1;
//    author: Bartosz Klimiuk

import java.awt.Dimension;
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;
import javax.swing.JFrame;

public class Lab7_1 {
    public static Scanner in = new Scanner(System.in);
    
    public static class intComparator implements Comparator<Integer>
    {
        @Override
        public int compare(Integer int1, Integer int2) {
            return Integer.compare(int1, int2);
        }
    }

    public static void main(String[] args) {
        int wybor, czyKule;
        File plik = new File("Kolizje.txt");

        do{
            System.out.println("\n-------------------------------------");
            System.out.println("Wybierz program:\n 0.Wyjscie\n 1.Kulki\n 2.Odczytanie zapisu kolizji z programu 'Kulki'");
            System.out.print(" 3.Ciagle pobieranie liczb\n 4.Sortowanie\n 5.Korekcja sumy \n 6.Korekcja iloczynu\n> Podaj swoj wybor:  ");
            wybor = in.nextInt();
            switch(wybor)
            {
            case 0:
               System.out.println("\nKoniec programu!\n");
               break;
            case 1:
                do{
                    System.out.print("Czy chcesz uruchomic program 'kule'? (1=tak/0=nie):  ");
                    czyKule = in.nextInt();
                }while(czyKule!=1 && czyKule!=0);
                
                if(czyKule==1)
                    Kulki();
                else
                    System.out.println("Powrot do menu glownego");
                break;
            case 2:
                System.out.println("Odczytywanie zapisanych kolizji kul (Po odczycie plik zostanie wyczyszczony:");
                
                try{
                    BufferedReader odczytPliku = new BufferedReader(new FileReader(plik));
                    String linia = null;
                    int i=0;
                    while((linia = odczytPliku.readLine()) != null)
                        System.out.println("Kolizja "+(i++)+":    "+linia); 
                    
                    odczytPliku.close();
                } catch(FileNotFoundException ex) {
                    System.out.println("Nie odnaleziono pliku z zapisanymi kolizjami");
                    System.err.println(ex.getCause());
                } catch(IOException ex) {
                    System.out.println("Blad wejscia/wyjscia");
                    System.err.print(ex.getCause());
                }
                
                try{
                    FileWriter czyszczenie = new FileWriter(plik, false);
                    czyszczenie.write("");
                    czyszczenie.close();
                } catch(IOException ex) {
                    System.out.println("Blad wejscia/wyjscia przy usuwaniu zawartosci");
                    System.err.print(ex.getCause());
                }
                break;
            case 3:
                Zadanie7_2();
                break;
            case 4:
                Zadanie7_3();
                break;
            case 5:
                Zadanie7_4();
                break;
            case 6:
                Zadanie7_5();
                break;
            default:
                System.out.println("Wybrano zla opcje!\n");
            }
        }while(wybor!=0);
    }
    
    private static void Kulki()
    {
        JFrame frame = new JFrame("Moje okno!");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(new Panel());
        frame.setPreferredSize(new Dimension(800, 600));
        frame.pack();
        frame.setVisible(true);
    }
    
    private static void Zadanie7_2()
    {
        int temp, suma=0, iloczyn=0;
        ArrayList<Integer> Lista = new ArrayList();
        
        System.out.println("Podaj liczby az do momentu wpisania zera: ");
        do{
            temp = in.nextInt();
            if(temp!=0)
            {
                if(Lista.isEmpty())
                {
                    suma = temp;
                    iloczyn = temp;
                }
                else
                {
                    suma += temp;
                    iloczyn *= temp;
                }
                Lista.add(temp);
            }
            else
                System.out.println("Wczytywanie zakonczone!");
        }while(temp!=0);
        System.out.println("Podano "+Lista.size()+" elementow");
        System.out.println("Ich suma wynosi "+suma+", natomiast iloczyn wynosi "+iloczyn);
    }
    
    private static void Zadanie7_3()
    {
        ArrayList<Integer> Lista = new ArrayList();
        intComparator porownanieWartosci = new intComparator();
        int suma=0, iloczyn=0, temp;
        
        System.out.println("Podaj liczby: ");
        do {
            temp = in.nextInt();
            if(Lista.isEmpty()) {
                suma = temp;
                iloczyn = temp;
            }
            else {
                suma += temp;
                iloczyn *= temp;
            }
            Lista.add(temp);
        }while(Math.abs(suma)<=250 || Math.abs(iloczyn)<=3000000);
        Lista.sort(porownanieWartosci);
        System.out.print("Podano liczby: ");
        for(Integer I : Lista)
        {
            System.out.print(I+", ");
        }
        System.out.print("\n");
    }

    private static void Zadanie7_4()
    {
        int suma=0, temp;
        ArrayList<Integer> Lista = new ArrayList();
        intComparator comp = new intComparator();
        
        System.out.println("Podaj liczby az do uzyskania sumy rownej 64:");
        do {
            temp = in.nextInt();
            suma+=temp;
            Lista.add(temp);
            if(suma>64) {
                System.out.print("Suma wprowadzonych liczb jest wieksza od 64! ");
                Lista.sort(comp);
                System.out.print("Usuwam element "+Lista.getLast()+" - ");
                suma -= Lista.getLast();
                Lista.removeLast();
                System.out.println("Usunieto\nKontynuuj podawanie liczb:");
            }
        }while(suma!=64);
        
        Iterator<Integer> it = Lista.iterator();
        System.out.println("Osiagnieto sume 64.\nPodano liczby: ");
        Lista.sort(comp);
        while(it.hasNext())
            System.out.print(it.next()+", ");
    }
    
    private static void Zadanie7_5()
    {
        int iloczyn=1, temp;
        ArrayList<Integer> Lista = new ArrayList();
        intComparator comp = new intComparator();
        
        System.out.println("Podawaj liczby az do momentu uzyskania iloczynu rownego 256 (Nie podawaj zera!):");
        do {
            temp = in.nextInt();
            
            if(temp==0) {
                System.out.println("Podano zero!");
            }
            else {
                iloczyn *= temp;
                Lista.add(temp);
            }
            
            if(iloczyn>256) {
                System.out.print("Iloczyn przekroczyl 256! ");
                Lista.sort(comp);
                System.out.print("Usuwam element "+Lista.getFirst()+" - ");
                iloczyn /= Lista.getFirst();
                Lista.removeFirst();
                System.out.println("Usunieto\nKontynuuj podawanie liczb:");
            }
        }while(iloczyn!=256);
        
        Iterator<Integer> it = Lista.iterator();
        System.out.println("Osiagnieto iloczyn 256.\nPodano liczby: ");
        Lista.sort(comp);
        while(it.hasNext())
            System.out.print(it.next()+", ");
    }
}
