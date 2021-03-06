///////////////////////////////////////////////////////////////////////////////
/// \file impl.hpp
/// Contains definition of transform<> and transform_impl<> helpers.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROTO_TRANSFORM_IMPL_HPP_EAN_04_03_2008
#define BOOST_PROTO_TRANSFORM_IMPL_HPP_EAN_04_03_2008

#include <boost/proto/detail/prefix.hpp>
#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/detail/suffix.hpp>

namespace boost { namespace proto
{
    template<typename PrimitiveTransform, typename Expr, typename State = int, typename Data = int>
    struct apply_transform
      : PrimitiveTransform::template impl<Expr, State, Data>
    {};

    struct transform_base
    {
        BOOST_PROTO_CALLABLE()
        BOOST_PROTO_TRANSFORM()
    };

    struct empty_base
    {};

    template<
        typename PrimitiveTransform
      , typename Base BOOST_PROTO_WHEN_BUILDING_DOCS(= transform_base)
    >
    struct transform : Base
    {
        typedef PrimitiveTransform transform_type;

        template<typename Sig>
        struct result;

        template<typename This, typename Expr>
        struct result<This(Expr)>
        {
            typedef typename PrimitiveTransform::template impl<Expr, int, int>::result_type type;
        };

        template<typename This, typename Expr, typename State>
        struct result<This(Expr, State)>
        {
            typedef typename PrimitiveTransform::template impl<Expr, State, int>::result_type type;
        };

        template<typename This, typename Expr, typename State, typename Data>
        struct result<This(Expr, State, Data)>
        {
            typedef typename PrimitiveTransform::template impl<Expr, State, Data>::result_type type;
        };

        template<typename Expr>
        typename apply_transform<PrimitiveTransform, Expr &>::result_type
        operator ()(Expr &e) const
        {
            int i = 0;
            return apply_transform<PrimitiveTransform, Expr &>()(e, i, i);
        }

        template<typename Expr, typename State>
        typename apply_transform<PrimitiveTransform, Expr &, State &>::result_type
        operator ()(Expr &e, State &s) const
        {
            int i = 0;
            return apply_transform<PrimitiveTransform, Expr &, State &>()(e, s, i);
        }

        template<typename Expr, typename State>
        typename apply_transform<PrimitiveTransform, Expr &, State const &>::result_type
        operator ()(Expr &e, State const &s) const
        {
            int i = 0;
            return apply_transform<PrimitiveTransform, Expr &, State const &>()(e, s, i);
        }

        template<typename Expr, typename State, typename Data>
        typename apply_transform<PrimitiveTransform, Expr &, State &, Data &>::result_type
        operator ()(Expr &e, State &s, Data &d) const
        {
            return apply_transform<PrimitiveTransform, Expr &, State &, Data &>()(e, s, d);
        }

        template<typename Expr, typename State, typename Data>
        typename apply_transform<PrimitiveTransform, Expr &, State const &, Data &>::result_type
        operator ()(Expr &e, State const &s, Data &d) const
        {
            return apply_transform<PrimitiveTransform, Expr &, State const &, Data &>()(e, s, d);
        }
    };

    template<typename Expr, typename State, typename Data>
    struct transform_impl
    {
        typedef Expr const expr;
        typedef Expr const &expr_param;
        typedef State const state;
        typedef State const &state_param;
        typedef Data const data;
        typedef Data const &data_param;
    };

    template<typename Expr, typename State, typename Data>
    struct transform_impl<Expr &, State, Data>
    {
        typedef Expr expr;
        typedef Expr &expr_param;
        typedef State const state;
        typedef State const &state_param;
        typedef Data const data;
        typedef Data const &data_param;
    };

    template<typename Expr, typename State, typename Data>
    struct transform_impl<Expr, State &, Data>
    {
        typedef Expr const expr;
        typedef Expr const &expr_param;
        typedef State state;
        typedef State &state_param;
        typedef Data const data;
        typedef Data const &data_param;
    };

    template<typename Expr, typename State, typename Data>
    struct transform_impl<Expr, State, Data &>
    {
        typedef Expr const expr;
        typedef Expr const &expr_param;
        typedef State const state;
        typedef State const &state_param;
        typedef Data data;
        typedef Data &data_param;
    };

    template<typename Expr, typename State, typename Data>
    struct transform_impl<Expr &, State &, Data>
    {
        typedef Expr expr;
        typedef Expr &expr_param;
        typedef State state;
        typedef State &state_param;
        typedef Data const data;
        typedef Data const &data_param;
    };

    template<typename Expr, typename State, typename Data>
    struct transform_impl<Expr &, State, Data &>
    {
        typedef Expr expr;
        typedef Expr &expr_param;
        typedef State const state;
        typedef State const &state_param;
        typedef Data data;
        typedef Data &data_param;
    };

    template<typename Expr, typename State, typename Data>
    struct transform_impl<Expr, State &, Data &>
    {
        typedef Expr const expr;
        typedef Expr const &expr_param;
        typedef State state;
        typedef State &state_param;
        typedef Data data;
        typedef Data &data_param;
    };

    template<typename Expr, typename State, typename Data>
    struct transform_impl<Expr &, State &, Data &>
    {
        typedef Expr expr;
        typedef Expr &expr_param;
        typedef State state;
        typedef State &state_param;
        typedef Data data;
        typedef Data &data_param;
    };

}} // namespace boost::proto

#endif
