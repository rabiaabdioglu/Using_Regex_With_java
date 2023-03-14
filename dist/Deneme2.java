/**
*
* @author Rabia Abdioðlu 	-	rabia.abdioglu@ogr.sakarya.edu.tr
* @since  30.03.2022
* <p>
*		  1C
* </p>
* 
* Kendi örnek kodum
*/



import java.math.*;
import java.util.*;
public class Test {
  public static void main(String[] args) {
	  public static void main(String[]args){
			int a,b,c;
			
			Scanner yaz=new Scanner(System.in);
		
			a=yaz.nextInt();
			b=yaz.nextInt();
			c=yaz.nextInt();

			int buyuk = 0,kucuk=0,orta=0;
		
			////Karþýlaþtýrmalar///
				if(a>=b && a>=c ){
					buyuk=a;
					if(b>=c){orta=b;kucuk=c;}
					else if(c>=b){orta=c; kucuk=b;	}	}
				
				if(b>=a && b>=c ){
					buyuk=b;
					if(a>=c){orta=a;kucuk=c;	}
					else if(c>=a){orta=c; kucuk=a;	}
				}
				if(c>=a && c>=b ){
					buyuk=c;
					if(b>=a){orta=b;kucuk=a;}
					else if(a>=b){orta=a; kucuk=b;	}
				}
				/*
				 * 
				 * 
				 * Ekran çýktýsý
				 * 
				 */
				
				System.out.println(buyuk+" ---> BUYUK");
				System.out.println(orta+" ---> ORTA");
				System.out.println(kucuk+" ---> KUCUK");


			
	}
  }
}