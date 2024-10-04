s = input('inserisci stringa s: ')
x = 1
while not ( s.count('a') > 0 and  s.count('c') > 0 ):
    s = input('inserisci stringa s: ')
    x += 1
print(x)
