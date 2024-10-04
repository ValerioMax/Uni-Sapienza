s = input('inserisci una stringa comosta da almeno un carattere: ')
i = 0
var = True
while var:
    if i < len(s) and ord(s[i]) <= 100:
        i += 1
    elif i < len(s):
            print('Il primo carattere Unicode maggiore di 100 è ' + s[i])
            var = False
    else:
        print("stringa consumata e crattere non trovato")
        var = False
    
        
    
