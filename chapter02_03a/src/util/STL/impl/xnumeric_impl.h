///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2014.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _XNUMERIC_IMPL_2010_02_23_H_
  #define _XNUMERIC_IMPL_2010_02_23_H_

  // Implement helper functions for some of <numeric>.

  #include "xiterator_impl.h"

  namespace xnumeric
  {
    template<typename input_iterator,
             typename value_type>
    inline value_type xaccumulate(input_iterator first, input_iterator last, value_type val)
    {
      // Compute the sum of the elements in the range [first, last).
      // Initialize the sum with val.
      while(first != last)
      {
        val += *first;
        ++first;
      }

      return val;
    }

    template<typename input_iterator,
             typename value_type,
             typename function_type>
    inline value_type xaccumulate(input_iterator first, input_iterator last, value_type val, function_type binary_function)
    {
      // Compute the sum of the elements in the range [first, last)
      // using binary_function. Initialize the sum with val.
      while(first != last)
      {
        val = binary_function(val, *first);

        ++first;
      }

      return val;
    }

    template<typename input_iterator1,
             typename input_iterator2,
             typename value_type>
    inline value_type xinner_product(input_iterator1 first1, input_iterator1 last1, input_iterator2 first2, value_type val)
    {
      // Compute the inner product of the elements in the ranges [first1, last1)
      // and [first2, last2). Initialize the sum with val.
      while(first1 != last1)
      {
        val += ((*first1) * (*first2));

        ++first1;
        ++first2;
      }

      return val;
    }

    template<typename input_iterator,
             typename output_iterator>
    output_iterator xpartial_sum(input_iterator first, input_iterator last, output_iterator result)
    {
      // Compute the partial sum of the elements in the range [first1, last1)
      // and store the result in result.
      if(first == last)
      {
      }
      else
      {
        typedef typename xiterator::xiterator_traits<input_iterator>::value_type sum_type;

        sum_type sum = *first;
        ++first;

        *result = sum;
        ++result;

        while(first != last)
        {
          sum += (*first);
          ++first;

          *result = sum;
          ++result;
        }
      }

      return result;
    }

    template<typename input_iterator,
             typename output_iterator,
             typename function_type>
    output_iterator xpartial_sum(input_iterator first, input_iterator last, output_iterator result, function_type binary_function)
    {
      // Compute the partial sum of the elements in the range [first1, last1)
      // using binary_function and store the result in result.
      if(first == last)
      {
      }
      else
      {
        typedef typename xiterator::xiterator_traits<input_iterator>::value_type sum_type;

        sum_type sum = *first;
        ++first;

        *result = sum;
        ++result;

        while(first != last)
        {
          sum = binary_function(sum, *first);
          ++first;

          *result = sum;
          ++result;
        }
      }

      return result;
    }
  }

#endif // _XNUMERIC_IMPL_2010_02_23_H_
