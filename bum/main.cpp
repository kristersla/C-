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


void cleanWord(char* word) {
    int j = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalnum(word[i])) {
            word[j++] = word[i];
        }
    }
    word[j] = '\0';
}

bool palindroms(const char* word) {

	int left = 0;
    int right = strlen(word) - 1;

	while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
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
        cleanWord(word);
        if (strlen(word) > 0 && palindroms(word)) {
            out << word << endl;
        }
    }

    return 0;
}
