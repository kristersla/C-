/********************************************
Kristers Laganovskis, kl24033
A10. Doti divi naturāli skaitļi m un n. Noteikt skaitļa m pirmo n ciparu summu. Skaitļa dalīšana ciparos jāveic skaitliski.
Programma izveidota: 14.09.2024.
********************************************/

#include <iostream>
using namespace std;

int main() {
    int m, n;
    string choice = "1";

    while (choice == "1") {
        cout << "Ievadi naturalu skaitli m: ";
        cin >> m;

        cout << "Ievadi otru naturalu skaitli n: ";
        cin >> n;

        if (n <= 0 || m <= 0) {
            cout << "Nevar but negativs skaitlis vai 0!" << endl;
            cout << "Ievadi atkartoti!" << endl;
        } else {

            int digitCount = 0;
            int temp = m;

            while (temp > 0) {
                temp /= 10;
                digitCount++;
            }

            // If n is greater than the number of digits in m, adjust it to digitCount
            if (n > digitCount) {
                n = digitCount;
            }

            int sum = 0;
            temp = m;

            // Extract and sum the first n digits
            for (int i = 0; i < (digitCount - n); i++) {
                temp /= 10;  // Shift right to get rid of extra digits
            }

            // Now temp contains only the first n digits
            while (temp > 0) {
                sum += temp % 10;  // Add the last digit to the sum
                temp /= 10;        // Remove the last digit
            }

            cout << "Skaitla m pirmo " << n << " ciparu summa ir: " << sum << endl;
        }

        cout << "Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> choice;
    }

    cout << "Programma beigusies!" << endl;

    return 0;
}
