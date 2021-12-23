#include "blink_led.h"

#include "file_system/src/file_system.h"

#define LED 2

Blink::Blink(const char* name, const char* id, Node* node, PROPERTY_TYPE type, bool settable, bool retained,
             const char* data_type)
    : Property(name, id, node, type, settable, retained, data_type) {
    pinMode(LED, OUTPUT);
}

bool Blink::Init(Homie* homie) {  // initialize toggles for notification
    bool status = true;
    if (!Property::Init(homie)) status = false;

    SetValue(value_ == "true" ? "true" : "false");

    return status;
}

void Blink::HandleCurrentState() {
    // nothing
}

void Blink::HandleSettingNewValue() {
    digitalWrite(LED, value_ == "true");

    if (HasNewValue()) {
        Device* device = node_->GetDevice();
        bool is_sys_notif_enabled = device->IsSysNotifyEnabled();
        if (is_sys_notif_enabled) device->SendNotification(value_ == "true" ? "Led on" : "Led off");
        SetHasNewValue(false);
    }
}
