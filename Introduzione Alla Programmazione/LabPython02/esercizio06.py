n = int(input('inserisci numeratore n: '))
d = int(input('inserisci denominatore d: '))

if n < d:
    print('propria')
if n % d == 0 and n > d:
    print('apparente')
if n > d and not n % d == 0:
    print('impropria')

