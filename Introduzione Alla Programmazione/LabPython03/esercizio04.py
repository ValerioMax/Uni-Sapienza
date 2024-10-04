x = int(input('inserisci numero intero x compreso in [0,10]: '))
y = int(input('inserisci numero intero y compreso in [0,10]: '))
z = 0
while z <= 10:
    if z == x or z == y:
        z +=1
    else:
        print(z)
        z += 1
