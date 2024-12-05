#include <iostream>
#include "program.h"
using namespace std;

//Simbolu_steks - konstruktors.

Simbolu_steks::Simbolu_steks(){

    elementu_sk = 0;

}

//Simbolu_steks - destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī steks nav tukšs).
Simbolu_steks::~Simbolu_steks(){

    cout<<"Tika likvidets objekts! Likvidēto elementu skaits: "<<elementu_sk<<endl;

}

//void Simbolu_steks::Push(char simbols) - metode "Push", kas pievieno stekam elementu, ja tas nav pilns.
void Simbolu_steks::Push(char simbols){

    if(!IsFull()){

        steks[elementu_sk] = simbols;
        elementu_sk++;

    }else{

        cout<<"Steks ir pilns! Nevar pievienot simbolu: "<<simbols<<endl;

    }

}

//char Simbolu_steks::Pop() - metode "Pop", kas izņem no steka augšējo elementu un atgriež tā vērtību.
char Simbolu_steks::Pop(){

    if(!IsEmpty()){

        elementu_sk--;
        return steks[elementu_sk];

    }else{

        cout<<"Steks ir tukšs! Nevar izņemt simbolu."<<endl;

    }

}

//int Simbolu_steks::Count() - metode "Count", kas atgriež elementu skaitu stekā.
int Simbolu_steks::Count(){

    return elementu_sk;

}

//char Simbolu_steks::Top() - metode "Top", kas atgriež augšējā elementa vērtību.
char Simbolu_steks::Top(){

    if(!IsEmpty()){
        return steks[elementu_sk - 1];
    }else{

        cout<<"Steks ir tukšs nav augšējā elementa"<<endl;

    }

}

//bool Simbolu_steks::IsEmpty() - metode "IsEmpty", kas noskaidro, vai steks ir tukšs.
bool Simbolu_steks::IsEmpty(){

    return elementu_sk == 0;

}

//bool Simbolu_steks::IsFull() - metode "IsFull", kas noskaidro, vai steks ir pilns.
bool Simbolu_steks::IsFull(){
    return elementu_sk == 5;

}
