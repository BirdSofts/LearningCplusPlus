// ********************************************************************************
/// <summary>
/// the searched and confronted ways for manipulation of Windows's console screen by the code itself in runtime.
/// </summary>
/// <returns></returns>
/// <created>ʆϒʅ,02.10.2018</created>
/// <changed>ʆϒʅ,10.01.2019</changed>
// ********************************************************************************

#pragma once

#ifdef CONSOLEADJUSTMENTS_EXPORTS
#define CONSOLEADJUSTMENTS_API __declspec (dllexport)
#else
#define CONSOLEADJUSTMENTS_API __declspec (dllimport)
#endif // CONSOLEADJUSTMENTS_EXPORTS


#ifndef CONSOLEADJUSTMENTS_H
#define CONSOLEADJUSTMENTS_H


#define F_BLACK                 0x00
#define F_BLUE                  0x01
#define F_GREEN                 0x02
#define F_CYAN                  0x03
#define F_RED                   0x04
#define F_PURPLE                0x05
#define F_YELLOW                0x06
#define F_WHITE                 0x07
#define F_bBLACK                0x08
#define F_bBLUE                 0X09
#define F_bGREEN                0x0A
#define F_bCYAN                 0x0B
#define F_bRED                  0x0C
#define F_bPURPLE               0x0D
#define F_bYELLOW               0x0E
#define F_bWHITE                0x0F

#define B_BLACK                 0x00
#define B_BLUE                  0x10
#define B_GREEN                 0x20
#define B_CYAN                  0x30
#define B_RED                   0x40
#define B_PURPLE                0x50
#define B_YELLOW                0x60
#define B_WHITE                 0x70
#define B_bBLACK                0x80
#define B_bBLUE                 0X90
#define B_bGREEN                0xA0
#define B_bCYAN                 0xB0
#define B_bRED                  0xC0
#define B_bPURPLE               0xD0
#define B_bYELLOW               0xE0
#define B_bWHITE                0xF0
    // octal (first 15 hexadecimal numbers are for colours)
    // numbers after the 15 are for backgrounds
    // more numbers also possible which
    //  reminds of old systems without proper graphic driver
    //  0: Black // 1: Blue  //  2 : Green  //  3 : Cyan  //  4 : Red  //  5 : Purple  //  6 : Yellow  //  7 : White  //  8 : bright black  //  9 : Bright blue  //  10 : Bright green  //  11 : Bright cyan  //  12 : Bright red  //  13 : Bright purple  //  14 : Bright yellow  //  15 : Bright white


// ********************************************************************************
/// <summary>
/// windows console's font changer
/// </summary>
/// <param name="fontName">Example: L"Consolas"</param>
// ********************************************************************************
extern "C" CONSOLEADJUSTMENTS_API void ConsoleFont ( const LPCWSTR fontName );


// ********************************************************************************
/// <summary>
/// windows console's font size changer
/// </summary>
/// <param name="fontSize">Example: {10,20}</param>
// ********************************************************************************
extern "C" CONSOLEADJUSTMENTS_API void ConsoleFontSize ( const COORD fontSize );


// ********************************************************************************
/// <summary>
/// windows console's font colour changer
/// </summary>
/// <param name="fontColour">Example: F_BLACK|B_BLACK which are the DLL's define constants values</param>
// ********************************************************************************
extern "C" CONSOLEADJUSTMENTS_API void ConsoleFontColour ( const WORD fontColour );


// ********************************************************************************
/// <summary>
/// windows console's screen position
/// </summary>
/// <param name="screenPosition">Example: {15,15}</param>
// ********************************************************************************
extern "C" CONSOLEADJUSTMENTS_API void ConsoleScreenPosition ( const COORD screenPosition );


// ********************************************************************************
/// <summary>
/// windows console's screen size in column and rows measures
/// </summary>
/// <param name="ColRowCount">Example: {100,30}</param>
// ********************************************************************************
extern "C" CONSOLEADJUSTMENTS_API void ConsoleScreenSize ( const COORD ColRowCount );


// ********************************************************************************
/// <summary>
/// windows console's screen colour
/// </summary>
/// <param name="ColRowCount">Example: B_BLACK which are the DLL's define constants values or RGB ( 100,100,100 ) format for more options</param>
// ********************************************************************************
extern "C" CONSOLEADJUSTMENTS_API void ConsoleScreenColour ( const COLORREF BGcolour );


// ********************************************************************************
/// <summary>
/// windows console's cursor state
/// </summary>
/// <param name="CursorVisible">Boolean value</param>
// ********************************************************************************
extern "C" CONSOLEADJUSTMENTS_API void ConsoleCursorState ( const bool CursorVisibility );


// ********************************************************************************
/// <summary>
/// Inserting string with colour
/// </summary>
/// <param name="strCharacter">String value</param>
/// <param name="Colour">Example: F_BLACK|B_BLACK which are the DLL's define constants values</param>
// ********************************************************************************
extern "C" CONSOLEADJUSTMENTS_API void ColourCouter ( const std::string strCharacter, const WORD Colour );


#endif // !CONSOLEADJUSTMENTS_H