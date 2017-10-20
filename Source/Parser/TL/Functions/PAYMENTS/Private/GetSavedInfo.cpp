#include "../Public/GetSavedInfo.h"


//begin namespace block
namespace PAYMENTS
{

GetSavedInfo::GetSavedInfo()
{
	this->_ConstructorID = 578650699;
	this->_ContentRelated = true;
}
void GetSavedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetSavedInfo::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PAYMENTS::SavedInfo*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetSavedInfo::~GetSavedInfo()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
