// --------------------------------------------------------------------------------
/// <summary>
/// _4_CompoundDataTypes.cpp
/// </summary>
/// <created>ʆϒʅ,30.05.2018</created>
/// <changed>ʆϒʅ,13.10.2019</changed>
// --------------------------------------------------------------------------------

#include "LearningCplusPlus.h"
#include "Console.h"


#define Tab '\t'
#define Nline '\n'


const char tab { '\t' };
const char nline { '\n' };


void _11_01_Arrays ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
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
    ColourCouter ( "~~~~~ Arrays:\n", F_bWHITE );
    ColourCouter ( "Same type elements can build series of elements known as arrays and every element can be referenced by adding an index to the array's unique identifier.\n\n", F_YELLOW );
  }
  catch ( const std::exception& )
  {

  }
}


void print_simple_array ( int array_arg [], int length )
{
  std::cout << tab;
  for ( int n = 0; n < length; n++ )
  {
    std::cout << array_arg [n];
    if ( array_arg [n] <= 9 ) std::cout << "   "; else std::cout << "  ";
  }
  std::cout << Nline << Nline;
}
void _11_02_InitializingArrays ()
{
  try
  {
    //! ####################################################################
    //! ----- initializing arrays:
    // arrays of local scope like variables are uninitialized by default
    // global scope and in namespaces (outside any function) declared arrays are initialized by default.
    // to explicitly initialize an array, the values must be enclosed in curly braces.
    // the number of values must not be grater than the exact number of elements in the array.
    // if the array is initialized with less, the remaining elements will be set to its type default value.
    // the default value for fundamental types is zero.
    // empty curly braces are to be used to initial an array with default values.
    // with leaving square braces empty for an initialization-provided array,
    // C++ automatically assume a size for the array that matches the number of its values.
    // evolution of C++ has provided universal initialization also for arrays,
    // so equal signs in between of their declarations and identifiers aren't needed any more.
    ColourCouter ( "----- Initialization of Arrays:\n", F_bWHITE );
    ColourCouter ( "Uninitialized arrays of local scope have undetermined values.\n\n", F_YELLOW );
    int array1 [5]; // uninitialized
    int array2 [5] = { 0,1,2,3,4 }; // explicitly initialized
    int array3 [5] = { 0,1,2 }; // remaining elements will be initialized with array's type default value
    int array4 [5] = {}; // all elements are initialized with array's type default value
    int array5 [] = { 0,1,2,3,4 }; // compiler of C++ assumes the size of array automatically
    int array6 [5] { 0,1,2,3,4 }; // universal initialization
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


void _11_03_AccessingValues ()
{
  try
  {
    //! ####################################################################
    //! ----- accessing the values of an array:
    // the value of any element in an array can be accessed just like the value of regular variable of the same type.
    // Note syntax: name[index]
    ColourCouter ( "----- Accessing the values of an array:\n", F_bWHITE );
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
    int b_array [5] { 0 }; // first use of brackets: in declaration to specify the size
    b_array [1] = -3; // second use of brackets: to access an element of the array
    int a { 3 };
    b_array [0] = a;
    b_array [a] = 33;
    int b { b_array [a + 1] }; // equivalent: int b {0};
    b_array [b_array [a] / 11] = b_array [2] + 5; // equivalent: b_array[3] = 5;
    std::cout << "The array's elements after some valid operations are:" << nline;
    std::string str { "" };
    int sum { 0 };
    for ( int n = 0; n < 5; n++ )
    {
      if ( b_array [n] < 0 )
        str = "-negative";
      else
        if ( b_array [n] == 0 )
          str = "-zero";
        else
          str = "-positive";
      std::cout << tab << "Element " << n + 1 << ":\t" << b_array [n] << tab << str << nline;
      sum += b_array [n];
    }
    std::cout << "Subtraction result:" << tab << sum << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void print_bidimensional_array ( int array_arg [][5], int width, int height )
{
  std::cout << tab;
  for ( int n = 0; n < width; n++ )
  {
    for ( int m = 0; m < height; m++ )
    {
      std::cout << array_arg [n][m];
      if ( array_arg [n][m] <= 9 ) std::cout << "   "; else std::cout << "  ";
    }
    std::cout << Nline << tab;
  }
  std::cout << Nline;
}
// depth parameter: to represent a simple array in a table (bidimensional):
// explanation in multidimensional arrays section
void print_simple_array_bidimensional ( int array_arg [], int length, int depth = 0 )
{
  std::cout << tab;
  for ( int n = 0; n < length; n++ )
  {
    if ( depth != 0 )
      if ( ( n != 0 ) && ( n % ( length / depth ) ) == 0 )
        std::cout << nline << tab;
    std::cout << array_arg [n];
    if ( array_arg [n] <= 9 ) std::cout << "   "; else std::cout << "  ";
  }
  std::cout << Nline << Nline;
}
void _11_04_MultidimensionalArrays ()
{
  try
  {
    //! ####################################################################
    //! ----- multidimensional arrays:
    // arrays with more than one dimension can be described as 'arrays of arrays'.
    // a bidimensional array can be described as a two-dimensional table made of elements, all of the same uniform data type.
    // with each additional dimension for an array, the number of its indices is going to be added to, and with it the amount of needed memory is also increases exponentially
    // multidimensional arrays are just an abstraction for the programmers, since the same result can be achieved with a simple array, by multiplying its indices.
#define HEIGHT 3 // using defined constants for better readability and easiness of later changes in one place
#define WIDTH 5 // the same
    ColourCouter ( "----- Multidimensional arrays:\n", F_bWHITE );
    ColourCouter ( "Can be described as 'arrays of arrays'.\n\n", F_YELLOW );
    int bidimensional_array [HEIGHT][WIDTH] {}; // declaration of a bidimensional array of 3 per 5 elements of type int
    bidimensional_array [0][2] = 13; // to reference to the element vertically first and horizontally third
    std::cout << "The bidimensional arrays's elements are:" << nline;
    print_bidimensional_array ( bidimensional_array, HEIGHT, WIDTH );

    //! - in addition:
    // a simple array can replace every multidimensional array by multiplying the needed indices. (multidimensional is just an abstraction for programmers.)
    // the only and useful difference is the depth of every imaginary dimension of an multidimensional array, which compiler automatically remembers.
    ColourCouter ( "Representing a bidimensional array with a simple array:\n", F_bYELLOW );
    int equivalent_simple_array [HEIGHT * WIDTH] {}; // equivalent to bidimensional_array (3*5=15)
    int o { 1 };
    for ( int n = 0; n < HEIGHT; n++ )
    {
      for ( int m = 0; m < WIDTH; m++ )
      {
        // both piece of code produce the same result:
        bidimensional_array [n][m] = o; // using a bidimensional array
        equivalent_simple_array [n * WIDTH + m] = o; // using a simple array
        ++o;
      }
    }
    std::cout << "The bidimensional arrays's elements are:" << nline;
    print_bidimensional_array ( bidimensional_array, HEIGHT, WIDTH );
    std::cout << "The simple arrays's elements are (same result is achieved):" << nline;
    print_simple_array ( equivalent_simple_array, HEIGHT * WIDTH );
    std::cout << "The simple arrays's elements are (same result is achieved plus printing bidimensional):" << nline;
    print_simple_array_bidimensional ( equivalent_simple_array, HEIGHT * WIDTH, 3 );
  }
  catch ( const std::exception& )
  {

  }
}


void _11_05_ArraysAsParameters ()
{
  try
  {
    //! ####################################################################
    //! ----- arrays as parameters:
    // C++ language passes the address of an array to a function.
    // in practice this has the same effect as passing the entire block of memory, while being more efficient and much faster.
    // to accept an array as parameter for a function, the parameters can be declared as the array type but with empty brackets, omitting the actual size of the array, thus the format is: base_type parameter_name[]
    // for a function to accept an array as parameter, the parameter must be declared as the type of the array but with empty brackets [], and with this the actual array size is omitted.
    // Note format: base_type parameter_name[]
    // Note syntax: void procedure (int arg[])  --accepts an array of type int as parameter
    // Note calling format: function_identifier ( array_identifier ) --without brackets
    ColourCouter ( "----- Arrays as parameters:\n", F_bWHITE );
    ColourCouter ( "In C++ the address of an array can be passed to a function.\n\n", F_YELLOW );
    int an_array [] { 1, 2, 3 };
    int another_array [] { 10, 20, 30, 40, 50 };
    std::cout << "Passing two simple arrays as argument (earlier defined function):" << nline;
    print_simple_array ( an_array, 3 );
    print_simple_array ( another_array, 5 );

    //! - in addition:
    // a function can also have a multidimensional array as parameter.
    // Note the format for tridimensional arrays: base_type parameter_name[] [depth] [depth]
    // Note syntax: void procedure (int myarray[][depth][depth])
    // for the compiler to determines the depth of each additional dimension, the size of all dimensions after the first one is necessary. (just first twin brackets stays empty)
    // explanation behind is, that for historical reasons, arrays can't be directly copied, therefore all arrays after passing as arguments lose one dimension, and the actual passed is just a pointer.
    // for this to be really understood, a clear understanding in pointer section helps a lot.
    int the_array [2][5] { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    std::cout << "Passing a bidimensional array as argument (earlier defined function):" << nline;
    print_bidimensional_array ( the_array, 2, 5 );
  }
  catch ( const std::exception& )
  {

  }
}


void print_library_array ( std::array<int, 3> array_arg )
{
  std::cout << tab;
  for ( int element : array_arg )
    std::cout << element << tab;
  std::cout << Nline << Nline;
}
void _11_06_LibraryArrays ()
{
  try
  {
    //! ####################################################################
    //! ----- library arrays:
    // all the arrays up until now were directly implemented as language features and inherited from C Language.
    // while they are great features, the restriction on copy and decay into pointers make them suffer from an excess of optimization.
    // to over come some of these issues, C++ provides an alternative array type, a type template (a class template in fact) as a standard container, defined in header <array>.
    // this alternative operates similar to built-in one, exception is that the expensive copying of entire block of memory is allowed and it decays into pointers by means of its member data only when explicitly told to do so.
    // in practice the main difference lays on the declaration and the additional inclusion of needed header.
    // classes and containers will be explained later.
    ColourCouter ( "----- Library arrays:\n", F_bWHITE );
    ColourCouter ( "To introduce an alternative for overcoming the issues with built-in C++ language arrays.\n\n", F_YELLOW );
    std::cout << "A language built in array in practice:" << nline << tab;
    int built_in_array [] { 10, 110, 1110 };
    for ( int i = 0; i < 3; i++ )
      ++built_in_array [i];
    for ( int element : built_in_array ) // range-based for loop
      std::cout << element << tab;
    std::cout << nline;
    //
    std::cout << "A container library array in practice:" << nline << tab;
    std::array<int, 3> library_array { 10, 110, 1110 };
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
void _12_01_CharacterSequences ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ character sequences:
    // while string class is a powerful feature to handle and manipulate strings,
    // they can aslo be represented by plain arrays of a character type, since they are also sequences of characters
    // by convention, the end of strings represented in character sequences is signalled by null character with literal value \0.
    // the capacity of the array doesn't need to be fully exhausted.
    ColourCouter ( "~~~~~ Character Sequences:\n", F_bWHITE );
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
    ColourCouter ( "----- Initialization of null-terminated character sequences:\n", F_bWHITE );
    ColourCouter ( "Arrays of characters and their different initializations.\n\n", F_YELLOW );
    // normal initialization of a null-terminated character sequence using an array (needs null character at the end)
    char a_word [] { 'W','o','r','d','\0' };
    // initialization of a null-terminated character sequence with a string literal using an array
    char two_words [] { "the word" };
    std::cout << "First array's string (initialized normally):" << nline << tab;
    print_simple_array_of_characters ( a_word, 5 );
    std::cout << "Second array's string (initialized by string literals):" << nline << tab;
    print_simple_array_of_characters ( two_words, 9 );
    a_word [0] = 'H';
    a_word [1] = 'i';
    a_word [2] = '\0';
    std::cout << "New string assigned to some elements of first array is:" << nline << tab;
    print_simple_array_of_characters ( a_word, 3 );

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
    ColourCouter ( "----- Strings and null-terminated character sequences:\n", F_bWHITE );
    ColourCouter ( "In standard library both representations of strings (C-string and library string) coexist.\n\n", F_YELLOW );
    ColourCouter ( "A demonstration that use both representations:\n", F_bYELLOW );
    char cString_1 [] { "Type your name to get stored to an array (C-string representation):" };
    std::string libString_1 { "Type your home country name to get stored to a library string variable:" };
    char cString_2 [100];
    std::string libString_2;
    std::cout << cString_1 << nline << tab << "- ";
    std::cin >> cString_2;
    std::cout << libString_1 << nline << tab << "- ";
    std::cin >> libString_2;
    std::cout << nline << "Howdy, " << cString_2 << " from " << libString_2 << "!" << nline << nline;

    //! - in addition:
    // in any case, null- terminated character sequences and strings are easily transformed from and to one another.
    // null-terminated character sequences can be transformed into strings implicitly.
    // transformation of strings into null-terminated character sequences can happen with string's member functions c_str or data and both are equivalent.
    ColourCouter ( "Null-terminated character sequences and strings are easily transformed from or to one another.\n", F_bYELLOW );
    char a_c_string [] { "-.^;^. a String .^;^.-" };
    std::string a_string = a_c_string; // implicit transformation into library string
    std::cout << "A string in C-string representation:" << nline;
    std::cout << tab << "- " << a_c_string << nline;
    std::cout << "The transformed string into library string representation:" << nline;
    std::cout << tab << "- " << a_string << nline;
    std::cout << "Inserting the string as C-string representation (c_str):" << nline;
    std::cout << tab << "- " << a_string.c_str () << nline; // print as a C-string
    std::cout << "Inserting the string as C-string representation (data):" << nline;
    std::cout << tab << "- " << a_string.data () << nline << nline; // print as a C-string
  }
  catch ( const std::exception& )
  {

  }
}


void _13_01_PointersBasics ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
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
    ColourCouter ( "~~~~~ Pointers:\n", F_bWHITE );
    ColourCouter ( "To obtain the address of a variable at runtime in order to access its relative data sells which are at a certain position.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- reference operator (&):
    // the ampersand sign (&) preceding the variable identifier can be used to obtain the address of it.
    // pointers are a kind of variable that can store the address of other variables.
    // for a language like C++ with a lot of uses in low-level programming pointers are a powerful feature.
    // Note reference operator (&) itself can be read as "address of"
    ColourCouter ( "----- Reference operator:\n", F_bWHITE );
    ColourCouter ( "The reference operator (&) can be used to obtain the address of the variable identifier.\n\n", F_YELLOW );
    int variable { 30 };
    int* pointer { &variable }; // declaring and assigning the address of a variable to a pointer
    std::cout << "Stored address of the variable in the pointer is:" << tab << pointer << nline << nline;

    //! ####################################################################
    //! ----- dereference operator (*):
    // to give it a more simple description, pointers point to the variable whose address they store.
    // an interesting property of pointers is, that by preceding the pointer identifier with asterisk sign (*),
    // pointers can be used to access the variable they point to directly.
    // Note dereference operator itself (*) can be read as "value pointed to by"
    // since reference and dereference operators are complementary, identified opposite meaning to know is:
    // an address obtained with ampersand (&) can be dereferenced with asterisk (*)
    ColourCouter ( "----- Dereference Operator (*):\n", F_bWHITE );
    ColourCouter ( "The dereference operator can be used to access the variable directly which the pointers point to.\n\n", F_YELLOW );
    int var_1 { 40 };
    int* ptr { &var_1 };
    int var_2 = var_1; // normal assignment
    var_2 = *ptr; // 'variable2' equal to value pointed to by 'ptr'
    std::cout << "The value pointed to by pointer and accessed directly by dereference operator is: " << var_2 << nline << nline;

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
    ColourCouter ( "----- Declaring Pointers:\n", F_bWHITE );
    ColourCouter ( "Different properties of the pointers when they directly refer to the values of variables justify the need to declare them with the needed specified data type.\n\n", F_YELLOW );

    int* anInteger;
    char* aCharacter;
    double* aDecimalValue;

    //! - in addition:
    // an example:
    // setting values to variables indirectly through pointers (using the memory location addresses of variables)
    // a pointer can point to different variables during its life time.
    ColourCouter ( "Indirectly setting values to variables through pointers.\n", F_bYELLOW );
    std::cout << "Look! a smily:" << tab;
    char a, b;
    char* thePointer;
    thePointer = &a;
    *thePointer = { '^' }; // assigning a character to the variable pointed by the pointer
    thePointer = &b;
    *thePointer = { ';' }; // the same
    std::cout << a << b << a << nline << nline;

    //! - in addition:
    // when declaring multiple pointers, each individual one needs an asterisk (*) in its declaration.
    // spaces aren't matter and it is even better to declare each pointer in a different statement.
    // to get familiar with the way to read each statement, pay attention to their following comments.
    ColourCouter ( "A more elaborated demonstration on setting new values:\n", F_bYELLOW );
    char c { '^' }, d { '_' }, e { '\0' };
    char* ptr_1, * ptr_2, * ptr_3; // asterisk (*) for each pointer -due to the precedence rules-
    ptr_1 = &c; // address of
    ptr_2 = &d; // the same
    ptr_3 = &e; // "
    *ptr_3 = c; // value pointed to by
    *ptr_1 = *ptr_2; // pointed values
    ptr_2 = ptr_3; // pointer's values (the addresses)
    d = *ptr_2; // value pointed to by
    std::cout << "Look! another smily:" << tab;
    std::string smily { "" };
    smily += d;
    smily += c;
    smily += d;
    std::cout << smily << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _13_02_PointersAndDataTypes ()
{
  try
  {
    //! ####################################################################
    //! ----- pointers and arrays:
    // the concepts of arrays and pointers are related, and they work very much like each other to their first elements.
    // implicitly the conversion of an array to a pointer of the proper type is possible.
    // whereas 'theArray' can never be assigned anything and will always represent the same block of 20 elements of type int.
    ColourCouter ( "----- Pointers and arrays\n", F_bWHITE );
    ColourCouter ( "Concepts of arrays and pointers are related.\n\n", F_YELLOW );
    int theArray [10];
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
    //a[3]=0; // a [offset of 3]
    //*(a+3)=0; // pointed to by (a+3)
    // no matter 'a' is an array or a pointer, these two expressions are equivalent and valid.
    // in case of an array, the array identifier refers to first element, just like a pointer.
    ColourCouter ( "Filling an array using pointers:\n", F_bYELLOW );
    char smilies [6];
    char* ptr;
    ptr = smilies;
    *ptr = '^';
    ptr++; *ptr = '_';
    ptr = &smilies [2]; *ptr = '^';
    ptr = smilies + 3; *ptr = '^';
    ptr = smilies; *( ptr + 4 ) = '.';
    *( ptr + 5 ) = '^';
    std::cout << "The filled array (array way print):" << nline << tab;
    for ( int i = 0; i < 6; i++ )
    {
      std::cout << smilies [i]; // array way
      if ( i == 2 )
        std::cout << tab;
    }
    std::cout << nline << "The filled array (pointer way print):" << nline << tab;
    for ( int i = 0; i < 6; i++ )
    {
      std::cout << *( ptr + i ); // pointer way
      if ( i == 2 )
        std::cout << tab;
    }
    std::cout << nline << nline;

    //! ####################################################################
    //! ----- pointer initialization:
    // the initialization of pointers can be introduced at the very moment of their declaration.
    // what is going to be initialized is the address to be pointed to and never the value stored in memory.
    // pointers can be initialized not only to the address of a variable, but also to the value of another pointer or array.
    ColourCouter ( "----- Pointer Initialization:\n", F_bWHITE );
    ColourCouter ( "Like variables initialization of pointers can be done at the moment of declaration.\n\n", F_YELLOW );
    int aVariable { 10 }; // a variable
    int* firstPointer { &aVariable }; // point to address of variable
    int anArray [3] { 20 }; // an array
    int* secondPointer { firstPointer }; // point to the value of a pointer
    int* thirdPointer { anArray }; // point to an array
    std::cout << "First pointer's value and pointed value (initialized using a variable) are:" << nline << tab << firstPointer << tab << *firstPointer << nline;
    std::cout << "Second pointer's value and pointed value (initialized using first pointer) are:" << nline << tab << secondPointer << tab << *secondPointer << nline;
    std::cout << "First pointer's value and pointed value (initialized using an array) are:" << nline << tab << thirdPointer << tab << *thirdPointer << nline << nline;

    //! ####################################################################
    //! ----- pointer arithmetics:
    // when conducting arithmetical operations on pointers, there are these differences to pay attention to:
    // first of all only addition and subtraction operations are allowed.
    // even these two allowed operations have slightly different behaviours, since types have different sizes,
    // and this size is going to be added or subtracted to the stored address value in pointers.
    // on the other hand the exact size of data types is also dependent on the system.
    ColourCouter ( "----- Pointer arithmetics:\n", F_bWHITE );
    ColourCouter ( "Arithmetical operations on pointers result in different behaviours and outputs than regular integer types.\n\n", F_YELLOW );
    char Char { 'A' };
    char* ptrChar { &Char };
    short Short { 222 };
    short* ptrShort { &Short };
    long Long { 333333 };
    long* ptrLong { &Long };
    std::cout << "The address values and the values pointed to before the addition:" << nline;
    std::cout << "ptrChar is:" << tab << ptrChar << tab << *ptrChar << nline;
    std::cout << "ptrShort is:" << tab << ptrShort << "\t\t\t\t" << *ptrShort << nline;
    std::cout << "ptrLong is:" << tab << ptrLong << "\t\t\t\t" << *ptrLong << nline;
    ++ptrChar;
    ++ptrShort;
    ++ptrLong;
    std::cout << "The address values and the values pointed to after the addition:" << nline;
    std::cout << "ptrChar is:" << tab << ptrChar << tab << *ptrChar << nline;
    std::cout << "ptrShort is:" << tab << ptrShort << "\t\t\t\t" << *ptrShort << nline;
    std::cout << "ptrLong is:" << tab << ptrLong << "\t\t\t\t" << *ptrLong << nline << nline;

    // combinations: dereference operator with both prefix or postfix versions of increment or decrement operators
    // increment/decrement operator: higher priority (left-to-right)
    // reference/dereference operator: lower priority (right-to-left)
    // as always parenthesis reduce confusion and add legibility to expressions.
    // postfix: *p++ = *q++;   is roughly equivalent to:   *p = *q; ++p; ++q;
    ColourCouter ( "Four possible combinations of dereference operator with both prefix or postfix versions of increment or decrement operators:\n", F_bYELLOW );
    int variable { 0 };
    int* pointer;
    int temp;
    std::cout << "The stored value in the variable is:" << "\t\t" << variable << nline;
    ColourCouter ( "The temp variable is the additional storage for each operation, so the results could be shown.\n\n", F_bCYAN );
    pointer = &variable;
    std::cout << "pointer value is:" << "\t\t\t\t" << pointer << nline;
    temp = *pointer++; // same as *(pointer ++): increment pointer, and dereference un-incremented address
    std::cout << "pointer after operation *pointer++ is:" << "\t\t" << pointer << nline;
    std::cout << "result of operation *pointer++ is:" << "\t\t" << temp << nline << nline;
    //
    pointer = &variable;
    std::cout << "pointer value is:" << "\t\t\t\t" << pointer << nline;
    temp = *++pointer; // same as *(++pointer): increment pointer, and dereference incremented address
    std::cout << "pointer after operation *++pointer is:" << "\t\t" << pointer << nline;
    std::cout << "result of operation *++pointer is:" << "\t\t" << temp << nline << nline;
    //
    pointer = &variable;
    std::cout << "pointer value is:" << "\t\t\t\t" << pointer << nline;
    temp = ++ * pointer; // same as ++(*pointer): dereference pointer, and increment the value it points to
    std::cout << "pointer after operation ++*pointer is:" << "\t\t" << pointer << nline;
    std::cout << "result of operation ++*pointer is:" << "\t\t" << temp << nline << nline;
    //
    pointer = &variable;
    std::cout << "pointer value is:" << "\t\t\t\t" << pointer << nline;
    temp = ( *pointer )++; // dereference pointer, and post-increment the value it points to.
                           // without parenthesis the incrementation happens to the pointer itself too.
    std::cout << "pointer after operation (*pointer)++ is:" << tab << pointer << nline;
    std::cout << "result of operation (*pointer)++ is:" << "\t\t" << temp << nline << nline;

  }
  catch ( const std::exception& )
  {

  }
}


void flag_prime_numbers ( const int* begin, const int* end, bool* flag )
{
  const int* element = begin;
  while ( element != end )
  {
    if ( *element % 2 == 0 )
      * flag = true;
    else
      if ( *element % 3 == 0 )
        * flag = true;
      else
        if ( *element % 5 == 0 )
          * flag = true;
        else
          if ( *element % 7 == 0 )
            * flag = true;
    ++element;
    ++flag;
  }
}
void print_prime_numbers ( const int* begin, const int* end, const bool* flag )
{
  const int* element = begin;
  while ( element != end )
  {
    if ( *flag == false )
      std::cout << *element << Tab;
    ++element;
    ++flag;
  }
  std::cout << Nline << Nline;
}
void _13_03_PointersAndLiterals ()
{
  try
  {
    //! ####################################################################
    //! ----- pointers and constants:
    // to access variables by pointers read-only, it is enough to qualify the type pointed to as constant.
    // pointers to non-const are implicitly convertible to pointers to constant, but as a safety feature, the other way around isn't possible.
    ColourCouter ( "----- Pointers and Constants:\n", F_bWHITE );
    ColourCouter ( "To access a variable for just reading purposes, not modifying.\n\n", F_YELLOW );
    int a;
    int b { 5 };
    const int* const_ptr { &b }; // points to a variable but in a constant-qualified manner
                                 // allowed (non-const type (address of) to constant):
                                 // the type of y is int* and is assigned to a pointer of type constant int*.
    a = *const_ptr; // ok: reading constant-qualified pointer
    //*const_ptr = a; // error: modifying constant-qualified pointer
    std::cout << "The value accessed by a constant-qualified pointer is:" << tab << a << nline << nline;

    //! - in addition:
    // one of the use cases: function parameters can include pointers to constant elements to prevent modifications on the passed arguments.
    // to be more clear: pointers that are constant type qualified (point to constant content), can still point to new addresses, but they can not modify the pointed content.
    ColourCouter ( "Two functions mixing the use of normal and constant-qualified pointers as parameters:\n", F_bYELLOW );
    const int count { 5 };
    int the_array [count] { 11,12,13,14,15 };
    bool bool_array [count] { false };
    std::cout << "The array elements are:" << nline << tab;
    for ( int i = 0; i < count; i++ )
    {
      std::cout << the_array [i] << tab;
    }
    std::cout << nline << nline;
    std::cout << "The prime ones are:" << nline << tab;
    flag_prime_numbers ( the_array, the_array + count, bool_array );
    print_prime_numbers ( the_array, the_array + count, bool_array );

    //! - in addition:
    // constant pointers:
    // a second dimension to the constness of pointers is that the pointers themselves can also be constant.
    // to define a pointer as constant the 'const' keyword needs to be appended to the pointed type (after the asterisk).
    // the syntaxes concerning pointers and their constant aspects are tricky,
    // therefore it needs a grow experience to recognise best suited use cases.
    // a sooner deep understanding of constness, pointers and references is of course better.
    ColourCouter ( "Pointers themselves can also be constant.\n", F_bYELLOW );
    int x_var { 1 };
    int* ptr1 { &x_var }; // non-const pointer to non-const int
    const int* ptr2 { &x_var }; // non-const pointer to constant int
    int* const ptr3 { &x_var }; // constant pointer to non-const int
    const int* const ptr4 { &x_var }; // constant pointer to constant int
    std::cout << "The value of variable dereferenced four times:" << "\t\t" << *ptr1 << tab << *ptr2 << tab << *ptr3 << tab << *ptr4 << nline;

    //! - in addition:
    // the above syntaxes get even more complex by considering,
    // that the pointed type can either be preceded or followed by the constant qualifier and both exact same meaning.
    // the order of constant qualifier like the surrounding spaces of asterisk is simply a matter of style.
    // on the internet the discussion on the merits of each still goes on intensely.
    const int* ptr5 { &x_var }; //      non-const pointer to constant int
    int const* ptr6 { &x_var }; // also non-const pointer to constant int
    std::cout << "The value of variable dereferenced again two times:" << tab << *ptr5 << tab << *ptr6 << nline << nline;


    //! ####################################################################
    //! ----- pointers and string literals:
    // additional to direct insertion into cout, initialization of strings and arrays of character,
    // string literals can be accessed directly by pointers.
    // another description for string literals: arrays of proper array type to contain all its character plus null-character and each element of type constant char (literals are not modifiable).
    // each element of a character sequence is accessible by a pointer that point to the sequence, exactly like it is accessible using the same array way.
    // the reason: already described fact, that arrays and pointers behave essentially the same way in expressions.
    ColourCouter ( "----- Pointers and string literals:\n", F_bWHITE );
    ColourCouter ( "By using pointers string literals can be accessed directly.\n\n", F_YELLOW );
    const char* Ptr_StrLit { "Way to go!" }; // a pointer pointed to an array of respected literal representation
    std::cout << "Accessing a character sequence directly in usual array and pointer way:" << nline << tab;
    for ( int i = 0; i < 10; i++ )
    {
      std::cout << Ptr_StrLit [i]; // accessing in usual array way
      if ( Ptr_StrLit [i] != '!' )
        std::cout << '.';
    }
    std::cout << "\t\t";
    for ( int i = 0; i < 10; i++ )
    {
      std::cout << *( Ptr_StrLit + i ); // accessing in usual pointer way
      if ( *( Ptr_StrLit + i ) != '!' )
        std::cout << '.';
    }
    std::cout << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void void_parameter ( void* void_ptr, int size )
{
  if ( size == sizeof ( char ) )
  {
    char* char_ptr;
    char_ptr = static_cast<char*>( void_ptr );
    // uppercase/lowercase switch (ASCII code of character)
    if ( *char_ptr < 97 )
      * char_ptr += 32;
    else
      *char_ptr -= 32;
  }
  if ( size == sizeof ( int ) )
  {
    int* int_ptr;
    int_ptr = static_cast<int*>( void_ptr );
    // square
    *int_ptr *= *int_ptr;
  }
}
void _13_04_MoreOnPointers ()
{
  try
  {
    //! ####################################################################
    //! ----- pointers to pointers:
    // C++ provides the use of pointers that point to pointers.
    // the result is a defined pointer that in different levels of indirection points to data or even other pointers.
    // the declaration syntax simply requires an additional asterisk for each level of indirection.
    ColourCouter ( "----- Pointers to pointers:\n", F_bWHITE );
    ColourCouter ( "In C++ pointers are allowed to point to pointers.\n\n", F_YELLOW );
    int int_var { 89 };
    int* int_ptr { &int_var };
    int** int_ptr_ptr { &int_ptr }; // a pointer to pointer, useable in three different levels of indirection and each one correspond to a different value.
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
    ColourCouter ( "----- Void pointers:\n", F_bWHITE );
    ColourCouter ( "Void pointers are able to point to values without any infos on their exact types.\n\n", F_YELLOW );
    char _char { 'A' };
    int _int = 24;
    std::cout << "Values ready to be passed are:" << nline << tab << _char << tab << _int << nline;
    void_parameter ( &_char, sizeof ( _char ) );
    void_parameter ( &_int, sizeof ( _int ) );
    std::cout << "The result values are:" << nline;
    std::cout << tab << _char << tab << _int << nline << nline;

    //! ####################################################################
    //! ----- invalid pointers and null pointers:
    // while pointers are meant to point to valid addresses, they can actually point to any address,
    // including addresses that refer to no valid element like uninitialized variables and non-existent elements of an array.
    // this fact introduces invalid pointers in C++, which means that a pointer can take any address value,
    // no matter whether there actually something is stored or not.
    ColourCouter ( "----- Invalid pointers and null pointers:\n", F_bWHITE );
    ColourCouter ( "In C++ pointers can point to any address values, no matter their storage state.\n\n", F_YELLOW );
    // the two pointer definitions below, while not pointing to any address with value, aren't cause of any compile error.
    // but dereferencing them is a different story and causes runtime error or undefined behaviours
    int* ptr_1; // uninitialized pointer (local variable) (no error)
    int theArray [2] { 0 };
    int* ptr_2 { &theArray [4] }; // element out of bound (no error)
    //std::cout << ptr_1 << nline; // error: used without initialization
    std::cout << "The pointed address is (out of bound of the array addresses):" << tab << ptr_2 << nline << nline;

    //! - in addition:
    // as in past sections somewhat described: null pointers: pointers can NULL, 0 or nullptr to represent that they point to nowhere.
    // null pointers satisfy the need of explicit point to nowhere, and not just an invalid address.
    // all null pointers compare equal to other null pointers.
    // Note as already described: void pointers: point to somewhere without a specific type
    int* ptr_a { 0 };
    int* ptr_b { nullptr };
    int* ptr_c { NULL }; // quite usual in old codes: using the defined constant NULL to refer to null pointer value
                     // NULL is defined in several headers of the standard library
                     // it is also defined as an alias of some null pointer constant such as 0 or nullptr
    std::cout << "The pointed addresses of defined null pointers are:" << nline;
    std::cout << tab << ptr_a << tab << ptr_b << tab << ptr_c << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


int increment ( int param )
{
  return ++param;
}
int decrement ( int param )
{
  return --param;
}
int operation_FunctionCaller ( int param, int ( *function ) ( int ) )
{
  // calling the wished function using its stored executable address which is passed as argument
  return ( *function ) ( param );
}
void _13_05_PointersToFunctions ()
{
  try
  {
    //! ####################################################################
    //! ----- pointers to functions:
    // in C++ operations with pointers to function are allowed, they point to the executable function code,
    // and their typical uses are to call a function and to pass a function as an argument to another function.
    // pointers arithmetic aren't performable on the pointers to functions.
    // regular function declaration is the source for declaring pointers to function,
    // except that the pointer identifier is followed by an asterisk * and enclosed in parenthesis ().
    // parenthesis are needed and alter the higher precedence of function parameters.
    ColourCouter ( "----- Pointers to functions:\n", F_bWHITE );
    ColourCouter ( "Pointers to functions are introduced to call a function or to pass a function as argument to another function.\n\n", F_YELLOW );
    int a { 10 }, b { 15 }, c { 20 }, d { 25 };
    std::cout << "The passed values are:" << "\t\t\t\t" << a << ", " << b << ", " << c << ", " << d << nline;
    int ( *decrease )( int ) = decrement; // a pointer to function (two parameters and direct initialization)
    a = decrement ( a ); // calling the function itself
    b = decrease ( b ); // calling the pointer to function
    c = operation_FunctionCaller ( c, increment ); // passing the function itself
    d = operation_FunctionCaller ( d, decrease ); // passing the pointer to function
    std::cout << "First result (function itself):" << "\t\t\t" << a << nline;
    std::cout << "Second result (pointer to function):" << "\t\t" << b << nline;
    std::cout << "Third result (passing the function itself):" << tab << c << nline;
    std::cout << "Forth result (passing pointer to function):" << tab << d << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _14_01_DynamicMemory ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ dynamic memory:
    // to this point of tutorial all needed memory was determined by defining the variables before the program execution.
    // there may be cases to determine the memory needs of a program on runtime, like when needed memory depends of user input.
    // for these cases C++ integrates operators 'new' and 'delete' to dynamically allocate memory.
    ColourCouter ( "~~~~~ Dynamic memory:\n", F_bWHITE );
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
    ColourCouter ( "----- Operators new and new[]:\n", F_bWHITE );
    ColourCouter ( "The integrated operator new is to be used to allocate dynamic memory.\n\n", F_YELLOW );
    int* ptr1;
    ptr1 = new int; // allocate memory to contain one single element of type int
    *ptr1 = 10;
    std::cout << "The address and value of dynamic allocated memory are:" << nline << tab << ptr1 << tab << *ptr1 << nline;
    // the substantial difference between declaring normal arrays and allocating dynamic memory is,
    // that allocation happens during runtime and the size is any variable value.
    char* ptr2;
    ptr2 = new char [3]; // allocate a block (an array) of char elements
    for ( int i = 0; i <= 2; i++ )
    {
      *( ptr2 + i ) = '$'; // accessing in usual pointer way
    }
    std::cout << "The address of first element of the dynamic allocated memory is:" << nline << tab << ptr2 << nline;
    std::cout << "The elements stored in the allocated memory are:" << nline << tab;
    for ( int i = 0; i <= 2; i++ )
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
    ptr3 = new ( std::nothrow ) int [3];
    if ( ptr3 == nullptr )
      std::cout << "Error assigning memory!" << nline;
    else
    {
      for ( int i = 0; i <= 2; i++ )
        ptr3 [i] = 5; // accessing in usual array way
      std::cout << "The address of first element of the dynamic allocated memory is:" << nline << tab << ptr3 << nline;
      std::cout << "The elements stored in the allocated memory are:" << nline << tab;
      for ( int i = 0; i <= 2; i++ )
        std::cout << ptr3 + i << tab; // accessing in usual pointer way
      std::cout << nline << nline;
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
    ColourCouter ( "----- Operators delete and delete[]:\n", F_bWHITE );
    ColourCouter ( "The integrated operator delete is to be used to free the allocated dynamic memory.\n\n", F_YELLOW );
    std::string inStr { "" };
    int number { 0 }, counter { 0 };
    int* pointer;
    std::cout << "Enter a number (enter 'bye' to exit):" << tab;
    std::getline ( std::cin, inStr );
    while ( inStr != "bye" )
    {
      std::stringstream ( inStr ) >> number;
      if ( ( number / 2 ) > 500 )
        counter = 20;
      else
        counter = 15;
      pointer = new( std::nothrow ) int [counter]; // reckoned form user entered value so not a constant
      if ( pointer == nullptr )
        std::cout << nline << "Error: memory couldn't be allocated!" << nline;
      else
      {
        int j { 0 };
        for ( int i = 1; i <= number; i++ )
        {
          if ( number % i == 0 )
          {
            pointer [j] = i;
            j++;
          }
          if ( j == counter )
            break;
        }
        if ( ( j < counter ) && ( number != 1 ) )
          pointer [j] = number;
        std::cout << "Some of the divisors are:" << nline << tab;
        for ( int i = 0; i < j; i++ )
        {
          std::cout << pointer [i]; // pointer way: *(_pointer + i)
          if ( ( i + 1 ) != j )
            std::cout << ", ";
        }
        std::cout << nline << nline << "Enter another number (enter 'bye' to exit):" << tab;
        std::getline ( std::cin, inStr );
      }
      delete [] pointer;
    }
    std::cout << nline;

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


struct phone
{
  std::string model;
  int year;
} mine; // optional field object_names in practice
void print ( phone info )
{
  std::cout << tab << "- " << info.model << " bought in year (" << info.year << ")" << Nline;
}
struct smily
{
  char signs [4] { ';', '.', '_', '^' };
  std::string title [3] { "moustache", "mouth", "lips" };
  int index { 0 };
};
void _15_01_DataStructures ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
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
    ColourCouter ( "~~~~~ Data structures:\n", F_bWHITE );
    ColourCouter ( "To introduce grouped data elements with different types and different lengths under one name.\n\n", F_YELLOW );
    phone yours; // after declaration used just like any other type
    std::string strTemp;
    mine.model = "LG M700 Q6";
    mine.year = 2018;
    std::cout << "Enter the model of your smartphone:" << tab;
    std::getline ( std::cin, yours.model );
    std::cout << "In which year you have bought it?" << tab;
    std::getline ( std::cin, strTemp );
    std::stringstream ( strTemp ) >> yours.year;
    std::cout << nline << "My smartphone model is:" << nline;
    print ( mine );
    std::cout << "Your smartphone model is:" << nline;
    print ( yours );
    std::cout << nline;

    //! - in addition:
    // using structures as type of arrays to construct tables or databases.
    ColourCouter ( "An array with data structure as its type:\n", F_bYELLOW );
    smily some [3];
    for ( int i = 0; i < 3; i++ )
      some [i].index = i;
    std::cout << "These smilies are built:" << nline;
    for ( int i = 0; i < 3; i++ )
    {
      std::cout << tab << some [i].signs [3] << some [i].signs [i] << some [i].signs [3] << tab;
      std::cout << some [i].title [i] << nline;
    }
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
    // Note in case *a.b, equivalent to *(a.b), the object member is a pointer type,
    // if not, the evaluation results in accessing a hypothetical pointer member called 'b', which isn't the case.
    ColourCouter ( "----- Pointers to structures:\n", F_bWHITE );
    ColourCouter ( "Structures can be pointed to by their own type of pointers.\n\n", F_YELLOW );
    std::string temp { "" };
    phone aPhone;
    phone* ptrPhone;
    ptrPhone = &aPhone;
    std::cout << "Accessing phone structure using pointers:" << nline;
    std::cout << "Enter your smartphone model:" << tab;
    std::getline ( std::cin, ptrPhone->model ); // for all purposes, equivalent to: (*ptrMovie_t).title
    std::cout << "Enter the bought year:" << tab;
    std::getline ( std::cin, temp );
    std::stringstream ( temp ) >> ptrPhone->year;
    std::cout << nline << "You have entered:" << nline;
    print ( aPhone );
    std::cout << nline;

    //! ####################################################################
    //! ----- nesting structures:
    // elements of a structure can also be of structure type, the result is then a nested structure.
    ColourCouter ( "----- Nesting structures:\n", F_bWHITE );
    ColourCouter ( "To introduce elements in a structure that themselves are also structures.\n\n", F_YELLOW );
    struct owner
    {
      std::string name;
      std::string email;
      phone _phone;
    } anna, john;
    owner* ptrOwner = &john;
    anna.name = "Anna";
    anna.email = "anna@gmail.com";
    anna._phone.model = "IPhone 6";
    anna._phone.year = 2016;
    john.name = "John";
    ptrOwner->email = "john@gmail.com";
    john._phone.model = "Samsung Galaxy";
    john._phone.year = 2015; // equivalent to next expression
    ptrOwner->_phone.year = 2015; // equivalent to next expression
    ( *ptrOwner )._phone.year = 2015;
    ColourCouter ( "A demonstration of a nested structure:\n", F_bYELLOW );
    std::cout << "Anna and John's smartphones model are:" << nline;
    std::cout << anna.name << nline;
    std::cout << anna.email << nline;
    print ( anna._phone );
    std::cout << john.name << nline;
    std::cout << ptrOwner->email << nline;
    print ( ( *ptrOwner )._phone );
    std::cout << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _16_01_OtherDataTypes ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ other data types:
    // 
    ColourCouter ( "~~~~~ Other data types:\n", F_bWHITE );
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
    ColourCouter ( "----- Type aliases (typedef / using):\n", F_bWHITE );
    ColourCouter ( "To introduce different identifiers as alias for any valid type.\n\n", F_YELLOW );
    typedef int I; // obvious
    typedef unsigned char COUNTER; // COUNTER is alias for unsigned char
    typedef char* ptrChar; // ptrChar is alias for char*
    typedef char name [30]; // Note name is alias for char [20]
    I theInteger { 10 }, aInteger { 20 }, * ptrInt1 { &theInteger };
    COUNTER theCounter { 50 };
    I* ptrInt2 { &aInteger };
    name myName { "Mehrdad" };
    using L = long;
    using Decimal = double;
    using ptrInt = int*;
    using surname = char [40];

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
    ColourCouter ( "----- Unions:\n", F_bWHITE );
    ColourCouter ( "To share one portion of memory between members with different date types.\n\n", F_YELLOW );
    union theTypes
    {
      char character;
      long number;
      double floating;
    } first;
    first.character = 'A';

    //! - in addition:
    // one interesting purpose of unions is to access a value both ways,
    // that is, in its entirety or as an array or structure of similar elements.
    // the example below explains it more precise.
    // Note this feature is likely to create portability issues,
    // since the exact alignment and order of union members in memory is system dependent.
    std::cout << "Accessing an union in its entirety, as structure and as array:" << nline;
    union mixed_types
    { // assumptions (as already explained fundamental type sizes are system dependent):
      int allBytes; // 4 byte (entirety access)
      struct
      {
        short highBytes; // 2 byte (access in structure form)
        short lowBytes; // 2 byte
      } highLow;
      char Byte [4]; // 4*1 byte (access in array form)
    } mix;
    mix.allBytes = 0x22222222;
    std::cout << "In entirety:" << "\t\t\t" << mix.allBytes << nline;
    std::cout << "Low and high bytes (structure):" << tab << mix.highLow.highBytes << tab << mix.highLow.lowBytes << nline;
    std::cout << "Byte by Byte (array):" << "\t\t";
    for ( unsigned char i = 0; i < 4; i++ )
    {
      std::cout << mix.Byte [i] << tab;
    }
    std::cout << nline << nline;

    //! ####################################################################
    //! ----- anonymous unions:
    // an union can be defined with no name, if its declaration happens within a class or structure.
    // after declaring an union anonymous, its members are accessible from objects by member names.
    // as already explained, an union share a space between its members.
    ColourCouter ( "----- Anonymous unions:\n", F_bWHITE );
    ColourCouter ( "By declaring an union without any name in a class or structure, they become anonymous unions.\n\n", F_YELLOW );
    struct person
    {
      char name [50];
      char email [50];
      union
      {
        short day;
        short month;
      } birthday; // a normal union
      union
      {
        short day;
        short month;
      }; // an anonymous union
    } mine;
    mine.birthday.day = 3;
    mine.day = 3;
    std::cout << "The value is (normal union):" << tab << mine.birthday.day << nline;
    std::cout << "The value is (anonymous union):" << tab << mine.day << nline << nline;

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
    ColourCouter ( "----- Enumerated types (enum):\n", F_bWHITE );
    ColourCouter ( "To introduce a set of custom identifiers, known as enumerators, as possible values.\n\n", F_YELLOW );
    enum seasons_t { spring, summer, autumn, winter }; // a total new data type
    seasons_t theSeason;
    theSeason = spring;
    if ( theSeason == spring )
      theSeason = summer;
    std::cout << "The value of 'theSeason' variable is:" << nline << tab << theSeason << nline;

    //! - in addition:
    // enumerators of an enumerated type declared with enum are always assigned integer values internally,
    // which make it possible to implicitly convert the enumerators to and from these integer values.
    // if not explicitly specified, the first enumerator's internal integer value is zero (0).
    // the following values then get plus one, each one after another.
    // it is also possible to assign arbitrary integer values to enumerators.
    enum week_t
    {
      Monday = 1, Thursday, Wednesday, Tuesday,
      Friday, Saturday, Sunday
    } _week;
    _week = Sunday;
    int val { _week };
    std::cout << "The values of variables are:" << nline << tab << _week << tab << val << nline << nline;

    //! ####################################################################
    //! ----- enumerated types with enum class:
    // in C++, real enum types can be created with enum class (or enum struct),
    // to preserve safety, the enumerator values are of the enum type itself,
    // therefore lacking enumerator values of type int, the conversion to int isn't possible.
    // each enumerator value of an enum class is accessible only with scoping into its type,
    // this way of access is also available in normal enum types, but it is just optional.
    ColourCouter ( "----- Enumerated types with enum class:\n", F_bWHITE );
    ColourCouter ( "To introduce real enum types that preserve safety.\n\n", F_YELLOW );
    enum class Seasons { spring, summer, autumn, winter };
    Seasons aSeason;
    aSeason = Seasons::spring; // the needed scoping into the type
    if ( aSeason == Seasons::spring )
      aSeason = Seasons::autumn;
    std::cout << "The value of 'aSeason' variable is:" << nline << tab << static_cast<int>( aSeason ) << nline;

    //! - in addition:
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
    enum class sports_t : unsigned short
    {
      football, tennis, golf, baseball
    }; // a distinct type (underlying type size is the size of short)
    std::cout << "The size of 'sports_t' type is:" << nline << tab << sizeof ( sports_t ) << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}
