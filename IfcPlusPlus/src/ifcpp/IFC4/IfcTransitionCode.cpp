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

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcTransitionCode.h"

// TYPE IfcTransitionCode = ENUMERATION OF	(DISCONTINUOUS	,CONTINUOUS	,CONTSAMEGRADIENT	,CONTSAMEGRADIENTSAMECURVATURE);
IfcTransitionCode::IfcTransitionCode() {}
IfcTransitionCode::~IfcTransitionCode() {}
shared_ptr<IfcPPObject> IfcTransitionCode::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcTransitionCode> copy_self( new IfcTransitionCode() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcTransitionCode::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCTRANSITIONCODE("; }
	if( m_enum == ENUM_DISCONTINUOUS )
	{
		stream << ".DISCONTINUOUS.";
	}
	else if( m_enum == ENUM_CONTINUOUS )
	{
		stream << ".CONTINUOUS.";
	}
	else if( m_enum == ENUM_CONTSAMEGRADIENT )
	{
		stream << ".CONTSAMEGRADIENT.";
	}
	else if( m_enum == ENUM_CONTSAMEGRADIENTSAMECURVATURE )
	{
		stream << ".CONTSAMEGRADIENTSAMECURVATURE.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcTransitionCode> IfcTransitionCode::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcTransitionCode>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcTransitionCode>(); }
	shared_ptr<IfcTransitionCode> type_object( new IfcTransitionCode() );
	if( boost::iequals( arg, L".DISCONTINUOUS." ) )
	{
		type_object->m_enum = IfcTransitionCode::ENUM_DISCONTINUOUS;
	}
	else if( boost::iequals( arg, L".CONTINUOUS." ) )
	{
		type_object->m_enum = IfcTransitionCode::ENUM_CONTINUOUS;
	}
	else if( boost::iequals( arg, L".CONTSAMEGRADIENT." ) )
	{
		type_object->m_enum = IfcTransitionCode::ENUM_CONTSAMEGRADIENT;
	}
	else if( boost::iequals( arg, L".CONTSAMEGRADIENTSAMECURVATURE." ) )
	{
		type_object->m_enum = IfcTransitionCode::ENUM_CONTSAMEGRADIENTSAMECURVATURE;
	}
	return type_object;
}
