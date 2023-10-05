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
}


#endif