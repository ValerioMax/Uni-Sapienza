In questo progetto:

.
├── init
│   └── init.sql
└── test
│    └── queries.sql
└── README.md

Andare nella cartella . e creare container "scuola-mariadb" dall'immagine "mariadb"
    docker run --name scuola-mariadb \
        -v "$(pwd)/init":/docker-entrypoint-initdb.d \
        -e MYSQL_ROOT_PASSWORD=mia_pass123 \
        -d mariadb

-v "$(pwd)/init":/docker-entrypoint-initdb.d
monta come Bind Mount nel container semplicemente la cartella init/ con dentro init.sql

--> quando container si avvierà il DB in esso andrà a cercare in /docker-entrypoint-initdb.d
    il file .sql di inizializzazione del DB
    (in questo modo glielo facciamo trovare)
--> mariadb (quello dentro al container) creerà un DB seguendo le istruzioni in init.sql

Se avessimo voluto rendere persistenti i dati del DB nel container
avremmo dovuto fare Bind Mount anche del DB stesso:
    In /home/valerio/
        mkdir mariadb_data
        chmod 0777 mariadb_data
    
    Poi
        docker run --name scuola-mariadb \
            -v "$(pwd)/init":/docker-entrypoint-initdb.d \
            -v /home/valerio/mariadb_data/:/var/lib/mysql:Z \
            -e MYSQL_ROOT_PASSWORD=mia_pass123 \
            -d mariadb

Connettersi al DB nel container con
    docker exec -it scuola-mariadb mariadb -uroot -pmia_pass123 scuola

Usare il DB corretto
    USE scuola;

Copia-incollare le query in queries.sql sulla linea di comando per interrogare il DB

Uscire con CTRL+D
