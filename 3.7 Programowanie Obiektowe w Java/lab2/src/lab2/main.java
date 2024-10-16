package lab2; 

public class main {

	public static void main(String[] args) {
		klasa k1 = new klasa();
		uczen u1 = new uczen();
		uczen u2 = new uczen("Jan", "Kowalski", 15, 4.5);
		Owoc o1 = new Owoc("Jablko", "Polska");
		trojkat t1 = new trojkat(3, 4, 5);
		trojkat t2 = new trojkat(4, 4, 9);
		int N = 10;
		
		
		k1.wyswietl();
		klasa.wypisz();
		
		System.out.println(u1.imie + " " + u1.nazwisko + " " + u1.wiek + " " + u1.srednia);
		System.out.println(u2.imie + " " + u2.nazwisko + " " + u2.wiek + " " + u2.srednia + "\n");
		o1.wyswietl();
		
		klasa.odliczanie();
		
		System.out.print("Trojkat pierwszy: ");
		t1.sprawdzenie();
		System.out.print("Trojkat drugi: ");
		t2.sprawdzenie();
		System.out.println();
		
		klasa.modulo();
		
		ciag(N);
	}
	
	public static void ciag(int n)
	{
		System.out.print("Ciag Fibbonacciego:  ");
		for(int i=0; i<=n; i++)
			System.out.print(fibbonacci(i)+" ");
		System.out.println();
	}
	
	public static int fibbonacci(int x)
	{
		if(x<0)
		{
			System.out.println("Zla liczba");
			return 0;
		}
		else if(x==0 || x==1)
			return x;
		else
			return fibbonacci(x-2)+fibbonacci(x-1);
	}

}

class klasa {
	int x;
	char c;
	String s;
	
	public void wyswietl()
	{
		System.out.println(x);
		System.out.println(c);
		System.out.println(s);
		System.out.println();
	}
	
	public static void wypisz()
	{
		for(int i=0; i<55; i++)
			System.out.println(i);
		System.out.println();
	}
	
	public static void odliczanie() {
		int i;
		System.out.print("Odliczanie for: ");
		for(i=5; i<=80; i+=15)
			System.out.print(i+" ");
		System.out.println();
		i=5;
		System.out.print("Odliczanie while: ");
		while(i<=80)
		{
			System.out.print(i+" ");
			i+=15;
		}
		System.out.println();
		i=5;
		System.out.print("Odliczanie do while: ");
		do {
			System.out.print(i+" ");
			i+=15;
		}while(i<80);
		System.out.println("\n");
	}
	
	public static void modulo()
	{
		System.out.print("Liczby z zakresu <11;111> podzielne przez 13: ");
		for(int i=11; i<=111; i++)
			if(i%13==0)
				System.out.print(i+" ");
		System.out.println();
	}
}

class uczen {
	String imie;
	String nazwisko;
	int wiek;
	double srednia;
	
	public uczen()
	{
		
	}
	public uczen(String imie, String nazwisko, int wiek, double srednia)
	{
		this.imie = imie;
		this.nazwisko = nazwisko;
		this.wiek = wiek;
		this.srednia = srednia;
	}
}

class Owoc {
	String nazwa;
	String krajPochodzenia;
	
	public Owoc()
	{}
	
	public Owoc(String n, String k)
	{
		nazwa = n;
		krajPochodzenia = k;
	}
	
	public void wyswietl()
	{
		System.out.println(nazwa + ", kraj pochodzenia: " + krajPochodzenia + "\n");
	}
}

class trojkat{
	int a,b,c;
	
	public trojkat(int A, int B, int C)
	{
		a = A;
		b = B;
		c = C;
	}
	
	public void sprawdzenie()
	{
		if(a+b>c && a+c>b && b+c>a)
			System.out.println("Z podanych bokow mozna utworzyc trojkat");
		else
			System.out.println("Z podanych bokow nie mozna utworzyc trojkata");
	}
}