#include "../Public/GetSavedInfo.h"


//begin namespace block
namespace PAYMENTS
{

GetSavedInfo::GetSavedInfo()
{
	this->_ConstructorID = 1266842914;
	this->_ContentRelated = true;
}
void GetSavedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetSavedInfo::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PAYMENTS::SavedInfo*>(Reader.TGReadObject());
}
GetSavedInfo::~GetSavedInfo()
{

}
}//end namespace block
