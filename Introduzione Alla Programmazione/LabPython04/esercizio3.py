s = input('inserisci numero intero: ')
x = 0

while s != '*':
    if int(s) < 0:
        x = x + int(s)
    s = input('inserisci un numero intero: ')
    
print(x)
