/*
 * File:   von_bertalanffy.hpp
 *
 * Author: Matthew Supernaw
 * National Oceanic and Atmospheric Administration
 * National Marine Fisheries Service
 * Sustainable Fisheries Division
 * Email: matthew.supernaw@noaa.gov
 *
 * Created on September 30, 2021, 12:54 PM
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
#ifndef VON_BERTALANFFY_HPP
#define VON_BERTALANFFY_HPP

#include "growth_base.hpp"

namespace fims {

    template<typename T>
    struct VonBertalanffy : public GrowthBase<T> {
        T l_inf_;
        T k_;
        T a_min_;
        
        VonBertalanffy():GrowthBase<T>(){
    
        }
        
        /**
         * von Bertalanffy growth curve.
         * 
         * @param age
         * @return 
         * 
         * \f$l_inf * (1.0 - e^(-k*(age - a_min)))\f$ 
         */
        virtual const T evaluate(const T& age){
            T ret = l_inf_ * (static_cast<T> (1.0) - fims::exp<T>(-1.0*k_ * (age - this->a_min_)));
            return ret < T(0.0) ? T(0.0) : ret;
        }
    };
    
}

#endif /* VON_BERTALANFFY_HPP */

