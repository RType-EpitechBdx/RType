#pragma once

#include <string>

/**
 * @brief struct Text to define a text, a size and a font
 * @param[text] -> string text
 * @param[size] -> text size
 * @param[font] -> text font
 */

struct Text {
    std::string text;
    std::string font;
    int size;
};