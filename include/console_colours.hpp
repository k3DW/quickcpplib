/* console_colours.hpp
Portable colourful console printing
(C) 2016 Niall Douglas http://www.nedprod.com/
File Created: Apr 2016


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef BOOSTLITE_CONSOLE_COLOURS_HPP
#define BOOSTLITE_CONSOLE_COLOURS_HPP

#include "config.hpp"

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

BOOSTLITE_NAMESPACE_BEGIN

namespace console_colours
{
#ifdef _WIN32
  namespace detail
  {
    inline bool &am_in_bold()
    {
      static bool v;
      return v;
    }
    inline void set(WORD v)
    {
      if(am_in_bold())
        v |= FOREGROUND_INTENSITY;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), v);
    }
  }
  //! Makes the text on the console red
  inline std::ostream &red(std::ostream &s)
  {
    s.flush();
    detail::set(FOREGROUND_RED);
    return s;
  }
  //! Makes the text on the console green
  inline std::ostream &green(std::ostream &s)
  {
    s.flush();
    detail::set(FOREGROUND_GREEN);
    return s;
  }
  //! Makes the text on the console blue
  inline std::ostream &blue(std::ostream &s)
  {
    s.flush();
    detail::set(FOREGROUND_BLUE);
    return s;
  }
  //! Makes the text on the console yellow
  inline std::ostream &yellow(std::ostream &s)
  {
    s.flush();
    detail::set(FOREGROUND_RED | FOREGROUND_GREEN);
    return s;
  }
  //! Makes the text on the console magenta
  inline std::ostream &magenta(std::ostream &s)
  {
    s.flush();
    detail::set(FOREGROUND_RED | FOREGROUND_BLUE);
    return s;
  }
  //! Makes the text on the console cyan
  inline std::ostream &cyan(std::ostream &s)
  {
    s.flush();
    detail::set(FOREGROUND_GREEN | FOREGROUND_BLUE);
    return s;
  }
  //! Makes the text on the console white
  inline std::ostream &white(std::ostream &s)
  {
    s.flush();
    detail::set(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return s;
  }
  //! Makes the text on the console bold
  inline std::ostream &bold(std::ostream &s)
  {
    detail::am_in_bold() = true;
    return s;
  }
  //! Makes the text on the console non-bold and white
  inline std::ostream &normal(std::ostream &s)
  {
    detail::am_in_bold() = false;
    return white(s);
  }
#else
  //! Makes the text on the console red
  constexpr const char red[] = {0x1b, '[', '3', '1', 'm', 0};
  //! Makes the text on the console green
  constexpr const char green[] = {0x1b, '[', '3', '2', 'm', 0};
  //! Makes the text on the console blue
  constexpr const char blue[] = {0x1b, '[', '3', '4', 'm', 0};
  //! Makes the text on the console yellow
  constexpr const char yellow[] = {0x1b, '[', '3', '3', 'm', 0};
  //! Makes the text on the console magenta
  constexpr const char magenta[] = {0x1b, '[', '3', '5', 'm', 0};
  //! Makes the text on the console cyan
  constexpr const char cyan[] = {0x1b, '[', '3', '6', 'm', 0};
  //! Makes the text on the console white
  constexpr const char white[] = {0x1b, '[', '3', '7', 'm', 0};
  //! Makes the text on the console bold
  constexpr const char bold[] = {0x1b, '[', '1', 'm', 0};
  //! Makes the text on the console non-bold and white
  constexpr const char normal[] = {0x1b, '[', '0', 'm', 0};
#endif
}

BOOSTLITE_NAMESPACE_END

#endif
