#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"

struct Point
{
  int x;
  int y;
};

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

enum class STATE{
  PLAYING,
  WIN,
  LOSE
};

struct Player
{
  explicit Player(Point pos = {.x = 10, .y = 10}) :
                 coords(pos), old_coords(coords) {};

  bool Moved() const;
  STATE ProcessInput(MovementDir dir, Image &screen);
  void Draw(Image &screen);
  void change_key() { key = !key; }

private:
  Point coords {.x = 10, .y = 10};
  Point old_coords {.x = 10, .y = 10};
  Pixel color {.r = 255, .g = 255, .b = 100, .a = 255};
  bool key = false;
  int move_speed = 1;
  bool changed_room = false;
};

#endif //MAIN_PLAYER_H
