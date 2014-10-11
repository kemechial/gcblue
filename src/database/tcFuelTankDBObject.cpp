/**   
**  @file tcFuelTankDBObject.cpp
*/
/*
**  Copyright (c) 2014, GCBLUE PROJECT
**  All rights reserved.
**
**  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
**
**  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
**
**  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the 
**     documentation and/or other materials provided with the distribution.
**
**  3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from 
**     this software without specific prior written permission.
**
**  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
**  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
**  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
**  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
**  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
**  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "stdwx.h"
#if _MSC_VER > 1000
#pragma warning(disable:4786) // suppress warning for STL bug in VC6, see Q167355 in the MSDN Library.
#endif // _MSC_VER > 1000



#include "tcFuelTankDBObject.h"
#include "CsvTranslator.h"
#include "common/tinyxml.h"
#include "database/tcSqlReader.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

namespace database
{


	void tcFuelTankDBObject::PrintToFile(tcFile& file) 
	{
		tcDatabaseObject::PrintToFile(file);
	}

	/**
	* Adds sql column definitions to columnString. This is used for
	* SQL create table command
	*/
	void tcFuelTankDBObject::AddSqlColumns(std::string& columnString)
	{
		tcDatabaseObject::AddSqlColumns(columnString);

		columnString += ",";

		columnString += "FuelCapacity_kg number(8),";
	}

	void tcFuelTankDBObject::ReadSql(tcSqlReader& entry)
	{
		tcDatabaseObject::ReadSql(entry);

		fuelCapacity_kg = entry.GetDouble("FuelCapacity_kg");
	}

	void tcFuelTankDBObject::WriteSql(std::string& valueString)
	{
		tcDatabaseObject::WriteSql(valueString);

		std::stringstream s;

		s << ",";

		s << fuelCapacity_kg;
	}


	tcFuelTankDBObject::tcFuelTankDBObject()
	{
		mzClass = "Undefined";
	}

	tcFuelTankDBObject::tcFuelTankDBObject(const tcFuelTankDBObject& obj) 
		: tcDatabaseObject(obj),
		  fuelCapacity_kg(obj.fuelCapacity_kg)
	{
	}


	tcFuelTankDBObject::~tcFuelTankDBObject() 
	{
	}


}