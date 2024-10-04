a = int(input('inserisci numero intero a: '))
b = int(input('inserisci numero intero b: '))
c = int(input('inserisci numero intero c: '))

if a > 0 and b > 0 and c > 0 and a < b+c and b < a+c and c < a+b:
    if a == b == c :
        print('equilatero')
    elif a == b or a == c or c == b:
        print('isoscele')
    else :
        print('scaleno')
else :
    print('input non valido')
