/*******************************************
Kristers Laganovskis, kl24033
B19. Atrast visus simetriskus skaitļus intervālā [n, m], kurus kāpinot kvadrātā iegūst simetrisku skaitli.
Skaitļu dalīšana ciparos jāveic skaitliski. Risinājumā izmantot funkciju, kas noskaidro, vai skaitlis ir
simetrisks (Piemēram, skaitlim 2341 simetriskais skaitlis ir 1432).
Programma izveidota: 30.09.2024.
*******************************************/

#include <iostream>
using namespace std;

/*******************************************
bool simetrisks(int skaitlis)
Funkcija simetrisks(int skaitlis) -

Funkcija pārbauda katru padoto skaitli, kas ir kvadrātā atsvevišķi vai, tas ir vienāds ar šo pašu skaitli, bet apgriestu otrādāk (Z-A).
Ja, šie skaitļi ir vinādi, tad tiek atgriesta vērtība - true, bet ja nē - false.
*******************************************/

bool simetrisks(int skaitlis) {
    int kapinats_skaitlis = skaitlis; // Saglabā sākotnējo skaitli
    int atmuguriski = 0; // Sākam ar 0, lai veidotu apgriezto skaitli

    // while cikls, kas sadala skaitli pa cipariem un pēc tam veido apgriezto skaitli.
    while (skaitlis > 0) {
        int pedejais_cipars = skaitlis % 10;
        atmuguriski = atmuguriski * 10 + pedejais_cipars;
        skaitlis = skaitlis / 10;
    }

    // Ja sākotnējais skaitlis ir vienāds ar apgriezto, tas ir simetrisks un tiek atgriezta vērtība true.
    if (kapinats_skaitlis == atmuguriski){
        return true;
    }else{
        return false;
    }
}

int main() {
    int ievade = 1;

    // while cikls, kas ļauj programmu darbināt vairākas reizes, līdz lietotājs izvēlas beigt programmu.
    do {
        int n, m;

        // Lietotājam tiek lūgts ievadīt intervāla sākuma un beigu vērtības (n, m).
        cout << "Ievadi pirmo skaitli: " << endl;
        cin >> n;
        cout << "Ievadi otro skaitli: " << endl;
        cin >> m;

        bool atrasts_simetrisks = false; // Mainīgais, lai sekotu līdzi, vai kāds simetrisks skaitlis ir atrasts

        // Cikls, kas kāpina katru skaitli intervālā [n,m], pārbauda katru kāpināto skaitli vai tas ir simetrisks.
        for (int skaitlis = n; skaitlis <= m; skaitlis++) {
            int kapinats_skaitlis = skaitlis * skaitlis;

            // Funkcija, kas pārbauda simetriju.
            if (simetrisks(kapinats_skaitlis)==true) {
                cout << "Simetrisks skaitlis: " << skaitlis << ", kvadrāts: " << kapinats_skaitlis << endl;
                atrasts_simetrisks = true; // Norāda, ka vismaz viens simetrisks skaitlis ir atrasts
            }
        }

        // Ja nav atrasts neviens simetrisks skaitlis, izdrukā atbilstošu ziņu.
        if (!atrasts_simetrisks) {
            cout << "Nav atrasts neviens simetrisks skaitlis intervālā [" << n << ";" << m << "]" << endl;
        }

        // Tiek jautāts lietotājam, vai vēlas turpināt programmu.
        cout << "Ievadi (1), ja vēlies turpināt, ievadi (0), ja vēlies beigt programmu: " << endl;
        cin >> ievade;

    } while (ievade == 1);

    return 0;
}
