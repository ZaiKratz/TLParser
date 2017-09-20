#include "../Public/SavedInfo.h"


//begin namespace block
namespace PAYMENTS
{

SavedInfo::SavedInfo()
{
	this->_ConstructorID = 1021612027;
}

SavedInfo::SavedInfo(bool has_saved_credentials, COMMON::PaymentRequestedInfo* saved_info)
{
	this->_ConstructorID = 1021612027;
	this->has_saved_credentials = has_saved_credentials;
	this->saved_info = saved_info;
}
void SavedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!has_saved_credentials)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!saved_info)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(!this->saved_info)
	{
	this->saved_info->OnSend(Writer);
	}
}


void SavedInfo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		has_saved_credentials = true;
	}
	if((Flags & (1 << 0)) != 0) 
	{
	saved_info = reinterpret_cast<COMMON::PaymentRequestedInfo*>(Reader.TGReadObject());
	}
}
SavedInfo::~SavedInfo()
{

}
}//end namespace block
