#Kod 
0x11

#Potpis 
```cpp
class _thread; 
typedef _thread* thread_t; 
int thread_create (
	thread_t* handle,                      void(*start_routine)(void*),
	void* arg
);
```

#Objasnjenje 
Pokreće nit nad funkcijom start_routine, pozivajući je sa argumentom arg. U slučaju uspeha, u handle upisuje „ručku“ novokreirane niti i vraća 0, a u slučaju neuspeha vraća negativnu vrednost (kôd greške). „Ručka“ je interni identifikator koji jezgro koristi da bi identifikovalo nit (pokazivač na neku internu strukturu/objekat jezgra čije je ime sakriveno iza sinonima thread).