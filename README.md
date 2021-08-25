# software_arch
Covers how the software is engineered and architected for FIMS

# scope

This repository covers the software architecture for FIMS. We seek to answer a number of key questions:

## tiered architecture
to facilitate maximum portability and reusability, the FIMS will be implemented in layers consisting of at minimum: 
- imported modules from other systems (for example, commonly used mathematical functions, statistical distributions, and their atomic functions)
- base function layer containing fisheries assessment specific pieces that can be easily separated and removed. For example: stock-recruit functions, somatic growth functions, the age-length key, catch equations, functional responses, selectivity, and catchability functions.
- modeling layer that loops through population/area/species segments and applies functions from the layer described above. This layer is focused on bookkeeping and associating data with likelihood functions incorporating process equations.
-  data layer. This layer consists of processing scripts and functions that may be region- or data-type specific. The translation of data types into a form amenable to inclusion in the likelihood is kept at this layer so that it is always possible to add a new data type or format by adding a new processing module to this layer without changing the modeling layer if at all possible. This also has the benefit of allowing processed data to be automatically tested, viewed, and checked before it is combined with other data types in a model. It also lowers the barrier to entry for data analysts who can update the data system without needing to understand the model structure, and formalizing this layer with packages and standards will reduce duplication.
-  programmatic interface. Surfacing the model via a programmatic interface will simplify reproducibility by capturing all of the settings and inputs the model uses instead of manually editing or manipulating them. This also has the benefit of exposing model configuration in the users' chosen language (e.g. R) even if the base model code is written at a lower level of abstraction (e.g. C++) for performance reasons.
-  graphical user interface. It is TBD if we need a GUI, but if we end up creating one in the future, this would be a separate layer of this system.
-  forecasting module. This is also for future consideration.

## modularity
Within each architecture tier, we seek to keep each component as portable, separable, and reusable as possible. Each module should be individually tested (please see Bai Li's testing framework for more information). When possible, components using the same math will reuse the same base code (e.g. logistic curve can be reused for selectivity function and functional response). We will need to determine which modules are private (only usable in this system) vs. published externally for community use (in an R package, for example). Also TBD is how many compiled model frameworks there are - more than one implementation is probably desired to meet a variety of needs without adding a large number of conditional statements to the code.

## minimum viable product
Each module and architecture layer will be first implemented in its most minimal sense and tested fully before extending the capabilities. This ensures the foundation is strong and well-tested and keeps the community engaged in development while the model is still small and easy to understand and modify. 

## extensibility
While the model is developed first minimally, it must be extensible to add complexity in the future. This means (for example) any simple function in the first iteration of the model should be built to be replaced by a more complex one down the road. 


# useful links
What is devops: https://aws.amazon.com/devops/what-is-devops/
(excluding collaboration piece which is under collaborative_workflow)
