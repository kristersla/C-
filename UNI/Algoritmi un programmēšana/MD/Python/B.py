# Kristers Laganovskis, kl24033 
# B19. Atrast visus simetriskus skaitļus intervālā [n, m], kurus kāpinot kvadrātā iegūst simetrisku skaitli.
# Skaitļu dalīšana ciparos jāveic skaitliski. Risinājumā izmantot funkciju, kas noskaidro, vai skaitlis ir 
# simetrisks (Piemēram, skaitlim 2341 simetriskais skaitlis ir 1432).
# Programma izveidota: 30.09.2024.

# *******************************************
# simetrisks(skaitlis)
# Funkcija simetrisks(skaitlis) - 

# Funkcija pārbauda katru padoto skaitli, kas ir kvadrātā atsvevišķi vai, tas ir vienāds ar šo pašu skaitli, bet apgriestu otrādāk (Z-A). 
# Ja, šie skaitļi ir vinādi, tad tiek atgriesta vērtība - True, bet ja nē - False.
# *******************************************
def simetrisks(skaitlis):

    kapinats_skaitlis = skaitlis  # Saglabā sākotnējo skaitli
    atmuguriski = 0  # Sākam ar 0, lai veidotu apgriezto skaitli
    
    # while cikls, kas sadala skaitli pa cipariem un pēc tam veido apgriezto skaitli.
    while skaitlis > 0:
        pedejais_cipars = skaitlis % 10
        atmuguriski = atmuguriski * 10 + pedejais_cipars
        skaitlis = skaitlis // 10

    # Ja sākotnējais skaitlis ir vienāds ar apgriezto, tas ir simetrisks un tiek atgriezta vērtība True.
    if kapinats_skaitlis == atmuguriski:
        return True  
    else:
        return False
    
ievade = 1

# while cikls, kas ļauj šo programmu darbināt vairākas reizes, līdz lietotājs izvēlas beigt programmu.
while ievade == 1:

    # Lietotājam tiek lūgts ievadīt intervāla sākuma un beigu vērtības.
    n = int(input("Ievadi pirmo skaitli: "))
    m = int(input("Ievadi otro skaitli: "))
    
    # Mainīgais, lai sekotu līdzi vai kāds simetrisks skaitlis ir atrasts
    atrasts_simetrisks = False

    # Cikls, kas kāpina katru skaitli intervālā [n,m], pārbauda katru kāpināto skaitli, vai tas ir simetrisks.
    for skaitlis in range(n, m+1):
        
        kapinats_skaitlis = skaitlis**2

        # Funkcija, kas pārbauda simetriju.
        parbaude = simetrisks(kapinats_skaitlis)

        # Nosacījums, ja kāpinātais skaitlis ir simetrisks (funkcija atgriež True), tad izdrukā šo skaitli.
        if parbaude==True:
            print(f"Simetrisks skaitlis: {skaitlis}, kvadrāts: {kapinats_skaitlis}")
            atrasts_simetrisks = True  # Norāda, ka vismaz viens simetrisks skaitlis ir atrasts

    # Ja nav atrasts neviens simetrisks skaitlis, izdrukā atbilstošu ziņu
    if not atrasts_simetrisks:
        print(f"Nav atrasts neviens simetrisks skaitlis intervālā [{n};{m}]")
        
    # Jautā lietotājam, vai vēlas turpināt programmu.
    ievade = int(input("Ievadi (1), ja vēlies turpināt, ievadi (0), ja vēlies beigt programmu: "))
