/**
*
* @author Rabia Abdio�lu 	-	rabia.abdioglu@ogr.sakarya.edu.tr
* @since  30.03.2022
* <p>
*		  1C
* </p>
*/


package odev;

import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Lexical {


//Sayaclar
 static	int iliskisel_S=0,sayisal_S=0,mantiksal_S=0;
 //tekli i�in say�sal- ikili de yap�labilirdi
 static	int tekli=0,ikili=0;	
 static	int operand=0;
 
//Pattern ve match Regex i�in
static Pattern pattern;
static	Matcher match ;
 
 public static String control(String line) {
	 
	
//�L��K�SEL OPERAT�R

		 pattern= Pattern.compile("(==|!=|<|<=|>|>=)");	 // Kullanaca��m�z Regex d�zenini olu�turduk
		 match = pattern.matcher(line);					// String ifade �zerindeki e�le�meyi bulduk
		 
		 while(match.find()) iliskisel_S++;
				
		 match.reset();

	
//SAYISAL OPERAT�R

		pattern=Pattern.compile("[^.\\n\\/\\*]\\*|\\/|%|[\\w\\d\\s]=[\\w\\d\\s]|[\\w\\d\\s]\\+[\\w\\s\\d]|[\\w\\d]-[\\w\\d]");
		match = pattern.matcher(line);				
		while(match.find()) {ikili++; 	sayisal_S++;}	
		
		match.reset();

		//tekli ve sayisal

		pattern=Pattern.compile("\\+\\+|--|[^\\w\\d\\+]\\+[\\w\\d]|[^-\\w\\d]-[\\d\\w]");
		match = pattern.matcher(line);				
		while(match.find()) {tekli++;	sayisal_S++;	}
		
			


			
		
		
//MANTIKSAL OPERAT�R

			
		pattern=Pattern.compile("\\&\\&|\\|\\||\\[\\^\\&\\]\\&[\\^\\&]|\\||\\^|\\^\\=|\\&\\=|\\|\\=|\\![^\\=]");
		match = pattern.matcher(line);			
		while(match.find()) mantiksal_S++;
	
//bulunan t�m verileri string olarak d�nd�r�yoruz.
		
		
		
		
		operand=((sayisal_S+iliskisel_S+mantiksal_S)*2)-tekli;
		String yazdir=line+"\nOperat�r Bilgisi:"
							+ "\n\tTekli Operat�r Say�s�:  "+tekli
							+ "\n\t�kili Operat�r Say�s�:  "+ikili
							+ "\n\tSayisal Operat�r Say�s�:  "+sayisal_S
							+ "\n\t�li�kisel Operat�r Say�s�:  "+iliskisel_S
							+ "\n\tMant�ksal Operat�r Say�s�:  "+mantiksal_S
						+"\nOperand Bilgisi:"
							+ "\n\tToplam Operand Say�s�:  "+operand;

		return yazdir;
	}
	
}
