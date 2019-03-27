// --------------------------------------------------------------------------------
/// <summary>
/// _4_CompoundDataTypes.cpp
/// </summary>
/// <created>ʆϒʅ,30.05.2018</created>
/// <changed>ʆϒʅ,27.03.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "ConsoleAdjustments.h"


#define Tab '\t'
#define Nline '\n'

const char tab { '\t' };
const char nline { '\n' };


void _07_01_Arrays ()
{
    // the functions used in this section are defined above it.
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ arrays:
        // an array is built a chain of same type elements placed in contiguous memory locations.
        // every individual element can be referred to by its unique index identifier.
        // in C++ language the first element index of an array is always zero.
        // an array like a variable is usable after declaration.
        // Note declaration syntax: type name [elements];
        // elements field which is always enclosed in square brackets [] specifies the length of the array in terms of the number of elements.
        // elements field specifies the length of the array in terms of number. (always enclosed in square brackets)
        // arrays are blocks of static memory, which sizes are determined at the compile time,
        // therefore the element field of an array must be a constant expression.
        ColourCouter ( "~~~~~ Arrays:\n", F_bBLUE );
        ColourCouter ( "Same type elements can build series of elements known as arrays and every element can be referenced by adding an index to the array's unique identifier.\n\n", F_YELLOW );
    }
    catch ( const std::exception& )
    {

    }
}


void print_simple_array ( int arg [], int length )
{
    std::cout << tab;
    for ( int n = 0; n < length; n++ )
    {
        std::cout << arg [n];
        if ( arg [n] < 9 ) std::cout << "   "; else std::cout << "  ";
    }
    std::cout << Nline << Nline;
}
void _07_02_InitializingArrays ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- initializing arrays:
        // arrays of local scope like variables are uninitialized by default
        // to explicitly initialize an array, the values must be enclosed in curly braces.
        // the number of values must not be grater than the exact number of elements in the array.
        // if the array is initialized with less, the remaining elements will be set to their default values.
        // the default value for fundamental types is zero.
        // empty curly braces are to be used to initial an array with default values.
        // with leaving square braces empty for an initialization-provided array,
        // C++ automatically assume a size for the array that matches the number of its values.
        // evolution of C++ has provided universal initialization also for arrays,
        // so equal signs in between of their declarations and identifiers aren't needed any more.
        ColourCouter ( "----- Initialization of Arrays:\n", F_bBLUE );
        ColourCouter ( "Uninitialized arrays of local scope have undetermined values.\n\n", F_YELLOW );
        int array1 [5]; // uninitialized
        int array2 [5] = { 0,10,20,30,40 }; // explicitly initialized
        int array3 [5] = { 0,10,20 }; // remaining elements will be initialized with array's type default value
        int array4 [5] = {}; // all elements are initialized with array's type default value
        int array5 [] = { 0,10,20,30,40 }; // compiler of C++ assumes the size of array automatically
        int array6 [5] { 0,10,20,30,40 }; // universal initialization
        std::cout << "The elements of an uninitialized array (it can be inserted):" << nline;
        print_simple_array ( array1, 5 );
        std::cout << "The elements of an array with explicit initialization:" << "\t\t";
        print_simple_array ( array2, 5 );
        std::cout << "The remaining uninitialized elements of an array:" << "\t\t";
        print_simple_array ( array3, 5 );
        std::cout << "Initialization of an array with default values of its elements:" << tab;
        print_simple_array ( array4, 5 );
        std::cout << "Assuming the size of an array automatically:" << "\t\t\t";
        print_simple_array ( array5, 5 );
        std::cout << "Declaring an array with the use of universal initialization:" << tab;
        print_simple_array ( array6, 5 );
    }
    catch ( const std::exception& )
    {

    }
}


void _07_03_AccessingValues ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- accessing the values of an array:
        // the value of any element in an array can be accessed just like the value of regular variable of the same type.
        // Note syntax: name[index]
        ColourCouter ( "----- Accessing the values of an array:\n", F_bBLUE );
        ColourCouter ( "Elements of an array can be accessed by their indices.\n\n", F_YELLOW );
        int a_array [5] {};
        std::cout << "The array's elements are (automatically initialized):" << "\t\t";
        print_simple_array ( a_array, 5 );
        a_array [0] = 11;
        a_array [2] = 33;
        a_array [4] = 55;
        std::cout << "The array's elements are (after assignment):" << "\t\t\t";
        print_simple_array ( a_array, 5 );

        //! - in addition:
        // exceeding the valid (defined) range of array indices is syntactically (compiler doesn't cause any error) correct,
        // but it can cause error at runtime and the reason for this being allowed will be seen in pointers chapter.
        // giving heed to the different uses that brackets [] have concerning arrays is also important. (define and access time)
        // following comes some expansion on valid operations with arrays.
        ColourCouter ( "More on arrays, their indices and some other valid operations:\n", F_bYELLOW );
        int b_array [5] {}; // first use of brackets: in declaration to specify the size
        b_array [1] = 22; // second use of brackets: to access an element of the array
        int a { 3 };
        b_array [0] = a;
        b_array [a] = 33;
        int b { b_array [a + 1] }; // equivalent: int b {0};
        b_array [b_array [a] / 11] = b_array [2] + 5; // equivalent: b_array[3] = 5;
        std::cout << "The array's elements are (after some valid operation):" << "\t\t";
        print_simple_array ( b_array, 5 );
        int result {};
        for ( int n = 0; n < 5; n++ )
        {
            result += b_array [n];
        }
        std::cout << "Subtraction of all the array's elements are:" << "\t\t\t\t" << result << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void print_bidimensional_array ( int arg [] [5], int width, int height )
{
    std::cout << tab;
    for ( int n = 0; n < width; n++ )
    {
        for ( int m = 0; m < height; m++ )
        {
            std::cout << arg [n] [m];
            if ( arg [n] [m] < 9 ) std::cout << "   "; else std::cout << "  ";
        }
        std::cout << Nline << tab;
    }
    std::cout << Nline;
}
// depth parameter: to represent a simple array in a table (bidimensional):
// explanation in multidimensional arrays section
void print_simple_array_bidimensional ( int arg [], int length, int depth = 0 )
{
    std::cout << tab;
    for ( int n = 0; n < length; n++ )
    {
        if ( depth != 0 )
            if ( ( n != 0 ) && ( n % ( length / depth ) ) == 0 )
                std::cout << nline << tab;
        std::cout << arg [n];
        if ( arg [n] < 9 ) std::cout << "   "; else std::cout << "  ";
    }
    std::cout << Nline << Nline;
}
void _07_04_MultidimensionalArrays ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- multidimensional arrays:
        // arrays with more than one dimension can be described as 'arrays of arrays'.
        // a bidimensional array can be described as a two-dimensional table made of elements, all of the same uniform data type.
        // with each additional dimension for an array, the number of its indices is going to be added to, and with it the amount of needed memory is also increases exponentially
        // multidimensional arrays are just an abstraction for the programmers, since the same result can be achieved with a simple array, by multiplying its indices.
#define HEIGHT 3 // using defined constants for better readability and easiness of later changes in one place
#define WIDTH 5 // the same
        ColourCouter ( "----- Multidimensional arrays:\n", F_bBLUE );
        ColourCouter ( "Can be described as 'arrays of arrays'.\n\n", F_YELLOW );
        int bidimensional_array [HEIGHT] [WIDTH] {}; // declaration of a bidimensional array of 3 per 5 elements of type int
        bidimensional_array [0] [2] = 13; // to reference to the element vertically first and horizontally third
        std::cout << "The bidimensional arrays's elements are:" << nline;
        print_bidimensional_array ( bidimensional_array, HEIGHT, WIDTH );

        //! - in addition:
        // a simple array can replace every multidimensional array by multiplying the needed indices. (multidimensional is just an abstraction for programmers.)
        // the only and useful difference is the depth of every imaginary dimension of an multidimensional array, which compiler automatically remembers.
        ColourCouter ( "Representing a bidimensional array with a simple array:\n", F_bYELLOW );
        int equivalent_simple_array [HEIGHT*WIDTH] {}; // equivalent to bidimensional_array (3*5=15)
        int o { 1 };
        for ( int n = 0; n < HEIGHT; n++ )
        {
            for ( int m = 0; m < WIDTH; m++ )
            {
                // both piece of code produce the same result:
                bidimensional_array [n] [m] = o; // using a bidimensional array
                equivalent_simple_array [n * WIDTH + m] = o; // using a simple array
                ++o;
            }
        }
        std::cout << "The bidimensional arrays's elements are:" << nline;
        print_bidimensional_array ( bidimensional_array, HEIGHT, WIDTH );
        std::cout << "The simple arrays's elements are (same result is achieved):" << nline;
        print_simple_array ( equivalent_simple_array, HEIGHT* WIDTH );
        std::cout << "The simple arrays's elements are (same result is achieved plus printing bidimensional):" << nline;
        print_simple_array_bidimensional ( equivalent_simple_array, HEIGHT* WIDTH, 3 );
    }
    catch ( const std::exception& )
    {

    }
}


void _07_05_ArraysAsParameters ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- arrays as parameters:
        // C++ language passes the address of an array to a function.
        // in practice this has the same effect as passing the entire block of memory, while being more efficient and much faster.
        // to accept an array as parameter for a function, the parameters can be declared as the array type but with empty brackets, omitting the actual size of the array, thus the format is: base_type parameter_name[]
        // for a function to accept an array as parameter, the parameter must be declared as the type of the array but with empty brackets [], and with this the actual array size is omitted.
        // Note format: base_type parameter_name[]
        // Note syntax: void procedure (int arg[])  --accepts an array of type int as parameter
        // Note calling format: function_identifier ( array_identifier ) --without brackets
        ColourCouter ( "----- Arrays as parameters:\n", F_bBLUE );
        ColourCouter ( "In C++ the address of an array can be passed to a function.\n\n", F_YELLOW );
        int first_array [] { 5, 10, 15 };
        int second_array [] { 2, 4, 6, 8, 10 };
        std::cout << "Passing two simple arrays as argument to an earlier defined function:" << nline;
        print_simple_array ( first_array, 3 );
        print_simple_array ( second_array, 5 );

        //! - in addition:
        // a function can also have a multidimensional array as parameter.
        // Note the format for tridimensional arrays: base_type parameter_name[] [depth] [depth]
        // Note syntax: void procedure (int myarray[][depth][depth])
        // for the compiler to determines the depth of each additional dimension, the size of all dimensions after the first one is necessary. (just first twin brackets stays empty)
        // explanation behind is, that for historical reasons, arrays can't be directly copied, therefore all arrays after passing as arguments lose one dimension, and the actual passed is just a pointer.
        // for this to be really understood, a clear understanding in pointer section helps a lot.
        int another_array [2] [5] { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
        std::cout << "Passing a bidimensional array as argument of an earlier defined function:" << nline;
        print_bidimensional_array ( another_array, 2, 5 );
    }
    catch ( const std::exception& )
    {

    }
}


void print_library_array ( std::array<int, 3> arg )
{
    std::cout << tab;
    for ( int element : arg )
        std::cout << element << tab;
    std::cout << Nline << Nline;
}
void _07_06_LibraryArrays ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- library arrays:
        // all the arrays up until now were directly implemented as language features and inherited from C Language.
        // while they are great features, the restriction on copy and decay into pointers make them suffer from an excess of optimization.
        // to over come some of these issues, C++ provides an alternative array type, a type template (a class template in fact) as a standard container, defined in header <array>.
        // this alternative operates similar to built-in one, exception is that the expensive copying of entire block of memory is allowed and it decays into pointers by means of its member data only when explicitly told to do so.
        // in practice the main difference lays on the declaration and the additional inclusion of needed header.
        // classes and containers will be explained later.
        ColourCouter ( "----- Library arrays:\n", F_bBLUE );
        ColourCouter ( "To introduce an alternative for overcoming the issues with built-in C++ language arrays.\n\n", F_YELLOW );
        std::cout << "A built in array in practice:" << nline << tab;
        int built_in_array [] { 10, 20, 30 };
        for ( int i = 0; i < 3; i++ )
            ++built_in_array [i];
        for ( int element : built_in_array ) // range-based for loop
            std::cout << element << tab;
        std::cout << nline;
        //
        std::cout << "A library array in practice:" << nline << tab;
        std::array<int, 3> library_array { 10, 20, 30 };
        for ( int i = 0; i < library_array.size (); i++ ) // Note the easiness of accessing the size of the library array
            ++library_array [i];
        for ( int element : library_array )
            std::cout << element << tab;
        std::cout << nline;
        std::cout << "The same library array passed as argument:" << nline;
        print_library_array ( library_array );
    }
    catch ( const std::exception& )
    {

    }
}


void print_simple_array_of_characters ( char arg [], int length )
{
    for ( int n = 0; n < length; n++ )
    {
        std::cout << arg [n]; // printing characters as a word in a loop
    }
    std::cout << Nline << Nline;
}
void _08_01_CharacterSequences ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ character sequences:
        // while string class is a powerful feature to handle and manipulate strings,
        // they can aslo be represented by plain arrays of a character type, since they are also sequences of characters
        // by convention, the end of strings represented in character sequences is signalled by null character with literal value \0.
        // the capacity of the array doesn't need to be fully exhausted.
        ColourCouter ( "~~~~~ Character Sequences:\n", F_bBLUE );
        ColourCouter ( "Since strings are sequences of characters, plain character type arrays can also represent them.\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- initialization of null-terminated character sequences:
        // arrays of characters are ordinary arrays with the same rules, so the initialization can be done just like any other array.
        // the second way to initialize an array of character is to directly use string literals.
        // string literals, as introduced earlier, are specified by enclosing the text in double quotes (").
        // string literals or literal constants are of type null-terminated arrays of characters, this means that null character automatically appear at the end of their strings.
        // note that the talk here is about the initialization of the arrays in the declaration time.
        // in fact because the string literals are regular arrays, they have the same restriction,
        // therefore they can only be used at declaration time.
        // to assign a new value to an array containing a sequence of character, each element of the array needs to be assigned a value separately.
        ColourCouter ( "----- Initialization of null-terminated character sequences:\n", F_bBLUE );
        ColourCouter ( "Arrays of characters and their different initializations.\n\n", F_YELLOW );
        // normal initialization of a null-terminated character sequence using an array (needs null character at the end)
        char the_word_hello_1 [] { 'H','e','l','l','o','\0' };
        // initialization of a null-terminated character sequence with a string literal using an array
        char the_word_hello_2 [] { "How are you?" };
        std::cout << "First array's string (initialized normally):" << nline << tab;
        print_simple_array_of_characters ( the_word_hello_1, 6 );
        std::cout << "Second array's string (initialized by string literals):" << nline << tab;
        print_simple_array_of_characters ( the_word_hello_2, 13 );
        the_word_hello_1 [0] = 'B';
        the_word_hello_1 [1] = 'y';
        the_word_hello_1 [2] = 'e';
        the_word_hello_1 [3] = '\0';
        std::cout << "New string assigned to each elements of first array is:" << nline << tab;
        print_simple_array_of_characters ( the_word_hello_1, 4 );

        //! ####################################################################
        //! ----- strings and null-terminated character sequences:
        // C-strings describe plain arrays with null-terminated character sequences, which is the typical types to represents strings in C language.
        // natural way to represent strings in C++ language is still C-strings,
        // therefore string literals still always produce null-terminated character sequences and not string objects.
        // both representations for strings (C-string and library string) coexist in standard library, and most functions with strings requirement are overloaded to support both.
        // for example: cin and cout both support null-terminated sequences directly (direct extraction and insertion just like strings).
        // the main difference between C-strings and library strings:
        // arrays have fixed size that need to be specified either implicit or explicitly in the declaration time (the size of arrays is determined on compilation)
        // while no size specified, strings are simply strings, since strings have a dynamic size determined during runtime.
        ColourCouter ( "----- Strings and null-terminated character sequences:\n", F_bBLUE );
        ColourCouter ( "In standard library both representations of strings (C-string and library string) coexist.\n\n", F_YELLOW );
        ColourCouter ( "A demonstration that use both representations:\n", F_bYELLOW );
        char question_1 [] { "What is your name?" };
        std::string question_2 { "Where do you live?" };
        char answer_1 [80];
        std::string answer_2;
        std::cout << question_1 << nline << tab << "- ";
        std::cin >> answer_1;
        std::cout << question_2 << nline << tab << "- ";
        std::cin >> answer_2;
        std::cout << nline << "Hello, " << answer_1 << " from " << answer_2 << "!" << nline << nline;

        //! - in addition:
        // in any case, null- terminated character sequences and strings are easily transformed from and to one another.
        // null-terminated character sequences can be transformed into strings implicitly.
        // transformation of strings into null-terminated character sequences can happen with string's member functions c_str or data and both are equivalent.
        ColourCouter ( "Null-terminated character sequences and strings are easily transformed from or to one another.\n", F_bYELLOW );
        char a_c_string [] { "some text" };
        std::string a_string = a_c_string; // implicit transformation into library string
        std::cout << "A string in C-string representation:" << "\t\t\t\t\t" << a_c_string << nline;
        std::cout << "The same string transformed into library string representation:" << "\t\t" << a_string << nline;
        std::cout << "The same string inserted as C-string representation by using c_str:" << tab;
        std::cout << a_string.c_str () << nline; // print as a C-string
        std::cout << "The same string inserted as C-string representation by using data:" << tab;
        std::cout << a_string.data () << nline << nline; // print as a C-string
    }
    catch ( const std::exception& )
    {

    }
}


void _09_01_PointersBasics ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ Pointers:
        // variables identifiers give to program the ability to access locations in memory, without the need to care about the physical address of the data in the memory.
        // for a C++ program, succession of memory cells, each one byte in size and with a unique address is known as memory.
        // the order of these memory cells allows the data representations larger than one byte to occupy memory in cells with consecutive addresses.
        // the locations of these cells can easily located by the means of their unique addresses.
        // declaration of a variable provides needed memory for its value on a specific location with a unique address.
        // active decision on the exact storage address of a variable is fortunately left to the environment (generally an OS) where the C++ program runs, and it happens on runtime.
        // it may be useful for a C++ program to obtain the exact address of a variable in the runtime to access the relevant data cells at a certain position, which happens with the help of pointers.
        ColourCouter ( "~~~~~ Pointers:\n", F_bBLUE );
        ColourCouter ( "To obtain the address of a variable at runtime in order to access its relative data sells which are at a certain position.\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- reference operator (&):
        // the ampersand sign (&) preceding the variable identifier can be used to obtain the address of it.
        // pointers are a kind of variable that can store the address of other variables.
        // for a language like C++ with a lot of uses in low-level programming pointers are a powerful feature.
        // Note reference operator (&) itself can be read as "address of"
        ColourCouter ( "----- Reference operator:\n", F_bBLUE );
        ColourCouter ( "The reference operator (&) can be used to obtain the address of the variable identifier.\n\n", F_YELLOW );
        int variable { 25 };
        int* pointer { &variable }; // declaring and assigning the address of a variable to a pointer
        int variable2 = variable; // normal assignment
        std::cout << "Stored address of the variable in the pointer is:" << tab << pointer << nline << nline;

        //! ####################################################################
        //! ----- dereference operator (*):
        // to give it a more simple description, pointers point to the variable whose address they store.
        // an interesting property of pointers is, that by preceding the pointer identifier with asterisk sign (*),
        // pointers can be used to access the variable they point to directly.
        // Note dereference operator itself (*) can be read as "value pointed to by"
        // since reference and dereference operators are complementary, identified opposite meaning to know is:
        // an address obtained with ampersand (&) can be dereferenced with asterisk (*)
        ColourCouter ( "----- Dereference Operator (*):\n", F_bBLUE );
        ColourCouter ( "The dereference operator can be used to access the variable directly which the pointers point to.\n\n", F_YELLOW );
        variable2 = *pointer; // 'variable2' equal to value pointed to by 'pointer'
        std::cout << "The value pointed to by the pointer and accessed directly by the dereference operator is: " << variable2 << nline << nline;

        //! ####################################################################
        //! ----- declaring pointers:
        // when it comes to different types of variable, a pointer has different properties,
        // due to its ability to directly refer to the value of the variable it points to.
        // the type needs to be known for dereferencing and it can happens in the moment of declaration of the pointer.
        // Note syntax: type* name;
        // the type is not the type of the pointer itself but the type of the data pointed to.
        // asterisk (*) in declaration is just a part of the pointer's type compound specifier,
        // therefore it is to be differentiate with dereference operator.
        // all pointers types likely to occupy the same amount of memory, since the pointer size in memory depends on the platform where the program runs.
        ColourCouter ( "----- Declaring Pointers:\n", F_bBLUE );
        ColourCouter ( "Different properties of the pointers when they directly refer to the values of variables justify the need to declare them with the needed specified data type.\n\n", F_YELLOW );

        int* number;
        char* character;
        double* decimal;

        //! - in addition:
        // an example:
        // setting values to variables indirectly through pointers (using the memory location addresses of variables)
        // a pointer can point to different variables during its life time.
        int firstValue, secondValue;
        int* myPointer;
        myPointer = &firstValue;
        *myPointer = 10; // assigning a value to the variable pointed by the pointer
        myPointer = &secondValue;
        *myPointer = 20; // the same
        ColourCouter ( "Indirectly setting values to variables through pointers.\n", F_bYELLOW );
        std::cout << "The value of firstValue is:" << tab << firstValue << nline;
        std::cout << "The value of secondValue is:" << tab << secondValue << nline << nline;

        //! - in addition:
        // when declaring multiple pointers, each individual one needs an asterisk (*) in its declaration.
        // spaces aren't matter and it is even better to declare each pointer in a different statement.
        // to get familiar with the way to read each statement, pay attention to their following comments.
        ColourCouter ( "A more elaborated demonstration on setting new values:\n", F_bYELLOW );
        firstValue = 5; secondValue = 15;
        std::cout << "First value is:" << "\t\t" << firstValue << nline << "Second value is:" << tab << secondValue << nline << nline;
        int* p1, *p2; // asterisk (*) for each pointer -due to the precedence rules-
        p1 = &firstValue;  // address of
        p2 = &secondValue; // the same
        *p1 = 10;          // value pointed to by
        *p2 = *p1;         // the same
        p1 = p2;           // assignment of pointers values (the addresses)
        *p1 = 20;          // value pointed to by
        std::cout << "Indirectly modified values through pointers are:" << nline;
        std::cout << "First value is:" << "\t\t" << firstValue << nline << "Second value is:" << tab << secondValue << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _09_02_PointersAndTypes ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- pointers and arrays:
        // the concepts of arrays and pointers are related, and they work very much like each other to their first elements.
        // implicitly the conversion of an array to a pointer of the proper type is possible.
        // whereas 'theArray' can never be assigned anything and will always represent the same block of 20 elements of type int.
        ColourCouter ( "----- Pointers and arrays\n", F_bBLUE );
        ColourCouter ( "Concepts of arrays and pointers are related.\n\n", F_YELLOW );
        int theArray [20];
        int* thePointer;
        // after the next assignment, the array and the pointer are equivalent with very similar properties.
        // main difference is the possibility of new assignment of a different address to the pointer.
        thePointer = theArray; // valid
        //theArray = thePointer; // not valid

        //! - in addition:
        // example: mixing arrays and pointers
        // the same set of operations with the same meaning are supported with both pointers and arrays.
        // as already explained brackets ([]) specify the index of an element of an array.
        // these brackets known as offset operator are in fact a dereferencing operator,
        // therefore they dereference the variable they follow like the operation of asterisk (*) to the variable it precedes,
        // and in addition they add the number between the brackets to the address.
        // for example:
        //a[5]=0; // a [offset of 5]
        //*(a+5)=0; // pointed to by (a+5)
        // no matter 'a' is an array or a pointer, these two expressions are equivalent and valid.
        // in case of an array, the array identifier refers to first element, just like a pointer.
        int numbers [10];
        int* p;
        p = numbers;
        *p = 10;
        p++; *p = 20;
        p = &numbers [2]; *p = 30;
        p = numbers + 3; *p = 40;
        p = numbers; *( p + 4 ) = 50;
        std::cout << "The values set to the array using pointers are (array way print):" << nline << tab;
        for ( int i = 0; i < 5; i++ )
        {
            std::cout << numbers [i] << tab; // array way
        }
        std::cout << nline << "The values set to the array using pointers are (pointer way print):" << nline << tab;
        for ( int i = 0; i < 5; i++ )
        {
            std::cout << *( p + i ) << tab; // pointer way
        }
        std::cout << nline << nline;

        //! ####################################################################
        //! ----- pointer initialization:
        // the initialization of pointers can be introduced at the very moment of their declaration.
        // what is going to be initialized is the address to be pointed to and never the value stored in memory.
        // pointers can be initialized not only to the address of a variable, but also to the value of another pointer or array.
        ColourCouter ( "----- Pointer Initialization:\n", F_bBLUE );
        ColourCouter ( "Like variables initialization of pointers can be done at the moment of declaration.\n\n", F_YELLOW );
        int myVar { 0 };            // a variable
        int* myPtr1 = &myVar; // point to address of variable
        int myArr [31] { 0 };     // an array
        int* myPtr2 = myPtr1; // point to the value of a pointer
        int* myPtr3 = myArr;  // point to an array
        std::cout << "First pointer's value and pointed value (points to a variable) are:" << nline << tab << myPtr1 << tab << *myPtr1 << nline;
        std::cout << "Second pointer's value and pointed value (points to first pointer) are:" << nline << tab << myPtr2 << tab << *myPtr2 << nline;
        std::cout << "First pointer's value and pointed value (points to an array) are:" << nline << tab << myPtr3 << tab << *myPtr3 << nline << nline;

        //! ####################################################################
        //! ----- pointer arithmetics:
        // when conduction arithmetical operations on pointers, there are these differences to pay attention to:
        // first of all only addition and subtraction operations are allowed.
        // even these two allowed operations have slightly different behaviours, since types have different sizes,
        // and this size is going to be added or subtracted to the stored address value in pointers.
        // on the other hand the exact size of data types is also dependent on the system.
        ColourCouter ( "----- Pointer arithmetics:\n", F_bBLUE );
        ColourCouter ( "Arithmetical operations on pointers result in different behaviours and outputs than regular integer types.\n\n", F_YELLOW );
        char Char { 'A' };
        char* ptrChar { &Char };
        short Short { 4454 };
        short* ptrShort { &Short };
        long Long { 44544454 };
        long* ptrLong { &Long };
        std::cout << "The address values and the values pointed to before the addition:" << nline;
        std::cout << "myChar is:" << tab << ptrChar << tab << *ptrChar << nline;
        std::cout << "myShort is:" << tab << ptrShort << "\t\t\t\t" << *ptrShort << nline;
        std::cout << "myLong is:" << tab << ptrLong << "\t\t\t\t" << *ptrLong << nline;
        ++ptrChar;
        ++ptrShort;
        ++ptrLong;
        std::cout << "The address values and the values pointed to after the addition:" << nline;
        std::cout << "myChar is:" << tab << ptrChar << tab << *ptrChar << nline;
        std::cout << "myShort is:" << tab << ptrShort << "\t\t\t\t" << *ptrShort << nline;
        std::cout << "myLong is:" << tab << ptrLong << "\t\t\t\t" << *ptrLong << nline << nline;

        // combinations: dereference operator with both prefix or postfix versions of increment or decrement operators
        // increment/decrement operator: higher priority (left-to-right)
        // reference/dereference operator: lower priority (right-to-left)
        // as always parenthesis reduce confusion and add legibility to expressions.
        // postfix: *p++ = *q++;   is roughly equivalent to:   *p = *q; ++p; ++q;
        ColourCouter ( "Four possible combinations of dereference operator with both prefix or postfix versions of increment or decrement operators:\n", F_bYELLOW );
        int ptrVar { 4454 };
        int* ptr;
        int temp;
        std::cout << "The stored value in the variable is:" << tab << ptrVar << nline;
        ColourCouter ( "The temp variable is storage of each operation, so it could be shown.\n\n", F_bCYAN );
        ptr = &ptrVar;
        std::cout << "ptr value is:" << "\t\t\t\t" << ptr << nline;
        temp = *ptr++;   // same as *(ptr++): increment pointer, and dereference un-incremented address
        std::cout << "ptr after incrementation *ptr++ is:" << tab << ptr << nline;
        std::cout << "result of incrementation *ptr++ is:" << tab << temp << nline << nline;
        //
        ptr = &ptrVar;
        std::cout << "ptr value is:" << "\t\t\t\t" << ptr << nline;
        temp = *++ptr;   // same as *(++p): increment pointer, and dereference incremented address
        std::cout << "ptr after incrementation *++ptr is:" << tab << ptr << nline;
        std::cout << "result of incrementation *++ptr is:" << tab << temp << nline << nline;
        //
        ptr = &ptrVar;
        std::cout << "ptr value is:" << "\t\t\t\t" << ptr << nline;
        temp = ++*ptr;   // same as ++(*p): dereference pointer, and increment the value it points to
        std::cout << "ptr after incrementation ++*ptr is:" << tab << ptr << nline;
        std::cout << "result of incrementation ++*ptr is:" << tab << temp << nline << nline;
        //
        ptr = &ptrVar;
        std::cout << "ptr value is:" << "\t\t\t\t" << ptr << nline;
        temp = ( *ptr )++; // dereference pointer, and post-increment the value it points to.
                         // without parenthesis the incrementation happens to the pointer itself too.
        std::cout << "ptr after incrementation (*ptr)++ is:" << tab << ptr << nline;
        std::cout << "result of incrementation (*ptr)++ is:" << tab << temp << nline << nline;

    }
    catch ( const std::exception& )
    {

    }
}


void increment_all_PointersUsed ( int* start, int* stop )
{
    int* current = start;
    while ( current != stop )
    {
        ++( *current );
        ++current;
    }
}
void print_all_ConstantPointersUsed ( const int* start, const int* stop )
{
    const int* current = start;
    while ( current != stop )
    {
        std::cout << *current << Tab;
        ++current;
    }
    std::cout << Nline << Nline;
}
void _09_03_PointersAndLiterals ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- pointers and constants:
        // to access variables by pointers read-only, it is enough to qualify the type pointed to as constant.
        // pointers to non-const are implicitly convertible to pointers to constant, but as a safety feature, the other way around isn't possible.
        ColourCouter ( "----- Pointers and Constants:\n", F_bBLUE );
        ColourCouter ( "To access a variable for just reading purposes, not modifying.\n\n", F_YELLOW );
        int x;
        int y { 10 };
        const int* const_ptr { &y }; // points to a variable but in a constant-qualified manner
                                     // allowed (non-const type (address of) to constant):
                                     // the type of y is int* and is assigned to a pointer of type constant int*.
        x = *const_ptr; // ok: reading p
        //*const_ptr = x; // error: modifying constant-qualified
        std::cout << "The value accessed by a constant-qualified pointer is:" << tab << x << nline << nline;

        //! - in addition:
        // one of the use cases: function parameters can include pointers to constant elements to prevent modifications on the passed arguments.
        // to be more clear: pointers that are constant type qualified (point to constant content), can still point to new addresses, but they can not modify the pointed content.
        ColourCouter ( "Two functions with normal and constant-qualified pointers as parameters:\n", F_bYELLOW );
        int numbers_array [] { 10,20,30 };
        std::cout << "The array elements are:" << nline << tab;
        for ( int i = 0; i < 3; i++ )
        {
            std::cout << numbers_array [i] << tab;
        }
        std::cout << nline << nline;
        std::cout << "The array elements after execution of the functions are:" << nline << tab;
        increment_all_PointersUsed ( numbers_array, numbers_array + 3 );
        print_all_ConstantPointersUsed ( numbers_array, numbers_array + 3 );

        //! - in addition:
        // constant pointers:
        // a second dimension to the constness of pointers is that the pointers themselves can also be constant.
        // to define a pointer as constant the 'const' keyword needs to be appended to the pointed type (after the asterisk).
        // the syntaxes concerning pointers and their constant aspects are tricky,
        // therefore it needs a grow experience to recognise best suited use cases.
        // a sooner deep understanding of constness, pointers and references is of course better.
        ColourCouter ( "Pointers themselves can also be constant.\n", F_bYELLOW );
        int x_var { 0 };
        int         *       ptr1 { &x_var }; // non-const pointer to non-const int
        const int   *       ptr2 { &x_var }; // non-const pointer to constant int
        int         * const ptr3 { &x_var }; // constant pointer to non-const int
        const int   * const ptr4 { &x_var }; // constant pointer to constant int
        std::cout << "The value of variable referenced four times:" << "\t\t" << *ptr1 << tab << *ptr2 << tab << *ptr3 << tab << *ptr4 << nline;

        //! - in addition:
        // the above syntaxes get even more complex by considering,
        // that the pointed type can either be preceded or followed by the constant qualifier and both exact same meaning.
        // the order of constant qualifier like the surrounding spaces of asterisk is simply a matter of style.
        // on the internet the discussion on the merits of each still goes on intensely.
        const int* ptr5 { &x_var }; //      non-const pointer to constant int
        int const* ptr6 { &x_var }; // also non-const pointer to constant int
        std::cout << "The value of variable referenced again two times:" << tab << *ptr5 << tab << *ptr6 << nline << nline;


        //! ####################################################################
        //! ----- pointers and string literals:
        // additional to direct insertion into cout, initialization of strings and arrays of character,
        // string literals can be accessed directly by pointers.
        // another description: arrays of proper array type to contain all its character plus null-character and each element of type constant char.
        // each element of a character sequence is accessible by a pointer that point to the sequence, exactly like it is accessible using the same array way.
        // this is because of the before described fact, that arrays and pointers behave essentially the same way in expressions.
        ColourCouter ( "----- Pointers and string literals:\n", F_bBLUE );
        ColourCouter ( "By using pointers string literals can be accessed directly.\n\n", F_YELLOW );
        const char* Ptr_StrLit { "Hello!" }; // a pointer pointed to an array of respected literal representation
        std::cout << "Accessing a character sequence directly in usual array and pointers way:" << nline << tab;
        for ( int i = 0; i <= 5; i++ )
        {
            std::cout << Ptr_StrLit [i]; // accessing in usual array way
            if ( Ptr_StrLit [i] != '!' )
                std::cout << '_';
        }
        std::cout << "\t\t";
        for ( int i = 0; i <= 5; i++ )
        {
            std::cout << *( Ptr_StrLit + i ); // accessing in usual pointer way
            if ( *( Ptr_StrLit + i ) != '!' )
                std::cout << '_';
        }
        std::cout << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void increase ( void* data, int p_size )
{
    if ( p_size == sizeof ( char ) )
    {
        char* p_char;
        p_char = static_cast<char*>( data );
        ++( *p_char );
    }
    if ( p_size == sizeof ( int ) )
    {
        int* p_int;
        p_int = static_cast<int*>( data );
        ++( *p_int );
    }
}
void _09_04_MoreOnPointers ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- pointers to pointers:
        // C++ provides the use of pointers that point to pointers.
        // the result is a defined pointer that in different levels of indirection points to data or even other pointers.
        // the declaration syntax simply requires an additional asterisk for each level of indirection.
        ColourCouter ( "----- Pointers to pointers:\n", F_bBLUE );
        ColourCouter ( "In C++ pointers are allowed to point to pointers.\n\n", F_YELLOW );
        int int_var;
        int* int_ptr;
        int** int_ptr_ptr; // a pointer to pointer
                           // useable in three different levels of indirection and each one correspond to a different value.
        int_var = 89;
        int_ptr = &int_var;
        int_ptr_ptr = &int_ptr;
        std::cout << "Pointed values in three different levels of indirection are:" << nline << tab;
        std::cout << int_ptr_ptr << tab; // first level, the address of the pointer to pointer
        std::cout << *int_ptr_ptr << tab; // second level, the address of pointed pointer
        std::cout << **int_ptr_ptr << nline << nline; // third level, the value being pointed by pointed pointer

        //! ####################################################################
        //! ----- void pointers: (a special type of pointer)
        // as already pointed out void represents absence of type,
        // therefore void pointers point to values without any infos about their exact type,
        // therefore also an undetermined length and undetermined dereferencing properties.
        // Note: void pointers great flexibility: being able to point to any type, additionally:
        // void pointers great limitation: absence of direct dereference of pointed data (logical: no type to reference to)
        // to be able to dereference void pointers, they need to be transformed into some other concrete data type.
        // one of void pointers uses may be to pass generic argument as parameters to a function.
        // already described sizeof operator is integrated in C++, returns the size of its argument in bytes,
        // which for non-dynamic data types it is a constant value.
        ColourCouter ( "----- Void pointers:\n", F_bBLUE );
        ColourCouter ( "Void pointers are able to point to values without any infos on their exact types.\n\n", F_YELLOW );
        char a { 'A' };
        int b = 24;
        std::cout << "Values ready to be passed are:" << nline << tab << a << tab << b << nline;
        increase ( &a, sizeof ( a ) );
        increase ( &b, sizeof ( b ) );
        std::cout << "Increased values in the function with a void pointer as parameter are:" << nline;
        std::cout << tab << a << tab << b << nline << nline;

        //! ####################################################################
        //! ----- invalid pointers and null pointers:
        // while pointers are meant to point to valid addresses, they can actually point to any address,
        // including addresses that refer to no valid element like uninitialized variables and non-existent elements of an array.
        // this fact introduces invalid pointers in C++, which means that a pointer can take any address value,
        // no matter whether there actually something is stored or not.
        ColourCouter ( "----- Invalid pointers and null pointers:\n", F_bBLUE );
        ColourCouter ( "In C++ pointers can point to any address values, no matter their storage state.\n\n", F_YELLOW );
        // the two pointer definitions below, while not pointing to any address with value, aren't cause of any compile error.
        // but dereferencing them is a different story and causes runtime error or undefined behaviours
        int* pp; // uninitialized pointer (local variable) (no error)
        int anArray [10];
        int* qq { &anArray [20] }; // element out of bound (no error)
        //std::cout << pp << nline; // error: used without initialization
        std::cout << "The pointed address is (out of bound of the array addresses):" << tab << qq << nline << nline;

        //! - in addition:
        // as in past sections somewhat described: null pointers: pointers can NULL, 0 or nullptr to represent that they point to nowhere.
        // null pointers satisfy the need of explicit point to nowhere, and not just an invalid address.
        // all null pointers compare equal to other null pointers.
        // Note as already described: void pointers: point to somewhere without a specific type
        int* pp2 { 0 };
        int* qq2 { nullptr };
        int* rr { NULL }; // quite usual in old codes: using the defined constant NULL to refer to null pointer value
                         // NULL is defined in several headers of the standard library
                         // it is also defined as an alias of some null pointer constant such as 0 or nullptr
        std::cout << "The pointed addresses of defined null pointers are:" << nline;
        std::cout << tab << pp2 << tab << qq2 << tab << rr << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


int addition_Function ( int a, int b )
{
    return ( a + b );
}
int subtraction_Function ( int a, int b )
{
    return ( a - b );
}
int operation_FunctionCaller ( int x, int y, int ( *FuncToCall ) ( int, int ) )
{
    // calling the wished function using its stored executable address which is passed as argument
    int g;
    g = ( *FuncToCall ) ( x, y );
    return g;
}
void _09_05_PointersToFunctions ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- pointers to functions:
        // in C++ operations with pointers to function are allowed, they point to the executable function code,
        // and their typical uses are to call a function and to pass a function as an argument to another function.
        // pointers arithmetic aren't performable on the pointers to functions.
        // regular function declaration is the source for declaring pointers to function,
        // except that the pointer identifier is followed by an asterisk * and enclosed in parenthesis ().
        // parenthesis are needed and alter the higher precedence of function parameters.
        ColourCouter ( "----- Pointers to functions:\n", F_bBLUE );
        ColourCouter ( "Pointers to functions are introduced to call a function or to pass a function as argument to another function.\n\n", F_YELLOW );
        int a, b, c, d;
        int ( *minus )( int, int ) = subtraction_Function; // a pointer to function (two parameters and direct initialization)
        a = subtraction_Function ( 10, 5 ); // calling the function itself
        b = minus ( 15, 5 ); // calling the pointer to function
        c = operation_FunctionCaller ( 10, 7, addition_Function ); // passing the function itself
        d = operation_FunctionCaller ( 34, c, minus ); // passing the pointer to function
        std::cout << "First result (function itself):" << "\t\t\t" << a << nline;
        std::cout << "Second result (pointer to function):" << "\t\t" << b << nline;
        std::cout << "Third result (passing the function itself):" << tab << c << nline;
        std::cout << "Forth result (passing pointer to function):" << tab << d << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _10_01_DynamicMemory ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ dynamic memory:
        // to this point of tutorial all needed memory was determined by defining the variables before the program execution.
        // there may be cases to determine the memory needs of a program on runtime, like when needed memory depends of user input.
        // for these cases C++ integrates operators 'new' and 'delete' to dynamically allocate memory.
        ColourCouter ( "~~~~~ Dynamic memory:\n", F_bBLUE );
        ColourCouter ( "To allocate memory during runtime, C++ language integrates the operators 'new' and 'delete'.\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- operators new and new[]:
        // operator new is to be used to allocate dynamic memory.
        // Note syntax:
        // pointer = new type
        // pointer = new type [number_of_elements]
        // declaring sequences of more than one elements required to use the second declaration syntax,
        // where the number of elements (an integer value) is to specified within brackets.
        // the result is a pointer to the beginning of the new allocated block of memory.
        ColourCouter ( "----- Operators new and new[]:\n", F_bBLUE );
        ColourCouter ( "The integrated operator new is to be used to allocate dynamic memory.\n\n", F_YELLOW );
        int* ptr1;
        ptr1 = new int; // allocate memory to contain one single element of type int
        *ptr1 = 555;
        std::cout << "The address and value of dynamic allocated memory are:" << nline << tab << ptr1 << tab << *ptr1 << nline;
        // the substantial difference between declaring normal arrays and allocating dynamic memory is,
        // that allocation happens during runtime and the size is any variable value.
        char* ptr2;
        ptr2 = new char [6]; // allocate a block (an array) of char elements
        for ( int i = 0; i <= 5; i++ )
        {
            *( ptr2 + i ) = '$'; // accessing in usual pointer way
        }
        std::cout << "The address of first element of the dynamic allocated memory is:" << nline << tab << ptr2 << nline;
        std::cout << "The elements stored in the allocated memory are:" << nline << tab;
        for ( int i = 0; i <= 5; i++ )
        {
            std::cout << ptr2 [i] << tab; // accessing in usual array way
        } std::cout << nline << nline;

        //! - in addition:
        // the requested dynamic memory is going to be allocated by the system from memory heap.
        // computer memory is a limited resource and can be exhausted,
        // therefore system doesn't guarantee the success of any allocations using operator new.
        // C++ standard mechanisms to check the success of allocation:
        //! first mechanism: handling exceptions
        // when allocation fails, an exception of type bad-alloc is thrown.
        // if this exception isn't handled by a specific handler, the program execution is terminated.
        // an exception of type bad-alloc (even at declaration line) will be thrown when the allocation fails,
        // then this exception is the default one used by the operator new.
        // more on exceptions and handling them is going to come in later sections.
        //! second mechanism: known as 'nothrow'
        // inclusion of the specific nothrow object at declaration line and handling the state of the result pointer,
        // which, after its declaration with this object, when allocation fails, has nullpter as value,
        // and as result program continues its normal execution. 'nothrow' is declared in header <new>.
        // Note despite simplicity 'nothrow' is likely to produce less efficient code than exceptions,
        // since it implies explicit check on pointer value after each and every allocation,
        // thus, unless it is a critical allocation, the exception mechanism is preferred.
        int* ptr3;
        ptr3 = new ( std::nothrow ) int [5] { 0 };
        if ( ptr3 == nullptr )
            std::cout << "Error assigning memory!" << nline;
        else
        {
            std::cout << "The address of first element of the dynamic allocated memory is:" << nline << tab << ptr3 << nline;
            std::cout << "The elements stored in the allocated memory are:" << nline << tab;
            for ( int i = 0; i <= 4; i++ ) { std::cout << ptr3 [i] << tab; } std::cout << nline << nline;
        }

        //! ####################################################################
        //! ----- operators delete and delete[]:
        // since in most cases the allocated memory within a program is only needed during specific periods of time,
        // using operator delete, it can be freed once it is no longer needed, making it available for other requests of dynamic memory.
        // Note syntax:
        // delete pointer;
        // delete[] pointer; (introduction of the number of elements isn't needed and the brackets are enough)
        // second statement is to release the memory allocated for the arrays of elements using new and a size in brackets.
        // argument taken by operator delete is to be a pointer to a dynamic memory block,
        // previously allocated with operator new or a null pointer.
        // if a null pointer is passed as argument, operator delete produces no effect.
        // allocation during runtime is always considered a practice of attention,
        // specially when there is a need that user provides its input amount,
        // therefore a program must be able to handle failures of allocation,
        // not only by catching the proper exception, but also controlling the user input and checking the pointer value.
        ColourCouter ( "----- Operators delete and delete[]:\n", F_bBLUE );
        ColourCouter ( "The integrated operator delete is to be used to free the allocated dynamic memory.\n\n", F_YELLOW );
        std::string _inStr;
        int _number, _index;
        int* _pointer;
        std::cout << "How many numbers would you like to type?" << tab;
        std::getline ( std::cin, _inStr );
        std::stringstream ( _inStr ) >> _number;
        while ( _number > 10 )
        {
            std::cout << "Come on! You don't want to enter so many numbers! Think and try again. :)" << tab;
            std::getline ( std::cin, _inStr );
            std::stringstream ( _inStr ) >> _number;
        }
        if ( _number > 5 )
            std::cout << "Really? You do want to enter so many numbers? :| OK!" << nline;
        _pointer = new( std::nothrow ) int [_number]; // entered by the user and not a constant
        if ( _pointer == nullptr )
            std::cout << nline << "Error: memory couldn't be allocated!" << nline;
        else
        {
            std::cout << nline;
            for ( _index = 0; _index < _number; _index++ )
            {
                std::cout << "Enter number:" << tab;
                //std::cin >> _pointer [_index]; // pointer way: *(_pointer + _index)
                std::getline ( std::cin, _inStr );
                std::stringstream ( _inStr ) >> _pointer [_index]; // pointer way: *(_pointer + _index)
            }
            std::cout << nline << "You have entered:" << nline << tab;
            for ( _index = 0; _index < _number; _index++ )
                std::cout << _pointer [_index] << tab; // pointer way: *(_pointer + _index)
            std::cout << nline << nline;
            delete [] _pointer;
        }

        //! - in addition:
        // dynamic memory in C language
        // operators new and delete are integrated in C++,
        // on the other hand C language uses library solution with the functions malloc, calloc, realloc and free,
        // defined in header <cstdlib> known as <srdlib.h> in C language,
        // and they are also available and usable to allocate and deallocate dynamic memory in C++.
        // Note, mixing blocks allocated with these functions and those of integrated C++ operators isn't possible,
        // since their results aren't necessarily compatible,
        // so each result should be handled with the suitable set of functions and operators.
    }
    catch ( const std::exception& )
    {

    }
}


struct movies_t
{
    std::string title;
    int year;
} mine; // optional field object_names in practice
void printMovie ( movies_t movie )
{
    std::cout << movie.title << " (" << movie.year << ")" << Nline;
}
void _11_01_DataStructures ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ data structures:
        // groups of data elements known as members with different types and different lengths under defined names.
        // Note syntax:
        // struct type_name {
        // member_type1 member_name1;
        // member_type2 member_name2;
        // .
        // .
        // } object_names;
        // 
        // optional object_names field: a set of valid identifiers (objects) to have the type of this structure.
        // after specifying object_names field, the field type_name becomes optional,
        // that is, in declaration either a type_name or at least one object_name is needed, not necessarily both.
        // corresponding members in a data type is the reference type of the members of the object defined using it.
        // declared objects' members using determined structure type can be accessed directly using a dot (.).
        // Note syntax:     object_name.member_name
        // subsequently:    objects' members can be operated with like standard variables of their respective types,
        //                  and the objects of structures can be passed to functions like standard variables.
        // this brings it to one of the features of the data structures, which is the ability to refer to both
        // objects declared of them as whole and to the object members individually using the same identifier.
        ColourCouter ( "~~~~~ Data structures:\n", F_bBLUE );
        ColourCouter ( "To introduce grouped data elements with different types and different lengths under one name.\n\n", F_YELLOW );
        movies_t yours; // after declaration used just like any other type
        std::string strTemp;
        mine.title = "2001 A Space Odyssey";
        mine.year = 1968;
        std::cout << "Enter the title of your favourite movie: ";
        std::getline ( std::cin, yours.title );
        std::cout << "Enter its release year: ";
        std::getline ( std::cin, strTemp );
        std::stringstream ( strTemp ) >> yours.year;
        std::cout << nline << "My favourite movie is:" << nline << tab;
        printMovie ( mine );
        std::cout << "And yours is:" << nline << tab;
        printMovie ( yours );
        std::cout << nline;

        //! - in addition:
        // using structures as type of arrays to construct tables or databases.
        std::cout << "An array with data structure as its type:" << nline;
        movies_t films [3];
        for ( int i = 0; i < 3; i++ )
        {
            std::cout << "Enter title: " << tab;
            std::getline ( std::cin, films [i].title );
            std::cout << "Enter year: " << tab;
            std::getline ( std::cin, strTemp );
            std::stringstream ( strTemp ) >> films [i].year;
        }
        std::cout << nline << "You have entered these movies:" << nline;
        for ( int i = 0; i < 3; i++ )
            printMovie ( films [i] );
        std::cout << nline;

        //! ####################################################################
        //! ----- pointers to structures:
        // structures can be pointed to by their own type of pointers just like any other type.
        // Note the arrow operator (->): exclusive dereference operator of pointers to objects that have members.
        // with other words, this operator create direct access to members of an object using the address.
        // a summarization of possible combinations of operators for pointers and for structure members:
        // --------------------------------------------------------------------------------
        // Expression   What is evaluated                                       Equivalent
        // --------------------------------------------------------------------------------
        // a.b          member b of object a
        // --------------------------------------------------------------------------------
        // a->b         member b of object pointed to by a                      (*a).b
        // --------------------------------------------------------------------------------
        // *a.b         value pointed to by member b (a pointer) of object a    *(a.b)
        // --------------------------------------------------------------------------------
        // Note in case *a.b equivalent to *(a.b) the object member is a pointer type,
        // if not, the evaluation results in accessing a hypothetical pointer member called 'b', which isn't the case.
        ColourCouter ( "----- Pointers to structures:\n", F_bBLUE );
        ColourCouter ( "Structures can be pointed to by their own type of pointers.\n\n", F_YELLOW );
        movies_t aMovie_t;
        movies_t* ptrMovie_t;
        ptrMovie_t = &aMovie_t;
        std::cout << "Accessing movie structure using pointers:" << nline;
        std::cout << "Enter title: " << tab;
        std::getline ( std::cin, ptrMovie_t->title ); // for all purposes, equivalent to: (*ptrMovie_t).title
        std::cout << "Enter year: " << tab;
        std::getline ( std::cin, strTemp );
        std::stringstream ( strTemp ) >> ptrMovie_t->year;
        std::cout << nline << "You have entered:" << tab;
        std::cout << ptrMovie_t->title << " (" << ptrMovie_t->year << " )" << nline << nline;

        //! ####################################################################
        //! ----- nesting structures:
        // elements of a structure can also be of structure type, the result is then a nested structure.
        ColourCouter ( "----- Nesting structures:\n", F_bBLUE );
        ColourCouter ( "To introduce elements in a structure that themselves are also structures.\n\n", F_YELLOW );
        struct friends_t
        {
            std::string name;
            std::string email;
            movies_t favorite_movie;
        } maria, charlie;
        friends_t* ptrFriend_t = &charlie;
        maria.name = "Marie";
        maria.email = "maria@gmail.com";
        maria.favorite_movie.title = "The Matrix";
        maria.favorite_movie.year = 1999;
        charlie.name = "Charlie";
        ptrFriend_t->email = "charlie@gmail.com";
        charlie.favorite_movie.title = "Blade Runner";
        charlie.favorite_movie.year = 1982; // equivalent to next expression
        ptrFriend_t->favorite_movie.year = 1982; // equivalent to next expression
        ( *ptrFriend_t ).favorite_movie.year = 1982;
        ColourCouter ( "A demonstration of a nested structure:\n", F_bYELLOW );
        std::cout << "Maria and Charlie's favourite movies are:" << nline;
        std::cout << maria.name << nline;
        std::cout << tab << maria.email << nline << tab;
        printMovie ( maria.favorite_movie );
        std::cout << charlie.name << nline;
        std::cout << tab << ptrFriend_t->email << nline << tab;
        printMovie ( ( *ptrFriend_t ).favorite_movie );
        std::cout << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _12_01_OtherDataTypes ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ other data types:
        // 
        ColourCouter ( "~~~~~ Other data types:\n", F_bBLUE );
        ColourCouter ( "This section introduces some expansions on compound data types.\n\n", F_YELLOW );

        //! ####################################################################
        //! ----- type aliases (typedef / using):
        // in C++ valid fundamental or compound types can be aliased.
        // that is to provide the ability to refer to them with another identifier.
        // after definition, aliases can be used in any declaration like any other valid type.
        // Note first syntax (inherited from C language):
        // typedef existing_type new_type_name;
        // Note second syntax (introduced in C++):
        // using new_type_name = exising_type;
        // both definition syntaxes are semantically equivalent, but typedef has certain limitation in sphere of templates,
        // and also has a longer history, therefore probably more common in existing code.
        // Note type aliases most useful purpose is as tools to separate programs from their underlying types,
        // for example to easily replace the program types in a later version.
        // another purpose is to reduce the length of long or confusing type names.
        ColourCouter ( "----- Type aliases (typedef / using):\n", F_bBLUE );
        ColourCouter ( "To introduce different identifiers as alias for any valid type.\n\n", F_YELLOW );
        typedef char C; // obvious
        typedef unsigned int WORD; // WORD is alias for unsigned int
        typedef char* pChar; // pChar is alias for char*
        typedef char field [50]; // Note field is alias for char [50]
        C myChar { 'A' }, anotherChar { 'B' }, *pTc1 { &myChar };
        WORD myWord { 111 };
        pChar ptc2 { &anotherChar };
        field name { "Mehrdad" };
        using C2 = char;
        using WORD2 = unsigned int;
        using pChar2 = char*;
        using field2 = char [50];

        //! ####################################################################
        //! ----- unions:
        // C++ introduce unions to access one portion of memory shared between different data types.
        // while similar declaration to structures, the functionality of unions is totally different.
        // Note syntax:
        // union type_name {
        // member_type1 member_name1;
        // member_type2 member_name2;
        // .
        // .
        // } object_names;
        // all members of new union type, declared by the syntax above and identified by its type_name,
        // occupy the same physical space in memory, which size is the size of the largest member element.
        // repeating it with other words, modification of one union member affects all the members
        // therefore no member of an union has an independent space for storing different values.
        ColourCouter ( "----- Unions:\n", F_bBLUE );
        ColourCouter ( "To share one portion of memory between members with different date types.\n\n", F_YELLOW );
        union myTypes_t
        {
            char c;
            int i;
            float f;
        } myTypes;
        myTypes.c = 'A';

        //! - in addition:
        // one interesting purpose of unions is to access a value both ways,
        // that is, in its entirety or as an array or structure of similar elements.
        // the example below explains it more precise.
        // Note this feature is likely to create portability issues,
        // since the exact alignment and order of union members in memory is system dependent.
        std::cout << "Accessing an union in its entirety, as structure and as array:" << nline;
        union mix_t
        {                               // assumptions (as already explained fundamental type sizes are system dependent):
            int int_allBytes;           // 4 byte (entirety access)
            struct
            {
                short short_highBytes;  // 2 byte (access in structure form)
                short short_lowBytes;   // 2 byte
            } struct_highLow;
            char char_Bytes [4];        // 4*1 byte (access in array form)
        } mix;
        mix.int_allBytes = 0x11111111;
        std::cout << "In entirety:" << "\t\t\t" << mix.int_allBytes << nline;
        std::cout << "Low and high bytes (structure):" << tab << mix.struct_highLow.short_highBytes << tab << mix.struct_highLow.short_lowBytes << nline;
        std::cout << "Byte by Byte (array):" << "\t\t";
        for ( unsigned char i = 0; i < 4; i++ )
        {
            std::cout << mix.char_Bytes [i] << tab;
        }
        std::cout << nline << nline;

        //! ####################################################################
        //! ----- anonymous unions:
        // an union can be defined with no name, if its declaration happens within a class or structure.
        // after declaring an union anonymous, its members are accessible from objects by member names.
        // as already explained, an union share a space between its members.
        ColourCouter ( "----- Anonymous unions:\n", F_bBLUE );
        ColourCouter ( "By declaring an union without any name in a class or structure, they become anonymous unions.\n\n", F_YELLOW );
        struct book_t
        {
            char title [50];
            char author [50];
            union
            {
                float dollar;
                int yen;
            } price; // a normal union
            union
            {
                float dollar;
                int yen;
            }; // an anonymous union
        } book;
        book.price.dollar = 3.4;
        book.dollar = 3.4;
        std::cout << "The value is (normal union):" << tab << book.price.dollar << nline;
        std::cout << "The value is (anonymous union):" << tab << book.dollar << nline << nline;

        //! ####################################################################
        //! ----- enumerated types (enum):
        // a set of custom identifiers, known as enumerators, can be used to define an enumerated type.
        // objects defined using an enumerated type, take its enumerators as possible values.
        // Note syntax:
        // enum type_name {
        // value1
        // value2
        // .
        // .
        // } object_names;
        // the field object_names can be used to directly instantiate objects (variables) of this type
        ColourCouter ( "----- Enumerated types (enum):\n", F_bBLUE );
        ColourCouter ( "To introduce a set of custom identifiers, known as enumerators, as possible values.\n\n", F_YELLOW );
        enum colours_t { black, blue, green, cyan, red, purple, yellow, white }; // a total new data type
        colours_t myColour;
        myColour = blue;
        if ( myColour = green )
            myColour = red;
        std::cout << "The value of 'myColour' variable is:" << nline << tab << myColour << nline;

        //! - in addition:
        // enumerators of an enumerated type declared with enum are always assigned integer values internally,
        // which make it possible to implicitly convert the enumerators to and from these integer values.
        // if not explicitly specified, the first enumerator's internal integer value is zero (0).
        // the following values then get plus one, each one after another.
        // it is also possible to assign arbitrary integer values to enumerators.
        enum months_t
        {
            January = 1, February, March, April,
            May, June, July, August,
            September, October, November, December
        } y2k;
        y2k = January;
        int val { y2k };
        std::cout << "The values of variables are:" << nline << tab << y2k << tab << val << nline << nline;

        //! ####################################################################
        //! ----- enumerated types with enum class:
        // in C++, real enum types can be created with enum class (or enum struct),
        // to preserve safety, the enumerator values are of the enum type itself,
        // therefore lacking enumerator values of type int, the conversion to int isn't possible.
        // each enumerator value of an enum class is accessible only with scoping into its type,
        // this way of access is also available in normal enum types, but it is just optional.
        // enum class declared enumerated types have more control over their underlying type,
        // which can be any integral data type such as char, short, unsigned int,
        // and essentially serves to determine the size of the enumerated type.
        // Note full syntax:
        // enum class type_name : underlying_type {
        // value1
        // value2
        // .
        // .
        // } object_names;
        ColourCouter ( "----- Enumerated types with enum class:\n", F_bBLUE );
        ColourCouter ( "To introduce real enum types that preserve safety.\n\n", F_YELLOW );
        enum class Colours { black, blue, green, cyan, red, purple, yellow, white };
        Colours myColour2;
        myColour2 = Colours::blue; // the needed scoping into the type
        if ( myColour2 == Colours::green )
            myColour2 = Colours::red;
        std::cout << "The value of 'myColour2' variable is:" << nline << tab << static_cast<int>( myColour2 ) << nline;
        enum class EyeColour : long { blue, green, brown }; // + underlying type (a distinct type of the 'char' size)
        std::cout << "The size of 'EyeColour' type is:" << nline << tab << sizeof ( EyeColour ) << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}