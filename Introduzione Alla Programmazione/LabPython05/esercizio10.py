l = int(input('inserisci lunghezza lato (num >= 2): '))
print('*' * l)
a = ''
b = l - 4
if l % 2 != 0:
    for i in range(1,(l // 2)):
        print('*' + a + '*' + (' ' * b) + '*' + a + '*')
        a = a + ' '
        b = b - 2
    b = b + 2
    print('*' + a + '*' + a + '*')
    a = a[0:len(a) - 1]
    for j in range(1,(l // 2)):
        print('*' + a + '*' + (' ' * b) + '*' + a + '*')
        a = a[0:len(a) - 1]
        b = b + 2    
    print('*' * l)
else:
    for i in range(1,(l // 2)):
        print('*' + a + '*' + (' ' * b) + '*' + a + '*')
        a = a + ' '
        b = b - 2
    b = b + 2
    a = a[0:len(a) - 1]
    for j in range(1,(l // 2)):
        print('*' + a + '*' + (' ' * b) + '*' + a + '*')
        a = a[0:len(a) - 1]
        b = b + 2    
    print('*' * l)

