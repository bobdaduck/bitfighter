//-----------------------------------------------------------------------------------
//
// bitFighter - A multiplayer vector graphics space game
// Based on Zap demo released for Torque Network Library by GarageGames.com
//
// Derivative work copyright (C) 2008 Chris Eykamp
// Original work copyright (C) 2004 GarageGames.com, Inc.
// Other code copyright as noted
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful (and fun!),
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//------------------------------------------------------------------------------------

#ifndef _INPUT_H_
#define _INPUT_H_

#include "../tnl/tnl.h"

#include "keyCode.h"
#include <string>

using namespace TNL;
using namespace std;

namespace Zap
{

const S32 gJoystickNameLength = 260;   // Needs to be 260 in windows, 255 in OSX (or does it?) --> we'll use the bigger of the two here

enum ControllerTypeType
{
   LogitechWingman,
   LogitechDualAction,
   SaitekDualAnalogP880,      // 6 buttons on top, 2 in front
   SaitekDualAnalogRumblePad, // 4 buttons on top, 4 in front
   PS2DualShock,
   PS2DualShockConversionCable,
   XBoxController,
   XBoxControllerOnXBox,
   ControllerTypeCount,
   GenericController,         // Something confirmed as a controller, but of unknown type --> treat as controller
   UnknownController,         // Something not confirmed as controller, or of unknown type --> treat as no controller
   NoController               // Pretty sure there is no controller
};

enum InputMode {
   Keyboard = 0,
   Joystick = 1
};

enum ButtonInfo {
   MaxJoystickAxes = 12,
   MaxJoystickButtons = 14,
   ControllerButton1 = 1 << 0,
   ControllerButton2 = 1 << 1,
   ControllerButton3 = 1 << 2,
   ControllerButton4 = 1 << 3,
   ControllerButton5 = 1 << 4,
   ControllerButton6 = 1 << 5,
   ControllerButton7 = 1 << 6,
   ControllerButton8 = 1 << 7,

   ControllerButtonStart = 1 << 8,
   ControllerButtonBack = 1 << 9,

   ControllerButtonDPadUp = 1 << 10,
   ControllerButtonDPadDown = 1 << 11,
   ControllerButtonDPadLeft = 1 << 12,
   ControllerButtonDPadRight = 1 << 13,
};

// the following functions are defined differently on each platform
// in the the platInput.cpp files.

void getModifierState( bool &shiftDown, bool &controlDown, bool &altDown );

void InitJoystick();
const char *GetJoystickName();
ControllerTypeType autodetectJoystickType();
void ShutdownJoystick();
bool ReadJoystick(F32 axes[MaxJoystickAxes], U32 &buttonMask, U32 &hatMask);
void renderControllerButton(F32 x, F32 y, KeyCode keyCode, bool activated, S32 offset = 0);

extern ControllerTypeType stringToJoystickType(string strJoystick);
extern string joystickTypeToString(S32 controllerType);
extern string joystickTypeToPrettyString(S32 controllerType);

};

#endif

