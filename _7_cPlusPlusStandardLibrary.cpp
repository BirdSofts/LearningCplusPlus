// --------------------------------------------------------------------------------
/// <summary>
/// _7_cPlusPlusStandardLibrary.h
/// </summary>
/// <created>ʆϒʅ,07.07.2019</created>
/// <changed>ʆϒʅ,13.10.2019</changed>
// --------------------------------------------------------------------------------

//#include "pch.h"
#include "LearningCplusPlus.h"
#include "Console.h"


#define Tab '\t'
#define Nline '\n'

const char tab { '\t' };
const char nline { '\n' };


void _24_01_InputAndOutputWithFiles ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ input/output with files:
    // standard streams classes provided by C++ language to perform output/input operations to and from files are:
    // --ofstream: to write to files
    // --ifstream: to read from files
    // --fstream: to read and write from/to files
    // directly or indirectly the base of these classes are the classes 'istream' or 'ostream',
    // which are the same already introduced basic input/output stream classes,
    // whose objects i.e.: 'cin' and 'cout' were used in examples of this tutorials total uncounted.
    // the big difference when it comes to physical files is the needed association,
    // after which the file streams can be used exactly on the same manner as objects of i/ostream.
    // to operate on physical files the header <fstream> is to be included additionally to <iostream>.
    // the used codes in the example below is going to be explained extended in the following sections.
    ColourCouter ( "~~~~~ Input/output with files:\n", F_bWHITE );
    ColourCouter ( "The diverted file stream classes from basic i/ostream classes satisfy the purpose.\n\n", F_YELLOW );
    std::ofstream firstTXTfile;
    firstTXTfile.open ( "text.txt" );
    firstTXTfile << "An output to a text file streamed using standard C++ file streams.";
    firstTXTfile.close ();
  }
  catch ( const std::exception& )
  {

  }
}


void _24_02_OpeningAndClosingFiles ()
{
  try
  {
    //! ####################################################################
    //! ----- opening files:
    // an object instantiated from the standard classes described above and provided to operate on files
    // generally needs to first associate a real existing file on the physical drives.
    // the procedure being known as to open a file,
    // the resulted object wraps the opened file and represents it as a stream object within the program.
    // afterward all the performed operations on this stream object is applied to the associated physical file.
    // Note: member function syntax: stream_object_identifier.open (filename, mode);
    // --the 'filename' parameter is to be passed a string representing the name of the physical file.
    // additionally the path to the file can be included to this parameter:
    // Note: example: "..\\.\\Directory\\FileName.ext"
    // two dots (..) for one directory backward, dot (.) to set the direction forward and double backslashes (\\) as separator.
    // --the optional parameter 'mode' is passable with arguments of a combined following flags:
    // -------------------------------------------------------------------------------------------------------------------------
    // flag         representation
    // ios::in      to open for inputting
    // ios::out     to open for outputting
    // ios::binary  to set the open mode 'binary'
    // ios::ate     to set the initial position at the end of the file (by default it is at the beginning of the file)
    // ios::app     set to operate at appending mode to add to the current file content
    // ios::trunc   if an existed file is open to output, it will delete the previous file content and replace them with new one
    // -------------------------------------------------------------------------------------------------------------------------
    // note that in the table introduced abbreviation 'ios' stands for 'ios_base',
    // in place of which either of the streams 'ofstream', 'ifstream' and 'fstream' is additionally usable,
    // therefore in real expressions it needs to be replaced and in case be preceded by the namespace 'std'.
    // the combination of the above flags using the bitwise operator (|) make it possible to choose different modes together.
    // Note: example of a binary file: stream_object_identifier.open ( "FileName.bin", ios::out | ios::app | ios::binary );
    // the open member functions of the classes 'ofstream', 'ifstream' and 'fstream' define the defaults of these modes,
    // if these member functions is called using just the first obligatory parameter:
    // -------------------------------
    // class      defined default mode
    // ofstream   ios::out
    // ifstream   ios::in
    // fstream    ios::in | ios::out
    // -------------------------------
    // in case of calling the open member functions of 'ifstream' and 'ofstream' passing new arguments as their second parameters,
    // their already defined default modes are going to be combined with the new ones passed.
    // on the other hand the process is in case of 'fstream' different, to be precise its defaults are only used,
    // when the calling expression provides the first mandatory parameter, that is, when the second parameter is passed,
    // the defaults provided by this member function is overridden.
    // while opened streams in binary mode operate on files independent of any format consideration,
    // non-binary known as text files need some translation due the format of some special characters like newline or carriage return.
    // using the constructors of these classes, since generally the first task of a file stream is to open a file,
    // they take exactly these two parameters and automatically open the file at the moment of instantiation
    // by calling the open member function, their destructors then close the file.
    // Note: example: std::ofstream stream_object_identifier ( "FileName.bin", ios::out | ios::app | ios::binary );
    // no matter which way a file is opened, both of these forms are valid and equivalent.
    // the member function 'is_open' returns a boolean value of true indicating,
    // whether the stream object is successfully associated an open file or false otherwise.

    //! ----- opening files:
    // an opened file in a stream object takes some resources from operating system,
    // thus after the operation with a file is done, OS needs awareness to free and set those resources available again.
    // calling the member function 'close' satisfies the purpose, flushes the buffers and closes the file opened by a stream object.
    // after closing a file using this member function, the stream object is available to open another file,
    // subsequently the closed file can be opened by other processes to operate on.
    // when a stream object is destroyed while being associated an open file,
    // the destructor automatically closes the file calling the member function 'close'.
    ColourCouter ( "----- Opening and closing files:\n", F_bWHITE );
    ColourCouter ( "For a successful operation, a file needs to probably be opened and closed.\n\n", F_YELLOW );
  }
  catch ( const std::exception& )
  {

  }
}


void _24_03_TextFiles ()
{
  try
  {
    //! ####################################################################
    //! ----- text files:
    // all associated files to a file stream object not mentioning ios::binary are text files, designed to store texts,
    // therefore all input/output operations passing values to/from them suffer some formatting translations,
    // in which the results don't necessarily correspond to their literal binary values.
    // like standard C++ input/output streams, the operators 'insertion' (<<) and 'extraction' (>>) are needed to operate on files.
    ColourCouter ( "----- Text files:\n", F_bWHITE );
    ColourCouter ( "Simple files designed to store texts.\n\n", F_YELLOW );
    std::cout << "Writing to a file, reading from it and capitalizing the characters for print:" << nline << nline;
    std::ofstream fileStreamOne ( "text.txt" );
    if ( fileStreamOne.is_open () )
    {
      fileStreamOne << "First line to a text file streamed using standard C++ file streams." << nline;
      fileStreamOne << "And this is the second line." << tab << "^;^" << nline;
      fileStreamOne.close ();
    }
    std::ifstream fileStreamTwo ( "text.txt" );
    std::string strLine { "" };
    std::string str { "" };
    // in the next expression, 'getline()' returns a reference to the object itself,
    // thus the evaluated result is 'true' if the stream is ready for more operations,
    // and 'false' if the end of the file is reached or an error is occurred.
    while ( std::getline ( fileStreamTwo, strLine ) )
    {
      for ( char el : strLine )
      {
        if ( ( el > 96 ) && ( el < 121 ) )
          el -= 32;
        str += el;
      }
      std::cout << str << nline;
      str = "";
    }
    fileStreamTwo.close ();
    std::cout << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _24_04_CheckingStateFlags ()
{
  try
  {
    //! ####################################################################
    //! ----- checking state flags:
    // followings are the member functions of a stream object provided to examine the current stream state,
    // all of which return a boolean value.
    // -- bad (): after a failure in a read/write operation, like having a close file under operation
    // or the device's lack of enough space, this member function results to 'true'.
    // -- fail (): when the same cases as 'bad ()' member function occur, this member function returns 'true' as result,
    // also if format errors happen, such as extraction of values with character nature, when an integer value is to be read.
    // -- eof (): this member function returns 'true', if the stream object while reading has reached the end of the file.
    // -- good (): this member function is the most generic one, returns 'false' when calling other function members result to 'true',
    // and despite the similarity considering 'bad ()' member function as antonym, they are not the exact opposites,
    // since 'good ()' member function examines more state flags at once.
    // -- clear (): the functionality of clearing the state flags is wrapped in this member function.
    ColourCouter ( "----- Checking state flags:\n", F_bWHITE );
    ColourCouter ( "To make sure whether a stream object functions as expected, different state flags are provided.\n\n", F_YELLOW );
  }
  catch ( const std::exception& )
  {

  }
}


void _24_05_GetAndPutStreamPositioning ()
{
  try
  {
    //! ####################################################################
    //! ----- get and put stream positioning:
    // at least one internal position is kept by all i/o stream objects:
    // --'ifstream' similar to 'istream', saves the location of the next element to be read in an internal 'get position'.
    // --'ofstream' similar to 'ostream', saves the location of the next element to be written in an internal 'put position'.
    // --'fstream' similar to 'iostream', saves both get and put positions.
    // while these internal stream positions indicate the locations, where the next read/write operation is performed,
    // they can be observed and modified through the member functions introduced below:
    // --'tellg ()' and 'tellp ()' are the member functions of an object instantiated from the streams above,
    // and while not taking any parameters return a value of the member type 'streampos',
    // which represents the current 'get position' and 'put position' in cases of 'tellg ()' and 'tellp ()' member functions in row.
    // --'seekg ()' and 'seekp ()' member functions after object instantiation from the i/o streams,
    // provide two different forms of overloaded prototypes:
    // Note: syntaxes:  seekg ( position );
    //                  seekp ( position );
    // these two different overloaded prototypes above are the first form, which take their parameters of type 'streampos',
    // and set the stream object pointer to the absolute location 'position', counting from the begin of the file.
    // Note: syntaxes:  seekg ( offset, direction );
    //                  seekp ( offset, direction );
    // two above introduced different overloaded prototypes as second form take their offset parameters of type 'streampos',
    // and set the 'get/put position' to an offset value counted from their taken parameters 'distance'.
    // their 'distance' parameters are of the enumerated type 'seekdir', taking any of the following values:
    // -------------------------------------------------------------
    // direction    representation
    // ios::beg     to count the offset from the begin of the stream
    // ios::cur     to count the offset from current position
    // ios::end     to count the offset from the begin of the stream
    // -------------------------------------------------------------
    // note that for an offset to be counted from the end of the file, which means in backward direction,
    // the offset needs to be introduced with negative numbers.
    // the above fact is additionally valid, when counting from current position in backward direction.
    // in the end, explaining the special member type 'streampos', its uses are in buffers and file positioning,
    // which as introduced up until now, is widely needed in member functions of objects instantiated from file stream classes.
    // values of this type, while being safely subtract-able,
    // are convertible to integers large enough to contain the size of the file.
    // another particular member type of stream class used by these stream positioning functions is 'streamoff'.
    // ---------------------------------------------------------------------------------------------------
    // type       member type     description
    // streampos  ios::pos_type   the type defined as fpos<mbstate_t>
    //                            is convertible to/from streamoff special member type and subtract-able to values thereof.
    // streamoff  ios::off_type   this type is defined as an alias of a fundamental integral type such as 'int' or 'long long'
    // ---------------------------------------------------------------------------------------------------
    // note that both the above special member types are aliases of their non-member equivalent fundamental types,
    // thus all of them are usable.
    // note that, since the special member types are the same on all stream objects,
    // including the stream objects using exotic types of characters, they are more generic,
    // on the other hand for historical reasons, the use of non-member types are wide in existing code.
    ColourCouter ( "----- Get and put stream positioning:\n", F_bWHITE );
    ColourCouter ( "Stream objects keep at least one internal stream position in their internal get/put positions.\n\n", F_YELLOW );
    ColourCouter ( "A text file created and inserted with two sentences in the examples of past sections:\n", F_bYELLOW );
    std::ifstream fileStream ( "text.txt" );
    std::streampos begin { fileStream.tellg () };
    fileStream.seekg ( 0, std::ifstream::end );
    long long end { fileStream.tellg () };
    //std::streampos end { fileStream.tellg () }; // the alias
    std::cout << "The size of the file is:" << tab << end - begin << nline;

    char ch [3] { '0' };
    fileStream.seekg ( -2, std::ifstream::end ); // from the end of the file in backward direction
    fileStream.seekg ( -3, std::ifstream::cur ); // from current position in backward direction
    for ( char i = 0; i < 3; i++ )
      fileStream >> ch [i];
    //fileStream.get ( ch [i] ); // alternative
    fileStream.close ();
    std::cout << "Extracting the smily at the end of the file:" << tab;
    for ( char i = 0; i < 3; i++ )
      std::cout << ch [i];
    std::cout << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


class dummy
{
private:
  int entity;
  std::string str;
public:
  dummy () { entity = 0; str = ""; };
  dummy ( int prmOne, std::string prmTwo ) : entity ( prmOne ), str ( prmTwo ) {}
  void print ( void ) { std::cout << "The object's elements are:" << tab << entity << tab << str; }
};
void _24_06_BinaryFiles ()
{
  try
  {
    //! ####################################################################
    //! ----- binary files:
    // when it comes to binary files, possibly the stored date is not formatted in lines,
    // and no extracted date from them needs to be formatted,
    // therefore extraction and insertion using the conventional operators (<< and >>),
    // functions like 'getline ()' or even some member functions provided for these kind of operations are not efficient.
    // instantiated objects from stream classes provide two specifically designed member functions,
    // which read or write binary date sequentially.
    // these two being declared as 'write' and 'read', based on their functionality,
    // are the member functions of 'ostream' or 'istream', are inherited from 'ofstream' or 'ifstream',
    // and additionally 'fstream' have them both introduced.
    // Note: prototype syntaxes:
    // an_object_of_streams.write ( memory_block, size );
    // an_object_of_streams.read ( memory_block, size );
    // note that their first parameter is a pointer to the type char (char*), representing the address of an array,
    // which will contain the bytes need to be read or write founded on their different functionality respectively.
    // their second parameter is passed a valid integer to specify the number of characters
    // needed to be read from the file into a block of memory, or to write it into the file.
    ColourCouter ( "----- Binary files:\n", F_bWHITE );
    ColourCouter ( "Files designed to store different kinds of unformatted data.\n\n", F_YELLOW );
    ColourCouter ( "Writing a binary file to be read in unformatted and formatted way:\n", F_bYELLOW );
    dummy data ( 10, "Hello!" ); // the object instantiated from the class
    std::streampos size { sizeof ( dummy ) };
    std::ofstream streamOne ( "binary.bin", std::ios_base::binary ); // object stream for write
    if ( streamOne.is_open () )
    {
      // complex data: simple type cast and write the content of the object already in the memory into the binary file
      streamOne.write ( ( char*) & data, size );
    }
    streamOne.close ();
    char* testTwo { new char [size] }; // to read the unformatted content of the binary file
    std::ifstream streamTwo ( "binary.bin", std::ios_base::binary ); // object stream for read
    streamTwo.seekg ( 0, std::ios_base::beg );
    std::cout << "Reading the unformatted content of the binary file:" << nline << nline;
    streamTwo.read ( testTwo, size ); // read the content into a pointer pointed to an array of char
    for ( int i = 0; i < size; i++ )
    {
      std::cout << testTwo [i];
    }
    std::cout << nline << nline;
    dummy* inFile { new dummy }; // to read the class written into the binary file for reusing purposes (formatted read)
    streamTwo.seekg ( 0, std::ios_base::beg );
    // complex data: simple type cast and read the data in char type form,
    // then format and load it into memory as a whole object of class pointed to by a pointer.
    streamTwo.read ( ( char*) inFile, size );
    std::cout << "Accessing the content of the binary file already loaded and correctly formatted in memory:" << nline << nline << tab;
    inFile->print ();
    streamTwo.close ();
    std::cout << nline << nline;
  }
  catch ( const std::exception& )
  {

  }
}


void _24_07_BuffersAndSynchronization ()
{
  try
  {
    //! ####################################################################
    //! ----- buffers and synchronization:
    // a stream object is provided with an internal buffer object of type 'streambuf', which may represent a memory block,
    // acting as an intermediary between the stream and the physical file.
    // with other words, through this buffer the operations on the file may be intermediated,
    // which means that the stream object itself may not directly insert or extract to/from the physical file.
    // additionally, consider that the operating system itself may define other layers of buffering,
    // intermediating all the read/write operations on files.
    // --closing a file: before the file is closed, the synchronization of all buffers that have not jet been flushed happens,
    // and all the pending data is going to be written or read to/from the physical drive.
    // --a full buffer: a buffer has size and when it is full, the automatic synchronization happens.
    // --explicit manipulators: stream objects are provided with certain manipulators such as 'flush' and 'endl',
    // each of them cause an explicit synchronization to take place.
    // --explicit member function 'sync ()': an explicit call to this member function immediately synchronize the buffer,
    // which returns an integer equal to -1, if the stream isn't associated a buffer or if the operation fails,
    // and otherwise 0 if the synchronization was indeed successful.
    ColourCouter ( "----- Buffers and synchronization:\n", F_bWHITE );
    ColourCouter ( "Operations on physical files may be intermediated through provided buffers.\n\n", F_YELLOW );
  }
  catch ( const std::exception& )
  {

  }
}


void _25_01_Extras ()
{
  try
  {
    // Todo Threads
    // Todo interface keyword
      
  }
  catch ( const std::exception& )
  {

  }
}
