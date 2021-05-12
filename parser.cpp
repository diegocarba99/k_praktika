/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"


  // C++|ko liburutegi estandarrak 
  #include <stdio.h>
  #include <iostream>
  #include <vector>
  #include <string>
  #include <list>
  #include <cstring>



  // Liburutegi pertsonalizatuak
  #include "Kodea.h"
  #include "Lag.h"
  #include "SinboloTaula.h"
  #include "SinboloTaulenPila.h"
  #include "Printer.h"

  using namespace std;
  
  extern int yylex();
  extern int yylineno;
  extern char *yytext;
  void yyerror (const char *msg) {
    printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
  }

  // Definitutako abstrakzioen aurrerazagupena
  Kodea kodea;
  SinboloTaulenPila stPila;


#line 104 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 39 "parser.y"

  #include "Kodea.h"
  #include "Lag.h"
  #include "SinboloTaula.h"
  #include "SinboloTaulenPila.h"

#line 154 "parser.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TID = 258,
    TFLOAT = 259,
    TINTEGER = 260,
    RPROGRAM = 261,
    RIF = 262,
    RWHILE = 263,
    RFOREVER = 264,
    RDO = 265,
    RPROC = 266,
    RUNTIL = 267,
    RELSE = 268,
    RSKIP = 269,
    REXIT = 270,
    RPRINTLN = 271,
    RREAD = 272,
    RINT = 273,
    RFLOAT = 274,
    RELSIF = 275,
    RAND = 276,
    ROR = 277,
    RNOT = 278,
    TMUL = 279,
    TASSIG = 280,
    TADD = 281,
    TSUB = 282,
    TDIV = 283,
    TCEQ = 284,
    TCGT = 285,
    TCLT = 286,
    TCGE = 287,
    TCLE = 288,
    TCNE = 289,
    TSEMIC = 290,
    TCOMMA = 291,
    TLPAREN = 292,
    TRPAREN = 293,
    TLBRACE = 294,
    TRBRACE = 295,
    TOUTPARAM = 296,
    TINOUTPARAM = 297,
    PRECED3 = 298,
    PRECED2 = 299,
    PRECED1 = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

    int ref;
    std::string *izena;
    std::string *mota;
    id_list *izenak;
    ref_list *next;
    azpiprog_st *azpi;
    expr_st *expr;
    ref_list_st *sent;
    var_st *var;

#line 223 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   101,   134,   133,   152,   155,   165,   174,
     179,   183,   189,   199,   205,   204,   225,   226,   230,   229,
     260,   264,   268,   275,   274,   295,   298,   317,   322,   342,
     372,   381,   404,   416,   421,   430,   444,   453,   458,   487,
     498,   507,   547,   587,   627,   644,   656,   668,   680,   692,
     704,   716,   728,   740,   749,   756,   763,   770,   784,   791
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TID", "TFLOAT", "TINTEGER", "RPROGRAM",
  "RIF", "RWHILE", "RFOREVER", "RDO", "RPROC", "RUNTIL", "RELSE", "RSKIP",
  "REXIT", "RPRINTLN", "RREAD", "RINT", "RFLOAT", "RELSIF", "RAND", "ROR",
  "RNOT", "TMUL", "TASSIG", "TADD", "TSUB", "TDIV", "TCEQ", "TCGT", "TCLT",
  "TCGE", "TCLE", "TCNE", "TSEMIC", "TCOMMA", "TLPAREN", "TRPAREN",
  "TLBRACE", "TRBRACE", "TOUTPARAM", "TINOUTPARAM", "PRECED3", "PRECED2",
  "PRECED1", "$accept", "programa", "$@1", "erazagupenak", "$@2",
  "id_zerrenda", "id_zerrendaren_bestea", "mota",
  "azpiprogramen_erazagupena", "azpiprogramaren_erazagupena", "$@3",
  "argumentuak", "par_zerrenda", "$@4", "par_mota",
  "par_zerrendaren_bestea", "$@5", "sententzia_zerrenda", "sententzia",
  "if_jarraipena", "bestela", "aldagaia", "adierazpena", "M", "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    12,    18,  -113,  -113,    31,  -113,  -113,    24,    26,
      48,    13,    24,    17,    30,  -113,  -113,  -113,    51,  -113,
    -113,    29,     6,    17,    31,    31,    31,  -113,     7,  -113,
      60,    32,    35,  -113,  -113,    43,    66,    65,  -113,  -113,
     -16,    61,    24,  -113,  -113,     7,     7,  -113,   205,    47,
       7,     7,    97,  -113,     7,   100,    71,  -113,  -113,  -113,
      26,  -113,    72,   290,   233,  -113,  -113,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,  -113,  -113,   263,
     248,    74,   278,    75,  -113,  -113,  -113,  -113,     7,     7,
    -113,     0,     0,  -113,   301,   301,   301,   301,   301,   301,
    -113,    68,  -113,    81,    82,  -113,  -113,    83,    87,   290,
     290,   128,    98,  -113,  -113,  -113,   143,    31,  -113,  -113,
    -113,  -113,  -113,   -16,  -113,     7,    84,    26,    -6,   189,
    -113,  -113,    85,     7,  -113,  -113,  -113,    83,  -113,   219,
      91,    93,  -113,   159,  -113,  -113,  -113,  -113,  -113,   174,
     190,  -113,  -113,    99,  -113,  -113,    -6,  -113,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     6,    10,    11,    13,     0,
       0,     0,    13,     9,     0,    14,    27,    12,     0,     7,
       4,    17,    58,     9,     6,     0,     6,    40,     0,    58,
       0,     0,     0,    58,    26,     0,     0,     0,     8,     5,
       0,     0,    13,    56,    55,     0,     0,    54,     0,     0,
       0,     0,     0,     3,     0,     0,     0,    21,    20,    22,
       0,    16,     0,    53,     0,    58,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    27,     0,
       0,     0,     0,     0,    33,    18,    27,    57,     0,     0,
      43,    41,    42,    44,    45,    46,    47,    48,    49,    50,
      27,    58,    58,     0,     0,    28,    27,    25,    58,    51,
      52,    58,     0,    32,    35,    34,    58,     0,    19,    15,
      59,    58,    58,     0,    58,     0,     0,     0,    37,     0,
      30,    23,     0,     0,    58,    36,    58,    25,    27,     0,
       0,     0,    24,    58,    58,    29,    27,    39,    27,    58,
      58,    58,    59,     0,    58,    31,     0,    58,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -113,  -113,  -113,    19,  -113,   -57,   110,   -19,   -11,  -113,
    -113,  -113,  -113,  -113,    -3,     2,  -113,   -59,  -113,  -113,
     -15,   -20,   -12,   -29,  -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     8,    24,    14,    19,     9,    11,    12,
      21,    26,    41,   107,    60,   118,   137,    22,    34,   134,
     135,    47,    48,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    17,    35,    85,    53,     1,    40,   132,   124,    27,
      27,    43,    44,    28,   133,     3,    29,    57,     4,   101,
      30,   -59,    31,    32,    67,    58,    59,   108,    70,    13,
      45,    62,    81,    63,    64,    10,    88,    89,    79,    80,
     154,   111,    82,    39,    46,    42,    33,   116,   100,     6,
       7,    15,    16,    18,    23,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    20,    25,    50,    54,    51,
     131,    27,    52,   113,    55,    28,   109,   110,    29,   143,
      56,    35,    30,   -59,    31,    32,    78,   149,    35,   150,
      27,    35,   125,   126,    28,   128,    35,    29,   123,    61,
      27,    30,   -59,    31,    32,   140,    84,   141,   112,    83,
     121,    86,   104,   129,   106,   148,   114,   115,   117,   130,
     127,   139,   153,    35,   138,   156,   145,   119,   158,    35,
      35,    27,   146,    38,   155,    28,     0,     0,    29,   142,
       0,   157,    30,   -59,    31,    32,    27,     0,     0,     0,
      28,     0,     0,    29,     0,     0,     0,    30,   -59,    31,
      32,     0,    27,     0,     0,     0,    28,     0,   120,    29,
       0,     0,     0,    30,   -59,    31,    32,    27,     0,     0,
       0,    28,     0,   122,    29,     0,     0,     0,    30,   -59,
      31,    32,     0,    27,     0,     0,     0,    28,     0,   147,
      29,     0,   136,     0,    30,   -59,    31,    32,     0,     0,
      65,    66,     0,    67,   151,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    65,    66,     0,    67,
     152,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      65,    66,     0,    67,    77,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    65,    66,     0,    67,   144,    68,
      69,    70,    71,    72,    73,    74,    75,    76,     0,    65,
      66,    87,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    65,    66,   103,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   102,    65,
      66,     0,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   105,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    67,     0,    68,    69,    70,
     -60,   -60,   -60,   -60,   -60,   -60
};

static const yytype_int16 yycheck[] =
{
      29,    12,    22,    60,    33,     6,    25,    13,   120,     3,
       3,     4,     5,     7,    20,     3,    10,    33,     0,    78,
      14,    15,    16,    17,    24,    41,    42,    86,    28,     3,
      23,    42,    52,    45,    46,    11,    65,    66,    50,    51,
     152,   100,    54,    24,    37,    26,    40,   106,    77,    18,
      19,     3,    39,    36,     3,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    35,    37,     7,    25,    37,
     127,     3,    37,   102,     8,     7,    88,    89,    10,   138,
      15,   101,    14,    15,    16,    17,    39,   146,   108,   148,
       3,   111,   121,   122,     7,   124,   116,    10,   117,    38,
       3,    14,    15,    16,    17,   134,    35,   136,    40,     9,
      12,    39,    38,   125,    39,   144,    35,    35,    35,    35,
     123,   133,   151,   143,    39,   154,    35,    40,   157,   149,
     150,     3,    39,    23,    35,     7,    -1,    -1,    10,   137,
      -1,   156,    14,    15,    16,    17,     3,    -1,    -1,    -1,
       7,    -1,    -1,    10,    -1,    -1,    -1,    14,    15,    16,
      17,    -1,     3,    -1,    -1,    -1,     7,    -1,    40,    10,
      -1,    -1,    -1,    14,    15,    16,    17,     3,    -1,    -1,
      -1,     7,    -1,    40,    10,    -1,    -1,    -1,    14,    15,
      16,    17,    -1,     3,    -1,    -1,    -1,     7,    -1,    40,
      10,    -1,    13,    -1,    14,    15,    16,    17,    -1,    -1,
      21,    22,    -1,    24,    40,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    21,    22,    -1,    24,
      40,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      21,    22,    -1,    24,    39,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    21,    22,    -1,    24,    39,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    21,
      22,    38,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    21,    22,    38,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    47,     3,     0,    48,    18,    19,    49,    53,
      11,    54,    55,     3,    51,     3,    39,    54,    36,    52,
      35,    56,    63,     3,    50,    37,    57,     3,     7,    10,
      14,    16,    17,    40,    64,    67,    69,    70,    52,    49,
      53,    58,    49,     4,     5,    23,    37,    67,    68,    69,
       7,    37,    37,    69,    25,     8,    15,    33,    41,    42,
      60,    38,    54,    68,    68,    21,    22,    24,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    39,    39,    68,
      68,    67,    68,     9,    35,    51,    39,    38,    69,    69,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    63,    35,    38,    38,    35,    39,    59,    63,    68,
      68,    63,    40,    69,    35,    35,    63,    35,    61,    40,
      40,    12,    40,    53,    70,    69,    69,    60,    69,    68,
      35,    51,    13,    20,    65,    66,    13,    62,    39,    68,
      69,    69,    61,    63,    39,    35,    39,    40,    69,    63,
      63,    40,    40,    69,    70,    35,    69,    66,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    48,    47,    50,    49,    49,    51,    52,    52,
      53,    53,    54,    54,    56,    55,    57,    57,    59,    58,
      60,    60,    60,    62,    61,    61,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     0,     5,     0,     2,     3,     0,
       1,     1,     2,     0,     0,     9,     3,     0,     0,     5,
       1,     1,     1,     0,     6,     0,     2,     0,     4,    11,
       8,    15,     5,     3,     5,     5,     1,     0,    10,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     2,     1,     1,     1,     3,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 102 "parser.y"
            {
              kodea.agGehitu("prog " + std::string(*(yyvsp[0].izena)));
              SinboloTaula st;
              stPila.pilaratu(st);
              delete (yyvsp[0].izena);
            }
#line 1539 "parser.cpp"
    break;

  case 3:
#line 109 "parser.y"
            {
              if ( ! (yyvsp[-2].sent)->error.empty() )
              {
                printErrors((yyvsp[-2].sent)->error);
              } 
              else
              {
                kodea.agGehitu("halt");
                kodea.agOsatu((yyvsp[-4].azpi)->zatizero, kodea.lortuErref() );
                kodea.agOsatu((yyvsp[-2].sent)->zatizero, kodea.lortuErref() );

                std::cout << "[info] M.ref: " << (yyvsp[0].ref) << endl;

                if ( !(yyvsp[-4].azpi)->zatizero.empty() || !(yyvsp[-2].sent)->zatizero.empty() ) {
                  kodea.agGehitu("write \"zerorekin zatiketa gertatu da\"");
                  kodea.agGehitu("writeln");
                  kodea.agGehitu("goto " + to_string((yyvsp[0].ref)));
                }
                kodea.idatzi();
                stPila.despilatu();
              }
            }
#line 1566 "parser.cpp"
    break;

  case 4:
#line 134 "parser.y"
                {
                  kodea.erazagupenakGehitu(*(yyvsp[-2].mota), *(yyvsp[-1].izenak));

                  // st_gehitu_aldagaiak();
                  id_list *izenak = (yyvsp[-1].izenak);
                  SinboloTaula st = stPila.tontorra();
                  stPila.despilatu();
                  while (izenak->size()>0){
                    st.gehituAldagaia(izenak->back(), *(yyvsp[-2].mota));  
                    izenak->pop_back();
                  }
                  stPila.pilaratu(st);


                  delete (yyvsp[-2].mota);
                  delete (yyvsp[-1].izenak);
                }
#line 1588 "parser.cpp"
    break;

  case 7:
#line 156 "parser.y"
              {
                (yyval.izenak) = new id_list;
                (yyvsp[0].izenak)->push_front(*(yyvsp[-1].izena));
                (yyval.izenak)->merge(*(yyvsp[0].izenak));  
                delete (yyvsp[-1].izena); 
                delete (yyvsp[0].izenak);
              }
#line 1600 "parser.cpp"
    break;

  case 8:
#line 166 "parser.y"
                        {
                          (yyval.izenak) = new id_list;
                          (yyvsp[0].izenak)->push_front(*(yyvsp[-1].izena));
                          (yyval.izenak)->merge(*(yyvsp[0].izenak));  
                          delete (yyvsp[-1].izena); 
                          delete (yyvsp[0].izenak);
                        }
#line 1612 "parser.cpp"
    break;

  case 9:
#line 174 "parser.y"
                        {
                          (yyval.izenak) = new id_list;
                        }
#line 1620 "parser.cpp"
    break;

  case 10:
#line 180 "parser.y"
        {
          (yyval.mota) = new string(MOTA_ENT);
        }
#line 1628 "parser.cpp"
    break;

  case 11:
#line 184 "parser.y"
        {
          (yyval.mota) = new string(MOTA_REAL);
        }
#line 1636 "parser.cpp"
    break;

  case 12:
#line 190 "parser.y"
                            {
                              (yyval.azpi) = new azpiprog_st;
                              (yyval.azpi)->zatizero.merge((yyvsp[-1].azpi)->zatizero);
                              (yyval.azpi)->zatizero.merge((yyvsp[0].azpi)->zatizero);

                              delete (yyvsp[-1].azpi);
                              delete (yyvsp[0].azpi);
                            }
#line 1649 "parser.cpp"
    break;

  case 13:
#line 199 "parser.y"
                            {
                              (yyval.azpi) = new azpiprog_st; 
                            }
#line 1657 "parser.cpp"
    break;

  case 14:
#line 205 "parser.y"
                              {
                                kodea.agGehitu( "proc " + string(*(yyvsp[0].izena))); 
                                SinboloTaula *st = new SinboloTaula; 
                                st->gehituProzedura(*(yyvsp[0].izena));
                                stPila.pilaratu(*st);
                              }
#line 1668 "parser.cpp"
    break;

  case 15:
#line 212 "parser.y"
                              {
                                kodea.agGehitu("endproc");

                                (yyval.azpi) = new azpiprog_st;
                                (yyval.azpi)->zatizero.merge((yyvsp[-3].azpi)->zatizero);
                                (yyval.azpi)->zatizero.merge((yyvsp[-1].sent)->zatizero);

                                delete (yyvsp[-3].azpi);
                                delete (yyvsp[-1].sent);
                                delete (yyvsp[-7].izena);
                              }
#line 1684 "parser.cpp"
    break;

  case 18:
#line 230 "parser.y"
                {
                  kodea.parametroakGehitu(string(*(yyvsp[-2].mota)), *(yyvsp[0].izenak), string(*(yyvsp[-1].mota)));

                  // st_gehitu_parametroak
                  id_list *izenak = (yyvsp[0].izenak);
                  //std::cout << "izenak lista sortu\n";
                  SinboloTaula st = stPila.tontorra();
                  //std::cout << "sinbolo taularen tontorra atzitu\n";
                  stPila.despilatu();
                  string prozeduraID = st.lortuLehenengoId();
                  //std::cout << "sinbolo taulako tontorra despilatu\n";
                  while (izenak->size()>0){
                    st.gehituParametroa(prozeduraID, *(yyvsp[-1].mota), *(yyvsp[-2].mota));
                    //std::cout << "st.gehituParametroa\n";
                    st.gehituAldagaia(izenak->back(), *(yyvsp[-2].mota));
                    //std::cout << "st.gehituAldagaia\n";
                    izenak->pop_back();
                    //std::cout << "izena atera zerrendatik\n";
                  }
                  stPila.pilaratu(st);
                  //std::cout << "pilaratu st\n";


                  delete (yyvsp[-2].mota);
                  delete (yyvsp[-1].mota);
                  delete (yyvsp[0].izenak);
                }
#line 1716 "parser.cpp"
    break;

  case 20:
#line 261 "parser.y"
            {
              (yyval.mota) = new string(PAR_VAL);
            }
#line 1724 "parser.cpp"
    break;

  case 21:
#line 265 "parser.y"
            {
              (yyval.mota) = new string(PAR_REF);
            }
#line 1732 "parser.cpp"
    break;

  case 22:
#line 269 "parser.y"
            {
              (yyval.mota) = new string(PAR_REF);
            }
#line 1740 "parser.cpp"
    break;

  case 23:
#line 275 "parser.y"
                          {
                            kodea.parametroakGehitu(string(*(yyvsp[-2].mota)), *(yyvsp[0].izenak), string(*(yyvsp[-1].mota)));

                            // st_gehitu_parametroak
                            id_list *izenak = (yyvsp[0].izenak);
                            SinboloTaula st = stPila.tontorra();
                            stPila.despilatu();
                            string prozeduraID = st.lortuLehenengoId();
                            while (izenak->size()>0){
                              st.gehituParametroa(prozeduraID, *(yyvsp[-1].mota), *(yyvsp[-2].mota));
                              st.gehituAldagaia(izenak->back(), *(yyvsp[-2].mota));
                              izenak->pop_back();
                            }
                            stPila.pilaratu(st);

                            delete (yyvsp[-2].mota);
                            delete (yyvsp[-1].mota);
                            delete (yyvsp[0].izenak);
                          }
#line 1764 "parser.cpp"
    break;

  case 26:
#line 299 "parser.y"
                      {
                        (yyval.sent) = new ref_list_st;
                        (yyval.sent)->exit.merge((yyvsp[-1].sent)->exit);
                        (yyval.sent)->exit.merge((yyvsp[0].sent)->exit);

                        (yyval.sent)->skip.merge((yyvsp[-1].sent)->skip);
                        (yyval.sent)->skip.merge((yyvsp[0].sent)->skip);

                        (yyval.sent)->error.merge((yyvsp[-1].sent)->error);
                        (yyval.sent)->error.merge((yyvsp[0].sent)->error);

                        (yyval.sent)->zatizero.merge((yyvsp[-1].sent)->zatizero);
                        (yyval.sent)->zatizero.merge((yyvsp[0].sent)->zatizero);

                        delete (yyvsp[-1].sent);
                        delete (yyvsp[0].sent);
                      }
#line 1786 "parser.cpp"
    break;

  case 27:
#line 317 "parser.y"
                      {
                        (yyval.sent) = new ref_list_st;
                      }
#line 1794 "parser.cpp"
    break;

  case 28:
#line 323 "parser.y"
              {
                (yyval.sent) = new ref_list_st;
                (yyval.sent)->zatizero.merge((yyvsp[-1].expr)->zatizero);

                if ((yyvsp[-3].var)->mota == MOTA_ENT && (yyvsp[-1].expr)->mota == MOTA_REAL){
                  (yyvsp[-3].var)->mota = MOTA_REAL;
                  kodea.agGehitu("implicit_conversion_to_real " + (yyvsp[-3].var)->izena);
                }

                kodea.agGehitu((yyvsp[-3].var)->izena + " := " + (yyvsp[-1].expr)->izena);

                if ( (yyvsp[-3].var)->mota.compare((yyvsp[-1].expr)->mota) != 0) {
                  //$<sent>$->error.merge(kalkulatuErroreak(ERR_NONE,*$<var>1, *$<expr>3)); 
                  kalkulatuErroreak((yyval.sent)->error, *(yyvsp[-3].var), *(yyvsp[-1].expr)); 
                }

                delete (yyvsp[-3].var); 
                delete (yyvsp[-1].expr); 
              }
#line 1818 "parser.cpp"
    break;

  case 29:
#line 343 "parser.y"
              {
                kodea.agOsatu((yyvsp[-9].expr)->true_list, (yyvsp[-7].ref));
                kodea.agOsatu((yyvsp[-9].expr)->false_list, (yyvsp[-3].ref));
                kodea.agOsatu(*(yyvsp[-4].next), (yyvsp[-1].ref));
                (yyval.sent) = new ref_list_st;

                (yyval.sent)->exit.merge((yyvsp[-6].sent)->exit);
                (yyval.sent)->exit.merge((yyvsp[-2].sent)->exit);
                
                (yyval.sent)->skip.merge((yyvsp[-6].sent)->skip);
                (yyval.sent)->skip.merge((yyvsp[-2].sent)->skip);
                
                (yyval.sent)->error.merge((yyvsp[-6].sent)->error);
                (yyval.sent)->error.merge((yyvsp[-2].sent)->error);
                
                (yyval.sent)->zatizero.merge((yyvsp[-9].expr)->zatizero);
                (yyval.sent)->zatizero.merge((yyvsp[-6].sent)->zatizero);
                (yyval.sent)->zatizero.merge((yyvsp[-2].sent)->zatizero);

                
                if ((yyvsp[-9].expr)->mota.compare(ADI_ERL) != 0)
                  kalkulatuErroreak((yyval.sent)->error, ERR_IF, *(yyvsp[-9].expr));

                delete (yyvsp[-9].expr);
                delete (yyvsp[-6].sent);
                delete (yyvsp[-2].sent);
                delete (yyvsp[-4].next);

              }
#line 1852 "parser.cpp"
    break;

  case 30:
#line 373 "parser.y"
              {
                kodea.agGehitu("goto " + to_string((yyvsp[-7].ref)));
                kodea.agOsatu((yyvsp[-3].sent)->exit, (yyvsp[-1].ref)+1);
                (yyval.sent) = new ref_list_st;
                (yyval.sent)->error.merge((yyvsp[-3].sent)->error);
                (yyval.sent)->zatizero.merge((yyvsp[-3].sent)->zatizero);
                delete (yyvsp[-3].sent);
              }
#line 1865 "parser.cpp"
    break;

  case 31:
#line 382 "parser.y"
              {
                kodea.agOsatu((yyvsp[-7].expr)->true_list, (yyvsp[-5].ref));
                kodea.agOsatu((yyvsp[-7].expr)->false_list, (yyvsp[-13].ref));
                kodea.agOsatu((yyvsp[-11].sent)->exit, (yyvsp[-5].ref));
                kodea.agOsatu((yyvsp[-11].sent)->skip, (yyvsp[-8].ref));
                kodea.agOsatu((yyvsp[-3].sent)->exit, (yyvsp[-1].ref));
                (yyval.sent) = new ref_list_st;
                (yyval.sent)->skip.merge((yyvsp[-3].sent)->skip);
                (yyval.sent)->zatizero.merge((yyvsp[-11].sent)->zatizero);
                (yyval.sent)->zatizero.merge((yyvsp[-7].expr)->zatizero);
                (yyval.sent)->zatizero.merge((yyvsp[-3].sent)->zatizero);                

                if ((yyvsp[-7].expr)->mota.compare(ADI_ERL) != 0)
                  kalkulatuErroreak((yyval.sent)->error, ERR_DO, *(yyvsp[-7].expr));

                (yyval.sent)->error.merge((yyvsp[-11].sent)->error);
                (yyval.sent)->error.merge((yyvsp[-3].sent)->error);

                delete (yyvsp[-7].expr);
                delete (yyvsp[-11].sent);
                delete (yyvsp[-3].sent);
              }
#line 1892 "parser.cpp"
    break;

  case 32:
#line 405 "parser.y"
              {
                kodea.agOsatu((yyvsp[-2].expr)->false_list, (yyvsp[0].ref));
                (yyval.sent) = new ref_list_st;
                (yyval.sent)->skip.merge((yyvsp[-2].expr)->true_list);
                (yyval.sent)->zatizero.merge((yyvsp[-2].expr)->zatizero);

                if ((yyvsp[-2].expr)->mota.compare(ADI_ERL) != 0)
                  kalkulatuErroreak((yyval.sent)->error, ERR_SKIP, *(yyvsp[-2].expr));

                delete (yyvsp[-2].expr);
              }
#line 1908 "parser.cpp"
    break;

  case 33:
#line 417 "parser.y"
              {
                (yyval.sent) = new ref_list_st;
                (yyval.sent)->exit.merge(*(yyvsp[-2].next));
              }
#line 1917 "parser.cpp"
    break;

  case 34:
#line 422 "parser.y"
              {
                kodea.agGehitu("read " + (yyvsp[-2].var)->izena);
                (yyval.sent) = new ref_list_st;
                
                // ikusi ea aldagia definitu den S_Tn

                delete (yyvsp[-2].var);
              }
#line 1930 "parser.cpp"
    break;

  case 35:
#line 431 "parser.y"
              {
                kodea.agGehitu("write " + string((yyvsp[-2].expr)->izena));
                kodea.agGehitu("writeln");
                (yyval.sent) = new ref_list_st;
                (yyval.sent)->zatizero.merge((yyvsp[-2].expr)->zatizero);

                if ((yyvsp[-2].expr)->mota.compare(ADI_ERL) == 0)
                  kalkulatuErroreak((yyval.sent)->error, ERR_PRINT, *(yyvsp[-2].expr));

                delete (yyvsp[-2].expr); 
              }
#line 1946 "parser.cpp"
    break;

  case 36:
#line 445 "parser.y"
              {
                (yyval.sent) = new ref_list_st;
                (yyval.sent)->exit.merge((yyvsp[0].sent)->exit);
                (yyval.sent)->skip.merge((yyvsp[0].sent)->skip);
                (yyval.sent)->error.merge((yyvsp[0].sent)->error);
                (yyval.sent)->zatizero.merge((yyvsp[0].sent)->zatizero);
              }
#line 1958 "parser.cpp"
    break;

  case 37:
#line 453 "parser.y"
              {
                (yyval.sent) = new ref_list_st;
              }
#line 1966 "parser.cpp"
    break;

  case 38:
#line 459 "parser.y"
        {
          kodea.agOsatu((yyvsp[-8].expr)->true_list, (yyvsp[-6].ref));
          kodea.agOsatu((yyvsp[-8].expr)->false_list, (yyvsp[-2].ref));
          kodea.agOsatu(*(yyvsp[-3].next), (yyvsp[0].ref));
          (yyval.sent) = new ref_list_st;

          (yyval.sent)->exit.merge((yyvsp[-5].sent)->exit);
          (yyval.sent)->exit.merge((yyvsp[-1].sent)->exit);
          
          (yyval.sent)->skip.merge((yyvsp[-5].sent)->skip);
          (yyval.sent)->skip.merge((yyvsp[-1].sent)->skip);
          
          (yyval.sent)->error.merge((yyvsp[-5].sent)->error);
          (yyval.sent)->error.merge((yyvsp[-1].sent)->error);
          
          (yyval.sent)->zatizero.merge((yyvsp[-8].expr)->zatizero);
          (yyval.sent)->zatizero.merge((yyvsp[-5].sent)->zatizero);
          (yyval.sent)->zatizero.merge((yyvsp[-1].sent)->zatizero);

          
          if ((yyvsp[-8].expr)->mota.compare(ADI_ERL) != 0)
            kalkulatuErroreak((yyval.sent)->error, ERR_IF, *(yyvsp[-8].expr));

          delete (yyvsp[-8].expr);
          delete (yyvsp[-5].sent);
          delete (yyvsp[-1].sent);
          delete (yyvsp[-3].next);
        }
#line 1999 "parser.cpp"
    break;

  case 39:
#line 488 "parser.y"
        {
          (yyval.sent) = new ref_list_st;
          (yyval.sent)->exit.merge((yyvsp[-1].sent)->exit);
          (yyval.sent)->skip.merge((yyvsp[-1].sent)->skip);
          (yyval.sent)->error.merge((yyvsp[-1].sent)->error);
          (yyval.sent)->zatizero.merge((yyvsp[-1].sent)->zatizero);
        }
#line 2011 "parser.cpp"
    break;

  case 40:
#line 499 "parser.y"
            {
              (yyval.var) = new var_st;
              (yyval.var)->izena = string(*(yyvsp[0].izena));
              (yyval.var)->mota = stPila.lortuMota(*(yyvsp[0].izena));
              delete (yyvsp[0].izena);
            }
#line 2022 "parser.cpp"
    break;

  case 41:
#line 508 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = kodea.idBerria();
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);

                int mota_aldaketa = kalkulatuMota(*(yyval.expr), *(yyvsp[-2].expr), *(yyvsp[0].expr));
                string ad1_converted, ad2_converted;

                if (mota_aldaketa == 0)  // ez dago mota aldaketarik. izenak mantendu
                {
                  ad1_converted = (yyvsp[-2].expr)->izena;
                  ad2_converted = (yyvsp[0].expr)->izena;
                } 
                else if (mota_aldaketa == 1)  // 1go adierazpena aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = (yyvsp[0].expr)->izena;
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + (yyvsp[-2].expr)->izena  + ")");
                }
                else if (mota_aldaketa == 2)  // 2go adierazpena aldatu real motara
                {
                  ad1_converted = (yyvsp[-2].expr)->izena;
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + (yyvsp[0].expr)->izena  + ")");
                }
                else  // 1go eta 2n adierazpenak aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + (yyvsp[-2].expr)->izena  + ")");
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + (yyvsp[0].expr)->izena  + ")");
                }

                kodea.agGehitu((yyval.expr)->izena + " := " + ad1_converted  + " + " + ad2_converted);
                
                delete (yyvsp[-2].expr);
                delete (yyvsp[0].expr);
              }
#line 2066 "parser.cpp"
    break;

  case 42:
#line 548 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = kodea.idBerria();
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);

                int mota_aldaketa = kalkulatuMota(*(yyval.expr), *(yyvsp[-2].expr), *(yyvsp[0].expr));
                string ad1_converted, ad2_converted;

                if (mota_aldaketa == 0)  // ez dago mota aldaketarik. izenak mantendu
                {
                  ad1_converted = (yyvsp[-2].expr)->izena;
                  ad2_converted = (yyvsp[0].expr)->izena;
                } 
                else if (mota_aldaketa == 1)  // 1go adierazpena aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = (yyvsp[0].expr)->izena;
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + (yyvsp[-2].expr)->izena  + ")");
                }
                else if (mota_aldaketa == 2)  // 2go adierazpena aldatu real motara
                {
                  ad1_converted = (yyvsp[-2].expr)->izena;
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + (yyvsp[0].expr)->izena  + ")");
                }
                else  // 1go eta 2n adierazpenak aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + (yyvsp[-2].expr)->izena  + ")");
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + (yyvsp[0].expr)->izena  + ")");
                }

                kodea.agGehitu((yyval.expr)->izena + " := " + ad1_converted  + " - " + ad2_converted);
                
                delete (yyvsp[-2].expr);
                delete (yyvsp[0].expr);
              }
#line 2110 "parser.cpp"
    break;

  case 43:
#line 588 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = kodea.idBerria();
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
                
                int mota_aldaketa = kalkulatuMota(*(yyval.expr), *(yyvsp[-2].expr), *(yyvsp[0].expr));
                string ad1_converted, ad2_converted;

                if (mota_aldaketa == 0)  // ez dago mota aldaketarik. izenak mantendu
                {
                  ad1_converted = (yyvsp[-2].expr)->izena;
                  ad2_converted = (yyvsp[0].expr)->izena;
                } 
                else if (mota_aldaketa == 1)  // 1go adierazpena aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = (yyvsp[0].expr)->izena;
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + (yyvsp[-2].expr)->izena  + ")");
                }
                else if (mota_aldaketa == 2)  // 2go adierazpena aldatu real motara
                {
                  ad1_converted = (yyvsp[-2].expr)->izena;
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + (yyvsp[0].expr)->izena  + ")");
                }
                else  // 1go eta 2n adierazpenak aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + (yyvsp[-2].expr)->izena  + ")");
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + (yyvsp[0].expr)->izena  + ")");
                }

                kodea.agGehitu((yyval.expr)->izena + " := " + ad1_converted  + " * " + ad2_converted);

                delete (yyvsp[-2].expr);
                delete (yyvsp[0].expr);
              }
#line 2154 "parser.cpp"
    break;

  case 44:
#line 628 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = kodea.idBerria();
                (yyval.expr)->mota = MOTA_REAL;   
                (yyval.expr)->zatizero.push_front(kodea.lortuErref());
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);   
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);

                for(auto v: (yyval.expr)->zatizero) std::cout << "[info] zatizero reference: " << v << std::endl;

                kodea.agGehitu("if " + (yyvsp[0].expr)->izena + " = 0 goto");      
                kodea.agGehitu((yyval.expr)->izena + " := " + (yyvsp[-2].expr)->izena  + " / " + (yyvsp[0].expr)->izena);

                delete (yyvsp[-2].expr);
                delete (yyvsp[0].expr);
              }
#line 2175 "parser.cpp"
    break;

  case 45:
#line 645 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.push_front(kodea.lortuErref());
                (yyval.expr)->false_list.push_front(kodea.lortuErref()+1); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
                kodea.agGehitu("if " + (yyvsp[-2].expr)->izena  + " = " + (yyvsp[0].expr)->izena + " goto");
                kodea.agGehitu("goto");
              }
#line 2191 "parser.cpp"
    break;

  case 46:
#line 657 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.push_front(kodea.lortuErref());
                (yyval.expr)->false_list.push_front(kodea.lortuErref()+1); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
                kodea.agGehitu("if " + (yyvsp[-2].expr)->izena  + " > " + (yyvsp[0].expr)->izena + " goto");
                kodea.agGehitu("goto");
              }
#line 2207 "parser.cpp"
    break;

  case 47:
#line 669 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.push_front(kodea.lortuErref());
                (yyval.expr)->false_list.push_front(kodea.lortuErref()+1); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
                kodea.agGehitu("if " + (yyvsp[-2].expr)->izena  + " < " + (yyvsp[0].expr)->izena + " goto");
                kodea.agGehitu("goto");
              }
#line 2223 "parser.cpp"
    break;

  case 48:
#line 681 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.push_front(kodea.lortuErref());
                (yyval.expr)->false_list.push_front(kodea.lortuErref()+1); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
                kodea.agGehitu("if " + (yyvsp[-2].expr)->izena  + " >= " + (yyvsp[0].expr)->izena + " goto");
                kodea.agGehitu("goto");
              }
#line 2239 "parser.cpp"
    break;

  case 49:
#line 693 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.push_front(kodea.lortuErref());
                (yyval.expr)->false_list.push_front(kodea.lortuErref()+1); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
                kodea.agGehitu("if " + (yyvsp[-2].expr)->izena  + " <= " + (yyvsp[0].expr)->izena + " goto");
                kodea.agGehitu("goto");
              }
#line 2255 "parser.cpp"
    break;

  case 50:
#line 705 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.push_front(kodea.lortuErref());
                (yyval.expr)->false_list.push_front(kodea.lortuErref()+1); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[-2].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
                kodea.agGehitu("if " + (yyvsp[-2].expr)->izena  + " != " + (yyvsp[0].expr)->izena + " goto");
                kodea.agGehitu("goto");
              }
#line 2271 "parser.cpp"
    break;

  case 51:
#line 717 "parser.y"
              { 
                kodea.agOsatu((yyvsp[-3].expr)->true_list, (yyvsp[-1].ref));
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.merge((yyvsp[0].expr)->true_list);
                (yyval.expr)->false_list.merge((yyvsp[-3].expr)->false_list);
                (yyval.expr)->false_list.merge((yyvsp[0].expr)->false_list); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[-3].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
              }
#line 2287 "parser.cpp"
    break;

  case 52:
#line 729 "parser.y"
              {
                kodea.agOsatu((yyvsp[-3].expr)->false_list, (yyvsp[-1].ref));
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.merge((yyvsp[-3].expr)->true_list);
                (yyval.expr)->true_list.merge((yyvsp[0].expr)->true_list);
                (yyval.expr)->false_list.merge((yyvsp[0].expr)->false_list); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[-3].expr)->zatizero);
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
              }
#line 2303 "parser.cpp"
    break;

  case 53:
#line 741 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = "";
                (yyval.expr)->true_list.merge((yyvsp[0].expr)->false_list);
                (yyval.expr)->false_list.merge((yyvsp[0].expr)->true_list); 
                (yyval.expr)->mota = ADI_ERL;
                (yyval.expr)->zatizero.merge((yyvsp[0].expr)->zatizero);
              }
#line 2316 "parser.cpp"
    break;

  case 54:
#line 750 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = (yyvsp[0].var)->izena.data();
                (yyval.expr)->mota = (yyvsp[0].var)->mota;
                delete (yyvsp[0].var);
              }
#line 2327 "parser.cpp"
    break;

  case 55:
#line 757 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = string(*(yyvsp[0].izena));
                (yyval.expr)->mota = string(MOTA_ENT);
                delete (yyvsp[0].izena);
              }
#line 2338 "parser.cpp"
    break;

  case 56:
#line 764 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = string(*(yyvsp[0].izena));
                (yyval.expr)->mota = string(MOTA_REAL);
                delete (yyvsp[0].izena);
              }
#line 2349 "parser.cpp"
    break;

  case 57:
#line 771 "parser.y"
              {
                (yyval.expr) = new expr_st;
                (yyval.expr)->izena = string((yyvsp[-1].expr)->izena);
                (yyval.expr)->true_list.merge((yyvsp[-1].expr)->true_list);
                (yyval.expr)->false_list.merge((yyvsp[-1].expr)->false_list); 
                (yyval.expr)->mota = (yyvsp[-1].expr)->mota;
                (yyval.expr)->zatizero.merge((yyvsp[-1].expr)->zatizero);
                delete (yyvsp[-1].expr);
              }
#line 2363 "parser.cpp"
    break;

  case 58:
#line 784 "parser.y"
    { 
      (yyval.ref) = kodea.lortuErref(); 
    }
#line 2371 "parser.cpp"
    break;

  case 59:
#line 791 "parser.y"
    { 
      (yyval.next) = new ref_list;
      (yyval.next)->push_back(kodea.lortuErref());
      kodea.agGehitu("goto");
    }
#line 2381 "parser.cpp"
    break;


#line 2385 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 797 "parser.y"


