#include <stdio.h>
#include <string.h>
#include <math.h>

double strtofloat (char *arrayOfNumber){
	 double y=0;
          int i = 0;
          int indexdot=0;
          int strlength=strlen(arrayOfNumber);
          int flag =0;
	        int ascii_value=0;
    for(indexdot=0;indexdot<strlength;indexdot++)
    if(arrayOfNumber[indexdot]=='.'){
            flag =1;
            break;}
       while (arrayOfNumber[i] != '\0' ) {
         if(arrayOfNumber[i]=='.'){break;}
          ascii_value = arrayOfNumber[i];
         y+= (ascii_value - 48)*pow(10,((indexdot-1)-i)); // Subtracting 48 to convert ASCII to integer
         i++;
    }
    if(flag){
    i++;
     while (arrayOfNumber[i] != '\0') {

         ascii_value = arrayOfNumber[i];
         y+= (ascii_value - 48)*(pow(10,-((i-indexdot)))); // Subtracting 48 to convert ASCII to integer
         i++;
    }
    }
		return y;
	  }
