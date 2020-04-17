struct semaphore
{
   int value;
   Queue type L;
}
Wait (semaphore s)
{
   s.value = s.value - 1;
   if (s.value < 0)
   {
      put process (PCB) in L;
      sleep();
   }
   else
      return;
}
Signal (semaphore s)
{
   s.value = s.value + 1;
   if (s.value <=0 )
   {
       select a process (PCB) from L;
       wake up();
   }
}