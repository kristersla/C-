/*******************************************
Kristers Laganovskis, kl24033
B19. Atrast visus simetriskus skaitļus intervālā [n, m], kurus kāpinot kvadrātā iegūst simetrisku skaitli.
Skaitļu dalīšana ciparos jāveic skaitliski. Risinājumā izmantot funkciju, kas noskaidro, vai skaitlis ir
simetrisks (Piemēram, skaitlim 2341 simetriskais skaitlis ir 1432).
Programma izveidota: 30.09.2024.
*******************************************/
#include <iostream>
using namespace std;

// Funkcija, kas pārbauda, vai skaitlis ir simetrisks.
// Tā veic skaitļa apgriešanu un pārbauda, vai tas ir vienāds ar sākotnējo skaitli.
void simetrisks(int skaitlis){

    int kapinats_skaitlis = skaitlis;
    int atmuguriski = 0;

    // cikls, kas sadala skaitli pa cipariem un apgriež to.
    do{
        int pedejais_cipars = skaitlis % 10;
        atmuguriski = atmuguriski * 10 + pedejais_cipars;
        skaitlis = skaitlis / 10;
    }while (skaitlis > 0);

    // Ja sākotnējais skaitlis ir vienāds ar apgriezto, tas ir simetrisks un izvada lietotājam paziņojumu.
    if (kapinats_skaitlis == atmuguriski) {
        cout<<"Simetrisks skaitlis: "<<kapinats_skaitlis<<endl;
    }
}

int main(){

    int ievade = 1;

    do{
        int n, m;

        // Lietotājam tiek lūgts ievadīt intervāla sākuma un beigu vērtības (n, m)
        cout<<"Ievadi pirmo skaitli: " <<endl;
        cin>>n;
        cout<<"Ievadi otro skaitli: " <<endl;
        cin>>m;

        // Ja n un m ir abi 0, tad izvada 0 un nepārbauda intervālu
        if (n == 0 && m == 0) {
            cout << 0 << endl;
        } else {

            // Cikls, kas kāpina katru skaitli intervālā [n, m], pārbauda katru kāpināto skaitli vai, tas ir simetrisks.
            for (int skaitlis = n; skaitlis <= m; skaitlis++) {

                int kapinats_skaitlis = skaitlis * skaitlis;
                simetrisks(kapinats_skaitlis);
            }
        }

        // Tiek jautāts lietotājam vai vēlas turpināt programmu.
        cout<<"Ievadi (1), ja velies turpinat, ievadi (0), ja velies beigt programmu: "<<endl;
        cin>>ievade;

    }while(ievade==1);

    return 0;
}
