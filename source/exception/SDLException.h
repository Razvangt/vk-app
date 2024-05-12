#ifndef SDLException_H
#define SDLException_H
#include <stdexcept>
class SDLException : private std::runtime_error
{
   private:
    const int code;

   public:
    SDLException(const char *message, const int code = 0);
    [[nodiscard]] auto
    get_code() const noexcept;
};
#endif  // DEBUG
