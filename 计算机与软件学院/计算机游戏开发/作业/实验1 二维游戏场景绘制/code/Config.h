
#ifndef __CONFIG_H__
#define __CONFIG_H__

using namespace std;

static const int PLAYER_TAG = 110;  // player tag
static const int MAP_TAG = 111;     // map tag
static int PLAYER_WIDTH = 100;		// player img width
static int PLAYER_HEIGHT = 100;	    // player img height
static int PLAYER_JUMP_SPEED = 30;  // player jump speed

static string MAP_TMX_FILE_PATH = "Chapter05/MoveAndControl.tmx";
static string MAP_BG_LAYER_NAME = "back";  // map background layer name

static int MAP_FLOUR_NUM = 6;
static int MAP_FLOUR[] = {7,8,151,170,171,172};

static string GAME_OVER_TIPS = "Game Over!";  // game failed tips words
static string GAME_SUCCESS = "Success!";      // game success tips words

//	fnt file path
static string TIPS_FNT_PATH = "fonts/futura-48.fnt";

// player img path
static string PLAYER_IMG_PATH[4] = {
	"Chapter05/player/player1.png",
	"Chapter05/player/player2.png",
	"Chapter05/player/player3.png",
	"Chapter05/player/player4.png"
} ;

enum Dir
{
	STOP,
	UP,
	DOWN
};

#endif