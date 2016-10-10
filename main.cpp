/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: esteban
 *
 * Created on October 7, 2016, 4:18 PM
 */

#include "Tablero.h"
#include "Juego.h"
using namespace std;
int main(int argc, char *argv[]) {
    
    
    
    cout << "Juego de la vida" << endl << "-----------------------" << endl;
    ///Construcción arreglo 2d para el tablero
    int dimension=12;
    int** cont = new int*[dimension];
    for (int i = 0; i < dimension; i++) {
        cont[i] = new int[dimension];
    }
    ///Inicialización valores tablero valores Tablero
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cont[i][j] = 0;
        }
    }
    
    ///Construcción patrones
    ///Patrón bloques centrales oscilantes
    /*cont[3][3]=1;
    cont[3][4]=1;
    cont[4][3]=1;
    cont[4][4]=1;
    
    cont[5][5]=1;
    cont[5][6]=1;
    cont[6][5]=1;
    cont[6][6]=1;*/
    
    ///Patrón linea oscilante vertical-horizontal
    cont[5][4]=1;
    cont[5][5]=1;
    cont[5][6]=1;
    
    ///Construcción e impresión estado inicial tablero  
    Tablero* T=new Tablero(dimension,cont);
    T->imprimir(*T);
    cout<<"------------------------"<<endl;

    /////////////////////////////////////////////
    
    ///Construcción arreglo 2d para el Tablero temporal
    int** contTemporal = new int*[dimension];
    for (int i = 0; i < dimension; i++) {
        contTemporal[i] = new int[dimension];
    }
    ///Inicialización valores Tablero temporal
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            contTemporal[i][j] = 0;
        }
    }
    /////////////////////////////////////////////
    
    int NumGen=20;
    for(int a=0;a<NumGen;a++){
    for (int i = 1; i < dimension-1; i++) {
        for (int j = 1; j < dimension-1; j++) {
            ///Renacimiento celulas 
            if(cont[i][j] == 0){
                int temp1=0;
                if(cont[i][j-1]==1){temp1++;}
                if(cont[i][j+1]==1){temp1++;}
                if(cont[i-1][j-1]==1){temp1++;}
                if(cont[i-1][j]==1){temp1++;}
                if(cont[i-1][j+1]==1){temp1++;}
                if(cont[i+1][j-1]==1){temp1++;}
                if(cont[i+1][j]==1){temp1++;}
                if(cont[i+1][j+1]==1){temp1++;}
                //cout<<"i="<<i<<" j="<<j<<" temp1="<<temp1<<endl;
                if(temp1==3){contTemporal[i][j]=1;}
                if(temp1<3 || temp1>3){contTemporal[i][j]=0;}
                
            }
            ///Supervivencia celulas
            else if(cont[i][j] == 1){
                int temp2=0;
                if(cont[i][j-1]==1){temp2++;}
                if(cont[i][j+1]==1){temp2++;}
                if(cont[i-1][j-1]==1){temp2++;}
                if(cont[i-1][j]==1){temp2++;}
                if(cont[i-1][j+1]==1){temp2++;}
                if(cont[i+1][j-1]==1){temp2++;}
                if(cont[i+1][j]==1){temp2++;}
                if(cont[i+1][j+1]==1){temp2++;}
                //cout<<"i="<<i<<" j="<<j<<" temp2="<<temp2<<endl;
                if(temp2==2 || temp2==3){contTemporal[i][j]=1;}
                if(temp2<2 || temp2>3){contTemporal[i][j]=0;}
                
            }
    }
    }
    ///Igualación contenido a contenido temporal
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cont[i][j] = contTemporal[i][j];
        }
    }
    Tablero* T=new Tablero(dimension,cont);
    T->imprimir(*T);
    cout<<"-----------------------"<<endl; 
}
    return 0;
}
