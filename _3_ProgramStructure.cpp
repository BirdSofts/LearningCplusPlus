// --------------------------------------------------------------------------------
/// <summary>
/// _3_ProgramStructures.cpp
/// </summary>
/// <created>ʆϒʅ,09.05.2018</created>
/// <changed>ʆϒʅ,24.01.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "ConsoleAdjustments.h"


#define Tab '\t'
#define Nline '\n'


// ********************************************************************************
/// <summary>
/// Control structures in C++
/// </summary>
/// <created>ʆϒʅ,09.05.2018</created>
/// <changed>ʆϒʅ,15.05.2018</changed>
// ********************************************************************************
void ControlStructures ()
{
    try
    {
        ColourCouter ( "-------------------------------------------------------", F_bRED );
        ColourCouter ( "-------------------------------------------------------\n\n", F_bRED );
        const char tab { '\t' };
        const char nline { '\n' };

        //! ####################################################################
        //! ~~~~~ statements and flow control (control structures): apart from linear sequence of statements a program can contain repeated segments of code, decision taking and bifurcations
        // generic (sub)statements required by most of the flow control statements in C++ as a part of their syntax are either simple statements ended with semicolon (;) or a compound one which every single statement ends with its own semicolon (;) enclosed as a block in curly braces ({}). { statement1; statement2; ... }
        // the entire block composed of sub-statements is considered a single statement.
        std::cout << nline << "~~~~~ Statements and flow control (Control Structures):" << nline;
        std::cout << "A program can contain linear sequence of statements, repeated segments of code, decision taking and bifurcations." << nline;

        //! ####################################################################
        //! ~~~~~ selection statements (if and else): execution of a statement or block if the condition is fulfilled.
        // the keywords are if and else.
        // syntax: if (condition) statement
        // if condition is true the statement will be executed
        std::cout << nline << "~~~~~ Selection Statements (if and else):" << nline;
        std::cout << "Can be used to introduce conditioned selection of statements." << nline;
        int x { 99 };
        std::cout << nline << "The value stored in x is:" << tab << x << nline;
        if ( x == 80 )
            std::cout << "x is 80" << nline; // a statement
        if ( x != 80 ) { std::cout << "x is "; std::cout << x << nline; } // a block statement without usual indentation and line breaks
        // syntax: id (condition) statement1 else statement2
        // the introduced statement2 by else executed when the condition is not fulfilled.
        x = 46;
        std::cout << nline << "The value stored in x is:" << tab << x << nline;
        if ( x == 80 )
            std::cout << "x is 80" << nline;
        else // introduction of an alternative statement
            std::cout << "x is not 80" << nline;
        // concatenated several if + else structure
        // for example it can be introduced to fulfil the intention of checking a range of values
        x = -2;
        std::cout << nline << "The value stored in x is:" << tab << x << nline;
        if ( x > 0 )
            std::cout << "x is positive" << nline;
        else if ( x < 0 ) // alternative statement is concatenated with another if-else structure
            std::cout << "x is negative" << nline;
        else
            std::cout << "x is zero" << nline;

        //! ####################################################################
        //! ~~~~~ iteration statements (loops): repetition of statements a certain times or till a condition is fulfilled.
        // the keywords are while, do and for.
        std::cout << nline << "~~~~~ Iteration Statements:" << nline;
        std::cout << "Can be used to introduce repetition of statements." << nline;

        //! ####################################################################
        //! ----- the while loop: repeat the statement while the expression is true.
        // alteration of the value must somehow happen in the statement to avoid looping forever in while loops
        // syntax: while (expression) statement
        // the complexity of the loop in the example below is trivial for computer so it will be performed instantly without any practical delay
        std::cout << nline << "----- The while loop:" << nline;
        std::cout << "Countdown example with while loop." << nline << nline;
        int n { 10 };
        while ( n > 0 )
        {
            std::cout << n << ", ";
            --n; // altering value checked in condition.
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );; // add delays to the countdown
        }
        std::cout << "lift-off!" << nline;

        //! ####################################################################
        //! ----- the do-while loop: the same behaviour like while loop but the condition will be checked after the execution of the statement.
        // in this loop even when the condition is never fulfilled, at least one execution of the statement is guaranteed.
        // the use of do-while loop is preferred over the while, especially when the condition that is to be checked is determined within the statement itself.
        // syntax: do statement while (condition);
        std::cout << nline << "----- The do-while loop:" << nline;
        std::cout << "Echoing the user inputted text with do-while loop." << nline;
        std::cout << "Enter 'bye' to exit the loop." << nline << nline;
        std::string user_input;
        do
        {
            std::cout << "+++++++ Enter something:" << tab;
            std::getline ( std::cin, user_input );
            std::cout << "You have entered:" << tab << user_input << nline;
        } while ( user_input != "bye" );

        //! ####################################################################
        //! ----- the for loop: iteration of the statement a certain number of times while its condition is true
        // the initialization expression executes before the loop begins and the increase expression after each iteration, therefore the usefulness is placed on the introduction of counter variables.
        // syntax: for (initialization; condition; increase) statement;
        std::cout << nline << "----- The for loop:" << nline;
        std::cout << "Countdown example using a for loop." << nline << nline;
        for ( int n { 10 }; n > 0; n-- )
        {
            std::cout << n << ", ";
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) ); // add delays to the countdown
        }
        std::cout << "lift-off!" << nline;

        // more about for loops plus some features:
        // the tree fields in the for loop are optional but the semicolons between them in all cases are obligatory
        // for example: for (; n<10; ;) --(equivalent to a while loop)
        // another example: for (; n<10; ++n;) --(maybe the variable is initialized before)
        // equivalent to a loop with no condition is a loop with true as condition i.e. an infinite loop.
        // each field will be executed in a particular time in the life cycle of a loop. these fields are expressions so they can use the comma operator, therefore a for loop can handle two counter variables at the same time.
        // expressions are not statements so they can't be replaced by a block.
        std::cout << nline << "Some features of the for loop:" << nline << nline;
        std::cout << "The practice of multiple expressions as fields." << nline << nline;
        for ( int i = 30, n = 0; n != i; n++, i -= 2 )
        {
            std::cout << "^-^" << tab; // times of execution is 10
        }
        std::cout << nline;
        // example of nested for loops:
        //  *   *  
        //   * *   
        //    *      * 9 times
        //   * *   
        //  *   *  
        std::cout << nline << "Demonstration of a pattern using nested for loops." << nline << nline;
        for ( int i = 1; i <= 5; i++ )
        {
            for ( int j = 1; j < 47; j++ )
            {
                if ( ( i == ( j % 5 ) ) || ( ( ( i - 1 ) + ( j % 5 ) ) == 5 ) )
                    std::cout << '*';
                else
                    std::cout << ' ';
            }
            std::cout << nline;
        }

        //! ####################################################################
        //! ----- range-based for loops: iteration over all the elements in a range
        // syntax: for (declaration : range) statement;
        // declaration declares a variable of a type which able to take values of an element in the range.
        // ranges are sequences of elements including arrays, containers and any other type supporting the functions begin and end.
        // none of these types is mentioned yet, therefore stings will be used which are sequences of character.
        // this kind of loop is automatic and doesn't require the explicit declaration of counter variable.
        std::cout << nline << "----- Rang-based for loops:" << nline;
        std::cout << "Iteration over all the elements in a range." << nline << nline;
        std::string for_range { "SequenceOfCharacters" };
        std::cout << "The stored string in the variable is:" << tab << for_range << nline << nline;
        for ( char c : for_range )
        {
            std::cout << "-" << c << " "; // representing the value of each element in the range using the variable c
        }
        std::cout << nline;
        // using type deduction (auto):
        // to automatically deduct the type of elements in a range
        std::cout << nline << "Type deduction in range-based for loops:" << nline << nline;
        for ( auto c : for_range )
        {
            std::cout << "-" << c << " ";
        }
        std::cout << nline;

        //! ####################################################################
        //! ~~~~~ jump statements:
        // they can be used to alter the flow of a program by jumping to specific locations
        std::cout << nline << "~~~~~ Jump statements:" << nline;
        std::cout << "The flow of a program can be altered by jumping to specific locations." << nline;

        //! ####################################################################
        //! ----- the break statement:
        // to leave a loop, even if its end condition isn't fulfilled.
        // purposes: to end an infinite loop, to leave a loop before its natural end
        std::cout << nline << "----- The break statement:" << nline;
        std::cout << "To introduce leaving of a loop before its natural end." << nline << nline;
        std::cout << "Countdown example and breaking its loop." << nline << nline;
        for ( int n { 10 }; n > 0; n-- )
        {
            std::cout << n << ", ";
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) ); // add delays to the countdown
            if ( n == 3 )
            {
                std::cout << "Countdown aborted!" << nline;
                break;
            }
        }

        //! ####################################################################
        //! ----- the continue statement:
        // to skip the current iteration and jumping to the next one.
        std::cout << nline << "----- The continue statement:" << nline;
        std::cout << "To introduce skipping the iterations of a loop." << nline << nline;
        std::cout << "Countdown example with for loop and skipping some of its iterations." << nline << nline;
        for ( int n { 10 }; n > 0; n-- )
        {
            if ( n == 8 || n == 5 || n == 2 )
            {
                continue;
            }
            std::cout << n << ", ";
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) ); // add delays to the countdown
        }
        std::cout << "The steps 8, 5 and 2 are skipped!" << nline;

        //! ####################################################################
        //! ----- the goto statement: provides absolute jump to another point in the program
        // this jump is an unconditional jump, ignores the nesting levels and doesn't cause any automatic stack unwinding,
        // therefore it is to be used with care, preferably within the same block and especially in the presence of local variables.
        // defined labels which are valid identifier followed by colon (:), are destinations point and will be used as argument for goto.
        // goto is deemed a low-level feature with no particular use in modern higher-level C++ programming paradigms.
        std::cout << nline << "----- The goto statement:" << nline;
        std::cout << "To introduce absolute and unconditional jump to another point in the program." << nline << nline;
        std::cout << "Countdown example using goto feature." << nline << nline;
        int n2 { 10 };
    a_loop_with_goto:
        std::cout << n2 << ", ";
        --n2;
        std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) ); // add delays to the countdown
        if ( n2 > 0 ) goto a_loop_with_goto;
        std::cout << "lift-off!" << nline;

        //! ####################################################################
        //! ~~~~~ another selection statement (switch): to compare the evaluated expression against labels that are constant expressions.
        // it is like concatenations of 'if' and 'else if' statements but limited to constant expressions.
        // it is not possible to use variables or ranges as labels since they aren't valid C++ constant expressions, therefore it is better to use 'if' for ranges and values that aren't constant.
        // after evaluating the expression and finding the equivalent constant, its break statement causes the end of the switch.
        // if the evaluation value isn't match to any of the constants, the default case and its group of statement, if existed since it is optional, will be executed.
        // syntax:
        // switch (expression) {
        // case constant1:
        //   group_of_statement1;
        //   break;
        // .
        // .
        // .
        // default:
        //   group_of_default_statement;
        //   break;
        // }
        std::cout << nline << "~~~~~ Another selection statement (switch):" << nline;
        std::cout << "Switching and checking for a value among the possible constant expressions." << nline << nline;
        int x2 { 0 };
        switch ( x2 )
        {
            case 1:
                std::cout << "The value of x2 is one" << nline;
                break;
            case 2:
                std::cout << "The value of x2 is two" << nline;
                break;
            default:
                std::cout << "The value of x2 is not among the cases" << nline;
                break;
        }
        // the syntax of switch is inherited from the early versions of C language. switch uses labels in place of blocks.
        // the break statement for each case is needed, otherwise switch executes all the statements after the equivalent case till the end or reaching a break no matter what case they belong to.
        // this makes enclosing a group statement in braces unnecessary and can be useful for execution the same group of statement for more than one case.
        std::cout << nline;
        switch ( x2 )
        {
            case 1:
            case 2:
            case 3:
                std::cout << "The value of x2 is either one, two or tree" << nline;
                break;
            default:
                std::cout << "The value of x2 is not one, two nor tree" << nline;
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
void duplication ( int& a, int& b, int& c )
{
    a *= 2, b *= 2, c *= 2;
}
void print_message ( void )
{
    std::cout << "\n\n\t I'm a Function. \n\n";
}
std::string concatenate ( std::string& a, std::string& b )
{
    return a + b;
}
std::string constant_concatenate ( const std::string& a, const std::string& b )
{
    return a + b;
}
inline std::string inline_constant_concatenate ( const std::string& a, const std::string& b )
{
    return a + b;
}
int divide ( int a, int b = 2 )
{
    int r; r = a / b; return r;
}
void odd ( int x ); // declaration before definition
void even ( int x ); // declaration before definition
long factorial ( long a )
{
    if ( a > 1 )
        return ( a*factorial ( a - 1 ) );
    else
        return 1;
}
// ********************************************************************************
/// <summary>
/// Functions in C++
/// </summary>
/// <created>ʆϒʅ,15.05.2018</created>
/// <changed>ʆϒʅ,24.05.2018</changed>
// ********************************************************************************
void Functions ()
{
    // the body code of functions used in this section are defined above it
    try
    {
        ColourCouter ( "-------------------------------------------------------", F_bRED );
        ColourCouter ( "-------------------------------------------------------\n\n", F_bRED );
        const char tab { '\t' };
        const char nline { '\n' };

        //! ####################################################################
        //! ~~~~~ functions: a group of code that is given a name to structure a program in segment of code to perform individual tasks and can be called from some point of the program.
        // most common syntax: type name (parameter1, ...) {statements}
        // the parenthesis which differentiate functions from other kind of declaration or statements are always required no matter declaring or calling a function.
        // parameters which allow passing arguments to the function act like local variables within the functions
        // the expression that calls a function is evaluated as the returned value by the function
        // all the functions that have defined return type in their definitions must return a value with a proper return statement that includes a return value, even if this value is never going to be used.
        // a function can be called multiple times and its parameter aren't limited to literals.
        std::cout << nline << "~~~~~ Functions:" << nline;
        std::cout << "Introduce structures that can be used to perform individual tasks in segment of code." << nline << nline;
        int result;
        std::cout << "Two function to perform addition and subtraction operations." << nline << nline;
        std::cout << "Passed literal values as parameters to be added:\t" << "2 and 7" << nline;
        result = addition ( 2, 7 ); // passing literals
        std::cout << "The result of addition function:" << tab << result << nline; // inserting returned value stored in result variable
        std::cout << "The result of addition function without storing in additional variable:" << tab << addition ( 2, 7 ) << nline << nline; // direct function calling in insertion stream
        int x { 4 }; int y { 3 };
        std::cout << "Passed variables as parameters to be subtracted:" << tab << "x = " << x << tab << "y = " << y << nline;
        result = subtraction ( x, y ); // passing variables
        std::cout << "The result of subtraction function:" << tab << result << nline << nline; // inserting returned value stored in result variable
        std::cout << "The result of subtraction function without storing in additional variable:" << tab << subtraction ( x, y ) << nline << nline; // direct function calling in insertion stream
        std::cout << "Passed variables as parameters to be subtracted:" << tab << "x = " << x << tab << "y = " << y << nline;
        result = 6 + subtraction ( x, y ); // the function call is operand of addition operation.
        result = subtraction ( x, y ) + 6; // same as above: commutative property of addition operation
        std::cout << "The result of subtraction function called as an operand of addition operation:" << tab << result << nline << nline; // inserting returned value stored in result variable

        //! ####################################################################
        //! ----- functions with no type (the use of void):
        // if the function doesn't need to return a value it shall be defined as void function.
        // the void type is an spacial type to represent the absence of value.
        // void keyword can also be used in function's parameter list to explicitly specify that the function takes no actual parameters
        // void keyword in parameter's list: in C++ optional, in C language required
        std::cout << nline << "----- Functions with no type (The use of void):" << nline;
        std::cout << "Void functions are those that don't have any returned value." << nline << nline;
        std::cout << "The message is inserted by calling a void function with no parameters:" << nline;
        print_message ();


        //! ####################################################################
        //! ----- the return value of main: the type of return value of main is int.
        // if the execution of main ends normally without encountering the return statement the compiler assumes that the function has ended with an implicit return statement. this only applies to the main function for historical reasons.
        // implicit return statement: return 0;
        // the returned zero value either implicitly or explicitly will be interpreted by the environment that the program ended successfully.
        // returning other values are possible and some environment give access to them to the caller in some way, although this behaviour is not required nor necessarily portable between platforms.
        // the values that are guaranteed that can be interpreted in the same way on all platform are:
        // 0 : the program was successful
        // EXIT_SUCCESS : the program was successful (the heater is <cstdlib>)
        // EXIT_FAILURE : the program failed (the heater is <cstdlib>)
        // some authors consider explicitly writing the statement is a good practice, since the implicit return statement for main is a tricky exception.
        std::cout << nline << "----- The return value of main:" << nline;
        std::cout << "The return value of the main function which is of type int has his own peculiarity." << nline << nline;
        std::cout << "Read the comments in the source code..." << nline;


        //! ####################################################################
        //! ----- arguments passed by value and by reference:

        // by value: the values of arguments will be passed to function on the moment of the call.
        // the values will be copied into the variables represented by function parameters.
        // the values of passed arguments will be used to initial the function parameters, thus the modification of them in function doesn't have any effect on the variables outside of it.
        std::cout << nline << "----- Arguments passed by value and by reference:" << nline;
        std::cout << "The Arguments can be passed to a function by value and by reference." << nline << nline;
        std::cout << "Passing arguments by value:" << nline;
        x = 3, y = 4, result = 0;
        std::cout << "The passed arguments are:" << tab << "x = " << x << tab << "y = " << y << nline;
        result = addition ( x, y );
        std::cout << "The result of addition function which has arguments passed by value:" << tab << result << nline;

        // by reference: make access to variables outside of function passible.
        // to actually modify the value of variables used as arguments to call a function, arguments need to be passed by reference.
        // to gain access to arguments, the function defines its parameters as reference.
        // in C++ references are indicated by the ampersand sign '&' following the parameter type.
        // what is passed is the variable itself, so somehow the association happens between the passed arguments and the parameters of the function to the extent that the modification of arguments on their corresponding local variables within function becomes possible and its reflection is on the variables passed as arguments.
        // 
        std::cout << nline << "Passing arguments by reference:" << nline;
        x = 2, y = 3;
        int z { 4 };
        std::cout << "The passed arguments are:" << tab << "x = " << x << tab << "y = " << y << tab << "z = " << z << nline;
        duplication ( x, y, z );
        std::cout << "The result of duplication function which has arguments passed by reference:" << nline;
        std::cout << tab << "x = " << x << tab << "y = " << y << tab << "z = " << z << nline;


        //! ####################################################################
        //! ----- efficiency consideration and constant reference:
        // passing arguments by value causes the arguments to be copied which it may be relatively inexpensive for fundamental types like int but in compound type it may result in certain overhead and copying large quantities of data just for function call.
        // for this unneeded copy to be avoided, calling functions by reference is suggested and with it, the function operates directly on aliases of passed strings and at most, it might mean the transfer of certain pointer to the function.
        std::cout << nline << "----- Efficiency consideration and constant reference:" << nline;
        std::cout << "Passing arguments by reference to avoid certain overhead." << nline << nline;
        std::string a, b, c;
        std::cout << "Enter two long string to be concatenated:" << nline << nline << "Enter the first one:" << tab;
        std::getline ( std::cin, a );
        std::cout << nline << "And the second one is:" << tab;
        std::getline ( std::cin, b );
        c = concatenate ( a, b );
        std::cout << nline << "And the concatenated result is:" << tab << c << nline << nline;

        // functions with reference parameters are generally perceived as functions that modify the arguments passed.
        // by qualifying the parameters as constant it can be guaranteed that the function doesn't modify the arguments 
        std::cout << "The use of constant parameters in passing arguments by reference." << nline << nline;
        std::cout << "Above entered strings will be used." << nline << nline;
        c = constant_concatenate ( a, b );
        std::cout << "And the concatenated result is:" << tab << c << nline;


        //! ####################################################################
        //! ----- inline functions:
        // since calling a function has a certain overhead (stacking arguments, jumps etc...) it isn't efficient for short functions.
        // by using inline specifier in the function declaration the compiler will be suggested that inline expansion is preferred over the usual function call mechanism.
        // behaviour of a function won't be changed but the function body will be inserted at each point of the function call, so the regular invocation will be avoided.
        std::cout << nline << "----- Inline functions:" << nline;
        std::cout << "To introduce the inline expansion of a function body and replace the regular invocation with it." << nline << nline;
        std::cout << "Example of concatenate function with inline specifier declaration." << nline << nline;
        std::cout << "Above entered strings will be used." << nline << nline;
        c = inline_constant_concatenate ( a, b );
        std::cout << "And the concatenated result is:" << tab << c << nline;
        // note that in C++ the optimization task is delegated to the compiler.
        // most compiler already optimize code to generate inline functions whenever there is an opportunity, even not explicitly marked with inline specifier.
        // Therefore using it in the declaration of a function is merely a suggestion and the compiler is free to not inline it and optimize otherwise, as long as the resulting behaviour is one specified by the code.

        //! ####################################################################
        //! ----- default value in parameters:
        // optional parameters in C++ functions that doesn't require any arguments in the call shall have default values in the definition which will be used when a function called with fewer arguments.
        // 
        std::cout << nline << "----- Default value in Parameters:" << nline;
        std::cout << "To introduce optional parameters of the function." << nline << nline;
        std::cout << "The divide function with two parameters of which the last one is optional." << nline;
        std::cout << "There are going to be two calls to this function and the results will be:" << nline << nline;
        result = divide ( 12 );
        std::cout << "divide (12):" << tab << result << nline;
        result = divide ( 20, 4 ); // optional parameter is used in the call, therefore the default value will be ignored
        std::cout << "divide (20, 4):" << tab << result << nline;


        //! ####################################################################
        //! ----- declaring functions:
        // in C++ functions like identifiers can not be used before declaration.
        // the prototype of a function can be declared without actually defining the function completely, giving just enough details about the types involved in the function definition which at least makes the call to the function possible.
        // the prototype of a function shall be declared before calling the function.
        // the declaration of prototype needs to include all types involved (return and arguments) and uses the same syntax as used in declaration of functions but it doesn't have any body code, and ends with semicolon.
        // in the declaration of the prototype, names of parameters are optional, therefore they can be mentioned with different names, not matching to the declaration of the function itself, or don't be mentioned at all.
        // so the syntax can be: int proto_function (int first, int second);
        // or it can be: int proto_function (int, int);
        // anyway including a name always improves the legibility of the declaration.
        // declaring function is not only useful to recognize the order of functions.
        // in the example below there is a call to function odd and this function, if needed, calls the function even, therefore without declaration of at least one of them before their actual definitions there isn't any way to structure the code so that the function odd is defined before even and the function even before odd.
        std::cout << nline << "----- Declaring functions:" << nline;
        std::cout << "To introduce the declaration of a function and place its definition elsewhere." << nline << nline;
        std::cout << "Working with the functions odd and even:" << nline;
        int number;
        do
        {
            std::cout << "Please enter a number (0 to exit):" << tab;
            std::cin >> number;
            odd ( number );
        } while ( number != 0 );

        //! ####################################################################
        //! ----- recursivity: the property of functions that allow them to call themselves.
        // usual for some task like sorting elements or factorial (n!)
        std::cout << nline << "----- Recursivity:" << nline;
        std::cout << "To introduce the property of functions, of that they take the ability to call themselves." << nline << nline;
        std::cout << "A recursive function to calculate factorial:" << nline;
        long number2 { 9 };
        std::cout << number2 << "! =" << tab << factorial ( number2 ) << nline;
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


int operate ( int a, int b )
{
    return ( a + b );
}
// different declaration and definition
double operate ( double a, double b )
{
    return ( a / b );
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
// the use of regular non-template type
bool equality_check ( T a, U b )
{
    return ( a == b );
}
// non-type template arguments: expressions of particular type
template <class T, int N>
T fixed_multiply ( T val )
{
    return val * N;
}
// ********************************************************************************
/// <summary>
/// Overloads and templates in C++
/// </summary>
/// <created>ʆϒʅ,24.05.2018</created>
/// <changed>ʆϒʅ,26.05.2018</changed>
// ********************************************************************************
void OverloadsAndTemplates ()
{
    // the body code of functions used in this section are defined above it
    try
    {
        ColourCouter ( "-------------------------------------------------------", F_bRED );
        ColourCouter ( "-------------------------------------------------------\n\n", F_bRED );
        const char tab { '\t' };
        const char nline { '\n' };

        //! ####################################################################
        //! ~~~~~ overloads and templates:
        std::cout << nline << "~~~~~ Overloads and templates:" << nline;

        //! ####################################################################
        //! ----- Overloads:
        // in C++, two or more different functions can have the same name if their parameters are different (number, type).
        // it isn't enough to have different return type to overload a function and at least one parameter must be different.
        // the compiler distinguish which overload of a function shall be called by examining the type of the passed arguments.
        std::cout << nline << "----- Overloaded functions:" << nline;
        std::cout << "C++ ability to define multiple operation for the same overloaded function." << nline << nline;
        // the example below is not generally a good idea to demonstrate overloads of a function, since it is expected, that the behaviour of the overloads of a function to be similar.
        // the functions in this example have entirely different behaviours, declarations and definitions and the only similarity is their name.
        // this example shows the possibility, while a similar behaviour is expected, the overloads can be fully different.
        std::cout << "The result of the operations addition and division performed by the overloads of the function operate:" << nline << nline;
        int x { 2 }, y { 3 };
        double n { 2.4 }, m { 3.7 };
        std::cout << "x =" << tab << x << tab << "y =" << tab << y << nline;
        std::cout << "Result of overload addition of the function operate is:" << tab << operate ( x, y ) << nline << nline;
        std::cout << "n =" << tab << n << tab << "m =" << tab << m << nline;
        std::cout << "Result of overload division of the function operate is:" << tab << operate ( n, m ) << nline;

        //! ####################################################################
        //! ----- function templates:
        // overloaded functions may have the same definition.
        // the function sum could be overloaded for many types and all of them having the same body or definition.
        std::cout << nline << "----- Function templates:" << nline;
        std::cout << "The ability of C++ to define generic functions known as function templates." << nline << nline;
        std::cout << "Overloads of the function sum with the same definition:" << nline;
        std::cout << "Sum of 10 and 20 (overloaded function for int type):" << tab << sum ( 10, 20 ) << nline;
        std::cout << "Sum of 1.2 and 1.5 (overloaded function for double type):" << tab << sum ( 1.2, 1.5 ) << nline << nline;
        // for cases such as the case above, C++ has the ability to define generic functions known as function templates.
        // syntax: template <template-parameters> function-declaration
        // it is like regular function, preceded with template keyword and a series of template parameters enclosed in angle-brackets <> and separated with comma
        // the template parameters can be generic template types by specifying either the class or typename keyword (100% synonym in template declaration) followed by an identifier. this identifier can then be used in the function definition like regular types. (seed generic sum function)
        // no matter how a generic type would be used (parameter, return or variable), it will be determined on the moment the template is instantiated.
        // a template can be instantiated by applying it to create a function using particular types or values for its template parameters.
        // the instantiation will be done when a template function called. call statement syntax is like function but the template arguments enclosed in angle-brackets are to be specified.
        // syntax: name <tamplate-arguments> (function-arguments)
        std::cout << "Calling sum2 function template (the use of generic function in C++):" << nline;
        int result1;
        result1 = sum2<int> ( 10, 20 ); // using int type to make an instance
        std::cout << "A call for the sum of 10 and 20 (int):" << tab << result1 << nline;
        double result2;
        result2 = sum2<double> ( 1.2, 1.5 ); // making another instance with double type
        std::cout << "Another call for the sum of 1.2 and 1.5 (double):" << tab << result2 << nline << nline;

        // since the generic type SomeType is also used as parameters of the function, the compiler is able to deduce the data type automatically.
        // therefore there is no need to explicitly specify the type within angle-brackets when calling the function.
        // for this the type shall be unambiguous so the compiler could perform the deduction.
        // if the function is called with arguments of different types, the compiler may not be able to deduct the type of generic type.
        // take the following call for instance:
        long long result3;
        result3 = sum2 ( 21355479374, 21370547592 ); // type deduction in generic types
        std::cout << "Using type deduction: a call for the sum of 21355479374 and 21370547592 (long long):" << tab << result3 << nline << nline;

        // templates are a powerful and versatile features. they can have multiple template parameters and the function can still use regular non-templated types.
        // in the example below there is no ambiguity possible since numerical literals are always of a specific type:
        // unless otherwise specified with a suffix, integer literals always produce values of type int and floating-point literals always produce values of type double.
        std::cout << "The versatile features that function templates have to offer:" << nline;
        if ( equality_check ( 10, 10.0 ) ) // automatic template parameter deduction
            std::cout << "The numbers 10 and 10.0 are equal" << nline;
        else
            std::cout << "The numbers 10 and 10.0 are not equal" << nline;

        //! ####################################################################
        //! ----- non-type template arguments:
        // the template parameter can also include expression of a particular type additionally to types introduced with class and typename.
        // the second argument of fixed-multiply function template is of type int, looks like regular function parameter and can actually be used just like one.
        // but there exist a major difference: template parameter's values will be determined in compile-time to generate different instantiations, thus the value of that argument is never passed during runtime.
        // this means that the two calls essentially happens to two different versions of fixed-multiply function template, one of them always multiplies by two and other one by tree.
        // therefore the second template argument needs to be a constant expression and it can't be passed a variable.
        std::cout << nline << "----- Non-type template arguments:" << nline;
        std::cout << "To include expression of particular types in the template parameter." << nline << nline;
        std::cout << "The use of fixed-multiply function template and its second template argument:" << nline;
        int result4;
        result4 = fixed_multiply<int, 2> ( 10 );
        std::cout << "First instance (always multiply with 2):" << tab << result4 << nline;
        result4 = fixed_multiply<int, 3> ( 10 );
        std::cout << "Second instance (always multiply with 3):" << tab << result4 << nline;
    }
    catch ( const std::exception& )
    {

    }
}


int global_variable { 22 }; // has global scope from this point of code
int first_function ()
{
    int local_variable; // has local scope within this block
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
namespace fistNamespace
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
namespace fistNamespace
{
    int c { 4 };
    int d { 5 };
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
int aGlobalVariable; // has static storage, is automatic initialized
// ********************************************************************************
/// <summary>
/// Name visibility
/// </summary>
/// <created>ʆϒʅ,26.05.2018</created>
/// <changed>ʆϒʅ,30.05.2018</changed>
// ********************************************************************************
void NameVisibility ()
{
    // the functions, namespaces and variables used in this section are defined above it.
    try
    {
        ColourCouter ( "-------------------------------------------------------", F_bRED );
        ColourCouter ( "-------------------------------------------------------\n\n", F_bRED );
        const char tab { '\t' };
        const char nline { '\n' };

        //! ####################################################################
        //! ~~~~~ name visibility:
        // in C++ name entities such as variables, functions and compound types need to be declared before being used.
        // the point where this declaration happens hat influence on its visibility.
        std::cout << nline << "~~~~~ Name Visibility:" << nline;
        std::cout << "The visibility of name entities such as variables, functions and compound types after declaration can be different." << nline;
        std::cout << "The point where an entity is declared, influences its visibility." << nline;


        //! ####################################################################
        //! ----- scope:
        // global scope: the entity is defined outside all blocks and is visible to all of them.
        // local scope: the entity is defined inside a block and is only visible to it.
        // a name can represents only one entity, therefore two variables can't have same name within the same scope.
        std::cout << nline << "----- Scope:" << nline;
        std::cout << "The scope of every entity is dependent on the point of its declaration." << nline << nline;
        std::cout << "The value of global_variable:" << tab << global_variable << nline;
        std::cout << "The value of local_variable of first_function:" << tab << first_function () << nline;
        std::cout << "The value of local_variable of second_function:" << tab << second_function () << nline;
        std::cout << "The value of global_variable after calling the second_function:" << tab << global_variable << nline << nline;

        // the visibility of an entity with block scope extends until the end of its block including its inner blocks.
        // nevertheless, re-utilization of an outer block defined name in the inner blocks is possible.
        // this re-utilization hides the outer block entity name in the inner block and refers to a different entity.
        // declarations that introduce a block such as functions, for, if etc... have these inner block entity rules too.
        std::cout << "The introduction of inner blocks and their scopes:" << nline << nline;
        int x { 10 };
        int y { 20 };
        std::cout << "The initialized value of x :" << tab << x << nline;
        std::cout << "The initialized value of y :" << tab << y << nline << nline;
        {
            int x; // OK, inner scope.
            x = 30; // assigns a value to the inner block x variable; outer block x variable is hidden.
            y = 30; // assigns a value to the outer block y variable; outer block y variable is not hidden.
            std::cout << "Inserted from inner block:" << nline;
            std::cout << "x (the inner block x entity) :" << tab << x << nline;
            std::cout << "y (the outer block y entity) :" << tab << y << nline << nline;
        }
        std::cout << "Inserted from outer block:" << nline;
        std::cout << "x (the outer block x entity) :" << tab << x << nline;
        std::cout << "y (the outer block y entity) :" << tab << y << nline;

        //! ####################################################################
        //! ----- namespaces: organization of named entities with global scope into narrower namespace scope to avoid name collision
        // only one entity can exist with a particular name in a particular scope, which for local names is seldom a problem, since the blocks tend to be relatively short.
        // non-local names bring more possibilities for name collision, considering the number of functions, types and variables, neither of them local in the nature and some of them very generic.
        // namespaces allow the introduction of different logical scopes referred to by names to organize the elements of program.
        // syntax: namespace identifier { name-entities }
        // the elements of namespaces can be accessed normally with their own identifier from within of their scope.
        // the elements of namespaces have to be properly qualified with the scope operator (::) and the identifier of their namespace to be reached from outside.
        // namespaces can be split, two segments of code can be declared in the same namespace
        // namespaces can even extend across different translation unit (i.e.: across different files of source code)
        std::cout << nline << "----- Namespaces:" << nline;
        std::cout << "To introduce the organization of named entities with global scope into narrower namespace scope." << nline << nline;
        std::cout << "The elements of first namespace before change:" << nline;
        std::cout << "a :" << tab << fistNamespace::a << tab << "b :" << fistNamespace::b << nline;
        fistNamespace::a = 55; // an element of namespace, accessed from outside
        fistNamespace::b = 66; // the same
        std::cout << "The elements of first namespace after change:" << nline;
        std::cout << "a :" << tab << fistNamespace::a << tab << "b :" << fistNamespace::b << nline << nline;
        std::cout << "Two function with the same name defined in two namespaces to avoid name collision:" << nline;
        std::cout << "The result of value function in the first namespace:" << tab << fistNamespace::value () << nline;
        std::cout << "The result of value function in the second namespace:" << tab << secondNamespace::value () << nline;
        std::cout << "The variable pi defined in the second namespace:" << tab << secondNamespace::pi << nline;

        //! ####################################################################
        //! ----- the using keyword:
        // to introduce a name into the current declarative region (such as a block), thus avoiding the need to qualify the name.
        std::cout << nline << "----- The using keyword:" << nline;
        std::cout << "To avoid the need to qualify a name in the current declarative region." << nline << nline;
        std::cout << "Accessing variables in the first and second namespace with and without qualification:" << nline << nline;
        {
            using first::xx; // avoid the need of name qualifier
            using second::yy; // the same
            std::cout << "No need to qualify the name:" << nline;
            std::cout << "The value of xx in the first namespace:" << tab << tab << xx << nline;
            std::cout << "The value of yy in the second namespace:" << tab << yy << nline << nline;
            std::cout << "Need to qualify the name:" << nline;
            std::cout << "The value of xx in the second namespace:" << tab << second::xx << nline;
            std::cout << "The value of yy in the first namespace:" << tab << tab << first::yy << nline << nline;
        }

        // the use of the keyword using as a directive to introduce an entire namespace
        // using and using namespace have validity only in the same block in which they are stated or in the entire source code if they are used directly in the global scope.
        // therefore it would be possible to first use the objects of one namespace and then those of another one by splitting the code in different blocks.
        std::cout << "To introduce an entire namespace, the keyword using can be used as a directive:" << nline;
        {
            using namespace first;
            std::cout << "The value of xx in the first namespace:" << tab << tab << xx << nline;
            std::cout << "The value of yy in the first namespace:" << tab << tab << yy << nline;
            std::cout << "The value of xx in the second namespace:" << tab << second::xx << nline;
            std::cout << "The value of yy in the second namespace:" << tab << second::yy << nline << nline;
        }
        std::cout << "Splitting the code in different blocks to use different namespaces:" << nline;
        {
            using namespace first;
            std::cout << "The value of xx (first block in which the first namespace is used):" << tab << xx << nline;
        }
        {
            using namespace second;
            std::cout << "The value of xx (second block in which the second namespace is used):" << tab << xx << nline << nline;
        }
        // while the direct visibility with the power of the keyword using facilitate comprehension and shorten the length of the code,
        // for projects mixing libraries explicit qualification tends to be preferred and with it the name collision can be avoided.

        // namespace aliasing: existing namespaces can be aliased with new names
        // syntax: namespace new_name = current_name;
        namespace firstNewName = first;
        {
            using namespace firstNewName;
            std::cout << "Using the alias of the first namespace." << nline;
            std::cout << "The value of xx :" << tab << xx << nline;
        }

        //! ####################################################################
        //! ----- storage classes:
        //# static storage: variables with global or namespace scope
        // their storage is allocated for the entire duration of the program
        // if they aren't explicitly initialized, they will be initialized automatically with zeroes
        //# automatic storage: local variables
        // their storage is only available during their declaration block
        // if they aren't explicitly initialized, they will be left uninitialized, and thus have undetermined value (considering compiler differences)
        std::cout << nline << "----- Storage classes:" << nline;
        std::cout << "The difference between static and automatic storage." << nline << nline;
        // int aLocalVariable; // has automatic storage, isn't automatically initialized and can't be used without initialization
        int anotherLocalVariable { 235 }; // has automatic storage, is explicitly initialized
        std::cout << "The value of a global variable which has static storage:" << tab << tab << aGlobalVariable << nline;
        // std::cout << aLocalVariable; // Error
        std::cout << "The value of another local variable which has automatic storage:" << tab << anotherLocalVariable << nline;
    }
    catch ( const std::exception& )
    {

    }
}