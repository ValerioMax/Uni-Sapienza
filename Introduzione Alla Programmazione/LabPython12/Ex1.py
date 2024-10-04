def Ex1(s):
    l = s.split()
    print(l)
    for par in l:
        par.lower()
        y = 0
        print(list(par))
        for car in list(par):
            x = 1
            
            paro = par[par.index(car):len(par)]
            for j in range(len(paro) - 1):
                
                if ord(paro[j]) <= ord(paro[j + 1]):
                    x += 1
                else:
                    break
            if x > y:
                y = x
    return y

    for par in l:
        par.lower()
        y = 0
        carpre = par[0]
        for car in list(par):
            if carpre <= car:
                x += 1
            
            carpre = car
            

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['cavallo'],4)
    counter_test_positivi += tester_fun(Ex1, ['arciere ponte'],2)
    counter_test_positivi += tester_fun(Ex1, ['casa vacanze arco'],3)
    counter_test_positivi += tester_fun(Ex1, ['parte di una casa'],3)
    counter_test_positivi += tester_fun(Ex1, ['ponte bassuz, tunnel lungo'],5)
    
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
