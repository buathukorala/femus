/*=========================================================================

 Program: FEMUS
 Module: MultiLevelProblemTwo
 Authors: Giorgio Bornia

 Copyright (c) FEMTTU
 All rights reserved.

 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __mgequationsmap_h__
#define __mgequationsmap_h__

#include <map>
#include <string>
using namespace std;

#include "Typedefs.hpp"


#include "SystemTwo.hpp"
#include "GaussPoints.hpp"

#include "MultiLevelProblem.hpp"

namespace femus {



class Physics;
class MultiLevelMeshTwo;
class FEElemBase;
class elem_type;
class TimeLoop;

class QuantityMap;


class MultiLevelProblemTwo : public MultiLevelProblem {

public:
  
    FemusInputParser<double> &  _phys;
    QuantityMap& _qtymap;
    MultiLevelMeshTwo&     _mesh;
    std::vector< std::vector<elem_type*> >  &  _elem_type;

  /// Constructor
    MultiLevelProblemTwo(FemusInputParser<double> & phys_in,
		  QuantityMap& qtymap_in,
		  MultiLevelMeshTwo& mesh_in,
                  std::vector< std::vector<elem_type*> > & elem_type_in,
		  std::vector<Gauss> qrule_in
		);

  inline const Gauss & GetQrule(const unsigned dim) const {return _qrule[dim - 1];}
    
    /// Destructor
  ~MultiLevelProblemTwo(){};
  
  void clean(); ///< Clean all substructures

  // equation get/set
  inline          void  add_system(SystemTwo* value)            {_equations.insert(make_pair(value->_eqname,value));}
  inline       SystemTwo* get_system(const string & name)       {return _equations.find(name)->second;}
  inline const SystemTwo* get_system(const string & name) const {return _equations.find(name)->second;}

  typedef std::map<string, SystemTwo*>::iterator iterator;
  typedef std::map<string, SystemTwo*>::const_iterator const_iterator;

  inline iterator       begin()       { return _equations.begin();}
  inline iterator         end()       { return _equations.end();}
  inline const_iterator begin() const { return _equations.begin();}
  inline const_iterator   end() const { return _equations.end();}

private:
  
 map<string,SystemTwo*> _equations;   // system map
    
    std::vector<Gauss>       _qrule;


};


} //end namespace femus



#endif