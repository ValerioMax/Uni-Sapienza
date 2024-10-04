def Ex1(s):
    smax = ''
    l = list(s)
    for i in l.copy():
        if i == ' ' or i == ',':
            l.remove(i)
    for i in range(len(l)):
        l[i] = l[i].lower()
    
    cmax = 1
    c = 1
    for i in range(len(l)):
        if i < len(l) - 1:
            if l[i] <= l[i + 1]:
                c += 1
                if c >= cmax:
                    cmax = c
            else:
                c = 1
    return cmax  


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
