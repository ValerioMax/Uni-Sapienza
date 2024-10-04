s = input('inserisci stringa che contenga almeno due caratteri: ')
n = int(input('inserisci numero intero positivo: '))
var = True
for i in range(0,len(s)):
    if i + n <= len(s) - 1 and s[i] == s[i + n] :
        print('True')
        var = False
if var:
    print('False')
