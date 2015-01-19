#include <iostream>
#include <boost/mpl/int.hpp>

/**
 * @brief static computation of factorial (compilation time)
 * @return the factorial of X
 */
template<int X>
int factorial()
{
    using namespace boost::mpl;

    return X * factorial< int_<X>::prior::value >();
}

/**
 * @brief specialization for factorial<1>()
 * @return 1
 */
template<>
int factorial<1>()
{
    return 1;
}

int main(int argc, char** argv)
{
    std::cout << "Statically computed value of factorial<8> is:" << factorial<8>() << std::endl;
    return 0;
}

