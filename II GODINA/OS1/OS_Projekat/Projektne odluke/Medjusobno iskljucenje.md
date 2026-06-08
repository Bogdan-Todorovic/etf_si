Ako jezgro ne omogucava preotimanje jezgra ceo kod jezgra se posmatra kao jedinstvena kriticna sekcija, tokom cijeg izvrsavanja nije moguca promena konteksta. Ovo se moze jednostavno obezbediti maskiranjem prekida pirlikom ulaska u kod jezgra na svim mestima.

Ako se odlucimo za jezgro koje omogucava preotimanje tokom izvrsavanja svog koda potrebno je posvetit paznju sledecim problemima:
- treba identifikovati deljene sturkture podatak kojima se moze pristupati iz konteksta razlicitih niti i operacije koje nad njima rade, svakoj strukturi treba pridruziti odgovarajucu sinhronizacionu primitivu ili promenjljivu a operaciju posmatrati kao kriticnu sekciju 
- medjusobno iskljucenje sasvim bazicnih kriticnih sekcija jezgra, onih koje se koriste za implementaciju promene konteksta i semafora, treba obezbediti maskiranjem prekida
- Medjusobno iskljucivanje ostalih kriticnih sekcija moze se obezbediti semaforima, ako se one izvrsavaju u kontekstu korisnickih niti
- potrebno je paziti na sprecavanje mrtve blokade, recimo postovanjem uvek istog redosleda zakljucavanja kriticnih sekcija.
- ukoliko postoji ugnezdjivanje kriticnih sekcija koje se iskljucuju maskiranjem prekida, potrebno je paziti da se prekid demaskira tek pri izlasku iz krajnje spoljasnje ugnezdjene sekcije, ovo se moze resiti brojanjem nivoa dubine ugnezdjivanja
- 