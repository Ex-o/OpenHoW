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
#pragma once

#include <iostream>

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>
#include <wx/combo.h>
#include <wx/glcanvas.h>
#include <wx/aui/aui.h>

#include <pork/pork.h>

/////////////////////////////////////////////

#define APP_VERSION_MAJOR   0
#define APP_VERSION_MINOR   0

enum {
    ID_FRAME_MAIN,
        ID_MAIN_CONSOLE,

        ID_MAIN_TRANSFORM,
        ID_MAIN_ROTATE,
        ID_MAIN_SCALE,

        ID_MAIN_TOOL_MODEL,
        ID_MAIN_TOOL_TEXTURE,
        ID_MAIN_TOOL_PARTICLE,

    ID_FRAME_PARTICLE,
};