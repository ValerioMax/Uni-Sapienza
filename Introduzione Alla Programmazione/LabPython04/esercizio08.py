s = input('inserisci stringa: ')
var = True
while var:
    x = s[len(s) - 1]
    z = s
    s = input('inserisci stringa: ')
    if x == s[0]:
        var = False
print(z,s)
