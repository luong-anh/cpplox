#include <gtest/gtest.h>

#include "lexer/lexer.h"

TEST(Lexer, ReturnsEOFWhenFileIsEmpty) {
    EXPECT_EQ(tokenize(""), "EOF  null");
}
