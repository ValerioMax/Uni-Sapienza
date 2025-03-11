import player as p

MAX_NUM = 1000000000000
ITER = 1000

player1 = p.HumanPlayer("Valerio")
player2 = p.CpuPlayer("CPU")
player3 = p.FastCpuPlayer("FastCPU")

#player1.start_playing(MAX_NUM)
#player2.start_playing(MAX_NUM)
player3.start_playing(MAX_NUM)

for i in range(0, ITER):
    player3.start_playing(MAX_NUM)

with open("results.tsv", 'r') as file:
    l = file.read().split('\n')
    avg = 0

    for i in range(0, ITER):
        avg += int(l[i].split('\t')[2])

    print(f"Average attempts number: {avg / ITER}")

