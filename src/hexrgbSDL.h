#ifndef HEXRGBSDL_H
#define HEXRGBSDL_H

#include <SDL2/SDL.h>
#include <string>
#include <sstream>

//SDL edition 🥹✌️
// convetrt my beloved # color codes into disgusting rgb confusing disgusting2 color code yuck
inline SDL_Color fixColors(const std::string& hex) {
    SDL_Color color = {0, 0, 0, 255}; // default

    if (hex.empty() || hex[0] != '#') return color; //not real

    std::string h = hex.substr(1);
    unsigned int r = 0, g = 0, b = 0, a = 255;

    if (h.size() == 3) { // #RGB
        std::istringstream(std::string(2, h[0])) >> std::hex >> r;
        std::istringstream(std::string(2, h[1])) >> std::hex >> g;
        std::istringstream(std::string(2, h[2])) >> std::hex >> b;
    } 
    else if (h.size() == 4) { // #RGBA
        std::istringstream(std::string(2, h[0])) >> std::hex >> r;
        std::istringstream(std::string(2, h[1])) >> std::hex >> g;
        std::istringstream(std::string(2, h[2])) >> std::hex >> b;
        std::istringstream(std::string(2, h[3])) >> std::hex >> a;
    } 
    else if (h.size() == 6) { // #RRGGBB
        std::istringstream(h.substr(0,2)) >> std::hex >> r;
        std::istringstream(h.substr(2,2)) >> std::hex >> g;
        std::istringstream(h.substr(4,2)) >> std::hex >> b;
    } 
    else if (h.size() == 8) { // #RRGGBBAA
        std::istringstream(h.substr(0,2)) >> std::hex >> r;
        std::istringstream(h.substr(2,2)) >> std::hex >> g;
        std::istringstream(h.substr(4,2)) >> std::hex >> b;
        std::istringstream(h.substr(6,2)) >> std::hex >> a;
    } 
    else return color; //not real

    color.r = static_cast<Uint8>(r);
    color.g = static_cast<Uint8>(g);
    color.b = static_cast<Uint8>(b);
    color.a = static_cast<Uint8>(a);

    return color;
}

#endif
