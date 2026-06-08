#Kod 
0x25

#Potpis 
```c
int sem_wait_n (sem_t id, unsigned n);
```

#Objasnjenje 
Operacija wait na semaforu sa datom ručkom, koja zahteva n jedinica resursa. Ukoliko je trenutna vrednost semafora veća ili jednaka n, vrednost se umanjuje za n i funkcija se odmah uspešno završava. U suprotnom, pozivajuća nit se blokira dok ne postane moguće izvršiti operaciju (ili dok semafor ne bude dealociran). U slučaju uspeha vraća 0, a u slučaju neuspeha, uključujući i slučaj kada je semafor dealociran dok je nit čekala, vraća negativnu vrednost (kôd greške).