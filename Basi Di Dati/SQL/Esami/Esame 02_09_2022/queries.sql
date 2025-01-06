--q1
select distinct r.codice, r.giorno, r.valore
from centralina c join rilevazione r on c.codice = r.codice join citta t on c.citta = t.id
where r.valore < 1100 and c.tipo = 200 and t.nome != 'Milano'

--q2
select distinct t.nome
from citta t, centralina c1, centralina c2
where t.id = c1.citta and t.id = c2.citta and c1.codice > c2.codice -- a > b usa ordine lessicografico per evitare ridondanze ((<a,a>) oppure (<a,b> e <b,a> contemporaneamente))
		and c1.tipo = c2.tipo

--oppure

-- tutte le citta per cui l'insieme delle centraline con tipo uguale in quella citta ha cardinalita >= 2
--	insieme delle centraline di tipo uguale in una città fissata è l'insieme delle centraline
--	per cui esiste almeno 1 altra centralina diversa e con tipo uguale a quella fissata (con card. >= 1)
select distinct t.nome
from citta t
where 2 <= (select distinct count(*)
			from centralina c
			where c.citta = t.id and 1 <= (select distinct count(*)
											from centralina 
											where citta = t.id and tipo = c.tipo and codice != c.codice))

--q3
with vista as
(select distinct c.codice, count(*) somma
from centralina c join rilevazione r on c.codice = r.codice
group by c.codice)

select distinct c.codice, t.regione, vista.somma
from vista join centralina c on vista.codice = c.codice
		join citta t on c.citta = t.id

union

select distinct c.codice, t.regione, 0
from centralina c join citta t on c.citta = t.id
where c.codice not in (select codice from rilevazione)

--oppure

-- (credo) se bisogna mettere un attributo nella select allora semplicemente aggiungerlo a quelli della group by
select c.codice, ci.regione, count(*)
from rilevazione r join centralina c on r.codice = c.codice
		join citta ci on ci.id = c.citta
group by c.codice, ci.regione

union

select c1.codice, ci1.regione, 0
from centralina c1 join citta ci1 on c1.citta = ci1.id
where c1.codice not in (select r1.codice from rilevazione r1)


--q4
-- tutte le centraline per cui centralina non è nell insieme delle centraline
-- 	che hanno prodotto rilev in gennaio

select distinct codice
from centralina
where codice not in (select c.codice
					 from centralina c join rilevazione r on c.codice = r.codice
					 where r.giorno >= 0 and r.giorno <= 31)
					 
-- se avesse chiesto almeno 2 rilevazioni in gennaio:
select distinct codice
from centralina
where codice not in (select c.codice
					 from centralina c join rilevazione r on c.codice = r.codice
					 where r.giorno >= 0 and r.giorno <= 31
					 group by c.codice
					 having count(*) >= 2)

--q5
