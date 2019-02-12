// --------------------------------------------------------------------------------
/// <summary>
/// _4_CompoundDataTypes.cpp
/// </summary>
/// <created>ʆϒʅ,30.05.2018</created>
/// <changed>ʆϒʅ,12.02.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "ConsoleAdjustments.h"


#define Tab '\t'
#define Nline '\n'

const char tab { '\t' };
const char nline { '\n' };


void _7_1_Arrays ()
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
    for ( int n = 0; n < length; n++ )
    {
        std::cout << arg [n];
        if ( arg [n] < 9 ) std::cout << "   "; else std::cout << "  ";
    }
    std::cout << Nline;
}
void _7_2_InitializingArrays ()
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
        std::cout << "The elements of an array with explicit initialization:" << "\t\t\t";
        print_simple_array ( array2, 5 );
        std::cout << "The remaining uninitialized elements of an array:" << "\t\t\t";
        print_simple_array ( array3, 5 );
        std::cout << "Initialization of an array with default values of its elements:" << "\t\t";
        print_simple_array ( array4, 5 );
        std::cout << "Assuming the size of an array automatically:" << "\t\t\t\t";
        print_simple_array ( array5, 5 );
        std::cout << "Declaring an array with the use of universal initialization:" << "\t\t";
        print_simple_array ( array6, 5 );
        std::cout << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void _7_3_AccessingValues ()
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
        std::cout << "The values of the array's elements (automatically initialized):" << "\t\t";
        print_simple_array ( a_array, 5 );
        a_array [0] = 11;
        a_array [2] = 33;
        a_array [4] = 55;
        std::cout << "The values of the array's elements (after assignment):" << "\t\t\t";
        print_simple_array ( a_array, 5 );
        std::cout << nline;

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
        std::cout << "The values of the array's elements (after some valid operation):" << tab;
        print_simple_array ( b_array, 5 );
        int result {};
        for ( int n = 0; n < 5; n++ )
        {
            result += b_array [n];
        }
        std::cout << "Subtraction of all the values of the array's elements:" << "\t\t\t" << result << nline << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void print_bidimensional_array ( int arg [] [5], int width, int height )
{
    for ( int n = 0; n < width; n++ )
    {
        for ( int m = 0; m < height; m++ )
        {
            std::cout << arg [n] [m] << "  ";
        }
        std::cout << Nline;
    }
    std::cout << Nline;
}
void _7_4_MultidimensionalArrays ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- multidimensional arrays:
        // can be described as 'arrays of arrays' for example a bidimensional array can be imagined as a two-dimensional table made of elements, all of them of a same uniform date type.
        // multidimensional arrays are not limited to two indices (i.e. two dimensions), but be careful, thus the amount of memory needed for an array increases exponentially with each dimension.
        // multidimensional arrays are just an abstraction for the programmers, since the same result can be achieved with a simple array, by multiplying its indices.
        // the only difference is that with multidimensional arrays, the compiler automatically remembers the depth of each imaginary dimension.
#define HEIGHT 3 // using defined constants for better readability and easiness of later changes in one place
#define WIDTH 5 // the same
        ColourCouter ( "----- Multidimensional arrays:\n", F_bBLUE );
        ColourCouter ( "Can be described as 'arrays of arrays'.\n\n", F_YELLOW );
        int bidimensional_array [HEIGHT] [WIDTH] {}; // declaration of a bidimensional array of 3 per 5 elements of type int
        bidimensional_array [0] [2] = 13; // to reference to the first element vertically and third horizontally
        std::cout << "Elements of the bidimensional_array:" << nline;
        print_bidimensional_array ( bidimensional_array, HEIGHT, WIDTH );
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
        std::cout << "The multidimensional arrays are just an abstraction for the programmers:" << nline << nline;
        std::cout << "Elements of a bidimensional array:" << nline;
        print_bidimensional_array ( bidimensional_array, HEIGHT, WIDTH );
        std::cout << "Elements of a simple array (achieving the same result):" << nline;
        print_simple_array ( equivalent_simple_array, HEIGHT* WIDTH );
        /*

        */
        //ColourCouter ( "\n", F_bBLUE );
        //ColourCouter ( "\n\n", F_YELLOW );
        //ColourCouter ( "\n", F_bYELLOW );
        //ColourCouter ( "\n", F_bCYAN );
        //! - in addition:
    }
    catch ( const std::exception& )
    {

    }
}


void _7_5_ArraysAsParameters ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- arrays as parameters:
        // in C++ it isn't possible to pass the entire block of memory represented by an array to a function directly as an argument.
        // the address of the array can be passed and in practice this has almost the same effect while being much faster and efficient.
        // to accept an array as parameter for a function, the parameters can be declared as the array type but with empty brackets, omitting the actual size of the array, thus the format is: base_type parameter_name[]
        // example for syntax: void procedure (int arg[])  --accepts a parameter of type 'array of int'
        std::cout << "----- Arrays as parameters:" << nline;
        std::cout << "In C++ the address of an array can be passed to a function." << nline << nline;
        int first_array [] { 5, 10, 15 };
        int second_array [] { 2, 4, 6, 8, 10 };
        std::cout << "Passing arrays as arguments to an earlier used function:" << nline << nline;
        print_simple_array ( first_array, 3 );
        print_simple_array ( second_array, 5 );

        // in a function declaration it is also passible to include multidimensional arrays.
        // the format for a tridimensional array is: base_type parameter_name[] [depth] [depth]
        // example for syntax: void procedure (int myarray[][3][4])
        // notice that the first brackets is empty, while the following ones specify sizes for their respective dimensions. this is necessary in order for the compiler to be able to determine the depth of each additional dimension.
        // in a way, passing an array as argument always loses a dimension. the reason behind is that, for historical reasons, arrays can not be directly copied, and thus what is really passed is a pointer. a clear understanding of pointer in the pointer section helps a lot.
        int another_array [2] [5] { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
        std::cout << "Passing a bidimensional array as the argument of an earlier used function:" << nline << nline;
        print_bidimensional_array ( another_array, 2, 5 );
    }
    catch ( const std::exception& )
    {

    }
}


void _7_6_LibraryArrays ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ----- library arrays:
        // the arrays explained above are directly implemented as a language features, inherited from the C language.
        // they are a great features, but by restricting its copy and easily decay into pointers, they probably suffer from an excess of optimization.
        // C++ provides an alternative array type as a standard container, to overcome some of these issues with the language built-in arrays. it is a type template (a class template in fact) defined in header <array>.
        // they operate in a similar way as built-in arrays, with the exception that they allow being copied (an actually expensive operation that copies the entire block of memory, and thus to use with care) and decay into pointers only when explicitly told to do so (by means of its member data).
        // the main differences in practice lays on the declaration of the array and the inclusion of an additional header for the library array.
        // classes and containers will be explained later.
        std::cout << "----- Library arrays:" << nline;
        std::cout << "To introduce an alternative for overcoming the issues with the language built-in arrays." << nline << nline;
        int built_in_array [] { 10, 20, 30 };
        std::array<int, 3> library_array { 10, 20, 30 };
        //
        std::cout << "Using the built in arrays:" << nline;
        for ( int i = 0; i < 3; i++ )
            ++built_in_array [i];
        for ( int elem : built_in_array ) // range-based for loop
            std::cout << elem << tab;
        //
        std::cout << nline << nline << "Using the library arrays:" << nline;
        for ( int i = 0; i < library_array.size (); i++ ) // notice the easiness of accessing the size of the library array
            ++library_array [i];
        for ( int elem : library_array ) // range-based for loop
            std::cout << elem << tab;
        std::cout << nline;
    }
    catch ( const std::exception& )
    {

    }
}


void print_simple_array_of_characters ( char arg [], int length )
{
    for ( int n = 0; n < length; n++ )
    {
        std::cout << arg [n]; // print the characters as a word
    }
    std::cout << Nline << Nline;
}
// ********************************************************************************
/// <summary>
/// Character sequences
/// </summary>
/// <created>ʆϒʅ,11.06.2018</created>
/// <changed>ʆϒʅ,25.06.2018</changed>
// ********************************************************************************
void CharacterSequences ()
{
    // the functions used in this section are defined above it.
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ character sequences:
        // the string class is a powerful features to handle and manipulate strings of characters.
        // since strings are also sequences of characters, we can represent them as plain arrays of elements of a character type.
        // the capacity of the array doesn't need to be fully exhausted.
        // by convention, the end of strings represented in character sequences is signalled by the null character, whose literal value can be written as '\0'.
        std::cout << nline << "~~~~~ Character Sequences:" << nline;
        std::cout << "Since strings are sequences of character, a plain array can also be used to represent them." << nline << nline;

        //! ####################################################################
        //! ----- initialization of null-terminated character sequences:
        // since arrays of characters are ordinary arrays, they follow the same rules, and the initialization can also be done just like any other array.
        // arrays of character elements have also another way to be initialized: using sting literals directly
        // string literals are introduced earlier. they are specified by enclosing the text in double quotes (").
        // sequences of characters enclosed in double quotes are literal constants and their type is null-terminated array of characters which means that they have always a null character ('\0') automatically appeared at the end.
        // note that the talk here is about he initialization of the arrays in the declaration time and not assigning values later on after their declaration.
        // in fact because the string literals are regular arrays, they have the same restriction as these and can not be assigned values, but each of their elements can be assigned a value individually.
        std::cout << "----- Initialization of null-terminated character sequences:" << nline;
        std::cout << "Arrays of characters are ordinary arrays and they follow the same rules." << nline << nline;
        char the_word_hello_1 [] { 'H','e','l','l','o','\0' }; // normal initialization
        char the_word_hello_2 [] { "How are you?" }; // the use of string literals in the initialization
        std::cout << "The string stored in the first array which is initialized normally:" << nline << nline;
        print_simple_array_of_characters ( the_word_hello_1, 6 );
        std::cout << "The string stored in the second array which is initialized by using string literals:" << nline << nline;
        print_simple_array_of_characters ( the_word_hello_2, 13 );
        the_word_hello_1 [0] = 'B';
        the_word_hello_1 [1] = 'y';
        the_word_hello_1 [2] = 'e';
        the_word_hello_1 [3] = '\0';
        the_word_hello_1 [4] = '\0';
        the_word_hello_1 [5] = '\0';
        std::cout << "The string stored in the first array after assigning each of its elements a new value:" << nline << nline;
        print_simple_array_of_characters ( the_word_hello_1, 6 );

        //! ####################################################################
        //! ----- strings and null-terminated character sequences:
        // plain arrays with null-terminated character sequences are the typical types to represent strings in the C language (also known as C-strings).
        // in C++ C-strings are a natural way of representing strings in the language. in fact, string literals still always produce null- terminated character sequences, and not string objects.
        // in standard library. both representation for strings (C-string and library string) coexist and most functions requiring strings are overloaded to support both.
        // for example: cin and cout both support null-terminated sequences directly (direct extraction and insertion just like strings).
        // the main difference between C-strings and library strings:
        // arrays have fixed size that need to be specified either implicit or explicitly in the declaration time (the size of arrays is determined on compilation)
        // strings are simply strings and no size is needed to be specified. this is due to the fact that strings have a dynamic size determined during runtime.
        std::cout << "----- Strings and null-terminated character sequences:" << nline;
        std::cout << "In standard library both representations of strings (C-string and library string) coexist." << nline << nline;
        std::cout << "A demonstration that use both representations:" << nline << nline;
        char question_1 [] { "What is your name?" };
        std::string question_2 { "Where do you live?" };
        char answer_1 [80];
        std::string answer_2;
        std::cout << question_1 << nline << tab << "- ";
        std::cin >> answer_1;
        std::cout << question_2 << nline << tab << "- ";
        std::cin >> answer_2;
        std::cout << nline << "Hello, " << answer_1 << " from " << answer_2 << "!" << nline << nline;

        // in any case, null- terminated character sequences and strings are easily transformed from one another.
        // null-terminated character sequences can be transformed into strings implicitly.
        // strings can be transformed into null-terminated character sequences by using either of string's member functions c_str or data and both c_str and data member of string are equivalent
        std::cout << "Null-terminated character sequences and strings are easily transformed from one another." << nline << nline;
        char my_c_string [] { "some text" };
        std::string my_string = my_c_string; // transfer into library string implicitly
        std::cout << "A string in C-string representation:" << tab << my_c_string << nline;
        std::cout << "The same string transformed into library string representation:" << tab << my_string << nline;
        std::cout << "The same string inserted as C-string representation by using c_str:" << tab;
        std::cout << my_string.c_str () << nline; // print as a C-string
        std::cout << "The same string inserted again as C-string representation by using data:" << tab;
        std::cout << my_string.data () << nline; // print as a C-string
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
    std::cout << Nline;
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
int addition_PointerToFunction ( int a, int b )
{
    return ( a + b );
}
int subtraction_PointerToFunction ( int a, int b )
{
    return ( a - b );
}
int operation_PointerToFunction ( int x, int y, int ( *FuncToCall ) ( int, int ) )
{
    // taking the function to be called as a pointer that points to the wished function
    int g;
    g = ( *FuncToCall ) ( x, y ); // the call to the wished function
    return g;
}
// ********************************************************************************
/// <summary>
/// Pointers
/// </summary>
/// <created>ʆϒʅ,25.06.2018</created>
/// <changed>ʆϒʅ,05.09.2018</changed>
// ********************************************************************************
void Pointers ()
{
    // the functions used in this section are defined above it.
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ Pointers:
        // variables which are locations in memory can be accessed by their identifier. this way, the program doesn't need to care about the physical address of the data in the memory.
        // for a C++ program, the memory of a computer is like a succession of memory cells, each one byte in size, and each with a unique address. the order of these one-byte sells is in a way that allows data representation larger than one byte to occupy memory cells that have consecutive addresses.
        // each sell can be easily located in the memory by the means of its unique address.
        // after declaration of a variable, the needed memory for its value to be stored is assigned a specific location in memory (its memory address). generally, C++ programs don't actively decide the exact memory addresses where its variables are stored. fortunately this task is left to the environment (generally an OS) where the program runs and it decides the particular memory locations on runtime.
        // however, it may be useful for a program to be able to obtain the address of a variable in the runtime in order to access the data sells that are at a certain position relative to it.
        std::cout << nline << "~~~~~ Pointers:" << nline;
        std::cout << "To obtain the address of a variable in the runtime in order to access its relative data sells that are at a certain position." << nline << nline;

        //! ####################################################################
        //! ----- reference operator (&):
        // the ampersand sign (&) preceding the variable identifier can be used to obtain the address of it.
        // pointers are a kind of variable that can store the address of another variables. They are a very powerful feature of a language like C++ that has many uses in the low-level programming.
        // more on their declaration and use is going to come later.
        // the operator itself can be read as "address of"
        std::cout << "----- Reference operator:" << nline;
        std::cout << "The reference operator (&) can be used to obtain the address of the variable identifier." << nline << nline;
        int variable { 25 };
        int* pointer { &variable }; // declaring and assigning the address of a variable to a pointer
        int variable2 = variable; // normal assignment
        std::cout << "The address of the variable stored in the pointer is:" << tab << pointer << nline;

        //! ####################################################################
        //! ----- dereference operator (*):
        // pointers are said to "point to" the variable whose address they store.
        // by preceding the pointer name with the asterisk sign (*) pointers can be used to access the variable they point to directly which is an interesting property of them.
        // the operator itself can be read as "value pointed to by"
        // the reference and dereference operators are thus complementary,
        // thus they have opposite meanings: an address obtained with & can be dereferenced with *
        std::cout << nline << "----- Dereference Operator (*):" << nline;
        std::cout << "The dereference operator can be used to access the variable directly which the pointers point to." << nline << nline;
        variable2 = *pointer; // 'variable2' equal to value pointed to by 'pointer'
        std::cout << "The value pointed to by the pointer and accessed directly by the dereference operator is: " << tab << variable2 << nline;

        //! ####################################################################
        //! ----- declaring pointers:
        // due to the ability of a pointer to directly refer to the value that it points to, a pointer has different properties when it points to a char than when it points to an int or a float.
        // once dereferenced, the type needs to be known, and for that, the declaration of pointers also needs the data types which the pointers are going to point to.
        // syntax: type *name;
        std::cout << nline << "----- Declaring Pointers:" << nline;
        std::cout << "Different properties of the pointers when they directly refer to the values justify the need to declare them with the needed specified data type." << nline << nline;

        // the declaration type is not the type of the pointer itself.
        // all pointers are likely going to occupy the same amount of space in memory no matter their declaration type (the size of a pointer in memory depends on the platform where the program runs).
        // the asterisk (*) in the declaration syntax is just a part of the pointer's type compound specifier and means that it is the declaration of a pointer, thus differentiate it with the dereference operator.
        int* number;
        char* character;
        double* decimal;

        // setting a value indirectly by using the memory location address of a variable which is stored in a pointer.
        // a pointer can point to different variables during its life time
        int firstValue, secondValue;
        int* myPointer;
        myPointer = &firstValue;
        *myPointer = 10; // assigning a value to the value pointed by the pointer
        myPointer = &secondValue;
        *myPointer = 20; // the same
        std::cout << "Setting values indirectly through the use of a pointer." << nline;
        std::cout << "The value of firstValue is:" << tab << firstValue << nline;
        std::cout << "The value of secondValue is:" << tab << secondValue << nline << nline;

        // each pointer needs an asterisk (*) in declaration of multiple pointers per statement.
        // it is even better to declare each pointer variable in a different statement.
        // other comments are written to get familiar with the way to read each statement.
        std::cout << "New setted values for a more elaborated demonstration are:" << nline;
        firstValue = 5; secondValue = 15;
        std::cout << "firstValue is:" << tab << firstValue << nline << "secondValue is:" << tab << secondValue << nline;
        int* p1, *p2; // asterisk (*) for each pointer -due to the precedence rules-
        p1 = &firstValue;  // address of
        p2 = &secondValue; // the same
        *p1 = 10;          // value pointed to by
        *p2 = *p1;         // the same
        p1 = p2;           // value of pointers (the addresses)
        *p1 = 20;          // value pointed to by
        std::cout << "Modifying values indirectly through the use of pointers." << nline;
        std::cout << "firstValue is:" << tab << firstValue << nline << "secondValue is:" << tab << secondValue << nline;

        //! ####################################################################
        //! ----- pointers and arrays:
        // the concepts of arrays and pointers are related. in fact, arrays work very much like pointers to their first elements.
        // actually an array can always be implicitly converted to the pointer of the proper type.
        // after the first assignment 'thePointer' and 'theArray' would be equivalent and would have very similar properties.
        // the main difference being that 'thePointer' can be assigned a different address
        // whereas 'theArray' can never be assigned anything and will always represent the same block of 20 elements of type int.
        // therefore, the second assignment would not be valid.
        std::cout << nline << "----- Pointers and arrays:" << nline;
        std::cout << "The concept of arrays are related to that of the pointers." << nline << nline;
        int theArray [20];
        int* thePointer;
        thePointer = theArray; // valid
        //theArray = thePointer; // not valid

        // a demonstration that mixes arrays and pointers
        // the same set of operations with the same meaning are supported with the pointers and arrays.
        // the main difference is that pointers can be assigned new addresses.
        int numbers [10];
        int* p;
        p = numbers;
        *p = 10;
        p++; *p = 20;
        p = &numbers [2]; *p = 30;
        p = numbers + 3; *p = 40;
        p = numbers; *( p + 4 ) = 50;
        std::cout << "The values set to the array with the use of pointers are:" << nline << tab;
        for ( int i = 0; i < 5; i++ )
        {
            std::cout << numbers [i] << tab;
        }
        // in the arrays section, the brackets ([]) have been explained as specifying the index of an element of the array.
        // these brackets in fact are a dereferencing operator known as offset operator.
        // they dereference the variable they follow just like what the operator (*) in pointers does to the variable it precedes.
        // they also add the number between the brackets to the address being dereferenced.
        // for example:
        //a[5]=0; // a [offset of 5]
        //*(a+5)=0; // pointed to by (a+5)
        // no matter 'a' is an array or a pointer, these two expressions are equivalent and valid.
        // if it is an array, its name can be used to its first element just like a pointer.
        std::cout << nline;

        //! ####################################################################
        //! ----- pointer initialization:
        // the initialization of pointers can be introduced at the very moment of their declaration.
        // what is going to be initialized is the address to be pointed to and never the value stored in memory.
        // pointers can be initialized not only to the address of a variable, but also to the value of another pointer or array.
        std::cout << nline << "----- Pointer Initialization:" << nline;
        std::cout << "To introduce the initialization of pointers which can be done at the moment of declaration." << nline << nline;
        int myVar;            // a variable
        int* myPtr1 = &myVar; // point to address of variable
        int myArr [31] {};     // an array
        int* myPtr2 = myPtr1; // point to the value of a pointer
        int* myPtr3 = myArr;  // point to an array
        std::cout << "The value of myPtr1 is:" << tab << myPtr1 << nline;
        std::cout << "The value of myPtr2 is:" << tab << myPtr2 << nline;
        std::cout << "The value of myPtr3 is:" << tab << myPtr3 << nline;

        //! ####################################################################
        //! ----- pointer arithmetics:
        // conduction of arithmetical operations on pointers are a little different to those of the regular integer types.
        // to begin with there are just addition and subtraction are allowed.
        // because of the fact that types have different sizes even the conductions of these two operations are going to have different  behaviours. (the size of the types is going to be added or subtracted to or from the stored address value in pointers)
        // the exact size of data types is also dependent on the system.
        std::cout << nline << "----- Pointer arithmetics:" << nline;
        std::cout << "Arithmetical operations on pointers result in different behaviours and outputs than regular integer types." << nline << nline;
        char Char { 'A' };
        char* ptrChar { &Char };
        short Short { 4454 };
        short* ptrShort { &Short };
        long Long { 44544454 };
        long* ptrLong { &Long };
        std::cout << "The address values before the addition:" << nline;
        std::cout << "myChar is:" << tab << ptrChar << nline;
        std::cout << "myShort is:" << tab << ptrShort << nline;
        std::cout << "myLong is:" << tab << ptrLong << nline << nline;
        ++ptrChar;
        ++ptrShort;
        ++ptrLong;
        std::cout << "The address values after the addition:" << nline;
        std::cout << "myChar is:" << tab << ptrChar << nline;
        std::cout << "myShort is:" << tab << ptrShort << nline;
        std::cout << "myLong is:" << tab << ptrLong << nline << nline;

        // possible combinations of dereference operator and prefix or postfix versions of the increment/decrement operator
        // increment/decrement operator: higher priority (left-to-right)
        // reference/dereference operator: lower priority (right-to-left)
        // like always parenthesis reduces confusion by adding legibility to expressions.
        // postfix: *p++ = *q++;   is roughly equivalent to:   *p = *q; ++p; ++q;
        std::cout << "Four possible combinations of dereference operator and prefix or postfix versions of the increment/decrement operator:" << nline;
        int ptrVar { 4454 };
        int* ptr;
        int temp;
        std::cout << "The stored value in the variable is:" << tab << ptrVar << nline;
        std::cout << "The temp variable stores the value of each operation, so it could be shown." << nline << nline;
        ptr = &ptrVar;
        std::cout << "The value of ptr before incrementation *ptr++ is:" << tab << ptr << nline;
        temp = *ptr++;   // same as *(ptr++): increment pointer, and dereference un-incremented address
        std::cout << "ptr is:" << tab << ptr << nline;
        std::cout << "temp is:" << tab << temp << nline << nline;
        ptr = &ptrVar;
        std::cout << "The value of ptr before incrementation *++ptr is:" << tab << ptr << nline;
        temp = *++ptr;   // same as *(++p): increment pointer, and dereference incremented address
        std::cout << "ptr is:" << tab << ptr << nline;
        std::cout << "temp is:" << tab << temp << nline << nline;
        ptr = &ptrVar;
        std::cout << "The value of ptr before incrementation ++*ptr is:" << tab << ptr << nline;
        temp = ++*ptr;   // same as ++(*p): dereference pointer, and increment the value it points to
        std::cout << "ptr is:" << tab << ptr << nline;
        std::cout << "temp is:" << tab << temp << nline << nline;
        ptr = &ptrVar;
        std::cout << "The value of ptr before incrementation (*ptr)++ is:" << tab << ptr << nline;
        temp = ( *ptr )++; // dereference pointer, and post-increment the value it points to.
                         // without parenthesis the incrementation happens to the pointer itself too.
        std::cout << "ptr is:" << tab << ptr << nline;
        std::cout << "temp is:" << tab << temp << nline;


        //! ####################################################################
        //! ----- pointers and constants:
        // pointers can be used to access a variable by its address and this access may include modifying the value pointed.
        // to declare pointers that can access the pointed value to read it but not to modify it, it is enough to qualify the type pointed to by the pointer as constant.
        // a pointer to non-const can be implicitly converted to a pointer to const, but not the other way around.
        // as a safety features, pointers to const are not implicitly convertible to pointer to non-const.
        std::cout << nline << "----- Pointers and Constants:" << nline;
        std::cout << "To access a variable for just reading purposes, not modifying." << nline << nline;
        int x;
        int y { 10 };
        const int* const_ptr { &y }; // points to a variable but in a const-qualified manner
                                     // allowed (non-const to const): the type of y is int* and is assigned to a pointer of type const int*.
        x = *const_ptr; // ok: reading p
        std::cout << "The value accessed by a const-qualified pointer is:" << tab << x << nline << nline;
        //*const_ptr = x; // error: modifying const-qualified

        // on of the use cases of pointers to constant elements is as function parameters.
        // a function that takes a pointer to constant element, can not modify the value passed as argument.
        // pointers that point to constant content they can not modify, doesn't mean that the pointers themselves are constant, they can still increment and decrement the assigned address but they can't modify the content they point to.
        std::cout << "Functions that use normal and const-qualified pointers:" << nline;
        int numbers_array [] { 10,20,30 };
        std::cout << "The elements of the array are:" << nline;
        for ( int i = 0; i < 3; i++ )
        {
            std::cout << numbers_array [i] << tab;
        }
        std::cout << nline << nline;
        std::cout << "The array elements after execution of the functions are:" << nline;
        increment_all_PointersUsed ( numbers_array, numbers_array + 3 );
        print_all_ConstantPointersUsed ( numbers_array, numbers_array + 3 );

        // constant pointers:
        // a second dimension to constness added to pointers is that the pointers themselves can also be constant.
        // this is specified by appending const to the pointed type (after the asterisk).
        // the syntax with const and pointer is definitly tricky.
        // recognising the cases that best suit each use tends to require some experience
        // in any case it is important to get constness with pointers (and references) right sooner rather than later.
        std::cout << nline << "Pointers themselves can also be constant." << nline;
        std::cout << "The source code contains the syntaxes and order needed for their definition." << nline;
        std::cout << "The cases of their uses are going to be introduced in the further sections." << nline;
        int x_var;
        int* ptr1 { &x_var };
        const int* ptr2 { &x_var }; // const int
        int* const ptr3 { &x_var }; // const pointer
        const int* const ptr4 { &x_var };

        // the const qualifier can either precede or follow the pointed type
        // as with the spaces surrounding the asterisk, the order of const in this case is simply a matter of style.
        // the merits of each are still intensely debated on the internet.
        const int* ptr5 { &x_var };
        int const* ptr6 { &x_var }; // the exact same meaning and use as the expression above

        //! ####################################################################
        //! ----- pointers and string literals:
        // by using pointers string literals can be accessed directly.
        // They are arrays of the proper array type to contain all its character plus terminating null-character with each of the element being of type const char (as literals, they can never be modified).
        // pointers that point to character sequences can be used to access their characters in the same way null-terminated character sequences are.
        // this is because pointers and arrays behave essentially in the same way in expressions.
        std::cout << nline << "----- Pointers and string literals:" << nline;
        std::cout << "By using pointers string literals can be accessed directly." << nline << nline;
        const char* Ptr_StrLit { "HELLO!" }; // an array with the respected literal representation and a pointer (identifier name) which points to its first element.
        std::cout << "A representation of the ways that the characters of a character sequence can be accessed directly:" << nline;
        for ( int i = 0; i <= 5; i++ )
        {
            std::cout << Ptr_StrLit [i] << ' '; // accessing in usual array way
        }
        std::cout << nline;
        for ( int i = 0; i <= 5; i++ )
        {
            std::cout << *( Ptr_StrLit + i ) << ' '; // accessing in usual pointer way
        }
        std::cout << nline;

        //! ####################################################################
        //! ----- pointers to pointers:
        // the use of pointers that point to pointers is allowed in C++.
        // these pointers, in its turn, point to data or even to other pointers.
        // the syntax in declaration of pointers simply requires an asterisk for each level of indirection.
        std::cout << nline << "----- Pointers to pointers:" << nline;
        std::cout << "C++ allows the use of pointers that point to pointers." << nline << nline;
        int int_var;
        int* int_ptr;
        int** int_ptr_ptr; // a pointer to a pointer which can be used in three different levels of indirection and each one of them would correspond to a different value.
        int_var = 89;
        int_ptr = &int_var;
        int_ptr_ptr = &int_ptr;
        std::cout << int_ptr_ptr << nline; // first level, the address of the pointer to pointer itself
        std::cout << *int_ptr_ptr << nline; // second level, the address of pointed pointer
        std::cout << **int_ptr_ptr << nline; // third level, the value being pointed by pointer to pointer

        //! ####################################################################
        //! ----- void pointers: (a special type of pointer)
        // in C++ void represents the absence of type.
        // therefore void pointers are pointers that point to a value that has no type, thus also an undetermined length and undetermined dereferencing properties.
        // this gives void pointers a great flexibility, by being able to point to any data type, but also a great limitation, which is the data pointed to by them can not be directly dereferenced.
        // any address in a void pointer needs to be transformed into some other date type that point to a concrete data type before being dereferenced.
        // one of its possible uses may be to pass generic arguments as parameters to a function.
        // sizeof is an integrated operator in C++ that returns the size of its argument in bytes.
        // for non-dynamic data types, this value is a constant.
        std::cout << nline << "----- Void pointers:" << nline;
        std::cout << "Void pointers are pointers that point to a value that has no type and this ability gives them a great flexibility and a great limitation." << nline << nline;
        char a { 'A' };
        int b = 24;
        std::cout << "Values ready to be passed are:" << nline << tab << a << tab << b << nline;
        increase ( &a, sizeof ( a ) );
        increase ( &b, sizeof ( b ) );
        std::cout << "Increased values in the function that has void pointers as parameters are:" << nline;
        std::cout << tab << a << tab << b << nline;

        //! ####################################################################
        //! ----- invalid pointers and null pointers:
        // in principle, pointers are meant to point to valid addresses, such as the addresses that introduced and worked with till now.
        // but pointers can actually point to an addresses, including addresses that do not refer to any valid element, such as uninitialized variables and non-existent elements of an array.
        // in C++ pointers are allowed to take any address value, no matter whether there actually is something in that address or not.
        // void (invalid) pointers: point to somewhere without a specific type (refers to the type of data it pints to)
        std::cout << nline << "----- Invalid pointers and null pointers:" << nline;
        std::cout << "Void pointers point to somewhere without a specific type" << nline;
        std::cout << "A null pointer is a value that any pointer can take to represent that it points to nowhere" << nline << nline;
        // the two statement below don't cause any error, while not pointing to any addresses known to contain a value.
        // what can cause runtime errors or undefined behaviours (i.e. accessing some random value) is to dereference such pointers.
        int* pp; // uninitialized pointer (local variable) (no error)
        int anArray [10];
        int* qq { &anArray [20] }; // element out of bound (no error)
        //std::cout << pp << nline; // error: used without initialization
        std::cout << "The pointed out of bound address of the array addresses is:" << qq << nline << nline;
        // the null pointer value:
        // a value that any pointer can take to represent that it points to nowhere (refers to the value stored in the pointer)
        // sometimes pointers really need to explicitly point to nowhere, and not just an invalid address.
        // for such cases, there exists a special value that any pointer type can take, which is the null pointer value
        // there are two ways for this value to be expressed in C++: either whit an integer value of zero or with the nullptr keyword;
        // all null pointers compare equal to other null pointers
        int* pp2 { 0 };
        int* qq2 { nullptr };
        int* rr { NULL }; // quite usual in old cod to use constant NULL to refer to null pointer value
                         // NULL is defined in several headers of the standard library, and is defined as an alias of some null pointer constant value such as 0 and nullpter.
        std::cout << "FYI :) ==> the addresses of the defined null pointers are:" << nline;
        std::cout << tab << pp2 << tab << qq2 << tab << rr << nline;

        //! ####################################################################
        //! ----- pointers to functions:
        // C++ allows operations with pointers to functions.
        // typical uses: using pointers to call functions, passing a function as an argument to another function.
        // pointers arithmetic can not be performed on the pointers to function.
        // the same syntax as a regular function is to be used to declare pointers to function except that the name of the function is enclosed between parenthesis () and an asterisk * is inserted before the name.
        std::cout << nline << "----- Pointers to functions:" << nline;
        std::cout << "A pointer can also be used to call a function and to pass a function as an argument to another function." << nline << nline;
        int m, n;
        int ( *minus )( int, int ) = subtraction_PointerToFunction; // a pointer to function that has two parameter and is directly initialized
        m = operation_PointerToFunction ( 10, 7, addition_PointerToFunction ); // calling with the function itself
        n = operation_PointerToFunction ( 34, m, minus ); // calling with a pointer to function
        std::cout << "The result of the first call (passing the wished function itself):" << tab << m << nline;
        std::cout << "The result of the second call (passing the wished function by using pointers to functions):" << tab << n << nline;
    }
    catch ( const std::exception& )
    {

    }
}


// ********************************************************************************
/// <summary>
/// Dynamic memory
/// </summary>
/// <created>ʆϒʅ,06.09.2018</created>
/// <changed>ʆϒʅ,08.09.2018</changed>
// ********************************************************************************
void DynamicMemory ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ dynamic memory:
        // up until now all demonstrations used memory that were determined before the execution of the program by defining the variables needed.
        // in cases that there is a need to determine the memory needed during runtime, such as when the memory needed depends on the user input, programs need to dynamically allocate memory, for which the C++ language integrates the operators 'new' and 'delete'.
        std::cout << nline << "~~~~~ Dynamic memory:" << nline;
        std::cout << "In cases that there is a need for programs to allocate the memory during runtime, C++ language introduces the concepts of dynamic memory." << nline;

        //! ####################################################################
        //! ----- operators new and new[]:
        // dynamic memory is allocated using the operator new.
        // syntax:
        // pointer = new type
        // pointer = new type [number_of_elements]
        // new is followed by a data type specifier, and if a sequence of more than one elements is required, the number of these within brackets (an integer value).
        // it returns a pointer to the beginning of the new block of memory allocated.
        std::cout << nline << "----- Operators new and new[]:" << nline;
        std::cout << "Dynamic memory is allocated using the operator new." << nline << nline;
        int* ptr1;
        ptr1 = new int; // allocate memory to contain one single element of type int
        *ptr1 = 555;
        std::cout << "The address of allocated memory is:" << tab << ptr1 << nline;
        std::cout << "The value stored in the allocated memory is:" << tab << *ptr1 << nline << nline;
        // the most important difference between declaring normal arrays and allocating dynamic memory is that the allocation happens during runtime using any variable value as size
        char* ptr2;
        ptr2 = new char [6]; // allocate a block (an array) of elements of type char
        for ( int i = 0; i <= 5; i++ )
        {
            *( ptr2 + i ) = '$'; // accessing in usual pointer way
        }
        std::cout << "The address of the first element is:" << tab << ptr2 << nline;
        std::cout << "The elements stored in the allocated memory are:" << nline << tab;
        for ( int i = 0; i <= 5; i++ )
        {
            std::cout << ptr2 [i] << tab; // accessing in usual array way
        } std::cout << nline << nline;

        // C++ standard mechanisms to check the success of allocation
        // the requested dynamic memory is going to be allocated by the system from the memory heap.
        // since the computer memory is a limited resource and can be exhausted, there are no guarantees that all request to allocate memory using operator new is going to be granted by the system.
        //* first mechanism is by handling exceptions:
        // an exception of type bad-alloc will be thrown when the allocation fails.
        // introduction of exceptions is in the later sections but for now it is enough to know that if this exception is thrown and it is not handled by a specific handler, the program execution is terminated.
        // by default this exception method is the one used by the operator new, so it may be thrown in the declaration line that request the allocation of memory.
        //* the other method known as 'nothrow', assigns the 'nullptr' to the pointer, instead of throwing a bad_alloc exception and terminating the program, therefore the returned pointer will be a null pointer and the program continue its execution normally.
        // this method can be specified by using a special object called 'nothrow', declared in header <new>, as argument for new.
        // in this case, if the allocation of this block of memory fails, it can be detected by checking if the pointer pointed to it, is a null pointer.
        //* the nothrow method despite simplicity is likely to produce less efficient code than the exceptions, since it implies explicitly checking the pointer value returned after each and every allocation.
        // therefore, at least for critical allocations, the exception mechanism is preferred.
        int* ptr3;
        ptr3 = new ( std::nothrow ) int [5];
        if ( ptr3 == nullptr )
            std::cout << "Error assigning memory!" << nline;
        else
            std::cout << "The address of the first element is:" << tab << ptr3 << nline;

        //! ####################################################################
        //! ----- operators delete and delete[]:
        // since the allocated memory in most cases is only needed during specific periods of time within a program, with the operator delete, it can be freed once it is no longer needed, so that the memory become available for other requests of dynamic memory.
        // syntax:
        // delete pointer; (releases the memory of a single element allocated with new)
        // delete[] pointer; (there is no need to introduce the number of elements, the brackets are enough)
        // the second statement releases the memory allocated for the arrays of elements using new and a size in brackets.
        // the value passed as argument to delete shall be a pointer to a memory block previously allocated with new or a null pointer (in case of a null pointer, delete produces no effect).
        std::cout << nline << "----- Operators delete and delete[]:" << nline;
        std::cout << "To introduce the practice of freeing the allocated memory, which there is no need of any more to make it available for other requests of dynamic memory." << nline << nline;
        std::string _instring;
        int _number, _index;
        int* _pointer;
        std::cout << "How many numbers would you like to type?" << tab;
        std::getline ( std::cin, _instring );
        std::stringstream ( _instring ) >> _number;
        while ( _number > 2500 )
        {
            std::cout << "Come on! You don't want to enter so many numbers! Think and try again." << tab;
            std::getline ( std::cin, _instring );
            std::stringstream ( _instring ) >> _number;
        }
        if ( _number > 25 )
            std::cout << "Really? You do want to enter so many numbers? :| OK!" << nline;
        _pointer = new( std::nothrow ) int [_number]; // entered by the user and not a constant
        if ( _pointer == nullptr )
            std::cout << nline << "Error: memory could not be allocated!" << nline;
        else
        {
            std::cout << nline;
            for ( _index = 0; _index < _number; _index++ )
            {
                std::cout << "Enter number:" << tab;
                std::cin >> _pointer [_index]; // pointer way: *(_pointer + _index)
            }
            std::cout << nline << "You have entered:" << nline;
            for ( _index = 0; _index < _number; _index++ )
                std::cout << _pointer [_index] << tab; // pointer way: *(_pointer + _index)
            std::cout << nline;
            delete [] _pointer;
        }

        // working with memory and allocating it during runtime, does always require great attention, specially when there is a need that the user introduces the inputs for it, since there is always a great chance that one user out there do bring not only the program also the running platform of the program in an unstable state.
        // it is always considered a good practice for programs to be able to handle the failures to allocate memory, not only by catching the proper exception, but also by controlling the user input and checking the pointer value (nothrow).


        // dynamic memory in C language
        // C++ integrates the operators new and delete for allocating dynamic memory, but these were not available in C language.
        // instead, C language, used library solution with the functions malloc, calloc, realloc, and free, defined in the header <cstdlib> (known as <stdlib.h> in C language).
        // these functions are also available and can be used to allocate and deallocate dynamic memory.
        // note, though, that the memory blocks allocated with these functions aren't necessarily compatible with those returned with new operator, thus they should not be mixed and each one should be handled with its own set of functions and operators.
    }
    catch ( const std::exception& )
    {

    }
}


struct movies_t
{
    std::string title;
    int year;
} mine, yours;
void printMovie ( movies_t movie )
{
    std::cout << movie.title << " (" << movie.year << ")" << Nline;
}
// ********************************************************************************
/// <summary>
/// Data structures
/// </summary>
/// <created>ʆϒʅ,08.09.2018</created>
/// <changed>ʆϒʅ,11.09.2018</changed>
// ********************************************************************************
void DataStructures ()
{
    // the functions and structures used in this section are defined above it.
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ data structures:
        // a data structure is a group of data elements grouped together under one name.
        // these data elements, known as members, can have different types and different lengths.
        // syntax:
        // struct type_name {
        // member_type1 member_name1;
        // member_type2 member_name2;
        // .
        // .
        // } object_names;
        // where optional field object_names can be a set of valid identifiers for objects that have the type of this structure.
        // in cases that the optional field object_names is specified, the field type_name becomes optional: struct requires either a type_name or at least on name in object_names, but not necessarily both.
        // after declaration of an object using the determined structure type, its members can be accessed directly by using a dot (.) between the object name and the member name.
        // subsequently the members can be operated with like standard variables of their respective types.
        // the structures can be passed to functions like standard variables.
        // one of the features of data structures is the ability to refer to both their members individually or to the entire structure as whole. in both cases using the same identifier: the name of the structure.
        // each member of a defined object has the data type corresponding to the member it refers to in the data structure.
        std::cout << nline << "~~~~~ Data structures:" << nline;
        std::cout << "A group of data elements which can have different types and different lengths, grouped together under one name is called a data structure." << nline << nline;
        struct product
        {
            int weight;
            double price;
        } pear, grape; // demonstration of how to use the optional field object_names
        product apple; // after declaration used just like any other type
        product banana, melon;
        apple.price = 2.5;
        grape.weight = 4;
        melon.price = 4.3;
        pear.weight = 3;
        // a demonstration with structure types in action
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
        // structures are types, therefore using them as the type of arrays to construct tables or databases is another feature.
        std::cout << nline << "Filling and using an array which has an data structure as its type:" << nline;
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

        //! ####################################################################
        //! ----- pointers to structures:
        // structures can be pointed to by their own type of pointers just like any other type.
        // the arrow operator (->):
        // the arrow operator is a dereference operator that is used exclusively with pointers to objects that have members.
        // this operator serves to access the member of an object directly form its address.
        // a summarization of possible combinations of operators for pointers and for structure members:
        // ------------------------------------------------------------------
        // Expression | What is evaluated                        | Equivalent
        // ------------------------------------------------------------------
        // a.b        | member b of object a                     |
        // ------------------------------------------------------------------
        // a->b       | member b of object pointed to by a       | (*a).b 
        // ------------------------------------------------------------------
        // *a.b       | value pointed to by member b of object a | *(a.b)
        // ------------------------------------------------------------------
        std::cout << nline << "----- Pointers to structures:" << nline;
        std::cout << "Structures can be pointed to by their own type of pointers." << nline << nline;
        movies_t aMovie;
        movies_t* ptrMovie; // a pointer to point to objects of structure type movies_t
        ptrMovie = &aMovie;
        std::cout << "Pointing to and accessing an object which has structure as type:" << nline;
        std::cout << "Enter title: " << tab;
        std::getline ( std::cin, ptrMovie->title ); // for all purposes, equivalent to: (*ptrMovie).title
        std::cout << "Enter year: " << tab;
        std::getline ( std::cin, strTemp );
        std::stringstream ( strTemp ) >> ptrMovie->year;
        std::cout << nline << "You have entered:" << nline;
        std::cout << ptrMovie->title << " (" << ptrMovie->year << " )" << nline;
        // note that:
        // *ptrMovie.title which is rather equivalent to *(ptrMovie.title) in the case above, would access the value pointed by a hypothetical pointer member called 'title' of the structure object 'ptrMovie', which is not the case, since 'title' is not a pointer type.

        //! ####################################################################
        //! ----- nesting structures:
        // structures can also be nested, so an element of an structure is itself another structure.
        std::cout << nline << "----- Nesting structures:" << nline;
        std::cout << "To introduce elements in a structure that themselves are also structures." << nline << nline;
        struct friends_t
        {
            std::string name;
            std::string email;
            movies_t favorite_movie;
        } maria, charlie;
        friends_t* ptrFriends = &charlie;
        maria.name = "Marie";
        maria.email = "maria@gmail.com";
        maria.favorite_movie.title = "The Matrix";
        maria.favorite_movie.year = 1999;
        charlie.name = "Charlie";
        ptrFriends->email = "charlie@gmail.com";
        charlie.favorite_movie.title = "Blade Runner";
        charlie.favorite_movie.year = 1982; // refer to the same member as the next expression
        ptrFriends->favorite_movie.year = 1982; // refer to the same member as the next expression
        ( *ptrFriends ).favorite_movie.year = 1982;
        std::cout << "A demonstration of nesting structures:" << nline;
        std::cout << maria.name << nline;
        std::cout << maria.email << nline;
        printMovie ( maria.favorite_movie );
    }
    catch ( const std::exception& )
    {

    }
}


// ********************************************************************************
/// <summary>
/// Other data types
/// </summary>
/// <created>ʆϒʅ,11.09.2018</created>
/// <changed>ʆϒʅ,18.09.2018</changed>
// ********************************************************************************
void OtherDataTypes ()
{
    try
    {
        ColourCouter ( "--------------------------------------------------", F_bRED );
        ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

        //! ####################################################################
        //! ~~~~~ other data types:
        // 
        std::cout << nline << "~~~~~ Other data types:" << nline;
        std::cout << "In the past sections, a lot of types have been introduced and there is even more about them." << nline;

        //! ####################################################################
        //! ----- type aliases (typedef / using):
        // in C++ any valid type either fundamental or compound can be aliased, which is a different name and then it can be referred to by it, which is its another identifier.
        // once the aliases are defined, they can be used in any declaration like any other valid type.
        //- the first syntax (inherited from the C language):
        // typedef existing_type new_type_name;
        //- second syntax introduced in C++:
        // using new_type_name = exising_type;
        std::cout << nline << "----- Type aliases (typedef / using):" << nline;
        std::cout << "To introduce different names for any valid type, so they could be used as another identifier for them." << nline;
        typedef char C; // obvious
        typedef unsigned int WORD; // alias WORD as unsigned int
        typedef char* pChar; // alias pChar as char*
        typedef char field [50]; // alias field as char[50]
        C myChar, anotherChar, *pTc1;
        WORD myWord;
        pChar ptc2;
        field name;
        using C2 = char;
        using WORD2 = unsigned int;
        using pChar2 = char*;
        using field = char [50];
        // both ways of definition define semantically equivalent aliases, the only difference being that typedef has certain limitation in the realm of templates, which means that using is more generic but typedef has longer history and probably more common in the existing code.
        // the purposes:
        // reducing the length of long or confusing type names
        // most useful as tools to abstract programs from the underlying types they use (i.e. to easily replace the types used in a program in a later version)

        //! ####################################################################
        //! ----- unions:
        // unions allow one portion of memory to be accessed as different date types. while its declaration is similar to the one of structures, its functionality is totally different.
        // syntax:
        // union type_name {
        // member_type1 member_name1;
        // member_type2 member_name2;
        // .
        // .
        // } object_names;
        // this creates a new union type, identified by type_name, in which all its members occupy the same physical space in the memory, and the size of this type is the size of the largest member element.
        // this means that the modification of one member in an union is going to affect all of its member,
        // therefore it is not possible to store different values for each member in an union in a way that each member is independent of the others.
        std::cout << nline << "----- Unions:" << nline;
        std::cout << "To introduce one portion of memory to be occupied by all members with different data types." << nline;
        union myTypes_t
        {
            char c;
            int i;
            float f;
        } myTypes;
        myTypes.c = 'A';

        // one of the uses of a union is to be able to access a value either in its entirety or as an array or structure of similar elements.
        // the exact alignment and order of the members of a union in memory depends on the system, with the possibility of creating portability issues.
        union mix_t
        { // assumptions:
            int l;      // 4 byte (entirety access)
            struct
            {
                short hi; // 2 byte (access in structure form)
                short lo; // 2 byte
            } s;
            char c [4];  // 4*1 byte (access in array form)
        } mix;

        //! ####################################################################
        //! ----- anonymous unions:
        // when unions are members of a class or structure, they can be declared with no names, with which they become anonymous unions, and their members are directly accessible from objects by their member name.
        // remember that the members of an union share a space in the memory so they can never have different values simultaneously.
        std::cout << nline << "----- Anonymous unions:" << nline;
        std::cout << "By declaring an union without any name in a class or structure, they become anonymous unions." << nline;
        struct book1_t
        {
            char title [50];
            char author [50];
            union
            {
                float dollar;
                int yen;
            } price; // a regular union in a structure
        } book1;
        struct book2_t
        {
            char title [50];
            char author [50];
            union
            {
                float dollar;
                int yen;
            }; // an anonymous union in a structure
        } book2;
        // accesses:
        book1.price.dollar = 3.4;
        book2.dollar = 3.4;

        //! ####################################################################
        //! ----- enumerated types (enum):
        // enumerated types are types that are defined with a set of custom identifiers, known as enumerators, as possible values.
        // objects of these enumerated types can take any of these enumerators as value.
        // syntax:
        // enum type_name {
        // value1
        // value2
        // .
        // .
        // } object_names;
        // objects (variables) of this type can directly be instantiated as object_names.
        std::cout << nline << "----- Enumerated types (enum):" << nline;
        std::cout << "To introduce a set of custom identifiers, known as enumerators, as possible values." << nline << nline;
        // a new data type from scratch without any base on the existing data types:
        enum colours_t { black, blue, green, cyan, red, purple, yellow, white };
        colours_t myColour;
        myColour = blue;
        if ( myColour = green )
            myColour = red;
        std::cout << "The value stored in the 'myColour' variable is:" << nline << tab << myColour << nline;

        // values of enumerated types declared with enum are implicitly convertible to an integer type and vice versa.
        // in fact, these values are always assigned an integer value internally, to or from which they can be implicitly converted.
        // if it is not specified the equivalent integer value to the first possible value is zero (0), the equivalent to the second is one (1) and so on.
        // any of the possible values in the enumerated type can be specified an integer value, and if the constant value that follows it, itself isn't given an integer value, it is automatically assumed to be the same value plus one.
        enum months_t
        {
            January = 1, February, March, April,
            May, June, July, August,
            September, October, November, December
        } y2k;
        y2k = January;
        std::cout << "The value stored in the 'y2k' variable is:" << nline << tab << y2k << nline;
        // the implicit conversation works both ways:
        // a value of type months_t can be assigned a value of 1 (equivalent to January)
        // or an integer variable can be assigned a value of January (equivalent to 1)

        //! ####################################################################
        //! ----- enumerated types with enum class:
        // in C++, real enum types can be created with enum class (or enum struct), which are then neither convertible to int and neither have enumerator values of type int, but of the enum type itself, thus preserving the type safety.
        // each of the enumerator values of an enum class needs to be scoped into its type (this is also possible with enum type, but it is only optional).
        // enumerated types declared with the enum class have also more control over their underlying type;
        // it may be any integral data type such as char, short, unsigned int, which essentially serve to determine the size of the type, which is specified with an colon and the underlying type following the enumerated type.
        std::cout << nline << "----- Enumerated types with enum class:" << nline;
        std::cout << "To introduce real enum types that preserve safety." << nline << nline;
        enum class Colours { black, blue, green, cyan, red, purple, yellow, white };
        Colours myColour2;
        myColour2 = Colours::blue; // needed scoping into the type
        if ( myColour2 == Colours::green )
            myColour2 = Colours::red;
        std::cout << "The value stored in the 'myColour2' variable is:" << nline << tab << static_cast<int>( myColour2 ) << nline;
        enum class EyeColour :char { blue, green, brown }; // + underlying type (a distinct type with the size of a char)
    }
    catch ( const std::exception& )
    {

    }
}