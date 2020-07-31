// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "rtlcore_parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "rtlcore_parser.tab.hh"

// User implementation prologue.

#line 51 "rtlcore_parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 33 "rtlcore_parser.yy" // lalr1.cc:413

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "RtlCoreDriver.h"
   #include "RtlCoreScanner.h"

#undef yylex
#define yylex scanner.yylex

#line 66 "rtlcore_parser.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "rtlcore_parser.yy" // lalr1.cc:479
namespace ThermPlanner {
#line 152 "rtlcore_parser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  RtlCoreParser::RtlCoreParser (RtlCoreScanner  &scanner_yyarg, RtlCoreDriver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  RtlCoreParser::~RtlCoreParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  RtlCoreParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  RtlCoreParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  RtlCoreParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 5: // ID
      case 6: // BINARY_VAL
      case 27: // ModuleDecl
        value.copy<  std::string  > (other.value);
        break;

      case 4: // INTEGER
        value.copy<  unsigned  > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  RtlCoreParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 5: // ID
      case 6: // BINARY_VAL
      case 27: // ModuleDecl
        value.copy<  std::string  > (v);
        break;

      case 4: // INTEGER
        value.copy<  unsigned  > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  RtlCoreParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  RtlCoreParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const  std::string  v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  RtlCoreParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const  unsigned  v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  RtlCoreParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  RtlCoreParser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 5: // ID
      case 6: // BINARY_VAL
      case 27: // ModuleDecl
        value.template destroy<  std::string  > ();
        break;

      case 4: // INTEGER
        value.template destroy<  unsigned  > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  RtlCoreParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  RtlCoreParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 5: // ID
      case 6: // BINARY_VAL
      case 27: // ModuleDecl
        value.move<  std::string  > (s.value);
        break;

      case 4: // INTEGER
        value.move<  unsigned  > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  RtlCoreParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  RtlCoreParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  RtlCoreParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  RtlCoreParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  RtlCoreParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  RtlCoreParser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  RtlCoreParser::symbol_type
  RtlCoreParser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_ERROR (const location_type& l)
  {
    return symbol_type (token::ERROR, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_INTEGER (const  unsigned & v, const location_type& l)
  {
    return symbol_type (token::INTEGER, v, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_ID (const  std::string & v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_BINARY_VAL (const  std::string & v, const location_type& l)
  {
    return symbol_type (token::BINARY_VAL, v, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_VERI_MODULE (const location_type& l)
  {
    return symbol_type (token::VERI_MODULE, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_VERI_ENDMODULE (const location_type& l)
  {
    return symbol_type (token::VERI_ENDMODULE, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_VERI_INPUT (const location_type& l)
  {
    return symbol_type (token::VERI_INPUT, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_VERI_OUTPUT (const location_type& l)
  {
    return symbol_type (token::VERI_OUTPUT, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_VERI_WIRE (const location_type& l)
  {
    return symbol_type (token::VERI_WIRE, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_VERI_ASSIGN (const location_type& l)
  {
    return symbol_type (token::VERI_ASSIGN, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_LEFT_PAREN (const location_type& l)
  {
    return symbol_type (token::LEFT_PAREN, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_RIGHT_PAREN (const location_type& l)
  {
    return symbol_type (token::RIGHT_PAREN, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::COMMA, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_SEMI_COLON (const location_type& l)
  {
    return symbol_type (token::SEMI_COLON, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_LEFT_CURL (const location_type& l)
  {
    return symbol_type (token::LEFT_CURL, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_RIGHT_CURL (const location_type& l)
  {
    return symbol_type (token::RIGHT_CURL, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_LEFT_BRAKET (const location_type& l)
  {
    return symbol_type (token::LEFT_BRAKET, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_RIGHT_BRAKET (const location_type& l)
  {
    return symbol_type (token::RIGHT_BRAKET, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_COLON (const location_type& l)
  {
    return symbol_type (token::COLON, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_DOT (const location_type& l)
  {
    return symbol_type (token::DOT, l);
  }

  RtlCoreParser::symbol_type
  RtlCoreParser::make_EQUAL (const location_type& l)
  {
    return symbol_type (token::EQUAL, l);
  }



  // by_state.
  inline
  RtlCoreParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  RtlCoreParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  RtlCoreParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  RtlCoreParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  RtlCoreParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  RtlCoreParser::symbol_number_type
  RtlCoreParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  RtlCoreParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  RtlCoreParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 5: // ID
      case 6: // BINARY_VAL
      case 27: // ModuleDecl
        value.move<  std::string  > (that.value);
        break;

      case 4: // INTEGER
        value.move<  unsigned  > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  RtlCoreParser::stack_symbol_type&
  RtlCoreParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 5: // ID
      case 6: // BINARY_VAL
      case 27: // ModuleDecl
        value.copy<  std::string  > (that.value);
        break;

      case 4: // INTEGER
        value.copy<  unsigned  > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  RtlCoreParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  RtlCoreParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  RtlCoreParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  RtlCoreParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  RtlCoreParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  RtlCoreParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  RtlCoreParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  RtlCoreParser::debug_level_type
  RtlCoreParser::debug_level () const
  {
    return yydebug_;
  }

  void
  RtlCoreParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline RtlCoreParser::state_type
  RtlCoreParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  RtlCoreParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  RtlCoreParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  RtlCoreParser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 5: // ID
      case 6: // BINARY_VAL
      case 27: // ModuleDecl
        yylhs.value.build<  std::string  > ();
        break;

      case 4: // INTEGER
        yylhs.value.build<  unsigned  > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 4:
#line 72 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.CommitModule(yystack_[0].value.as<  std::string  > ()) ; }
#line 853 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 73 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.CommitModule(yystack_[0].value.as<  std::string  > ()) ; }
#line 859 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 77 "rtlcore_parser.yy" // lalr1.cc:859
    { yylhs.value.as<  std::string  > () = yystack_[6].value.as<  std::string  > () ; /* Get Module Name */ }
#line 865 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 79 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.AddPort(yystack_[0].value.as<  std::string  > ()) ; }
#line 871 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 80 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.AddPort(yystack_[0].value.as<  std::string  > ()) ; }
#line 877 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 83 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.CommitStatement() ; }
#line 883 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 84 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.CommitStatement() ; }
#line 889 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 100 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.AddConnect(yystack_[0].value.as<  std::string  > ()) ; }
#line 895 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 101 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.AddConnect(yystack_[0].value.as<  std::string  > ()) ; }
#line 901 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 105 "rtlcore_parser.yy" // lalr1.cc:859
    { driver.UpdateRange() ; }
#line 907 "rtlcore_parser.tab.cc" // lalr1.cc:859
    break;


#line 911 "rtlcore_parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  RtlCoreParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  RtlCoreParser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char RtlCoreParser::yypact_ninf_ = -50;

  const signed char RtlCoreParser::yytable_ninf_ = -1;

  const signed char
  RtlCoreParser::yypact_[] =
  {
       5,   -50,    21,    25,     6,   -50,     4,   -50,   -50,   -50,
      33,   -50,    14,    23,    35,    11,   -50,    36,    -4,    -4,
      -4,    37,    -1,    27,   -50,   -50,    26,    31,   -50,    42,
      32,   -50,    43,    32,    32,    30,   -50,    34,   -50,    47,
      -3,    38,    -4,   -50,    48,   -50,    40,    39,   -50,    -3,
      49,    16,   -50,   -50,    51,   -50,    41,   -50,    52,     9,
      44,   -50,    -3,    45,    46,    12,   -50,    -3,   -50,   -50,
     -50,    56,   -50,    59,    20,   -50,    50,   -50,   -50
  };

  const unsigned char
  RtlCoreParser::yydefact_[] =
  {
       0,     2,     0,     0,     0,     5,     0,     1,     3,     4,
       0,     8,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     0,     0,    15,    14,    24,     0,    20,     0,
      11,    18,     0,    12,    13,     0,     6,     0,    10,     0,
       0,     0,     0,    19,     0,     9,     0,    31,    30,     0,
       0,     0,    28,    27,     0,    17,     0,    23,     0,     0,
       0,    22,     0,     0,     0,     0,    29,     0,    25,    26,
      21,     0,    32,     0,     0,    16,     0,    34,    33
  };

  const signed char
  RtlCoreParser::yypgoto_[] =
  {
     -50,   -50,   -50,    60,   -50,   -50,    53,   -50,    17,    24,
     -50,   -50,   -50,   -49,    -9,    10
  };

  const signed char
  RtlCoreParser::yydefgoto_[] =
  {
      -1,     3,     4,     5,    12,    22,    23,    24,    30,    31,
      32,    25,    27,    51,    52,    53
  };

  const unsigned char
  RtlCoreParser::yytable_[] =
  {
      59,    28,    47,    48,    17,     1,     8,    36,    18,    19,
      20,    21,     2,     2,    49,    29,    17,    10,    74,    50,
      18,    19,    20,    21,    62,     7,     6,    66,    13,    14,
      61,    62,    72,    73,    77,    62,    33,    34,    11,    15,
      16,    26,    35,    38,    40,    39,    41,    42,    43,    44,
      45,    46,    56,    68,    60,    63,    65,    67,    58,    54,
      57,    64,    75,    76,     9,    70,    55,     0,     0,    71,
      78,     0,    69,     0,     0,    37
  };

  const signed char
  RtlCoreParser::yycheck_[] =
  {
      49,     5,     5,     6,     5,     0,     0,     8,     9,    10,
      11,    12,     7,     7,    17,    19,     5,    13,    67,    22,
       9,    10,    11,    12,    15,     0,     5,    18,    14,    15,
      14,    15,    20,    21,    14,    15,    19,    20,     5,    16,
       5,     5,     5,    16,    13,    19,     4,    15,     5,    19,
      16,     4,     4,    62,     5,     4,     4,    13,    19,    21,
      20,    20,     6,     4,     4,    20,    42,    -1,    -1,    23,
      20,    -1,    62,    -1,    -1,    22
  };

  const unsigned char
  RtlCoreParser::yystos_[] =
  {
       0,     0,     7,    25,    26,    27,     5,     0,     0,    27,
      13,     5,    28,    14,    15,    16,     5,     5,     9,    10,
      11,    12,    29,    30,    31,    35,     5,    36,     5,    19,
      32,    33,    34,    32,    32,     5,     8,    30,    16,    19,
      13,     4,    15,     5,    19,    16,     4,     5,     6,    17,
      22,    37,    38,    39,    21,    33,     4,    20,    19,    37,
       5,    14,    15,     4,    20,     4,    18,    13,    38,    39,
      20,    23,    20,    21,    37,     6,     4,    14,    20
  };

  const unsigned char
  RtlCoreParser::yyr1_[] =
  {
       0,    24,    25,    25,    26,    26,    27,    28,    28,    29,
      29,    30,    30,    30,    30,    30,    31,    32,    32,    33,
      33,    34,    35,    36,    36,    37,    37,    37,    37,    38,
      39,    39,    39,    39,    39
  };

  const unsigned char
  RtlCoreParser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     8,     3,     1,     3,
       2,     2,     2,     2,     1,     1,     7,     3,     1,     2,
       1,     5,     5,     4,     1,     3,     3,     1,     1,     3,
       1,     1,     4,     6,     5
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const RtlCoreParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "ERROR", "INTEGER", "ID",
  "BINARY_VAL", "VERI_MODULE", "VERI_ENDMODULE", "VERI_INPUT",
  "VERI_OUTPUT", "VERI_WIRE", "VERI_ASSIGN", "LEFT_PAREN", "RIGHT_PAREN",
  "COMMA", "SEMI_COLON", "LEFT_CURL", "RIGHT_CURL", "LEFT_BRAKET",
  "RIGHT_BRAKET", "COLON", "DOT", "EQUAL", "$accept", "Program",
  "ModuleDeclList", "ModuleDecl", "ModulePorts", "StatementList",
  "Statement", "Assignment", "ConnectList", "Connect", "Range",
  "Instantiation", "InstId", "PortValList", "PortValBus", "PortVal", YY_NULLPTR
  };


  const unsigned char
  RtlCoreParser::yyrline_[] =
  {
       0,    70,    70,    70,    72,    73,    76,    79,    80,    83,
      84,    87,    88,    89,    90,    91,    94,    96,    97,   100,
     101,   104,   107,   109,   110,   113,   114,   115,   116,   119,
     121,   122,   123,   124,   125
  };

  // Print the state stack on the debug stream.
  void
  RtlCoreParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  RtlCoreParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  RtlCoreParser::token_number_type
  RtlCoreParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
    };
    const unsigned int user_token_number_max_ = 278;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "rtlcore_parser.yy" // lalr1.cc:1167
} // ThermPlanner
#line 1285 "rtlcore_parser.tab.cc" // lalr1.cc:1167
#line 129 "rtlcore_parser.yy" // lalr1.cc:1168



void ThermPlanner::RtlCoreParser::error (const location_type &l, const std::string &err_message)
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
