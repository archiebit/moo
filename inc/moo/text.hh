#ifndef MOO_TEXT_HH
#define MOO_TEXT_HH

#include <moo\char.hh>
#include <moo\size.hh>


namespace moo::text::symbol
{
    usize size( upoint value, encoding option ) noexcept;



#if defined _WIN32
    usize size( const char08 units[], encoding option ) noexcept;
    usize size( const char16 units[], encoding option ) noexcept;
#endif
    usize size( const unit08 units[], encoding option ) noexcept;
    usize size( const unit16 units[], encoding option ) noexcept;
    usize size( const unit32 units[], encoding option ) noexcept;



#if defined _WIN32
    usize encode( upoint value, char08 units[] ) noexcept;
    usize encode( upoint value, char16 units[] ) noexcept;
#endif
    usize encode( upoint value, unit08 units[] ) noexcept;
    usize encode( upoint value, unit16 units[] ) noexcept;
    usize encode( upoint value, unit32 units[] ) noexcept;



#if defined _WIN32
    usize decode( upoint & value, const char08 units[] ) noexcept;
    usize decode( upoint & value, const char16 units[] ) noexcept;
#endif
    usize decode( upoint & value, const unit08 units[] ) noexcept;
    usize decode( upoint & value, const unit16 units[] ) noexcept;
    usize decode( upoint & value, const unit32 units[] ) noexcept;
}



namespace moo::text::stream
{
#if defined _WIN32
    usize size( const char08 units[], encoding option ) noexcept;
    usize size( const char16 units[], encoding option ) noexcept;
#endif
    usize size( const unit08 units[], encoding option ) noexcept;
    usize size( const unit16 units[], encoding option ) noexcept;
    usize size( const unit32 units[], encoding option ) noexcept;



#if defined _WIN32
    usize size( const char08 units[], encoding option, usize codes ) noexcept;
    usize size( const char16 units[], encoding option, usize codes ) noexcept;
#endif
    usize size( const unit08 units[], encoding option, usize codes ) noexcept;
    usize size( const unit16 units[], encoding option, usize codes ) noexcept;
    usize size( const unit32 units[], encoding option, usize codes ) noexcept;



#if defined _WIN32
    usize leng( const char08 units[], encoding option ) noexcept;
    usize leng( const char16 units[], encoding option ) noexcept;
#endif
    usize leng( const unit08 units[], encoding option ) noexcept;
    usize leng( const unit16 units[], encoding option ) noexcept;
    usize leng( const unit32 units[], encoding option ) noexcept;



#if defined _WIN32
    usize leng( const char08 units[], encoding option, usize size ) noexcept;
    usize leng( const char16 units[], encoding option, usize size ) noexcept;
#endif
    usize leng( const unit08 units[], encoding option, usize size ) noexcept;
    usize leng( const unit16 units[], encoding option, usize size ) noexcept;
    usize leng( const unit32 units[], encoding option, usize size ) noexcept;
}



namespace moo::text::stream
{
#if defined _WIN32
    usize turn( char16 spot[], const char08 from[] ) noexcept;
    usize turn( unit08 spot[], const char08 from[] ) noexcept;
    usize turn( unit16 spot[], const char08 from[] ) noexcept;
    usize turn( unit32 spot[], const char08 from[] ) noexcept;



    usize turn( char08 spot[], const char16 from[] ) noexcept;
    usize turn( unit08 spot[], const char16 from[] ) noexcept;
    usize turn( unit16 spot[], const char16 from[] ) noexcept;
    usize turn( unit32 spot[], const char16 from[] ) noexcept;
#endif



#if defined _WIN32
    usize turn( char08 spot[], const unit08 from[] ) noexcept;
    usize turn( char16 spot[], const unit08 from[] ) noexcept;
#endif
    usize turn( unit16 spot[], const unit08 from[] ) noexcept;
    usize turn( unit32 spot[], const unit08 from[] ) noexcept;



#if defined _WIN32
    usize turn( char08 spot[], const unit16 from[] ) noexcept;
    usize turn( char16 spot[], const unit16 from[] ) noexcept;
#endif
    usize turn( unit08 spot[], const unit16 from[] ) noexcept;
    usize turn( unit32 spot[], const unit16 from[] ) noexcept;



#if defined _WIN32
    usize turn( char08 spot[], const unit32 from[] ) noexcept;
    usize turn( char16 spot[], const unit32 from[] ) noexcept;
#endif
    usize turn( unit08 spot[], const unit32 from[] ) noexcept;
    usize turn( unit16 spot[], const unit32 from[] ) noexcept;



#if defined _WIN32
    usize turn( char16 spot[], const char08 from[], usize codes ) noexcept;
    usize turn( unit08 spot[], const char08 from[], usize codes ) noexcept;
    usize turn( unit16 spot[], const char08 from[], usize codes ) noexcept;
    usize turn( unit32 spot[], const char08 from[], usize codes ) noexcept;



    usize turn( char08 spot[], const char16 from[], usize codes ) noexcept;
    usize turn( unit08 spot[], const char16 from[], usize codes ) noexcept;
    usize turn( unit16 spot[], const char16 from[], usize codes ) noexcept;
    usize turn( unit32 spot[], const char16 from[], usize codes ) noexcept;
#endif



#if defined _WIN32
    usize turn( char08 spot[], const unit08 from[], usize codes ) noexcept;
    usize turn( char16 spot[], const unit08 from[], usize codes ) noexcept;
#endif
    usize turn( unit16 spot[], const unit08 from[], usize codes ) noexcept;
    usize turn( unit32 spot[], const unit08 from[], usize codes ) noexcept;



#if defined _WIN32
    usize turn( char08 spot[], const unit16 from[], usize codes ) noexcept;
    usize turn( char16 spot[], const unit16 from[], usize codes ) noexcept;
#endif
    usize turn( unit08 spot[], const unit16 from[], usize codes ) noexcept;
    usize turn( unit32 spot[], const unit16 from[], usize codes ) noexcept;



#if defined _WIN32
    usize turn( char08 spot[], const unit32 from[], usize codes ) noexcept;
    usize turn( char16 spot[], const unit32 from[], usize codes ) noexcept;
#endif
    usize turn( unit08 spot[], const unit32 from[], usize codes ) noexcept;
    usize turn( unit16 spot[], const unit32 from[], usize codes ) noexcept;
}


#endif