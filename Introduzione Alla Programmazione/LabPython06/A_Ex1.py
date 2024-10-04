n1 = int(input('inserisci numero intero maggiore di zero: '))
n2 = int(input('inserisci numero intero maggiore di zero: '))
x = 1
while x <= n1:
    z = n1 / x
    if n1 % x == 0 and not n2 % z == 0:
        print(int(z))
    x += 1
    
