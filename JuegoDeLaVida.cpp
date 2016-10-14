/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "JuegoDeLaVida.h"
using namespace std;

///Constructor vacío de JuegoDeLaVida
JuegoDeLaVida::JuegoDeLaVida(){
    
}

///Constructor de JuegoDeLaVida
JuegoDeLaVida::JuegoDeLaVida(int dimensionTab, int** contenidoTab){
    this->dimensionTab = dimensionTab;
    this->contenidoTab = contenidoTab;
}

///Destructor de JuegoDeLaVida
JuegoDeLaVida::~JuegoDeLaVida(){
}

void JuegoDeLaVida::Iniciar(JuegoDeLaVida&){
    ///////////////////////////////////////////
    
    ///Construcción arreglo 2d para el Tablero temporal
    int** contTemporal = new int*[dimensionTab];
    for (int i = 0; i < dimensionTab; i++) {
        contTemporal[i] = new int[dimensionTab];
    }
    ///Inicialización valores Tablero temporal
    for (int i = 0; i < dimensionTab; i++) {
        for (int j = 0; j < dimensionTab; j++) {
            contTemporal[i][j] = 0;
        }
    }
    /////////////////////////////////////////////
    
    JuegoDeLaVida* Jtemp = new JuegoDeLaVida(this->dimensionTab,this->contenidoTab);
    Jtemp->Supervivencia(*Jtemp,contTemporal);
}

void JuegoDeLaVida::Iniciar(JuegoDeLaVida&, int NumGen){
    ///////////////////////////////////////////
    
    ///Construcción arreglo 2d para el Tablero temporal
    int** contTemporal = new int*[dimensionTab];
    for (int i = 0; i < dimensionTab; i++) {
        contTemporal[i] = new int[dimensionTab];
    }
    ///Inicialización valores Tablero temporal
    for (int i = 0; i < dimensionTab; i++) {
        for (int j = 0; j < dimensionTab; j++) {
            contTemporal[i][j] = 0;
        }
    }
    /////////////////////////////////////////////
    
    JuegoDeLaVida* Jtemp = new JuegoDeLaVida(this->dimensionTab,this->contenidoTab);
    Jtemp->Supervivencia(*Jtemp,contTemporal,NumGen);
}

void JuegoDeLaVida::Supervivencia(JuegoDeLaVida&,int** contTemporal, int NumGen){
    JuegoDeLaVida* Jtemp = new JuegoDeLaVida(this->dimensionTab,this->contenidoTab);
    for(int a=0;a<NumGen;a++){
        for (int i = 1; i < dimensionTab-1; i++) {
            for (int j = 1; j < dimensionTab-1; j++) {
                ///Renacimiento celulas 
                if(contenidoTab[i][j] == 0){
                    int temp1=0;
                    if(contenidoTab[i][j-1]==1){temp1++;}
                    if(contenidoTab[i][j+1]==1){temp1++;}
                    if(contenidoTab[i-1][j-1]==1){temp1++;}
                    if(contenidoTab[i-1][j]==1){temp1++;}
                    if(contenidoTab[i-1][j+1]==1){temp1++;}
                    if(contenidoTab[i+1][j-1]==1){temp1++;}
                    if(contenidoTab[i+1][j]==1){temp1++;}
                    if(contenidoTab[i+1][j+1]==1){temp1++;}
                    //cout<<"i="<<i<<" j="<<j<<" temp1="<<temp1<<endl;
                    if(temp1==3){contTemporal[i][j]=1;}
                    if(temp1<3 || temp1>3){contTemporal[i][j]=0;}

                }
                ///Supervivencia celulas
                else if(contenidoTab[i][j] == 1){
                    int temp2=0;
                    if(contenidoTab[i][j-1]==1){temp2++;}
                    if(contenidoTab[i][j+1]==1){temp2++;}
                    if(contenidoTab[i-1][j-1]==1){temp2++;}
                    if(contenidoTab[i-1][j]==1){temp2++;}
                    if(contenidoTab[i-1][j+1]==1){temp2++;}
                    if(contenidoTab[i+1][j-1]==1){temp2++;}
                    if(contenidoTab[i+1][j]==1){temp2++;}
                    if(contenidoTab[i+1][j+1]==1){temp2++;}
                    //cout<<"i="<<i<<" j="<<j<<" temp2="<<temp2<<endl;
                    if(temp2==2 || temp2==3){contTemporal[i][j]=1;}
                    if(temp2<2 || temp2>3){contTemporal[i][j]=0;}

                }
            }
        }
        ///Igualación contenido a contenido temporal
        for (int i = 0; i < dimensionTab; i++) {
            for (int j = 0; j < dimensionTab; j++) {
                contenidoTab[i][j] = contTemporal[i][j];
            }
        }
        
        Jtemp->Imprimir(*Jtemp); 
    }
    
}

void JuegoDeLaVida::Supervivencia(JuegoDeLaVida&,int** contTemporal){
    JuegoDeLaVida* Jtemp = new JuegoDeLaVida(this->dimensionTab,this->contenidoTab);
    while(contenidoTab!= contTemporal){
        for (int i = 1; i < dimensionTab-1; i++) {
            for (int j = 1; j < dimensionTab-1; j++) {
                ///Renacimiento celulas 
                if(contenidoTab[i][j] == 0){
                    int temp1=0;
                    if(contenidoTab[i][j-1]==1){temp1++;}
                    if(contenidoTab[i][j+1]==1){temp1++;}
                    if(contenidoTab[i-1][j-1]==1){temp1++;}
                    if(contenidoTab[i-1][j]==1){temp1++;}
                    if(contenidoTab[i-1][j+1]==1){temp1++;}
                    if(contenidoTab[i+1][j-1]==1){temp1++;}
                    if(contenidoTab[i+1][j]==1){temp1++;}
                    if(contenidoTab[i+1][j+1]==1){temp1++;}
                    //cout<<"i="<<i<<" j="<<j<<" temp1="<<temp1<<endl;
                    if(temp1==3){contTemporal[i][j]=1;}
                    if(temp1<3 || temp1>3){contTemporal[i][j]=0;}

                }
                ///Supervivencia celulas
                else if(contenidoTab[i][j] == 1){
                    int temp2=0;
                    if(contenidoTab[i][j-1]==1){temp2++;}
                    if(contenidoTab[i][j+1]==1){temp2++;}
                    if(contenidoTab[i-1][j-1]==1){temp2++;}
                    if(contenidoTab[i-1][j]==1){temp2++;}
                    if(contenidoTab[i-1][j+1]==1){temp2++;}
                    if(contenidoTab[i+1][j-1]==1){temp2++;}
                    if(contenidoTab[i+1][j]==1){temp2++;}
                    if(contenidoTab[i+1][j+1]==1){temp2++;}
                    //cout<<"i="<<i<<" j="<<j<<" temp2="<<temp2<<endl;
                    if(temp2==2 || temp2==3){contTemporal[i][j]=1;}
                    if(temp2<2 || temp2>3){contTemporal[i][j]=0;}

                }
            }
        }
        ///Igualación contenido a contenido temporal
        for (int i = 0; i < dimensionTab; i++) {
            for (int j = 0; j < dimensionTab; j++) {
                contenidoTab[i][j] = contTemporal[i][j];
            }
        }
        
        Jtemp->Imprimir(*Jtemp); 
    }
    
}

void JuegoDeLaVida::Imprimir(const JuegoDeLaVida&){
    for(int i = 0; i < dimensionTab; i++){
        for(int j=0; j< dimensionTab ;j++){
            cout << contenidoTab[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"------------------------"<<endl;
}

void JuegoDeLaVida::Vaciar(JuegoDeLaVida&){
    for(int i = 0; i < dimensionTab; i++){
        for(int j=0; j< dimensionTab ;j++){
            contenidoTab[i][j]=0;
        }
    }
}
