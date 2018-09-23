#pragma once

#include <string>
#include <map>

enum class EKeyboardDefinitions
{
SPACE			=	32,
APOSTROPHE		=	39, /* ' */
COMMA			=	44, /* , */
MINUS			=	45, /* - */
PERIOD			=	46, /* . */
SLASH			=	47, /* / */
NUM_0			=	48,
NUM_1			=	49,
NUM_2			=	50,
NUM_3			=	51,
NUM_4			=	52,
NUM_5			=	53,
NUM_6			=	54,
NUM_7			=	55,
NUM_8			=	56,
NUM_9			=	57,
SEMICOLON		=	59, /* ; */
EQUAL			=	61, /* = */
A				=	65,
B				=	66,
C				=	67,
D				=	68,
E				=	69,
F				=	70,
G				=	71,
H				=	72,
I				=	73,
J				=	74,
K				=	75,
L				=	76,
M				=	77,
N				=	78,
O				=	79,
P				=	80,
Q				=	81,
R				=	82,
S				=	83,
T				=	84,
U				=	85,
V				=	86,
W				=	87,
X				=	88,
Y				=	89,
Z				=	90,
LEFT_BRACKET	=	91, /* [ */
BACKSLASH		=	92, /* \ */
RIGHT_BRACKET	=	93, /* ] */
GRAVE_ACCENT	=	96, /* ` */
WORLD_1			=	161, /* non-US #1 */
WORLD_2			=	162, /* non-US #2 */
ESCAPE			=	256,
ENTER			=	257,
TAB				=	258,
BACKSPACE		=	259,
INSERT			=	260,
DELETE			=	261,
RIGHT			=	262,
LEFT			=	263,
DOWN			=	264,
UP				=	265,
PAGE_UP			=	266,
PAGE_DOWN		=	267,
HOME			=	268,
END				=	269,
CAPS_LOCK		=	280,
SCROLL_LOCK		=	281,
NUM_LOCK		=	282,
PRINT_SCREEN	=	283,
PAUSE			=	284,
F1				=	290,
F2				=	291,
F3				=	292,
F4				=	293,
F5				=	294,
F6				=	295,
F7				=	296,
F8				=	297,
F9				=	298,
F10				=	299,
F11				=	300,
F12				=	301,
F13				=	302,
F14				=	303,
F15				=	304,
F16				=	305,
F17				=	306,
F18				=	307,
F19				=	308,
F20				=	309,
F21				=	310,
F22				=	311,
F23				=	312,
F24				=	313,
F25				=	314,
KP_0			=	320,
KP_1			=	321,
KP_2			=	322,
KP_3			=	323,
KP_4			=	324,
KP_5			=	325,
KP_6			=	326,
KP_7			=	327,
KP_8			=	328,
KP_9			=	329,
KP_DECIMAL		=	330,
KP_DIVIDE		=	331,
KP_MULTIPLY		=	332,
KP_SUBTRACT		=	333,
KP_ADD			=	334,
KP_ENTER		=	335,
KP_EQUAL		=	336,
LEFT_SHIFT		=	340,
LEFT_CONTROL	=	341,
LEFT_ALT		=	342,
LEFT_SUPER		=	343,
RIGHT_SHIFT		=	344,
RIGHT_CONTROL	=	345,
RIGHT_ALT		=	346,
RIGHT_SUPER		=	347,
MENU			=	348,
LAST			=	MENU

};

struct SKeyboardMapping
{
	static std::map<const std::string, int> Mapping;

	SKeyboardMapping()
	{
		Mapping["SPACE"] = 32;
		Mapping["APOSTROPHE"] = 39; /* ' */
		Mapping["COMMA"] = 44; /* ; */
		Mapping["MINUS"] = 45; /* - */
		Mapping["PERIOD"] = 46; /* . */
		Mapping["SLASH"] = 47; /* / */
		Mapping["NUM_0"] = 48;
		Mapping["NUM_1"] = 49;
		Mapping["NUM_2"] = 50;
		Mapping["NUM_3"] = 51;
		Mapping["NUM_4"] = 52;
		Mapping["NUM_5"] = 53;
		Mapping["NUM_6"] = 54;
		Mapping["NUM_7"] = 55;
		Mapping["NUM_8"] = 56;
		Mapping["NUM_9"] = 57;
		Mapping["SEMICOLON"] = 59; /* ; */
		Mapping["EQUAL"] = 61; /* = */
		Mapping["A"] = 65;
		Mapping["B"] = 66;
		Mapping["C"] = 67;
		Mapping["D"] = 68;
		Mapping["E"] = 69;
		Mapping["F"] = 70;
		Mapping["G"] = 71;
		Mapping["H"] = 72;
		Mapping["I"] = 73;
		Mapping["J"] = 74;
		Mapping["K"] = 75;
		Mapping["L"] = 76;
		Mapping["M"] = 77;
		Mapping["N"] = 78;
		Mapping["O"] = 79;
		Mapping["P"] = 80;
		Mapping["Q"] = 81;
		Mapping["R"] = 82;
		Mapping["S"] = 83;
		Mapping["T"] = 84;
		Mapping["U"] = 85;
		Mapping["V"] = 86;
		Mapping["W"] = 87;
		Mapping["X"] = 88;
		Mapping["Y"] = 89;
		Mapping["Z"] = 90;
		Mapping["LEFT_BRACKET"] = 91; /* [ */
		Mapping["BACKSLASH"] = 92; /* \ */
		Mapping["RIGHT_BRACKET"] = 93; /* ] */
		Mapping["GRAVE_ACCENT"] = 96; /* ` */

		Mapping["WORLD_1"] = 161;
		Mapping["WORLD_2"] = 162;
		Mapping["ESCAPE"] = 256;
		Mapping["ENTER"] = 257;
		Mapping["TAB"] = 258;
		Mapping["BACKSPACE"] = 259;
		Mapping["INSERT"] = 260;
		Mapping["DELETE"] = 261;
		Mapping["RIGHT"] = 262;
		Mapping["LEFT"] = 263;
		Mapping["DOWN"] = 264;
		Mapping["UP"] = 265;
		Mapping["PAGE_UP"] = 266;
		Mapping["PAGE_DOWN"] = 267;
		Mapping["HOME"] = 268;
		Mapping["END"] = 269;
		Mapping["CAPS_LOCK"] = 280;
		Mapping["SCROLL_LOCK"] = 281;
		Mapping["NUM_LOCK"] = 282;
		Mapping["PRINT_SCREEN"] = 283;
		Mapping["PAUSE"] = 284;
		Mapping["F1"] = 290;
		Mapping["F2"] = 291;
		Mapping["F3"] = 292;
		Mapping["F4"] = 293;
		Mapping["F5"] = 294;
		Mapping["F6"] = 295;
		Mapping["F7"] = 296;
		Mapping["F8"] = 297;
		Mapping["F9"] = 298;
		Mapping["F10"] = 299;
		Mapping["F11"] = 300;
		Mapping["F12"] = 301;
		Mapping["F13"] = 302;
		Mapping["F14"] = 303;
		Mapping["F15"] = 304;
		Mapping["F16"] = 305;
		Mapping["F17"] = 306;
		Mapping["F18"] = 307;
		Mapping["F19"] = 308;
		Mapping["F20"] = 309;
		Mapping["F21"] = 310;
		Mapping["F22"] = 311;
		Mapping["F23"] = 312;
		Mapping["F24"] = 313;
		Mapping["F25"] = 314;
		Mapping["KP_0"] = 320;
		Mapping["KP_1"] = 321;
		Mapping["KP_2"] = 322;
		Mapping["KP_3"] = 323;
		Mapping["KP_4"] = 324;
		Mapping["KP_5"] = 325;
		Mapping["KP_6"] = 326;
		Mapping["KP_7"] = 327;
		Mapping["KP_8"] = 328;
		Mapping["KP_9"] = 329;
		Mapping["KP_DECIMAL"] = 330;
		Mapping["KP_DIVIDE"] = 331;
		Mapping["KP_MULTIPLY"] = 332;
		Mapping["KP_SUBTRACT"] = 333;
		Mapping["KP_ADD"] = 334;
		Mapping["KP_ENTER"] = 335;
		Mapping["KP_EQUAL"] = 336;
		Mapping["LEFT_SHIFT"] = 340;
		Mapping["LEFT_CONTROL"] = 341;
		Mapping["LEFT_ALT"] = 342;
		Mapping["LEFT_SUPER"] = 343;
		Mapping["RIGHT_SHIFT"] = 344;
		Mapping["RIGHT_CONTROL"] = 345;
		Mapping["RIGHT_ALT"] = 346;
		Mapping["RIGHT_SUPER"] = 347;
		Mapping["MENU"] = 348;
	}


};

__declspec(selectany) std::map<const std::string, int> SKeyboardMapping::Mapping;

int GetKeyByName(const std::string name)
{
	return SKeyboardMapping::Mapping[name];
}