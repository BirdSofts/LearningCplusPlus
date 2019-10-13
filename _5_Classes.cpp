// --------------------------------------------------------------------------------
/// <summary>
/// _5_Classes.cpp
/// </summary>
/// <created>ʆϒʅ,18.09.2018</created>
/// <changed>ʆϒʅ,13.10.2019</changed>
// --------------------------------------------------------------------------------

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
  int square ( void ) { return entity * entity; } // declaration and definition
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
    //! ~~~~~ Classes:
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
    ColourCouter ( "~~~~~ Classes:\n", F_bWHITE );
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
  int square ( void ) { return entity * entity; }
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
    ColourCouter ( "----- Constructors:\n", F_bWHITE );
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
    ColourCouter ( "----- Overloading constructors\n", F_bWHITE );
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
    ColourCouter ( "----- Uniform initialization:\n", F_bWHITE );
    ColourCouter ( "There are different ways for a constructor to be called.\n\n", F_YELLOW );
    Smily a ( 0 ); // functional form (usable for single argument constructors)
    Smily b = 1; // assignment initialization (usable for single argument constructors)
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
    ColourCouter ( "----- Member initialization in constructors:\n", F_bWHITE );
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
    ColourCouter ( "----- Pointers to classes:\n", F_bWHITE );
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
    ColourCouter ( "----- Overloading operators:\n", F_bWHITE );
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
    ColourCouter ( "----- The keyword this:\n", F_bWHITE );
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
    ColourCouter ( "----- Static members:\n", F_bWHITE );
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
    ColourCouter ( "----- Constant member functions:\n", F_bWHITE );
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
  result = entity * entity;
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
    ColourCouter ( "----- Class templates:\n", F_bWHITE );
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
  void square () { content *= content; }
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
    ColourCouter ( "----- Template specialization:\n", F_bWHITE );
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
    // member function defined implicitly under certain circumstances are known as special members:
    // -------------------------------------------------------------
    // member function        typical form for class theClass
    // -------------------------------------------------------------
    // default constructor    theClass::theClass();
    // -------------------------------------------------------------
    // destructor             theClass::~theClass();
    // -------------------------------------------------------------
    // copy constructor       theClass::theClass (const theClass&);
    // -------------------------------------------------------------
    // copy assignment        theClass& operator= (const theClass&);
    // -------------------------------------------------------------
    // move constructor       theClass::theClass (theClass&&);
    // -------------------------------------------------------------
    // move assignment        theClass& operator= (theClass&&);
    // -------------------------------------------------------------
    ColourCouter ( "~~~~~ Special members:\n", F_bWHITE );
    ColourCouter ( "Special member functions are defined implicitly under certain circumstances.\n\n", F_YELLOW );



  }
  catch ( const std::exception& )
  {

  }
}


class FloatingPoint
{
private:
  double entity;
public:
  FloatingPoint () { entity = 0; } // explicit defined default constructor
  FloatingPoint ( const double& arg ) :entity ( arg ) {}
  const double& get () const { return entity; }
};
void _18_02_DefaultConstructor ()
{
  try
  {
    //! ####################################################################
    //! ----- default constructor:
    // an object defined of a class, but not initialised with any arguments, calls the default constructor.
    // classes defined without any constructor are assumed by compiler to have an implicitly defined default constructor.
    // after a class provides a constructor, taking any number of parameters to initialize object's data members with,
    // compiler in no case introduces an implicit default constructor,
    // thus no instantiation not using the explicit defined constructor is possible.
    // hence afterward, for the ability to instantiate using default constructor, it shall be defined explicitly.
    ColourCouter ( "----- Default Constructor:\n", F_bWHITE );
    ColourCouter ( "This special member introduces object's instantiation without passing any arguments.\n\n", F_YELLOW );
    FloatingPoint anEntity;
    FloatingPoint anotherEntity { 2.2 };
    std::cout << "The floating point numbers are:" << nline;
    std::cout << tab << anEntity.get () << tab << anotherEntity.get () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class FloatEntity
{
private:
  double* ptrEntity;
public:
  FloatEntity () : ptrEntity ( new double ) { *ptrEntity = 0; }
  FloatEntity ( const double& arg ) :ptrEntity ( new double ( arg ) ) {}
  ~FloatEntity () { delete ptrEntity; } // destructor
  const double& get () const { return *ptrEntity; }
};
void _18_03_Destructor ()
{
  try
  {
    //! ####################################################################
    //! ----- destructor:
    // the special member destructor is needed to free the allocated resource by a class, when its lifetime ends.
    // note that when a class doesn't allocate any dynamic memory, it doesn't really require a destructor.
    // like constructor, destructor of a class is automatically called upon the lifetime end of the objects defined of.
    // destructor, very much like the default constructor, takes not even void as argument,
    // while using the class identifier as its own and preceded with a tilde sign (~).
    // the destructor of the below defined object is called at the end of the function.
    ColourCouter ( "----- Destructor:\n", F_bWHITE );
    ColourCouter ( "Destructor is a special member, and is called at the lifetime end of a class.\n\n", F_YELLOW );
    FloatEntity theEntity { 4.4 };
    std::cout << "The floating point number is:" << nline;
    std::cout << tab << theEntity.get () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Creature
{
private:
  std::string name;
public:
  Creature ( std::string arg ) :name ( arg ) {}
  const std::string& get () const { return name; }
};
class creaturePtr
{
private:
  std::string* ptrName;
public:
  creaturePtr ( const std::string& arg ) :ptrName ( new std::string ( arg ) ) {}
  ~creaturePtr () { delete ptrName; }
  // custom copy constructor
  creaturePtr ( const creaturePtr& obj ) : ptrName ( new std::string ( obj.get () ) ) {}
  const std::string& get () const { return *ptrName; }
};
void _18_04_CopyConstructor ()
{
  try
  {
    //! ####################################################################
    //! ----- copy constructor:
    // the special member copy constructor, after invocation at the moment of a new object's definition,
    // which is passed another already defined object of the same class as a single argument,
    // instantiates a duplication of it, using the new object's identifier.
    // with other words, the new object get initialized using another already defined object of the same class.
    // copy constructor introduces its first possibly constant qualified argument of type reference to the class itself.
    // copy, move constructors/assignments are implicitly provided through compiler,
    // if the class itself doesn't introduce its custom version,
    // which then simply performs a shallow copy of the members of the passed object.
    // for example the implicit defined copy constructor by compiler for the class Creature is roughly equivalent to:
    // Creature::Creature ( const Creature & obj ) : name ( obj.name ) {}
    ColourCouter ( "----- Copy constructor:\n", F_bWHITE );
    ColourCouter ( "To instantiate an object as copy of another object.\n\n", F_YELLOW );
    Creature one { "Human" };
    Creature two { one }; // invoking the implicit copy constructor
    std::cout << "The copied creature is identified as:" << nline;
    std::cout << tab << two.get () << nline << nline;

    //! - in addition:
    // while the introduced implicit copy constructor perfectly suites the need of many classes,
    // when it comes to pointers and handling the allocated storage, a performed shallow copy,
    // through which just the pointer value and not the pointed content get duplicated, in no case is a wished result.
    // after a shallow copy, the object and its duplication point to the same destination address of memory,
    // hence the program crushes at the destruction moment of this object or its copy on runtime.
    // therefore the only solution is a custom copy constructor to perform a deep copy.
    ColourCouter ( "Deep copy instantiation:\n", F_bYELLOW );
    creaturePtr three { "Human" };
    creaturePtr four { three };
    std::cout << "The copied creature is identified as:" << nline;
    std::cout << tab << four.get () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Animal
{
private:
  std::string* ptrName;
public:
  Animal ( const std::string& arg ) :ptrName ( new std::string ( arg ) ) {}
  ~Animal () { delete ptrName; }
  Animal ( const Animal& obj ) : ptrName ( new std::string ( obj.get () ) ) {}
  // copy assignment operator
  Animal& operator= ( const Animal& obj )
  {
    // --two available options for different scenarios:
    // ----free the allocated memory (in case of constant member)
    delete ptrName;
    ptrName = new std::string ( obj.get () );
    return *this;
    // ----re-utilization (in case of non-constant member)
    *ptrName = obj.get ();
    return *this;
  }
  const std::string& get () const { return *ptrName; }
};
void _18_05_CopyAssignment ()
{
  try
  {
    //! ####################################################################
    //! ----- copy assignment:
    // objects can additionally be copied on any assignment operation.
    // one of the overloads of the operator= is the copy assignment operator, which is a special member,
    // the single parameter of which is a value or reference to the class itself,
    // and generally returns a reference to *this, although not being a requirement.
    // a possible signature of the copy assignment of the class Creature is:
    // Creature& operator= ( const Creature& );
    // like copy constructor, the compiler defines a copy assignment operator implicitly,
    // when the class introduces no custom version of its own,
    // which performs needed shallow copy of a lot of classes perfectly.
    // when it comes to pointers to objects and handling the needed storage, as the case with copy constructor,
    // additionally to risk of freeing the allocated memory twice, there is the danger of memory leaks creation,
    // which occurs by not deleting the object pointed to by the under new assignment operation object.
    // a deep copy performed after deleting or reassigning the previous object solves these issues.
    ColourCouter ( "----- Copy Assignment:\n", F_bWHITE );
    ColourCouter ( "To copy an object on assignment operation.\n\n", F_YELLOW );
    Animal one { "Dog" };
    // initialization through copy constructor
    Animal two { one };
    // initialization through copy constructor (already introduced syntax, which calls single-argument constructors)
    Animal three = one;
    // already initialized objects, thus copy assignment is called
    one = three;
    std::cout << "The copied animal is identified as:" << nline;
    std::cout << tab << one.get () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Appliance
{
private:
  std::string* ptrName;
public:
  Appliance ( const std::string& arg ) :ptrName ( new std::string ( arg ) ) {}
  ~Appliance () { delete ptrName; }
  // copy constructor
  Appliance ( const Appliance& obj ) : ptrName ( new std::string ( obj.get () ) ) {}
  // copy assignment operator (non-constant member scenario)
  Appliance& operator= ( const Appliance& obj )
  {
    *ptrName = obj.get ();
    return *this;
  }
  // move constructor
  Appliance ( Appliance&& obj ) :ptrName ( obj.ptrName ) { obj.ptrName = nullptr; }
  // move assignment
  Appliance& operator= ( Appliance&& obj )
  {
    delete ptrName;
    ptrName = obj.ptrName;
    obj.ptrName = nullptr;
    return *this;
  }
  // addition
  Appliance operator+ ( const Appliance& arg ) { return Appliance ( get () + " and " + arg.get () ); }
  const std::string& get () const { return *ptrName; }
};
void _18_06_MoveConstructorAndAssignment ()
{
  try
  {
    //! ####################################################################
    //! ----- move constructor and assignment:
    // moving similar to copying set the value to another object, the difference is the actual transfer,
    // hence the source, which must be an unnamed object, loses that content.
    // unnamed objects, for example return type of functions or type-casts, are in nature temporary,
    // therefore they aren't identified with any name.
    // initialization/assignment using temporary objects triggers the special member move constructor/assignment.
    // to mention the efficient side, the use of unnamed temporaries make the copy unnecessary,
    // with other words, the short-living unnamed objects are then acquired with the most efficient operation.
    // the only parameter of move constructor/assignment is of type revalue reference to the class itself,
    // which is specified following the type with two ampersands (&&),
    // and then as a parameter matches the temporaries of the same type.
    // Note syntax form (revalue reference): theClass ( theClass&& ); --- theClass& operator= ( theClass&& );
    // for objects that manage their storage, such as objects that allocate and free storage with 'new' and 'delete',
    // the concept of moving provides its most usefulness,
    // considering the real difference between the operations copying and moving:
    // --copying from A to B means: memory allocation for B and copying the entire content of A to it
    // --moving from A to B means: transferring the allocated memory of A to B, which simply involves copying the pointer.
    ColourCouter ( "----- Move constructor and assignment:\n", F_bWHITE );
    ColourCouter ( "Transferring the content of an unnamed object to destination.\n\n", F_YELLOW );
    Appliance one { "Refrigerator" };
    Appliance two { "Washing machine" };
    std::cout << "The copied appliances are identified as:" << nline;
    Appliance temp { one }; // copy constructor
    std::cout << tab << temp.get () << nline;
    temp = two; // copy assignment
    std::cout << tab << temp.get () << nline << nline;
    std::cout << "The moved appliances are identified as:" << nline;
    Appliance three { Appliance{"Stove"} }; // move constructor
    std::cout << tab << three.get () << nline;
    temp = one + three; // move assignment
    std::cout << tab << temp.get () << nline << nline;

    //! - in addition:
    // compilers introducing Return Value Optimization optimize many cases,
    // that formally require a move-construction call, such as returned function value used to initialize an object.
    // through this optimization the move constructor may actually never get called.
    // note that the use of revalue reference needs to be practised with care.
    // while it can be used as parameter type of any function, the usefulness is arguable.
    // using it in other functions than move constructors is tricky,
    // unnecessary and the source of errors quite difficult to track.
  }
  catch ( const std::exception& )
  {

  }
}


const double PI { 3.14159 };
class Circle
{
private:
  double radius;
public:
  Circle ( double arg ) :radius ( arg ) {}
  Circle () = default; // default definition is explicitly selected
  Circle ( const Circle& obj ) = delete; // explicitly deleted
  double circumference () { return 2 * radius * PI; }
};
void _18_07_ImplicitMembers ()
{
  try
  {
    //! ####################################################################
    //! ----- implicit members:
    // below comes the certain circumstances,
    // under which the six special member functions described above are implicitly defined:
    // --------------------------------------------------------------------------------------------------
    // member function      implicitly defined if:                                    default definition:
    // --------------------------------------------------------------------------------------------------
    // default constructor  no other constructors                                     does nothing
    // destructor           no destructor                                             "
    // copy constructor     no move constructor/assignment                            copies all members
    // copy assignment      "                                                         "
    // move constructor     no destructor/copy constructor/copy nor move assignment   moves all members
    // move assignment      "                                                         "
    // --------------------------------------------------------------------------------------------------
    // note that due to backward compatibility with C structures and earlier C++ version,
    // under same criteria pairs of special members are implicitly defined,
    // which in fact contain even deprecated circumstances.
    // further more classes using the keywords 'default' and 'delete' can explicitly select,
    // which of these members exist with their default definition and which are deleted.
    // Note syntax:
    // function_declaration = default; --- function_declaration = delete;
    // note that the recommendation for future support backward in time is there, when defining a class,
    // which explicitly introduces one custom copy/move constructor or copy/move assignment but not both,
    // to explicitly specify the state of the other special member functions as 'delete' or 'default'.
    ColourCouter ( "----- Implicit members:\n", F_bWHITE );
    ColourCouter ( "Special members are implicit defined under different criteria.\n\n", F_YELLOW );
    Circle one;
    Circle two ( 2.2 );
    std::cout << "The circle's circumference is:" << tab << two.circumference () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _19_01_FriendshipAndInheritance ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ friendship and inheritance:
    //
    ColourCouter ( "~~~~~ Friendship and inheritance:\n", F_bWHITE );
    ColourCouter ( "Some useful expansions on the concept of classes.\n\n", F_YELLOW );
  }
  catch ( const std::exception& )
  {

  }
}


class Cylinder; // empty declaration (usable as type to define objects)
class Base
{
  friend class Cylinder; // Cylinder is a friend (Cylinder has the privilege to access)
private:
  double radius;
  const double P { 3.14159 };
public:
  Base () { radius = 1; } // default constructor
  Base ( double prm ) :radius ( prm ) {}
  double circumference () { return 2 * radius * P; }
  friend void expand_by_base ( Base&, double ); // friend function (not a member function!)
  friend void expand_by_height ( Cylinder&, double ); // the same
};
class Cylinder
{
private:
  Base base;
  double height;
public:
  Cylinder ( double prm ) :height ( prm ) {}
  double volume () { return base.circumference () * height; }
  void new_base ( Base );
  void set ( double prm ) { height *= prm; }
};
void expand_by_base ( Base& obj, double prm ) { obj.radius *= prm; } // friend of Base
void expand_by_height ( Cylinder& obj, double prm ) { obj.set ( prm ); } // not a friend of Cylinder
void Cylinder::new_base ( Base obj ) // defined outside
{
  // the privilege of friends! :)
  base.radius = obj.radius;
}
void _19_02_FriendFunctionsAndClasses ()
{
  try
  {
    //! ####################################################################
    //! ----- friend functions and classes:
    // private and protected members of a class are accessible within it and from its friends,
    // which are those classes or functions defined with the keyword 'friend'.
    // --a non-member external function's declaration needs to be included within the definition of the class,
    // preceded with the keyword 'friend'.
    // when conducting operations between two different classes, accessing their private and protected members,
    // the concept of friend functions has its most typical use.
    // --similarly, the declaration of a friend class after inclusion within the class definition,
    // preceded with the keyword 'friend', qualifies it by additional rights.
    // note that unless explicitly specified, friendships are not corresponded,
    // hence declaring a class as friend within a class,
    // doesn't qualifies the class to be also a friend to its friend class,
    // therefore the friend class, if needed, must define its friendship to this class explicitly.
    // note, since friendships are not transitive, unless explicitly declared, a friend of a friend is a friend.
    ColourCouter ( "----- Friend functions and classes:\n", F_bWHITE );
    ColourCouter ( "Functions and classes defined as friend of a class can access its private and protected members.\n\n", F_YELLOW );
    Cylinder one { 5 };
    std::cout << "Cylinder's volume (base is default constructed):" << nline << tab << one.volume () << nline;
    Base two ( 2.2 );
    one.new_base ( two );
    std::cout << "Cylinder's volume (class friend's privilege):" << nline << tab << one.volume () << nline;
    expand_by_base ( two, 0.9 );
    one.new_base ( two );
    std::cout << "Cylinder's volume (function friend's privilege):" << nline << tab << one.volume () << nline;
    expand_by_height ( one, 0.9 );
    std::cout << "Cylinder's volume (no friendship is declared):" << nline << tab << one.volume () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Person
{
protected:
  std::string name;
public:
  void setter ( std::string arg ) { name = arg; };
};
// first derived class and its own features
class Customer :public Person
{
public:
  std::string print () { return name + " wants to buy a new phone."; }
};
// second derived class and its own features
class Worker :public Person
{
public:
  std::string print () { return name + " works in the shop as cashier."; }
};
void _19_03_InheritanceBetweenClasses ()
{
  try
  {
    //! ####################################################################
    //! ----- inheritance between classes:
    // classes can inherit some of their characteristics from another classes.
    // a derived class from a base class through the process of inheritance then retains to the inherited features,
    // which means that it inherits all accessible members of the base class, and additionally introduces its own members.
    // a class can base itself on another class by declaring the inheritance relationship.
    // Note syntax: class derived_class_neme :public base_class_name { ... };
    // there are three options to specify the access level, which are 'public', 'protected' and 'private' keywords.
    // using these access specifiers, the derived class can limits the accessibility of the inherited members,
    // hence an inheritance relationship declared with 'private' keyword, retain all inherited members as private members,
    // no matter that they have been originally defined as public or protected in the base class.
    // note that, on the other hand, inheriting with public access specifier, saves the original defined state of base class members.
    // all in all, in C++ public inheritance has the most use cases,
    // since needed members of a base class defined with other access levels are better represented as member variables instead.
    // after not explicitly specifying the access level for inheritance,
    // compiler implicitly assumes it as private for those defined with 'class' keyword and public for those defined with 'struct'.
    // Note accessibility of class members, considering inheritance concepts:
    // ----------------------------------------------------------
    // Access                       public    protected   private
    // members of the same class    yes       yes         yes
    // members of derived class     yes       yes         no
    // not members                  yes       no          no
    // ----------------------------------------------------------
    // note that protected members of a base class are accessible within the derived class.
    ColourCouter ( "----- Inheritance between classes:\n", F_bWHITE );
    ColourCouter ( "Characteristics of a class can be inherited by other classes.\n\n", F_YELLOW );
    Customer one;
    Worker two;
    one.setter ( "John" );
    two.setter ( "Mary" );
    std::cout << one.print () << nline;
    std::cout << two.print () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class toInherit
{
private:
  int baseEntity;
public:
  toInherit ()
  {
    std::cout << "Base class: default constructor" << nline;
    baseEntity = 0;
  }
  toInherit ( int a ) :baseEntity { a }
  {
    std::cout << "Base class: custom constructor" << nline;
  }
  const int& baseGet () { return baseEntity; }
};
class derivedOne :public toInherit
{
private:
  int entity;
public:
  // call to base class default constructor
  derivedOne ( int a ) :entity { a }
  {
    std::cout << "First derived class: custom constructor" << nline;
  };
  const int& get () { return entity; }
};
class derivedTwo :public toInherit
{
private:
  int entity;
public:
  // call to base class specific custom constructor
  derivedTwo ( int a, int b ) :entity { a }, toInherit { b }
  {
    std::cout << "Second derived class: custom constructor" << nline;
  };
  const int& get () { return entity; }
};
void _19_04_InheritedCharacteristics ()
{
  try
  {
    //! ####################################################################
    //! ----- inherited characteristics:
    // generally, a derived class defined with public inheritance relationship retain access to every member of a base class except:
    // constructors, destructor, assignment operator members, the friends, and private members of the base class.
    // note that, while the access to constructors and destructors of the base class in inheritance way isn't provided,
    // the constructors and destructor of the derived class automatically call these special member functions of the base class.
    // this automated call, unless explicitly specified differently, happens to its default constructor.
    // through the syntax provided to initialize member variables in the initialization list,
    // it is possible to explicitly call custom constructors of a base class.
    // Note syntax
    // derived_constructor_name ( parameters ) : data_members { parameters }, base_constructor_name { parameters } { ... }
    ColourCouter ( "----- Inherited characteristics:\n", F_bWHITE );
    ColourCouter ( "Not all the members of a base class get retained in the process of inheritance.\n\n", F_YELLOW );
    // base class default constructor:
    derivedOne first { 1 };
    std::cout << "First derived class entities:" << tab << first.baseGet () << tab << first.get () << nline << nline;
    // base class custom constructor:
    derivedTwo second { 2, 1 };
    std::cout << "Second derived class entities:" << tab << second.baseGet () << tab << second.get () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Shape
{
protected:
  const double PI { 3.14159 };
  double radius;
public:
  Shape ( const double& prm ) : radius ( prm ) {}
  double exponent ( const double& prmOne, const unsigned char& ex )
  {
    double temp { 1 };
    for ( unsigned char i = 0; i < ex; i++ )
    {
      temp *= prmOne;
    }
    return temp;
  }
};
class Output
{
private:
public:
  void print ( const double& prm ) { std::cout << "The volume of sphere is:" << tab << prm; }
};
class Sphere :public Shape, public Output
{
private:
public:
  Sphere ( const double& prm ) : Shape ( prm ) {}
  double area () { return ( 4 / 3 ) * PI * exponent ( radius, 3 ); }
};
void _19_05_MultipleInheritance ()
{
  try
  {
    //! ####################################################################
    //! ----- multiple inheritance:
    // expanding the inheritance concepts, classes can be based on more than one class,
    // the declaration syntax then get extended to include the needed base classes, separating them with coma ','.
    // Note syntax: class derived_class_neme :public base_class_one, public base_class_two, ... { ... };
    ColourCouter ( "----- Multiple inheritance:\n", F_bWHITE );
    ColourCouter ( "A class can inherit characteristics from more than one base class.\n\n", F_YELLOW );
    Sphere one ( 10.5 );
    one.print ( one.area () );
    std::cout << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _20_01_Polymorphism ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ polymorphism:
    // the needed concepts for the following to be understood are data structures, classes, pointers, friendship and inheritance,
    // without which, learning deeper isn't going to bring anything.
    // all of them are already introduced in this tutorial.
    ColourCouter ( "~~~~~ Polymorphism:\n", F_bWHITE );
    ColourCouter ( "Deeper knowledge in the concepts of classes.\n\n", F_YELLOW );
  }
  catch ( const std::exception& )
  {

  }
}


class Numbers
{
protected:
  int first, second;
public:
  void set_numbers ( int a, int b ) { first = a; second = b; }
};
class Subtraction :public Numbers
{
public:
  int result ()
  {
    if ( first > second )
      return first - second;
    else
      return second - first;
  }
};
class Summation :public Numbers
{
public:
  int result ()
  {
    return first + second;
  }
};
void _20_02_PointersToBaseClass ()
{
  try
  {
    //! ####################################################################
    //! ----- pointers to base class:
    // furthermore on the advantages of inheritance concepts and introducing polymorphism,
    // a pointer to a derived class is additionally type-compatible with another one to its base class.
    // note that it is not possible to access the members of a derived class through a pointer to its base class.
    // in the example, base class can't represent a common implementation for the different operations.
    ColourCouter ( "----- Pointer to base class:\n", F_bWHITE );
    ColourCouter ( "A pointer can point to a base class through its derived class address.\n\n", F_YELLOW );
    Subtraction minus;
    Summation plus;
    Numbers* ptr_minus { &minus }; // type-compatible feature
    Numbers* ptr_plus { &plus };
    ptr_minus->set_numbers ( 20, 10 ); // dereferencing the base member
    ptr_plus->set_numbers ( 20, 10 );
    std::cout << "The subtraction result:" << tab << minus.result () << nline;
    std::cout << "The summation result:" << tab << plus.result () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Pair
{
protected:
  int first, second;
public:
  void set ( int a, int b ) { first = a; second = b; }
  virtual int result () { return 0; }
};
class Division :public Pair
{
public:
  int result ()
  {
    if ( first > second )
      return first / second;
    else
      return second / first;
  }
};
class Multiplication :public Pair
{
public:
  int result ()
  {
    return first * second;
  }
};
void _20_03_VirtualMembers ()
{
  try
  {
    //! ####################################################################
    //! ----- virtual members:
    // preceding the member function declaration with 'virtual' keyword and redefining it in derived classes,
    // its calling properties through references are preserved.
    // the redefined implementations of a member function defined and qualified as virtual in base class,
    // can then be accessed through a reference of the base class.
    // with other words, the 'virtual' keyword qualifies a function and its redefined implementations to be called appropriately,
    // specially using a pointer to the type of the base class, which points to an object of the derived class.
    // Note syntax: virtual function_return_type identifier () {...}
    // classes that inherit or declare a virtual function are known as polymorphic ones.
    // the example introduces a regular class as base containing a virtual member function with different implementations.
    ColourCouter ( "----- Virtual members:\n", F_bWHITE );
    ColourCouter ( "Through virtual qualification, calling properties through references are preserved.\n\n", F_YELLOW );
    Pair aPair;
    Division divide;
    Multiplication multiply;
    Pair* ptr_aPair { &aPair };
    Pair* ptr_divide { &divide };
    Pair* ptr_multiply { &multiply };
    ptr_aPair->set ( 20, 10 );
    ptr_divide->set ( 20, 10 );
    ptr_multiply->set ( 20, 10 );
    // access to members of derived classes through the pointers to base
    std::cout << "The base implementation:" << tab << ptr_aPair->result () << nline;
    std::cout << "The division result:" << "\t\t" << ptr_divide->result () << nline;
    std::cout << "The multiplication result:" << tab << ptr_multiply->result () << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class Bits
{
protected:
  int entity;
public:
  Bits ( int a ) : entity ( a ) {};
  virtual int result () = 0;
  // call to pure virtual members from the abstract base class
  void print () { std::cout << this->result () << nline; }
};
class ShiftR :public Bits
{
public:
  ShiftR ( int a ) : Bits ( a ) {};
  int result () { return ( entity >> 1 ); }
};
class ShiftL :public Bits
{
public:
  ShiftL ( int a ) : Bits ( a ) {};
  int result () { return ( entity << 1 ); }
};
void _20_04_AbstractBaseClasses ()
{
  try
  {
    //! ####################################################################
    //! ----- abstract base classes:
    // furthermore the introduction to abstract base classes follows.
    // these ones can't be used to instantiate any object thereof and can only be used as base classes,
    // therefore they can introduce pure virtual member functions, which don't have any definition.
    // Note syntax: virtual function_return_type identifier () = 0;
    // note that the definition is replaced by equal to zero.
    // through the introduction of even one virtual member function the class is then known as abstract base class.
    // note: the advantages of abstract base classes:
    // --they shine with their polymorphic ability, after declaration of pointers to them and dereferencing objects of derived classes.
    // --an abstract base class, despite not even being implemented,
    // can use special pointer 'this' within its member functions to access the proper virtual members.
    // C++ language introduces its polymorphic characteristics through virtual members and abstract classes,
    // which provide their most usefulness on object-oriented projects.
    // additionally these features can be applied to arrays of objects or dynamically allocated objects.
    // note that, when declaring a dynamic allocated object, somehow like the pointer to base class pointed to object of derived class,
    // the declared pointer is of type base class and the allocated object is directly declared of type derived class.
    ColourCouter ( "----- Abstract base classes:\n", F_bWHITE );
    ColourCouter ( "Abstract base classes introduce pure virtual member functions.\n\n", F_YELLOW );
    ShiftR right { 1 };
    Bits* ptr_right { &right };
    Bits* ptr_left = new ShiftL { 1 }; // the dynamic allocated object
    std::cout << "Shift to right (result function):" << tab << ptr_right->result () << nline;
    std::cout << "Shift to left (result function):" << tab << ptr_left->result () << nline;
    std::cout << "Shift to right (print function):" << tab;
    ptr_right->print ();
    std::cout << "Shift to left (print function):" << "\t\t";
    ptr_left->print ();
    std::cout << nline;
  }
  catch ( const std::exception& )
  {

  }
}
