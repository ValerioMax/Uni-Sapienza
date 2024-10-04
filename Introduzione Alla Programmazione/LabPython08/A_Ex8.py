def A_Ex8(l):
    insieme = set()
    var = True
    j = 0
    for i in l:
        x = list(l[j])

        h = 0
        for i in range(len(x)):
            num = x[h]

            z = 0
            for i in range(len(l) + 1):
                if z < len(l):
                    if x != (list(l[z])) and (list(l[z])).count(num) > 0:
                        var = False
                else:
                    break
                z += 1
            if var:
                numero = num
                insieme.add(numero)
                
            var = True
            h += 1

        j += 1
    return insieme


   

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, [[{3,2,90},{2,87,23},{2,23,3}]] , {90,87})
    counter_test_positivi += tester_fun(A_Ex8, [[set(),{-10},{2}]] , {-10,2})
    counter_test_positivi += tester_fun(A_Ex8, [[set()]] , set())
    counter_test_positivi += tester_fun(A_Ex8, [[set(),{10,-2},{10},{-2}]] , set())
    counter_test_positivi += tester_fun(A_Ex8, [[set(),{10,-9,4},{4,-5,2},{3,7,4}]] , {10,-9,-5,2,3,7})


    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
