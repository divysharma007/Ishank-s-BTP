#include<bits/stdc++.h>
using namespace::std ;

const long Na = 79 ;
const long Nt = 5001 ;


int main (int argc, char *argv[]){
	
	ifstream dataStream ;
	ofstream avgStream ;
	
	long atomID ;
	int part,adx,ady;
	double XXsum = 0.0, YYsum = 0.0,xcor,ycor ;
	static double x[Nt], y[Nt] ;

	
	avgStream.open("avg_pos.dat", ios::out) ;
	
	dataStream.open("ploc.txt", ios::in) ;
	
	for(long i=0 ; i<Nt ; i++) {
	
		for(int j=0 ; j<3 ; j++) dataStream.ignore(10000,'\n') ;
		for(long j=0 ; j<Na ; j++) {
			
			dataStream>>part>>xcor>>ycor>>adx>>ady;
			dataStream.ignore(10000,'\n') ;
            XXsum += xcor;
            YYsum += ycor;
            //cout << part << " " << xcor << " " << ycor << " " << adx << " " << ady << endl;
        }
        x[i] = (XXsum) / Na;
        y[i]=(YYsum) / Na;
        XXsum=0;
        YYsum=0;
    }

	dataStream.close() ;

	
	for(long i = 0 ; i < Nt ; i++) 
		avgStream<<i<<"\t"<<x[i]<<"\t"<<y[i]<<"\n" ;
	
	avgStream.close() ;
	
	return 0 ;
	
}
