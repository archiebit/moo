#ifndef MOO_BYTE_HH
#define MOO_BYTE_HH

#include <moo\size.hh>


namespace moo
{
    enum class byte : unsigned char
    { };


    inline constexpr byte operator | ( byte first, byte other ) noexcept
    {
        return static_cast<byte>( static_cast<unsigned char>( first ) | static_cast<unsigned char>( other ) );
    }
    inline constexpr byte operator & ( byte first, byte other ) noexcept
    {
        return static_cast<byte>( static_cast<unsigned char>( first ) & static_cast<unsigned char>( other ) );
    }
    inline constexpr byte operator ^ ( byte first, byte other ) noexcept
    {
        return static_cast<byte>( static_cast<unsigned char>( first ) ^ static_cast<unsigned char>( other ) );
    }
    inline constexpr byte operator ~ ( byte value ) noexcept
    {
        return static_cast<byte>( ~static_cast<unsigned char>( value ) );
    }

    inline constexpr byte operator << ( byte value, usize bits ) noexcept
    {
        return static_cast<byte>( static_cast<unsigned char>( value ) << bits );
    }
    inline constexpr byte operator >> ( byte value, usize bits ) noexcept
    {
        return static_cast<byte>( static_cast<unsigned char>( value ) >> bits );
    }



    inline constexpr byte & operator |= ( byte & first, byte other ) noexcept
    {
        return first = first | other;
    }
    inline constexpr byte & operator &= ( byte & first, byte other ) noexcept
    {
        return first = first & other;
    }
    inline constexpr byte & operator ^= ( byte & first, byte other ) noexcept
    {
        return first = first ^ other;
    }

    inline constexpr byte & operator <<= ( byte & value, usize bits ) noexcept
    {
        return value = value << bits;
    }
    inline constexpr byte & operator >>= ( byte & value, usize bits ) noexcept
    {
        return value = value >> bits;
    }
}


#endif