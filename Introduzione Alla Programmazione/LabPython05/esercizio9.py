l = int(input('inserisci lunghezza lato (num disapri >= 3): '))
print('*' * l)
for i in range(1,l - 1):
    print('*' + ' ' * (l - 2) + '*')
print('*' * l)
