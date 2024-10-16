package lab3;
import java.util.Scanner;

public class main {
	public static void main(String[] args) {
		/*char znak = 'a';
		String s = new String("Ala ma kota");
		cezar Z4 = new cezar();
		
		System.out.println("Lancuch: " + s);
		zadania.zad1(znak, s);
		zadania.zad2(s);
		znak = zadania.zad3();
		System.out.println("Znak: " + znak);
		Z4.zad4();*/
		System.out.println("\nWyznaczanie ciagow zer");
		int zera = zadania.zad5();
		System.out.println("Ilosc ciagow zer: " + zera);
		
	}

}

class zadania {
	public static void zad1(char znak, String s) {
		int wystapienia = 0;
		for(int i=0; i<s.length(); i++)
		{
			if(znak == s.charAt(i))
				wystapienia++;
		}
		if(wystapienia==0)
			System.out.println("Podany znak nie wystepuje w lancuchu znakow");
		else
			System.out.println("Podany znak wystepuje w lancuchu znakow " + wystapienia + " razy");
	}
	
	public static void zad2(String s) {
		int z;
		int suma = 0;
		for(int i=0; i<s.length(); i++)
		{
			z = s.charAt(i);
			if((z>=48 && z<=57)||(z>=65 && z<=90)||(z>=97 && z<=122))
				suma += z;
		}
		System.out.println("Suma kodow ASCII cyfr i liter w lancuchu:  " + suma);
	}
	
	public static char zad3() {
		int z;
		Scanner wejscie = new Scanner(System.in);
		do {
			System.out.print("Podaj liczbe z zakresu <33, 126>:  ");
			z = wejscie.nextInt();
		} while(z<33 || z>126);
		return (char)z;
	}
	
	public static int zad5()
	{
		int n, i=0, j, zera = 0;
		String s;
		Scanner wejscie = new Scanner(System.in);
		System.out.print("Podaj liczbe: ");
		n = wejscie.nextInt();
		s = Integer.toBinaryString(n);
		char[] c = s.toCharArray();
		System.out.println("Liczba w systemie binarnym" + s);
		while(i<s.length())
		{
			if(c[i] == '0')
			{
				j=i;
				while(c[j]==0)
					j++;
				i=j;
				zera++;
			}
			i++;
		}
		if(c[0]=='0')
			zera--;
		if(c[s.length()-1]==0)
			zera--;
		return zera;
	}
}

class cezar{
	public static void zad4()
	{
		String s = new String();
		boolean czyPalindrom;
		Scanner wejscie = new Scanner(System.in);
		System.out.print("Podaj lancuch znakow:  ");
		s = wejscie.nextLine();
		int wybor;
		
		do{
			System.out.println("\nCo chcesz zrobic z lancuchem znakow?");
			System.out.println("1. Zaszyfruj\n2. Odszyfruj\n3. Czy jest palindromem?\n0. Koniec petli");
			wybor = wejscie.nextInt();
			System.out.println();
			switch(wybor) {
			case 0:
				System.out.println("Koniec petli");
				break;
			case 1:
				s = szyfrowanie(s);
				System.out.println("String po zaszyfrowaniu: " + s);
				break;
			case 2:
				s = deszyfrowanie(s);
				System.out.println("String po odszyfrowaniu: " + s);
				break;
			case 3:
				czyPalindrom = palindrom(s);
				if(czyPalindrom==true)
					System.out.println("Lancuch jest palindromem");
				else
					System.out.println("Lancuch nie jest palindromem");
				break;
			default:
				System.out.println("Zly wybor z menu");
			}
			System.out.println();
		} while(wybor!=0);
		
	}
	
	
	static String szyfrowanie(String s)
	{
		char c[] = s.toCharArray();
		int a;
		for(int i=0; i<s.length(); i++)
		{
			a = (int)c[i];
			if((a>=65 && a<=90)||(a>=97 && a<=122))
			{
				if(a==65 || a==66 || a==67 || a==97 || a==98 || a==99)
					a+=26;
				c[i] = (char)(a-3);
			}
			else
				c[i] = (char)a;
		}
		s = c.toString();
		return s;
	}
	static String deszyfrowanie(String s)
	{
		char c[] = s.toCharArray();
		int a;
		for(int i=0; i<s.length(); i++)
		{
			a = (int)c[i];
			if((a>=65 && a<=90)||(a>=97 && a<=122))
			{
				if(a==88 || a==89 || a==90 || a==120 || a==121 || a==122)
					a-=26;
				c[i] = (char)(a+3);
			}
			else
				c[i] = (char)a;
		}
		s = c.toString();
		return s;
	}
	static boolean palindrom(String s)
	{
		boolean wynik;
		char c[] = s.toCharArray();
		int i=0, j=s.length()-1;
		while(c[i]==c[j] && i<j)
		{
			i++;
			j--;
		}
		if(i>=j)
			wynik = true;
		else
			wynik = false;
		return wynik;
	}
}