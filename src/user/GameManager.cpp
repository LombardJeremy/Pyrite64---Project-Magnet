#include "script/userScript.h"
#include "scene/sceneManager.h"
#include "timer.h"
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
    GameState state;
    Player players[MAX_PLAYERS];
    int player_count;
    joypad_inputs_t input;
} GameManager;

static void gm_init(GameManager *gm) {
    memset(gm, 0, sizeof(GameManager));
    gm->state = GS_MENU;
    gm->player_count = 0;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        gm->players[i].port = i;
        gm->players[i].connected = false;
        gm->players[i].isActive = false;
    }

    //TODO - Init Wave Manager
}

static void gm_set_state(GameManager *gm, GameState new_state) {
    gm->state = new_state;
    if (new_state == GS_PLAYING) {
        //TODO - WaveManagerTimer
        //P64::User::Timer::resetTimer(&gm->wave_manager.timer);
    }
}


namespace P64::Script::C10EC9787AF49529 {
    P64_DATA(
        // Put your arguments here if needed, those will show up in the editor.
        //
        // Types that can be set in the editor:
        // - uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t
        // - float
        // - AssetRef<sprite_t>
        // - ObjectRef
        //TODO - Hud, PlayerObject, WaveManager, BossManager

        //[[P64_NAME("gedagedi")]]
        GameManager gm;
    );

    // The following functions are called by the engine at different points in the object's lifecycle.
    // If you don't need a specific function you can remove it.


    void initDelete(Object &obj, Data *data, bool isDelete) {
        if (isDelete) {
            // do cleanup
            return;
        }
        // do initialization
        gm_init(&data->gm);
    }

    void update(Object &obj, Data *data, float deltaTime) {
    }

    void draw(Object &obj, Data *data, float deltaTime) {
    }

    void onEvent(Object &obj, Data *data, const ObjectEvent &event) {
    }

    void onCollision(Object &obj, Data *data, const Coll::CollEvent &event) {
    }
}
