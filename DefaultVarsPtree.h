/**
 * GeoDa TM, Copyright (C) 2011-2014 by Luc Anselin - all rights reserved
 *
 * This file is part of GeoDa.
 * 
 * GeoDa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GeoDa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GEODA_CENTER_DEFAULT_VARS_PTREE_H__
#define __GEODA_CENTER_DEFAULT_VARS_PTREE_H__

#include <vector>
#include <list>
#include "DataViewer/PtreeInterface.h"

struct DefaultVar {
	wxString name;
	wxString time_id;
	wxString ToStr() const;
};

class DefaultVarsPtree : public PtreeInterface {
public:
    DefaultVarsPtree();
	DefaultVarsPtree(const DefaultVarsPtree& o);
    DefaultVarsPtree(const boost::property_tree::ptree& pt,
					 const wxString& proj_path);
    virtual ~DefaultVarsPtree();
	
	/// PtreeInterface method.  Throws GdaException
	virtual void ReadPtree(const boost::property_tree::ptree& pt,
						   const wxString& proj_path);
	/// PtreeInterface method.  Throws GdaException
	virtual void WritePtree(boost::property_tree::ptree& pt,
							const wxString& proj_path);

	const std::list<DefaultVar>& GetDefaultVarList() const;
	void SetDefaultVarList(const std::vector<wxString>& names,
						   const std::vector<wxString>& time_ids);

	wxString ToStr() const;
	
    DefaultVarsPtree* Clone();
    
private:
	std::list<DefaultVar> default_vars_list;
};

#endif
