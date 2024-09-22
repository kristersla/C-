n = int(input("Ievadi pirmo skaitli: "))
m = int(input("Ievadi otro skaitli: "))

def simetrisks(skaitlis):

    kapinats_skaitlis = skaitlis
    atmuguriski = 0
    
    while skaitlis > 0:
        pedejais_cipars = skaitlis % 10
        atmuguriski = atmuguriski * 10 + pedejais_cipars
        skaitlis = skaitlis // 10

    if kapinats_skaitlis == atmuguriski: print(kapinats_skaitlis,"ir simetrisks skaitlis kapinot ar 2")
    

for skaitlis in range(n,m+1):
    kapinats_skaitlis = skaitlis**2
    parbaude = simetrisks(kapinats_skaitlis)

