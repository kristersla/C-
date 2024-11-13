/********************************************************************************************
Kristers Laganovskis, kl24033

Izveidot programmu valodā C++, obligāti izmantojot norādītās vai kādas citas funkcijas.
Prasības tādas pašas kā iepriekšējā uzdevumā, precīzāk sk. Laboratorijas darbu noteikumos.

C19. Dots masīvs no veseliem nenegatīviem skaitļiem A(n). Atrast tā elementa indeksu, kuram pirms
tā esošo skaitļu summa vismazāk atšķiras no pēc tā esošo skaitļu summas.

Programma tika izveidota: 13.11.2024.
********************************************************************************************/
#include <iostream>
using namespace std;

/***********************
int TuvakaisIndekss(int arr[5]);
Funkcija TuvakaisIndekss(int arr[5]) -

atgriež kā rezultātu tuvāko arr masīva indeksu, kuram pirms
tā esošo skaitļu summa vismazāk atšķiras no pēc tā esošo skaitļu summas.

***********************/

int TuvakaisIndekss(int arr[5]){

	int total_sum = 0;

	//Tiek iegūts masīva - arr - kopsumma.
    for (int i = 0; i < 5; i++) {
        total_sum += arr[i];
    }

    int kreisa_puse = 0;
    int minimala_starpiba = total_sum;
    int tuvakais_indekss = -1;
    int paslaik_starp;

	//Tiek iegūta katra starpība starp indeksa pusēm.
    for (int i = 0; i < 5; i++) {
        int right_sum = total_sum - kreisa_puse - arr[i]; //Tiek iegūta labās puses kopsumma.
        paslaik_starp = kreisa_puse - right_sum;

        //Ja starpība ir ar negatīvu vērtību, tad vērtība tiek pārvērsta par pozitīvu (modulis).
        if (paslaik_starp < 0) {
            paslaik_starp = -paslaik_starp;
        }

		//Tiek noteikts tuvākais indekss.
        if (paslaik_starp < minimala_starpiba) {
            minimala_starpiba = paslaik_starp;
            tuvakais_indekss = i;
        }

        kreisa_puse += arr[i]; //Pieskaita klāt arr[i] pie kreisās puses.
    }

    return tuvakais_indekss;
}

int main() {

    int arr[5] = {1,4,6,2,9};
    int tuvakais_indekss = TuvakaisIndekss(arr); //Tiek inicializēta funkcija.

    cout<<"Tuvakais indekss: "<<tuvakais_indekss<<endl;

	return 0;
}
