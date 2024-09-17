/********************************************
Kristers Laganovskis, kl24033
A10. Doti divi naturāli skaitļi m un n. Noteikt skaitļa m pirmo n ciparu summu. Skaitļa dalīšana ciparos jāveic skaitliski.
Programma izveidota: 14.09.2024.
********************************************/

#include <iostream>
#include <string> // Nepieciešams, lai pārveidotu skaitli 'm' par string un noteiktu ciparu virknes garumu.
using namespace std;

int main() {
    int m, n; // Deklarēti divi mainīgie, ko lietot ievades datiem.
    int izvele = 1; // Vērtība 1 ļauj programmai darboties, izmantojot 'while' ciklu.

    while (izvele == 1) {
        cout << "Ievadi naturalu skaitli m: ";
        cin >> m;

        cout << "Ievadi otru naturalu skaitli n: ";
        cin >> n;

        // Pārbauda, vai n vai m ir mazāks vai vienāds ar 0.
        if (n <= 0 || m <= 0) {
            cout << "Nevar but negativs skaitlis vai 0!" << endl;
            continue;
        }

        int cipars; // Katra cipara vērtība no skaitļa 'm'.
        int summa = 0; // Gala summa no skaitļa 'm' pirmajiem 'n' cipariem.
        int skaits = 0; // Ciparu skaitīšanai sāk vērtību no 0.
        int skaitlis_m = m; // Saglabā sākotnējo 'm' vērtību, lai vēlāk varētu izmantot.

        int ciparu_daudzums = to_string(m).length(); // Nosaka, cik ciparu ir skaitlī 'm'.

        int ciparu_masivs[ciparu_daudzums]; // Masīvs ciparu uzglabāšanai.

        // Izdala skaitļa 'm' ciparus un ievieto tos masīvā.
        while (m > 0) {
            cipars = m % 10;
            ciparu_masivs[ciparu_daudzums - skaits - 1] = cipars; // Apgriež ciparus, lai tie būtu pareizā secībā.
            m /= 10;
            skaits++;
        }

        // Ja 'n' ir lielāks par ciparu daudzumu 'm', izvada kļūdas ziņojumu un lūdz ievadīt skaitļus no jauna.
        if (n > ciparu_daudzums) {
            cout << "Skaitlis 'n' nevar but lielaks par 'm' ciparu virknes garumu!" << endl;
            continue;
        }

        // Saskaita masīva pirmos 'n' elementus.
        for (int i = 0; i < n; i++) {
            summa += ciparu_masivs[i];
        }

        // Izvada gala rezultātu.
        cout << "Skaitla " << skaitlis_m << " pirmo " << n << " ciparu summa ir " << summa << endl;

        // Jautā, vai turpināt vai beigt programmu.
        cout << "Vai turpinat (1) vai beigt (0)?" << endl;
        cin >> izvele;
    }

    cout << "Programma beigusies!" << endl;

    return 0;
}
