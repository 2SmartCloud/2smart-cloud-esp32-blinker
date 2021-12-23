#pragma once

#include <Arduino.h>

#include "homie.h"

#define LED_STATE_ID "state"

class Blink : public Property {
 public:
    Blink(const char* name, const char* id, Node* node, PROPERTY_TYPE type, bool settable, bool retained,
          const char* data_type);

    bool Init(Homie* homie);

    void HandleCurrentState();

    void HandleSettingNewValue();

 private:
};
