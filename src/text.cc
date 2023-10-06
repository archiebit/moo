#include <moo\text.hh>
#include <moo\type.hh>


namespace moo::text::symbol
{
    usize size( upoint value, encoding option ) noexcept
    {
        switch( option )
        {
            case ASCII:
                if( value <= 0x0000'007F ) return 1;
                else                       return 0;

            case UTF08:
                if( value <= 0x0000'007F ) return 1;
                if( value <= 0x0000'07FF ) return 2;
                if( value <= 0x0000'D7FF ) return 3;
                if( value <= 0x0000'DFFF ) return 0;
                if( value <= 0x0000'FFFF ) return 3;
                if( value <= 0x0010'FFFF ) return 4;
                else                       return 0;

            case UTF16:
                if( value <= 0x0000'D7FF ) return 1;
                if( value <= 0x0000'DFFF ) return 0;
                if( value <= 0x0000'FFFF ) return 1;
                if( value <= 0x0010'FFFF ) return 2;
                else                       return 0;

            case UTF32:
                if( value <= 0x0000'D7FF ) return 1;
                if( value <= 0x0000'DFFF ) return 0;
                if( value <= 0x0010'FFFF ) return 2;
                else                       return 0;
        }

        return 0;
    }



#if defined _WIN32
    usize size( const char08 units[], encoding option ) noexcept
    {
        if( not units ) return 0;

        switch( option )
        {
            case ASCII: return units[ 0 ] <= 0x7F;
            case UTF08: return units[ 0 ] <= 0x7F;
            case UTF16: return units[ 0 ] <= 0x7F;
            case UTF32: return units[ 0 ] <= 0x7F;
        }

        return 0;
    }
    
    usize size( const char16 units[], encoding option ) noexcept
    {
        if( not units ) return 0;

        boole fail = false;
        boole dual = false;

        {
            boole x = false;
            boole y = false;

            ( x = ( units[ 0 ] bitand 0xFC00 ) == 0xD800 )
            and
            ( y = ( units[ 1 ] bitand 0xFC00 ) == 0xDC00 );

            fail = x + y == 1;
            dual = x + y == 2;
        }

        if( not fail ) switch( option )
        {
            case ASCII:
                if( units[ 0 ] <= 0x007F ) return 1;
                else                       return 0;

            case UTF08:
                if( units[ 0 ] <= 0x007F ) return 1;
                if( units[ 0 ] <= 0x07FF ) return 2;
                else                       return 3 + dual;

            case UTF16:                    return 1 + dual;
            case UTF32:                    return 1;
        }

        return 0;
    }
#endif
    usize size( const unit08 units[], encoding option ) noexcept
    {
        if( not units ) return 0;

        usize size = 0;

        {
            usize index = 8;
            usize value = units[ 0 ];

            while( value bitand ( 1 << --index ) );

            if( index == 6 or index < 3 )
            {
                size = 0;
            }
            else size = index == 7 ? 1 : 7 - index;

            for( index = 1; index < size; ++index )
            {
                value = units[ index ] bitand 0xC0;

                if( value != 0x80 )
                {
                    size = 0;
                }
            }
        }

        if( size != 0 ) switch( option )
        {
            case ASCII: return size == 1;
            case UTF08: return size;
            case UTF16: return size == 4 ? 2 : 1;
            case UTF32: return 1;
        }

        return 0;
    }
    
    usize size( const unit16 units[], encoding option ) noexcept
    {
        if( not units ) return 0;

        boole fail = false;
        boole dual = false;

        {
            boole x = false;
            boole y = false;

            ( x = ( units[ 0 ] bitand 0xFC00 ) == 0xD800 )
            and
            ( y = ( units[ 1 ] bitand 0xFC00 ) == 0xDC00 );

            fail = x + y == 1;
            dual = x + y == 2;
        }

        if( not fail ) switch( option )
        {
            case ASCII:
                if( units[ 0 ] <= 0x007F ) return 1;
                else                       return 0;

            case UTF08:
                if( units[ 0 ] <= 0x007F ) return 1;
                if( units[ 0 ] <= 0x07FF ) return 2;
                else                       return 3 + dual;

            case UTF16:                    return 1 + dual;
            case UTF32:                    return 1;
        }

        return 0;
    }
    
    usize size( const unit32 units[], encoding option ) noexcept
    {
        if( not units ) return 0;

        return size( units[ 0 ], option );
    }



#if defined _WIN32
    usize encode( upoint value, char08 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( value, ASCII );

        if( size == 1 )
        {
            units[ 0 ] = value;
        }

        return size;
    }

    usize encode( upoint value, char16 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( value, UTF16 );

        if( size == 1 )
        {
            units[ 0 ] = value;
        }

        if( size == 2 )
        {
            value -= 65'536;

            char16 x = ( value bitand 0x000F'FC00 ) >> 10;
            char16 y = ( value bitand 0x0000'03FF );

            units[ 0 ] = x bitor 0xD800;
            units[ 1 ] = y bitor 0xDC00;
        }

        return size;
    }
#endif

    usize encode( upoint value, unit08 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( value, UTF08 );

        switch( size )
        {
            case 1:
                units[ 0 ] = ( ( value bitand 0x0000'007F ) >>  0 ) bitor 0x00;
            break;

            case 2:
                units[ 0 ] = ( ( value bitand 0x0000'07C0 ) >>  6 ) bitor 0xC0;
                units[ 1 ] = ( ( value bitand 0x0000'003F ) >>  0 ) bitor 0x80;
            break;

            case 3:
                units[ 0 ] = ( ( value bitand 0x0000'F000 ) >> 12 ) bitor 0xE0;
                units[ 1 ] = ( ( value bitand 0x0000'0FC0 ) >>  6 ) bitor 0x80;
                units[ 2 ] = ( ( value bitand 0x0000'003F ) >>  0 ) bitor 0x80;
            break;

            case 4:
                units[ 0 ] = ( ( value bitand 0x001C'0000 ) >> 18 ) bitor 0xF0;
                units[ 1 ] = ( ( value bitand 0x0003'F000 ) >> 12 ) bitor 0x80;
                units[ 2 ] = ( ( value bitand 0x0000'0FC0 ) >>  6 ) bitor 0x80;
                units[ 3 ] = ( ( value bitand 0x0000'003F ) >>  0 ) bitor 0x80;
            break;
        }

        return size;
    }

    usize encode( upoint value, unit16 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( value, UTF16 );

        if( size == 1 )
        {
            units[ 0 ] = value;
        }

        if( size == 2 )
        {
            value -= 65'536;

            unit16 x = ( value bitand 0x000F'FC00 ) >> 10;
            unit16 y = ( value bitand 0x0000'03FF );

            units[ 0 ] = x bitor 0xD800;
            units[ 1 ] = y bitor 0xDC00;
        }

        return size;
    }

    usize encode( upoint value, unit32 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( value, UTF32 );

        if( size == 1 )
        {
            units[ 0 ] = value;
        }

        return size;
    }



#if defined _WIN32
    usize decode( upoint & value, const char08 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( units, ASCII );

        if( size == 1 )
        {
            value = units[ 0 ];
        }

        return size;
    }

    usize decode( upoint & value, const char16 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( units, UTF16 );

        if( size == 1 )
        {
            value = units[ 0 ];
        }
        
        if( size == 2 )
        {
            char16 x = units[ 0 ] bitand 0x03FF;
            char16 y = units[ 1 ] bitand 0x03FF;

            value = ( x << 10 ) + y + 65'536;
        }

        return size;
    }
#endif
    usize decode( upoint & value, const unit08 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( units, UTF16 );

        switch( size )
        {
            case 1:
                value  = ( units[ 0 ] bitand 0x7F ) <<  0;
            break;

            case 2:
                value  = ( units[ 0 ] bitand 0x1F ) <<  6;
                value += ( units[ 1 ] bitand 0x3F ) <<  0;
            break;

            case 3:
                value  = ( units[ 0 ] bitand 0x0F ) << 12;
                value += ( units[ 1 ] bitand 0x3F ) <<  6;
                value += ( units[ 2 ] bitand 0x3F ) <<  0;
            break;

            case 4:
                value  = ( units[ 0 ] bitand 0x07 ) << 18;
                value += ( units[ 1 ] bitand 0x3F ) << 12;
                value += ( units[ 2 ] bitand 0x3F ) <<  6;
                value += ( units[ 3 ] bitand 0x3F ) <<  0;
            break;
        }

        return size;
    }

    usize decode( upoint & value, const unit16 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( units, UTF16 );

        if( size == 1 )
        {
            value = units[ 0 ];
        }
        
        if( size == 2 )
        {
            unit16 x = units[ 0 ] bitand 0x03FF;
            unit16 y = units[ 1 ] bitand 0x03FF;

            value = ( x << 10 ) + y + 65'536;
        }

        return size;
    }

    usize decode( upoint & value, const unit32 units[] ) noexcept
    {
        if( not units ) return 0;

        usize size = symbol::size( units, UTF32 );

        if( size == 1 )
        {
            value = units[ 0 ];
        }

        return size;
    }
}