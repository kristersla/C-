/**************************

Klase Simbolu_steks attēlo simbolu (char) stekā ar maksimālo izmēru 5 elementi.
Klase nodrošina steķa datu struktūras pamata operācijas:
  - konstruktors: inicializē tukšu steku,
  - destruktors: paziņo par objekta likvidēšanu un izdrukā likvidēto elementu skaitu,
  - push(): pievieno jaunu elementu stekā, ja tas nav pilns,
  - pop(): izņem augšējo elementu no steka un atgriež tā vērtību,
  - count(): atgriež pašreizējo elementu skaitu stekā,
  - top(): atgriež augšējā elementa vērtību, neizņemot to no steka,
  - isEmpty(): pārbauda, vai steks ir tukšs,
  - isFull(): pārbauda, vai steks ir pilns.

Steka elementi tiek glabāti fiksēta izmēra masīvā (5 elementi).
******************************************************************/

class Simbolu_steks{

    private:
        char steks[5];
        int elementu_sk;

    public:

        Simbolu_steks();
        ~Simbolu_steks();

        void Push(char simbols);
        char Pop();
        int Count();
        char Top();
        bool IsEmpty();
        bool IsFull();

};
