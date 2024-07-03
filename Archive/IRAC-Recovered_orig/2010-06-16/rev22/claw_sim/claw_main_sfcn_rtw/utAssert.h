/*
 * utAssert.h
 *
 * Real-Time Workshop code generation for Simulink model "claw_main_sf.mdl".
 *
 * Model Version              : 1.5449
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Dec 13 11:25:43 2011
 */

#ifndef RTW_HEADER_utAssert_h_
#define RTW_HEADER_utAssert_h_

/*=========*
 * Asserts *
 *=========*/
#ifndef utAssert
# if defined(DOASSERTS)
#  if !defined(PRINT_ASSERTS)
#    include <assert.h>
#    define utAssert(exp)              assert(exp)
#  else
#    include <stdio.h>

static void _assert(char *statement, char *file, int line)
{
  printf("%s in %s on line %d\n", statement, file, line);
}

#   define utAssert(_EX)               ((_EX) ? (void)0 : _assert(#_EX, __FILE__, __LINE__))
#  endif

# else
#  define utAssert(exp)                                          /* do nothing */
# endif
#endif
#endif                                 /* RTW_HEADER_utAssert_h_ */