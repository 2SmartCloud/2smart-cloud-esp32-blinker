#include "main.h"

#include "2smart.h"
#include "property/blink_led.h"

String product_id = "1640089360218659";  // production id
const char *device_name = "2Smart Blinker";
const char *device_version = "3";

Cloud2Smart smartcloud;

void setup() {
    Node *blinker = new Node("Blinker", "blinker", smartcloud.GetDevice());  // (name, id,device)

    Blink *led_state = new Blink("Blinker", LED_STATE_ID, blinker, SENSOR, true, true, "boolean");

    smartcloud.setup();
}
void loop() { smartcloud.loop(); }
