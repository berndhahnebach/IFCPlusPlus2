/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPObject.h"
#include "IfcRelSpaceBoundary1stLevel.h"
class IfcRelSpaceBoundary2ndLevel;
//ENTITY
class IfcRelSpaceBoundary2ndLevel : public IfcRelSpaceBoundary1stLevel
{
public:
	IfcRelSpaceBoundary2ndLevel();
	IfcRelSpaceBoundary2ndLevel( int id );
	~IfcRelSpaceBoundary2ndLevel();
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkSelf();
	virtual const char* classname() const { return "IfcRelSpaceBoundary2ndLevel"; }


	// IfcRoot -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcGloballyUniqueId>						m_GlobalId;
	//  shared_ptr<IfcOwnerHistory>							m_OwnerHistory;				//optional
	//  shared_ptr<IfcLabel>									m_Name;						//optional
	//  shared_ptr<IfcText>									m_Description;				//optional

	// IfcRelationship -----------------------------------------------------------

	// IfcRelConnects -----------------------------------------------------------

	// IfcRelSpaceBoundary -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcSpaceBoundarySelect>					m_RelatingSpace;
	//  shared_ptr<IfcElement>								m_RelatedBuildingElement;
	//  shared_ptr<IfcConnectionGeometry>					m_ConnectionGeometry;		//optional
	//  shared_ptr<IfcPhysicalOrVirtualEnum>					m_PhysicalOrVirtualBoundary;
	//  shared_ptr<IfcInternalOrExternalEnum>				m_InternalOrExternalBoundary;

	// IfcRelSpaceBoundary1stLevel -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcRelSpaceBoundary1stLevel>				m_ParentBoundary;			//optional
	// inverse attributes:
	//  std::vector<weak_ptr<IfcRelSpaceBoundary1stLevel> >	m_InnerBoundaries_inverse;

	// IfcRelSpaceBoundary2ndLevel -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcRelSpaceBoundary2ndLevel>				m_CorrespondingBoundary;	//optional
	// inverse attributes:
	std::vector<weak_ptr<IfcRelSpaceBoundary2ndLevel> >	m_Corresponds_inverse;
};

