temp = int(input('inserire valore temperatura: '))
scala = input('inserire scala (F o C): ')

if scala =='C':
    if temp <= 0:
        print('solida')
    if 0 < temp < 100:
        print('liquida')
    if temp >= 100:
        print('gassosa')
if scala == 'F':
    if temp <= 32:
        print('solida')
    if 32 < temp < 212:
        print('liquida')
    if temp >= 212:
        print('gassosa')
