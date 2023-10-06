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


#endif