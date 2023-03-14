/**
*
* @author Rabia Abdioðlu 	-	rabia.abdioglu@ogr.sakarya.edu.tr
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
 //tekli için sayýsal- ikili de yapýlabilirdi
 static	int tekli=0,ikili=0;	
 static	int operand=0;
 
//Pattern ve match Regex için
static Pattern pattern;
static	Matcher match ;
 
 public static String control(String line) {
	 
	
//ÝLÝÞKÝSEL OPERATÖR

		 pattern= Pattern.compile("(==|!=|<|<=|>|>=)");	 // Kullanacaðýmýz Regex düzenini oluþturduk
		 match = pattern.matcher(line);					// String ifade üzerindeki eþleþmeyi bulduk
		 
		 while(match.find()) iliskisel_S++;
				
		 match.reset();

	
//SAYISAL OPERATÖR

		pattern=Pattern.compile("[^.\\n\\/\\*]\\*|\\/|%|[\\w\\d\\s]=[\\w\\d\\s]|[\\w\\d\\s]\\+[\\w\\s\\d]|[\\w\\d]-[\\w\\d]");
		match = pattern.matcher(line);				
		while(match.find()) {ikili++; 	sayisal_S++;}	
		
		match.reset();

		//tekli ve sayisal

		pattern=Pattern.compile("\\+\\+|--|[^\\w\\d\\+]\\+[\\w\\d]|[^-\\w\\d]-[\\d\\w]");
		match = pattern.matcher(line);				
		while(match.find()) {tekli++;	sayisal_S++;	}
		
			


			
		
		
//MANTIKSAL OPERATÖR

			
		pattern=Pattern.compile("\\&\\&|\\|\\||\\[\\^\\&\\]\\&[\\^\\&]|\\||\\^|\\^\\=|\\&\\=|\\|\\=|\\![^\\=]");
		match = pattern.matcher(line);			
		while(match.find()) mantiksal_S++;
	
//bulunan tüm verileri string olarak döndürüyoruz.
		
		
		
		
		operand=((sayisal_S+iliskisel_S+mantiksal_S)*2)-tekli;
		String yazdir=line+"\nOperatör Bilgisi:"
							+ "\n\tTekli Operatör Sayýsý:  "+tekli
							+ "\n\tÝkili Operatör Sayýsý:  "+ikili
							+ "\n\tSayisal Operatör Sayýsý:  "+sayisal_S
							+ "\n\tÝliþkisel Operatör Sayýsý:  "+iliskisel_S
							+ "\n\tMantýksal Operatör Sayýsý:  "+mantiksal_S
						+"\nOperand Bilgisi:"
							+ "\n\tToplam Operand Sayýsý:  "+operand;

		return yazdir;
	}
	
}
