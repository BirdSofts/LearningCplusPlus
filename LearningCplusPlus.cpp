
// --------------------------------------------------------------------------------
/// <summary>
/// ............................::Nerd snow sayings!::............................
/// nerd Snow's sayings!
/// Learning C++
/// Programming needs patience and practical practice.
/// Programming in a way, that no nerdy dog in the future is able to compile it, is to be avoided!
/// I was almost a good nerd and emptied my Recycle Bin regularly at the night! :) So be a lamb (^.^) and stay a good nerd!
/// </summary>
/// <created>ʆϒʅ,11.04.2018</created>
/// <changed>ʆϒʅ,13.10.2019</changed>
// --------------------------------------------------------------------------------

#include "LearningCplusPlus.h"
#include "Console.h"
#include "_1_Introduction.h"
#include "_2_BasicsOfCplusPlus.h"
#include "_3_ProgramStructure.h"
#include "_4_CompoundDataTypes.h"
#include "_5_Classes.h"
#include "_6_OtherLanguageFeatures.h"
#include "_7_cPlusPlusStandardLibrary.h"


int main ()
{
  try
  {
#pragma region Console
    // font
    COORD fontS { 16,16 };
    ConsoleFont ( L"Courier New" );
    ConsoleFontSize ( fontS );
    ConsoleFontColour ( F_WHITE );
    // screen
    COORD leftANDtop { 15,15 };
    COORD widthANDheight { 102,32 };
    COLORREF backColour { RGB ( 50,50,50 ) };
    ConsoleScreenPosition ( leftANDtop );
    ConsoleScreenSize ( widthANDheight );
    ConsoleScreenColour ( backColour );

    //// cursor
    //ConsoleCursorState ( false );

    //// codec
    //UINT consoleOutputCPstorage;
    //consoleOutputCPstorage = GetConsoleOutputCP ();
    //SetConsoleOutputCP ( CP_UTF8 );

    //// back to default codec
    //SetConsoleOutputCP ( consoleOutputCPstorage );
#pragma endregion

    //! ...................................:: References ::...................................
    // http://www.cplusplus.com/doc/
    // https://stackoverflow.com/
    // http://de.cppreference.com/
    // https://docs.microsoft.com/
    // https://www.ibm.com/support/knowledgecenter/en/
    // https://www.tutorialspoint.com/cplusplus/
    // C++ reference: http://www.cplusplus.com/reference/
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n", F_bRED );
    ColourCouter ( "References:\n", F_bWHITE );
    ColourCouter ( "http://www.cplusplus.com/doc/\n", F_YELLOW );
    ColourCouter ( "https://stackoverflow.com/\n", F_YELLOW );
    ColourCouter ( "http://de.cppreference.com/\n", F_YELLOW );
    ColourCouter ( "https://docs.microsoft.com/\n", F_YELLOW );
    ColourCouter ( "https://www.ibm.com/support/knowledgecenter/en/\n", F_YELLOW );
    ColourCouter ( "https://www.tutorialspoint.com/cplusplus/\n", F_YELLOW );
    ColourCouter ( "C++ reference: http://www.cplusplus.com/reference/\n", F_YELLOW );
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n", F_bRED );
    //! ...............................:: nerd Snow's sayings! ::...............................
    ColourCouter ( "Nerd snow's sayings!\n", F_bWHITE );
    ColourCouter ( "Programming needs patience and practical practice.\n", F_YELLOW );
    ColourCouter ( "Programming in a way, that no nerdy dog in the future is able to compile it, is to be avoided!\n", F_YELLOW );
    ColourCouter ( "I was almost a good nerd and emptied my Recycle Bin regularly at the night! :) So be a lamb (^.^) and stay a good nerd!\n", F_YELLOW );
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
    ColourCouter ( ".:: Introduction ::.\n", F_CYAN );

    _01_01_Introduction ();

    //! .................................:: BASICS OF C++ ::.................................
    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
    ColourCouter ( ".:: BASICS OF C++ ::.\n", F_CYAN );

    _02_01_StructureOfaProgram ();
    _03_01_VariablesTypesAndIdentifiers ();
    _03_02_FundamentalTypesAndDeduction ();
    _04_01_ConstantNumerals ();
    _04_02_ConstantLiterals ();
    _04_03_OtherConstantLiterals ();
    _05_01_ArithmeticOperators ();
    _05_02_LagicalOperators ();
    _05_03_OtherOperators ();
    _05_04_PrecedenceOfOperators ();
    _06_01_BasicInputOutput ();


    //! ...............................:: PROGRAM STRUCTURE ::...............................
    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
    ColourCouter ( ".:: PROGRAM STRUCTURE ::.\n", F_CYAN );

    _07_01_ControlStructures ();
    _07_02_SelectionStatements ();
    _07_03_IterationStatements ();
    _07_04_JumpStatements ();
    _07_05_AnotherSelectionStatement ();
    _08_01_Functions ();
    _08_02_VoidFunctions ();
    _08_03_MainFunctionReturnValue ();
    _08_04_PassedArgumentsTypes ();
    _08_05_Efficiency ();
    _08_06_InlineFunctions ();
    _08_07_ParametersDefaultValues ();
    _08_08_FunctionsDeclaration ();
    _08_09_Recursivity ();
    _09_01_OverloadsAndTemplates ();
    _09_02_OverloadedFunctions ();
    _09_03_FunctionTemplates ();
    _09_04_ParticularTypeTemplateArguments ();
    _10_01_NameVisibility ();
    _10_02_Scopes ();
    _10_03_Namespaces ();
    _10_04_UsingKeyword ();
    _10_05_NamespaceAliasing ();
    _10_06_StorageClasses ();

    //! ..............................:: COMPOUND DATA TYPES ::..............................
    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
    ColourCouter ( ".:: COMPOUND DATA TYPES ::.\n", F_CYAN );

    _11_01_Arrays ();
    _11_02_InitializingArrays ();
    _11_03_AccessingValues ();
    _11_04_MultidimensionalArrays ();
    _11_05_ArraysAsParameters ();
    _11_06_LibraryArrays ();
    _12_01_CharacterSequences ();
    _13_01_PointersBasics ();
    _13_02_PointersAndDataTypes ();
    _13_03_PointersAndLiterals ();
    _13_04_MoreOnPointers ();
    _13_05_PointersToFunctions ();
    _14_01_DynamicMemory ();
    _15_01_DataStructures ();
    _16_01_OtherDataTypes ();

    //! ....................................:: CLASSES ::....................................
    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
    ColourCouter ( ".:: CLASSES ::.\n", F_CYAN );

    _17_01_ClassesI ();
    _17_02_Constructors ();
    _17_03_UniformInitialization ();
    _17_04_MemberInitializationInConstructor ();
    _17_05_PointersToClasses ();
    _17_06_OverloadingOperators ();
    _17_07_TheKeywordThis ();
    _17_08_StaticMembers ();
    _17_09_ConstantMemberFunctions ();
    _17_10_ClassTemplates ();
    _17_11_TemplateSpecialization ();
    _18_01_SpecialMembers ();
    _18_02_DefaultConstructor ();
    _18_03_Destructor ();
    _18_04_CopyConstructor ();
    _18_05_CopyAssignment ();
    _18_06_MoveConstructorAndAssignment ();
    _18_07_ImplicitMembers ();
    _19_01_FriendshipAndInheritance ();
    _19_02_FriendFunctionsAndClasses ();
    _19_03_InheritanceBetweenClasses ();
    _19_04_InheritedCharacteristics ();
    _19_05_MultipleInheritance ();
    _20_01_Polymorphism ();
    _20_02_PointersToBaseClass ();
    _20_03_VirtualMembers ();
    _20_04_AbstractBaseClasses ();

    //! ....................................:: OTHER LANGUAGE FEATURES ::....................................
    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
    ColourCouter ( ".:: OTHER LANGUAGE FEATURES ::.\n", F_CYAN );

    _21_01_TypeConversions ();
    _21_02_ImplicitConversion ();
    _21_03_ImplicitConversionsWithClasses ();
    _21_04_KeywordExplicit ();
    _21_05_TypeCasting ();
    _21_06_DynamicCast ();
    _21_07_StaticCast ();
    _21_08_ReinterpretCast ();
    _21_09_ConstCast ();
    _21_10_TypeId ();
    _22_01_Exceptions ();
    _22_02_ExceptionSpecification ();
    _22_03_StandardExceptions ();
    _23_01_PreprocessorDirectives ();
    _23_02_MacroDefinitions ();
    _23_03_ConditionalInclusions ();
    _23_04_LineControl ();
    _23_05_ErrorDirective ();
    _23_06_SourceFileInclusion ();
    _23_07_PragmaDirective ();
    _23_08_PredefinedMacroNames ();
    _24_01_InputAndOutputWithFiles ();
    _24_02_OpeningAndClosingFiles ();
    _24_03_TextFiles ();
    _24_04_CheckingStateFlags ();
    _24_05_GetAndPutStreamPositioning ();
    _24_06_BinaryFiles ();
    _24_07_BuffersAndSynchronization ();
    _25_01_Extras ();


    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
  }
  catch ( const std::exception& )
  {

  }

  // preventing the instant closing of console window, so the result could be seen
  // not a good practice anyhow with a lot discussion in the internet
  // alternatives:
  // Ctrl+F5 is, which compile without debugging
  // putting a break point at the end of the function main
  system ( "PAUSE" ); // system dependent
  std::cin.get (); // alternative and portable
  // for advanced programmer: your program should be able to handle it itself

  //return 0;
  return EXIT_SUCCESS; // see the tutorials > functions section > the return value of main
}
