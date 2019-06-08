// --------------------------------------------------------------------------------
/// <summary>
/// _5_Classes.cpp
/// </summary>
/// <created>ʆϒʅ,18.09.2018</created>
/// <changed>ʆϒʅ,09.06.2019</changed>
// --------------------------------------------------------------------------------

//#include "pch.h"
#include "LearningCplusPlus.h"
#include "Console.h"


#define Tab '\t'
#define Nline '\n'

const char tab { '\t' };
const char nline { '\n' };


class Number
{
private:
  int entity; // by default: private members
public:
  void set_value ( int ); // declaration but not definition (prototype)
  void print ( void )
  {
    std::cout << Tab << "-Value:" << Tab << entity << Nline;
  }
  int square ( void ) { return entity * 2; } // declaration and definition
};
void Number::set_value ( int a ) // scope operator: class member is defined outside
{
  entity = a;
}
void _17_01_ClassesI ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ Classes I:
    // C++ language introduces classes as an expansion to data structures,
    // additionally to data members, they can contain functions as members.
    // an instantiation of a class result in an object
    // putting the concept of classes in that of variables, classes are types and objects are variables.
    // Note keywords: classes can be defined using keywords 'class' or 'struct'
    // Note syntax:
    // class class_name {
    // access_specifier1;
    // member1;
    // access_specifier2;
    // member2;
    // ...
    // } object_names;
    // declaration body contains members (data or function declaration), also optionally access specifiers.
    // access right of members get modified using access specifiers, which precede them.
    // Note access specifiers keywords: 'private' 'protected' 'public'
    // private: accessible form the members of the same class (or their 'friends')
    // protected: additionally to that of private, members are accessible from members of their derived classes
    // public: access to members is granted from everywhere, in which the object is visible
    // the default access specifier is private,
    // which is valid for every member declared using no access specifier, that is implicitly.
    // Note considering compiler differences, explicit way is always considered a better practice.
    // note that restrictions on data members of a class prevent modifications in an unexpected way.
    // since the class's data members get instantiated to be the properties of objects,
    // from the view point of objects, no unexpected modification should happens to their properties,
    // with other words, they must have full control on the art of modification procedure.

    //! - in addition:
    // definition of a class member outside of the class itself:
    // scope operator (::) (earlier in relation to namespaces)
    // scope operator grants the same scope properties, as when the member been defined within the class definition.
    // therefore it specifies the class of the member, while being defined outside.
    // a function defined completely within the class itself is automatically considered as inline.
    // when only its definition is included within the class, compiler considers it a normal (non-inline) class member.
    // the only difference being already mentioned, the behaviour stays the same,
    // thus in the end it may come to a possible compiler optimization.
    ColourCouter ( "~~~~~ Classes I:\n", F_bBLUE );
    ColourCouter ( "Classes are an expanded concept of data structure with the ability, not only containing data members but also functions as members.\n\n", F_YELLOW );
    class Number first;
    // like data structures, dot (.) method is used to directly access members either data or function of a class
    first.set_value ( 3 );
    first.print ();
    std::cout << "Of which the square is:" << tab << first.square () << nline;
    class Number second;
    second.set_value ( 5 );
    second.print ();
    std::cout << "Of which the square is:" << tab << second.square () << nline << nline;
    // object-oriented paradigms are implemented in programming using classes,
    // this means that an object instantiated from a class, has its members either data or function implemented within,
    // therefore the concept reduces the passing and carrying of handlers or other state variables as arguments to functions.

    //! - in addition:
    // classes defined using keywords 'struct' or 'union':
    //-- the keyword struct:
    // same syntax as keyword 'class' is needed and the only difference is that default access specifier is 'public'.
    //-- the keyword 'union'
    // despite different concepts with that of classes defined using keywords 'class' or 'struct',
    // unions are also classes, thus hold member functions.
    // default access specifier of unions is 'public'
  }
  catch ( const std::exception& )
  {

  }
}


class numberEntity
{
  int entity;
public:
  numberEntity ( int ); // constructor prototype (only declaration)
  // the default constructor:
  numberEntity (); // overloaded constructor prototype
  void print ( void )
  {
    std::cout << Tab << "-Value:" << Tab << entity << Nline;
  }
  int square ( void ) { return entity * 2; }
};
numberEntity::numberEntity ( int a ) // constructor definition
{
  entity = a;
}
numberEntity::numberEntity () // overloaded constructor definition
{
  entity = 0;
}
void _17_02_Constructors ()
{
  try
  {
    //! ####################################################################
    //! ----- constructors:
    // a call to a member function that uses uninitialized data members, causes undetermined results,
    // which can get avoided, considering the best practice, using the special member function known as constructor.
    // instantiation of an object automatically calls the constructor of class,
    // with the most obvious purpose, initialization of data members and allocation of the needed memory.
    // a constructor can be declared like regular functions, its identifier matches to that of the class itself,
    // while having the same structure, a constructor introduces no return type, not even void.
    // to add to the peculiarity of this special member function, a constructor can never get called explicitly,
    // therefore unlike regular functions, constructors are executed once at the instantiation moment of objects.
    ColourCouter ( "----- Constructors:\n", F_bBLUE );
    ColourCouter ( "A special member function to initialize data members or allocate memory.\n\n", F_YELLOW );
    ColourCouter ( "The class 'number' improved to introduce its constructor:\n", F_bYELLOW );
    class numberEntity first ( 2 ); // initialization at the moment of instantiation using class constructor
    numberEntity second ( 3 ); // no error, class has a constructor present, thus the 'class' keyword is optional
    first.print ();
    std::cout << "Of which the square is:" << tab << first.square () << nline << nline;

    //! ####################################################################
    //! ----- overloading constructors:
    // any regular function likewise, a constructor can be overloaded with different number or type of parameters.
    // being able to overload constructors, the default constructor can also get introduced,
    // which is the special kind, that takes no parameters.
    ColourCouter ( "----- Overloading constructors\n", F_bBLUE );
    ColourCouter ( "Constructors can also introduce different overloads.\n\n", F_YELLOW );
    numberEntity third ( 4 );
    third.print ();
    std::cout << "Of which the square is:" << tab << third.square () << nline << nline;
    ColourCouter ( "Instantiating using the default constructor:\n", F_bYELLOW );
    numberEntity forth; // Note without parenthesis
    forth.print ();
    std::cout << "Of which the square is:" << tab << forth.square () << nline << nline;

    //! - in addition:
    numberEntity fifth (); // declaration of a new function
    // Note peculiarity: default constructor is called using no parenthesis,
    // since following the object declaration with empty set of parenthesis introduces it as a new function,
    // which takes no parameters and returns a value of type class
  }
  catch ( const std::exception& )
  {

  }
}


class Smily
{
private:
  char signs [5] { '-', ';', '.', '_', '^' };
  std::string title [4] { "nose", "moustache", "mouth", "lips" };
  int index;
public:
  Smily () { index = 0; print (); }
  Smily ( int i ) { index = i; print (); }
  void print ( void )
  {
    std::cout << "The smily:" << Tab << signs [4] << signs [index] << signs [4] << tab << title [index] << Nline;
  }
};
void _17_03_UniformInitialization ()
{
  try
  {
    //! ####################################################################
    //! ----- uniform initialization:
    // beside the above way to call constructors known as functional form,
    // which encloses their parameters in parenthesis, there are also other syntaxes for constructors to be called.
    // Note syntax: variable initialization
    // usable for constructors with a single parameter
    // --class_name object_name = initialization_value;
    // Note syntax: uniform initialization
    // recently introduced in C++, essentially the same as functional form, but using braces
    // --class_name object_name {value, value, value, ...}
    // optionally, this syntax can include an equal sign before the braces.
    ColourCouter ( "----- Uniform initialization:\n", F_bBLUE );
    ColourCouter ( "There are different ways for a constructor to be called.\n\n", F_YELLOW );
    Smily a ( 0 ); // functional form
    Smily b = 1; // assignment initialization
    Smily c { 2 }; // uniform initialization
    Smily d = { 3 }; // uniform initialization plus equal (POD type-like)
    std::cout << nline;

    //! - in addition:
    // advantage of using uniform initialization:
    // using braces no confusion is possible with function declaration,
    // thus provides the ability to explicitly call the default constructor.
    Smily x; // default constructor called
    Smily y (); // a function declaration
    Smily z {}; // default constructor called
    std::cout << nline;

    //! - in addition:
    // the chosen syntax to call constructors is largely seen as a matter of style.
    // currently most existing code uses the functional form.
    // despite the newer style guides suggestion to use uniform initialization,
    // when preferring initializer_list as its type, it also has its potential pitfalls.
    // http://www.cplusplus.com/reference/initializer_list/initializer_list/
  }
  catch ( const std::exception& )
  {

  }
}


class rectangle
{
private:
  double edgeOne, edgeTwo;
public:
  //Rect ( double a, double b ) { edgeOne = a; edgeTwo = b; } // the usual definition
  //Rect ( double a, double b ) : edgeOne ( a ) { edgeTwo = b; } // partly member initialization
  rectangle ( double a, double b ) : edgeOne ( a ), edgeTwo ( b ) {} // fully member initialization
  double area () { return edgeOne * edgeTwo; }
};
class Cube
{
private:
  rectangle base; // Cube's constructor needs to pass parameters to Rect's constructor (member initializer list)
  double edgeThree;
public:
  //Cube ( double a, double b, double c ) : base ( a, b ), edgeThree ( c ) {} // function initializer list syntax
  Cube ( double a, double b, double c ) : base { a, b }, edgeThree { c } {} // uniform initializer list syntax
  double volume () { return base.area () * edgeThree; }
};
void _17_04_MemberInitializationInConstructor ()
{
  try
  {
    //! ####################################################################
    //! ----- member initialization in constructors:
    // constructors can be used in different ways to initialize the data members.
    // the already introduced way resorts to statements within boy code of a constructor.
    // the direct initialization introduces a list followed by a colon (:), which precedes the constructor body.
    // Note syntax: constructor_identifier (parameter1, ...) : data_member1 (parameter1), ... { body code }
    // the way in which a constructor is defined, has no effect on data members of fundamental types,
    // since thy aren't initialized by default.
    // this story is different, when it comes to data member objects defined using classes.
    // to initialize them, there is only two ways, direct initialization after colon or default-constructing.
    // Note the convenience of default-constructing all data member of a class is questionable:
    // it is not even possible, when the class introduces no default constructor, and on the other hand,
    // it is a waste, if data members are reinitialized otherwise in the constructor.
    // therefore, member initialization list is preferable and this is valid not only in these cases
    // in these cases, members shall be initialized in the member initialization list.
    ColourCouter ( "----- Member initialization in constructors:\n", F_bBLUE );
    ColourCouter ( "Constructors can use different methods to initialize data members.\n\n", F_YELLOW );
    Cube first { 1.1, 2.2, 3.3 };
    std::cout << "Cube's volume:" << tab << first.volume () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Triangle
{
private:
  double base, height;
public:
  Triangle ( double a, double b ) : base ( a ), height ( b ) {}
  double area ( void ) { return ( base * height ) / 2; }
};
void _17_05_PointersToClasses ()
{
  try
  {
    //! ####################################################################
    //! ----- pointers to classes:
    // declared classes are valid types, thus after declaration usable as pointer type,
    // thence the declared pointers are able to point to objects of the class.
    // likewise plain data structures, using the pointers,
    // members of an object pointed to by a pointer are then accessible through arrow operator (->).
    // several operators are usable to operate on objects and pointers.
    // below is a guide list of them, which mostly have been already introduced.
    // -------------------------------------------------
    // expression     interpretation
    // -------------------------------------------------
    // *x             pointed to by x
    // -------------------------------------------------
    // &x             address of x
    // -------------------------------------------------
    // x.y            member y of object x
    // -------------------------------------------------
    // x->y           member y of object pointed to by x
    // -------------------------------------------------
    // (*x).y         equivalent to the previous one
    // -------------------------------------------------
    // x[0]           first object pointed to by x
    // -------------------------------------------------
    // x[1]           second object pointed to by x
    // -------------------------------------------------
    // x[n]           (n+1)th object pointed to by x
    // -------------------------------------------------
    ColourCouter ( "----- Pointers to classes:\n", F_bBLUE );
    ColourCouter ( "A defined class is a valid data type, therefore it can be used as the type of objects pointed to by a pointer.\n\n", F_YELLOW );
    Triangle objA ( 2.2, 3.3 );
    Triangle* ptrObjA, * ptrObjB, * ptrObjC;
    ptrObjA = &objA;
    ptrObjB = new Triangle ( 4.4, 5.5 );
    ptrObjC = new Triangle [2] { {6.6, 7.7},{8.8, 9.9} };
    std::cout << "Triangle's area (object itself):" << "\t\t" << objA.area () << nline;
    std::cout << "Triangle's area (pointer to object):" << "\t\t" << ptrObjA->area () << nline;
    std::cout << "Triangle's area (pointer to object):" << "\t\t" << ( *ptrObjB ).area () << nline;
    std::cout << "Triangle's area (pointer to array of objects):" << tab << ptrObjC [0].area () << nline;
    std::cout << "Triangle's area (pointer to array of objects):" << tab << ptrObjC [1].area () << nline << nline;
    delete ptrObjB;
    delete [] ptrObjC;
  }
  catch ( const std::exception& )
  {

  }
}


class Matrix
{
private:
public:
  int a, b, c, d; // public so usable for none-member functions
  Matrix () { a = b = c = d = 0; };
  Matrix ( int a, int b, int c, int d ) : a ( a ), b ( b ), c ( c ), d ( d ) {}
  Matrix operator + ( const Matrix& );
  //Matrix operator = ( const Matrix& );
  void print ( void )
  { std::cout << Tab << "The matrix is:" << Tab << a << ", " << b << ", " << c << ", " << d << Nline; }
};
// operator overloaded as member function
Matrix Matrix::operator + ( const Matrix& input )
{
  Matrix temp;
  temp.a = a + input.a; temp.b = b + input.b;
  temp.c = c + input.c; temp.d = d + input.d;
  return temp;
}
// operator overloaded as non-member function
Matrix operator - ( const Matrix& first, const Matrix& second )
{
  Matrix temp;
  temp.a = first.a - second.a;
  temp.b = first.b - second.b;
  return temp;
}
void _17_06_OverloadingOperators ()
{
  try
  {
    //! ####################################################################
    //! ----- overloading operators:
    // new types defined through classes interact with the code also by the means of operators,
    // hence operators' obvious and unambiguous interaction with fundamental types can change using these new types,
    // therefore the need to overload operators is self explanatory, which C++ language provides the means so to.
    // a list of over-loadable operators:
    // ---------------------------------------------------------------------------
    // +      -     *     /     =     <     >     +=    -=    *=    /=    <<    >>
    // ---------------------------------------------------------------------------
    // <<=    >>=   ==    !=    <=    >=    ++    --    %     &     ^     !     |
    // ---------------------------------------------------------------------------
    // ~&=    ^=    |=    &&    ||    %=    []    ()    ,     ->*   ->
    // ---------------------------------------------------------------------------
    // new    delete    new[]   delete[]
    // ---------------------------------------------------------------------------
    // the operator functions, which through their special names differentiate with regular functions,
    // are to be used to overload operators.
    // Note the syntax:
    // type operator sign (parameters) {}
    // while the obligation of exact functionality of overloaded operator to that of mathematical or usual meaning lacks,
    // the strong recommendation is there to oblige, and to follow the usual meaning of operators.
    ColourCouter ( "----- Overloading operators:\n", F_bBLUE );
    ColourCouter ( "In C++, most operators can be overloaded, so they could have defined behaviours for almost any type.\n\n", F_YELLOW );
    Matrix matrix_1 ( 1, 2, 3, 4 );
    Matrix matrix_2 ( 4, 3, 2, 1 );
    Matrix result_1;
    // both expressions are equivalent:
    result_1 = matrix_1 + matrix_2; // calling the function operator+ implicitly
    result_1 = matrix_1.operator+( matrix_2 ); // calling the function operator+ explicitly
    ColourCouter ( "The matrices are:\n", F_bYELLOW );
    matrix_1.print ();
    matrix_2.print ();
    ColourCouter ( "The result of the overloaded addition operator on two matrices is:\n", F_bYELLOW );
    result_1.print ();
    std::cout << nline;

    //! - in addition:
    // a guide list, that introduces parameters needed for different over-loadable operators and their diverse forms.
    // guide to the table:
    // in each case # is to be replaced by the operator.
    // a is an object of the class A, b is an object of the class B, c is an object of the class C
    // TYPE is just any type, that operators overloads perform the conversion to
    // ----------------------------------------------------------------------------------------------------------
    // Expression     Operator                                        Member function         Non-member function
    // ----------------------------------------------------------------------------------------------------------
    // #a             + - * & ! ~ ++ --                               A::operator#()          operator#(A)
    // ----------------------------------------------------------------------------------------------------------
    // a#             ++ --                                           A::operator#(int)       operator#(A, int)
    // ----------------------------------------------------------------------------------------------------------
    // a#b            + - * / % ^ & | < > == != <= >= << >> && || ,   A::operator#(B)         operator#(A, B)
    // ----------------------------------------------------------------------------------------------------------
    // a#b            = += -= *= /= %= ^= &= |= <<= >>= []            A::operator#(B)         -
    // ----------------------------------------------------------------------------------------------------------
    // a(b,c...)      ()                                              A::operator()(B,C...)   -
    // ----------------------------------------------------------------------------------------------------------
    // a->b           ->                                              A::operator->()         -
    // ----------------------------------------------------------------------------------------------------------
    // (TYPE) a       TYPE                                            A::operator TYPE()      -
    // ----------------------------------------------------------------------------------------------------------

    //! - in addition:
    // some operators may be overloaded not only as a member function, but also as a non-member function.
    // when overloading by the mean of non-member functions,
    // the operator function takes naturally all the needed objects of proper class as arguments.
    ColourCouter ( "Overloading the operator as a non-member function:\n\n", F_YELLOW );
    Matrix matrix_3 ( 1, 2, 3, 4 );
    Matrix matrix_4 ( 4, 3, 2, 1 );
    Matrix result_2;
    // the overloaded operator is not a member of the class so explicit expression produces error:
    result_2 = matrix_3 - matrix_4; // implicit
    //result_2 = matrix_3.operator-( matrix_4 ); // explicit
    ColourCouter ( "The matrices are:\n", F_bYELLOW );
    matrix_3.print ();
    matrix_4.print ();
    ColourCouter ( "The result of the overloaded subtraction operator on two matrices is:\n", F_bYELLOW );
    result_2.print ();
    std::cout << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Pattern
{
private:
  char sign;
public:
  Pattern ( char prm ) : sign ( prm ) {}
  bool Equal ( Pattern& prm )
  {
    if ( &prm == this ) return true;
    else return false;
  }
  Pattern operator=( Pattern& prm )
  {
    sign = prm.sign;
    return *this;
  }
  void print ( void )
  {
    for ( unsigned char i = 1; i <= 3; i++ )
    {
      for ( unsigned char j = 0; j < i; j++ )
        std::cout << sign;
      std::cout << nline;
    }
  }
};
void _17_07_TheKeywordThis ()
{
  try
  {
    //! ####################################################################
    //! ----- the keyword this:
    // the keyword 'this', usable within a class's member function, is a pointer to the object itself
    // whose member function is already executing.
    ColourCouter ( "----- The keyword this:\n", F_bBLUE );
    ColourCouter ( "To refer to the object itself within the class's member function.\n\n", F_YELLOW );
    class Pattern A { '*' };
    class Pattern B { '$' };
    class Pattern* C { &A };
    std::cout << "Pattern object A (pointed to):" << nline;
    if ( C->Equal ( A ) )
      C->print ();
    std::cout << "Pattern object B:" << nline;
    if ( A.Equal ( B ) == false )
      B.print ();
    std::cout << nline;

    //! - in addition:
    // operator= member function uses the keyword 'this' frequently, which returns objects by reference.
    std::cout << "Pattern object A (after assignment):" << nline;
    if ( A.Equal ( B ) == false )
      A = B;
    A.print ();
    std::cout << nline;

  }
  catch ( const std::exception& )
  {

  }
}


class Sentence
{
private:
  std::string content;
public:
  Sentence () { n++; };
  Sentence ( std::string prm ) : content ( prm ) { n++; };
  void print ( void ) { std::cout << content; }
  static int n;
  static void decrease ( void ) { n--; }
};
int Sentence::n { 0 }; // a static data member of a class need to be initialized somewhere outside it.
void _17_08_StaticMembers ()
{
  try
  {
    //! ####################################################################
    //! ----- static members:
    // a class can introduce static members, either data members known as class variables or member functions.
    // an static member is not only shared between all the objects of that class,
    // it is also accessible through the identifier of the class itself,
    // hence a good example of such a member is a counter to observe the number of allocated objects of that class.
    // static members are referable and accessible from all the objects of the class by dot (.),
    // and directly from the class's identifier by scope operator (::).
    // -- in fact, static members, while having properties as non-member data or functions, enjoy class scope,
    // ---- therefore static data members:
    // can not be initialized directly in the class, hence additionally to avoid they being declared several times.
    // ---- therefore static member functions:
    // lack the access to non-static class members, either data or functions, additionally they can't use keyword 'this'.
    ColourCouter ( "----- Static members:\n", F_bBLUE );
    ColourCouter ( "Static members, either data or functions, are common members of a class to all the objects of that class.\n\n", F_YELLOW );
    std::string temp = "Hello! ";
    Sentence A [3] { temp, temp, temp };
    Sentence B { "How are you?\n" };
    for ( unsigned char i = 0; i < 3; i++ )
      A [i].print ();
    B.print ();
    std::cout << "Counted objects of the class:" << tab << B.n << nline; // referring by an object
    Sentence* C = new Sentence { "where are you from?\n" };
    C->print ();
    std::cout << "Counted objects of the class:" << tab << C->n << nline; // referring by a dynamic allocated pointer
    delete C;
    Sentence::decrease (); // static member function: counting down (one object is gone! :) )
    std::cout << "Counted objects of the class:" << tab << Sentence::n << nline << nline; // referring by the class
  }
  catch ( const std::exception& )
  {

  }
}


class Character
{
private:
public:
  char entity;
  Character ( char arg ) :entity ( arg ) {} // constructor
  char get_1 () { return entity; } // normal member function
  char get_2 () const { return entity; } // constant member function: 'const' keyword must follows the function prototype
  const char& get_3 () const { return entity; }; // constant member function returning a constant reference
  const char& get_4 () { return entity; }; // normal member function returning a constant reference
  char& set_get_overloads () { return entity; }; // overloaded on constant state: returns reference
  const char& set_get_overloads () const { return entity; }; // overloaded on constant state: returns constant reference
};
void print ( const Character& arg )
{
  std::cout << "Object's data member (object taken as constant reference):" << nline << Tab << arg.get_2 () << Nline << Nline;
}
void _17_09_ConstantMemberFunctions ()
{
  try
  {
    //! ####################################################################
    //! ----- constant member functions:
    // a constant object declared from a class qualifies the outside access to all its data members to read-only,
    // exactly as if these data member were actually constant declared within the class definition,
    // while constructor still get called and has modification-right on these data members.
    // --properties of constant qualified objects of a class:
    // they can only call the member functions qualified as constant. note: constant function return type is different.
    // --properties of constant qualified member functions:
    // while they can't modify non-static data members, they lake the right to call non-constant member functions.
    // in essence, the state of an object shan't be modified by a constant member.
    // Note: non-constant objects can access both constant and non-constant member functions alike.
    ColourCouter ( "----- Constant member functions:\n", F_bBLUE );
    ColourCouter ( "Declaring an object of a class with qualification as constant introduces the restricted read-only access to its own members either data or function.\n\n", F_YELLOW );
    const Character aConstantObject ( 'A' ); // valid: constructor of the constant objects
    char temp { '-' };
    //aConstantObject.x = 'B'; // not valid: unmodifiable data members
    temp = aConstantObject.entity; // valid: read access right on data members
    std::cout << "Object's data member (read-only access):" << nline << tab << temp << nline << nline;

    //temp = aConstantObject.get1 (); // not valid: not a constant member function
    temp = aConstantObject.get_2 ();
    std::cout << "Object's member function (constant member function):" << nline << tab << temp << nline;

    temp = aConstantObject.get_3 ();
    std::cout << "Object's member function (constant member function with constant reference as return type):" << nline << tab << temp << nline << nline;
    //temp = aConstantObject.get4 (); // not valid: not a constant member function

    //! - in addition:
    // the consideration should be there that the use of constant objects are perfectly common,
    // thus the effort of declaring all members that don't modify the object as constant worth it.
    // most functions with classes as parameters take them as constant reference,
    // therefore they can only access the constant object members.
    Character aObject ( 'B' );
    print ( aObject );

    //! - in addition:
    // note: member functions with identical signatures are on their constant state over-loadable,
    // this means, that the constant qualified versions are called when the objects themselves are constant.
    // Note FYI: the reference returned in a member function is a kind of implicit pointer to returned value.
    // when defined as non-constant, the member function is then usable at the left side of assignment operator,
    // hence giving the member function the ability to modify the returned value.
    // https://www.tutorialspoint.com/cplusplus/returning_values_by_reference.htm
    Character firstObject ( 'D' );
    const Character secondObject ( 'E' );
    firstObject.set_get_overloads () = 'F'; // valid: modification through function return type qualified as reference
    temp = firstObject.set_get_overloads ();
    std::cout << "Object's member function (modification through references):" << nline << tab << temp << nline;
    //secondObject.set_get_overloads () = 'G'; // not valid: read access through constant reference
    temp = secondObject.set_get_overloads ();
    std::cout << "Object's member function (read access through references):" << nline << tab << temp << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


template <class tType> // template parameter
class NumberGeneric
{
private:
  tType entity;
public:
  NumberGeneric ( tType prm ) :entity ( prm ) {} // inline: defined within the class definition
  tType get () { return  entity; }
  tType square ();
};
// defined outside the class definition
template <class tType>
tType NumberGeneric <tType> ::square ()
{
  tType result;
  result = entity * 2;
  return result;
}
void _17_10_ClassTemplates ()
{
  try
  {
    //! ####################################################################
    //! ----- class templates:
    // class templates allow the use of template parameters as type in the concepts of class,
    // just as already introduced in function templates section.
    // Note when defining a member function outside of the class template, the template <...> prefix shall precede it.
    // additionally following is the needed definition syntax, which is notable.
    // Note syntax: template_parameter class_identifier <template_parameter> ::member_function_identifier () {}
    // the template parameter between the angel brackets is also a requirement,
    // which introduces the function's template parameter, which is the same as class template parameter.
    ColourCouter ( "----- Class templates:\n", F_bBLUE );
    ColourCouter ( "To introduce classes that are able to have members that use template parameters as type.\n\n", F_YELLOW );
    NumberGeneric<int> intNum ( 2 );
    NumberGeneric<double> doubleNum ( 2.2 );
    std::cout << "The number entities and their squares:" << nline;
    std::cout << "First one:" << tab << intNum.get () << tab << intNum.square () << nline;
    std::cout << "Second one:" << tab << doubleNum.get () << tab << doubleNum.square () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


// generic template class:
template <class tType>
class Entity
{
private:
  tType content;
public:
  Entity ( tType prm ) :content ( prm ) {}
  tType get () { return  content; }
  void square () { content *= 2; }
  tType operator+ ( tType prm ) { return content + prm; }
};
// class template specialization
template <>
class Entity <std::string>
{
private:
  std::string content;
public:
  Entity ( std::string prm ) :content ( prm ) {}
  std::string get () { return  content; }
  void upLowerCase ()
  {

    // uppercase/lowercase switch (ASCII code of character)
    std::string temp { "" };
    for ( char c : content )
    {
      if ( c < 97 )
        c += 32;
      else
        c -= 32;
      temp += c;
    }
    content = temp;
  }
  std::string operator+ ( std::string prm ) { return  content + prm; }
};
void _17_11_TemplateSpecialization ()
{
  try
  {
    //! ####################################################################
    //! ----- template specialization:
    // different defined implementation for a template to introduce specific behaviour,
    // when a special type is passed is known as template specialization.
    // Note syntax: template <> class class_identifier <type_specialization_parameter> {...};
    // note the empty parameter list <>
    // the reason: this introduction specializes an already defined template with all its needed template argument.
    // type specialization parameter identifies the type, for which the template specialization is being introduced.
    // note that all members of the generic class, even identical ones, must be defined in its specialization again,
    // since there is no inheritance between a generic class and the specialization there of.
    ColourCouter ( "----- Template specialization:\n", F_bBLUE );
    ColourCouter ( "To introduce different implementation of a template for a specific type.\n\n", F_YELLOW );
    Entity <int> theInt ( 2 );
    Entity <std::string> theString ( "Hello" );
    std::cout << "The integer value:" << tab << theInt.get () << nline;
    theInt.square ();
    std::cout << "Square operation:" << tab << theInt.get () << nline;
    std::cout << "+operator:" << "\t\t" << theInt + 2 << nline << nline;
    std::cout << "The character value:" << tab << theString.get () << nline;
    theString.upLowerCase ();
    std::cout << "Upper/lowercase switch:" << tab << theString.get () << nline;
    std::cout << "+operator:" << "\t\t" << theString + " bye" << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _18_01_SpecialMembers ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ special members:
    // 
    std::cout << nline << "~~~~~ Special members:" << nline;
    std::cout << "." << nline << nline;




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
