#include "script/userScript.h"
#include "scene/sceneManager.h"

#define MAX_PLAYERS 4

typedef enum {
  GS_MENU,
  GS_PLAYING,
  GS_PAUSED,
  GS_GAME_OVER,
} GameState;

typedef struct {
  int port;
  bool connected;
  bool isActive;
} Player;

typedef struct {
  GameState  state;
  Player players[MAX_PLAYERS];
  int player_count;
} GameManager;



namespace P64::Script::C10EC9787AF49529
{
  P64_DATA(
    // Put your arguments here if needed, those will show up in the editor.
    //
    // Types that can be set in the editor:
    // - uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t
    // - float
    // - AssetRef<sprite_t>
    // - ObjectRef


  );

  // The following functions are called by the engine at different points in the object's lifecycle.
  // If you don't need a specific function you can remove it.

  void initDelete(Object& obj, Data *data, bool isDelete)
  {
    if(isDelete) {
      // do cleanup
      return;
    }
    // do initialization
  }

  void update(Object& obj, Data *data, float deltaTime)
  {
    gm->state = GS_MENU;
  }

  void draw(Object& obj, Data *data, float deltaTime)
  {
  }

  void onEvent(Object& obj, Data *data, const ObjectEvent &event)
  {
  }

  void onCollision(Object& obj, Data *data, const Coll::CollEvent& event)
  {
  }
}
