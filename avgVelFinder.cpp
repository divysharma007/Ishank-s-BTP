#include<bits/stdc++.h>
using namespace::std ;

const long Na = 72 ;
const long Nt = 5000 ;


int main (int argc, char *argv[]){
	
	ifstream dataStream ;
	ofstream avgStream ;
	
	long atomID ;
    int part;
    double UxSum = 0.0, UySum = 0.0,Ux,Uy,Wz ;
	static double Vx[Nt], Vy[Nt] ;

	
	avgStream.open("avg_vel.dat", ios::out) ;
	
	dataStream.open("uwvl.txt", ios::in) ;
	
	for(long i=0 ; i<Nt ; i++) {
	
		for(int j=0 ; j<3 ; j++) dataStream.ignore(10000,'\n') ;
		for(long j=0 ; j<Na ; j++) {
			
			dataStream>>part>>Ux>>Uy>>Wz;
			dataStream.ignore(10000,'\n') ;
            UxSum +=Ux;
            UySum +=Uy;
            //cout << part << " " <<Ux << " " <<Uy << " " << Wz << endl;
        }
        Vx[i] = (UxSum) / Na;
        Vy[i]=(UySum) / Na;
        UxSum=0;
        UySum=0;
    }

	dataStream.close() ;

	
	for(long i = 0 ; i < Nt ; i++) 
		avgStream<<i<<"\t"<<Vx[i]<<"\t"<<Vy[i]<<"\n" ;
	
	avgStream.close() ;
	
	return 0 ;
	
}
