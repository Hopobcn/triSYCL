#ifndef TRISYCL_SYCL_RANGE_HPP
#define TRISYCL_SYCL_RANGE_HPP

/** \file The OpenCL SYCL range<>

    Ronan at Keryell point FR

    This file is distributed under the University of Illinois Open Source
    License. See LICENSE.TXT for details.
*/

#include "CL/sycl/detail/small_array.hpp"

namespace cl {
namespace sycl {

/** \addtogroup parallelism Expressing parallelism through kernels
    @{
*/

/** A SYCL range defines a multi-dimensional index range that can be used
    to define launch parallel computation extent or buffer sizes.

    \todo use std::size_t dims instead of int dims in the specification?

    \todo add to the specification this default parameter value?

    \todo add to the specification some way to specify an offset?
*/
template <std::size_t dims = 1>
struct range : public detail::small_array_123<std::size_t, range<dims>, dims> {
  // Inherit of all the constructors
  using detail::small_array_123<std::size_t,
                                range<dims>,
                                dims>::small_array_123;
};


/** Implement a make_range to construct a range<> of the right dimension
    with implicit conversion from an initializer list for example.

    Cannot use a template on the number of dimensions because the implicit
    conversion would not be tried.
*/
auto make_range(range<1> r) { return r; }
auto make_range(range<2> r) { return r; }
auto make_range(range<3> r) { return r; }


/** Construct a range<> from a function call with arguments, like
    make_range(1, 2, 3)
*/
template<typename... BasicType>
auto make_range(BasicType... Args) {
  return range<sizeof...(Args)>(Args...);
}

/// @} End the parallelism Doxygen group

}
}

/*
    # Some Emacs stuff:
    ### Local Variables:
    ### ispell-local-dictionary: "american"
    ### eval: (flyspell-prog-mode)
    ### End:
*/

#endif // TRISYCL_SYCL_RANGE_HPP
