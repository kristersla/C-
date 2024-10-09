# Kristers Laganovskis, kl24033 
# B19. Atrast visus simetriskus skaitļus intervālā [n, m], kurus kāpinot kvadrātā iegūst simetrisku skaitli.
# Skaitļu dalīšana ciparos jāveic skaitliski. Risinājumā izmantot funkciju, kas noskaidro, vai skaitlis ir 
# simetrisks (Piemēram, skaitlim 2341 simetriskais skaitlis ir 1432).
# Programma izveidota: 30.09.2024.


# Funkcija, kas pārbauda, vai skaitlis ir simetrisks. Funkcija apgriež padoto skaitli un pārbauda, vai tā ir vienāds ar padoto skaitli.
def simetrisks(skaitlis):

    kapinats_skaitlis = skaitlis
    atmuguriski = 0
    
    # while cikls, kas sadala skaitli pa cipariem un pēc tam to veido apgriezto skaitli.
    while skaitlis > 0:
        
        pedejais_cipars = skaitlis % 10
        atmuguriski = atmuguriski * 10 + pedejais_cipars
        skaitlis = skaitlis // 10

    # Ja sākotnējais skaitlis ir vienāds ar apgriezto, tas ir simetrisks un tiek izvadīts lietotājam, ka tas ir simetrisks.
    if kapinats_skaitlis == atmuguriski:
        print(f"Simetrisks skaitlis: {kapinats_skaitlis}")
    
ievade = 1

# while cikls, kas ļauj šo programmu darbināt vairākas reizes, līdz lietotājs izvēlas beigt programmu.
while ievade == 1:

    # Lietotājam tiek lūgts ievadīt intervāla sākuma un beigu vērtības.
    n = int(input("Ievadi pirmo skaitli: "))
    m = int(input("Ievadi otro skaitli: "))

    # Cikls, kas kāpina katru skaitli intervālā [n,m], pārbauda katru kāpināto skaitli vai, tas ir simetrisks.
    for skaitlis in range(n, m+1):
        
        kapinats_skaitlis = skaitlis**2
        # Funkcijas, kas pārbauda simetriju.
        parbaude = simetrisks(kapinats_skaitlis)
        
    # Tiek jautāts lietotājam vai vēlas turpināt programmu.
    ievade = int(input("Ievadi (1), ja velies turpināt, ievadi (0), ja vēlies beigt programmu: "))
