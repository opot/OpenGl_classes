#include <Engine.h>

#include "MainGame.h"

int main() {
  fjfj::Engine e(MainGame::init, MainGame::update, MainGame::render);
  e.start();
}
