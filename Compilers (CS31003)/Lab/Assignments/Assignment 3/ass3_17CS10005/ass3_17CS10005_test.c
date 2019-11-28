/******************************* 
Name - Anshul Choudhary
Roll No - 17CS10005
Assignment - 3 (Lexer for tinyC)
********************************/

/*//////////////////////	TEST_FILE	/////////////////////////*/

// test for keywords
float short union _Complex
Imaginary _Imaginary
While
while
sizeof
randomword
else
typedef register switch

// test for Identifiers
fjahdskjfhasdkjfhsdfk
56hbjhfd
4756475
Anshul Choudhary
17CS10005
a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
dhfdsKJFUKGFKfhsdh___FHgejhf
6g58 b6dh8d JGD9

// test for Constants
73464283
0
1
2
3
4
5
6
7
8
9
0987654
5242472565425743782479647937
63475468e+4637
37475467e-47676
653475.6546548674598
.5746357
0.4543775
45634558.
'a'
'b'
'ai'
fhgdshfgdshfgdsjhfgs
\' \'' \? \\
\a \b \f \n \r \t \v

// test for string literals
"fhjsfhffsfbr rbrkj burbg f gmnrberkjf\n"
"fgfdghfdgd dfghj dfgjh dgdfksfkdj b"

// test for Punctuators
[ ] ( ) { } . ->
++ -- & * + - ~ !
/ % << >> < > <= >= == != ^ | && ||
? : ; ...
= *= /= %= += -= <<= >>= &= ^= |=


//Bubble sort code 

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
   
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

// test for comments

// this is a comment

/* djhsf fjhdf sfhgfhsfjgs sf hj hfsf yjf jfsfee
efh egf
rb rgrjrjh gjyrb jdgjrd
jrfbrjhfb 
srhjvs rj

*/

/*djhfgjfhv  hbfhj bfjhbf j jdf fjhbf sf sfb b ///////////*/

/* fhjgefgfgsjhf hdsgfy fjh gsfgsjfjfgsejhgfejshvfc rfjhdjdjdyg
 jhfd jfjhdsjh jh djh fdjhg fjdhg hdfshgj vjjhf

 This comment does not contain closing syntax so this is a error in commenting