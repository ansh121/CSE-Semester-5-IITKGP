/*
Name - Anshul Choudhary
Roll No. - 17CS10005
Tutorial - 3 (Closest pair problem)
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
using namespace std;

int compX(const void *a1, const void *b1){			// compare function to sort according to x-coordinate
	const int *a = *(const int**) a1;
	const int *b = *(const int**) b1;
	return a[0]-b[0];
}

int compY(const void *a1, const void *b1){			// compare function to sort according to y-coordinate
	const int *a = *(const int**) a1;
	const int *b = *(const int**) b1;
	return a[1]-b[1];
}

double dist(int *a, int *b){						// function to clalulate distance between 2 points
	return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

int* allocate(int *X){								// function to allocate memory and provide values for new point
	int *y=(int*) malloc(2*sizeof(int));
	y[0]=X[0];
	y[1]=X[1];
	return y;
}

double findClosest(int **X, int **Y, int n){		// recursive function to calculate minimum distance


	if(n<=3){										// using brute force for end case when points <= 3
		int i,j;
		double min=100000000,d;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				d=dist(X[i],X[j]);
				if(d<min) min=d;
			}
		}
		return min;
	}




	int i,j,k,mid=n/2;

	int **tempY1,**tempY2;							// partiton Y sorted array into two parts according to the x-coorinate of X[mid]
	tempY1=(int**) malloc((n/2+1)*sizeof(int*));	// y sorted points having x-cordinate less than that of X[mid] 
	tempY2=(int**) malloc((n/2+1)*sizeof(int*));	// y sorted points having x-cordinate greater than or equal to that of X[mid] 

	j=0;k=0;										// provide points to tempY1 and tempY2 accordingly
	for(i=0;i<n;i++){
		if(Y[i][0]<X[mid][0]){
			tempY1[j++]=allocate(Y[i]);
		}
		else{
			tempY2[k++]=allocate(Y[i]);
		}
	}

	double d1=findClosest(X,tempY1,mid);			// recursive call on left partition
	double d2=findClosest(X+mid,tempY2,n-mid);		// recursive call on right partition

	double min;										// min contain the minimum of the two calclated values
	if(d2<d1) min=d2;
	else min=d1;

	free(tempY1);									// free un-necessary memory
	free(tempY2);





	int **strip=(int**) malloc(n*sizeof(int*));		// array contaning points having x coordinate in the range (X[mid]-min, X[mid]+min) i.e. central strip with distance min both sides
	j=0;
	for(i=0;i<n;i++){								// filter all points of strip in strip sorted according to y-coordinate; 
		if(abs(Y[i][0]-X[mid][0])<min){
			strip[j++]=allocate(Y[i]);
		}
	}

	n=j;
	for(i=0;i<n;i++){								// find closest pair in the strip
		for(j=i+1;j<n && strip[j][1]-strip[i][1]<min;j++){
			if(dist(strip[i],strip[j])<min) min=dist(strip[i],strip[j]);
		}
	}

	free(strip);									// free un-necessary memory
	return min;										// return minimum distance

}

int main() {
	int i,j,n,**X,**Y,x;
	X=(int**)malloc(1000*sizeof(int*));		//array containing points sorted according to X coordinate
	Y=(int**)malloc(1000*sizeof(int*));		//array containing points sorted according to Y coordinate

	cout << "Enter number of points (less than 600): ";
	cin >> n;

	if(n>600 || n<0){
		cout << "Invalid number" << endl;
		return main();
	}

	srand(time(0));

	int done[700];
	for(i=0;i<700;i++) done[i]=0;			// array to check x co-ordinate availability

	for(i=0;i<n;i++){						// Generating n random points having distinct x-coordinates
		X[i]=(int*)malloc(2*sizeof(int));
		Y[i]=(int*)malloc(2*sizeof(int));
		
		x=rand()%641+10;
		while(done[x]==1) x=rand()%641+10;	// checking x-coordinate repetition
		done[x]=1;

		X[i][0]=Y[i][0]=x;
		X[i][1]=Y[i][1]=rand()%391+10;
	}

	qsort(X,n,sizeof(X[0]),compX);			// sort points according to x-coordinate and store in X 
	qsort(Y,n,sizeof(Y[0]),compY);			// sort points according to y-coordinate and store in Y




	cout << "Random points generated are : ";		// print points
	for(i=0;i<n;i++){											
		cout << '{' << X[i][0] << ',' << X[i][1] << "}, ";
	}
	cout << endl;



	double ans=findClosest(X,Y,n);			// function to find closest distance between 2 points



	cout << "closest distance is : " << ans << endl;  // print closest distance

	ofstream myfile;						// generating HTML file to print data set
  	myfile.open ("pairs.SVG");
	myfile << "<html>\n<body>\n<h1>Closest Pair : </h1>\n<svg width=\"700\" height=\"450\">\n<rect width=\"700\" height=\"450\" style=\"fill:rgb(255,255,255); stroke-width:0; stroke:rgb(0,0,0)\" />" << endl;		// file initials

	for(i=0;i<n;i++){						// providing point coordinates to generate circles
		myfile << "<circle cx=\"" << X[i][0] << "\" cy=\"" << X[i][1] << "\" r=\""<< ans/2 << "\" stroke=\"#0066ff\" stroke-width=\"0\" fill=\"#0066ff\" fill-opacity=\"0.4\" />\n<circle cx=\""<< X[i][0] <<"\" cy=\""<< X[i][1] <<"\" r=\"2\" stroke=\"black\" stroke-width=\"0\" fill=\"#000000\" />" << endl;
	}

	myfile << "</svg>\n</body>\n</html>"<< endl;	// closing tags
	myfile.close();
	free(X);								//free allocated memory
	free(Y);
	return 0;
}