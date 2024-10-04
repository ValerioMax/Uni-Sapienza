def A_Ex8(s1,s2):
    if len(s1) <= len(s2):
        i = 0
        for i in range(len(s2)):
            
            j = 0
            stringan = ''
            stringa = ''
            for i in range(len(s1)):
                
                if s1[j] == s2[i]:
                    stringa = stringa + s1[j]
                else:
                    stringa = ''
                    
                if len(stringan) < len(stringa):
                    stringan = stringa
                
                j += 1
            i += 1
    else:
        i = 0
        for i in range(len(s1)):
            
            j = 0
            stringan = ''
            stringa = ''
            for i in range(len(s2)):
                
                if s2[j] == s1[i]:
                    stringa = stringa + s2[j]
                else:
                    stringa = ''
                    
                if len(stringan) < len(stringa):
                    stringan = stringa
                

                j += 1
            i += 1
    return stringan
            
    
  


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, ['amaca','amaranto'], 'ama')
    counter_test_positivi += tester_fun(A_Ex8, ['asso','assolato'], 'asso')
    counter_test_positivi += tester_fun(A_Ex8, ['','stringa'], '')
    counter_test_positivi += tester_fun(A_Ex8, ['stringa',''], '')
    counter_test_positivi += tester_fun(A_Ex8, ['ciao mamma','ciao '], 'ciao ')

    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
