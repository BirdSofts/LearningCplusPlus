// --------------------------------------------------------------------------------
/// <summary>
/// _3_ProgramStructures.cpp
/// </summary>
/// <created>ʆϒʅ,09.05.2018</created>
/// <changed>ʆϒʅ,09.03.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "ConsoleAdjustments.h"


#define Tab '\t'
#define Nline '\n'

const char tab { '\t' };
const char nline { '\n' };


void _03_01_ControlStructures ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ control structures (statements and flow control):
        // apart from linear sequence of statements a program can contain repeated segments of code, decision taking and bifurcations.
        // generic (sub)statements required by most of the flow control statements in C++ as a part of their syntax are:
        // either simple statements ended with semicolon (;)
        // or a compound one which every single statement ends with its own semicolon (;) enclosed as a block in curly braces ({}). { statement1; statement2; ... }
        // the entire block composed of sub-statements is considered a single statement.
        ColourCouter ( "~~~~~ Control structures (Statements and flow control):\n", F_bBLUE );
        ColourCouter ( "A program can contain linear sequence of statements, repeated segments of code, decision taking and bifurcations.\n\n", F_YELLOW );
    }
    catch ( const std::exception& )
    {

    }
}


void _03_02_SelectionStatements ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ selection statements (if and else):
        // execution of a statement or block if the condition is fulfilled.
        //! keywords:   if  else

        // Note syntax: if (condition) statement
        ColourCouter ( "~~~~~ Selection statements (if and else):\n", F_bBLUE );
        ColourCouter ( "Can be used to introduce conditioned execution of statements.\n\n", F_YELLOW );
        int x { 99 };
        std::cout << "Current value of x is:" << tab << x << nline;
        if ( x == 80 )
            std::cout << "x is 80." << nline; // a statement
        // a block statement without usual indentation and line breaks:
        if ( x != 80 ) { std::cout << "x is "; std::cout << "greater than 80." << nline << nline; }

        // Note syntax: if (condition) statement1 else statement2
        // the introduced statement2 by 'else' keyword will be executed, when the condition is not fulfilled.
        x = 46;
        std::cout << "Current value of x is:" << tab << x << nline;
        if ( x == 80 )
            std::cout << "x is 80." << nline;
        else // introduction of an alternative statement
            std::cout << "x is not 80." << nline << nline;

        // concatenated several if + else structure
        // for example it can be introduced to fulfil the intention of checking a range of values
        x = -2;
        std::cout << "Current value of x is:" << tab << x << nline;
        if ( x > 0 )
            std::cout << "x is positive." << nline << nline;
        else if ( x < 0 ) // alternative statement is concatenated with another if-else structure
            std::cout << "x is negative." << nline << nline;
        else
            std::cout << "x is zero." << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _03_03_IterationStatements ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ iteration statements (loops):
        // repetition of statements a certain times or till a condition is fulfilled.
        //! keywords:   while   do  for
        ColourCouter ( "~~~~~ Iteration statements (Loops):\n", F_bBLUE );
        ColourCouter ( "To repeat statements a certain times or until a condition is fulfilled.\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- the while loop:
        // repeat the statement while the expression is true.
        // alteration of the value must somehow happen in the statement to avoid looping forever in while loops
        // Note syntax: while (expression) statement
        // the complexity of the loop in the example below is trivial for computer,
        // so it will be performed instantly without any practical delay
        ColourCouter ( "----- The while loop:\n", F_bBLUE );
        ColourCouter ( "While the expression is true, this loop continue to iterate.\n\n", F_YELLOW );
        std::cout << "Countdown example using a while loop:" << tab;
        int n { 10 };
        while ( n > 0 )
        {
            std::cout << n << ", ";
            --n; // alter the value checked in condition.
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );; // add delays to the countdown
        }
        std::cout << "lift-off!" << nline << nline;

        //! ####################################################################
        //! ----- the do-while loop:
        // the same behaviour like while loop but the condition will be checked after the execution of the statement.
        // either if the condition is fulfilled or not, at least one execution of the statement is guaranteed.
        // the use of do-while loop is preferred over the while loop,
        // especially when the to be checked condition is determined within the statement itself.
        // Note syntax: do statement while (condition);
        ColourCouter ( "----- The do-while loop:\n", F_bBLUE );
        ColourCouter ( "Same behaviour like while loop, but with guarantee of one time statement execution.\n\n", F_YELLOW );
        ColourCouter ( "Echoing the user inputted text with do-while loop.\n", F_bYELLOW );
        ColourCouter ( "Enter 'bye' to exit the loop.\n", F_bCYAN );
        std::string user_input;
        do
        {
            std::cout << "-- Enter something:" << tab;
            std::getline ( std::cin, user_input );
            std::cout << "You have entered:" << tab << user_input << nline << nline;
        } while ( user_input != "bye" );

        //! ####################################################################
        //! ----- the for loop:
        // iteration of the statement a certain number of times while its condition is true
        // the initialization expression executes before the loop begins and the increase expression after each iteration,
        // therefore this loop is most useful, when it comes to counter variables.
        // Note syntax: for (initialization; condition; increase) statement;
        ColourCouter ( "----- The for loop:\n", F_bBLUE );
        ColourCouter ( "To introduce loops that iterate a certain number of times.\n\n", F_YELLOW );
        std::cout << "Countdown example using a for loop:" << tab;
        for ( int n { 10 }; n > 0; n-- )
        {
            std::cout << n << ", ";
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );
        }
        std::cout << "lift-off!" << nline << nline;

        //! - in addition:
        // more on for loops plus some other features:
        // the tree fields in the for loop are optional but the semicolons between them in all cases are obligatory.
        //! for example: for (; n<10; ;) -equivalent to a while loop
        //! another example: for (; n<10; ++n;) -maybe the variable is initialized before
        // a loop with true as condition (no condition) is equivalent to an infinite loop
        // each field will be executed in a particular time in the life cycle of a loop.
        // these fields are expressions so they can use the comma operator, therefore a for loop can handle two counter variables at the same time.
        // Note expressions are not statements so they can't be replaced by a block.
        ColourCouter ( "Features of for loops: multiple expressions as fields:\n", F_bYELLOW );
        std::cout << nline << tab;
        for ( int i = 30, n = 0; n != i; n++, i -= 2 )
        {
            std::cout << "^-^" << tab; // times of execution is 10
        }
        std::cout << nline << nline;

        //! - in addition:
        // example of nested for loops:
        // Added to pattern: take note of repeated line and division in patterns
        //  *   *  
        //   * *   
        //    *      * 9 times
        //    *    
        //   * *   
        //  *   *  
        ColourCouter ( "Demonstration of a pattern using nested for loops:\n", F_bYELLOW );
        bool flag { false };
        for ( int i = 1; i <= 5; i++ )
        {
            if ( i == 4 && flag == false ) { i = 3; flag = true; } // repeat a line
            for ( int j = 1; j < 54; j++ )
            {
                if ( ( i == ( j % 6 ) ) || ( ( ( i - 1 ) + ( j % 6 ) ) == 5 ) ) // 6 to divide the patterns (try 5 too)
                    ColourCouter ( "*", F_bBLUE );
                else
                    std::cout << ' ';
            }
            std::cout << nline;
        }
        std::cout << nline;

        //! ####################################################################
        //! ----- range-based for loops: iteration over all the elements in a range
        // Note syntax: for (declaration : range) statement;
        // declaration declares a variable of a type which is able to take values of an element in the range.
        // ranges are sequences of elements including arrays, containers and any other type supporting the functions begin and end.
        // none of these types is mentioned yet, therefore stings will be used which are sequences of character.
        // this kind of loop is automatic and doesn't require the explicit declaration of counter variable.
        ColourCouter ( "----- Rang-based for loops:\n", F_bBLUE );
        ColourCouter ( "Iteration over all the elements in a range.\n\n", F_YELLOW );
        std::string for_range { "SequenceOfCharacters" };
        std::cout << "The stored string in the variable is:" << tab << for_range << nline;
        for ( char c : for_range )
        {
            std::cout << "-" << c << " "; // representing the value of each element in the range using the variable c
        }
        std::cout << nline << nline;
        // using type deduction (auto):
        // to automatically deduct the type of elements in a range
        ColourCouter ( "Type deduction in range-based for loops:\n", F_bYELLOW );
        for ( auto c : for_range )
        {
            std::cout << "-" << c << " ";
        }
        std::cout << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _03_04_JumpStatements ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ jump statements:
        // they can be used to alter the flow of a program by jumping to specific locations
        ColourCouter ( "~~~~~ Jump statements:\n", F_bBLUE );
        ColourCouter ( "The flow of a program can be altered by jumping to specific locations.\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- the break statement:
        // to leave a loop, even if its end condition isn't fulfilled.
        // purposes: to end an infinite loop, to leave a loop before its natural end
        ColourCouter ( "----- The break statement:\n", F_bBLUE );
        ColourCouter ( "To leave a loop before its natural end.\n\n", F_YELLOW );
        std::cout << "Countdown example and breaking its loop:" << tab;
        for ( int n { 10 }; n > 0; n-- )
        {
            std::cout << n << ", ";
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );
            if ( n == 3 )
            {
                std::cout << "Countdown aborted!" << nline << nline;
                break;
            }
        }

        //! ####################################################################
        //! ----- the continue statement:
        // to skip the current iteration and jumping to the next one.
        ColourCouter ( "----- The continue statement:\n", F_bBLUE );
        ColourCouter ( "To introduce skipping the iterations of a loop.\n\n", F_YELLOW );
        std::cout << "Skipping some of iterations in countdown example with for loop:" << nline << "--\t";
        for ( int n { 10 }; n > 0; n-- )
        {
            if ( n == 8 || n == 5 || n == 2 )
            {
                continue;
            }
            std::cout << n << ", ";
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );
        }
        std::cout << "The steps 8, 5 and 2 are skipped!" << nline << nline;

        //! ####################################################################
        //! ----- the goto statement: provides absolute jump to another point in the program
        // this jump is an unconditional jump, ignores the nesting levels and doesn't cause any automatic stack unwinding,
        // therefore it is to be used with care, preferably within the same block and especially in the presence of local variables.
        // defined labels which are valid identifier followed by colon (:), are destinations point and will be used as argument for goto statement.
        // goto is deemed a low-level feature with no particular use in modern higher-level C++ programming paradigms.
        ColourCouter ( "----- The goto statement:\n", F_bBLUE );
        ColourCouter ( "To introduce absolute and unconditional jump to another point in the program.\n\n", F_YELLOW );
        std::cout << "Countdown example using goto statement:" << "\t\t";
        int n2 { 10 };
    a_loop_with_goto:
        std::cout << n2 << ", ";
        --n2;
        std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );
        if ( n2 > 0 ) goto a_loop_with_goto;
        std::cout << "lift-off!" << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _03_05_AnotherSelectionStatement ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ another selection statement (switch):
        // to compare the evaluated expression against labels that are constant expressions.
        // it is like concatenations of 'if' and 'else if' statements but limited to constant expressions.
        // it is not possible to use variables or ranges as labels since they aren't valid C++ constant expressions, therefore it is better to use 'if' for ranges and values that aren't constant.
        // after evaluating the expression and finding the equivalent constant, its break statement causes the end of the switch.
        // if the evaluation value isn't match to any of the constants, the default case and its group of statement when it is existed, will be executed since it is optional, .
        // Note syntax: (type 'switch' and press tab key twice)
        // switch (expression)
        // {
        //  case constant1:
        //      group_of_statement1;
        //      break;
        //  .
        //  .
        //  default:
        //      group_of_default_statement;
        //      break;
        // }
        ColourCouter ( "~~~~~ Another selection statement (switch):\n", F_bBLUE );
        ColourCouter ( "Switching and checking for a value among the possible constant expressions.\n\n", F_YELLOW );
        int x2 { 1 };
        switch ( x2 )
        {
            case 1:
                std::cout << "The value of variable is one" << nline << nline;
                break;
            case 2:
                std::cout << "The value of variable is two" << nline << nline;
                break;
            default:
                std::cout << "The value of variable is not among the cases" << nline << nline;
                break;
        }

        //! - in addition:
        // the syntax of switch is inherited from the early versions of C language. switch uses labels in place of blocks.
        // the break statement for each case is needed, otherwise switch executes all the statements after the equivalent case till the end or reaching a break no matter what case they belong to.
        // this makes enclosing a group statement in braces unnecessary,
        // and can be useful for execution of same group of statement for more than one case.
        ColourCouter ( "Execution of same group of statement for more than one case.\n", F_bYELLOW );
        switch ( x2 )
        {
            case 1:
            case 2:
            case 3:
                std::cout << "The value of variable is either one, two or tree" << nline << nline;
                break;
            default:
                std::cout << "The value of variable is not one, two nor tree" << nline << nline;
                break;
        }
    }
    catch ( const std::exception& )
    {

    }
}


int addition ( int a, int b )
{
    int r; r = a + b; return r;
}
int subtraction ( int a, int b )
{
    int r; r = a - b; return r;
}
void _04_01_Functions ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ functions:
        // a group of code that is given a name to structure a program in segment of code to perform individual tasks,
        // which can be called from some points of the program.
        // Note most common syntax: type name (parameter1, ...) {statements}
        // the parenthesis which differentiate functions from other kind of declarations or statements are always required no matter declaring or calling a function.
        // parameters which allow passing arguments to the function act like local variables within the functions.
        // the expression that calls a function, will be evaluated as the returned value by the function.
        // all the functions that have defined return type in their definitions must return a value with a proper return statement that includes a return value, even if this value is never going to be used.
        // a function can be called multiple times and its parameter aren't limited to literals.
        ColourCouter ( "~~~~~ Functions:\n", F_bBLUE );
        ColourCouter ( "To introduce structures that can be used to perform individual tasks in segment of code.\n\n", F_YELLOW );
        int result;
        ColourCouter ( "Two function to perform addition and subtraction operations:\n", F_bYELLOW );
        std::cout << "Passed literal values as parameters to be added:\t" << "2 and 7" << nline;
        result = addition ( 2, 7 ); // passing literals
        std::cout << "The result of addition function:" << "\t\t\t" << result << nline;
        std::cout << "Result of function without any additional variable:" << tab << addition ( 2, 7 ) << nline << nline; // direct function calling in insertion stream
        int x { 4 }; int y { 3 };
        std::cout << "Passed variables as parameters to be subtracted:" << tab << "x = " << x << tab << "y = " << y << nline;
        result = subtraction ( x, y ); // passing variables
        std::cout << "The result of subtraction function:" << "\t\t\t" << result << nline << nline;

        ColourCouter ( "Subtraction function called as an operand of addition operation:\n", F_bYELLOW );
        std::cout << "So the expression is: \t\t subtraction ( x, y ) + 6:" << nline;
        std::cout << "Passed variables as parameters to be subtracted:" << tab << "x = " << x << tab << "y = " << y << nline;
        result = 6 + subtraction ( x, y ); // the function call is operand of addition operation.
        result = subtraction ( x, y ) + 6; // same as above: commutative property of addition operation
        std::cout << "The result of both expressions is:" << "\t\t\t" << result << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void print_message ( void )
{
    std::cout << "\t\t Hi, I'm a Function. ^_^ \n\n";
}
void _04_02_VoidFunctions ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- functions with no type (the use of void):
        // if the function doesn't need to return a value it shall be defined as a void function.
        // the void type is an spacial type to represent the absence of value.
        // void keyword can also be used in function's parameter list to explicitly specify that the function takes no actual parameters
        // void keyword in parameter's list: in C++ optional, in C language required
        ColourCouter ( "----- Functions with no type (The use of void):\n", F_bBLUE );
        ColourCouter ( "Void functions are those that don't have any returned value.\n\n", F_YELLOW );
        std::cout << "Following message is inserted by calling a void function with no parameters:" << nline << nline;
        print_message ();
    }
    catch ( const std::exception& )
    {

    }
}


void _04_03_MainFunctionReturnValue ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- the return value of main function:
        // the type of return value of main is int.
        // if the execution of main ends normally without encountering the return statement,
        // the compiler assumes that the function has ended with an implicit return statement.
        // this only applies to the main function for historical reasons.
        //! return statement: return 0;
        // the returned zero value either implicitly or explicitly will be interpreted by the environment that the program ended successfully.
        // returning other values are possible and some environment give access to them to the caller in some way,
        // although this behaviour is not required nor necessarily portable between platforms.
        // Note in some way guaranteed interpretable values on all platforms are:
        // ----------------------------------------------------------------------
        // 0                the program was successful
        // ----------------------------------------------------------------------
        // EXIT_SUCCESS     the program was successful (the header is <cstdlib>)
        // ----------------------------------------------------------------------
        // EXIT_FAILURE     the program failed (the header is <cstdlib>)
        // ----------------------------------------------------------------------
        // Note some authors consider the explicitly written return statement a good practice,
        // thus the implicit return statement for main function is a tricky exception.
        ColourCouter ( "----- The return value of main function:\n", F_bBLUE );
        ColourCouter ( "The return value of the main function which is of type int has his own peculiarity.\n\n", F_YELLOW );
        ColourCouter ( "Read the comments in the source code...\n\n", F_bYELLOW );
    }
    catch ( const std::exception& )
    {

    }
}


// ampersand signs '&' indicate, that the arguments are passed as reference
void duplication ( int& a, int& b, int& c )
{
    a *= 2, b *= 2, c *= 2;
}
void _04_04_PassedArgumentsTypes ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- arguments passed by value and by reference:
        //? by value:
        // the values of arguments will be passed to function on the moment of the call, that is:
        // the values will be copied into the variables represented by function parameters.
        // the values of passed arguments will be used to initial the function parameters,
        // thus the modification of them in function doesn't have any effect on the variables outside of it.
        ColourCouter ( "----- Arguments passed by value and by reference:\n", F_bBLUE );
        ColourCouter ( "The Arguments can be passed to a function by value and by reference.\n\n", F_YELLOW );
        int x { 3 }; int y { 4 };
        int result { 0 };
        ColourCouter ( "Passing arguments by value:\n", F_bYELLOW );
        std::cout << "The passed arguments are:" << "\t\t" << "x = " << x << tab << "y = " << y << nline;
        result = addition ( x, y );
        std::cout << "Result of addition function:" << "\t\t" << result << nline << nline;
        //? by reference:
        // to make access to variables outside of function passible.
        // to actually modify the value of variables used as arguments to call a function, arguments need to be passed by reference.
        // to gain access to arguments, the function defines its parameters as reference.
        // in C++ language, references are indicated by the ampersand sign '&' following the parameter type.
        // what is passed is the variable itself,
        // so somehow the association happens between the passed arguments and the parameters of the function to the extent,
        // that the modification of arguments on their corresponding local variables within function becomes possible,
        // and in the end its reflection is on the variables passed as arguments.
        ColourCouter ( "Passing arguments by reference:\n", F_bYELLOW );
        x = 2, y = 3;
        int z { 4 };
        std::cout << "The passed arguments are:" << "\t\t" << "x = " << x << tab << "y = " << y << tab << "z = " << z << nline;
        duplication ( x, y, z );
        std::cout << "Result of duplication function:" << "\t\t" << "x = " << x << tab << "y = " << y << tab << "z = " << z << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


std::string concatenate ( std::string& a, std::string& b )
{
    return a + b;
}
// constant arguments passed as reference
std::string constant_concatenate ( const std::string& a, const std::string& b )
{
    return a + b;
}
void _04_05_Efficiency ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- efficiency consideration and constant reference:
        // passing arguments by value causes the arguments to be copied which it may be relatively inexpensive for fundamental types like int,
        // but in compound type it may result in certain overhead and copying large quantities of data just for function call.
        // for this unneeded copy to be avoided, calling functions by reference is suggested and with it,
        // the function operates directly on aliases of passed arguments and at utter most, it might mean the transfer of certain pointer to the function.
        ColourCouter ( "----- Efficiency consideration and constant reference:\n", F_bBLUE );
        ColourCouter ( "Passing arguments by reference to avoid certain overhead.\n\n", F_YELLOW );
        std::string a, b, c;
        std::cout << "Enter two long string to be concatenated:" << nline;
        std::cout << "- The first one is:" << "\t\t";
        std::getline ( std::cin, a );
        std::cout << "- And the second one is:" << tab;
        std::getline ( std::cin, b );
        c = concatenate ( a, b );
        std::cout << nline << "The concatenated result is:" << tab << c << nline << nline;

        //! - in addition:
        // functions with reference parameters are generally perceived as functions that modify the arguments passed.
        // by qualifying the parameters as constant, it can be guaranteed that the function doesn't modify the arguments 
        ColourCouter ( "The use of constant parameters in passing arguments by reference:\n", F_bYELLOW );
        std::cout << "Above entered strings will be used:" << nline << nline;
        c = constant_concatenate ( a, b );
        std::cout << "The concatenated result is:" << tab << c << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


inline std::string inline_constant_concatenate ( const std::string& a, const std::string& b )
{
    return a + b;
}
void _04_06_InlineFunctions ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- inline functions:
        // since calling a function has a certain overhead (stacking arguments, jumps etc...) it isn't efficient for short functions.
        // by using inline specifier in the function declaration the compiler will be suggested that inline expansion is preferred over the usual function call mechanism.
        // behaviour of a function won't be changed but the function body will be inserted at each point of the function call, so the regular invocation will be avoided.
        ColourCouter ( "----- Inline functions:\n", F_bBLUE );
        ColourCouter ( "To introduce the inline expansion of a function body and replace the regular invocation with it.\n\n", F_YELLOW );
        ColourCouter ( "Concatenate function with inline specifier declaration:\n", F_bYELLOW );
        std::string a { "AAA" }, b { "BBB" }, c { "" };
        std::cout << "The strings to be concatenated are:" << tab << a << tab << b << nline;
        c = inline_constant_concatenate ( a, b );
        std::cout << "The concatenated result is:" << "\t\t" << c << nline << nline;
        // note that in C++ the optimization task is delegated to the compiler.
        // most compiler already optimize code to generate inline functions whenever there is an opportunity, even not explicitly marked with inline specifier.
        // Therefore using it in the declaration of a function is merely a suggestion and the compiler is free to not inline it and optimize otherwise, as long as the resulting behaviour is the one specified by the code.
    }
    catch ( const std::exception& )
    {

    }
}


// a default value in function's declaration (optional parameters)
int divide ( int a, int b = 2 )
{
    int r; r = a / b; return r;
}
void _04_07_ParametersDefaultValues ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- default values in parameters:
        // optional parameters in C++ functions that doesn't require any arguments in the call shall have default values in the definition,
        // which will be used when a function is needed to be called with fewer arguments.
        ColourCouter ( "----- Default values in Parameters:\n", F_bBLUE );
        ColourCouter ( "To declare functions with optional parameters.\n\n", F_YELLOW );
        std::cout << "Two call to divide function with two parameters of which the last one is optional:" << nline;
        int result;
        result = divide ( 12 );
        std::cout << "-- divide (12):" << "\t\t" << result << nline;
        result = divide ( 20, 4 ); // optional parameter is used in the call, therefore the default value will be ignored
        std::cout << "-- divide (20, 4):" << tab << result << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void odd ( int x ); // function prototype
void even ( int x ); // the same
void _04_08_FunctionsDeclaration ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- declaring functions:
        // in C++ language, like identifiers, functions can not be used before declaration.
        // in any case, at least the prototype of a function needs to be declared before any call to the function,
        // which gives enough details about the types involved (return and parameters) in the function definition (function body).
        // prototype syntax is like the one of a function's declaration without any body code which ends with semicolon.
        // name of parameters are optional in the declaration, this means they can be mentioned or not,
        // and when mentioned, not matching to the declaration of the function itself is also possible.
        //? so two possible syntaxes are:
        // Note int proto_function (int first, int second);
        // Note int proto_function (int, int);
        // name inclusion always improves the legibility of the declaration anyhow.
        // the purposes of declaring functions before their actual definition:
        // the order of functions becomes recognizable.
        // possibility to call another function from within the already called function. (example below)
        ColourCouter ( "----- Declaring functions:\n", F_bBLUE );
        ColourCouter ( "To introduce the declaration of a function and place its definition elsewhere.\n\n", F_YELLOW );
        ColourCouter ( "Working with the functions odd and even:\n", F_bYELLOW );
        int number;
        do
        {
            std::cout << "Please enter a number (enter zero to exit):" << tab;
            std::cin >> number;
            if ( number == 0 ) { std::cout << nline; break; }
            odd ( number );
        } while ( number != 0 );
    }
    catch ( const std::exception& )
    {

    }
}
void odd ( int x )
{
    if ( ( x % 2 ) != 0 ) std::cout << "The entered number is odd.\n\n";
    else even ( x );
}
void even ( int x )
{
    if ( ( x % 2 ) == 0 ) std::cout << "The entered number is even.\n\n";
    else odd ( x );
}


long factorial ( long a )
{
    if ( a > 1 )
        return ( a*factorial ( a - 1 ) );
    else
        return 1;
}
void _04_09_Recursivity ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- recursivity:
        // the property with which functions can call themselves.
        // usual for some task like sorting elements or factorial (n!)
        ColourCouter ( "----- Recursivity:\n", F_bBLUE );
        ColourCouter ( "The call that a function can make to itself.\n\n", F_YELLOW );
        std::cout << "A recursive function to calculate factorial:" << nline;
        long number2 { 9 };
        std::cout << "-- " << number2 << "! =" << tab << factorial ( number2 ) << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _05_01_OverloadsAndTemplates ()
{
    // the body code of functions used in this section are defined above it
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ overloads and templates:
        ColourCouter ( "~~~~~ Overloads and templates:\n", F_bBLUE );
        ColourCouter ( "-- Overloads are two or more functions with the same name.\n", F_YELLOW );
        ColourCouter ( "-- Defining a function with generic type is known as function template.\n\n", F_YELLOW );
    }
    catch ( const std::exception& )
    {

    }
}


int operate ( int a, int b )
{
    return ( a + b );
}
// different declaration and definition
double operate ( double a, double b )
{
    return ( a / b );
}
void _05_02_OverloadedFunctions ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- overloaded functions:
        // in C++, two or more different functions can have the same name if their parameters are different (number, type).
        // it isn't enough to have different return type to overload a function, hence at least one parameter must be different.
        // by examining the type of the passed arguments the compiler distinguish which overload of a function shall be called.
        // the example below is not generally a good idea to demonstrate overloads of a function, since similar behaviour of overloads is expected,
        // on the other hand it shows the possibility that the overloads can be fully different.
        // the functions in this example have entirely different behaviours, declarations and definitions and the only similarity is their name.
        ColourCouter ( "----- Overloaded functions:\n", F_bBLUE );
        ColourCouter ( "C++ ability to define multiple instances of a function.\n\n", F_YELLOW );
        ColourCouter ( "Operations addition and division performed by overloads of the function operate:\n", F_bYELLOW );
        int x { 2 }, y { 3 };
        double n { 2.4 }, m { 3.7 };
        std::cout << "x = " << x << tab << "y = " << y << nline;
        std::cout << "Result of overload addition is:" << tab << operate ( x, y ) << nline;
        std::cout << "n = " << n << tab << "m = " << m << nline;
        std::cout << "Result of overload division is:" << tab << operate ( n, m ) << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


int sum ( int a, int b )
{
    return ( a + b );
}
// different declaration with same definition
double sum ( double a, double b )
{
    return ( a + b );
}
// a generic sum function. the appropriate version of function will be instantiated and called by compiler each time.
template <class SomeType>
SomeType sum2 ( SomeType a, SomeType b )
{
    SomeType result;
    result = ( a + b );
    return result;
}
// multiple template parameters
template <class T, class U>
bool equality_check ( T a, U b )
{
    return ( a == b );
}
void _05_03_FunctionTemplates ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- function templates:
        // a function (the function sum for example) could be overloaded for many types and all of them having the same body or definition.
        ColourCouter ( "----- Function templates:\n", F_bBLUE );
        ColourCouter ( "The ability of C++ to define generic functions known as function templates.\n\n", F_YELLOW );
        ColourCouter ( "A function could be overloaded for different types while all of them having the same definition:\n", F_bYELLOW );
        std::cout << "Sum of 10 and 20 (overload for int type):" << tab << sum ( 10, 20 ) << nline;
        std::cout << "Sum of 1.2 and 1.5 (overload for double type):" << tab << sum ( 1.2, 1.5 ) << nline << nline;
        // for such a case (above),
        // C++ has the ability to define generic functions known as function templates.
        // Note syntax: template <template-parameters> function-declaration
        // it is like regular function, preceded with template keyword and a series of template parameters enclosed in angle-brackets <> and separated with comma
        // the template parameters can be generic template types by specifying either the class or typename keyword (both are 100% synonym in template declaration) followed by an identifier.
        // this identifier can then be used in the function definition like regular types. (see generic function sum2)
        // no matter how a generic type would be used (parameter, return or variable), it will be determined on the moment the template is instantiated.
        // a template can be instantiated by applying it to create a function using particular types or values for its template parameters.
        // the instantiation will be done when a template function called.
        // call statement syntax is like function but the template arguments, enclosed in angle-brackets shall to be specified.
        // Note syntax: name <tamplate-arguments> (function-arguments)
        ColourCouter ( "Multiple instances of a function (the use of generic function or function template):\n", F_bYELLOW );
        int result1;
        result1 = sum2<int> ( 10, 20 ); // using int type to make an instance
        std::cout << "Result of the instance for int type:" << "\t\t" << result1 << nline;
        double result2;
        result2 = sum2<double> ( 1.2, 1.5 ); // making another instance with double type
        std::cout << "Result of another instance for double type:" << tab << result2 << nline << nline;

        //! - in addition:
        // since the generic type SomeType is also used as parameters of the function, the compiler is able to deduce the data type automatically.
        // therefore there is no need to explicitly specify the type within angle-brackets when calling the function.
        // for this, the type shall be unambiguous so the compiler could perform the deduction.
        // if the function is called with arguments of different types, the compiler may not be able to deduct the type of the generic type.
        // take the following call for instance:
        ColourCouter ( "Instantiating another instance while using deduction of type:\n", F_bYELLOW );
        long long result3;
        result3 = sum2 ( 21355479374, 21370547592 ); // type deduction in generic types
        std::cout << "Result of another instance (deduction for type long long):" << tab << result3 << nline << nline;

        //! - in addition:
        // templates are a powerful and versatile feature.
        // while they can have multiple template parameters, it is still possible for the function to use regular non-templated types.
        // since numerical literals are always of a specific type, unless otherwise specified with a suffix.
        // this means integer literals always produce values of type int and floating-point literals always produce values of type double.
        // so there is no ambiguity possible in the example below.
        ColourCouter ( "Multiple template parameters plus using non-templated types:\n", F_bYELLOW );
        if ( equality_check ( 10, 10.0 ) ) // the use of regular non-template type
                                           // automatic template parameter deduction
            std::cout << "The numbers 10 and 10.0 are equal" << nline << nline;
        else
            std::cout << "The numbers 10 and 10.0 are not equal" << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


// non-type template arguments: expressions of particular type
template <class T, int N>
T fixed_multiply ( T val )
{
    return val * N;
}
void _05_04_NonTypeTemplateArguments ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- non-type template arguments:
        // the template parameter can also include expression of a particular type additionally to types introduced with class and typename.
        // when a particular type is used, the parameter looks like regular function parameter and can actually be used just like one.
        // the major difference:
        // since template parameter's values are compile-time-determined, so different instantiations could be generated,
        // the values of arguments of particular types are never passed during runtime.
        // this means that every call to such a template generates a different version of the function template,
        // therefore the values of argument of particular types need to be constant expressions and the template can not be instantiated with variables.
        ColourCouter ( "----- Non-type template arguments:\n", F_bBLUE );
        ColourCouter ( "To include expression of particular types in the template parameter.\n\n", F_YELLOW );
        ColourCouter ( "A function template and its second template parameter of particular type int:\n", F_bYELLOW );
        int result4;
        result4 = fixed_multiply<int, 2> ( 10 );
        std::cout << "First instance (always multiply with 2):" << tab << result4 << nline;
        result4 = fixed_multiply<int, 3> ( 10 );
        std::cout << "Second instance (always multiply with 3):" << tab << result4 << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _06_01_NameVisibility ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ name visibility:
        // in C++ name entities such as variables, functions and compound types need to be declared before being used.
        // the point where this declaration happens hat influence on its visibility.
        ColourCouter ( "~~~~~ Name Visibility\n", F_bBLUE );
        ColourCouter ( "The visibility of name entities such as variables, functions and compound types can be different after declaration.\n", F_YELLOW );
        ColourCouter ( "The point where an entity is declared, influences its visibility.\n\n", F_YELLOW );
    }
    catch ( const std::exception& )
    {

    }
}


int global_variable { 22 }; // global scope from this point of code (not in other .cpp files)
int first_function ()
{
    int local_variable; // local scope within this block
    local_variable = 0;
    return local_variable;
}
int second_function ()
{
    global_variable = 1;
    int local_variable; // no redefinition (another local variable)
    local_variable = 2;
    return local_variable;
}
void _06_02_Scopes ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- scopes:
        // global scope: the entity is defined outside all blocks and is visible to them all.
        // Note real global scope in all translation units (i.e. files of source code):
        // -------- definition with 'extern' keyword in pch.h or whichever file that is foreseen for pre-compiled header,
        // -------- then its initialization in one of the translation units
        // Note another global scope in all translation units:
        // -------- definition inside pch.cpp or whichever file that is foreseen for pre-compiled header,
        // local scope: the entity is defined inside a block and is visible inside of it.
        // a name can represents only one entity, therefore two variables can't have same name within the same scope.
        ColourCouter ( "----- Scopes:\n", F_bBLUE );
        ColourCouter ( "The scope of every entity is dependent on the point of its declaration.\n\n", F_YELLOW );
        std::cout << "Global variable's value:" << "\t\t\t\t" << global_variable << nline;
        std::cout << "Local variable's value (first function scope):" << "\t\t" << first_function () << nline;
        std::cout << "Local variable's value (second function scope):" << "\t\t" << second_function () << nline;
        std::cout << "Global variable's value after change:" << "\t\t\t" << global_variable << nline << nline;

        //! - in addition:
        // the visibility of an entity with block scope extends until the end of the block including its inner blocks.
        // nevertheless, re-utilization of an outer block defined name in the inner blocks is possible.
        // this re-utilization hides the outer block entity name in the inner block and refers to a different entity.
        // declarations that introduce a block such as functions, for, if etc... are local to the block they introduce.
        ColourCouter ( "Inner blocks and their scopes:\n", F_bYELLOW );
        int x { 10 };
        int y { 20 };
        std::cout << "Inserted from outer block:" << nline;
        std::cout << tab << "The initialized value of x:" << tab << x << nline;
        std::cout << tab << "The initialized value of y:" << tab << y << nline << nline;
        {
            int x; // OK, inner scope.
            x = 30; // assigns a value to the inner block x variable; outer block x variable is hidden.
            y = 30; // assigns a value to the outer block y variable; outer block y variable is not hidden.
            std::cout << "Inserted from inner block:" << nline;
            std::cout << tab << "x (the inner block x entity):" << tab << x << nline;
            std::cout << tab << "y (the outer block y entity):" << tab << y << nline << nline;
        }
        std::cout << "Inserted from outer block:" << nline;
        std::cout << tab << "x (the outer block x entity) :" << tab << x << nline;
        std::cout << tab << "y (the outer block y entity) :" << tab << y << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


namespace firstNamespace
{
    int a { 2 };
    int b { 3 };
    int value () { return ( a * b ); }
}
namespace secondNamespace
{
    double pi { 3.1416 };
    double value () { return ( 2 * pi ); }
}
// namespaces can be split
namespace firstNamespace
{
    int c { 4 };
    int d { 5 };
}
void _06_03_Namespaces ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- namespaces:
        // organization of named entities with global scope into narrower namespace scope to avoid name collision
        // only one entity can exist with a particular name in a particular scope, which for local names is seldom a problem, since the blocks tend to be relatively short.
        // non-local names bring more possibilities for name collision, considering the number of functions, types and variables declared by libraries, neither of them local in the nature and some of them very generic.
        // namespaces allow the introduction of different logical scopes referred to by names to organize the elements of program.
        // syntax: namespace identifier { name-entities }
        // the elements of namespaces can be accessed normally with their own identifier from within their scope.
        // the elements of namespaces have to be properly qualified with the scope operator (::) and the identifier of their namespace to be reached from outside.
        // namespaces can be split: first segment of a code can be extended to the second segment in the same namespace
        // namespaces can even get extend across different translation units (i.e.: across different files of source code)
        ColourCouter ( "----- Namespaces:\n", F_bBLUE );
        ColourCouter ( "To introduce the organization of named entities with global scope into narrower namespaces scope.\n\n", F_YELLOW );
        std::cout << "The elements of first namespace before change:" << nline;
        std::cout << tab << "a: " << firstNamespace::a << "\t\t" << "b: " << firstNamespace::b << nline;
        firstNamespace::a = 55; // an element of namespace, accessed from outside
        firstNamespace::b = 66; // the same
        std::cout << "The elements of first namespace after change:" << nline;
        std::cout << tab << "a: " << firstNamespace::a << "\t\t" << "b: " << firstNamespace::b << nline << nline;
        ColourCouter ( "Two function with the same name defined in two namespaces:\n", F_bYELLOW );
        std::cout << "Result of the function (first namespace):" << tab << firstNamespace::value () << nline;
        std::cout << "Result of the function (second namespace):" << tab << secondNamespace::value () << nline;
        std::cout << "Defined pi variable (second namespace):" << "\t\t" << secondNamespace::pi << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


namespace first
{
    int xx { 5 };
    int yy { 10 };
}
namespace second
{
    double xx { 3.1416 };
    double yy { 2.7183 };
}
void _06_04_UsingKeyword ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- the using keyword:
        // to introduce a name into the current declarative region (such as a block), to avoid name qualification need.
        ColourCouter ( "----- The using keyword:\n", F_bBLUE );
        ColourCouter ( "To avoid the need to qualify a name in the current declarative region.\n\n", F_YELLOW );
        ColourCouter ( "Accessing variables in the first and second namespace with and without qualification:\n", F_bYELLOW );
        {
            using first::xx; // avoid the need of name qualifier
            using second::yy; // the same
            std::cout << "No need to qualify the name:" << nline;
            std::cout << tab << "The value of xx (first namespace):" << tab << xx << nline;
            std::cout << tab << "The value of yy (second namespace):" << tab << yy << nline;
            std::cout << "Need to qualify the name:" << nline;
            std::cout << tab << "The value of xx (second namespace):" << tab << second::xx << nline;
            std::cout << tab << "The value of yy (first namespace):" << tab << first::yy << nline << nline;
        }

        // using as a directive to introduce an entire namespace:
        // using and using namespace stated in a block, have only validity within inside of it,
        // and when stated directly in the global scope, inside of the entire source code,
        // therefore the possibility is there to split the code in different blocks and use the objects of different namespaces.
        ColourCouter ( "Introducing an entire namespace by the keyword 'using' as a directive:\n", F_bYELLOW );
        {
            using namespace first;
            std::cout << tab << "The value of xx (first namespace):" << tab << xx << nline;
            std::cout << tab << "The value of yy (first namespace):" << tab << yy << nline;
            std::cout << tab << "The value of xx (second namespace):" << tab << second::xx << nline;
            std::cout << tab << "The value of yy (second namespace):" << tab << second::yy << nline << nline;
        }
        ColourCouter ( "Splitting the code in different blocks and using different namespaces:\n", F_bYELLOW );
        {
            using namespace first;
            std::cout << "The value of xx (first block - first namespace):" << tab << xx << nline;
        }
        {
            using namespace second;
            std::cout << "The value of xx (second block - second namespace):" << tab << xx << nline << nline;
        }
    }
    catch ( const std::exception& )
    {

    }
}


namespace third
{
    int xx { 5 };
    int yy { 10 };
}
void _06_05_NamespaceAliasing ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- : namespace aliasing
        // existing namespaces can be aliased with new names
        // Note syntax: namespace new_name = current_name;
        ColourCouter ( "----- Namespace aliasing:\n", F_bBLUE );
        ColourCouter ( "New names can be used as alias to have a different name for a defined namespace in a project.\n\n", F_YELLOW );
        ColourCouter ( "Using the alias of the namespace 'third':\n", F_bYELLOW );
        namespace firstNewName = third;
        {
            using namespace firstNewName;
            std::cout << "The value of xx (third namespace):" << tab << xx << nline << nline;
        }

        //! ####################################################################
        //! ----- : the std namespace
        // entities declared in this namespace belong to the standard C++ library.
        // using this namespace with the keyword 'using' facilitate comprehension and shorten the length of the code
        // on the other hand, to avoid name collision, most programmers tend to prefer explicit qualification for projects mixing libraries.
        ColourCouter ( "----- The std namespace:\n", F_bBLUE );
        ColourCouter ( "All the entities of the standard C++ library is declared within the namespace 'std'.\n\n", F_YELLOW );
    }
    catch ( const std::exception& )
    {

    }
}


int aGlobalVariable; // static storage, is automatic initialized
void _06_06_StorageClasses ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- storage classes:
        //# static storage: variables with global or namespace scope
        // their storage is allocated for the entire duration of the program
        // if they aren't explicitly initialized, they will be initialized automatically with zeroes
        //# automatic storage: local variables
        // their storage is only available during their declaration block
        // if they aren't explicitly initialized, they will be left uninitialized, and thus have undetermined values
        ColourCouter ( "----- Storage classes:\n", F_bBLUE );
        ColourCouter ( "The difference between static and automatic storage.\n\n", F_YELLOW );
        int aLocalVariable; // automatic storage, not automatically initialized, can't be used without initialization
        int anotherLocalVariable { 235 }; // automatic storage, explicitly initialized
        std::cout << "Value of a global variable (static storage, uninitialized):" << tab << aGlobalVariable << nline;
        // std::cout << aLocalVariable; // not valid, uninitialized
        std::cout << "Value of a local variable (automatic storage, initialized):" << tab << anotherLocalVariable << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}