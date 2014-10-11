/**  
**  @file tcCountryData.cpp
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


#include "tcCountryData.h"
#include "tcTexture2D.h"
#include "tc3DWindow2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

namespace database
{

tcTexture2D* tcCountryData::GetEnsignImage()
{
    return navalEnsignImage.get();
}

boost::shared_ptr<tcTexture2D> tcCountryData::GetEnsignImageShared()
{
    return navalEnsignImage;
}

void tcCountryData::LoadEnsignImage()
{
    wxString s("flags\\");
    s += navalEnsign.c_str();

    navalEnsignImage = tc3DWindow2::LoadTexture(s.c_str(), ensignWidth, ensignHeight);
}

tcCountryData::tcCountryData()
: countryName("Error"),
  ensignWidth(96),
  ensignHeight(64)
{

}

tcCountryData::tcCountryData(const tcCountryData& obj) 
: countryName(obj.countryName),
  navalEnsign(obj.navalEnsign),
  navalEnsignImage(obj.navalEnsignImage),
  ensignWidth(obj.ensignWidth),
  ensignHeight(obj.ensignHeight)
{
}

const tcCountryData& tcCountryData::operator=(const tcCountryData& obj)
{
    countryName = obj.countryName;
    navalEnsign = obj.navalEnsign;
    navalEnsignImage = obj.navalEnsignImage;

    return *this;
}

tcCountryData::tcCountryData(const std::string& countryName_, const std::string& navalEnsign_)
: countryName(countryName_),
  navalEnsign(navalEnsign_),
  ensignWidth(96),
  ensignHeight(64)
{
    LoadEnsignImage();
}

tcCountryData::~tcCountryData() 
{
}


}