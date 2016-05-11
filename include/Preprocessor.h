#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H


#include <string>
#include <list>
#include <experimental/optional>
#include <fstream>
#include <regex>


//Represents the lexemes we care about
//for preprocessing.
enum class CPPLexeme {
    OPENCURLY,
    CLOSECURLY,
    NEWLINE,
    WHITESPACE,
    IDENTIFIER,
    PLUS,
    MINUS,
    ASTERISK,
    STRINGLITERAL,
    BACKSLASH,
    INTEGERLITERAL,
    OPENPAREN,
    CLOSEPAREN,
    SEMICOLON,
    EQUALS,
    ASSIGNMENT,
    COMMA,
    FOWARDSLASH,
    DEFINE,
    INCLUDE,
    POUND,
    HEADERNAME,
    LESSTHAN,
    GREATERTHAN
    
};

struct CPPToken {
	std::string raw_val;
	CPPLexeme lex_val;
};

class SourceFile {
private:
        bool is_pp_dir_line;
        bool lexed_include_directive;
        size_t position;
        size_t size;
        std::string raw_val;
        std::experimental::optional<CPPToken> get_next_token();
        std::experimental::optional<CPPToken> get_regex_tok(const std::regex& reg);
        std::experimental::optional<CPPToken> get_whitespace_tok();
public:
	SourceFile(const std::string &file_name);
        std::experimental::optional<std::vector<CPPToken>> tokenize();
};

#endif
