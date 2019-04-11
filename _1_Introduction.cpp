// --------------------------------------------------------------------------------
/// <summary>
/// _1_Introduction.cpp
/// </summary>
/// <created>ʆϒʅ,20.12.2018</created>
/// <changed>ʆϒʅ,09.03.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "Console.h"


void _01_01_Introduction ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ C++ language:
        // over the years the evolution of the C++ language was constant.
        // therefore having a compiler with the ability to support the most recent feature is self-explanatory.
        ColourCouter ( "~~~~~ C++ Language:\n", F_bBLUE );
        ColourCouter ( "The constant evolution of the C++ language over the years, make the use of a compiler with support for the most recent feature self-explanatory.\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- C++ compilers:
        // rewriting the code in high-level language to machine language happens with the help of special programs called compilers, interpreters or assemblers based on the type of the high level language.
        // C++ language is designed to be a compiled language, therefore its code generally get translated into machine language, which results to a highly efficient program.
        // for this purpose, a set of tools, known as development toolchain, are needed, whose core are a compiler and its linker.
        ColourCouter ( "----- C++ Compilers:\n", F_bBLUE );
        ColourCouter ( "The compilers job are to rewrite the code in higher level language into machine language, which have been built into various programming applications\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- console programs:
        // the fact of easy interaction, simple implementation and identical behaviour of console programs across all platforms make them very useful to learn the basics of a programming language.
        // the programmer's decision to use a particular tool defines the way, in which a console program get compiled.
        ColourCouter ( "----- Console Programs:\n", F_bBLUE );
        ColourCouter ( "They are programs that use characters to communicate with user and their environment i.e. printer, keyboard etc.\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- IDE:
        // generally several development tools get integrated in an IDE, which includes a text editor and tools to compile the program directly.
        // some free IDE's:
        // ---------------------------------------------
        // IDE                      Platform
        // ---------------------------------------------
        // Code::blocks             Windows/Linux/MacOS
        // ---------------------------------------------
        // Visual Studio Express    Windows
        // ---------------------------------------------
        // Dev-C++                  Windows
        // ---------------------------------------------
        ColourCouter ( "----- IDE:\n", F_bBLUE );
        ColourCouter ( "The easiest way for a beginner is to use an Integrated Development Environment (IDE).\n\n", F_YELLOW );

        //! - in addition:
        // if there is a Linux or Mac environment with development features at disposal, with including the C++11 flags in the command for the compiler, any code could be compilable.
        // ----------------------------------------------------------------------------------------------------------
        // IDE          Platform                    Command
        // ----------------------------------------------------------------------------------------------------------
        // GCC          Linux, among others...      g++ -std=c++0x example.cpp -o example_program
        // ----------------------------------------------------------------------------------------------------------
        // Clang        OS X, among others...       clang++ -std=c++11 -stdlib=libc++ example.cpp -o example_program
        // ----------------------------------------------------------------------------------------------------------

    }
    catch ( const std::exception& )
    {

    }
}