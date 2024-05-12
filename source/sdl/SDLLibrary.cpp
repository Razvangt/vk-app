#include "SDLLibrary.h"
SDLLibrary::SDLLibrary(SDL_InitFlags init_flags)
{
    if (const int error_code = SDL_Init(init_flags)) {
        throw SDLException{SDL_GetError(), error_code};
    }
}
SDLLibrary::~SDLLibrary()
{
    SDL_Quit();
}
