s = int(input('inserisci un numero intero: '))
x = 0
if s % 3 == 0:
        x = s
        
while s != 0:
    s = int(input('inserisci un numero intero: '))
    
    if s % 3 == 0:
        x = x + s
print(x)
