ABI (application binary interface) je binarni interfejs sistemskih poziva koji se vrse pomocu softverskog prekida. Ovaj sloj obezbedjuje prenos argumenata sistemskog poziva preko registara procesora, prelazak u privilegovani rezim rada procesora i prelazak na kod jezgra:

Parametri se u sistemski poziv prenose kroz registre procesora na sledeci nacin:
- a0: kod sistemskog poziva, jednak broju iz prve kolone za C API
- a1, a2, ...: parametri sistemskog poziva, redom po potpisu iz C API sleva na desno.
- a0: povratna vrednost

Svi potpisi navedenih sistemskih poziva se u potpunosti preslikavaju na odgovarajuce ABI pozive i imaju istu semantiku, osim sledecih izuzetaka:
- Sistemski poziv broj 0x01, mem_alloc, parametar *size* izrazava velicinu u blokovima. Funkcija mem_alloc iz C API treba da zadatu vrednost zaokruzi na cele blokove
- Sistemski poziv broj 0x11, thread_create, ima ABI potpis ekvivalentan sledecem C potpisu:
```c
	  int thread_create (thread_t* handle), void (* start_routine) (void * )), void * arg,  void * stack_space);
```
- Kreira nit nad funkcijom start_routine, pozivajuci je sa argumentom arg, smestajuci stek te niti u vec odvojen prostor na ciju poslednju lokaciju ukazuje stack_space. U slucaju uspeha u handle se upisuje 0, u slucaju neuspeha kod greske.
- Sistemski poziv u ABI sloju kreira nit sa zadatom pozicijom steka, thread_create iz C API treba najpre da alocira stek (sistemskim pozivom mem_alloc) pre nego sto izvrsi ovaj sistemski poziv ABI
