n = int(input("Ievadi dabiskais skaitlis n: "))

if n < 0:
    print(n," nav naturāls skaitlis")
else:
    is_prime = True

    for i in range(2, int(n**0.5) + 1):  # Check only up to the square root of n
        if n % i == 0:
            print(f"{n} nav pirmskaitlis")
            is_prime = False
            break
    if is_prime:
        print(f"{n} ir pirmskaitlis")
