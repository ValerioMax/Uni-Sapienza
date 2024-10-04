x = int(input('inserisci numero intero x: '))
y = int(input('inserisci numero intero y: '))
z = 1
if y == 0 or x == 0:
    print('0')
    
elif ( y > 0 and x > 0 ) or ( y < 0 and x < 0 ):
    k = abs(x)
    while z < abs(y):
        x = abs(x) + k
        z += 1
    print(x)
    
elif y > 0 and x < 0:
    k = abs(x)
    while z < y:
        x = abs(x) + k
        z += 1
    print(-x)
    
elif y < 0 and x > 0:
    k = x
    while z < abs(y):
        x = x + k
        z += 1
    print(-x)

    
