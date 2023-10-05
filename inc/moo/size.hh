#ifndef MOO_SIZE_HH
#define MOO_SIZE_HH


namespace moo
{
#if defined _WIN32
    using usize = unsigned long long int;
    using ssize = signed long long int;

    using uintp = unsigned long long int;
    using sintp = signed long long int;
#endif
}


#endif