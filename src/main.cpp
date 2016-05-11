#include "../include/Preprocessor.h"
#include <iostream>



int main(void) {
    SourceFile file("test.c");
    
    std::experimental::optional<std::vector<CPPToken>> result = file.tokenize();
    std::vector<CPPToken> vec = *result;
    if (result) {
            std::cout << "Number of tokens in file is " << result->size();
    } else {
        std::cout << "Tokenization failed\n";
    }

    for (auto token: vec) {
            std::cout << token.raw_val << " is a token!" << std::endl;
    }
    return 0;

}
