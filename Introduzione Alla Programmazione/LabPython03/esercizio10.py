n = int(input('inserisci numero intero positivo n > 1: '))
if n > 1:
    x = 2
    a = 2
    while x <= n:
        while x % a != 0:
            a += 1
        if x == a:
            print(x)
            x += 1
            a = 2
        else:
            x += 1
            a = 2
    
