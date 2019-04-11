// --------------------------------------------------------------------------------
/// <summary>
/// _2_Basics.cpp
/// </summary>
/// <created>ʆϒʅ,11.04.2018</created>
/// <changed>ʆϒʅ,12.04.2019</changed>
// --------------------------------------------------------------------------------

//! preprocessor directives:
// directives are special lines interpreted by what is known as preprocessor before the compilation of the program begins.
// example: #include <iostream>
// this directive instruct the preprocessor to include header iostream, which is a section of standard C++ code.
// header iostream after inclusion allow the program to perform standard input and output operations.
#include "pch.h"
#include "Console.h"


//! using namespace std:
//using namespace std;
// to write code simply by introducing visibility of components of the standard C++ library,
// on the other hand by qualifying each and every use of the elements, name collision can be avoided.
// after this declaration, explicit qualified std::cout is going to be replaced with unqualified name cout.
// std is the namespace of standard C++ library and cout is one of its elements.
// the examples in this tutorial are written using the explicit qualification.


void _02_01_StructureOfaProgram () // declaration of the function, explanation in function section
{ // braces {} indicate begin and end of a block of code, in this case the body code of the function
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ structure of a program:
    // a C++ program always start from the main function, no matter the order of definitions.
    // the main function of this program is in LearningCplusPlus.cpp file.
    // the main function is the only function which called automatically.
    // other functions can be executed if they are called directly or indirectly from main function.
    ColourCouter ( "~~~~~ Structure of a program:\n", F_bBLUE );
    ColourCouter ( "Although C++ language doesn't have any strict rules on structure and indention in source code, it is better for human understanding, that it be properly structured and indented.\n\n", F_YELLOW );

    // comment is the important tool, which provides direct documentation within source code
    // a line comment
    /// a documentation comment
    /* block
    comment*/

    // inserting an output
    std::cout << "Hello World! ";
    // std::cout is standard character output
    // << is insertion operator

    // '/n' is the newline character.
    std::cout << "I'm the first C++ example of this tutorial.\n\n";

    // semicolon (;): all statements in C++ must ends with semicolons.
    // preprocessor directives are not statements.

  }
  catch ( const std::exception& )
  {

  }
}


void _02_02_VariablesTypesAndIdentifiers ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ variables, types and identifiers:
    // variables are portions of memory that have types and are defined to store values.
    ColourCouter ( "~~~~~ Variables, types and identifiers:\n", F_bBLUE );
    ColourCouter ( "Portions of memory to store values of different types.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- declaration and initialization in different C++ revisions
    // declaration alone introduces variables with undetermined values,
    // therefore they are practically unusable till their first time value assignation.
    // initialization is the process of introducing a value for a variable in declaration time.
    // a valid identifiers could be built by a sequence of one or more letters, digits or underscore _
    // identifiers shall always begin with letters, additionally they can begin with underscore too.
    // programmers identifiers can not match C++ reserved keywords.
    // C++ is a case-sensitive language.
    // std::endl: flushes the stream and prints the newline character
    ColourCouter ( "----- Declaration and initialization in different C++ revisions:\n", F_bBLUE );
    ColourCouter ( "A variable must first be declared and in the moment of declaration, it can be initialized.\n\n", F_YELLOW );
    int a1 = 0; // C-like initialization
    int a2 ( 0 ); // constructor initialization (C++ language)
    std::cout << "Initialized with C-Like initialization:\t\t" << "a1: " << a1 << "\n";
    std::cout << "Initialized in constructor (C++ language):\t" << "a2: " << a2 << "\n";
    int aa { 0 }, bb { 0 }, result { 0 }; // C++ standard initialization (2011 revision)

    std::cout << "Initialized in C++ standard revision:\t\t" << "aa: " << aa << '\t' << "bb: " << bb << '\t' << "result: " << result << std::endl << std::endl;

    //! - in addition:
    // after declaration, a variable can be assigned its first time value or a new value.
    // some simple processes on variables for the time being:
    ColourCouter ( "Assigning new values to variables:\n", F_bYELLOW );
    std::cout << "aa: " << aa << '\t' << "bb: " << bb << '\t' << "Initialization's value of result is: " << result << std::endl;
    aa = 5;
    bb = 2;
    std::cout << "Assigned values:\t" << "aa: " << aa << '\t' << "bb: " << bb << std::endl << std::endl;
    aa = aa + 1;
    ColourCouter ( "Some processes on the variables above:\n", F_bYELLOW );
    std::cout << "Result of ( aa + 1 ):\t" << aa << std::endl;
    result = bb - aa;
    // last insertion:
    std::cout << "aa: " << aa << '\t' << "bb: " << bb << '\t' << "Result of ( bb - aa ): " << result << std::endl << std::endl;
  }
  catch ( const std::exception& )
  {

  }
}


void _02_03_FundamentalTypesAndDeduction ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ fundamental types and deduction
    // the zeros and ones stored in memory which represent variables need to be interpreted.
    // for this purpose the program needs to be aware of the kind of the stored data.
    // implementations of basic types, supported by most systems, directly into the language, represent basic storage units known as fundamental types.
    ColourCouter ( "~~~~~ Fundamental types and deduction:\n", F_bBLUE );
    ColourCouter ( "Fundamental types are the basics types supported by most systems.\n", F_YELLOW );
    ColourCouter ( "Deduction introduce the ability of the compiler, with which the type of an unknown variable can be identified.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- fundamental types: characters
    // ----------------------------------------------------------------
    // Type name    Size / Precision description
    // ----------------------------------------------------------------
    // char         Exactly one byte in size. At least 8 bits.
    // ----------------------------------------------------------------
    // char16_t     Not smaller than char. At least 16 bits.
    // ----------------------------------------------------------------
    // char32_t     Not smaller than char16_t. At least 32 bits.
    // ----------------------------------------------------------------
    // wchar_t      Can represent the largest supported character set.
    // ----------------------------------------------------------------
    ColourCouter ( "----- Fundamental types: Character types\n", F_bBLUE );
    ColourCouter ( "Character types can represents a single character and are in different sizes.\n\n", F_YELLOW );

    std::cout << "Size of char in byte:\t\t" << sizeof ( char ) << "\n";
    char ch1 { 'M' };
    std::cout << "char:\t\t\t\t" << ch1 << std::endl << std::endl;

    std::cout << "Size of char16_t in byte:\t" << sizeof ( char16_t ) << "\n";
    char16_t ch2 { 'M' };
    std::cout << "char16_t:\t\t\t" << ch2 << std::endl << std::endl;

    std::cout << "Size of char32_t in byte:\t" << sizeof ( char32_t ) << "\n";
    char32_t ch3 { 'M' };
    std::cout << "char32_t:\t\t\t" << ch3 << std::endl << std::endl;

    std::cout << "Size of wchar_t in byte:\t" << sizeof ( wchar_t ) << "\n";
    wchar_t ch4 { 'M' };
    std::cout << "wchar_t:\t\t\t" << ch4 << std::endl << std::endl;

    //! ####################################################################
    //! ----- fundamental types: integers
    // ------------------------------------------------------------------
    // Type name                Size / Precision description
    // ------------------------------------------------------------------
    // signed char              Same size as char. At least 8 bits.
    // ------------------------------------------------------------------
    // signed short int         Not smaller than char. At least 16 bits.
    // ------------------------------------------------------------------
    // signed int               Not smaller than short. At least 16 bits.
    // ------------------------------------------------------------------
    // signed long int          Not smaller than int. At least 32 bits.
    // ------------------------------------------------------------------
    // signed long long int     Not smaller than long. At least 64 bits
    // ------------------------------------------------------------------
    // unsigned char            Same size as its signed counterpart
    // ------------------------------------------------------------------
    // unsigned short int       "
    // ------------------------------------------------------------------
    // unsigned int             "
    // ------------------------------------------------------------------
    // unsigned long int        "
    // ------------------------------------------------------------------
    // unsigned long long int   "
    // ------------------------------------------------------------------
    ColourCouter ( "----- Fundamental types: integer types\n", F_bBLUE );
    ColourCouter ( "Integer types can represent numerical values, are in variety of sizes and can be either signed or unsigned.\n\n", F_YELLOW );

    signed char num1_1 { -128 }, num1_2 { 127 }; // hexadecimal: -0x80 to 0x7f
    unsigned char num1_3 { 0 }, num1_4 { 255 }; // hexadecimal: 0xff
    std::cout << "Size of char:\t\t\t" << sizeof ( char ) << "\n";
    std::cout << "Signed char range:\t\t" << static_cast<int>( num1_1 ) << "\t\t\tto\t" << static_cast<int>( num1_2 ) << "\n";
    std::cout << "Unsigned char range:\t\t" << static_cast<int>( num1_3 ) << "\t\t\tto\t" << static_cast<int>( num1_4 ) << "\n\n";

    short num2_1 = { -32768 }, num2_2 = { 32767 }; // hexadecimal: -0x8000 to 0x7fff
    unsigned short num2_3 { 0 }, num2_4 { 65535 }; // hexadecimal: 0xffff
    std::cout << "Size of short:\t\t\t" << sizeof ( short ) << "\n";
    std::cout << "Signed short range:\t\t" << num2_1 << "\t\t\tto\t" << num2_2 << "\n";
    std::cout << "Unsigned short range:\t\t" << num2_3 << "\t\t\tto\t" << num2_4 << "\n\n";

    int num3_1 { -2147483647 }, num3_2 { 2147483647 }; // hexadecimal: -0x7fffffff to 0x7fffffff
    unsigned int num3_3 { 0 }, num3_4 { 4294967295 }; // hexadecimal: 0xffffffff
    std::cout << "Size of int:\t\t\t" << sizeof ( int ) << "\n";
    std::cout << "Signed int range:\t\t" << num3_1 << "\t\tto\t" << num3_2 << "\n";
    std::cout << "Unsigned int:\t\t\t" << num3_3 << "\t\t\tto\t" << num3_4 << "\n\n";

    long num4_1 { -2147483647 }, num4_2 { 2147483647 }; // hexadecimal: -0x7fffffff to 0x7fffffff
    unsigned int num4_3 { 0 }, num4_4 { 4294967295 }; // hexadecimal: 0xffffffff
    std::cout << "Size of long:\t\t\t" << sizeof ( long ) << "\n";
    std::cout << "Signed long range:\t\t" << num4_1 << "\t\tto\t" << num4_2 << "\n";
    std::cout << "Unsigned long:\t\t\t" << num4_3 << "\t\t\tto\t" << num4_4 << "\n\n";

    long long num5_1 { -9223372036854775807 }, num5_2 { 9223372036854775807 }; // hexadecimal: -0x7fffffffffffffff to 0x7fffffffffffffff
    unsigned long long num5_3 { 0 }, num5_4 { 18446744073709551615 }; // // hexadecimal: -0xffffffffffffffff
    std::cout << "Size of long long:\t\t" << sizeof ( long long ) << "\n";
    std::cout << "Signed long long range:\t\t" << num5_1 << "\tto\t" << num5_2 << "\n";
    std::cout << "Unsigned long long:\t\t" << num5_3 << "\t\t\tto\t" << num5_4 << "\n\n";

    //! ####################################################################
    //! ----- fundamental types: floats
    // ------------------------------------------------------------------
    // Type name                Size / Precision description
    // ------------------------------------------------------------------
    // float                    (7 digits)
    // ------------------------------------------------------------------
    // double                   precision not less than float (15 digits)
    // ------------------------------------------------------------------
    // long double              precision not less than double (15 digits)
    // ------------------------------------------------------------------
    ColourCouter ( "----- Fundamental types: floats\n", F_bBLUE );
    ColourCouter ( "Depending on the kind of the floating-point of these types, they can represent real values with different levels of precision.\n\n", F_YELLOW );

    float num6_1 { 1.8e-38 }, num6_2 { 3.4e+38 };
    std::cout << "Size of float:\t\t" << sizeof ( float ) << "\n";
    std::cout << "Float range:\t\t" << num6_1 << "\t\tto\t" << num6_2 << "\n";

    double num7_1 { 2.2e-308 }, num7_2 { 1.79e+308 };
    std::cout << "Size of double:\t\t" << sizeof ( double ) << "\n";
    std::cout << "Double rang:\t\t" << num7_1 << "\tto\t" << num7_2 << "\n";

    long double num8_1 { 2.2e-308 }, num8_2 { 1.79e+308 };
    std::cout << "Size of long double:\t" << sizeof ( long double ) << "\n";
    std::cout << "Long double range:\t" << num8_1 << "\tto\t" << num8_2 << "\n\n";
    // check the link for more details on float: http://de.cppreference.com/w/cpp/language/types

    //! - in addition:
    // since C++ has a lot different compilers, when it comes to types C++ can give these guaranties:
    // char size 1 byte [-128...127]
    // short is smaller than int, which is smaller than long and long long is the largest one.
    // long long, which is a GCC extension, has found his way into C++ standard.

    //! ####################################################################
    //! ----- fundamental other types: bool, void and nullptr
    // ------------------------------------------------------------------
    // Type name                Size / Precision description
    // ------------------------------------------------------------------
    // bool                     one byte
    // ------------------------------------------------------------------
    // void                     no storage
    // ------------------------------------------------------------------
    // decltype (nullptr)       void pointer
    // ------------------------------------------------------------------
    ColourCouter ( "----- Fundamental other types: bool, void and nullptr\n", F_bBLUE );
    ColourCouter ( "The in C++ known as bool Boolean type, is a logical type and represents 'true' or 'false' as values.\n\n", F_YELLOW );

    bool bool_var_1 { true }, bool_var_2 { false };
    std::cout << "Size of bool:\t\t" << sizeof ( bool ) << "\n";
    std::cout << "Two bool variables:\t" << bool_var_1 << "\tand\t" << bool_var_2 << "\n\n";

    //! - in addition:
    // additional reference: https://docs.microsoft.com/en-us/cpp/cpp/void-cpp?view=vs-2017
    // void identifies the lack of type.
    // use: in function return types, function parameters, universal pointers
    // there is no constant or volatile variables of type void.
    //! - in addition:
    // some basic knowledge on void (universal) pointers:
    // they can be dereferenced only by casting to another type.
    // they can be converted to other types of data pointer.
    // they can point to a function but not to a class member.
    //! - in addition:
    // A null pointer (nullptr) is a value that any pointer can take to represent that it points to nowhere.
    // more on void and nullptr will be mentioned in further sections.
    ColourCouter ( "The lack of type is identified with 'void' keyword.\n", F_YELLOW );
    ColourCouter ( "Any pointer can point to nowhere by taking nullptr as its value.\n\n", F_YELLOW );
    void *void_poi; // uninitialized: can not be used
    int *int_poi; // uninitialized: can not be used
    int *nullptr_poi { nullptr }; // initialized to point to nowhere! :)
    std::cout << "The address of a pointer initialized with nullptr:\t\t\t\t" << nullptr_poi << "\n";
    int int_i { 22 };
    void_poi = &int_i;
    std::cout << "Variable address -pointed to by a void pointer-:\t\t\t\t" << void_poi << "\n";
    int_poi = (int*) void_poi; // casting operation: optional in C, required in C++
    std::cout << "Variable address -pointed to by a int pointer- -cast from void pointer-:\t" << int_poi << "\n\n";

    //! - in addition:
    // more infos on all fundamental types:
    // the properties of fundamental types in particular systems and compiler implementations:
    //! http://www.cplusplus.com/%3Climits%3E
    // types of specific sizes:
    //! http://www.cplusplus.com/%3Ccstdint%3E

    //! ####################################################################
    //! ----- strings:
    // the class string is one of the compound types in C++.
    // header file is <string>.
    ColourCouter ( "----- Strings:\n", F_bBLUE );
    ColourCouter ( "One of the compound types in C++ is the class string.\n\n", F_YELLOW );
    std::string str1 = { "This is the initial string." }; // initialization in C++ standard form.
    std::cout << "The string variable value is:\t" << str1 << "\n\n";

    // more details on standard C++ strings:
    //! http://www.cplusplus.com/string

    //! ####################################################################
    //! ----- deduction of type:
    // auto and decltype shall mainly be used when the type can't be determined or for improving the readability. the example below is non of them.
    ColourCouter ( "----- Deduction of type:\n", F_bBLUE );
    ColourCouter ( "Uses: determination of types, improving the readability.\n\n", F_YELLOW );
    int int_var { 0 };
    auto aut_var { int_var }; // same as: int aut_var { int_var }
    decltype( int_var ) dec_var { int_var }; // same as: int dec_var { int_var }
    std::cout << "Normal declaration and initialization:\t" << int_var << std::endl;
    std::cout << "Using auto to deduct the type:\t\t" << aut_var << std::endl;
    std::cout << "Using decltype to deduct the type:\t" << dec_var << std::endl << std::endl;
  }
  catch ( const std::exception& )
  {

  }
}


void _02_04_ConstantNumerals ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ constants numerals:
    // first kind of the most obvious constants are numerals, which can be of types integer or floating-point.
    // like variables numerals have types.
    // in the statement "i=5;" 5 is a numeral constant.
    ColourCouter ( "~~~~~ Constants numerals:\n", F_bBLUE );
    ColourCouter ( "One of the most obvious kind of constants are numerals.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- integer constants:
    // C++ allows the use of numbers in octal or hexadecimal base
    ColourCouter ( "----- Integer constants:\n", F_bBLUE );
    ColourCouter ( "Fixed values of type integer.\n\n", F_YELLOW );
    const int con1 { 75 }; // decimal
    const int con2 { 0113 }; // octal (preceded with 0)
    const int con3 { 0x4b }; // hexadecimal (preceded with 0x)
    std::cout << "Integer constant (initialized in decimal base):\t\t" << con1 << "\n";
    std::cout << "Integer constant (initialized in octal base):\t\t" << con2 << "\n";
    std::cout << "Integer constant (initialized in hexadecimal base):\t" << con3 << "\n\n";

    //! - in addition:
    // by default integer literals are "int" but they can be modified by appending certain suffixes.
    // modification of types: (these suffixes aren't case-sensitiv.)
    // -------------------
    // u        unsigned
    // -------------------
    // l        long
    // -------------------
    // ll       long long
    // -------------------
    ColourCouter ( "Modifying integer constant by using suffixes:\n\n", F_YELLOW );
    const int con4 { 75u };
    const int con5 { 0113lU };
    const int con6 { 0x4blL };
    const int con7 { 0X4buLl };
    std::cout << "Modified to type unsigned:\t\t" << con4 << "\n";
    std::cout << "Modified to type unsigned long:\t\t" << con5 << "\n";
    std::cout << "Modified to type long long:\t\t" << con6 << "\n";
    std::cout << "Modified to type unsigned long long:\t" << con7 << "\n\n";

    //! ####################################################################
    //! ----- floating point constants:
    // expressing real values which can include either decimal point or "e" character
    // "e" character stands for exponents, isn't case-sensitiv.
    // expresses "by ten at the Xth height" where "X" is an integer value that follows "e".
    // modification of types: (these suffixes aren't case-sensitiv.)
    // ---------------------
    // f        float
    // ---------------------
    // l        long double
    // ---------------------
    ColourCouter ( "----- Floating point constants:\n", F_bBLUE );
    ColourCouter ( "Fixed values of type floating point.\n\n", F_YELLOW );
    const double con8 { 3.14159f }; // the PI number
    const float con9 { static_cast<float>( 6.02e23L ) }; // the number of Avogadro
    const double con10 { 1.6E-19 }; // the number of electric charge of an electron
    const float con11 { 3.0 };
    std::cout << "The PI number:\t\t\t\t\t" << con8 << "\n";
    std::cout << "The Avogadro number:\t\t\t\t" << con9 << "\n";
    std::cout << "The number of electric charge of an electron:\t" << con10 << "\n";
    std::cout << "A float number:\t\t\t\t\t" << con11 << "\n\n";
  }
  catch ( const std::exception& )
  {

  }
}


void _02_05_ConstantLiterals ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ constant literals:
    // second kind of the most obvious constants are literals, which can be of types character or string
    // this kind of constants are enclosed in quotes.
    // ' for characters and "  for strings
    ColourCouter ( "~~~~~ Constant literals:\n", F_bBLUE );
    ColourCouter ( "Literals are the second most obvious kind in the sphere of constants.\n\n", F_YELLOW );

    ColourCouter ( "Some constant characters and strings:\n", F_bYELLOW );
    const char con12 { 'Z' };
    std::cout << "'Z' character:\t" << con12 << "\n";
    const std::string con13 = { "How do you do?" };
    std::cout << "A string:\t" << con13 << "\n\n";

    //! - in addition:
    // character and string literals can be used to represent special characters,
    // which are in most cases difficult or impossible to be used in the source code.
    ColourCouter ( "Constants ability (spacial characters):\n", F_bYELLOW );
    const char con14 { '\n' };
    const std::string con15 { "One\tTwo\tThree" };
    std::cout << "Special new line character:" << con14;
    std::cout << "Special tab characters:\t\t" << con15 << "\n\n";
    // ------------------------------------------------------------
    // escape sequence                      representation
    // ------------------------------------------------------------
    // \'                                   byte 0x27
    // ------------------------------------------------------------
    // \"                                   byte 0x22
    // ------------------------------------------------------------
    // \?                                   byte 0x3f
    // ------------------------------------------------------------
    // \\                                   byte 0x5c
    // ------------------------------------------------------------
    // \a           audible bell            byte 0x07
    // ------------------------------------------------------------
    // \b                                   byte 0x08
    // ------------------------------------------------------------
    // \f           form feed               byte 0x0c
    // ------------------------------------------------------------
    // \n           line feed               byte 0x0a
    // ------------------------------------------------------------
    // \r           carriage return         byte 0x0d
    // ------------------------------------------------------------
    // \t           horizontal tab          byte 0x09
    // ------------------------------------------------------------
    // \v           vertical tab            byte 0x0b
    // ------------------------------------------------------------
    // \nnn         arbitrary octal         byte nnn
    // ------------------------------------------------------------
    // \xnn         arbitrary hexadecimal   byte nn
    // ------------------------------------------------------------
    // \nnnnn       arbitrary Unicode       code point U+nnnn
    // ------------------------------------------------------------
    // \Unnnnnnnn   arbitrary Unicode       code point U+nnnnnnnn
    // ------------------------------------------------------------
    // Reference: http://de.cppreference.com/w/cpp/language/escape
    // ------------------------------------------------------------

    //! - in addition:
    // every character in computer is an ASCI code.
    // https://de.cppreference.com/w/cpp/language/ascii
    // examples: "\202","\x2d". for more on this check the link below.
    ColourCouter ( "Using ASCII code of characters:\n", F_bYELLOW );
    const char con16 { '\202' };
    const char con17 { '\x2d' };
    std::cout << "Initialled constants with ASCI code of characters:\t" << con16 << '\t' << con17 << "\n\n";

    //! - in addition:
    // simply by separating several literal strings by blank spaces they will be concatenated in one.
    // in C++ big literal strings within a twin of quotes can be written in more than one line by using "\" backslash character.
    // note: only blank spaces which are within the quotes are a part of the literal string, all the other ones or none at all will be ignored.
    ColourCouter ( "Concatenating string literals features in C++:\n", F_bYELLOW );
    const std::string con18 { "\
This strIng Is ""In ""the"   " soURce\
c0de"           " paRTed"  " And "
"wriTTen"           " In Four Line" }; // note: pay attention to the last two line!
    std::cout << "Check the initialization expression in source code:\n" << con18 << "\n\n";

    //! - in addition:
    // the type of the character and string literals can be modified by using specific prefixes
    // these prefixes are case-sensitive.
    // ------------------
    // u        char16_t
    // ------------------
    // U        char32_t
    // ------------------
    // L        whar_t
    // ------------------
    ColourCouter ( "Modification to the types of defined characters:\n", F_bYELLOW );
    const char16_t con19 { ( 'UZ' ) };
    const char32_t con20 { ( 'LZ' ) };
    const wchar_t con21 { ( 'uZ' ) };
    std::cout << "Modification of type (to char16_t):\t" << con19 << "\n";
    std::cout << "Modification of type (to char32_t):\t" << con20 << "\n";
    std::cout << "Modification of type (to wchar_t):\t" << con21 << "\n\n";

    //! - in addition:
    // two more prefixes are:
    // ----------------------------------
    // u8       encoding string in UTF_8
    // ----------------------------------
    // R        string is a raw string
    // ----------------------------------
    // in a raw string no special character is going to be identified
    // Note format:
    // R"sequence(string)sequence"
    // note: in the format above, the both delimiting sequences must be alike,
    // both are going to be ignored and both can be anything,
    // therefore what lies between parenthesis is the content of the string.
    // if needed the combinations of raw prefix and other ones (u, U, L and u8) are a possibility.
    ColourCouter ( "All possible modification to string literals:\n", F_bYELLOW );
    const std::string con22 { u8"Z\t!\tz" };
    const std::string con23 { u8R"aRawString(--\"' (^_^) AnY likeable StrIng (^.^) '"/--)aRawString" };
    std::cout << "Modifying the type of literal string to UTF_8:\t" << con22 << "\n";
    std::cout << "A raw string encoded in UTF_8:\t\t\t" << con23 << "\n\n";
  }
  catch ( const std::exception& )
  {

  }
}


void _02_06_OtherConstantLiterals ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ other constant literals:
    // third kind of constants is boolean and pointers type, that is keyword literals true, false and nullptr.
    ColourCouter ( "~~~~~ Other constant literals:\n", F_bBLUE );
    ColourCouter ( "In C++ language there are three other keyword literals which are 'true', 'false' and 'nullptr'.\n\n", F_YELLOW );
    const bool con24 { false };
    std::cout << "Boolean constant keyword literal 'false':\t" << con24 << "\n";
    const int *p { nullptr };
    std::cout << "Pointer constant keyword literal 'nullptr':\t" << p << "\n\n";

    //! ####################################################################
    //! ----- typed constant expressions (programmer defined):
    // for convenience sake, since some literals may often be repeated in source code.
    // an example:
    ColourCouter ( "----- Typed constant expressions:\n", F_bBLUE );
    ColourCouter ( "To avoid the often repetition of literals in the source code.\n\n", F_YELLOW );
    const char tab { '\t' };
    const char nline { '\n' };
    const double pi { 3.1415926 };
    double r { 5.0 }, circle;
    circle = 2 * r * pi;
    ColourCouter ( "Using typed constants:\n", F_bYELLOW );
    std::cout << "The circle circumference:" << tab << "2 * " << r << " * " << pi << " =  " << circle << nline << nline;


    //! ####################################################################
    //! ----- preprocessor definitions (#define):
    // another way to define constant values
    // Note syntax:
    // #define identifier replacement
    // the occurrences of identifier will be interpreted to replacement.
    // the replacement can be any set of characters till the end of the line.
    // the replacement happens before compiling by the preprocessor,
    // therefore the mechanism is a blind replacement and there is no verification of the involved syntax.
    // #define lines are preprocessor directives,
    // which means they are single line instructions and unlike statements don't need semicolons.
    // a semicolon in the replacement will be a part of the sequence,
    // so it is going to be included in all of the occurrences.
    ColourCouter ( "----- Preprocessor definitions:\n", F_bBLUE );
    ColourCouter ( "Another mechanism to define constant values.\n\n", F_YELLOW );
#define Tab '\t'
#define Nline '\n'
#define Pi 3.1415926
    circle = 2 * r * Pi;
    ColourCouter ( "Using preprocessor definitions:\n", F_bYELLOW );
    std::cout << "The circle circumference:" << Tab << "2 * " << r << " * " << Pi << " =  " << circle << Nline << Nline;
  }
  catch ( const std::exception& )
  {

  }
}


// scope start point of these constants
const char tab { '\t' };
const char nline { '\n' };
void _02_07_ArithmeticOperators ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    int x { 0 }, y { 2 }, z { 4 };

    //! ####################################################################
    //! ~~~~~ mathematical operators:
    // mathematical operators will be used to have mathematical operations on operands.
    ColourCouter ( "~~~~~ Mathematical operators:\n", F_bBLUE );
    ColourCouter ( "Mathematical operators represent the most important and basic mathematical operations.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- assignment operator (=):
    // the assignment operations always takes place from right to left.
    ColourCouter ( "----- Assignment operator (=):\n", F_bBLUE );
    ColourCouter ( "The most simple mathematical operation in C++ is represented by assignment.\n\n", F_YELLOW );
    std::cout << "Current values are:" << "\t\t\t" << "x: " << x << tab << "y: " << y << nline;
    x = 5;
    std::cout << "The values after first assignment:" << tab << "x: " << x << tab << "y: " << y << nline;
    x = y;
    std::cout << "The values after second assignment:" << tab << "x: " << x << tab << "y: " << y << nline;
    x = y = 3; // valid in C++
    std::cout << "The values after third assignment:" << tab << "x: " << x << tab << "y: " << y << nline << nline;

    //! - in addition:
    // assignment operation can be evaluated, this means the assignment itself has a value,
    // which in fundamental types is the value that assigned in the operation.
    ColourCouter ( "The value of assignment operation:\n", F_bYELLOW );
    y = 6 + ( x = 10 ); // y is 6 + the value of another assignment operation
    std::cout << "y = 6 + ( x = 10 ):" << tab << "x: " << x << tab << "y: " << y << nline << nline;


    //! ####################################################################
    //! ----- arithmetic operators (+, -, *, /, %):
    // percentage sign represent modulo which is the remainder of a division.
    ColourCouter ( "----- Arithmetic operator (+, -, *, /, %):\n", F_bBLUE );
    ColourCouter ( "The most simple arithmetic operators with the most use.\n\n", F_YELLOW );
    x = 40 % 9;
    std::cout << "The result of modulo operator ( 40 % 9 ):" << tab << "x: " << x << nline << nline;

    //! ####################################################################
    //! ----- compound assignments (+=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=):
    // modification of the current value of the variable by performing an operation on it.
    ColourCouter ( "----- Compound assignments (+=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=):\n", F_bBLUE );
    ColourCouter ( "To introduce expressions that modify the current value while assigning.\n\n", F_YELLOW );
    std::cout << "Current values are:" << "\t\t\t" << "x: " << x << tab << "y: " << y << nline;
    y *= x + 1; // equivalent to y=y*(x+1)
    std::cout << "Result of expression ( y *= x + 1 ):" << tab << "x: " << x << tab << "y: " << y << nline << nline;

    //! ####################################################################
    //! ----- increment and decrement (++, --):
    // these operators increase or decrease the value stored in a variable by one.
    ColourCouter ( "----- Increment and decrement (++, --):\n", F_bBLUE );
    ColourCouter ( "Increment and decrement of the value by one.\n\n", F_YELLOW );
    std::cout << "Current values are:" << "\t\t" << "x: " << x << tab << "y: " << y << nline;
    x++;// equivalent to x+=1 or x=x+1
    --y;
    std::cout << "Result of expression ( x++ ):" << tab << "x: " << x << nline;
    std::cout << "Result of expression ( --y ):" << tab << "y: " << y << nline << nline;

    //! - in addition:
    // these operators can be used both as prefix and as suffix.
    // although simple expressions like ++x and x++ have the same meaning,
    // they result a different value in different expressions.
    ColourCouter ( "Difference between the expressions ( y = ++x ) and ( y = x++ ):\n", F_bYELLOW );
    x = 3;
    y = 0;
    std::cout << "Current values are:" << "\t\t\t" << "x: " << x << tab << "y: " << y << nline;
    y = ++x; // y = x after the increment
    std::cout << "Result of expression ( y = ++x ):" << tab << "y: " << y << nline << nline;
    x = 3;
    y = 0;
    std::cout << "Current values are:" << "\t\t\t" << "x: " << x << tab << "y: " << y << nline;
    y = x++; // y = x before the increment
    std::cout << "Result of expression ( y = x++ ):" << tab << "y: " << y << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _02_08_LagicalOperators ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    int x { 0 }, y { 2 }, z { 4 };

    //! ####################################################################
    //! ~~~~~ boolean operators:
    // boolean operators will be used to have logical operations on operands.
    ColourCouter ( "~~~~~ Boolean operators:\n", F_bBLUE );
    ColourCouter ( "Boolean operators represent the logical operations.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- relational and comparison operators (==, !=, <, > ,<=, >=):
    // the results of comparison are going be boolean. any value can be compared.
    ColourCouter ( "----- Relational and comparison operators (==, !=, <, > ,<=, >=):\n", F_bBLUE );
    ColourCouter ( "To introduce the comparison of expressions.\n\n", F_YELLOW );
    std::cout << "To be compared values are:" << "\t\t\t" << "x: " << x << tab << "y: " << y << tab << "z: " << z << nline;
    if ( ( x + 6 ) >= ( y*x ) )
    {
      if ( ( z - x ) >= y )
      {
        std::cout << "Result of expression ( z != y ):" << "\t\t" << ( z != y ) << nline;
        // the use of = and == operators needs some attention:
        std::cout << "Result of expression (( z = 2 ) == x ):" << tab << ( ( z = 2 ) == x ) << tab << "z: " << z << nline << nline;
      }
    }

    //! ####################################################################
    //! ----- logical operators (!, &&, ||):
    // the operator ! (logical NOT) inverts its one operand, which will be written to its right.
    ColourCouter ( "----- Logical operators (!, &&, ||):\n", F_bBLUE );
    ColourCouter ( "Logical operators evaluate their operands to come up with the rational end results.\n\n", F_YELLOW );
    std::cout << "Current values are:" << "\t\t\t" << "x: " << x << tab << "y: " << y << tab << "z: " << z << nline;
    std::cout << "Result of expression !( x <= y ): " << tab << !( x <= y ) << nline;
    std::cout << "Result of expression !( y >= z ): " << tab << !( y >= z ) << nline << nline;

    //! - in addition:
    // short circuit evaluation: C++ only evaluates what is necessary to come up with the combined relational result.
    // this evaluation happens from left to right.
    // for example in '(x==y)&&(x<=y)' statement, considering the logical AND, if 'x==y' is false, C++ never checks the rest of the statement.
    ColourCouter ( "Short circuit evaluation in C++:\n", F_bYELLOW );
    std::cout << "Current values are:" << "\t\t\t\t\t" << "x: " << x << tab << "y: " << y << nline;
    if ( !( x == y ) )
    {
      std::cout << "Result of expression (( x == y ) && ( x <= y )):" << tab << ( ( x == y ) && ( x <= y ) ) << nline;
      std::cout << "Result of expression (( x == y ) || ( x >= y )):" << tab << ( ( x == y ) || ( x >= y ) ) << nline << nline;
    }

    //! - in addition:
    // this is most important when it comes to statements that has side effects.
    // for example altering values in the right-hand expression.
    ColourCouter ( "Side effects of short circuit evaluation:\n", F_bYELLOW );
    std::cout << "Current values are:" << tab << "x: " << x << tab << "y: " << y << tab << "z: " << z << nline;
    if ( ( x == 4 ) || ( ++y > z ) ) // if x==4 is true, then ++y will never be executed
      std::cout << "The increment in (( x == 4 ) || ( ++y > z )) is going to happen if x isn't 4:" << nline;
    std::cout << "Current values are:" << tab << "x: " << x << tab << "y: " << y << tab << "z: " << z << nline << nline;

    //! ####################################################################
    //! ----- conditional ternary operator (?):
    // if its condition is true, the operator will return result1 and otherwise result2.
    // Note statement syntax (format):
    // condition ? result1 : result2
    ColourCouter ( "----- Conditional ternary operator (?):\n", F_bBLUE );
    ColourCouter ( "This operator evaluate an expression and returns one value.\n\n", F_YELLOW );
    std::string str_result;
    int int_result;
    std::cout << "Current values are:" << "\t\t" << "x: " << x << tab << "y: " << y << tab << "z: " << z << nline;
    str_result = ( ( x == y ) && ( x > z ) ) ? "True" : "False";
    int_result = ( ( x == y ) && ( x > z ) ) ? x : z;
    std::cout << "Result of expression (( x == y ) && ( x > z )) ? \"True\" : \"False\";\tis:" << tab << str_result << nline;
    std::cout << "Result of expression (( x == y ) && ( x > z )) ? x : z;\t\t\tis:" << tab << int_result << nline << nline;

    //! ####################################################################
    //! ----- comma operator (,):
    // this operator will be used to separate the expressions,
    // when there are more than one expression in a statement that actually suppose to have one.
    ColourCouter ( "----- Comma operator (,):\n", F_bBLUE );
    ColourCouter ( "Separating the expressions is what this operator does.\n\n", F_YELLOW );
    std::cout << "Current values are:" << "\t\t\t\t" << "x: " << x << tab << "y: " << y << tab << "z: " << z << nline;
    z = ( x = 2, ++y * x );
    std::cout << "Result of expression (x = 2, ++y * x):" << "\t\t" << z << nline << nline;

    //! - in addition:
    // in cases that the set of expressions need to be evaluated for a value to be reached,
    // only the most right expression is considered.
    ColourCouter ( "Evaluation of a set of expressions and reaching a value:\n", F_bYELLOW );
    std::cout << "Current values are:" << "\t\t\t\t\t" << "x: " << x << tab << "y: " << y << tab << "z: " << z << nline;
    z = ( x = 2, x + 2 ); // in this expression set, first the assignment 'b=2' is considered and then the rest.
    std::cout << "Result of expression ( x = 2, x + 2 ):" << "\t\t\t" << z << nline << nline;
    std::cout << "Current values are:" << "\t\t\t\t\t" << "x: " << x << tab << "y: " << y << tab << "z: " << z << nline;
    z = ( x >= 2, y <= 4, y != 4 ); // in this expression set, only the last expression 'y!=4' is considered.
    std::cout << "Result of expression ( x >= 2, y <= 4, y != 4 ):" << tab << z << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _02_09_OtherOperators ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    int x { 0 }, y { 2 }, z { 4 };

    //! ####################################################################
    //! ~~~~~ other operators:
    // 
    ColourCouter ( "~~~~~ Other operators:\n", F_bBLUE );
    ColourCouter ( "The introduction of some other important operators.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- bitwise operators (&, |, ^, ~, <<, >>):
    // modifying an operand in its stored bit patterns which represent their value in system.
    // ----------------------------------------------
    // &    AND     bitwise And
    // ----------------------------------------------
    // |    OR      bitwise inclusive or
    // ----------------------------------------------
    // ^    XOR     bitwise exclusive or
    // ----------------------------------------------
    // ~    NOT     unary complement (bit inversion)
    // ----------------------------------------------
    // <<   SHL     shift bits left
    // ----------------------------------------------
    // >>   SHR     shift bits right
    // ----------------------------------------------
    char xx { 1 };
    ColourCouter ( "----- Bitwise operators (&, |, ^, ~, <<, >>):\n", F_bBLUE );
    ColourCouter ( "To introduce modification on the stored bit patterns of a value.\n\n", F_YELLOW );
    std::cout << "Current value which stays unchanged:" << tab << xx << nline;
    ColourCouter ( "The result of modification:\n", F_bYELLOW );
    std::cout << "Result of expression ( x & x ):" << "\t\t" << ( xx & xx ) << nline; // -0001 and -0001 = -0001
    std::cout << "Result of expression ( x | x ):" << "\t\t" << ( xx | xx ) << nline; // -0001 or -0001 = -0001
    std::cout << "Result of expression ( x ^ x ):" << "\t\t" << ( xx ^ xx ) << nline; // -0001 xor -0001 = -0000
    std::cout << "Result of expression ( ~x ):" << "\t\t" << ( ~xx ) << nline; // not -0001 = -1110
    std::cout << "Result of expression ( x << 2 ):" << tab << ( xx << 2 ) << nline; // left shift -0001 = -0100
    std::cout << "Result of expression ( x >> 2 ):" << tab << ( xx >> 2 ) << nline << nline; // right shift -0001 = -0000

    //! ####################################################################
    //! ----- explicit type casting operator:
    // convert the value of a given type to another type
    ColourCouter ( "----- Explicit type casting operator:\n", F_bBLUE );
    ColourCouter ( "To introduce the conversion of the type of a value to another type:\n\n", F_YELLOW );
    float f { static_cast<float> ( 3.14 ) }; // type casting in C++ standard 2011 revision (initialization)
    std::cout << "Current values:" << "\t\t\t\t\t\t" << "float: " << f << tab << "int: " << x << nline;
    x = (int) f; // C-like explicit type casting
    std::cout << "Converting the type (C-like explicit type casting):" << tab << x << nline;
    x = int ( f ); // C++ functional notation casting
    std::cout << "Converting the type (C++ functional notation casting):" << tab << x << nline << nline;

    //! ####################################################################
    //! ----- The 'sizeof' operator:
    // sizeof: take one parameter (type or variable) and return the size in bytes.
    ColourCouter ( "----- The 'sizeof' operator:\n", F_bBLUE );
    ColourCouter ( "Returns the size of fundamental types.\n\n", F_YELLOW );
    x = sizeof ( long long ); // the returned value of 'sizeof' is a compile-time constant (before program execution)
    std::cout << "The size of type long long is:" << tab << x << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _02_10_PrecedenceOfOperators ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    int x { 0 }, y { 2 }, z { 4 };

    //! ####################################################################
    //! ~~~~~ precedence of operators:
    // higher precedence of operators determines the evaluation order of operators in an expression
    ColourCouter ( "~~~~~ Precedence of operators:\n", F_bBLUE );
    ColourCouter ( "Defines the evaluation order of operators in an expression.\n\n", F_YELLOW );
    x = 2 + 5 % 2; // the remainder operator will be evaluated first
    std::cout << "The result of expression ( 2 + 5 % 2 ):" << "\t\t" << x << nline << nline;

    //! - in addition:
    // uses of parenthesis:
    // to explicitly clarify the intended effect
    // to override the precedence of operators
    ColourCouter ( "Overriding the precedence of operators:\n", F_bYELLOW );
    x = 2 + ( 5 % 2 ); // same as without parenthesis
    std::cout << "The result of expression ( 2 + ( 5 % 2 )):" << tab << x << nline;
    x = ( 2 + 5 ) % 2; // overriding the precedence
    std::cout << "The result of expression (( 2 + 5 ) % 2 ):" << tab << x << nline << nline;

    //! - in addition:
    // evaluation of C++ operator from greatest to smallest happen in the following order:
    // -------------------------------------------------------------------------------------------------------
    // Level    Precedence Group        Operator            Description                         Grouping
    // -------------------------------------------------------------------------------------------------------
    // 1        Scope                   ::                  scope qualifier                     left-to-right
    // -------------------------------------------------------------------------------------------------------
    // 2        Postfix (unary)         ++ --               postfix increment / decrement       left-to-right
    // 2        "                       ()                  functional forms                    "
    // 2        "                       []                  subscript                           "
    // 2        "                       . ->                member access                       "
    // -------------------------------------------------------------------------------------------------------
    // 3        Prefix (unary)          ++ --               prefix increment / decrement        Right-to-left
    // 3        "                       ~ !                 bitwise NOT / logical NOT           "
    // 3        "                       + -                 unary prefix                        "
    // 3        "                       & *                 reference / dereference             "
    // 3        "                       new delete          allocation / deallocation           "
    // 3        "                       sizeof              parameter pack                      "
    // 3        "                       (type)              C-style type casting                "
    // -------------------------------------------------------------------------------------------------------
    // 4        pointer-to-member       .* ->*              access pointer                      left-to-right
    // 5        Arithmetic: scaling     * / %               multiply, divide, modulo            "
    // 6        Arithmetic: addition    + -                 addition, subtraction               "
    // 7        Bitwise shift           << >>               shift left, shift right             "
    // 8        Relational              < > <= >=           comparison operators                "
    // 9        Equality                == !=               equality / inequality               "
    // 10       And                     &                   bitwise AND                         "
    // 11       Exclusive or            ^                   bitwise XOR                         "
    // 12       Inclusive or            |                   bitwise OR                          "
    // 13       Conjunction             &&                  logical AND                         "
    // 14       Disjunction             ||                  logical OR                          "
    //          Assignment-level        = *= /= %= -=       assignment / compound
    // 15       expressions             >>= <<= &= ^= |=    assignment                          Right-to-left
    //                                  ? :                 conditional operator
    // 16       sequencing              ,                   comma separator                     left-to-right
    // -------------------------------------------------------------------------------------------------------

    // an expression that has two the same precedence level operators, either left-to-right or right-to-left groupings determine which one is first to be evaluated. so every operator based on its defined precedence and grouping is independent.
    // therefore, the consideration is there, that enclosure in parenthesis is a good practice and can improve the code readability.

    //! - in addition:
    // there are some other operators such as ones referring to pointers or
    // the specifics for object-oriented programming, which will be introduced later on.
  }
  catch ( const std::exception& )
  {

  }
}


void _02_11_BasicInputOutput ()
{
  try
  {
    ColourCouter ( "--------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ basic input/output:
    // standard features to interact with users.
    // abstraction streams is the convenient way C++ use to perform input/ output operations in sequential media like screen.
    // a stream is an entity, where a program can interact with, also inserting or extracting characters to/from.
    // there are a handful of streams defined in the standard library to access the standard source and destination in an environment where the program runs.
    // the most useful ones are:
    // ------------------------------------------
    // cin      standard input stream
    // cin      standard output stream
    // cin      standard error (output) stream
    // cin      standard logging (output) stream
    // ------------------------------------------
    // The streams cin and cout will be mentioned in details.
    // cerr and clog streams work like the cout stream with the difference,
    // that they identify streams for error messages and logging
    // which in many cases and most environment setups they do the same thing which is printing on screen,
    // although they can be individually redirected.
    ColourCouter ( "~~~~~ Basic input/output (cin, cout, cerr and clog):\n", F_bBLUE );
    ColourCouter ( "The streams are the standard features, which C++ language uses to interact with users.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- standard output (cout):
    // default output of this stream is screen and processes the operation with using the insertion operator (<<)
    // which inserts the data into the stream that precedes it
    ColourCouter ( "----- Standard output (cout):\n", F_bBLUE );
    ColourCouter ( "Inserting outputs of different types:\n\n", F_YELLOW );
    std::cout << "An output string"; // a string literal
    std::cout << '\n'; // a character literal
    std::cout << 23487284; // a number literal (numeral)
    std::cout << nline; // a variable of type char (\n)
    std::cout << nline;
    ColourCouter ( "Chained insertion:\n", F_bYELLOW );
    std::cout << "Current year is: " << tab << 2018 << nline << "My birth year is: " << tab << 1989 << nline;

    //! - in addition:
    // since cout dosen't automatically break the line, "\n" or endl manipulator will be used instead.
    // endl manipulator break the line and flushes the buffer which means to physically write the output in device.
    // this affects the fully-buffered systems but cout generally isn't one.
    // it is a good idea to use it as an extra feature when needed,
    // since it incurs a certain overhead and on some devices it may produce a delay.
    std::cout << nline << "Breaking the line:" << nline;
    std::cout << "\n ____This is the sentence in between____ \n" << std::endl;

    //! ####################################################################
    //! ----- standard input (cin):
    // default input of this stream is keyboard, and processes the operation with the help of extraction operator (>>),
    // which followed by the variable where the extracted data needs to be stored.
    // the extraction of characters from input by cin stream will be continued till the user presses the enter or return key.
    // depended on the type of the variable, cin stream determines how to interpret the entered characters.
    ColourCouter ( "----- Standard input (cin):\n", F_bBLUE );
    ColourCouter ( "Extracting inputs of different types:\n\n", F_YELLOW );
    char char_in;
    std::cout << "Please enter a character as input:" << tab;
    std::cin >> char_in;
    std::cout << "The character you have entered is:" << tab << char_in << nline << nline;

    //! - in addition:
    // taking input from cin stream is easy but it has a big drawback.
    // if the entered characters couldn't be interpreted to an integer type for example, when they need to,
    // the program continue and the result of process is unknown.
    // a program shall handle invalid values properly, independent from what user enters.
    // for this purpose, latter on the stringstreams will be used to have a better control on user input.
    ColourCouter ( "The drawback of cin:\n", F_bYELLOW );
    int int_in;
    ColourCouter ( "Test: for the next insertion input a character:\n", F_bCYAN );
    ColourCouter ( "-- If you try it, you probably need to debug the program again. ^_^\n", F_bCYAN );
    std::cout << "Please enter a number as input:" << "\t\t";
    std::cin >> int_in; // unknown results caused from unwanted inputs
    std::cout << "The double of it is:" << "\t\t\t" << int_in * 2 << nline << nline;

    //! - in addition:
    // chained extraction of more than one datum in one line.
    // user must separate inputs with blank spaces such as white space, tab or new line.
    ColourCouter ( "Chained extraction:\n", F_bYELLOW );
    int int_in2;
    std::cout << "Please enter two integer values as input (separate them with any kind of spaces):" << nline;
    std::cout << "  - ";
    std::cin >> int_in >> int_in2; // chained extraction
    std::cout << "The entered values are:" << "\t\t" << int_in << tab << int_in2 << nline << nline;

    //! - in addition:
    // the stream cin can extract strings just like other fundamental types. the only problem is that it consider any type of spaces as termination of the operation so it can only extract a single word by one extraction operator.
    // to get an entire line with the stream cin the function getline() from the standard library can be used.
    // what users generally expect for inputs to happen in console environment is to introduce the field and press enter or return. in terms of lines getline function can be used to obtain inputs from user.
    // if there isn't any strong reason not to, getline shall be used to extract inputs instead of cin.
    ColourCouter ( "Extracting an entire line (string):\n", F_bYELLOW );
    std::string str_in;
    std::cout << "Please enter a line of string containing spaces:" << nline << "  - ";
    std::cin >> str_in; // extracting the input till first space
    std::cout << "The stream cin did extract the first word which is:" << tab << str_in << nline << nline;
    std::cout << "Please enter another line of string containing spaces:" << nline << "  - ";
    std::getline ( std::cin, str_in ); // clear unneeded buffered characters
    // std::cin.ignore (100,'\n'); // clear unneeded buffered characters (another way but in most cases not a good idea)
    std::getline ( std::cin, str_in ); // getting a line with spaces
    std::cout << "The extracted line with getline function is:" << "\t\t" << str_in << nline << nline;

    //! ####################################################################
    //! ----- the type stringstream:
    // this type which is defined in standard header <sstream> allows the strings to be treated like streams,
    // thus allowing the insertion and extraction operations to be performed on strings like what happens in cin or cout streams.
    // the most useful means of this feature is to convert string to numeral values and vice versa.
    ColourCouter ( "----- The type stringstream:\n", F_bBLUE );
    ColourCouter ( "Performing insertion and extraction on strings just like what happens in cin or cout stream.\n\n", F_YELLOW );
    ColourCouter ( "Converting string to int:\n", F_bYELLOW );
    std::string str_var { "2048 ABC 1024" };
    std::cout << "The string containing numeral values:" << "\t\t" << str_var << nline;
    int int_var;
    std::stringstream ( str_var ) >> int_var; // extract the value from a stringstream constructed from the string variable
    std::cout << "The value converted from string to integer:" << tab << int_var << nline << nline;

    //! - in addition:
    // acquiring numeric values indirectly from the standard input:
    // using getline and stringstream instead of cin
    // the goal is to separate the input process from its interpretation as data.
    // a demonstration of extracting in the user-expected behaviour of console programs and in the same time gaining more control over the transformation of inputs into more useful data.
    ColourCouter ( "Separating input process from its interpretation:\n", F_bYELLOW );
    std::string str_var2;
    float price { 0 }; int quantity { 0 };
    std::cout << "  - Enter the price:" << "\t\t";
    //std::getline (std::cin, str_var2); //clear
    std::getline ( std::cin, str_var2 );
    std::cout << "The entered string is:" << "\t\t" << str_var2 << nline;
    std::stringstream ( str_var2 ) >> price;
    std::cout << "The interpreted value is:" << "\t\t" << price << nline;
    std::cout << "  - Enter the quantity:" << "\t\t";
    //std::getline (std::cin, str_var2); //clear
    std::getline ( std::cin, str_var2 );
    std::cout << "The entered string is:" << "\t\t" << str_var2 << nline;
    std::stringstream ( str_var2 ) >> quantity;
    std::cout << "The interpreted value is:" << "\t\t" << quantity << nline;
    std::cout << "  - The total price is:" << "\t\t" << price * quantity << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}