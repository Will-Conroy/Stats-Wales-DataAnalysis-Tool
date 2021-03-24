#ifndef INPUT_H_
#define INPUT_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: 976789

  This file contains declarations for the input source handlers. There are
  two classes: InputSource and InputFile. InputSource is abstract (i.e. it
  contains a pure virtual function). InputFile is a concrete derivation of
  InputSource, for input from files.

  Although only one class derives from InputSource, we have implemented our
  code this way to support future expansion of input from different sources
  (e.g. the web).


  functions and member variables you need to declare in these classes.
 */

#include <string>
#include <fstream>

/*
  InputSource is an abstract/purely virtual base class for all input source 
  types. In future versions of our application, we may support multiple input 
  data sources such as files and web pages. Therefore, this virtual class 
  will allow us to mix/match sources as needed. 

  there may be additional constructors or functions you implement here,
  and perhaps additional operators you may wish to overload.
*/
class InputSource {
protected:
    InputSource(const std::string& source);
    std::string source;

public:
    std::string getSource();

};

/*
  Source data that is contained within a file. For now, our application will
  only work with files (and in particular, the files in the datasets directory).

  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class InputFile : public InputSource {
public:
  InputFile(const std::string& filePath);
  std::istream& open();
};

#endif // INPUT_H_