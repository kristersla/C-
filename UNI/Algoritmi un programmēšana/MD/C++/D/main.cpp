/*******************************************
Kristers Laganovskis, kl24033

Izveidot programmu valodā C++, izmantojot objektorientētās programmēšanas līdzekļus un strukturējot programmu vismaz trīs failos.
Klases hederi obligāti novietot atsevišķā hedera failā (program.h). Visas metodes realizēt ārpus hedera faila – speciālā C++ failā (program.cpp).
Funkcija main ievietojama vēl citā C++ failā (main.cpp). Klases dati pēc noklusēšanas ir slēpti (private), bet metodes atklātas (public).
Šīs programmas ietvaros NAV obligāti jānodrošina tāda lietotāja saskarne, kāda tika prasīta iepriekšējos trīs uzdevumos (main funkciju drīkst “cieti” iekodēt).
Citas prasības sk. Laboratorijas darbu noteikumos.

D13. Izveidot klasi "Simbolu steks", kurā glabājas masīvs ar simboliskām vērtībām (char) garumā 5 un steka elementu skaits.
Klasei izveidot šādas metodes: (1) konstruktors, (2) destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu
(ja likvidēšanas brīdī steks nav tukšs), (3) metode "Push", kas pievieno stekam elementu, ja tas nav pilns, (4) metode "Pop",
kas izņem no steka augšējo elementu un atgriež tā vērtību, (5) metode "Count", kas atgriež elementu skaitu stekā, (6) metode "Top",
kas atgriež augšējā elementa vērtību, (7) metode "IsEmpty", kas noskaidro, vai steks ir tukšs, (8) metode "IsFull", kas noskaidro,
vai steks ir pilns. Pirms uzdevuma veikšanas precīzi noskaidrot, ko nozīmē jēdziens steks (stack) kā datu struktūra.

Programma izveidota: 12.5.2024.
*******************************************/


#include <iostream>
#include "program.h"
using namespace std;

int main()
{

    Simbolu_steks steks;

    //Tiek pievienoti visi simboli stakam.

    steks.Push('a');
    steks.Push('b');
    steks.Push('c');
    steks.Push('d');
    steks.Push('e');

    //Tiek pievienots sesais simbols, kas ir lieks. Lai demonstrētu, kas notiek, kad tiek pievienoti par daudz simbolu stakam.
    steks.Push('f');

    cout<<"Elementu skaits stekā: "<<steks.Count()<<endl;

    cout<<"Augšējais elements: "<<steks.Top()<<endl;

    while (!steks.IsEmpty()){

           cout<<"Izņemts elements: "<<steks.Pop()<<endl;

           }

    //Tiek demonstrēts, kas notiek, ja tiek izņemts simbols, kad stakā vairs nav neviena simbola.
    steks.Pop();


    return 0;
}
