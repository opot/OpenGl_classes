#include "GlUtils/Engine.h"
#include "MainGame.h"

using fjfj::MainGame;

int main(int argc, char** argv) {

    fjfj::Engine e(MainGame::init, MainGame::update, MainGame::render);
    e.start();

    return 0;
}