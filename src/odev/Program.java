/**
*
* @author Rabia Abdio�lu 	-	rabia.abdioglu@ogr.sakarya.edu.tr
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
    	int isStringInCode=0;		//kod i�indeki string ifade say�s� --> "
    	boolean isComment=false,isComment2=false;	// yorum sat�r� kontrol� i�in
	    	
    	//shellden gelecek parametre say�s� kontrol�
    	if(args.length==2) System.out.println("Birden �ok parametre girildi");
    	else if(args.length==0) System.out.println("Dosya parametresi girilmedi");
    	else {
		    	// parametre olarak verilen dosya yolu ile 
    			//java dosyas� i�erisini sat�r sat�r okumak i�in
		    	try {
					Scanner scanner = new Scanner(new File(System.getProperty("user.dir")+"\\"+args[0]));
					while (scanner.hasNextLine()) 	tmp+=scanner.nextLine()+"\n";
					scanner.close();
					
				} catch (FileNotFoundException e) {
					e.printStackTrace();	}	
		    	
		    	
		    	
					
		    	//Yorum sat�rlar� ve string ifadeleri kald�rmak i�in
		    	for(int i=2;i<tmp.length();i++) {
		    
		    		//newline karakteri ise yorum sat�r� de�ildir
		    		if(tmp.charAt(i)=='\n' && isComment2==false)isComment=false;
		    	
		    		//yorum sat�rlar�n� silmek i�in
		    		if(tmp.charAt(i-1)=='\n' && (tmp.charAt(i)=='/'|| tmp.charAt(i)=='*'))isComment=true;
		    		if(tmp.charAt(i)=='/'&&tmp.charAt(i+1)=='/') isComment=true;
		    		
		    		//yorum sat�rlar�n� silmek i�in
		    		if(tmp.charAt(i)=='/'&&tmp.charAt(i+1)=='*')isComment2=true; 
		    		if(tmp.charAt(i-2)=='*'&&tmp.charAt(i-1)=='/')isComment2=false; 
		    	
		    		
		    		//Ekrana yaz�lan stringleri silmek i�in 
		    		//iki adet " karakteri bulunursa string ifadeden ��k�lm�� olur
		    		if(tmp.charAt(i)=='"') {isStringInCode++; isComment=true;}
		    		if(isStringInCode==2) {isComment=false;isStringInCode=0;}
		    		
		    			
		    		//e�er yorum sat�r�nda de�il ise  code stringine char� atar
		    		if(isComment==false && isComment2==false) code+=tmp.charAt(i);
		    		
		    	
	   	}		
		
		    System.out.println("dshjhsdjhdj\n"+code); 
			System.out.print("\n\n______________________________________________________\n");

			//Lexical s�n�f�ndaki control fonksiyonunu �a��r�yor
			System.out.println(Lexical.control(code));	
			
			System.out.print("\n\n______________________________________________________\n");
		}
	}
}
