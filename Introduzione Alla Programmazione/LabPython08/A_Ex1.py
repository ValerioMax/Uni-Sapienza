def A_Ex1(l):
    j = 0
    h = 97
    xprec = 0

    z = 0
    var = True
    while var:
        if h <= 122:
            j = 0
            x = 0
            for i in l:
                if l[j].count(chr(h)) > 0:
                    x += 1
                j += 1
  
            if x >= xprec and h >= z:
                xprec = x
                z = h
     
            h += 1
        else:
            break
        
    return chr(z)
        






    

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex1, [["casa", "senape", "ketchup", "pasta"]] , "s")
    counter_test_positivi += tester_fun(A_Ex1, [["a", "b", "b", "a", "a", "a", "a"]] , "a")
    counter_test_positivi += tester_fun(A_Ex1, [["1fI", "1FI", "1FI", "1FI","1FI" ]] , "f")
    counter_test_positivi += tester_fun(A_Ex1, [["conte", "dpcm"]] , "c")
    counter_test_positivi += tester_fun(A_Ex1, [["Zlatan", "Ibraimovich", "Cristiano", "Ronaldo", "Francesco", "Totti"]] , "o")


    print('La funzione',A_Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
