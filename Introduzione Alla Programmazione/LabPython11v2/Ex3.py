def Ex3(file):
    import re
    f = open(file, 'r', encoding = 'UTF-8')
    testo = f.read()
    pattern = r'(\w)\1\w*.? +\w*\1\1\w*.? +\w*\1\1'
    c = 0
    print(testo)
    for parola in re.finditer(pattern,testo,re.IGNORECASE):
        c = c + 1
        print(parola.group())
    return c





    
    
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex3, ["file2_1.txt"] , 1)
    counter_test_positivi += tester_fun(Ex3, ["file2_2.txt"] , 2)
    counter_test_positivi += tester_fun(Ex3, ["file2_3.txt"] , 3)
    counter_test_positivi += tester_fun(Ex3, ["file2_4.txt"] , 4)
    counter_test_positivi += tester_fun(Ex3, ["file2_5.txt"] , 5)

    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
