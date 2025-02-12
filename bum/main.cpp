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

/***********************
void attira(char* word);
Funkcija attira(char* word) -

atgriež kā rezultātu attīrītu vārdu no simboliem atstājot tikai burtus un ciparus.

***********************/
void attria(char* word) {
    int j = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalnum(word[i])) { //Tiek attīrīts vārds no simboliem un tiek atstāti tikai burti un cipri.
            word[j++] = word[i];
        }
    }
    word[j] = '\0';
}

/***********************
bool palindroms(const char* word);
Funkcija palindroms(const char* word) -

atgriež kā rezultātu true vai false vai padotais vārds ir palindroms.

***********************/
bool palindroms(const char* word) {

	int left = 0;
    int right = strlen(word) - 1;

	while (left < right) {
        if (word[left] != word[right]) { //Ja burti nesakrīt, tad tas nav palindroms.
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

    if (!in || !out) { //Parbauda vai eksistē ievades un izvaides 'txt' faili.
        cout << "Nav atrasts in9.txt vai out9.txt fails." << endl;
        return 1;
    }

    while (in >> word) { //Katrs vards kamer ir vards iekš faila.
        attria(word);
        if (strlen(word) > 0 && palindroms(word)) {
            out << word << endl; //Tiek ierakstīts iegūtais palindroms izejas failā.
        }
    }

    return 0;
}
