dnl $Id$
dnl config.m4 for extension u4u_functions

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(u4u_functions, for u4u_functions support,
dnl Make sure that the comment is aligned:
dnl [  --with-u4u_functions             Include u4u_functions support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(u4u_functions, whether to enable u4u_functions support,
dnl Make sure that the comment is aligned:
[  --enable-u4u_functions           Enable u4u_functions support])

if test "$PHP_U4U_FUNCTIONS" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-u4u_functions -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/u4u_functions.h"  # you most likely want to change this
  dnl if test -r $PHP_U4U_FUNCTIONS/$SEARCH_FOR; then # path given as parameter
  dnl   U4U_FUNCTIONS_DIR=$PHP_U4U_FUNCTIONS
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for u4u_functions files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       U4U_FUNCTIONS_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$U4U_FUNCTIONS_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the u4u_functions distribution])
  dnl fi

  dnl # --with-u4u_functions -> add include path
  dnl PHP_ADD_INCLUDE($U4U_FUNCTIONS_DIR/include)

  dnl # --with-u4u_functions -> check for lib and symbol presence
  dnl LIBNAME=u4u_functions # you may want to change this
  dnl LIBSYMBOL=u4u_functions # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $U4U_FUNCTIONS_DIR/lib, U4U_FUNCTIONS_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_U4U_FUNCTIONSLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong u4u_functions lib version or lib not found])
  dnl ],[
  dnl   -L$U4U_FUNCTIONS_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(U4U_FUNCTIONS_SHARED_LIBADD)

  PHP_NEW_EXTENSION(u4u_functions, u4u_functions.c, $ext_shared)
fi
