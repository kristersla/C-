/**********************************
F10. Dots teksta fails f. Uzrakstīt programmu, kura atrod failā f visus vārdus, kas ir simetriski.
Izvadīt šos vārdus failā f1. Par vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem vai pieturas zīmēm
(punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme.)
Simetrisks ir vārds, kas no abām pusēm lasāms vienādi (aka, 1221). Drīkst uzskatīt, ka vārda garums nepārsniedz 40.
**********************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

// Funkcija, kas pārbauda, vai vārds ir palindroms

bool isPalindrome(const char* word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i]) return false;
    }
    return true;
}

// Funkcija, kas izfiltrē pieturas zīmes no vārda

void cleanWord(char* word) {
    int j = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalnum(word[i])) {  // Patur tikai burtus un ciparus
            word[j++] = word[i];
        }
    }
    word[j] = '\0'; // Beigas simbols
}

int main() {
    ifstream in("in9.txt");
    ofstream out("out9.txt");
    char word[50];

    if (!in || !out) {
        cout << "Error opening input or output file!" << endl;
        return 1;
    }

    while (in >> word) {
        cleanWord(word);  // Noņem pieturas zīmes
        if (strlen(word) > 0 && isPalindrome(word)) {
            out << word << endl;
        }
    }

    cout << "Done!" << endl;
    return 0;
}
