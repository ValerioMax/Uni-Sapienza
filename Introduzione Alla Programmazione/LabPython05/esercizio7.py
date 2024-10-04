s = input('inserisci stringa: ')
var = True
for i in range(0,len(s)):
    if var:
        if s.count(s[i]) > 1:
            print('True')
            var = False
if var:
    print('False')
