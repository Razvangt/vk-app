
#ifndef SDLLibrary_H
#define SDLLibrary_H
#include <SDL_init.h>
#include "../exception/SDLException.h"
class SDLLibrary
{
   public:
    explicit SDLLibrary(SDL_InitFlags init_flags);
    ~SDLLibrary();
};
#endif  // !SDLLibrary_H
