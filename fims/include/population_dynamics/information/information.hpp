/*
 * File:   information.hpp
 *
 * Author: Matthew Supernaw
 * National Oceanic and Atmospheric Administration
 * National Marine Fisheries Service
 * Sustainable Fisheries Division
 * Email: matthew.supernaw@noaa.gov
 *
 * Created on September 30, 2021, 11:47 PM
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
#ifndef INFORMATION_HPP
#define INFORMATION_HPP

#include <map>
#include <memory>
#include <vector>
#include "../common/model_object.hpp"
#include "../common/traits.hpp"


namespace fims {

    /**
     * Contains all objects and data pre-model construction 
     */
    template<typename T>
    class Information {
        typedef fims::FIMSTrait<T>::variable_t variable_t;
        typedef fims::FIMSTrait<T>::real_t real_t;
        std::map<uint32_t, std::shared_ptr<fims::MortalityBase<T> > model_objects; //list of all created model objects
        typedef typename std::map<uint32_t, std::shared_ptr<fims::MortalityBase<T> >::iterator model_objects_iterator;
        std::vector<variable_t*> parameters; //list of all estimated parameters
        std::vector<variable_t*> random_effects; //list of all estimated random effects
        
        bool create_model(){
            
        }

    };
}



#endif /* INFORMATION_HPP */

