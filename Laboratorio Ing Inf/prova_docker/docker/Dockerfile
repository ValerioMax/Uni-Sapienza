# selezione immagine da cui partire per costruire il docker (questa contiene versione minimale di python 3.9)
FROM python:3.9-slim

# imposta dir di lavoro (dir dove vevngono eseguite le istruzioni successive del Dockerfile (RUN, CPY, ...))
WORKDIR /app

# esegue pip e installa librerie (--no-cache-dir non fa sprecare spazio nel container con la cache)
# si poteva anche fare:
#   COPY requirements.txt .
#   RUN pip install --no-cache-dir -r requiements.txt
RUN pip install --no-cache-dir fastapi uvicorn

# copia file a sx (nostro sistema) nella destinazione a dx (docker container)
# (. è settata a /app dal comando WORKDIR)
COPY main.py .

# rende visibile all'esterno del docker la SUA porta 8000 in modo che che possiamo interagirci
EXPOSE 8000

# specifica del comando che verrà eseguito quando viene avviato un container sulla base della
# docker image creata a partire da questo dockerfile
# In questo caso: quando viene runnato
#   $docker run <nome_immagine>
# verrà eseguito: 
#   $uvicorn main:app --host 0.0.0.0 --port 8000
CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000"]

# NOTA:
# l'immagine all'inizio (in FROM ...) è l'immagine di base/genitore da cui viene costruita la nuova immagine
# Questa base è un punto di partenza come un "sistema operativo minimale" su cui andremo
# ad aggiungere librerie (RUN pip install ...) e file (COPY main.py .)
# (Si parte dall'immagine di base e si aggiungono strati uno sopra lìaltro: WORKDIR, RUN, COPY, EXPOSE, CMD)