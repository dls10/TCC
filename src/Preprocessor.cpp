//TODO Need to look over cases. Resolve newline differences
//TODO Finish up the tokenization cases. Also check to make sure
//TODO that context is reset after parsing header name.

#include "../include/Preprocessor.h"

#include <sstream>
#include <iostream>


const std::regex identifier("[_a-zA-Z]([_a-zA-Z0-9])*");
const std::regex string_literal("\"([^\"])*\"");
const std::regex integer_literal("([0-9])*");
const std::regex default_header("<([^<])*>");
const std::regex string_header("\"([^\"])*\"");

SourceFile::SourceFile(const std::string &file_name):
        is_pp_dir_line(false),
        lexed_include_directive(false),
        position(0)
{

	std::ifstream source(file_name);
        if (source.fail()) {
            throw std::runtime_error ("Could not open source file.\n");
        }
	std::stringstream rawBuffer;
	rawBuffer << source.rdbuf();
	raw_val = rawBuffer.str();
	size = raw_val.size();

}


std::experimental::optional<CPPToken> 
SourceFile::get_regex_tok(const std::regex &reg)
{
        CPPToken cur_tok;
        std::experimental::optional<CPPToken> result;
        std::cmatch potenital_match;
        const size_t rangeBegin = this->position;
        const char* start = this->raw_val.c_str() + rangeBegin;
        
        if (std::regex_search(start, potenital_match, reg)) {
            auto size_of_match = potenital_match[0].length();
            auto match = potenital_match[0].str();

            if (raw_val.find(match.c_str(), rangeBegin, size_of_match) == rangeBegin) {
                cur_tok = {match, CPPLexeme::STRINGLITERAL};
                result = cur_tok;
                return result;
            }

        }
        
        return result;

}

std::experimental::optional<std::vector<CPPToken>>
SourceFile::tokenize()
{
    

    std::experimental::optional<std::vector<CPPToken>> potential_result;
    std::vector<CPPToken> tokens;
    std::experimental::optional<CPPToken> potential_token;

    CPPToken curTok;
    //Main method for our SourceFile class.
    
    std::cout << "Size of file is " << this->size << std::endl;

    while(position < size) {
        
        std::cout << "Position is now " << this->position << std::endl;
        std::cout << "Character at position is: " 
                << this->raw_val[this->position] << std::endl;
        
        potential_token = this->get_next_token();

        if (potential_token) {
            curTok = *potential_token;
            this->position = this->position + curTok.raw_val.size();
            tokens.push_back(curTok);
        } else {
            return potential_result;
        }
    }

    potential_result = tokens;

    return potential_result;
    

}


std::experimental::optional<CPPToken>
SourceFile::get_whitespace_tok() {
	size_t temp_pos = this->position;
        std::string &string_source = this->raw_val;
        std::experimental::optional<CPPToken> result;
        CPPToken curTok;

	while (string_source[temp_pos] == ' ' 
                || string_source[temp_pos] == '\t' ) { 
                temp_pos++; 
        }

        if (temp_pos == this->position) return result;
        
        std::string white_space_str (temp_pos - (this->position), ' ');

        curTok = {white_space_str, CPPLexeme::WHITESPACE};
        
        result = std::experimental::make_optional(curTok);

        return result;
}


/*
 *  Requires:
 *  	We need the source file object to still have characters left
 *      to tokeneize. 
 *  Effects:
 *  	Procures the next token at the given index this current
 *  	source file object holds. If there is a failure,
 *     
 */
std::experimental::optional<CPPToken>
SourceFile::get_next_token() {

	CPPToken curTok;
	std::experimental::optional<CPPToken> potential_token;
	std::experimental::optional<CPPToken> result;
	int cur_pos = this->position;
	int size = this->size;

	//static_assert(cur_pos < size, "No more tokens in SourceFile");

	//Lets see if we can spot one character tokens that are siginicant 
        //in there own right like punctuators.
	switch(this->raw_val[cur_pos])
	{
                case '=':
                        curTok = {"=", CPPLexeme::ASSIGNMENT};
                        result = curTok;
                        return result;
		case '+':
			curTok = {"+", CPPLexeme::PLUS};
			result = curTok;
			return result;
		case '-':
			curTok = {"-", CPPLexeme::MINUS};
			result = curTok;
			return result;		
		case '*':
			curTok = {"*", CPPLexeme::ASTERISK};
			result = curTok;
			return result;
		case '/':
			curTok = {"/", CPPLexeme::FOWARDSLASH};
			result = curTok;
			return result;
		case '\\':
			curTok = {"\\", CPPLexeme::BACKSLASH};
			result = curTok;
			return result;	
		case '\n':
			curTok = {"\n", CPPLexeme::NEWLINE};
			result = curTok;
                        this->is_pp_dir_line = false;
                        this->lexed_include_directive = false;
			return result;
		case '"':
                         if (this->lexed_include_directive) {
                               //Lets parse this as a preprocessing header.
                               potential_token = this->get_regex_tok(string_header);
                               if (potential_token) {
                                        curTok = *potential_token;
                                        result = curTok;
                                        return result;
                               } else {
                                        return result;
                               }

                        }
			potential_token = this->get_regex_tok(string_literal);
			if (potential_token) {
				curTok = *potential_token;
				result = curTok;
				return result;
			} else {
				return result;
			}
		case '{':
			curTok = {"{", CPPLexeme::OPENCURLY};
			result = curTok;
			return result;
		case '}':
			curTok = {"}", CPPLexeme::CLOSECURLY};
			result = curTok;
			return result;
		case '(':
			curTok = {"(", CPPLexeme::OPENPAREN};
			result = curTok;
			return result;
		case ')':
			curTok = {")", CPPLexeme::CLOSEPAREN};
			result = curTok;
			return result;
		case '#':
			//Handle preprocessing directive
			if (cur_pos == 0 || this->raw_val[cur_pos - 1] == '\n'){
				this->is_pp_dir_line = true;
			}
			curTok = {"#", CPPLexeme::POUND};
			result = curTok;
			return result;
		case ' ':
			//Handle Whitespace
			potential_token = this->get_whitespace_tok();
			if (potential_token) {
				curTok = *potential_token;
				result = curTok;
				return result;
			} else {
				return result;
			}
		case '\t':
			//Handle Whitespace
			potential_token = this->get_whitespace_tok();
			if (potential_token) {
				curTok = *potential_token;
				result = curTok;
				return result;
			} else {
				return result;
			}
		case '\r':
			//Newline case
                        if (cur_pos != size && this->raw_val[cur_pos + 1] == '\n') {
			    curTok = {"\r\n", CPPLexeme::NEWLINE};
			    result = curTok;
                            this->is_pp_dir_line = false;
                            this->lexed_include_directive = false;
		    	    return result;
                        }
                        return result;
		case '<':
			//Tricky case. How we parse this depends on context.
                        if (this->lexed_include_directive) {
                               //Lets parse this as a preprocessing header.
                               potential_token = this->get_regex_tok(default_header);
                               if (potential_token) {
                                        curTok = *potential_token;
                                        result = curTok;
                                        return result;
                               } else {
                                        return result;
                               }

                        }
                        //We can simply return a '<' punctuator token
                        curTok = {"<", CPPLexeme::LESSTHAN};
                        result = curTok;
                        return result;
                case '>':
                        curTok = {">", CPPLexeme::GREATERTHAN};
                        result = curTok;
                        return result;

                case ';':
                        curTok = {";", CPPLexeme::SEMICOLON};
                        result = curTok;
                        return result;

	}


	//If we get here, we know that this next token is either invalid,
	//a integer literal, or an identifier

	potential_token = this->get_regex_tok(identifier);

	if (potential_token) {
		if (potential_token->raw_val == "include" && this->is_pp_dir_line) {
			this->lexed_include_directive = true;
		}
                curTok = *potential_token;
                result = curTok;
                return result;
	}


        //Identifier parse failed. Try integer literal parse.
        potential_token = this->get_regex_tok(integer_literal);

	if (potential_token) {
                curTok = *potential_token;
                result = curTok;
                return result;
	}

        return result;



}
