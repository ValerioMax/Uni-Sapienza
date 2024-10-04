def A_Ex7(l):
    j = 0
    for i in l:
        if j < len(l) - 1:
            if l[j] < l[j + 1]:
                l.append(l[j + 1] - l[j])
        j += 1
    return l









    

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""    
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex7, [[10,1,11,31,251]] , [10,1,11,31,251,10,20,220,10,200,190])
    counter_test_positivi += tester_fun(A_Ex7, [[]] , [])
    counter_test_positivi += tester_fun(A_Ex7, [[2,7,3]] , [2,7,3,5,2])
    counter_test_positivi += tester_fun(A_Ex7, [[200,501,300]] , [200,501,300,301,1])
    counter_test_positivi += tester_fun(A_Ex7, [[3,2,0]] , [3,2,0])


    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
