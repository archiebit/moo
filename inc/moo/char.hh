#ifndef MOO_CHAR_HH
#define MOO_CHAR_HH


namespace moo
{
    using upoint = char32_t;

#if defined _WIN32
    using char08 = char;
    using char16 = wchar_t;
#endif

    using unit08 = char8_t;
    using unit16 = char16_t;
    using unit32 = char32_t;

    enum encoding
    {
        ASCII,
        UTF08, UTF16, UTF32
    };


    template <typename unit>
    inline constexpr encoding native = ASCII;

#if defined _WIN32
    template <>
    inline constexpr encoding native<char08> = ASCII;

    template <>
    inline constexpr encoding native<char16> = UTF16;
#endif

    template <>
    inline constexpr encoding native<unit08> = UTF08;

    template <>
    inline constexpr encoding native<unit16> = UTF16;

    template <>
    inline constexpr encoding native<unit32> = UTF32;
}


#endif