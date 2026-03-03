#include "script/userScript.h"
#include <libdragon.h>

namespace P64::Script::C6D442CC0709BF30
{
  P64_DATA(
    // Put your arguments here if needed, those will show up in the editor.
    //
    // Types that can be set in the editor:
    // - uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t
    // - float
    // - AssetRef<sprite_t>
    // - ObjectRef

    [[P64::Name("Speed")]] float speed = 10.0f;
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
    Comp::CollBody* collBody = obj.getComponent<Comp::CollBody>();
    Coll::BCS* bcs = &collBody->bcs;

    const joypad_inputs_t inputs = joypad_get_inputs(JOYPAD_PORT_1);
    fm_vec2_t moveInput{static_cast<float>(inputs.cstick_x), static_cast<float>(inputs.cstick_y)};

    bcs->velocity = {moveInput.x * data->speed, bcs->velocity.y, moveInput.y * data->speed};
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
