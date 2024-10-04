n = int(input('inserisci numero intero n: '))
if n > 1: 
    a = 2
    while n % a != 0:
        a += 1
    if a == n:
        print('numero primo')
    else:
        print('numero non primo')
else:
    print('numero non primo')
 
