def A_Ex6(fileName):
    f = open(fileName, 'r', encoding = 'UTF-8')
    righe = f.read().strip().split('\n')
    d = {}
    insieme = set()
    if righe != ['']:
        for riga in righe:
            a = riga.strip().split(',')
            for i in range(len(a)): 
                insieme.add(int(a[i]))
        lista = list(insieme)
        
        for numero in lista:
            d[numero] = set()
            for j in range(len(righe)):
                
                b = righe[j].strip().split(',')
                
                if str(numero) in b:
                    d[numero].add(j + 1)
    return d
    
    





    
                    
            
        











    
 
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex6, ['numeri1.txt'] , {10: {1,2}, -5: {1,2}, 0: {1}, 8: {2}, -3: {2}})
    counter_test_positivi += tester_fun(A_Ex6, ['numeri2.txt'] , {10: {1,2}, 0: {2}})
    counter_test_positivi += tester_fun(A_Ex6, ['numeri3.txt'] , {3: {1,2}, 4: {1}, 5: {1}, 2: {2,3}, 0: {2,3}})
    counter_test_positivi += tester_fun(A_Ex6, ['numeri4.txt'] , {2: {1,2,3,4,5}, 1: {1,2,6}, 3: {6}})
    counter_test_positivi += tester_fun(A_Ex6, ['numeri5.txt'] , {})

    print('La funzione',A_Ex6.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
