/* boostmacros.hpp
Provides lightweight Boost macros
(C) 2014 Niall Douglas http://www.nedprod.com/
File Created: Aug 2014


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

#ifndef BOOST_STL11_MAP_MACROS_HPP
#define BOOST_STL11_MAP_MACROS_HPP
 
#ifndef BOOST_SMT_PAUSE
# if defined(_MSC_VER) && _MSC_VER >= 1310 && ( defined(_M_IX86) || defined(_M_X64) )
extern "C" void _mm_pause();
#  pragma intrinsic( _mm_pause )
#  define BOOST_SMT_PAUSE _mm_pause();
# elif defined(__GNUC__) && ( defined(__i386__) || defined(__x86_64__) )
#  define BOOST_SMT_PAUSE __asm__ __volatile__( "rep; nop" : : : "memory" );
# endif
#endif

#ifndef BOOST_NOEXCEPT
# if !defined(_MSC_VER) || _MSC_VER >= 1900
#  define BOOST_NOEXCEPT noexcept
# endif
#endif
#ifndef BOOST_NOEXCEPT
# define BOOST_NOEXCEPT
#endif

#ifndef BOOST_NOEXCEPT_OR_NOTHROW
# if !defined(_MSC_VER) || _MSC_VER >= 1900
#  define BOOST_NOEXCEPT_OR_NOTHROW noexcept
# endif
#endif
#ifndef BOOST_NOEXCEPT_OR_NOTHROW
# define BOOST_NOEXCEPT_OR_NOTHROW throw()
#endif

#ifndef BOOST_NOEXCEPT_IF
# if !defined(_MSC_VER) || _MSC_VER >= 1900
#  define BOOST_NOEXCEPT_IF(v) noexcept(v)
# endif
#endif
#ifndef BOOST_NOEXCEPT_IF
# define BOOST_NOEXCEPT_IF
#endif

#ifndef BOOST_NOEXCEPT_EXPR
# if !defined(_MSC_VER) || _MSC_VER >= 1900
#  define BOOST_NOEXCEPT_EXPR(v) noexcept(v)
# endif
#endif
#ifndef BOOST_NOEXCEPT_EXPR
# define BOOST_NOEXCEPT_EXPR false
#endif

#ifndef BOOST_CONSTEXPR
# if !defined(_MSC_VER) || _MSC_VER >= 2000
#  define BOOST_CONSTEXPR constexpr
# endif
#endif
#ifndef BOOST_CONSTEXPR
# define BOOST_CONSTEXPR
#endif

#ifndef BOOST_CONSTEXPR_OR_CONST
# if !defined(_MSC_VER) || _MSC_VER >= 1900
#  define BOOST_CONSTEXPR_OR_CONST constexpr
# endif
#endif
#ifndef BOOST_CONSTEXPR_OR_CONST
# define BOOST_CONSTEXPR_OR_CONST const
#endif

#ifndef BOOST_FORCEINLINE
# if defined(_MSC_VER)
#  define BOOST_FORCEINLINE __forceinline
# elif defined(__GNUC__)
#  define BOOST_FORCEINLINE __attribute__((always_inline))
# else
#  define BOOST_FORCEINLINE
# endif
#endif

#ifndef BOOST_FOREACH
#define BOOST_FOREACH(a, b) for(a : b)
#endif

#ifndef BOOST_MSVC
#ifdef _MSC_VER
#define BOOST_MSVC _MSC_VER
#endif
#endif
#ifndef BOOST_GCC
#ifdef __GNUC__
#define BOOST_GCC (__GNUC__ * 10000 \
                   + __GNUC_MINOR__ * 100 \
                   + __GNUC_PATCHLEVEL__)
#endif
#endif

/* The following are for convenience, but really should be regex find & replace in modern C++ */
#ifndef BOOST_FWD_REF
#define BOOST_FWD_REF(a) a&&
#endif

#ifndef BOOST_RV_REF
#define BOOST_RV_REF(a) a&&
#endif

#ifndef BOOST_COPY_ASSIGN_REF
#define BOOST_COPY_ASSIGN_REF(a) const a&
#endif

#ifndef BOOST_STATIC_ASSERT_MSG
#define BOOST_STATIC_ASSERT_MSG(v, m) static_assert((v), m)
#endif

#endif
