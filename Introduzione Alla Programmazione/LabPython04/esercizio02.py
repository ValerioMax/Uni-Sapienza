s = input('inserisci una numeoro intero: ')
x = 0
while s != '*':
    if int(s) > 0:
        x += 1
    s = input('inserisci una numeoro intero: ')
print(x)
