/*****************************************************************************
 * 
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2011 Artem Pavlenko
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

#ifndef MAPNIK_MEMORY_DATASOURCE_HPP
#define MAPNIK_MEMORY_DATASOURCE_HPP

// mapnik
#include <mapnik/datasource.hpp>
#include <mapnik/feature_layer_desc.hpp>

// boost
#include <boost/optional.hpp>

// stl
#include <vector>
#include <set>

namespace mapnik {
    
class MAPNIK_DECL memory_datasource : public datasource
{
    friend class memory_featureset;
    friend class memory_featureset2;
public:
    memory_datasource();
    virtual ~memory_datasource();
    void push(feature_ptr feature);
    void calculate_extent();
    int type() const;
    featureset_ptr features(const query& q) const;
    featureset_ptr features(const std::set<std::string>& names) const;
    featureset_ptr features_at_point(coord2d const& pt) const;
    boost::optional<box2d<double> > envelope() const;
    layer_descriptor get_descriptor() const;
    size_t size() const;
private:
    bool extent_initialized_;
    boost::optional<box2d<double> > extent_;
    std::vector<feature_ptr> features_;
    mapnik::layer_descriptor desc_;
}; 
   
// This class implements a simple way of displaying point-based data
// TODO -- possible redesign, move into separate file
//
   
class MAPNIK_DECL point_datasource : public memory_datasource {
public:
    point_datasource() :
        feature_id_(1) {}
    void add_point(double x, double y, const char* key, const char* value);  
    inline int type() const { return datasource::Vector; }
      
private:
    int feature_id_;
};   
}

#endif // MAPNIK_MEMORY_DATASOURCE_HPP
