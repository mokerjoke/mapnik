/*****************************************************************************
 *
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2012 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

#ifndef MAPNIK_FEATURESET_HPP
#define MAPNIK_FEATURESET_HPP

// mapnik
#include <mapnik/config.hpp>
#include <mapnik/noncopyable.hpp>

// boost
#include <boost/shared_ptr.hpp>

namespace mapnik {

class feature_impl;
typedef boost::shared_ptr<feature_impl> feature_ptr;

struct MAPNIK_DECL Featureset : private mapnik::noncopyable
{
    virtual feature_ptr next() = 0;
    virtual ~Featureset() {}
};

typedef MAPNIK_DECL boost::shared_ptr<Featureset> featureset_ptr;

}

#endif // MAPNIK_FEATURESET_HPP
