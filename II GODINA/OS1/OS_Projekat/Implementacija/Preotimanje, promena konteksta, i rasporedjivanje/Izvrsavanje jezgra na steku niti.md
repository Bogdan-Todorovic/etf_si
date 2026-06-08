Ako se jezgro izvrsava na steku pojedinacne niti:  
  
- sav kod jezgra izvrsava se u kontekstu neke niti  
- sve do trenutka promene konteksta  
  
Promena konteksta se radi:  
- tek kada procesor treba dati drugoj niti  
  
Na primer:  
- u operacijama semafora  
- ili iz drugih razloga  
  
Tada se koristi:  
- `yield`