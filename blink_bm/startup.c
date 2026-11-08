extern int main(void);

void Reset_Handler(void) {
  main();
  while (1);
}

__attribute__((section(".vectors")))
void (*const vectors[])(void) = {
  (void (*)(void)) 0x20005000,
  Reset_Handler
};