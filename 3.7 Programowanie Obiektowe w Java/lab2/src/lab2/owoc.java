package lab2;

public class owoc {

	String nazwa;
	
	public owoc(String nazwa)
	{
		this.nazwa = nazwa;
	}
	
	public void wyswietl()
	{
		System.out.println(this.nazwa);
	}
	
	public static void main(String[] args) {
		owoc banan = new owoc("banan");
		owoc agrest = new owoc("agrest");
		banan.wyswietl();
		banan.met();
		owoc.met();
	}
	
	public static void met()
	{
		System.out.println("abcdefgh");
	}

}
