n = int(input('inserisci un numero intero n > 0: '))
x = 1
while x <= n:
    if n % x == 0:
        print(x)
        x += 1
    else:
        x += 1
        
