<?xml version="1.0"?><doc>
<members>
<member name="M:ConsoleFont(System.Char!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsConst)" decl="true" source="c:\users\smehr\source\repos\dlls\consoleadjustments\consoleadjustments.h" line="2">
<summary>
the searched and confronted ways for manipulation of Windows's console screen by the code itself in runtime.
</summary>
<returns></returns>
<created>ʆϒʅ,02.10.2018</created>
<changed>ʆϒʅ,10.01.2019</changed>
<summary>
windows console's font changer
</summary>
<param name="fontName">Example: L"Consolas"</param>
</member>
<member name="M:ConsoleFontSize(_COORD!System.Runtime.CompilerServices.IsConst)" decl="true" source="c:\users\smehr\source\repos\dlls\consoleadjustments\consoleadjustments.h" line="73">
<summary>
windows console's font size changer
</summary>
<param name="fontSize">Example: {10,20}</param>
</member>
<member name="M:ConsoleFontColour(System.UInt16!System.Runtime.CompilerServices.IsConst)" decl="true" source="c:\users\smehr\source\repos\dlls\consoleadjustments\consoleadjustments.h" line="82">
<summary>
windows console's font colour changer
</summary>
<param name="fontColour">Example: F_BLACK|B_BLACK which are the DLL's define constants values</param>
</member>
<member name="M:ConsoleScreenPosition(_COORD!System.Runtime.CompilerServices.IsConst)" decl="true" source="c:\users\smehr\source\repos\dlls\consoleadjustments\consoleadjustments.h" line="91">
<summary>
windows console's screen position
</summary>
<param name="screenPosition">Example: {15,15}</param>
</member>
<member name="M:ConsoleScreenSize(_COORD!System.Runtime.CompilerServices.IsConst)" decl="true" source="c:\users\smehr\source\repos\dlls\consoleadjustments\consoleadjustments.h" line="100">
<summary>
windows console's screen size in column and rows measures
</summary>
<param name="ColRowCount">Example: {100,30}</param>
</member>
<member name="M:ConsoleScreenColour(System.UInt32!System.Runtime.CompilerServices.IsLong!System.Runtime.CompilerServices.IsConst)" decl="true" source="c:\users\smehr\source\repos\dlls\consoleadjustments\consoleadjustments.h" line="109">
<summary>
windows console's screen colour
</summary>
<param name="ColRowCount">Example: B_BLACK which are the DLL's define constants values or RGB ( 100,100,100 ) format for more options</param>
</member>
<member name="M:ConsoleCursorState(System.Boolean!System.Runtime.CompilerServices.IsConst)" decl="true" source="c:\users\smehr\source\repos\dlls\consoleadjustments\consoleadjustments.h" line="118">
<summary>
windows console's cursor state
</summary>
<param name="CursorVisible">Boolean value</param>
</member>
<member name="M:ColourCouter(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;!System.Runtime.CompilerServices.IsConst,System.UInt16!System.Runtime.CompilerServices.IsConst)" decl="true" source="c:\users\smehr\source\repos\dlls\consoleadjustments\consoleadjustments.h" line="127">
<summary>
Inserting string with colour
</summary>
<param name="strCharacter">String value</param>
<param name="Colour">Example: F_BLACK|B_BLACK which are the DLL's define constants values</param>
</member>
</members>
</doc>