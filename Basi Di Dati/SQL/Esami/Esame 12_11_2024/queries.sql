--q1
select distinct a.id, a.categoria
from arbitro a join direzione d on a.id = d.direttore
		join partita p on d.partita = p.codice
where p.sqcasa = 'Roma' and p.risultato = '1'

--q2
select distinct a.id, count(*)
from arbitro a join direzione d on a.id = d.var
		join partita p on d.partita = p.codice
where p.risultato = '2'
group by a.id

union

select distinct a.id, 0
from arbitro a
where a.id not in (select a.id
				   from arbitro a join direzione d on a.id = d.var
				   			join partita p on d.partita = p.codice
				   where p.risultato = 2)

--q3
-- Tutti gli arbitri che sono nell'insieme di quelli che hanno gestito var in una partita finita pari
--	e che non sono nell'insieme di quelli che hanno diretto partite finite pari

select distinct a1.id
from arbitro a1
where a1.id in (select a.id
			    from arbitro a join direzione d on a.id = d.var
					join partita p on d.partita = p.codice
			    where p.risultato = 'X')
				
		and a1.id not in (select a.id
					   	  from arbitro a join direzione d on a.id = d.direttore
							join partita p on d.partita = p.codice
					      where p.risultato = 'X')

--q4
-- Tutti gli arbitri per cui per ogni partita diretta da loro con almeno un check
--	è finita con vittora squadra in casa
-- ovvero
-- Tutti gli arbitri che non sono nell'insieme di quelli per cui hanno diretto almeno una partita con almeno un check
--	dove non vince la squadra in casa

select distinct a1.id
from arbitro a1
where a1.id not in (select d.direttore
					from direzione d join partita p on d.partita = p.codice
					where quanticheck >= 1 and risultato <> '1')

--q5
