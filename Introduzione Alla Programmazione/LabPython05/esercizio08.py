b = int(input('inserisci la lunghezza della base (numero dispari >= 3): '))

for i in range(1,b + 1):
    b = b - 1
    x = (' ' * b + '*' * i)
    y = ('*' * (i - 1))
    x =  x + y
    print(x)
    
