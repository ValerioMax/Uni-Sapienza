def A_Ex9(l):
    j = 0
    lista = []
    for i in l:
        s = str(l[j])
        h = 0
        y = 0
        for i in range(len(s)):
            x = s.count(s[h])
            if x > y:
                y = x
                posizione = h
            elif x == y and ord(s[h]) <= ord(s[posizione]):
                y = x
                posizione = h
            
            h += 1
        
        lista.append(s[posizione])
        
        j += 1
        
    return lista





    

###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex9, [['amaca','amaranto','rosso']], ['a','a','o'])
    counter_test_positivi += tester_fun(A_Ex9, [['osso','assolato','alto']], ['o','a','a'])
    counter_test_positivi += tester_fun(A_Ex9, [['stringa','a','bbbbcccc','dado']], ['a','a','b','d'])
    counter_test_positivi += tester_fun(A_Ex9, [['fosso','dosso','rosso','fosso']], ['o', 'o', 'o', 'o'])
    counter_test_positivi += tester_fun(A_Ex9, [['ciao mamma','ciao ']], ['a', ' '])

    print('La funzione',A_Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
