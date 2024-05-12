#include "SDLException.h"

SDLException::SDLException(const char *message, const int code)
    : runtime_error(message), code{code}
{
}
[[nodiscard]] auto
SDLException::get_code() const noexcept
{
    return code;
}
