numeraleAlieno="349776123345679876543234567876543234569055"
numeroTerrestre=9510990939794952322311710154344301747012051743844839

x = 1
numero = ''
for i in range(1,100):
    for i in range(len(str(numeroTerrestre)) + 1):
        quoziente = numeroTerrestre // x
        resto = numeroTerrestre % x
        numero = str(numero) + str(resto)
        numeroTerrestre = quoziente
    numero = numero[len(numero) - 1::-1]
    if int(numero) == int(numeraleAlieno):
        print(x)
        break
    else:
        numero = ''
        numeroTerrestre=9510990939794952322311710154344301747012051743844839
        x += 1
