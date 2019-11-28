/******************************* 
Name - Anshul Choudhary
Roll No - 17CS10005
Assignment - 4 (Parser for tinyC)
********************************/

//Operators
int main(){
   int a,b,c;
   a=b+c;
   a=b-c;
   a=b*c;
   a=b/c;
   a+=b;
   a-=b;
   a*=b;
   a/=b;
   a=b<<c; a=b>>c; a=b>>(30); a=(30)<<a+b;
   a=!b;
   a=~b;
   a%=b;
   a=b^c;
   a=b&c;
   a=b&&c;
   --a;
   ++a;
   a=(b)?b:c;
   a&=b;
   a|=b;
   if(a) return 0;
   else return b;
   while(a<b){
      a++;
   }

   //general program
   int Q,K,i,j,b,C,ans=0,c,d,totald;
   int frontc[200001],backc[200001],frontd[200001],backd[200001],countf=0,countb=0;
   scanf("%d %d",&Q,&K);

   for(i=0;i<Q;i++){
      scanf("%d %d",&b,&C);
      c=C^ans;
      if(b==1){
         scanf("%d",&d);
         frontc[countf]=c;
         frontd[countf]=d;
         countf++;
      }
      else if(b==2){
         scanf("%d",&d);
         backc[countb]=c;
         backd[countb]=d;
         countb++;
      }
      else if(b==3){
         totald=0;
         for(j=0;j<countf;j++){
            if(frontc[j]<=c+K && frontc[j]>=c-K)totald+=frontd[j];
         }
         for(j=0;j<countb;j++){
            if(backc[j]<=c+K && backc[j]>=c-K)totald+=backd[j];
         }

         printf("%d\n",totald);
         ans=totald;
      }
   }

}
