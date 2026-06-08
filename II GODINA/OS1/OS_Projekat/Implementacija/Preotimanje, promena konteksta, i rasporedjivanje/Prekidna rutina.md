## Osnovna ideja  
  
Procesor ima jedinstvenu rutinu za:  
- sistemski poziv  
- spoljasnji prekid  
- izuzetak  
  
Na rutinu pokazuje registar `stvec`.  
  
Odgovarajuci registri sadrze informaciju o uzroku skoka u rutinu.  
  
Zbog toga:  
- dovoljno je  
- i potrebno  
  
napraviti jednu prekidnu rutinu.  
  
Ta rutina predstavlja:  
- jedino mesto prelaska iz korisnickog koda u jezgro i nazad  
- jedino mesto prelaska iz korisnickog u sistemski rezim rada i nazad