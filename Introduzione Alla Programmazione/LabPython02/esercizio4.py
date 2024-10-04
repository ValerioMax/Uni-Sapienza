s = input('inserisci stringa s: ')
var1 = len(s)
n = len(s)

if var1 != 0:
    if s[0] == s[n-1]:
        print('caratteri iniziale e finale uguali')
    else:
        print('caratteri iniziale e finale diversi')
    