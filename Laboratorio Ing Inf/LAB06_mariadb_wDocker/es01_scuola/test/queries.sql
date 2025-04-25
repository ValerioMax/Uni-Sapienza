USE scuola;

-- 1. Trovare tutti gli studenti che hanno effettuato almeno una verifica.
-- La query seleziona in modo univoco tutti gli studenti che compaiono nella tabella "esiti_verifiche"
SELECT DISTINCT s.*
FROM studenti s
JOIN esiti_verifiche ev ON s.id = ev.id_studente;


-- 2. Trovare tutte le verifiche effettuate da un determinato studente.
-- Si uniscono "verifiche" ed "esiti_verifiche" in modo da recuperare le info della verifica e il voto ottenuto.
-- Sostituire "1" con l'id dello studente desiderato.
SELECT v.*, ev.voto
FROM verifiche v
JOIN esiti_verifiche ev ON v.id = ev.id_verifica
WHERE ev.id_studente = 1;


-- 3. Trovare quali insegnanti hanno assegnato almeno 2 verifiche agli studenti.
-- Per ogni insegnante si contano le verifiche distinte che hanno avuto almeno una partecipazione
-- (questo evita di contare più volte la stessa verifica sostenuta da diversi studenti).
SELECT i.*, COUNT(DISTINCT v.id) AS num_verifiche
FROM insegnanti i
JOIN verifiche v ON i.id = v.id_insegnante
JOIN esiti_verifiche ev ON v.id = ev.id_verifica
GROUP BY i.id
HAVING COUNT(DISTINCT v.id) >= 2;


-- 4. Cancellare lo studente con id=2.
-- Nota: se non sono configurati i comportamenti di "ON DELETE CASCADE" nelle chiavi esterne,
-- assicurati di rimuovere anche i record nelle tabelle di associazione.
-- In questo esempio, cancelliamo prima le associazioni ed infine lo studente.
DELETE FROM esiti_verifiche
WHERE id_studente = 2;

DELETE FROM studenti
WHERE id = 2;


-- 5. Modificare lo studente con id=3 per aumentare l’età da 15 a 16 anni.
UPDATE studenti
SET eta = 16
WHERE id = 3;
