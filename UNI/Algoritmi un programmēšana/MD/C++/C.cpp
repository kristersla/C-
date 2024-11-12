/********************************************************************************************
    Izveidot programmu valodā C++, obligāti izmantojot norādītās vai kādas citas funkcijas.
    Prasības tādas pašas kā iepriekšējā uzdevumā, precīzāk sk. Laboratorijas darbu noteikumos.

    C19. Dots masīvs no veseliem nenegatīviem skaitļiem A(n) Atrast tā elementa indeksu, kuram pirms
    tā esošo skaitļu summa vismazāk atšķiras no pēc tā esošo skaitļu summas.
    Ja elementi ar šādu īpašību ir vairāki, uzrādīt visus.
********************************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 4, 6, 2, 9};

    int total_sum = 0;

    for (int i = 0; i < 5; i++) {
        total_sum += arr[i];
    }

    int left_sum = 0;
    int min_diff = total_sum;
    int closest_index = -1;
    int current_diff;

    for (int i = 0; i < 5; i++) {
        int right_sum = total_sum - left_sum - arr[i];
        current_diff = left_sum - right_sum;

        if (current_diff < 0) {
            current_diff = -current_diff;
        }

        if (current_diff < min_diff) {
            min_diff = current_diff;
            closest_index = i;
        }

        left_sum += arr[i];
    }

    cout << "Index with closest sums: " << closest_index << endl;
    cout << "Minimum difference: " << min_diff << endl;

    return 0;
}


