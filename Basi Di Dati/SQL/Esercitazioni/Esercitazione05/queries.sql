--q1
select distinct s.codicea
from scritto s join libro b on s.titolo = b.titolo
where copieVendute > 10

--q2
select distinct titolo
from libro
where copieVendute >= 1 
		and titolo not in (select titolo from scritto)

--q3
select distinct codice, cognome
from autore
where codice not in (select codicea
					 from scritto
					 where titolo in (select titolo
					 				  from libro
									  where copieVendute > 10))

--oppure

select a.codice, a.cognome
from autore a
where a.codice not in (select codicea
						from scritto s join libro b on s.titolo = b.titolo
						where b.copieVendute > 10)

--q4
select distinct codice, sum(l.copieVendute)
from autore join scritto s on codice = s.codicea
		join libro l on s.titolo = l.titolo
where eta > 30
group by codice
having count(*) >= 2

--q5
select distinct codice, avg(l.copieVendute)
from autore join scritto s on codice = s.codicea
		join libro l on s.titolo = l.titolo
group by codice

union

select distinct codice, 0
from autore
where codice not in (select codicea from scritto)

order by codice

--q6
select distinct l.titolo, count(s.codicea)
from autore join scritto s on codice = s.codicea
		join libro l on s.titolo = l.titolo
where l.copieVendute > 15 and eta > 40
group by l.titolo

union

select distinct titolo, 0
from libro
where copieVendute > 15
		and titolo not in (select titolo 
						   from autore join scritto on codice = codicea
						   where eta > 40)

--q7
select distinct s.titolo
from scritto s join autore a on a.codice = s.codicea
where 1 = (select count(*)
		   from scritto s2
		   where s2.titolo = s.titolo
		   group by s2.titolo)

--oppure

-- NONN esiste autore che ha scritto stesso libro e che NON è lo stesso autore
select distinct s.titolo
from scritto s
where not exists (select s1.codicea	
				  from scritto s1
				  where s1.titolo = s.titolo
				  		and s1.codicea != s.codicea)

--q8
with v as
	(select a1.codice, sum(l1.copieVendute) as somma
	 from autore a1 join scritto s1 on a1.codice = s1.codicea
		join libro l1 on s1.titolo = l1.titolo
	 group by a1.codice
	)

select distinct a.codice, a.cognome
from autore a join v on a.codice = v.codice
where v.somma = (select max(somma) from v)

--q9

-- Tutti i libri dove libro NON è nell'insieme dei libri scritti da almeno un autore NON famoso
select distinct titolo
from scritto
where titolo not in (select titolo
					 from scritto
					 where codicea not in (select s.codicea
										   from scritto s join libro l on s.titolo = l.titolo
										   where l.copieVendute > 10
										   group by s.codicea
										   having count(*) >= 2))

--oppure

-- Uguale ma autore famoso trovato diversamente
select distinct titolo
from scritto
where titolo not in (select titolo
					 from scritto
					 where codicea not in (select s.codicea
										   from scritto s
										   where 2 <= all (select count(*)
														   from scritto s1 join libro l on s1.titolo = l.titolo
														   where s.codicea = s1.codicea and l.copieVendute > 10)))
			   
--oppure

-- Tutti i libri dove NON ESISTE autore t.c. autore ha scritto libro e autore NON è famoso
select distinct s.titolo
from scritto s
where not exists (select s1.codicea 
				  from scritto s1
				  where s.titolo = s1.titolo 
						and s1.codicea not in (select s.codicea
											   from scritto s join libro l on s.titolo = l.titolo
											   where l.copieVendute > 10
											   group by s.codicea
											   having count(*) >= 2))

-- query aux
select s.codicea, s.titolo, l.copieVendute
from scritto s join libro l on s.titolo = l.titolo
order by s.codicea

--q10
-- insieme autori solitari
select distinct s.codicea
from autore a join scritto s on a.codice = s.codicea
		join libro l on s.titolo = l.titolo
group by s.codicea
having count(s.titolo) = 1

-- insieme autori famosi
select s.codicea
from scritto s join libro l on s.titolo = l.titolo
where l.copieVendute > 10
group by s.codicea
having count(*) >= 2

-- insieme autori famosi e non solitari
select distinct codice, cognome
from autore join scritto s on codice = s.codicea
where codice in (select s.codicea
				   from scritto s join libro l on s.titolo = l.titolo
				   where l.copieVendute > 10
				   group by s.codicea
				   having count(*) >= 2)
		and codice not in (select s.codicea
							from autore a join scritto s on a.codice = s.codicea
									join libro l on s.titolo = l.titolo
							group by s.codicea
							having count(s.titolo) = 1)

--oppure

select s.codicea
from scritto s join libro l on s.titolo = l.titolo
where l.copieVendute > 10
group by s.codicea
having count(*) >= 2

except

	(select codice
	 from autore
	
	 except
	
	 select s1.codicea
	 from scritto s1
	 where (select count(*) 
	 		from scritto s2 
			where s2.codicea = s1.codicea) > 1)
