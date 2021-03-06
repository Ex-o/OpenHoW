/* OpenHoW
 * Copyright (C) 2017-2018 Mark Sowden <markelswo@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <PL/platform_graphics_camera.h>

#include "pork_engine.h"
#include "pork_input.h"
#include "pork_audio.h"

#include "script/script.h"

#include "client.h"
#include "client_display.h"
#include "client_actor.h"
#include "client_frontend.h"

/*****************************************************/

enum {
    CAMERA_MODE_DEFAULT,
    CAMERA_MODE_FREE,

    MAX_CAMERA_MODES
};

void ProcessClientInput(void) {
    static double input_delay = 0;
    if(input_delay < g_state.sim_ticks) {
        input_delay = g_state.sim_ticks + 50;

        if (GetKeyState('`')) {
            ToggleConsole();
            return;
        }
    }

    ProcessFrontendInput();

    /* todo: move this server-side or make safe... somehow :( */
    switch(cv_camera_mode->i_value) {
        default:break;

        case CAMERA_MODE_DEFAULT: {
            /* follow currently selected pig */
        } break;

        case CAMERA_MODE_FREE: {
            if(GetActionState(0, ACTION_MOVE_FORWARD)) {
                g_state.camera->position.x += 4.f;
            } else if(GetActionState(0, ACTION_MOVE_BACKWARD)) {
                g_state.camera->position.x -= 4.f;
            }

            if(GetButtonState(0, PORK_BUTTON_L1)) {
                g_state.camera->position.y += 4.f;
            } else if(GetButtonState(0, PORK_BUTTON_R1)) {
                g_state.camera->position.y -= 4.f;
            }

            if(GetButtonState(0, PORK_BUTTON_L2)) {
                g_state.camera->position.z += 4.f;
            } else if(GetButtonState(0, PORK_BUTTON_R2)) {
                g_state.camera->position.z -= 4.f;
            }

            if(GetActionState(0, ACTION_TURN_LEFT)) {
                g_state.camera->angles.z += 4.f;
            } else if(GetActionState(0, ACTION_TURN_RIGHT)) {
                g_state.camera->angles.z -= 4.f;
            }
        } break;
    }
}

/*****************************************************/

void InitClient(void) {
    if(g_state.is_dedicated) {
        return;
    }

    InitInput();
    InitDisplay();
    InitAudio();
    InitFrontend();

    ClearClientActors();
}

void SimulateClient(void) {
    if(g_state.is_dedicated) {
        return;
    }

    ProcessClientInput();

    SimulateFrontend();
}

void ShutdownClient(void) {
    if(g_state.is_dedicated) {
        return;
    }

    ClearClientActors();

    plParseConsoleString("audio_shutdown");
    ShutdownDisplay();
    /* todo: input, etc */
}
