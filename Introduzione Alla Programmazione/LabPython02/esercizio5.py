var1 = int(input('inserire il numero dell\'anno: '))

if var1 % 4 == 0 and not var1 % 100 == 0:
    print('anno bisestile')
elif var1 % 400 == 0:
    print('anno bisestile')
else:
    print('anno non bisestile')
