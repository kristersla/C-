#include <iostream>

using namespace std;

void simetrisks(int skaitlis) {
    int kapinats_skaitlis = skaitlis;
    int atmuguriski = 0;

    do {
        int pedejais_cipars = skaitlis % 10;
        atmuguriski = atmuguriski * 10 + pedejais_cipars;
        skaitlis = skaitlis / 10;
    } while (skaitlis > 0);

    if (kapinats_skaitlis == atmuguriski) {
        cout<< kapinats_skaitlis <<" ir simetrisks skaitlis kapinot ar 2"<<endl;
    }
}

int main() {
    int n, m;

    cout << "Ievadi pirmo skaitli: " << endl;
    cin >> n;
    cout << "Ievadi otro skaitli: " << endl;
    cin >> m;

    for (int skaitlis = n; skaitlis <= m; skaitlis++) {
        int kapinats_skaitlis = skaitlis * skaitlis;
        simetrisks(kapinats_skaitlis);
    }

    return 0;
}
