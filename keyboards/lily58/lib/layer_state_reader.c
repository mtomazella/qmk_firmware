#include "action_layer.h"
#include <stdio.h>

#define L_BASE 0
#define L_LOWER (1 << 1)
#define L_RAISE (1 << 2)
#define L_ADJUST (1 << 3)
#define L_MOUSE (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Base");
            break;
        case L_RAISE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbol");
            break;
        case L_LOWER:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Number");
            break;
        case L_ADJUST:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Movement");
            break;
        case L_MOUSE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mouse");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undefined");
    }

    return layer_state_str;
}
