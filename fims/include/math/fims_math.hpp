/*
 * File:   fims_math.hpp
 *
 * Author: Matthew Supernaw
 * National Oceanic and Atmospheric Administration
 * National Marine Fisheries Service
 * Sustainable Fisheries Division
 * Email: matthew.supernaw@noaa.gov
 *
 * Created on September 30, 2021, 1:43 PM
 *
 * This File is part of the NOAA, National Marine Fisheries Service
 * Fisheries Integrated Modeling System project.
 *
 * This software is a "United States Government Work" under the terms of the
 * United States Copyright Act.  It was written as part of the author's official
 * duties as a United States Government employee and thus cannot be copyrighted.
 * This software is freely available to the public for use. The National Oceanic
 * And Atmospheric Administration and the U.S. Government have not placed any
 * restriction on its use or reproduction.  Although all reasonable efforts have
 * been taken to ensure the accuracy and reliability of the software and data,
 * the National Oceanic And Atmospheric Administration and the U.S. Government
 * do not and cannot warrant the performance or results that may be obtained by
 * using this  software or data. The National Oceanic And Atmospheric
 * Administration and the U.S. Government disclaim all warranties, express or
 * implied, including warranties of performance, merchantability or fitness
 * for any particular purpose.
 *
 * Please cite the author(s) in any work or product based on this material.
 *
 */
#ifndef FIMS_MATH_HPP
#define FIMS_MATH_HPP

//note: this is modeling platform specific, must be controlled by 
//preprocessing macros
#include "../def/def.hpp"
#include <cmath>

namespace fims {

    
#ifdef USE_STANDARD_LIB
    
    
    
    template <class T>
    inline const T exp(const T& x) {
        return std::exp(x);
    }

    template <class T>
    inline const T log(const T& x) {
        return std::log(x);
    }

    template <class T>
    inline const T logistic(const T& mean, const T& slope, const T& x) {
        return (1.0) / (1.0 + exp(-1.0 * (x - mean) / slope));
    }

    
    
#endif

    namespace cstar{//common stock assessment routines
        
        
        
    }
    
}


#endif /* FIMS_MATH_HPP */

