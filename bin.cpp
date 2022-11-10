#include<bits/stdc++.h>
using namespace::std ;

const long Na = 72 ;
const long Nt = 5000 ;


int main (int argc, char *argv[]){
	
	ifstream dataStream1, dataStream2 ;
	ofstream binStream ;
    
    long atomID ;
	int part1,part2,adx,ady,binNum;
	double xcor,ycor ;
    double sum,Ux,Uy,Wz ;
	vector<vector<double>>bin(10,vector<double>(Nt)) ;
	binStream.open("bin.dat", ios::out) ;
	dataStream1.open("ploc.txt", ios::in) ;
    dataStream2.open("uwvl.txt", ios::in) ;
	
	for(long i=4999 ; i<Nt ; i++) {
        vector<int> cnt(10);
        for(int j=0 ; j<3 ; j++) {dataStream1.ignore(10000,'\n') ;dataStream2.ignore(10000,'\n') ;}
        for(int j=0 ; j<7 ; j++)  dataStream1.ignore(10000, '\n');
        for(long j=0 ; j<Na ; j++) {
			
			dataStream1>>part1>>xcor>>ycor>>adx>>ady;
            dataStream2>>part2>>Ux>>Uy>>Wz;
			dataStream1.ignore(10000,'\n') ;
            dataStream2.ignore(10000,'\n') ;
            binNum = ycor / 4.2;
            bin[binNum][i] += Ux;
            cnt[binNum]++;
            // cout<<part1<<" "<<ycor<<" "<<binNum<<" "<<Ux<<endl;
        }
        for (int j = 0; j < 10;j++){
            if(cnt[j]){
                bin[j][i] /= cnt[j];
            }
            // cout<<j<<" "<<cnt[j]<<endl;
        }
         
    }
    for (int i = 0; i < 10;i++){
           sum = 0;
        for (int j = 0; j < Nt;j++){
            sum += bin[i][j];
        }
        binStream << i << " " << (sum) / (float)Nt << "\n";
     
    }

        return 0;
	
}
