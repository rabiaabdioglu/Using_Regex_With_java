/**
*
* @author Rabia Abdioðlu 	-	rabia.abdioglu@ogr.sakarya.edu.tr
* @since  30.03.2022
* <p>
*		  1-C
* </p>
*/

package odev;
import java.io.*;
import java.util.Scanner;

public class Program {


	 public static void main(String[] args) {
	    	
		 
    	String code="",tmp="";		//yedek stringler    	
    	int isStringInCode=0;		//kod içindeki string ifade sayýsý --> "
    	boolean isComment=false,isComment2=false;	// yorum satýrý kontrolü için
	    	
    	//shellden gelecek parametre sayýsý kontrolü
    	if(args.length==2) System.out.println("Birden çok parametre girildi");
    	else if(args.length==0) System.out.println("Dosya parametresi girilmedi");
    	else {
		    	// parametre olarak verilen dosya yolu ile 
    			//java dosyasý içerisini satýr satýr okumak için
		    	try {
					Scanner scanner = new Scanner(new File(System.getProperty("user.dir")+"\\"+args[0]));
					while (scanner.hasNextLine()) 	tmp+=scanner.nextLine()+"\n";
					scanner.close();
					
				} catch (FileNotFoundException e) {
					e.printStackTrace();	}	
		    	
		    	
		    	
					
		    	//Yorum satýrlarý ve string ifadeleri kaldýrmak için
		    	for(int i=2;i<tmp.length();i++) {
		    
		    		//newline karakteri ise yorum satýrý deðildir
		    		if(tmp.charAt(i)=='\n' && isComment2==false)isComment=false;
		    	
		    		//yorum satýrlarýný silmek için
		    		if(tmp.charAt(i-1)=='\n' && (tmp.charAt(i)=='/'|| tmp.charAt(i)=='*'))isComment=true;
		    		if(tmp.charAt(i)=='/'&&tmp.charAt(i+1)=='/') isComment=true;
		    		
		    		//yorum satýrlarýný silmek için
		    		if(tmp.charAt(i)=='/'&&tmp.charAt(i+1)=='*')isComment2=true; 
		    		if(tmp.charAt(i-2)=='*'&&tmp.charAt(i-1)=='/')isComment2=false; 
		    	
		    		
		    		//Ekrana yazýlan stringleri silmek için 
		    		//iki adet " karakteri bulunursa string ifadeden çýkýlmýþ olur
		    		if(tmp.charAt(i)=='"') {isStringInCode++; isComment=true;}
		    		if(isStringInCode==2) {isComment=false;isStringInCode=0;}
		    		
		    			
		    		//eðer yorum satýrýnda deðil ise  code stringine charý atar
		    		if(isComment==false && isComment2==false) code+=tmp.charAt(i);
		    		
		    	
	   	}		
		
		    System.out.println("dshjhsdjhdj\n"+code); 
			System.out.print("\n\n______________________________________________________\n");

			//Lexical sýnýfýndaki control fonksiyonunu çaðýrýyor
			System.out.println(Lexical.control(code));	
			
			System.out.print("\n\n______________________________________________________\n");
		}
	}
}
