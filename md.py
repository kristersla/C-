# *******************************************
# Kristers Laganovskis, kl24033
# A10. Doti divi naturāli skaitļi m un n. Noteikt skaitļa m pirmo n ciparu summu. Skaitļa dalīšana ciparos jāveic skaitliski.
# Programma izveidota: 14.09.2024.
# *******************************************

while True:  # Sāk bezgalīgu ciklu, kas turpināsies līdz tas tiek pārtraukts ar komandu.

    # Tiek ievadīti 2 skaitļi 'm' un 'n', tie tiek pārvērsts par integer tipa vērtībām, kuras tiks izmantotas turpmākajā programmā.
    m = int(input("Ievadi naturālu skaitli m: "))
    n = int(input("Ievadi otru naturālu skaitli n: "))

    if m <= 0 or n <= 0: # Pārbaudām, vai kāds no ievadītajiem skaitļiem ir mazāks vai vienāds ar 0, rezultējoši izvada paziņojumu vai arī programma tālāk apstrādā datus. 
        print("Nevar būt negatīvs skaitlis vai 0!\nIevadi atkārtoti!")
    else:

        skaitlis_list = []  # Tukšs saraksts, kurā tiks saglāti skaitļa 'm' cipari.
        cikla_m = m  # 'm' tiek piešķirta jauna vērtība, lai varētu to izmantot 'while' ciklā. Tādejādi izveidojot 'skaitlis_list' sarakstu.

        # Šajā ciklā mēs pārveidojam skaitli 'm' par atsevišķu ciparu sarakstu.
        while cikla_m > 0:
            skaitlis_list.append(cikla_m % 10)  # Iegūstam pēdējo ciparu no 'cikla_m' vērtības un tad to pievieno sarakstam.
            cikla_m = cikla_m // 10  # Tiek noņemts pēdējais cipars no 'cikla_m'.

        skaitlis_list = skaitlis_list[::-1]  # Tiek apgriests ciparu sarakstu, lai tas būtu pareizā secībā, jo skaitļi tika iegūti no beigām uz sākumu.
        skaitlu_virknes_garums = len(skaitlis_list)  # Tiek iegūts saraksta garums, kas kalpos tālāk 'if' funkcijā, lai notiektu vai ievadītias 'n' skaitlis būs derīgs.

        # Pārbaudām, vai 'n' nav lielāks par 'm' ciparu virknes garumu jeb ''.
        if n > skaitlu_virknes_garums:
            print(f"Skaitlis 'n' ({n}) nevar būt lielāks par 'm' ciparu virknes garumu!\nIevadi atkārtoti!")
        else:
            # Ja 'n' ir derīgs, aprēķinām pirmo 'n' ciparu summu.
            gala_sum = sum(skaitlis_list[:n])  # Summējam pirmos 'n' ciparus no ciparu saraksta.
            print(f"\nSkaitļa {m} pirmo {n} ciparu summa ir: {gala_sum}\n")

        again = input("Vai turpināt (1) vai beigt (0)?\n")  # Ievadam '1' (turpināt) vai '0' (beigt).
        if again != "1":  # Ja ievadītā atbilde nav '1', cikls tiek pārtraukts ar 'break' komandu.
            break 



