#include "../Public/ClearSavedInfo.h"


//begin namespace block
namespace PAYMENTS
{

ClearSavedInfo::ClearSavedInfo()
{
	this->_ConstructorID = -667062079;
	this->_ContentRelated = true;
}

ClearSavedInfo::ClearSavedInfo(bool credentials, bool info)
{
	this->_ConstructorID = -667062079;
	this->_ContentRelated = true;
	this->credentials = credentials;
	this->info = info;
}
void ClearSavedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(credentials)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(info)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

}


void ClearSavedInfo::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ClearSavedInfo::~ClearSavedInfo()
{
}
}//end namespace block
