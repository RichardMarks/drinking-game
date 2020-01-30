/*
drinking-game.c

(c) 2020, Richard Marks
MIT License
*/
#include <stdio.h>
#include <stdlib.h>
#if defined(__APPLE__) || defined(__unix__)
  #include <time.h>
  #ifndef delay_ms
    #define delay_ms(ms) nanosleep((struct timespec[]){{ (time_t)(ms / 1000), 0L }}, 0)
  #endif
#elif defined(_WIN32)
  #include <windows.h>
  #ifndef delay_ms
    #define delay_ms(ms) Sleep(ms)
  #endif
#endif
#ifndef delay_ms
  void no_sleep(int ms) {}
  #define delay_ms(ms) no_sleep(ms)
#endif

int main (int argc, char* argv[]) {
  int running = 1;
  int ln = 1;
  setbuf(stdout, NULL);
  printf(
    "Let's play a drinking game!\n\n"
    "Whenever you see a \"1\" you need to"
    " take a drink of your beverage of choice.\n\n"
    "Press Enter to start. Press CTRL+C to quit.\n");
  while (fgetc(stdin) != '\n') {}
  while (running) {
    char a = rand() % 100 < 40 ? '0' : '1';
    char b = rand() % 100 < 50 ? '0' : '1';
    char c = rand() % 100 < 60 ? '0' : '1';
    char d = rand() % 100 < 70 ? '0' : '1';
    printf("%c%c%c%c ", a, b, c, d);
    delay_ms(1000);
    if (++ln % 9 == 0) {
      printf("\n\n");
      ln = 1;
    }
  }
  return 0;
}
