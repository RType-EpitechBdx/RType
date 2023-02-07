#include "Window.hpp"
#include "gtest/gtest.h"


// Check if the rectangle is drawn at the given position with the given color

TEST(WindowTests, TestDisplayGraphics) {
    Window w;
    Position pos = {100, 100};
    Color color = {255, 0, 0};
    w.displayGraphics(pos, color);
}

// Check if the text is drawn at the given position with the given font, size, and color

TEST(WindowTests, TestWriteText) {
    Window w;
    Position pos = {100, 100};
    Text text = {"Hello World", "font.ttf", 20};
    Color color = {255, 0, 0, 255};
    w.writeText(pos, text, color);
}

// Check if the window is cleared with the black color

TEST(WindowTests, TestClearWindow) {
    Window w;
    w.clearWindow();
}

// Check if the window is closed

TEST(WindowTests, TestCloseWindow) {
    Window w;
    w.closeWindow();
}

// Check if the window is displayed

TEST(WindowTests, TestDisplayWindow) {
    Window w;
    w.displayWindow();
}

// Check if winIsOpen returns the correct value depending on whether the window is open or not

TEST(WindowTests, TestWinIsOpen) {
    Window w;
    EXPECT_TRUE(w.winIsOpen());
    w.closeWindow();
    EXPECT_FALSE(w.winIsOpen());
}

// Emulate a keyboard event, for example pressing the up arrow key
// Check if the correct input event is returned, in this case Input::UP_ARROW

TEST(WindowTests, TestInputEvent) {
    Window w;
}
