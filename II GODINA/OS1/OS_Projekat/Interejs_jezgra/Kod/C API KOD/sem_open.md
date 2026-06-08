#Kod 
0x21

#Potpis 
```cpp
class _sem;
typedef _sem* sem_t;

int sem_open(
	sem_t* handle,
	unsigned init
);
```

#Objasnjenje 
Kreira semafor sa inicijalnom vrednošću init. U slučaju uspeha, u handle upisuje ručku novokreiranog semafora i vraća 0, a u slučaju neuspeha vraća negativnu vrednost (kôd greške). „Ručka“ je interni identifikator koji jezgro koristi da bi identifikovalo semafore (pokazivač na neku internu strukturu/objekat jezgra čije je ime sakriveno iza sinonima _sem).