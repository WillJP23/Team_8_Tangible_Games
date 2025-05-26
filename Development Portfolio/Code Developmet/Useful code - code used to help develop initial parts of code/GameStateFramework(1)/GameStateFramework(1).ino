

#define STATE_START    1
#define STATE_GAME1    2
#define STATE_GAME2    3
#define STATE_SUCCESS  4
#define STATE_FAILURE  5


#define GAME_RUNNING 0
#define GAME_SUCCESS 1
#define GAME_FAILURE 2

void setup() {

}

int state = STATE_START;
int gameResult = GAME_RUNNING;

void loop() {

  update();

  switch (state) {
    case STATE_START:
      welcome();
      state = STATE_GAME1;
      break;

    case STATE_GAME1:
      gameResult = playGame1();
      if (gameResult == GAME_SUCCESS) {
        state = STATE_GAME2;
      } else if (gameResult == GAME_FAILURE) {
        state = STATE_FAILURE;
      }
      break;

    case STATE_GAME2:
      gameResult = playGame2();
      if (gameResult == GAME_SUCCESS) {
        state = STATE_SUCCESS;
      } else if (gameResult == GAME_FAILURE) {
        state = STATE_FAILURE;
      }
      break;

    case STATE_FAILURE:
      failed();
      state = STATE_START;
      break;

    case STATE_SUCCESS:
      succeeded();
      state = STATE_START
      break;
  }


}
