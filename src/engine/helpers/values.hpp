#ifndef VALUES_HPP
#define VALUES_HPP

// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// ------------------------VALUES---------------------------- //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //

constexpr float        PLAYER_SPEED                    = 2;
constexpr unsigned int PLAYER_JUMP                     = 400;
constexpr unsigned int PLAYER_KILL                     = PLAYER_JUMP / 2;
constexpr float        SHIFTING_PLAYER_SPEED           = PLAYER_SPEED + 1;
constexpr unsigned int PLAYER_FIRE                     = 150;
constexpr unsigned int PLAYER_PICKED_MUSHROOM_ON_FLOOR = 120; 
constexpr unsigned int PLAYER_PICKED_FLOWER_ON_FLOOR   = 50; 


constexpr float        FIRE_SPEED      = SHIFTING_PLAYER_SPEED + 1;
constexpr unsigned int FIRE_HEIGHT     = 120;  // ms - this is being counted with a clock
constexpr unsigned int FIRE_KILL_TIMER = 3000; // ms

constexpr float        ENEMY_SPEED    = 0.6;
constexpr float        FALL_SPEED     = 4;
constexpr unsigned int POINTS_VALUE   = 10;

#endif