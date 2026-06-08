Klase ovog interfejsa treba da se definisu u fajlu syscall_cpp.hpp Interfejsi imaju sledeci oblik:
[[C++ API KOD]]

Globalne operatorske funkcije *new* i *delete* treba implementirati tako da obmotavaju sistemske pozive *mem_alloc* i *mem_free*. Apstraktna klasa **PeriodicThread** sluzi sa podrsku periodicnim nitima. Korisnik treba da izvede klasu iz ove i redefinise polimorfnu operaciju *periodicActivation*. Klasa **Console** je usluzna, fasadna klasa koja samo obezbedjuje odgovarajuci prostor imena za operacije koje obmotavaju sistemske pozive za pristup konzoli. Ukoliko je konstruktorom postavljen pokazivac na funkciju, operaciju run treba ignoristati u svakom slucaju.

Postojanje destruktora u interfejsu oznacava da se dati objekti mogu unistavati i da je eventualno potrebno obezbediti odgovarajucu sinhronizaciju ili dealokaciju sistemskim pozicom.

Zadatak je u potpunosti implementirati klase i operacije kako bi korisnicki kod koji se daje u biblioteci app.lib bio kompatibilan.